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


//$Header: /cvsroot/hpgcc/sources/hplib/saturn/sat_stack_push_int.c,v 1.2 2004/11/28 14:09:55 iblank Exp $

#include <hpgcc49.h>

//@</head>

int
_sat_stack_push_int(int z, int radix, int binary)
{
	char zz[16];
	char buf[32];
	char *a = NULL;
	
	itoa(z,zz,radix);
	if(binary && (radix == 8 || radix == 10 || radix == 16)) {
		strcpy(buf,"#");
		strcat(buf,zz);
		switch(radix) {
			case 8  : a = "o"; break;
			case 10 : a = "d"; break;
			case 16 : a = "h"; break;
		}
		strcat(buf,a);
	}
	
	return sat_stack_push_string(a ? buf : zz);
}

int
sat_stack_push_int(int z)
{
	return _sat_stack_push_int(z,10,0);
}




