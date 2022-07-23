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

#ifndef _WINCHOOSE_H_
#define _WINCHOOSE_H_

/*!
 * \file winchoose.h
 * \brief Fuctions to display a choose widget in the window system.
 *
 * Choose widgets provide a list of choices, allowing the user to choose
 * from between them.
 */

/*!
 * \brief Creates a new choose widget.
 *
 * Allocates and returns a new choose widget, with no initial values.
 *
 * The widget is initially set to black text on a white background, opaque,
 * with the minifont.
 *
 * \return A pointer to the newly allocated choose widget.
 */
win_widget_t *win_choose_new(void);

void win_choose_add(win_widget_t *widget, char *option);
void win_choose_add_with_label(
    win_widget_t *widget, char *option, char *label);
void win_choose_remove(win_widget_t *widget, char *option);

char *win_choose_get_choice(win_widget_t *widget);
int win_choose_get_index(win_widget_t *widget);
void win_choose_set_choice(win_widget_t *widget, char *choice);
void win_choose_set_index(win_widget_t *widget, int index);

void win_choose_set_menu(win_widget_t *widget, win_widget_t *menu, int idx);

#endif /* _WINCHOOSE_H_ */
