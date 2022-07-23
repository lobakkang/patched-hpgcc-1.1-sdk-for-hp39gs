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

#include "boxpriv.h"

static void install(win_widget_t *widget)
{
    struct win_box *box =
        (struct win_box *) win_wcore_get_data(widget);

    struct box_entry *entry = box->head;
    while (entry != NULL)
    {
        win_add_widget(entry->widget);
        entry = entry->next;
    }
}

static void deinstall(win_widget_t *widget)
{
    struct win_box *box =
        (struct win_box *) win_wcore_get_data(widget);

    struct box_entry *entry = box->head;
    while (entry != NULL)
    {
        win_remove_widget(entry->widget);
        entry = entry->next;
    }
}

static void destroy(win_widget_t *widget)
{
    struct win_box *box =
        (struct win_box *) win_wcore_get_data(widget);

    struct box_entry *entry = box->head;
    while (entry != NULL)
    {
        struct box_entry *next = entry->next;
        free(entry);
        entry = next;
    }

    free(box);
}

static void pref_size(win_widget_t *widget, int *width, int *height)
{
    int i; // general purpose counter variable

    struct win_box *box =
        (struct win_box *) win_wcore_get_data(widget);

    /*
     * Count the rows and columns in the grid model used for layout.
     */
    int n_rows = 0;
    int n_cols = 0;

    struct box_entry *entry = box->head;
    while (entry != NULL)
    {
        if (entry->row >= n_rows) n_rows = entry->row + 1;
        if (entry->col >= n_cols) n_cols = entry->col + 1;

        entry = entry->next;
    }

    int *row_size = (int *) malloc(n_rows * sizeof(int));
    int *col_size = (int *) malloc(n_cols * sizeof(int));

    /*
     * Initialize all sizes to zero.  They will be increased as
     * widgets are found with non-zero layout parameters.
     */
    memset((char *) row_size, 0, n_rows * sizeof(int));
    memset((char *) col_size, 0, n_cols * sizeof(int));

    entry = box->head;
    while (entry != NULL)
    {
        /*
         * Check for an increase in preferred cell size.
         */
        int x, y;
        _win_box_prefsize(entry, &x, &y);

        if (x > col_size[entry->col]) col_size[entry->col] = x;
        if (y > row_size[entry->row]) row_size[entry->row] = y;

        entry = entry->next;
    }

    int total_width = 0;
    int total_height = 0;

    for (i = 0; i < n_cols; i++) total_width += col_size[i];
    for (i = 0; i < n_rows; i++) total_height += row_size[i];

    free(row_size);
    free(col_size);

    if (n_cols > 1) total_width += (n_cols - 1) * box->xpad;
    if (n_rows > 1) total_height += (n_rows - 1) * box->ypad;

    *width = total_width;
    *height = total_height;
}

win_widget_t *win_box_new(void)
{
    return win_box_new_padding(0, 0);
}

win_widget_t *win_box_new_padding(int xpad, int ypad)
{
    struct win_box *box = (struct win_box *)
        malloc(sizeof(struct win_box));
    memset((void *) box, 0, sizeof(struct win_box));

    box->head = NULL;
    box->tail = NULL;
    box->xpad = xpad;
    box->ypad = ypad;

    return win_wcore_alloc(
        install, deinstall, destroy, pref_size, 0, (void *) box);
}
