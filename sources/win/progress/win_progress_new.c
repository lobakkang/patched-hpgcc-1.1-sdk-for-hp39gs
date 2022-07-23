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
#include <hpstdio.h>
#include <hpstring.h>
#include <hpkeyb49.h>
#include <hpgraphics.h>

#include <win.h>
#include <wincore.h>
#include <winprogress.h>

#include "progresspriv.h"

static int paint (void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_progress *bar =
        (struct win_progress *) win_wcore_get_data(widget);
    int x, y, w, h;

    // Draws the progress bar area with the background color
    win_wcore_paint_base(widget);
    win_widget_get_location (widget, &x, &y);
    win_widget_get_size (widget, &w, &h);

    if (win_widget_has_focus(widget) && bar->cursor_vis)
    {
        unsigned int pat = 0xAA55AA55;

        hpg_pattern_t *old_pat = hpg_get_pattern(hpg_stdscreen);
        hpg_pattern_t *new_pat = hpg_alloc_pattern((char *) &pat, 4, 0);

        hpg_set_pattern(hpg_stdscreen, new_pat);
        hpg_fill_rect(x, y, x + w - 1, y + h - 1);
        hpg_set_pattern(hpg_stdscreen, old_pat);
        hpg_free_pattern(new_pat);
    }

    // Draws the progress bar frame with the foreground color
    hpg_draw_rect(x, y, x + w - 1, y + h - 1);

    // Fills the progress depending on the orientation
    double pct = (bar->value - bar->min) / (bar->max - bar->min);
    if (bar->orient == WIN_PROGRESS_VERT)
    {
        hpg_fill_rect(
            x, y + (int) (h * (1 - pct)),
            x + w - 1, y + h - 1);
    }
    else if (bar->orient == WIN_PROGRESS_VERT_TOP)
    {
        hpg_fill_rect(
            x, y,
            x + w - 1, y + (int) ((h - 1) * pct));
    }
    else if (bar->orient == WIN_PROGRESS_HORIZ)
    {
        /* Horizontal */
        hpg_fill_rect(
            x, y,
            x + (int) ((w - 1) * pct), y + h - 1);
    }
    else if (bar->orient == WIN_PROGRESS_HORIZ_RIGHT)
    {
        /* Horizontal */
        hpg_fill_rect(
            x + (int) (w * (1 - pct)), y,
            x + w - 1, y + h - 1);
    }

    return 0;
}

static void update_value(win_widget_t *widget)
{
    struct win_progress *bar = (struct win_progress *)
        win_wcore_get_data(widget);

    double new_val = bar->value + bar->repeatval * bar->inc;

    win_progress_set_value(widget, new_val);
    win_post_event(bar->event, widget);
}

static int rep_handler (void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;

    if (!win_widget_has_focus(widget)) return 1;

    update_value(widget);
    return 0;
}

static int first_handler (void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;

    if (win_widget_has_focus(widget))
    {
        update_value(widget);

        struct win_progress *bar =
            (struct win_progress *) win_wcore_get_data(widget);
        win_add_timer(rep_handler, widget, bar->next, 1);
    }

    return 1;
}

static int arrow_pressed (void *event_data, void *app_data)
{
    int key = (int) event_data;

    /*
     * Progress widgets only respond to arrow keys.  If this is not an arrow
     * key, then let it propogate elsewhere.
     */
    if ((key != KB_UP) && (key != KB_DN)
        && (key != KB_LF) && (key != KB_RT))
    {
        return 0;
    }

    win_widget_t *widget = (win_widget_t *) app_data;
    if (!win_widget_has_focus(widget)) return 0;

    struct win_progress *bar =
        (struct win_progress *) win_wcore_get_data(widget);

    int inc = -1, dec = -1;

    if (bar->orient == WIN_PROGRESS_HORIZ) inc = KB_RT, dec = KB_LF;
    if (bar->orient == WIN_PROGRESS_HORIZ_RIGHT) inc = KB_LF, dec = KB_RT;
    if (bar->orient == WIN_PROGRESS_VERT) inc = KB_UP, dec = KB_DN;
    if (bar->orient == WIN_PROGRESS_VERT_TOP) inc = KB_DN, dec = KB_UP;

    bar->repeatval = 0;
    if (key == inc) bar->repeatval = 1;
    if (key == dec) bar->repeatval = -1;

    if ((bar->repeatval > 0) && (bar->value == bar->max)) bar->repeatval = 0;
    if ((bar->repeatval < 0) && (bar->value == bar->min)) bar->repeatval = 0;

    if (bar->repeatval == 0)
    {
        /*
         * Remove any old auto-repeats, since there is no longer an increment.
         */
        win_remove_timer(first_handler, app_data);
        win_remove_timer(rep_handler, app_data);

        if (key == KB_LF) win_focus_prev();
        if (key == KB_UP) win_focus_prev();
        if (key == KB_RT) win_focus_next();
        if (key == KB_DN) win_focus_next();
    }
    else
    {
        update_value(widget);
        win_repaint ();

        /*
         * Remove any old auto-repeats, which prevents some strange
         * behavior with competing auto-repeats on the same bar.
         */
        win_remove_timer(first_handler, app_data);
        win_remove_timer(rep_handler, app_data);

        /*
         * Add initial delay for auto-repeat.
         */
        win_add_timer(first_handler, widget, bar->first, 0);
    }

    return 1;
}

