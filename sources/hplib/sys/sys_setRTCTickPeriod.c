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


//sets the RTC Tick Period. By default it is 8hz. If modified, you 
//should restore it to this speed
//at the end of your program eg call with n=15
//period = (n+1)/128 seconds. N _must_ be between 1 and 127

// modified for preserving/querying state
// < ibl ; 2004-12-03 >

// state preservation disabled to prevent crash
// < chris ; 2005-01-10 >

// re-enabled state preservation by circumventing (possible) gcc bug
// i.e. 'static unsigned char' declaration replaced by 'static int', which obviously works
// < ibl ; 2005-01-11 >

// Move current period to a non-static variable, so that it can be accessed
// from outside this file.
// < chris ; 2005-01-23 >

int _sys_RTCTickPeriod = 15;

unsigned char
sys_setRTCTickPeriod(unsigned char n)
{
	
// 	causes a system crash due to a (possible) gcc bug!
//	static unsigned char old_period = 15; // System default
//	unsigned char r;

	static int old_period = 15; // System default
	int r;
	
	unsigned char volatile * TICNT = (char*) 0x7B00047;

	if((n==0)||(n>127))
	{
		return (unsigned char) _sys_RTCTickPeriod;
	}
	
	r = _sys_RTCTickPeriod;
	_sys_RTCTickPeriod = n;
	
	*TICNT = (unsigned char) (n | 0x80); //set bit 7, enable tick interrupt
	
	return (unsigned char) r;
}
