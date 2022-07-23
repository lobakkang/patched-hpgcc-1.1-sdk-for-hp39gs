//& ****************************************************************************
//&
//& Copyright (C) 2004 HP-GCC Team
//&
//& ****************************************************************************
//&
//& This file is part of HP-GCC.
//&
//& HP-GCC is free software; you can redistribute it and/or modify
//& it under the terms of the GNU General Public License as published by
//& the Free Software Foundation; either version 2, or (at your option)
//& any later version.
//& 
//& HP-GCC is distributed in the hope that it will be useful,
//& but WITHOUT ANY WARRANTY; without even the implied warranty of
//& MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//& GNU General Public License for more details.
//& 
//& You should have received a copy of the GNU General Public License
//& along with HP-GCC; see the file COPYING. 
//& 
//& As a special exception, you may use this file as part of a free software
//& library without restriction.  Specifically, if other files instantiate
//& templates or use macros or inline functions from this file, or you compile
//& this file and link it with other files to produce an executable, this
//& file does not by itself cause the resulting executable to be covered by
//& the GNU General Public License.  This exception does not however
//& invalidate any other reasons why the executable file might be covered by
//& the GNU General Public License.
//&
//& ****************************************************************************

/*!
 * \file  ggl.h
 * \brief Extended grayscale graphics routines for HP calculators.
 */

/*!
 * \mainpage GGL - Grayscale Graphics Library
 *
 * \section overview Overview
 *
 * GGL (the Gray Graphics Library) provides extended functions for 16-color
 * grayscale graphics on the HP49G+ (and possible HP39G+ and HP48gII)
 * calculators.  It complements the abilities of HPG by providing faster and
 * more specialized routines for the 16-color grayscale mode.  GGL may be used
 * independently of HPG, or seamlessly alongside it.
 *
 * The main features of the GGL library are:
 *
 * - Optimizations for 16-color grayscale drawing
 * - Fast bitblt routine
 * - Masked sprites
 * - Antialiased lines
 */

/*!
 * \brief The minimum number of bytes for a state buffer.
 *
 * Save buffers, which are allocated and supplied to GGL by the application
 * for use by ::ggl_save and ::ggl_restore, need to be at least this size
 * to prevent undefined (but probably bad) behavior from occurring.
 *
 * \sa ggl_save
 * \sa ggl_restore
 */
#define STATEBUFSIZE ((11+6)*4)

/*!
 * \brief Height of the screen, in pixels.
 */
#define LCD_H 80

/*!
 * \brief Width of the screen, in pixels.
 */
#define LCD_W 160

/*!
 * \brief Number of bytes in the screen buffer.
 *
 * This constant provides the size in bytes of the screen buffer, allowing 
 * the use of standard routines like memset to clear the screen, memcpy to
 * copy it elsewhere, and so forth.
 *
 */
#define SCREENBUFSIZE ((LCD_W>>2)*(LCD_H)*2)

// data types/structures

// surface used for bitblt operations
// notes:
// a surface is infinite in both width and height, there are no memory limits
// .addr must be a word aligned address
// .width is used only to find a new scanline, and can be changed at will
//        the width is given in pixels and it can be arbitrary (no alignement needed)
// for normal drawing primitives, (0,0) is the word-aligned address pointed by .addr,
// disregarding of the values in .x and .y
// for bitblt operations, .x and .y give the origin (top-left corner) of the region to use
// the surface is nibble-aligned, so a 1 pixel wide surface will contain 8
// rows of pixels per word

/*!
 * \brief A surface (bitmap) that can be drawn upon using GGL.
 *
 * All GGL operations are performed on surfaces. Each surface is an instance
 * of this data structure. The LCD screen is a surface as well. Surfaces can
 * be copied, scrolled, etc.
 * To create a surface, the user should allocate a memory block of enough size
 * to accomodate the desired bitmap. The size in bytes is (width*height)/2.
 */
typedef struct {
	int *addr;  //! Word-aligned address of the surface buffer
	int width;  //! Width (in pixels) of the buffer
	int x,y;    //! Offset coordinates within the buffer
} gglsurface;

