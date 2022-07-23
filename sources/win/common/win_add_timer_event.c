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

void win_add_timer_event(
    int event_num,
    void *event_data,
    int interval_ms,
    int periodic)
{
    win_init();

    sys_updateTimer(&_win_sys_timer);

    struct win_timer *timer =
        (struct win_timer *) malloc(sizeof(struct win_timer));

    timer->func = _win_timer_event;
    timer->app_data = (void *) timer;
    timer->event_num = event_num;
    timer->event_data = event_data;
    timer->interval = interval_ms;
    timer->next_time = _win_sys_timer.current
        + (ULONGLONG) 1000000 * interval_ms;
    timer->periodic = periodic ? 1 : 0;

    _win_push_timer(timer);
}
