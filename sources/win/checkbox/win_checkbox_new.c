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
#include <hpstring.h>
#include <hpkeyb49.h>
#include <hpgraphics.h>

#include <win.h>
#include <wincore.h>

#include "checkpriv.h"

static int toggle_event = -1;

static int paint(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_checkbox *check =
        (struct win_checkbox *) win_wcore_get_data(widget);

    win_wcore_paint_base(widget);

    int x, y;
    win_widget_get_location(widget, &x, &y);

    unsigned char fgcolor, bgcolor;
    win_widget_get_colors(widget, &fgcolor, &bgcolor);

    if (win_widget_has_focus(widget))
    {
        hpg_fill_rect(x, y, x + 6, y + 8);
        hpg_set_color(hpg_stdscreen, bgcolor);
    }

    ULONGLONG pat = check->selected
        ? 0x003E040E1A302000ULL : 0x003E000000000000ULL;

    hpg_pattern_t *old_pat, *new_pat;
    old_pat = hpg_get_pattern(hpg_stdscreen);
    new_pat = hpg_alloc_pattern((char *) &pat, 8, 0);
    hpg_set_pattern(hpg_stdscreen, new_pat);
    hpg_fill_rect(x, y, x + 8, y + 8);

    hpg_set_pattern(hpg_stdscreen, old_pat);
    hpg_free_pattern(new_pat);

    hpg_set_color(hpg_stdscreen, fgcolor);
    hpg_draw_text(check->label, x + 8, y + 1);

    return 0;
}

static int keyhandler(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    if (!win_widget_has_focus(widget)) return 0;

    struct win_checkbox *check =
        (struct win_checkbox *) win_wcore_get_data(widget);
    win_keytyped_t *event = (win_keytyped_t *) event_data;

    switch (event->keycode)
    {
        case KB_UP:
            win_focus_prev();
            return 1;

        case KB_DN:
            win_focus_next();
            return 1;

        case KB_LF:
            win_focus_prev();
            return 1;

        case KB_RT:
            win_focus_next();
            return 1;

        case KB_W:
            if (!event->lshift && !event->rshift && !event->alpha)
            {
                check->selected = !check->selected;
                win_repaint();

                return 1;
            }
    }

    return 0;
}

static int toggle(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    if (!win_widget_has_focus(widget)) return 0;

    struct win_checkbox *check =
        (struct win_checkbox *) win_wcore_get_data(widget);

    check->selected = !check->selected;
    win_repaint();

    return 1;
}

static void install(win_widget_t *widget)
{
    if (toggle_event == -1) toggle_event = win_register_event();

    win_add_event_handler(WIN_REPAINT_EVENT,
        1000000000, paint, (void *) widget);
    win_add_event_handler(WIN_KEY_TYPED,
        1000000000, keyhandler, (void *) widget);
    win_add_event_handler(toggle_event,
        1000000000, toggle, (void *) widget);
}

static void deinstall(win_widget_t *widget)
{
    win_remove_event_handler(WIN_REPAINT_EVENT, paint, (void *) widget);
    win_remove_event_handler(WIN_KEY_TYPED, keyhandler, (void *) widget);
    win_remove_event_handler(toggle_event, toggle, (void *) widget);
}

static void destroy(win_widget_t *widget)
{
    free(win_wcore_get_data(widget));
}

static void pref_size(win_widget_t *widget, int *width, int *height)
{
    struct win_checkbox *check =
        (struct win_checkbox *) win_wcore_get_data(widget);

    int line = 0;
    int max_col = 0;
    int col = 0;

    char *p = check->label;

    while (1)
    {
        if (*p == '\0')
        {
            if (col > 0) line++;
            break;
        }
        else if (*p == '\n')
        {
            line++;
            col = 0;
        }
        else
        {
            if (++col > max_col) max_col = col;
        }

        p++;
    }

    hpg_font_t *font = win_widget_get_font(widget);

    *width = max_col * hpg_font_get_advance(font) + 8;
    *height = line * hpg_font_get_height(font) + 2;
}

static void focus_lost(win_widget_t *widget)
{
    struct win_checkbox *check =
        (struct win_checkbox *) win_wcore_get_data(widget);

    if (check->menu)
    {
        win_softmenu_delete_item(
            check->menu, check->menu_idx, check->menu_idx);
    }
}

static void focus_gained(win_widget_t *widget)
{
    struct win_checkbox *check =
        (struct win_checkbox *) win_wcore_get_data(widget);

    if (check->menu)
    {
        win_softmenu_set_item(
            check->menu, check->menu_idx, "CHK", toggle_event, NULL);
    }
}

win_widget_t *win_checkbox_new(char *label)
{
    struct win_checkbox *check = (struct win_checkbox *)
        malloc(sizeof(struct win_checkbox));
    memset((void *) check, 0, sizeof(struct win_checkbox));

    check->label = label;
    check->selected = 0;

    win_widget_t *widget = win_wcore_alloc(
        install, deinstall, destroy,
        pref_size, 1, (void *) check);
    win_wcore_notify_focus(widget, focus_lost, focus_gained);

    return widget;
}
