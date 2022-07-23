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

#include <hpstdlib.h>
#include "winpriv.h"

void win_remove_widget(win_widget_t *widget)
{
    win_init();

    if (_win_focus_list == NULL) return;

    struct win_focus_node *orig = _win_focus_list;
    struct win_focus_node *next = orig;

    do
    {
        if (next->widget == widget)
        {
            if (next->next == next)
            {
                _win_focus_list = NULL;
            }
            else
            {
                if (next == orig) win_focus_next();

                next->next->prev = next->prev;
                next->prev->next = next->next;
            }

            free(next);

            (*widget->deinstall) (widget);
            win_repaint();

            break;
        }

        next = next->next;
    }
    while (next != orig);
}