/*!
 * \brief A filter for pixels being drawn to a surface.
 *
 * A filter is a unary operation (uses one argument) that is applied to
 * colors being drawn to a screen.  Filters are very flexible and can be used
 * for a wide variety of drawing purposes, including color modification and
 * texturing.  However, they lack the ability to combine colors with those
 * already on the surface.
 * The function takes as arguments a word containing 8 pixels and a parameter
 * defined by the user. A custom filter should process the 8 pixels, using the
 * parameter if needed, and return a word containing the modified 8 pixels.
 * Packs of 8 pixels are processed at the same time for efficiency reasons.
 * Examples of simple filter operations are to 'darken' or 'lighten' an image.
 * A more complex filter can be written for 'color replace' for example.
 *
 *
 * \sa ggl_fltdarken
 * \sa ggl_fltlighten
 * \sa ggloperator
 */
typedef unsigned int (*gglfilter)(unsigned int pixels,int param);

/*!
 * \brief An operator for pixels being drawn to a surface.
 *
 * An operator is a binary operation (using two values) that is applied to
 * colors being drawn to a screen.  Operators can be used to implement a great
 * variety of features, including either partial or complete transparency.
 * Operators are more powerful than filters, but at a slightly higher 
 * performance cost.
 * The function takes a word containing 8 pixels from the source surface, a
 * word conatining the corresponding 8 pixels from the destination surface,
 * and an arbitrary parameter.
 * Packs of 8 pixels are processed at the same time for efficiency reasons.
 * The function should return a word containing the 8 pixels resulting from
 * the operation performed.
 *
 * \sa ggl_opmask
 * \sa ggl_optransp
 * \sa gglfilter
 */
typedef unsigned int (*ggloperator)(unsigned int dest,unsigned int source,int param);


// general routines

/*!
 * \brief Prepares to draw on the LCD screen with GGL.
 *
 * This routine prepares for GGL drawing onto the LCD screen, by allocating
 * memory for the screen buffer and filling the ::gglsurface structure with
 * the proper width and other parameters.  It is used by stand-alone GGL
 * applications; HPG applications that make use of GGL should use
 * ::ggl_gethpgscreen instead.
 *
 * \param srf  An instance of ::gglsurface to fill in with the new surface.
 */
void ggl_initscr(gglsurface *srf);	// allocate screen buffer

/*!
 * \brief Prepares to draw on the LCD screen with GGL and HPG.
 *
 * This routine prepares for GGL drawing onto an HPG surface.  It fills in the
 * ::gglsurface structure with appropriate values to draw to HPG's standard
 * screen.  This function should be called by HPG applications that wish to
 * make use of GGL.  Stand-alone GGL applications should use ::ggl_initscr
 * instead.
 *
 * \param srf  An instance of ::gglsurface to fill in with HPG's screen.
 */
void ggl_gethpgscreen(gglsurface *srf);

/*!
 * \brief Sets a 16-color display mode.
 *
 * This macro calls sys_lcdsetmode(), which actually switches the calculator
 * LCD controller into 16-color grayscale mode with the given address for a
 * frame buffer. This should be done for stand-alone GGL applications.
 * (HPG applications using GGL should instead use HPG's \c hpg_set_mode_gray16
 * to perform the same task.)
 *
 * \param framebuf A pointer to the new LCD screen's frame buffer.  This is
 *                 generally found in the gglsurface::addr field of the
 *                 surface passed to ggl_initscr or ggl_gethpgscreen.
 *                 IMPORTANT: framebuf MUST be a physical memory pointer. Use
 *                            sys_map_v2p() to convert.
 */
#define ggl_setmode(framebuf) sys_lcdsetmode(MODE_16GRAY,framebuf);


