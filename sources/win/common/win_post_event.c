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

extern void *alloca(int size);

int win_post_event(int event, void *event_data)
{
    int lev1, lev2;
    struct win_eventhandler *handler;
    struct win_eventhandler *copychain;
    struct win_eventhandler *copypos;

    win_init();

    if (event < 0) return 0;

    lev1 = event / EQ_LEV2SIZE;
    lev2 = event % EQ_LEV2SIZE;

    if (lev1 > EQ_LEV1SIZE) return 0;

    handler = _win_sysqueue.handler_chains[lev1][lev2];
    copychain = copypos = NULL;

    /*
     * Copy the event queue.  This prevents all kinds of wackiness if the
     * event queue is modified while win_post_event is walking it.
     */
    while (handler != NULL)
    {
        struct win_eventhandler *next = (struct win_eventhandler *)
            alloca(sizeof(struct win_eventhandler));

        next->handler = handler->handler;
        next->app_data = handler->app_data;
        next->next = NULL;

        if (copypos == NULL)
        {
            copypos = copychain = next;
        }
        else
        {
            copypos = copypos->next = next;
        }

        handler = handler->next;
    }

    /*
     * Walk through the copy, call the handlers, and delete the copied data
     * structures along the way.
     */
    handler = copychain;
    while (handler != NULL)
    {
        struct win_eventhandler *next;
        int result;

        int (*func) (void *event_data, void *app_data);
        func = handler->handler;

        result = (*func)(event_data, handler->app_data);

        if (result != 0) return result;

        next = handler->next;
        handler = next;
    }

    return 0;
}
