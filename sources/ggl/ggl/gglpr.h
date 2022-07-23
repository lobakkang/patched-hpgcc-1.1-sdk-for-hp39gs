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


// constants

#define LCD_REGS	0x07300000

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

#define LINEVAL (LCD_H-1)
#define HOZVAL ((LCD_W>>2)-1)
#define LINEBLANK 8
#define WDLY 0
#define WLH 0
#define MVAL 80

#define PAGEWIDTH (HOZVAL+1)
#define OFFSIZE 0

/*!
 * \brief Number of halfwords in the screen.
 *
 * This constant provides the size of the screen buffer, allowing the use of
 * standard routines like memset to clear the screen, memcpy to copy it
 * elsewhere, and so forth.
 *
 * \warning This number is "halfwords", which are 16 bits long.  To find the
 *          value in bytes, use \c BUFSIZE \c << \c 1 instead.
 */
#define BUFSIZE ( (PAGEWIDTH+OFFSIZE)*(LINEVAL+1) )

#define DITHER_CONST  0x12210


// internal buffer for hblt routines

#define HBLT_BUFFER 64		// default 64 words = 512 pixels



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
 * \brief A screen that can be drawn upon using GGL.
 *
 * All GGL operations are performed on an instance of this data structure.
 * It represents basic information about the size and location of the screen
 * buffer, among other things.
 */
typedef struct {
	int *addr;  //! Word-aligned address of the surface buffer
	int width;  //! Width (in pixels) of the buffer
	int x,y;    //! Offset coordinates within the buffer
} gglsurface;

/*!
 * \brief A filter for pixels being drawn to a surface.
 *
 * A filter is a unary operation (using only one value) that is applied to
 * colors being drawn to a screen.  Filters are very flexible and can be used
 * for a wide variety of drawing purposes, including color modification and
 * texturing.  However, they lack the ability to combine colors with those
 * already on the surface.
 *
 * \sa ggloperator
 */
typedef unsigned int (*gglfilter)(unsigned int pixels,int param);

/*!
 * \brief An operator for pixels being drawn to a surface.
 *
 * An operator is a unary operation (using two values) that is applied to
 * colors being drawn to a screen.  The two operands are the new color being
 * drawn, and the old color at that location.  Operators can be used to
 * implement a great variety of features, including either partial or complete
 * transparency.  Operators are more powerful than filters, but at a slightly
 * higher performance cost.
 *
 * \sa gglfilter
 */
typedef unsigned int (*ggloperator)(unsigned int dest,unsigned int source,int param);




// inline routines

