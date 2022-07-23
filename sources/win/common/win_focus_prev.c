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

void win_focus_prev(void)
{
    if (_win_focus_list == NULL) return;

    if (_win_focus_list->widget->focus_lost)
    {
        (*_win_focus_list->widget->focus_lost)(_win_focus_list->widget);
    }

    struct win_focus_node *orig = _win_focus_list;
    struct win_focus_node *prev = orig->prev;

    while (prev != orig)
    {
        if (prev->widget->focusable)
        {
            orig->widget->focus = 0;
            prev->widget->focus = 1;
            _win_focus_list = prev;

            win_repaint();
            break;
        }

        prev = prev->prev;
    }

    if (_win_focus_list->widget->focus_gained)
    {
        (*_win_focus_list->widget->focus_gained)(_win_focus_list->widget);
    }
}
