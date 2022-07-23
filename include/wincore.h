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

#ifndef _WIN_CORE_H_
#define _WIN_CORE_H_

/*!
 * \file  wincore.h
 * \brief API for writing custom window system components.
 *
 * Writing custom components for the window system involves several repetitive
 * tasks, and requires a little more knowledge about the window system
 * internals than is required to use them.  This header file contains the
 * API needed to create widgets that work with the window system.
 */

/*!
 * \brief Allocates a new widget.
 *
 * This function allocates and returns a new widget.  It is used as the base
 * for all widgets created in the HPGCC window system.  The function returns
 * a pointer to the newly allocated widget.  The parameters contain a large
 * amount of information about the widget to create.
 *
 * The caller should generally create the widget-specific data before calling
 * this function.  This function may interact with the widget as if it has been
 * fully initialized.
 *
 * \param install      The installation callback function.
 * \param deinstall    The de-installation callback function.
 * \param destroy      The deallocation callback function.
 * \param pref_size    The preferred size callback function.
 * \param focusable    Non-zero if the widget should be able to receive focus.
 * \param widget_data  An opaque pointer to widget-specific data.
 *
 * \return A pointer to the widget object that was created.
 */
win_widget_t *win_wcore_alloc(
    void (*install) (win_widget_t *),
    void (*deinstall) (win_widget_t *),
    void (*destroy) (win_widget_t *),
    void (*pref_size) (win_widget_t *, int *, int *),
    int focusable, void *widget_data);

/*!
 * \brief Retrieves the type-specific data for a widget.
 *
 * \param widget The widget for which data is needed.
 * \return The data object which was specified when the widget was created.
 */
void *win_wcore_get_data(win_widget_t *widget);
 
/*!
 * \brief Retrieves the preferred size of a widget.
 *
 * The preferred height of a widget is the size that it should be in order
 * to function properly.
 *
 * \param widget The widget for which data is needed.
 * \param width  A pointer to where the preferred width will be stored.
 * \param height A pointer to where the preferred height will be stored.
 */
void win_wcore_pref_size(win_widget_t *widget, int *width, int *height);

/*!
 * \brief Prepares to paint a widget.
 *
 * Preparation for painting includes clearing the background if the component
 * is not transparent, and setting an appropriate clipping rectangle, font,
 * color, and pattern.
 *
 * \param widget The widget being painted.
 */
void win_wcore_paint_base(win_widget_t *widget);

/*!
 * \brief Register functions to be called when focus changes.
 *
 * The two function pointers passed here point to functions which will be
 * called when the widget gains or loses focus.  NULL pointers will result in
 * no action being taken when focus changes.
 *
 * \param widget        The widget for which to watch focus.
 * \param focus_lost    Function to call when focus is lost.
 * \param focus_gained  Function to call when focus is gained.
 */
void win_wcore_notify_focus(win_widget_t *widget,
    void (*focus_lost) (win_widget_t *widget),
    void (*focus_gained) (win_widget_t *widget));

#endif /* _WIN_CORE_H_ */
