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

int win_register_event(void)
{
    win_init();

    int lev1, i;
    int event = _win_sysqueue.next_event++;

    if (event < 0) return -1;
    lev1 = event / EQ_LEV2SIZE;

    if (lev1 > EQ_LEV1SIZE) return -1;

    if (_win_sysqueue.handler_chains[lev1] == NULL)
    {
        _win_sysqueue.handler_chains[lev1] = (struct win_eventhandler **)
            malloc(EQ_LEV2SIZE * sizeof (struct win_eventhandler *));

        for (i = 0; i < EQ_LEV2SIZE; i++)
        {
            _win_sysqueue.handler_chains[lev1][i] = NULL;
        }
    }

    return event;
}
