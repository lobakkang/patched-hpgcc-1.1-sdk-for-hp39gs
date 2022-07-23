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


void sys_setupTimers()
{
	//sets timer2 up to update at 750kHz
	unsigned int volatile * TCFG0 = (unsigned int*) 0x7600000;
	unsigned int volatile * TCFG1 = (unsigned int*) 0x7600004;
	unsigned int volatile * TCON = (unsigned int*) 0x7600008;
	unsigned int volatile * TCNTB2 = (unsigned int*) 0x7600024;

	*TCNTB2 = 0x1; // make timer count down from 1 DEBUG
 
	*TCFG0 = 0x0;// prescalers set to 1

	//PCLK on slow mode is 3MHz typically, so 3/4 = 750kHz

	*TCFG1 = 0x0; // all dividers set to 1/2
	*TCON =0x222202; // preload all timers  
	*TCON =0x599909; // turn all timers on 
}
