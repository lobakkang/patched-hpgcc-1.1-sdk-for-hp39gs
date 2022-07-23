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

#include <win.h>
#include <wincore.h>

#include "softmenupriv.h"

void win_softmenu_set_colors(win_widget_t *widget, int entry,
    unsigned char fg_color, unsigned char bg_color)
{
    struct win_softmenu *menu =
        (struct win_softmenu *) win_wcore_get_data(widget);

    menu->items[entry].fg_disable_color = fg_color;
    menu->items[entry].bg_disable_color = bg_color;

    win_repaint();
}
