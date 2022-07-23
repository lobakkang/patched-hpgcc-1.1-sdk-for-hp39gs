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


#include <hpstdio.h>
#include <hpkeyb49.h>

int
getchar()
{
	return keyb_getkey(1);
}

//#ifdef NO_ASSEMBLY_GETS


char *
_gets(char *buf)
{
	char *r = buf,c;
	int pos = 0;
	//int old_speed = set_speed(1); // slow ON
//REMOVED BY AL 6th OCTOBER, MAKE SPEED THE PROGRAMMERS RESPONSIBILITY FOR NOW	
	
	while ((c = getchar()) != '\r') {
		if (c == 8 ) {
			if (pos > 0) {
				pos--;
				buf--;
				putchar(c);
			}
		}
		else {
			pos++;
			*buf++ = c;
			putchar(c);
		}
	}
	
	*buf = '\0';
	
//	set_speed(old_speed);

//REMOVED BY AL 6th OCTOBER, MAKE SPEED THE PROGRAMMERS RESPONSIBILITY FOR NOW	

	return r;
}

//#endif

