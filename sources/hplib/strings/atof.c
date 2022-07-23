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
#include <hpmath.h>


double
atof(char * _buf)
{
	
	double val,integral,fraction,expo;
	int minus;
	char c,__buf[32],*buf;
	
	buf = lower(__buf,_buf); // just handle lowercase chars
	
	val = integral = fraction = 0.0;
	expo = 1.0;
	
	if((minus = (*buf == '-')))
		buf++;
	if (*buf == '+')
		buf++;
		
	while (*buf && *buf != '.') {
		c = *buf++;
		if (isdigit(c))
			integral = 10.0 * integral + c - '0';
		else
			goto fail;
	}
	
	if (*buf == '.') {
		int digits = 0;
		buf++;

		while (*buf && *buf != 'e' ) {
			c = *buf++;
// Ph Salmon : 23.10.04 : completes the fraction computation before exiting
			if (! isdigit(c))
			{
				fraction /= ipow(10.0,digits);
				goto fail;
			}
			digits++;
			fraction = 10.0 * fraction + c - '0';
		}
		
		fraction /= ipow(10.0,digits);
	}
	
	if (*buf == 'e') {
		int minus,ee = 0;
		buf++;
		if ((minus = (*buf == '-')))
			buf++;
		if (*buf == '+')
			buf++;
		while (*buf) {
			c = *buf++;
			if (! isdigit(c))
				goto fail;
			ee = 10 * ee + c - '0';
		}
		
		expo = ipow(10.0,minus ? -ee : ee);
	}

fail:
	
	val = expo * (integral + fraction);
	return minus ? -val : val;
}
