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

#include "choosepriv.h"

static int choose_event = -1;
static int box_ok_event = -1;
static int box_cancel_event = -1;

static int paint(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    win_wcore_paint_base(widget);

    int x, y;
    win_widget_get_location(widget, &x, &y);

    if (win_widget_has_focus(widget))
    {
        int w, h;
        unsigned char fgcolor, bgcolor;

        win_widget_get_size(widget, &w, &h);
        win_widget_get_colors(widget, &fgcolor, &bgcolor);

        hpg_fill_rect(x, y, x + w, y + h);
        hpg_set_color(hpg_stdscreen, bgcolor);
    }

    if (choose->pos < choose->count)
    {
        hpg_draw_text(choose->labels[choose->pos], x + 1, y + 1);
    }

    return 0;
}

static int keyhandler(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    if (!win_widget_has_focus(widget)) return 0;

    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);
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
                choose->pos++;
                if (choose->pos >= choose->count) choose->pos = 0;

                win_repaint();
                return 1;
            }
    }

    return 0;
}

static int paint_box(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    unsigned char fgcolor, bgcolor;
    win_widget_get_colors(widget, &fgcolor, &bgcolor);

    hpg_font_t *font = win_widget_get_font(widget);
    hpg_set_font(hpg_stdscreen, font);

    int box_h = (hpg_font_get_height(font) + 1) * choose->count + 4;
    int box_w = 100;
    int box_x = 15;
    int box_y = (80 - box_h) / 2;

    hpg_clip_set(hpg_stdscreen,
        box_x, box_y, box_x + box_w + 1, box_y + box_h + 1);

    hpg_set_color(hpg_stdscreen, bgcolor);
    hpg_fill_rect(box_x, box_y, box_x + box_w, box_y + box_h);

    hpg_set_color(hpg_stdscreen, fgcolor);
    hpg_draw_rect(box_x, box_y, box_x + box_w - 1, box_y + box_h - 1);
    hpg_draw_line(
        box_x + 1, box_y + box_h, box_x + box_w, box_y + box_h);
    hpg_draw_line(
        box_x + box_w, box_y + 1, box_x + box_w, box_y + box_h);

    int x = box_x + 2;
    int y = box_y + 2;
    int w = box_w - 5;
    int h = hpg_font_get_height(font) + 1;

    int i;
    for (i = 0; i < choose->count; i++)
    {
        if (i == choose->box_idx)
        {
            hpg_set_color(hpg_stdscreen, fgcolor);
            hpg_fill_rect(x, y, x + w, y + h - 1);
            hpg_set_color(hpg_stdscreen, bgcolor);
        }
        else
        {
            hpg_set_color(hpg_stdscreen, fgcolor);
        }

        hpg_draw_text(choose->options[i], x + 1, y + 1);
        y += h;
    }

    return 1;
}

/* Forward declaration, so this can be called from ok and cancel */
static void unchoose(win_widget_t *widget);

static int box_ok(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    choose->pos = choose->box_idx;
    unchoose(widget);
    return 1;
}

static int box_cancl(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    unchoose(widget);
    return 1;
}

static int keyhandler_box(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    win_keytyped_t *event = (win_keytyped_t *) event_data;

    switch (event->keycode)
    {
        case KB_UP:
            choose->box_idx--;
            if (choose->box_idx < 0) choose->box_idx = choose->count - 1;
            win_repaint();
            return 1;

        case KB_DN:
            choose->box_idx++;
            if (choose->box_idx >= choose->count) choose->box_idx = 0;
            win_repaint();
            return 1;

        case KB_LF: return 1;
        case KB_RT: return 1;
        case KB_W: return 1;
    }

    return 0;
}