/*!
 * \brief Saves the state of the LCD controller.
 *
 * **OBSOLETE**: This function is now a macro that calls sys_lcdsave().
 *
 * Calling this function results in the current state of the LCD controller
 * being stored in the given buffer. The saved state can be restored by
 * passing the same buffer to ::ggl_restore. This function can be used when
 * it is important to restore the LCD controller to the exact previous state.
 * For example, if a program sets the LCD in a non-standard (or unknown state,
 * like when using hardware scrolling, and a routine needs to use the LCD,
 * it can save the state and restore it later using ggl_save and ggl_restore.
 *
 * If HPG is in use, the application should use hpg_cleanup when finished to
 * restore the LCD controller to a known state.  It is dangerous to make
 * changes to the LCD controller state while HPG is operating.
 * However, it is safe to use ggl_save before initializing HPG and use 
 * ggl_restore after hpg_cleanup has returned.
 *
 * \param buf A flat buffer, with a size of at least ::STATEBUFSIZE bytes.
 * \sa ggl_restore
 */
#define ggl_save(buf) sys_lcdsave(buf)

/*!
 * \brief Restores the state of the LCD controller.
 *
 * **OBSOLETE**: This function is now a macro that calls sys_lcdrestore().
 *
 * Calling this function results in the current state of the LCD controller
 * being restored from the given buffer.  The buffer should have been filled
 * in earlier by a call to ::ggl_save.
 * Warning: A buffer with invalid or corrupted data might cause unexpected
 * results, including possible damage to the LCD.
 *
 * If HPG is in use, the application should use hpg_cleanup when finished to
 * restore the LCD controller to a known state.  It is dangerous to make
 * changes to the LCD controller state while HPG is operating.
 * However, it is safe to use ggl_save before initializing HPG and use 
 * ggl_restore after hpg_cleanup has returned.
 *
 * \param buf A flat buffer, containing data stored by ggl_save.
 * \sa ggl_save
 */
void ggl_restore(int *buf);	// restore saved LCD state

/*
 * \brief Causes a different GGL surface to be displayed.
 *
 * This function allows the use of several GGL surfaces as the main screen
 * in an application. It causes the LCD controller to begin displaying a
 * different screen.  No VSYNC is performed, so some tearing is possible 
 * unless external VSYNC is checked before calling this function.
 *
 * This function should be used by applications that use GGL exclusively.  If
 * HPG is in use, the application should use hpg_flip to accomplish page
 * flipping.
 *
 * \param framebuf A pointer to the new LCD screen's frame buffer.  This is
 *                 generally found in the gglsurface::addr field of a
 *                 ::gglsurface.
 */
void ggl_show(int *buffer);	// display buffer, no vertical sync

// drawing primitives
// general pixel set/read routines

/*!
 * \brief Pokes a color into a specific pixel of a surface.
 *
 * Colors the given pixel by the given color.  The pixel is identified by an
 * offset from the beginning of the frame buffer, which is defined as
 * \c x \c + \c y \c * \c width for a given x and y coordinate, where \c width
 * is the width of the surface to plot to. The calling procedure is 
 * responsible for correctly calculating the offset. This reduces the
 * overhead when pixels are painted in a specific sequence.
 *
 * \param buff  The address of a surface bitmap (gglsurface::addr field).
 * \param off   The offset (\c x \c + \c width \c * \c y).
 * \param color The color, between 0 and 15. 15=black.
 */
void ggl_pltnib(int *buff,int off,int color);	// poke a pixel (off in nibbles)

/*!
 * \brief Peeks a color from a specific pixel of a surface.
 *
 * Retrieves the color of the given pixel.  The pixel is identified by an
 * offset from the beginning of the frame buffer, which is defined as
 * \c x \c + \c y \c * \c width for a given x and y coordinate, where \c width
 * is the width of the surface to plot to. The calling procedure is 
 * responsible for correctly calculating the offset. This reduces the
 * overhead when pixels are painted in a specific sequence.
 *
 * \param buff  The address of a surface bitmap (gglsurface::addr field).
 * \param off   The offset (\c x \c + \c width \c * \c y).
 *
 * \return The color, between 0 and 15.
 */
int  ggl_getnib(int *buff,int off);				// peek a pixel (off in nibbles)

// general drawing primitives

// note: the argument color is a 32-bit value containing a different
//       color for each pixel. For solid colors, set color to contain the same value
//       on every nibble (for color 8, color=0x88888888)
//       or call ggl_mkcolor for that purpose

