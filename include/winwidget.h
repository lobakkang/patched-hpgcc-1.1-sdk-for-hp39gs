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

#ifndef _WIN_WIDGET_H_
#define _WIN_WIDGET_H_

#include <hpgraphics.h>

/*!
 * \file  winwidget.h
 * \brief Component infrastructure for the window system.
 *
 * The bulk of the HPGCC window system consists of widgets.  The functions
 * and constants defined here provide the basis of the widget model.
 *
 * Coming soon: this space will hold documentation on: common operations for
 * all widgets (which don't exist yet - planned are functions to set size
 * and location, focusability, and enable/disable); how to build a custom
 * widgets, etc.  Also, I will add a description of the surprising
 * differences between HPGCC's window system and others (for example, there
 * is no widget hierarchy; all widgets exist on their own).
 */

/*!
 * \brief Event number for repaint events.
 */
#define WIN_REPAINT_EVENT 7

/*!
 * \brief Data type for a widget.
 *
 * This opaque type is used to identify individual widgets to the window
 * system.  It is returned from all functions that create widgets, and is
 * later used to manage and/or destroy those widgets.
 */
typedef struct win_widget win_widget_t;

/*!
 * \brief De-allocates a widget.
 *
 * All memory used by the given widget will be freed to the heap.
 *
 * \warning Before destroying a widget, the application should ensure that
 *          the widget has been removed from the window system, and that
 *          any residual events have been delivered.  It is often
 *          sufficient to wait for the next idle event or return non-zero from
 *          the event handler where the widget is destroyed.
 *
 * \param widget The widget to be destroyed.
 */
void win_widget_destroy(win_widget_t *widget);

/*!
 * \brief Adds a widget to the window system, making it functional.
 *
 * This is equivalent to other window and GUI frameworks' concepts of showing
 * a widget or making it visible.  The widget will appear immediately
 * on the screen.
 *
 * \param widget  The widget to add.
 */
void win_add_widget(win_widget_t *widget);

/*!
 * \brief Removes a widget from the window system.
 *
 * This is equivalent to other window and GUI frameworks' concepts of hiding
 * a widget.  The widget will no longer receive events, and will therefore
 * not appear on the screen.
 *
 * \param widget  The widget to remove.
 */
void win_remove_widget(win_widget_t *widget);

/*!
 * \brief Moves focus to the next widget.
 *
 * The focus will pass to the next focusable widget, in the order the widgets
 * were added to the window system.  If there is no other focusable widget,
 * then this function has no effect.
 *
 * Although this function is typically called from within a widget, it may
 * also be called from the application.
 */
void win_focus_next(void);

/*!
 * \brief Moves focus to the previous widget.
 *
 * The focus will pass to the previous focusable widget, in the order the
 * widgets were added to the window system.  If there is no other focusable
 * widget, then this function has no effect.
 *
 * Although this function is typically called from within a widget, it may
 * also be called from the application.
 */
void win_focus_prev(void);

/*!
 * \brief Determines if a widget has input focus.
 *
 * \return Non-zero if the widget has focus; or zero if it does not.
 */
int win_widget_has_focus(win_widget_t *widget);

/*!
 * \brief Sets the location of a widget on the screen.
 *
 * The precise meaning of this information depends on the component.  For
 * some components, it may be completely ignored.
 *
 * \param x The x coordinate for the left edge of the widget.
 * \param y The y coordinate for the top edge of the widget.
 */
void win_widget_set_location(win_widget_t *widget, int x, int y);

/*!
 * \brief Retrieves the location of a widget on the screen.
 *
 * \param widget The widget to operate on.
 * \param x      Pointer to storage for the x coordinate of the widget.
 * \param y      Pointer to storage for the y coordinate of the widget.
 */
void win_widget_get_location(win_widget_t *widget, int *x, int *y);

