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

#include <win.h>
#include <wincore.h>
#include "boxpriv.h"

void _win_box_prefsize(struct box_entry *entry, int *width, int *height)
{
    int w = 0, h = 0;

    if ((entry->widget != NULL)
        && ((entry->pwidth == -1) || (entry->pheight == -1)))
    {
        /*
         * Need to ask the widget for its preferred size, for at least one
         * of the two dimensions.
         */
        win_wcore_pref_size(entry->widget, &w, &h);
    }

    /*
     * Look for overridden preferred sizes in the box layout parameters.
     */
    if (entry->pwidth != -1) w = entry->pwidth;
    if (entry->pheight != -1) h = entry->pheight;

    *width = w;
    *height = h;
}
