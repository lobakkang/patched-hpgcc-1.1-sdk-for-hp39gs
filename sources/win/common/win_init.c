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
#include "winpriv.h"

static int inited = 0;

void win_init(void)
{
    if (inited) return;
    inited = 1;

    int i;

    _win_sysqueue.next_event = LAST_SYS_EVENT + 1;
    _win_sysqueue.handler_chains[0] = (struct win_eventhandler **)
        malloc(EQ_LEV2SIZE * sizeof (struct win_eventhandler *));

    for (i = 0; i < EQ_LEV2SIZE; i++)
    {
        _win_sysqueue.handler_chains[0][i] = NULL;
    }

    for (i = 1; i < EQ_LEV1SIZE; i++)
    {
        _win_sysqueue.handler_chains[i] = NULL;
    }

    win_add_event_handler(WIN_IDLE_EVENT,
        2000000002, _win_key_generator, NULL);
    win_add_event_handler(WIN_IDLE_EVENT,
        2000000001, _win_repaint_generator, NULL);
    win_add_event_handler(WIN_IDLE_EVENT,
        2000000000, _win_timer_generator, NULL);

    win_add_event_handler(WIN_KEY_PRESSED,
        2000000000, _win_default_key_handler, (void *) WIN_KEY_PRESSED);
    win_add_event_handler(WIN_KEY_RELEASED,
        2000000000, _win_default_key_handler, (void *) WIN_KEY_RELEASED);

    win_add_event_handler(WIN_REPAINT_EVENT,
        2000000000, _win_indicator_paint, NULL);
}