static int boxchoose(void *event_data, void *app_data)
{
    if (box_ok_event == -1) box_ok_event = win_register_event();
    if (box_cancel_event == -1) box_cancel_event = win_register_event();

    win_widget_t *widget = (win_widget_t *) app_data;
    if (!win_widget_has_focus(widget)) return 0;

    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    choose->box_showing = 1;
    choose->box_idx = choose->pos;

    win_add_event_handler(WIN_REPAINT_EVENT,
        -2000000000, paint_box, (void *) widget);
    win_add_event_handler(WIN_KEY_TYPED,
        2000000000, keyhandler_box, (void *) widget);
    win_add_event_handler(box_ok_event,
        2000000000, box_ok, (void *) widget);
    win_add_event_handler(box_cancel_event,
        2000000000, box_cancl, (void *) widget);

    if (choose->box_menu == NULL)
    {
        win_widget_t *box_menu = win_softmenu_new();
        win_softmenu_set_item(box_menu, 4, "CANCL", box_cancel_event, widget);
        win_softmenu_set_item(box_menu, 5, "OK", box_ok_event, widget);

        choose->box_menu = box_menu;
    }

    if (choose->menu) win_remove_widget(choose->menu);
    win_add_widget(choose->box_menu);

    return 1;
}

static void unchoose(win_widget_t *widget)
{
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    choose->box_showing = 0;

    win_remove_event_handler(WIN_REPAINT_EVENT, paint_box, (void *) widget);
    win_remove_event_handler(WIN_KEY_TYPED, keyhandler_box, (void *) widget);
    win_remove_event_handler(box_ok_event, box_ok, (void *) widget);
    win_remove_event_handler(box_cancel_event, box_cancl, (void *) widget);

    win_remove_widget(choose->box_menu);
    if (choose->menu) win_add_widget(choose->menu);
}

static void install(win_widget_t *widget)
{
    if (choose_event == -1) choose_event = win_register_event();

    win_add_event_handler(WIN_REPAINT_EVENT, 0, paint, (void *) widget);
    win_add_event_handler(WIN_KEY_TYPED, 0, keyhandler, (void *) widget);
    win_add_event_handler(choose_event, 0, boxchoose, (void *) widget);
}

static void deinstall(win_widget_t *widget)
{
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    win_remove_event_handler(WIN_REPAINT_EVENT, paint, (void *) widget);
    win_remove_event_handler(WIN_KEY_TYPED, keyhandler, (void *) widget);
    win_remove_event_handler(choose_event, boxchoose, (void *) widget);

    if (choose->box_showing)
    {
        unchoose(widget);
    }
}

static void destroy(win_widget_t *widget)
{
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    free(choose->options);
    free(choose->labels);

    if (choose->box_menu != NULL)
    {
        win_widget_destroy(choose->box_menu);
    }

    free(choose);
}

static void pref_size(win_widget_t *widget, int *width, int *height)
{
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    int x_result = 0;
    int y_result = 0;

    int i;
    for (i = 0; i < choose->count; i++)
    {
        int line = 0;
        int max_col = 0;
        int col = 0;

        char *p = choose->labels[i];

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

        if (max_col > x_result) x_result = max_col;
        if (line > y_result) y_result = line;
    }

    hpg_font_t *font = win_widget_get_font(widget);

    *width = x_result * hpg_font_get_advance(font) + 1;
    *height = y_result * hpg_font_get_height(font) + 1;
}

static void focus_lost(win_widget_t *widget)
{
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    if (choose->menu)
    {
        win_softmenu_delete_item(
            choose->menu, choose->menu_idx, choose->menu_idx);
    }
}

static void focus_gained(win_widget_t *widget)
{
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    if (choose->menu)
    {
        win_softmenu_set_item(
            choose->menu, choose->menu_idx, "CHOOS", choose_event, NULL);
    }
}

win_widget_t *win_choose_new(void)
{
    struct win_choose *choose = (struct win_choose *)
        malloc(sizeof(struct win_choose));
    memset((void *) choose, 0, sizeof(struct win_choose));

    choose->options = (char **) malloc(0);
    choose->labels = (char **) malloc(0);
    choose->count = 0;
    choose->pos = 0;

    choose->menu = NULL;
    choose->menu_idx = -1;

    choose->box_showing = 0;
    choose->box_menu = NULL;
    choose->box_idx = 0;

    win_widget_t *widget = win_wcore_alloc(
        install, deinstall, destroy, pref_size, 1, (void *) choose);
    win_wcore_notify_focus(widget, focus_lost, focus_gained);

    return widget;
}
