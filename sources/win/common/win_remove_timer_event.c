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

void win_remove_timer_event(int event_num, void *event_data)
{
    win_init();

    struct win_timer *prev = NULL;
    struct win_timer *cur = _win_timer_list;

    while (cur != NULL)
    {
        if ((cur->func == _win_timer_event)
            && (cur->app_data == cur)
            && (cur->event_num == event_num)
            && (cur->event_data == event_data))
        {
            if (prev == NULL)
            {
                _win_timer_list = cur->next;
                cur->next = NULL;
                free(cur);
            }
            else
            {
                prev->next = cur->next;
                cur->next = NULL;
                free(cur);
            }

            return;
        }

        prev = cur;
        cur = cur->next;
    }
}