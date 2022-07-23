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

#include <win.h>
#include <wincore.h>

#include "boxpriv.h"

void win_box_add_with(win_widget_t *widget, win_widget_t *child,
    int row, int col, double xweight, double yweight,
    int pwidth, int pheight, int align_x, int align_y)
{
    struct win_box *box =
        (struct win_box *) win_wcore_get_data(widget);

    struct box_entry *entry = (struct box_entry *)
        malloc(sizeof(struct box_entry));

    entry->widget = child;
    entry->next = NULL;

    entry->row = row;
    entry->col = col;

    entry->pwidth = pwidth;
    entry->pheight = pheight;

    entry->xweight = xweight;
    entry->yweight = yweight;

    entry->align_x = align_x;
    entry->align_y = align_y;

    if (box->tail == NULL)
    {
        box->head = box->tail = entry;
    }
    else
    {
        box->tail->next = entry;
        box->tail = entry;
    }
}
