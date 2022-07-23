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
#include <hpgraphics.h>

#include <win.h>
#include <wincore.h>

#include "imgpriv.h"

static int paint(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_img *img = (struct win_img *) win_wcore_get_data(widget);

    win_wcore_paint_base(widget);

    int x, y, w, h;
    win_widget_get_location(widget, &x, &y);
    win_widget_get_size(widget, &w, &h);

    if (img->pattern != NULL)
    {
        hpg_set_pattern(hpg_stdscreen, img->pattern);
        hpg_fill_rect(x, y, x + w, y + h);
        hpg_set_pattern(hpg_stdscreen, NULL);
    }

    if (img->image != NULL)
    {
        hpg_blit(img->image, 0, 0, w, h, hpg_stdscreen, x, y);
    }

    return 0;
}

static void install(win_widget_t *widget)
{
    win_add_event_handler(WIN_REPAINT_EVENT,
        2000000000, paint, (void *) widget);
}

static void deinstall(win_widget_t *widget)
{
    win_remove_event_handler(WIN_REPAINT_EVENT, paint, (void *) widget);
}

static void destroy(win_widget_t *widget)
{
    free(win_wcore_get_data(widget));
}

static void pref_size(win_widget_t *widget, int *width, int *height)
{
    struct win_img *img = (struct win_img *) win_wcore_get_data(widget);
    if (img->image != NULL)
    {
        *width = hpg_get_width(img->image);
        *height = hpg_get_height(img->image);
    }
    else
    {
        *width = *height = 0;
    }
}

win_widget_t *win_img_new(hpg_pattern_t *pattern, hpg_t *image)
{
    struct win_img *img = (struct win_img *) malloc(sizeof(struct win_img));
    memset((void *) img, 0, sizeof(struct win_img));

    img->pattern = pattern;
    img->image = image;

    return win_wcore_alloc(
        install, deinstall, destroy, pref_size, 0, (void *) img);
}