/*!
 * \brief Sets the size of a widget on the screen.
 *
 * The precise meaning of this information depends on the component.  For
 * some components, it may be completely ignored.
 *
 * \param widget The widget to resize.
 * \param w      The width of the widget in pixels.
 * \param h      The height of the widget in pixels.
 *
 * \see win_widget_pack
 */
void win_widget_set_size(win_widget_t *widget, int x, int y);

/*!
 * \brief Retrieves the size of a widget on the screen.
 *
 * \param widget The widget to operate on.
 * \param w      Pointer to storage for the width of the widget in pixels.
 * \param h      Pointer to storage for the height of the widget in pixels.
 */
void win_widget_get_size(win_widget_t *widget, int *w, int *h);

/*!
 * \brief Sets the widget to its preferred size.
 *
 * The widget will be resized to the size it reports as its "preferred" size.
 * The preferred size of a widget is the size that the widget believed it needs
 * in order to look presentable on the screen.  The means of determining the
 * preferred size are widget-specific.
 *
 * \param widget The widget to resize.
 *
 * \see win_widget_set_size
 */
void win_widget_pack(win_widget_t *widget);

/*!
 * \brief Sets the colors of a widget.
 *
 * The widget colors are used in a widget-specific way to determine how to
 * draw the widget on the screen.  Typically, the background color is used to
 * fill the entire area taken by the widget, while the foreground color is
 * used for drawing the widget's actual contents.  However, some widgets may
 * use these colors in other ways, or may ignore them entirely.
 *
 * Setting colors will not change the widget's transparency.  If the widget
 * is transparent, the value of the background color is likely to be ignored
 * until it becomes opaque.
 *
 * \param widget  The widget to operate on.
 * \param fgcolor The new foreground color.
 * \param bgcolor The new background color.
 */
void win_widget_set_colors(win_widget_t *widget,
    unsigned char fgcolor, unsigned char bgcolor);

/*!
 * \brief Retrieves the colors of a widget.
 *
 * \param widget   The widget to operate on.
 * \param fgcolor  Pointer to storage for the foreground color.
 * \param bgcolor  Pointer to storage for the background color.
 */
void win_widget_get_colors(win_widget_t *widget,
    unsigned char *fgcolor, unsigned char *bgcolor);

/*!
 * \brief Sets the font of a widget.
 *
 * After this call, the widget's font is changed to the given value.  The
 * font is used to draw text on the widget.  The exact use of the font is
 * widget-specific, and some widgets may use other fonts for rendering.
 * However, the intent is that this font will be used for the widget's text.
 *
 * Setting the font may affect the preferred size of the widget.  The widget's
 * size is not modified by this call.  If the size should be updated, you must
 * call ::win_widget_pack or ::win_widget_set_size to do so.
 *
 * \param widget  The widget to operate on.
 * \param font    The new font.
 */
void win_widget_set_font(win_widget_t *widget, hpg_font_t *font);

/*!
 * \brief Retrieves the font of a widget.
 *
 * \param widget  The widget to operate on.
 * \return The widget's current font.
 */
hpg_font_t *win_widget_get_font(win_widget_t *widget);

/*!
 * \brief Sets the transparency of a widget.
 *
 * After this call, the widget should appear with the new transparency.  It
 * is intended that a transparent widget does not overwrite its background.
 * Setting transparency can be used, for example, to preserve a background
 * image that is drawn in light grays by a high-priority event handler for
 * ::WIN_REPAINT_EVENT.
 *
 * \param widget  The widget to operate on.
 * \param val     1 if the widget should be transparent; 0 otherwise.
 */
void win_widget_set_transparent(win_widget_t *widget, unsigned val);

/*!
 * \brief Triggers a repaint of the screen.
 *
 * The repaint will occur at at some point during the dispatch of a coming
 * idle event.  In order to avoid unnecessary painting when multiple changes
 * occur, several consecutive repaints are combined in a single paint
 * operation by the window system.
 */
void win_repaint(void);

#endif /* _WIN_WIDGET_H_ */