/*!
 * \brief Draws a horizontal line on a surface.
 *
 * Draws a horizontal line onto the given surface, in the given color or color
 * pattern.
 *
 * \param srf   The surface to draw onto.
 * \param y     The Y coordinate of the line.
 * \param xl    The left-most x coordinate of the line.
 * \param xr    The right-most x coordinate of the line.
 * \param color The color pattern.  This is a 32-bit value, containing 8
 *              consecutive pixels worth of color.  For solid colors, set the
 *              color to contain the same pattern on every nibble (for color 8,
 *              use 0x88888888), or call ::ggl_mkcolor for that purpose.  The
 *              colors in this pattern will be used consecutively in the
 *              horizontal direction. Patterns are always 8-pixel aligned,
 *              so painting a sequence of lines produces the right pattern.
 */
void ggl_hline(gglsurface *srf,int y,int xl,int xr, int color); // fast low-level horizontal line

/*!
 * \brief Draws a vertical line on a surface.
 *
 * Draws a vertical line onto the given surface, in the given color or color
 * pattern.
 *
 * \param srf   The surface to draw onto.
 * \param x     The x coordinate of the line.
 * \param yt    The top-most y coordinate of the line.
 * \param yb    The bottom-most y coordinate of the line.
 * \param color The color pattern.  This is a 32-bit value, containing 8
 *              consecutive pixels worth of color.  For solid colors, set the
 *              color to contain the same pattern on every nibble (for color 8,
 *              use 0x88888888), or call ::ggl_mkcolor for that purpose.  The
 *              colors in this pattern will be used consecutively in the
 *              vertical direction, making this different from the use of the
 *              color parameter in other GGL functions. Pattern is always
 *              8-pixel aligned.
 */
void ggl_vline(gglsurface *srf,int x,int yt,int yb, int color); // fast low-level vertical line

/*!
 * \brief Draws a rectangle on a surface.
 *
 * Fills in a rectangle onto the given surface, with the given color or color
 * pattern.  The color pattern is oriented horizontally, so that the color
 * remains the same in any given column of pixels.
 *
 * \param srf   The surface to draw onto.
 * \param x1    The X coordinate of the top-left coordinate of the rectangle.
 * \param y1    The Y coordinate of the top-left coordinate of the rectangle.
 * \param x2    The X coordinate of the bottom-right coordinate of the
 *              rectangle.
 * \param y2    The Y coordinate of the bottom-right coordinate of the
 *              rectangle.
 * \param color The color pattern.  This is a 32-bit value, containing 8
 *              consecutive pixels worth of color.  For solid colors, set the
 *              color to contain the same pattern on every nibble (for color 8,
 *              use 0x88888888), or call ::ggl_mkcolor for that purpose.  The
 *              colors in this pattern will be used consecutively in the
 *              horizontal direction.
 */
void ggl_rect(gglsurface *srf,int x1,int y1,int x2,int y2,int color); // low-level rectangle

/*!
 * \brief Draws a rectangle on a surface with a 2D pattern.
 *
 * Fills in a rectangle onto the given surface, with the given color or color
 * pattern.  The color pattern is 8x8 pixels in size, and is repeated both
 * horizontally and vertically.
 *
 * \param srf   The surface to draw onto.
 * \param x1    The X coordinate of the top-left coordinate of the rectangle.
 * \param y1    The Y coordinate of the top-left coordinate of the rectangle.
 * \param x2    The X coordinate of the bottom-right coordinate of the
 *              rectangle.
 * \param y2    The Y coordinate of the bottom-right coordinate of the
 *              rectangle.
 * \param color The color pattern.  This is an array of 8 32-bit values, each
 *              containing 8 consecutive pixels worth of color for a single
 *              line.  The result is an 8x8 color pattern that is used to draw
 *              to the screen.
 */
void ggl_rectp(gglsurface *srf,int x1,int y1,int x2,int y2,int *color); // low-level rectangle with 8x8 pattern

// rectangle blt
// note: see gglsurface above for complete understanding of the behavior of these routines
// ggl_bitblt loops from top to bottom

