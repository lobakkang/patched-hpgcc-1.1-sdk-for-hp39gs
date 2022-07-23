//& ****************************************************************************
//&
//& HP-GCC Development Team
//& Copyright (C) 2005 The HP-GCC Development Team
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


#include <hpstring.h>

char *
utoa(unsigned int z, char * buff, int base)
{
unsigned powers[32],*ptr=powers;
register unsigned pw=1;
char *ret=buff;
int digit;
// GENERATE LIST OF POWERS OF THE BASE
do {
*ptr=pw;
++ptr;
// DETECT OVERFLOW!
if( ((pw>>16)*base) >= 0x10000) break;
pw*=base;
} while(pw<=z);

for(--ptr;ptr>=powers;ptr--)
{
	digit=0;
	while(z>=*ptr) { ++digit; z-=*ptr; }
	*buff= (digit>9)? (digit+87) : (digit+48) ;
	++buff;
}

*buff=0;
return ret;
}
