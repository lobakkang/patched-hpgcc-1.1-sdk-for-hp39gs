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

#ifndef _WINCHECKBOX_H_
#define _WINCHECKBOX_H_

#include <winprogress.h>

/*!
 * \file wincheckbox.h
 * \brief Fuctions to display a checkbox in the window system.
 *
 * Check boxes are on/off selectable widgets which can be used to represent
 * or edit boolean values.
 */

/*!
 * \brief Creates a new checkbox.
 *
 * Allocates and returns a new checkbox widget, with its initial label set to
 * the given value.  
 *
 * The widget is initially set to black text on a white background, opaque,
 * with the minifont.
 *
 * \param label The label of the check box.  The label is used in-place, so
 *              this parameter should not point to a temporary buffer.
 *
 * \return A pointer to the newly allocated checkbox widget.
 */
win_widget_t *win_checkbox_new(char *label);

/*!
 * \brief Sets the label of a checkbox widget.
 *
 * After this call, the widget will be assigned the new label.  The size
 * is not changed to match the new text.  You may need to modify the width or
 * height of the widget by calling ::win_widget_pack or ::win_widget_set_size
 * to avoid cutting off the label.
 *
 * \param widget A pointer to the new checkbox widget.
 * \param label  The new label, as a null-terminated C string.
 */
void win_checkbox_set_label(win_widget_t *widget, char *label);

/*!
 * \brief Retrieves the label of a checkbox widget.
 *
 * The result of this method is the label assigned to a checkbox widget.
 *
 * \param widget  A pointer to the checkbox widget.
 * \return The label, as a null-terminated C string.
 */
char *win_text_get_text(win_widget_t *widget);

/*!
 * \brief Sets the selection state of a checkbox widget.
 *
 * After this call, the widget will be assigned the new selection state.
 *
 * \param widget A pointer to the new checkbox widget.
 * \param sel    The new selection state, either zero or non-zero.
 */
void win_checkbox_set_selected(win_widget_t *widget, int sel);

/*!
 * \brief Retrieves the selection state of a checkbox widget.
 *
 * The result of this method is non-zero if the checkbox widget is selected
 * (checked), or zero if it is not selected.
 *
 * \param widget  A pointer to the checkbox widget.
 * \return The selection state, either zero or non-zero.
 */
int win_text_is_selected(win_widget_t *widget);

/*!
 * \brief Sets the menu tie-in for a checkbox.
 *
 * Although a checkbox widget can always be toggled with the +/- key, it is
 * common to also designate a soft menu tie-in.  This will cause a soft menu
 * item to become visible to toggle the checkbox widget when it has focus.
 * Typically, the same menu item would be used for all checkbox widgets and
 * all other widgets that support soft menu tie-in.
 *
 * This should be set before the checkbox is added to the window system.
 * Otherwise, the menu changes may not happen until the next time focus
 * changes for the check box.
 *
 * \param widget  A pointer to the checkbox widget.
 * \param menu    The soft menu to tie in to the checkbox.
 * \param idx     The menu item index used to tie in to the checkbox.
 */
void win_checkbox_set_menu(
    win_widget_t *widget, win_widget_t *menu, int idx);

#endif /* _WINCHECKBOX_H_ */
