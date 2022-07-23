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

// $Header: /cvsroot/hpgcc/sources/hplib/saturn/sat_push_char.c,v 1.1 2005/01/09 04:35:39 cdlapilli Exp $

#include <hpgcc49.h>

//@</head>



//@<func name="sat_push_char">			
BOOL
sat_push_char(char byte)
{
	// PUSH IMPLEMENTATION
	
	// push a char on the stack
	
	int sataddr=sat_createtemp(7);

	if(sataddr==0) return FALSE;
	
	sat_poke(sataddr,SAT_DOCHAR,5);
	sat_poke(sataddr+5,byte,2);
	
	// done with object creation

	sat_pushptr(sataddr);

	return TRUE;
}
//@</func>