static int arrow_released (void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_progress *bar =
        (struct win_progress *) win_wcore_get_data(widget);

    /*
     * If an arrow is released, it should stop the auto-repeat process.
     * Even focus doesn't matter; if the widget has lost focus, then the
     * auto-repeat should stop at the next fire anyway, so may as well do it
     * now.
     */
    bar->repeatval = 0;
    win_remove_timer(first_handler, app_data);
    win_remove_timer(rep_handler, app_data);

    return 0;
}

static int cursor_flash(void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_progress *bar =
        (struct win_progress *) win_wcore_get_data(widget);

    bar->cursor_vis = 1 - bar->cursor_vis;
    if (win_widget_has_focus(widget)) win_repaint();

    return 0;
}

static void install(win_widget_t *widget)
{
    win_add_event_handler(
        WIN_REPAINT_EVENT, 2000000000, paint, (void *) widget);

    win_add_event_handler(
        WIN_KEY_PRESSED, 2000000000, arrow_pressed, (void *) widget);
    win_add_event_handler(
        WIN_KEY_RELEASED, 2000000000, arrow_released, (void *) widget);

    win_add_timer(cursor_flash, widget, 500, 1);
}

static void deinstall(win_widget_t *widget)
{
    win_remove_event_handler(WIN_REPAINT_EVENT, paint, (void *) widget);

    win_remove_event_handler(
        WIN_KEY_PRESSED, arrow_pressed, (void *) widget);
    win_remove_event_handler(
        WIN_KEY_RELEASED, arrow_released, (void *) widget);

    win_remove_timer(cursor_flash, widget);

    /*
     * Get rid of auto-repeat timers, in case they still exist.  Otherwise,
     * the timers may fire and access memory that has been freed, causing an
     * application crash.
     */
    win_remove_timer(first_handler, widget);
    win_remove_timer(rep_handler, widget);
}

static void destroy(win_widget_t *widget)
{
    if (widget)
    {
        struct win_progress *bar =
            (struct win_progress *) win_wcore_get_data(widget);
        free(bar);
    }
}

static void pref_size (win_widget_t *widget, int *w, int *h)
{
    struct win_progress *bar =
        (struct win_progress *) win_wcore_get_data(widget);

    int minor = 5;
    int major = (int) ((bar->max - bar->min + (bar->inc - 1)) / bar->inc);

    if (major < minor * 4) major = minor * 4;
    if ((bar->orient == WIN_PROGRESS_HORIZ)
        || (bar->orient == WIN_PROGRESS_HORIZ_RIGHT))
    {
        *w = major;
        *h = minor;
    }
    else
    {
        *w = minor;
        *h = major;
    }
}

win_widget_t *win_progress_new(int slider)
{
    win_widget_t *ret = NULL;
    struct win_progress *bar;

    if ((bar = (struct win_progress *) malloc (sizeof(struct win_progress))))
    {
        bar->value = 0.;
        bar->min = 0.;
        bar->max = 100.;
        bar->inc = (bar->max - bar->min) / 10.;
        bar->orient = WIN_PROGRESS_HORIZ;
        bar->first = 1000;
        bar->next = 200;
        bar->repeatval = 0;
        bar->cursor_vis = 0;
        bar->event = WIN_IDLE_EVENT;

        ret = win_wcore_alloc(
            install, deinstall, destroy, pref_size, slider, (void *) bar);
        if (ret == NULL) free(bar);
    }

    return ret;
}
