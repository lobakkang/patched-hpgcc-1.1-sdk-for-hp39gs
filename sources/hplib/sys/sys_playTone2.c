//& ****************************************************************************
//&
//& Copyright (C) 2004 The HP-GCC Development Team
//&
//& ****************************************************************************
//&
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

#include "hpsys.h"

void sys_playTone2(unsigned int tone, unsigned int duration)
{
    unsigned int volatile * GPBDAT = (unsigned int*) 0x7A00014;

    /*
     * The period in nanoseconds = 1 000 000 000 / tone.  The half-period
     * (time for half of a full wave) is half of that
     */
    unsigned int halfperiod = (int) (500000000 / tone);

    sys_timer_t timer = SYS_TIMER_INITIALIZER_NUM(3);
    sys_updateTimer(&timer);

    ULONGLONG next = timer.current + halfperiod;
    ULONGLONG finish = timer.current + (duration * 1000000);

    while (timer.current < finish)
    {
        *GPBDAT=0x4;	//beeper on
        while (timer.current < next) sys_updateTimer(&timer);
        next += halfperiod;

        *GPBDAT = 0;	//beeper off
        while (timer.current < next) sys_updateTimer(&timer);
        next += halfperiod;
    }
}
