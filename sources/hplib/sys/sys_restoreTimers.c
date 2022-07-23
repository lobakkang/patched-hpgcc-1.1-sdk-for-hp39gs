//& ****************************************************************************
//&
//& Written by Ingo Blank, August 2004
//& Donated to the HP-GCC Development Team
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


void sys_restoreTimers()
{
	//restores timing system so emulator doesn't crash
	unsigned int volatile * TCFG0 = (unsigned int*) 0x7600000;
	unsigned int volatile * TCFG1 = (unsigned int*) 0x7600004;
	unsigned int volatile * TCON = (unsigned int*) 0x7600008;

	//first, stop all timers while changing settigns (just in case)
	*TCON = 0;

	//restore prescalers on timers 1 and 0 
	*TCFG0 = 0x2C8e ;// default

	//now restore divider on timer1 to 1/16
	*TCFG1 = 0x033033; //defaults, except mux 1 is 1/4
	*TCON = 0x590909; //default
}
