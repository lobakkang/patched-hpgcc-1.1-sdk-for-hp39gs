//& ****************************************************************************
//&
//& Written by Al Borowski, August 2004
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

int sys_RTC_seconds()
{
	//read the RTC register
	int sec,min,hour;

	// fixed: (unsigned short*) -> (unsigned char *) since we are reading 8 bit quantities
	// < ibl ; 2004-12-06 >
	
	sec = sys_bcd2bin(*(unsigned char*)(0x7B00070));
	min = sys_bcd2bin(*(unsigned char*)(0x7B00074)) ;
	hour = sys_bcd2bin(*(unsigned char*)(0x7B00078));

	return(sec+60*min+3600*hour);
}



/*
RTC_ss:
	STMFD SP!, {R1,LR} 
	mov	r1,#0x7B00000	@ RTC - BASE
	ldrb	r0,[r1,#0x70]	@ BCD - seconds
	bl	bcd2bin
	LDMFD SP!, {R1,PC}
	
RTC_mm:
	STMFD SP!, {R1,LR} 
	mov	r1,#0x7B00000	@ RTC - BASE
	ldrb	r0,[r1,#0x74]	@ BCD - minutes
	bl	bcd2bin
	LDMFD SP!, {R1,PC}
	
RTC_hh:
	STMFD SP!, {R1,LR} 
	mov	r1,#0x7B00000	@ RTC - BASE
	ldrb	r0,[r1,#0x78]	@ BCD - hours
	bl	bcd2bin
	LDMFD SP!, {R1,PC}
	
*/
