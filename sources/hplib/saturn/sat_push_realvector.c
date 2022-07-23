//@<head>
//& <prolog>
//& ****************************************************************************
//&
//& Written by Ingo Blank & Claudio Lapilli, October 2004
//&
//& Copyright (C) 2004 HP-GCC Development Team
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

//& </prolog>

// $Header: /cvsroot/hpgcc/sources/hplib/saturn/sat_push_realvector.c,v 1.2 2005/01/14 23:11:56 cdlapilli Exp $

#include <hpgcc49.h>

//@</head>



//@<func name="sat_push_realvector">			
BOOL
sat_push_realvector(int elements,ULONGLONG *arry)
{
	// PUSH IMPLEMENTATION
	
	// push a vector of reals on the stack
	int prlgptr;
	
	int sataddr=sat_createtemp(16*elements+25);

	if(sataddr==0) return FALSE;
	
	prlgptr=sataddr;
	sat_poke(sataddr,SAT_DOARRY,5);
	sataddr+=5;
	sat_poke(sataddr, 16*elements+20,5);
	sataddr+=5;
	sat_poke(sataddr, SAT_DOREAL,5);
	sataddr+=5;
	sat_poke(sataddr, 1,5);
	sataddr+=5;
	sat_poke(sataddr, elements,5);
	sataddr+=5;

	while(elements!=0) {
	sat_poke_nibbles(sataddr,(const char *)arry,16);
	sataddr+=16;
	++arry;
	--elements;
	}	

	
	// done with object creation

	sat_pushptr(prlgptr);

	return TRUE;
}
//@</func>
