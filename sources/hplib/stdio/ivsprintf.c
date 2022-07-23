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
#include <hpstring.h>
#include <stdarg.h>


static
char *
out_copy(char *t,char *s)
{
	int slen;
	char *r = t;
	
	strncpy(t,s,slen=strlen(s));
	return r + slen;
}

// This is the workhorse for all *printf variants 

int
ivsprintf(char *out, const char *fmt, va_list argp)
{
const char *p;

char fmtbuf[256];
char padbuf[256];
char hexbuf[16];
char *s;

int lead_zero, pad, minus, entry;



for(p = fmt; *p != '\0'; p++) {
	
	if(*p != '%') {
		*out++ = *p;
		continue;
	}
	
	lead_zero = pad = minus = 0;
	entry = 1;
	
	p++;
	
	if ((minus = *p == '-'))
		p++;
	
	while(isdigit(*p) ) {
		if (entry) {
			lead_zero = (*p == '0');
			entry = 0;
		}
		pad = 10 * pad + ( *p & 0xF );
		p++;
	}
	
	if (*p ==  's') {
		s = va_arg(argp, char *);
		if (s == NULL)
			s = "<NULL>";
		out = out_copy(out,pad ? xpad(padbuf,s,pad,minus,' ') : s);
		
		goto t_break;
	}
	
	if (*p == 'd' || *p == 'i') {
	
		s = itoa(va_arg(argp, int), fmtbuf, 10);
		goto numeric_puts;
	}
	
	if (*p == 'c') {
		*out++=(char)va_arg(argp, int);
		goto t_break;
	}
	
	
	if (*p == 'x' || *p == 'X') {
		s = utoa(va_arg(argp, unsigned), fmtbuf, 16);
		if (*p == 'X')
			s = upper(hexbuf,fmtbuf);
		goto numeric_puts;
	}
	
	if (*p == 'p') {
		s = utoa((unsigned) va_arg(argp, void *), fmtbuf, 16);
		goto numeric_puts;
	}
	
	
	//The 'b' format has been added for debug only, this is NOT standard C format
	if (*p == 'u' || *p == 'b') {
	
		s = utoa(va_arg(argp, unsigned), fmtbuf, *p == 'b' ? 2 : 10);
		//puts(pad ? xpad(padbuf,s,pad,!minus,lead_zero ? '0' : ' ') : s);
		goto numeric_puts;
	}
		
	
	if (*p == 'U') {
		
		s = ulltoa(va_arg(argp, unsigned long long), fmtbuf,10);
		goto numeric_puts;
	}
		
	if (*p ==  'L') {
		s = lltoa(va_arg(argp, long long), fmtbuf,10);
		goto numeric_puts;
	}
	

	if (*p == '%') {
		*out++='%';
		goto t_break;
	}
	
		
numeric_puts:
	out = out_copy(out,pad ? xpad(padbuf, s, pad, ! minus, lead_zero ? '0' : ' ') : s);
	// goto t_break;
		

t_break:	;
		
		
		
	
	}


	*out = '\0';
	return strlen(out);

}