/*!
 * \brief Copies a rectangular surface. Forward direction.
 *
 * Copies a rectangular area from one surface to another. The direction
 * of memory movement is from top to bottom, so care should be taken if
 * the areas overlap.
 *
 * \param dest   The surface to draw onto. The area will be copied at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param src    The source surface. The region to copy will start at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param width  The width in pixels of the rectangular region to copy.
 * \param height The height in pixels of the rectangular region to copy.
 *
 * \sa ggl_revblt
 * \sa ggl_ovlblt
 */

void ggl_bitblt(gglsurface *dest,gglsurface *src,int width, int height); // copy a rectangular region

// ggl_revblt loops from bottom to top, for overlapping zones
/*!
 * \brief Copies a rectangular surface. Reverse direction.
 *
 * Copies a rectangular area from one surface to another. The direction
 * of memory movement is from bottom to top, so care should be taken if
 * the areas overlap.
 *
 * \param dest   The surface to draw onto. The area will be copied at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param src    The source surface. The region to copy will start at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param width  The width in pixels of the rectangular region to copy.
 * \param height The height in pixels of the rectangular region to copy.
 *
 * \sa ggl_bitblt
 * \sa ggl_ovlblt
 */
void ggl_revblt(gglsurface *dest,gglsurface *src,int width, int height); // copy a rectangular region, reverse loop
// ggl_ovlblt chooses to use normal/reverse loop based on the addresses
// use it when the direcction of movement is unknown
/*!
 * \brief Copies a rectangular surface.  Safe to use when areas overlap.
 *
 * Copies a rectangular area from one surface to another. If the areas
 * overlap, it chooses the appropriate direction and calls ggl_bitblt or
 * ggl_revblt as needed.
 *
 * \param dest   The surface to draw onto. The area will be copied at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param src    The source surface. The region to copy will start at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param width  The width in pixels of the rectangular region to copy.
 * \param height The height in pixels of the rectangular region to copy.
 *
 * \sa ggl_bitblt
 * \sa ggl_revblt
 */
void ggl_ovlblt(gglsurface *dest,gglsurface *src,int width, int height); // copy overlapped regions
// ggl_bitbltmask behaves exactly as ggl_bitblt but using tcol as a transparent color


/*!
 * \brief Copies a rectangular surface with mask.
 *
 * Performs a bitblit copy operation where the given color is considered
 * transparent, thus not affecting the background color. The direction
 * of the memory movement is from top to bottom.
 * Note: This is a macro that calls ggl_bitbltoper with the proper operator.
 *
 * \param dest   The surface to draw onto. The area will be copied at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param src    The source surface. The region to copy will start at the
 *               coordinates x and y given in the proper fields of the 
 *               ::gglsurface structure.
 * \param width  The width in pixels of the rectangular region to copy.
 * \param height The height in pixels of the rectangular region to copy.
 * \param tcol   Transparent color. Color in the source surface to be considered
 *               as transparent (between 0 and 15).
 *
 * \sa ggl_bitblt
 * \sa ggl_bitbltoper
 */
#define ggl_bitbltmask(dest,src,width,height,tcol)  ggl_bitbltoper(dest,src,width,height,tcol,&ggl_opmask)


// rectangle scrolling routines
// dest contains the surface to scroll, and width and height define the rectangle
// the area that needs to be redrawn after the scroll is not erased or modified by these routines 
/*!
 * \brief Scroll a surface up.
 *
 * Scrolls up a surface by the specified number of pixels.
 * The unveiled area is not cleared.
 *
 * \param dest    The surface to draw onto. The area will be scrolled at
 *                coordinates x and y given in the proper fields of the 
 *                ::gglsurface structure.
 * \param width   The width in pixels of the rectangular region to scroll.
 * \param height  The height in pixels of the rectangular region to scroll.
 * \param npixels Number of pixels to scroll.
 *
 * \sa ggl_scrolldn
 * \sa ggl_scrolllf
 * \sa ggl_scrollrt
 */
void ggl_scrollup(gglsurface *dest,int width, int height, int npixels); // scroll npixels up
/*!
 * \brief Scroll a surface down.
 *
 * Scrolls down a surface by the specified number of pixels.
 * The unveiled area is not cleared.
 *
 * \param dest    The surface to draw onto. The area will be scrolled at
 *                coordinates x and y given in the proper fields of the 
 *                ::gglsurface structure.
 * \param width   The width in pixels of the rectangular region to scroll.
 * \param height  The height in pixels of the rectangular region to scroll.
 * \param npixels Number of pixels to scroll.
 *
 * \sa ggl_scrollup
 * \sa ggl_scrolllf
 * \sa ggl_scrollrt
 */

