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

struct win_focus_node *_win_focus_list = NULL;

void win_add_widget(win_widget_t *widget)
{
    struct win_focus_node *node = (struct win_focus_node *)
        malloc(sizeof(struct win_focus_node));
    node->widget = widget;

    if (_win_focus_list == NULL)
    {
        node->next = node;
        node->prev = node;

        _win_focus_list = node;
        if (widget->focusable)
        {
            widget->focus = 1;
            if (widget->focus_gained) (*widget->focus_gained) (widget);
        }
    }
    else
    {
        node->next = _win_focus_list;
        node->prev = _win_focus_list->prev;

        node->next->prev = node;
        node->prev->next = node;

        if (!node->next->widget->focus && widget->focusable)
        {
            widget->focus = 1;
            _win_focus_list = node;
            if (widget->focus_gained) (*widget->focus_gained) (widget);
        }
    }

    (*widget->install) (widget);
    win_repaint();
}
