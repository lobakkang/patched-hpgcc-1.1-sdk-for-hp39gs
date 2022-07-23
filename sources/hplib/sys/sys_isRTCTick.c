//& ****************************************************************************
//&
//& Written by Al Borowski, October 2004
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

#include <hpsys.h>

//RTC ticks are good for slow timing (between 1hz and 64hz). They are
//independant of CPU frequency.

int sys_isRTCTick()
{ 
	//returns 1 if the RTC Tick interrupt is pending (if so, this routine clears it)
	//0 otherwise
     
	unsigned int volatile * SRCPND = (int*) 0x7100000;
	if((*SRCPND&0x100)!=0x100)
	{
		//not pending
		return 0;
	}
	*SRCPND = 0x100 ; //clear the tick interrupt
	return 1;
}