void ggl_scrolldn(gglsurface *dest,int width, int height, int npixels); // scroll npixels dn

/*!
 * \brief Scroll a surface left.
 *
 * Scrolls left a surface by the specified number of pixels.
 * The unveiled area is not cleared.
 *
 * \param dest    The surface to draw onto. The area will be scrolled at
 *                coordinates x and y given in the proper fields of the 
 *                ::gglsurface structure.
 * \param width   The width in pixels of the rectangular region to scroll.
 * \param height  The height in pixels of the rectangular region to scroll.
 * \param npixels Number of pixels to scroll.
 *
 * \sa ggl_scrollup
 * \sa ggl_scrolldn
 * \sa ggl_scrollrt
 */
void ggl_scrolllf(gglsurface *dest,int width, int height, int npixels); // scroll npixels left
/*!
 * \brief Scroll a surface right.
 *
 * Scrolls right a surface by the specified number of pixels.
 * The unveiled area is not cleared.
 *
 * \param dest    The surface to draw onto. The area will be scrolled at
 *                coordinates x and y given in the proper fields of the 
 *                ::gglsurface structure.
 * \param width   The width in pixels of the rectangular region to scroll.
 * \param height  The height in pixels of the rectangular region to scroll.
 * \param npixels Number of pixels to scroll.
 *
 * \sa ggl_scrollup
 * \sa ggl_scrolldn
 * \sa ggl_scrolllf
 */
void ggl_scrollrt(gglsurface *dest,int width, int height, int npixels); // scroll npixels right

// custom filters and operators

// bitmap filtering routine
/*!
 * \brief Applies a filter to a surface.
 *
 * Applies a user-defined filter (unary operator) on a specified
 * region of a surface.
 *
 * \param dest    The surface to filter. The area to filter starts at
 *                coordinates x and y given in the proper fields of the 
 *                ::gglsurface structure.
 * \param width   The width in pixels of the rectangular region to filter.
 * \param height  The height in pixels of the rectangular region to filter.
 * \param param   A parameter to be passed to the filter. This parameter
 *                is defined by each filter function.
 * \param filterfunc The filter function to apply.
 *
 * \sa gglfilter
 * \sa ggl_bitbltoper
 */
void ggl_filter(gglsurface *dest,int width, int height, int param, gglfilter filterfunc);

// bitblt operator routine
/*!
 * \brief Applies a binary operator to a surface.
 *
 * Applies a user-defined operator on a specified region of a surface,
 * using a second surface as an argument.
 *
 * \param dest    The surface to operate on. The area starts at
 *                coordinates x and y given in the proper fields of the 
 *                ::gglsurface structure.
 * \param src     The source surface. The area starts at coordinates x
 *                and y given in the proper fields of the ::gglsurface
 *                structure.
 * \param width   The width in pixels of the rectangular region.
 * \param height  The height in pixels of the rectangular region.
 * \param param   A parameter to be passed to the operator. This parameter
 *                is defined by each operator function.
 * \param filterfunc The operator function to apply.
 *
 * \sa ggloperator
 * \sa ggl_filter
 */
void ggl_bitbltoper(gglsurface *dest,gglsurface *src,int width, int height,int param,ggloperator fop);

// predefined filters and operators

// filters (unary operators)
// ligthens an image by subtracting param from all pixels

/*!
 * \brief Lightens an image.
 *
 * This filter lightens an image by subtracting the parameter from
 * all the pixels. Do NOT call this function. This is a filter
 * function to be passed as argument to ggl_filter.
 *
 * \sa ggl_filter
 * \sa gglfilter
 * \sa ggl_fltdarken
 */

unsigned ggl_fltlighten(unsigned word,int param);
// darkens an image by adding param to all pixels

