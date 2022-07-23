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
#include <hpgraphics.h>

#include <win.h>
#include <wincore.h>

#include "softmenupriv.h"

void win_softmenu_set_item(
    win_widget_t *widget, int entry, char *label,
    int event_num, void *event_data)
{
    struct win_softmenu *menu =
        (struct win_softmenu *) win_wcore_get_data(widget);

    strncpy(menu->items[entry].label, label, 5);
    menu->items[entry].label[5] = '\0';

    unsigned char fgcolor, bgcolor;
    win_widget_get_colors(widget, &fgcolor, &bgcolor);

    /*
     * Default colors are taken from the component colors, but inverted.
     * Note that these are not updated if the component colors change.
     */
    menu->items[entry].bg_color = fgcolor;
    menu->items[entry].fg_color = bgcolor;

    /*
     * Default disabled colors are half of the enabled colors, rounding down.
     * This will cause the button to stop appearing on monochrome screens, or
     * to be grayed out in grayscale modes.
     */
    menu->items[entry].bg_disable_color = fgcolor / 2;
    menu->items[entry].fg_disable_color = bgcolor / 2;

    /*
     * Menu items default to enabled.
     */
    menu->items[entry].enabled = 1;

    menu->items[entry].event_num = event_num;
    menu->items[entry].event_data = event_data;

    menu->select |= (1 << entry);

    win_repaint();
}