#define ggl_leftmask(cx) ((1<<(( (cx)&7)<<2))-1)	// create mask
#define ggl_rightmask(cx) ((-1)<<((((cx)&7)+1)<<2))	// create mask


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
 * This function actually switches the calculator LCD controller into 16-color
 * grayscale mode, with the given address for a frame buffer.  This should be
 * done for stand-alone GGL applications.  (HPG applications using GGL should
 * instead use HPG's \c hpg_set_mode_gray16 to perform the same task.)
 *
 * \param framebuf A pointer to the new LCD screen's frame buffer.  This is
 *                 generally found in the gglsurface::addr field of a
 *                 ::gglsurface.
 */
void ggl_setmode(int *framebuf);

/*!
 * \brief Saves the state of the LCD controller.
 *
 * Calling this function results in the current state of the LCD controller
 * being stored in the given buffer.  When the application is finished, the
 * state can be restored by passing the same buffer to ::ggl_restore.
 *
 * This function should be used by applications that use GGL exclusively.  If
 * HPG is in use, the application should use hpg_cleanup when finished to
 * restore the LCD controller to a known state.  It is dangerous to make
 * changes to the LCD controller state while HPG is operating.
 *
 * \param buf A flat buffer, with a size of at least ::STATEBUFSIZE bytes.
 * \sa ggl_restore
 */
void ggl_save(int *buf); // save LCD controller state

/*!
 * \brief Restores the state of the LCD controller.
 *
 * Calling this function results in the current state of the LCD controller
 * being restored from the given buffer.  The buffer should have been filled
 * in earlier by a call to ::ggl_save.
 *
 * This function should be used by applications that use GGL exclusively.  If
 * HPG is in use, the application should use hpg_cleanup when finished to
 * restore the LCD controller to a known state.  It is dangerous to make
 * changes to the LCD controller state while HPG is operating.
 *
 * \param buf A flat buffer, with a size of at least ::STATEBUFSIZE bytes.
 * \sa ggl_save
 */
void ggl_restore(int *buf);	// restore saved LCD state

/*
 * \brief Causes a different GGL surface to be displayed.
 *
 * This function allows the use of several GGL surfaces in an application.
 * It causes the LCD controller to begin displaying a different screen.  No
 * VSYNC is performed, so some tearing is possible unless external VSYNC is
 * checked before calling this function.
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
 * \brief Pokes a color into a specific pixel of the frame buffer.
 *
 * Colors the given pixel by the given color.  The pixel is identified by an
 * offset from the beginning of the frame buffer, which is defined as
 * \c x \c + \c y \c * \c 160 for a given x and y coordinate.  The calling
 * procedure is responsible for correctly calculating the offset.
 *
 * \param buff  The start address of the framebuffer.
 * \param off   The offset (\c x \c + \c 160 \c * \c y).
 * \param color The color, between 0 and 15.
 */
void ggl_pltnib(int *buff,int off,int color);	// poke a pixel (off in nibbles)

/*!
 * \brief Peeks a color from a specific pixel of the frame buffer.
 *
 * Retrieves the color of the given pixel.  The pixel is identified by an
 * offset from the beginning of the frame buffer, which is defined as
 * \c x \c + \c y \c * \c 160 for a given x and y coordinate.  The calling
 * procedure is responsible for correctly calculating the offset.
 *
 * \param buff  The start address of the framebuffer.
 * \param off   The offset (\c x \c + \c 160 \c * \c y).
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
 * \param srf   The surface to draw on.
 * \param y     The Y coordinate of the line.
 * \param xl    The left-most x coordinate of the line.
 * \param xr    The right-most x coordinate of the line.
 * \param color The color pattern.  This is a 32-bit value, containing 8
 *              consecutive pixels worth of color.  For solid colors, set the
 *              color to contain the same pattern on every nibble (for color 8,
 *              use 0x88888888), or call ::ggl_mkcolor for that purpose.  The
 *              colors in this pattern will be used consecutively in the
 *              horizontal direction.
 */
void ggl_hline(gglsurface *srf,int y,int xl,int xr, int color); // fast low-level horizontal line

/*!
 * \brief Draws a vertical line on a surface.
 *
 * Draws a vertical line onto the given surface, in the given color or color
 * pattern.
 *
 * \param srf   The surface to draw on.
 * \param x     The x coordinate of the line.
 * \param yt    The top-most y coordinate of the line.
 * \param yb    The bottom-most y coordinate of the line.
 * \param color The color pattern.  This is a 32-bit value, containing 8
 *              consecutive pixels worth of color.  For solid colors, set the
 *              color to contain the same pattern on every nibble (for color 8,
 *              use 0x88888888), or call ::ggl_mkcolor for that purpose.  The
 *              colors in this pattern will be used consecutively in the
 *              vertical direction, making this different from the use of the
 *              color parameter in other GGL functions.
 */
void ggl_vline(gglsurface *srf,int x,int yt,int yb, int color); // fast low-level vertical line

/*!
 * \brief Draws a rectangle on a surface.
 *
 * Fills in a rectangle onto the given surface, with the given color or color
 * pattern.  The color pattern is oriented horizontally, so that the color
 * remains the same in any given column of pixels.
 *
 * \param srf   The surface to draw on.
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
 * \param srf   The surface to draw on.
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

// for antialiased lines, call first ggl_initaline and call ggl_endaline for cleanup
// notice that ggl_init/ggl_exit do NOT call ggl_initaline
// anitaliased lines are always 3 pixels wide
void ggl_aline(gglsurface *srf,int x1,int y1,int x2,int y2);	// ANTIALIASED LINES

// bit-blit functions

// LOW-LEVEL row copy functions
// ggl_ll_hblt is a general nibble-aligned memcpy
// WARNING: npixels is limited to 512!!
//          if you need more than that, increase the constant HBLT_BUFFER above
//          and RE-COMPILE the ggl library
// dest and src must be word-aligned
// destoff and srcoff are offsets in nibbles from the word-aligned pointers
// npixels is the number of nibbles to copy
// note: hblt will behave well even if the zones overlap, no need for moveup/movedown

void ggl_hblt(int *dest,int destoff,int *src,int srcoff, int npixels); // copy a row of pixels

// same behavior as hblt but specifying a transparent color
// every pixel in *src with the transparent color will not affect the
// corresponding pixel in *dest
void ggl_hbltmask(int *dest,int destoff,int *src,int srcoff, int npixels, int tcol); // copy a row of pixels w/mask

// rectangle blt
// note: see gglsurface above for complete understanding of the behavior of these routines
// ggl_bitblt loops from top to bottom
void ggl_bitblt(gglsurface *dest,gglsurface *src,int width, int height); // copy a rectangular region
// ggl_revblt loops from bottom to top, for overlapping zones
void ggl_revblt(gglsurface *dest,gglsurface *src,int width, int height); // copy a rectangular region, reverse loop
// ggl_ovlblt chooses to use normal/reverse loop based on the addresses
// use it when the direcction of movement is unknown
void ggl_ovlblt(gglsurface *dest,gglsurface *src,int width, int height); // copy overlapped regions
// ggl_bitbltmask behaves exactly as ggl_bitblt but using tcol as a transparent color
#define ggl_bitbltmask(dest,src,width,height,tcol)  ggl_bitbltoper(dest,src,width,height,tcol,&ggl_opmask)


// rectangle scrolling routines
// dest contains the surface to scroll, and width and height define the rectangle
// the area that needs to be redrawn after the scroll is not erased or modified by these routines 
void ggl_scrollup(gglsurface *dest,int width, int height, int npixels); // scroll npixels up
void ggl_scrolldn(gglsurface *dest,int width, int height, int npixels); // scroll npixels dn
void ggl_scrolllf(gglsurface *dest,int width, int height, int npixels); // scroll npixels left
void ggl_scrollrt(gglsurface *dest,int width, int height, int npixels); // scroll npixels right

// custom filters and operators

// low-level row filtering routine
void ggl_hbltfilter(int *dest,int destoff, int npixels, int param,gglfilter filterfunc);
// bitmap filtering routine
void ggl_filter(gglsurface *dest,int width, int height, int param, gglfilter filterfunc);

// low-level row operator routine
void ggl_hbltoper(int *dest,int destoff,int *src,int srcoff, int npixels, int param,ggloperator foperator);
// bitblt operator routine
void ggl_bitbltoper(gglsurface *dest,gglsurface *src,int width, int height,int param,ggloperator fop);

// predefined filters and operators

// filters (unary operators)
// ligthens an image by subtracting param from all pixels
unsigned ggl_fltlighten(unsigned word,int param);
// darkens an image by adding param to all pixels
unsigned ggl_fltdarken(unsigned word,int param);

// operators (between two surfaces)
// standard mask, tcolor in src is considered transparent
unsigned ggl_opmask(unsigned dest,unsigned src,int tcolor);
// transparency blend, weight is 0 = src is opaque, 16 = src is fully transparent
unsigned ggl_optransp(unsigned dest,unsigned src,int weight);




// miscellaneous

// ggl_mkcolor repeats the same color on every nibble
// ggl_mkcolor(2) will return 0x22222222
int ggl_mkcolor(int color); // solid color generator

// ggl_mkcolor32 creates virtual 32-colors by using 8x8 patterns
// col32 is a value from 0 to 30, being 30=black, 0=white
// note: the user is responsible to provide a valid int[8] buffer in the
// pattern argument
void ggl_mkcolor32(int col32, int *pattern);	// 50% dither pattern generator for 31 colors
	
// ANTIALIAS INITIALIZATION

// ggl_initaline initializes tables needed for antialiased lines
void ggl_initaline();
// ggl_endaline cleans up the memory allocated by ggl_initaline
void ggl_endaline();
