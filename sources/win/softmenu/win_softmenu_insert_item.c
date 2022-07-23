//& ****************************************************************************
//&
//& Copyright (C) 2004 HP-GCC Team
//&
//& Portions of this code are based on code that is copyright 2005 by
//& by Philippe Salmon.
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
#include <hpstring.h>
#include <win.h>
#include <wincore.h>
#include "softmenupriv.h"

void win_softmenu_insert_item(
    win_widget_t *widget, int entry, char *label,
    int event_num, void *event_data)
{
    struct win_softmenu *menu =
        (struct win_softmenu *) win_wcore_get_data(widget);
    int next = entry, i;

    /*
     * Find the next blank slot after the insertion position.  If it is the
     * insertion position, that's okay too!
     */
    if (next > WIN_SOFTMENU_MAX_ITEMS - 1) next = WIN_SOFTMENU_MAX_ITEMS - 1;
    while ((next < WIN_SOFTMENU_MAX_ITEMS - 1)
        && (menu->select & (1 << next))) next++;

    /*
     * Copy existing menu items forward.  The source of the copy is at index
     * i, and the target at index next.
     */
    for (i = next - 1; i >= entry; next = i, i--)
    {
        int mask = menu->select & (1 << i);
        menu->select = (menu->select & ~mask) | (mask << 1);

        strcpy(menu->items[next].label, menu->items[i].label);

        menu->items[next].bg_color = menu->items[i].bg_color;
        menu->items[next].bg_disable_color = menu->items[i].bg_disable_color;
        menu->items[next].fg_color = menu->items[i].fg_color;
        menu->items[next].fg_disable_color = menu->items[i].fg_disable_color;
        menu->items[next].enabled = menu->items[i].enabled;
        menu->items[next].event_num = menu->items[i].event_num;
        menu->items[next].event_data = menu->items[i].event_data;
    }

    win_softmenu_set_item(widget, entry, label, event_num, event_data);
}
