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

#ifndef _WINTEXT_H_
#define _WINTEXT_H_

/*!
 * \file wintext.h
 * \brief Fuctions to display a text widget in the window system.
 *
 * Text widgets are used for two purposes: to display text, and to allow the
 * user to edit text.  The two tasks are selected by settings of the
 * \c focusable flag of the component.
 */

/*!
 * \brief Creates a new text widget as a label.
 *
 * Allocates and returns a new text widget, with its initial text set to the
 * given value.  The widget is not focusable, and has no extra memory reserved
 * for future changes to the text.
 *
 * The text is initially set to black text on a white background, opaque,
 * with the minifont.
 *
 * \return A pointer to the newly allocated text widget.
 */
win_widget_t *win_text_new_label(char *text);

/*!
 * \brief Creates a new text widget as an entry field.
 *
 * Allocates and returns a new text widget, with no initial text, and a given
 * amount of memory set for the user to type.  The widget is focusable, and is
 * intended to be used as a field for input.
 *
 * The text is initially set to black text on a white background, opaque,
 * with the minifont.
 *
 * \return A pointer to the newly allocated text widget.
 */
win_widget_t *win_text_new_entry(int len);

/*!
 * \brief Sets the contents of a text widget.
 *
 * After this call, the widget will contain the new text.  The text size
 * is not changed to match the new text.  You may need to modify the width or
 * height of the label by calling ::win_widget_pack or ::win_widget_set_size
 * to avoid cutting off the text.
 *
 * \param text The new text, as a null-terminated C string.
 */
void win_text_set_text(win_widget_t *widget, char *text);

/*!
 * \brief Retrieves the contents of a text widget.
 *
 * The result of this method is a pointer to an internal text buffer.  It may
 * safely be used only until the next call to a windowing system method.  If it
 * will be stored for later use, then the contents should be copied to an
 * alternate location.
 *
 * Modifications made to the returned text array are live, and require only
 * a call to ::win_repaint to display on the screen.  However, the amount of
 * memory reserved for text is indeterminate.  If the text will extended for
 * longer than the current string length, the application should call
 * ::win_text_set_text with a different text buffer instead.  This behavior
 * may change in a future release of the library, depending on user feedback.
 *
 * \param text The new text, as a null-terminated C string.
 */
char *win_text_get_text(win_widget_t *widget);

#endif /* _WINTEXT_H_ */
