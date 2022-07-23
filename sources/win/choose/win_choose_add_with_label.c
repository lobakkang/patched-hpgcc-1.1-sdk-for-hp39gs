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

void win_choose_add_with_label(
    win_widget_t *widget, char *option, char *label)
{
    struct win_choose *choose =
        (struct win_choose *) win_wcore_get_data(widget);

    char **new_options = (char **)
        malloc((choose->count + 1) * sizeof(char *));
    if (new_options == NULL) return;

    char **new_labels = (char **)
        malloc((choose->count + 1) * sizeof(char *));
    if (new_labels == NULL) return;

    int i;
    for (i = 0; i < choose->count; i++)
    {
        new_options[i] = choose->options[i];
        new_labels[i] = choose->labels[i];
    }

    new_options[choose->count] = option;
    new_labels[choose->count] = label;

    free(choose->options);
    free(choose->labels);
    choose->options = new_options;
    choose->labels = new_labels;

    choose->count++;

    if (choose->pos == choose->count - 1) win_repaint();
}
