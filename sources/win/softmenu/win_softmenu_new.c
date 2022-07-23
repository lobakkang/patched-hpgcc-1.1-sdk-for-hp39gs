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
#include <hpkeyb49.h>
#include <hpgraphics.h>

#include <win.h>
#include <wincore.h>

#include "softmenupriv.h"

extern void *alloca(int size);

static int paint(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    win_wcore_paint_base(widget);

    struct win_softmenu *menu =
        (struct win_softmenu *) win_wcore_get_data(widget);

    int i;

    for (i = menu->start; i < menu->start + 6; i++)
    {
        int mask = 1 << i;
        if (menu->select & mask)
        {
            int length;
            int enabled = menu->items[i].enabled;
            int off = i - menu->start;

            length = strlen(menu->items[i].label);

            if (enabled) hpg_set_color(hpg_stdscreen, menu->items[i].bg_color);
            else hpg_set_color(hpg_stdscreen, menu->items[i].bg_disable_color);

            hpg_fill_rect(off * 22, 73, (off * 22) + 20, 79);

            if (enabled) hpg_set_color(hpg_stdscreen, menu->items[i].fg_color);
            else hpg_set_color(hpg_stdscreen, menu->items[i].fg_disable_color);

            hpg_draw_text(menu->items[i].label,
                off * 22 + (22 - length * 4) / 2, 74);
        }
    }

    return 0;
}

static int keyhandler(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_softmenu *menu =
        (struct win_softmenu *) win_wcore_get_data(widget);

    win_keytyped_t *event = (win_keytyped_t *) event_data;

    if (event->alpha > 0) return 0;

    int index;

    if (event->keycode == KB_A) index = 0;
    else if (event->keycode == KB_B) index = 1;
    else if (event->keycode == KB_C) index = 2;
    else if (event->keycode == KB_D) index = 3;
    else if (event->keycode == KB_E) index = 4;
    else if (event->keycode == KB_F) index = 5;
    else if (event->keycode == KB_L) // L key is NXT
    {
        if (event->rshift > 0) return 0;

        if (event->lshift > 0)
        {
            menu->start -= 6;
            if (menu->start < 0) menu->start = WIN_SOFTMENU_MAX_ITEMS - 6;

            win_repaint();
        }
        else
        {
            menu->start += 6;
            if ((menu->start > WIN_SOFTMENU_MAX_ITEMS - 6)
                || ((menu->select >> menu->start) == 0))
            {
                menu->start = 0;
            }

            win_repaint();
        }

        return 1;
    }
    else return 0;

    index += menu->start;
    if (menu->select & (1 << index))
    {
        struct win_softmenu_item *item = &(menu->items[index]);
        if (!item->enabled) return 0;

        win_softmenu_event_t *newevent = (win_softmenu_event_t *)
            alloca(sizeof(win_softmenu_event_t));

        newevent->lshift = event->lshift;
        newevent->rshift = event->rshift;
        newevent->extra_data = item->event_data;

        return win_post_event(item->event_num, newevent);
    }

    return 0;
}

static void install(win_widget_t *widget)
{
    win_add_event_handler(WIN_KEY_TYPED,
        1000000000, keyhandler, (void *) widget);
    win_add_event_handler(WIN_REPAINT_EVENT,
        2000000000, paint, (void *) widget);
}

static void deinstall(win_widget_t *widget)
{
    win_remove_event_handler(WIN_KEY_TYPED, keyhandler, (void *) widget);
    win_remove_event_handler(WIN_REPAINT_EVENT, paint, (void *) widget);
}

static void destroy(win_widget_t *menu)
{
    free(win_wcore_get_data(menu));
}

static void pref_size(win_widget_t *widget, int *x, int *y)
{
    *x = 131;
    *y = 80;
}

win_widget_t *win_softmenu_new(void)
{
    struct win_softmenu *menu_data = (struct win_softmenu *)
        malloc(sizeof(struct win_softmenu));
    memset((void *) menu_data, 0, sizeof(struct win_softmenu));

    menu_data->select = 0;
    menu_data->start = 0;

    win_widget_t *widget = win_wcore_alloc(
        install, deinstall, destroy, pref_size, 0, (void *) menu_data);
    win_widget_set_transparent(widget, 1);

    return widget;
}
