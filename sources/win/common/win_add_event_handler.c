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

void win_add_event_handler(
    int event, int priority, win_eventhandler func, void *app_data)
{
    int lev1, lev2;
    struct win_eventhandler *handler;

    win_init();

    struct win_eventhandler *last_handler = NULL;
    struct win_eventhandler *this_handler = NULL;

    if (event < 0) return;

    lev1 = event / EQ_LEV2SIZE;
    lev2 = event % EQ_LEV2SIZE;

    if (lev1 > EQ_LEV1SIZE) return;

    handler = (struct win_eventhandler *)
        malloc(sizeof(struct win_eventhandler));

    handler->handler = func;
    handler->app_data = app_data;
    handler->priority = priority;

    this_handler = _win_sysqueue.handler_chains[lev1][lev2];
    while ((this_handler != NULL) && (priority < this_handler->priority))
    {
        last_handler = this_handler;
        this_handler = this_handler->next;
    }

    if (last_handler == NULL)
    {
        _win_sysqueue.handler_chains[lev1][lev2] = handler;
    }
    else
    {
        last_handler->next = handler;
    }

    handler->next = this_handler;
}
