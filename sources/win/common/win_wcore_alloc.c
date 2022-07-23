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

win_widget_t *win_wcore_alloc(
    void (*install) (win_widget_t *),
    void (*deinstall) (win_widget_t *),
    void (*destroy) (win_widget_t *),
    void (*pref_size) (win_widget_t *, int *, int *),
    int focusable, void *widget_data)
{
    win_init();

    win_widget_t *widget = (win_widget_t *) malloc(sizeof(win_widget_t));
    memset((void *) widget, 0, sizeof(win_widget_t));

    widget->install = install;
    widget->deinstall = deinstall;
    widget->destroy = destroy;
    widget->pref_size = pref_size;
    widget->focus_lost = NULL;
    widget->focus_gained = NULL;

    widget->bgcolor = HPG_COLOR_WHITE;
    widget->fgcolor = HPG_COLOR_BLACK;
    widget->font = hpg_get_minifont();

    widget->focusable = (focusable != 0);
    widget->focus = 0;
    widget->transparent = 0;

    widget->widget_data = widget_data;

    win_widget_pack(widget);

    return widget;
}