/*!
 * \brief Darkens an image.
 *
 * This filter darkens an image by adding the parameter to
 * all the pixels. Do NOT call this function. This is a filter
 * function to be passed as argument to ggl_filter.
 *
 * \sa ggl_filter
 * \sa gglfilter
 * \sa ggl_fltlighten
 */

unsigned ggl_fltdarken(unsigned word,int param);

// operators (between two surfaces)
// standard mask, tcolor in src is considered transparent


/*!
 * \brief Mask operator.
 *
 * This operator copies the source image on the destination. All
 * pixels in the source surface matching the color passed as param
 * are not copied. Do NOT call this function. This is an operator
 * function to be passed as argument to ggl_bitbltoper.
 * The macro ggl_bitbltmask uses this operator.
 *
 * \sa ggl_bitbltoper
 * \sa ggloperator
 * \sa ggl_bitbltmask
 */

unsigned ggl_opmask(unsigned dest,unsigned src,int tcolor);
// transparency blend, weight is 0 = src is opaque, 16 = src is fully transparent

/*!
 * \brief Transparency blend operator.
 *
 * This operator copies the source image on the destination with
 * a uniform transparency, specified by the parameter.
 * When parameter is 0, the source surface is opaque. When param
 * is 16 the source surface is fully transparent. Intermediate
 * values provide different opacities.
 * Do NOT call this function. This is an operator function to be
 * passed as argument to ggl_bitbltoper.
 *
 * \sa ggl_bitbltoper
 * \sa ggloperator
 */

unsigned ggl_optransp(unsigned dest,unsigned src,int weight);




// miscellaneous

// ggl_mkcolor repeats the same color on every nibble
// ggl_mkcolor(2) will return 0x22222222
/*!
 * \brief Solid color word generator.
 *
 * Generates a word containing the specified color in every
 * nibble, to be used with the line and rectangle functions.
 *
 * \param color Color between 0 and 15.
 * \sa ggl_mkcolor32
 */
int ggl_mkcolor(int color); // solid color generator

// ggl_mkcolor32 creates virtual 32-colors by using 8x8 patterns
// col32 is a value from 0 to 30, being 30=black, 0=white
// note: the user is responsible to provide a valid int[8] buffer in the
// pattern argument
/*!
 * \brief 30-colors dither pattern generator.
 *
 * Generates an 8x8 pattern containing the specified color. The color is
 * specified in a 30-colors scale. This function will return the appropriate
 * dither pattern to approximate the color.
 * 
 * \param col32   Color between 0 and 30, 0 being white and 30 being black.
 * \param pattern Pointer to and array of 8 words to be filled with the
 *                generated pattern.
 *
 * \sa ggl_mkcolor
 */
void ggl_mkcolor32(int col32, int *pattern);	// 50% dither pattern generator for 31 colors
	
// ANTIALIAS INITIALIZATION

// ggl_initaline initializes tables needed for antialiased lines
/*!
 * \brief Antialiased lines initialization.
 *
 * Call this function before using antialiased lines. Call ggl_endaline
 * for cleanup procedures when done.
 * 
 * \sa ggl_aline
 * \sa ggl_endaline
 */
void ggl_initaline();

// for antialiased lines, call first ggl_initaline and call ggl_endaline for cleanup
// notice that ggl_init/ggl_exit do NOT call ggl_initaline
// anitaliased lines are always 3 pixels wide
/*!
 * \brief Draw antialiased line.
 *
 * Draws a 3-pixel wide line with soft borders. Line is black on white.
 * Call ggl_initaline before using this function.
 *
 * \param srf Surface to draw onto.
 * \param x1  X coordinate, origin of the line
 * \param y1  Y coordinate, origin of the line
 * \param x2  X coordinate, end of the line
 * \param y2  Y coordinate, end of the line
 *
 * \sa ggl_initaline
 * \sa ggl_endaline
 */
void ggl_aline(gglsurface *srf,int x1,int y1,int x2,int y2);	// ANTIALIASED LINES

// ggl_endaline cleans up the memory allocated by ggl_initaline
/*!
 * \brief Antialiased lines cleanup.
 *
 * Call this function after using antialiased lines. Call ggl_initaline
 * for initialization.
 * 
 * \sa ggl_initaline
 * \sa ggl_aline
 */
void ggl_endaline();
