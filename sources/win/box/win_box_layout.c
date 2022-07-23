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

#include <win.h>
#include <wincore.h>

#include "boxpriv.h"

void win_box_layout(win_widget_t *widget)
{
    int i; // general purpose counter variable

    struct win_box *box =
        (struct win_box *) win_wcore_get_data(widget);

    /*
     * Determine the size and location of the containing box.
     */
    int boxx, boxy, boxw, boxh;
    win_widget_get_size(widget, &boxw, &boxh);
    win_widget_get_location(widget, &boxx, &boxy);

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

    double *row_weight = (double *) malloc(n_rows * sizeof(double));
    double *col_weight = (double *) malloc(n_cols * sizeof(double));

    /*
     * Initialize all sizes and weights to zero.  They will be increased as
     * widgets are found with non-zero layout parameters.
     */
    memset((char *) row_size, 0, n_rows * sizeof(int));
    memset((char *) col_size, 0, n_cols * sizeof(int));
    memset((char *) row_weight, 0, n_rows * sizeof(double));
    memset((char *) col_weight, 0, n_cols * sizeof(double));

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

        /*
         * Check for an increase in cell size weights.
         */
        if (entry->xweight > col_weight[entry->col])
        {
            col_weight[entry->col] = entry->xweight;
        }

        if (entry->yweight > row_weight[entry->row])
        {
            row_weight[entry->row] = entry->yweight;
        }

        entry = entry->next;
    }

    /*
     * Extra space (or shortcomings) need to be determined according to
     * weight.
     */
    int total_width = 0;
    double total_xweight = 0.0;
    for (i = 0; i < n_cols; i++)
    {
        total_width += col_size[i];
        total_xweight += col_weight[i];
    }

    int total_height = 0;
    double total_yweight = 0.0;
    for (i = 0; i < n_rows; i++)
    {
        total_height += row_size[i];
        total_yweight += row_weight[i];
    }

    int pad_width = 0;
    int pad_height = 0;

    if (n_cols > 1) pad_width = (n_cols - 1) * box->xpad;
    if (n_rows > 1) pad_height = (n_rows - 1) * box->ypad;

    int x_surplus = boxw - total_width - pad_width;
    if (x_surplus < 0)
    {
        /*
         * Take deficit from padding first.
         */
        if (-x_surplus > pad_width)
        {
            x_surplus += pad_width;
            pad_width = 0;
        }
        else
        {
            pad_width += x_surplus;
            x_surplus = 0;
        }
    }

    for (i = 0; i < n_cols; i++)
    {
        double pad = x_surplus * col_weight[i] / total_xweight;
        int ipad = (int) (pad + 0.5);

        if (ipad < -col_size[i]) ipad = -col_size[i];
        col_size[i] += ipad;

        /*
         * By updating x_surplus and total_xweight here, we ensure that any
         * error is self-correcting, causing the columns to add up to the
         * values that they should.
         */
        x_surplus -= ipad;
        total_xweight -= col_weight[i];
    }

    int y_surplus = boxh - total_height - pad_height;
    if (y_surplus < 0)
    {
        /*
         * Take deficit from padding first.
         */
        if (-y_surplus > pad_height)
        {
            y_surplus += pad_height;
            pad_height = 0;
        }
        else
        {
            pad_height += y_surplus;
            y_surplus = 0;
        }
    }

    for (i = 0; i < n_rows; i++)
    {
        double pad = y_surplus * row_weight[i] / total_yweight;
        int ipad = (int) (pad + 0.5);

        if (ipad < -row_size[i]) ipad = -row_size[i];
        row_size[i] += ipad;

        /*
         * By updating y_surplus and total_yweight here, we ensure that any
         * error is self-correcting, causing the rows to add up to the
         * values that they should.
         */
        y_surplus -= ipad;
        total_yweight -= row_weight[i];
    }

    /*
     * ======================================================================
     *
     * The first major stage of layout is complete; all rows and columns have
     * their proper sizes.  Components will now be layed out according to
     * that grid.
     */
    entry = box->head;
    while (entry != NULL)
    {
        if (entry->widget == NULL) continue; // place holder

        int x = boxx, y = boxy;
        int pw = pad_width, ph = pad_height;

        for (i = 0; i < entry->col; i++)
        {
            x += col_size[i];

            int pad = pw / (n_cols - i - 1);
            x += pad;
            pw -= pad;
        }

        for (i = 0; i < entry->row; i++)
        {
            y += row_size[i];

            int pad = ph / (n_rows - i - 1);
            y += pad;
            ph -= pad;
        }

        int prefw, prefh;
        _win_box_prefsize(entry, &prefw, &prefh);

        int w = prefw, h = prefh;
        if (w > col_size[entry->col]) w = col_size[entry->col];
        if (h > row_size[entry->row]) h = row_size[entry->row];

        if (entry->align_x == WIN_BOX_LEADING)
        {
            /* Do nothing; already there */
        }
        else if (entry->align_x == WIN_BOX_CENTER)
        {
            x += (col_size[entry->col] - w) / 2;
        }
        else if (entry->align_x == WIN_BOX_TRAILING)
        {
            x += (col_size[entry->col] - w);
        }
        else if (entry->align_x == WIN_BOX_FILL)
        {
            w = col_size[entry->col];
        }

        if (entry->align_y == WIN_BOX_LEADING)
        {
            /* Do nothing; already there */
        }
        else if (entry->align_y == WIN_BOX_CENTER)
        {
            y += (row_size[entry->row] - h) / 2;
        }
        else if (entry->align_y == WIN_BOX_TRAILING)
        {
            y += (row_size[entry->row] - h);
        }
        else if (entry->align_y == WIN_BOX_FILL)
        {
            h = row_size[entry->row];
        }

        win_widget_set_location(entry->widget, x, y);
        win_widget_set_size(entry->widget, w, h);

        entry = entry->next;
    }

    free(row_size);
    free(col_size);
    free(row_weight);
    free(col_weight);
}
