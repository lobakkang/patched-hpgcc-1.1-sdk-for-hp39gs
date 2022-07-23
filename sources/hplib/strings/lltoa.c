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


#include <hpstring.h>
#include <hpsys.h>

// REWRITTEN BY CLAUDIO 02-09-05

char *
ulltoa(ULONGLONG z, char * buff, int base)
{
ULONGLONG powers[64],*ptr=powers;
ULONGLONG pw=1;
char *ret=buff;
int digit;
// GENERATE LIST OF POWERS OF THE BASE
do {
*ptr=pw;
++ptr;
// DETECT OVERFLOW!
if( ((pw>>32)*base) >> 32 ) break;
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


char *lltoa(LONGLONG z, char *buff, int base)
{
	char *ret=buff;
	if(z<0) { *buff='-'; ++buff; z=-z; }
	ulltoa(z,buff,base);
	return ret;

}

// ORIGINAL INGO'S CODE
/*
#define N 64


char *
ulltoa(ULONGLONG z, char *t, int base)
{
	
	char *dig = "0123456789ABCDEFEFGHIJKLMNOPQRSTUVWXYZ";
	char buf[N+1];
	int i;
	
	memset(buf,0,N+1);
	i = N-1;
	buf[i] = '0';
	
	
	if(z) {
		
		do {
			unsigned rem;
			
			z = udiv64(z,(unsigned long) base, &rem);
			buf[i--] = dig[rem];
		} while(z && i);
		i++;
	}
	
	
	return strcpy(t,&buf[i]);
}


char *
lltoa(LONGLONG z, char *t, int base)
{
	
	
	int minus;
	char buf[N+1];
	char mbuf[N+2];
	
	
	if ((minus = (z < 0))) {
		z = -z;
		strcpy(mbuf,"-");
	}
	
	ulltoa(z,buf,base);
			
	return minus ? strcpy(t,strcat(mbuf,buf)) : strcpy(t,buf);
}
*/

