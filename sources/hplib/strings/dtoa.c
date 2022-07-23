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

// $Header: /cvsroot/hpgcc/sources/hplib/strings/dtoa.c,v 1.14 2005/02/21 00:52:06 iblank Exp $

#include <hpstdlib.h>
#include <hpstring.h>
#include <hpstdio.h>
#include <hpmath.h>


#define MAXDIGITS 15
#define TINY_EXP 1.0e-15
#define BIG_EXP 1.0e15
			
char *
dtoa(double x, char *buf, int force_expo)
{
	double fp,ip;
	int digits,max_digits;
	int minus,expo;
	char fraction[MAXDIGITS+1];
	char integral[MAXDIGITS+1];
	char exps[8];
	
	digits = minus = expo = 0;
	max_digits = min(get_decimal_digits(),MAXDIGITS);
	memset(fraction,'0',MAXDIGITS);
	fraction[MAXDIGITS] = '\0';
	strcpy(integral,"0");
	
	if(x != 0.0) {
	
		if ((minus = x < 0.0))
			x = -x;
		
		// split & scale
		
		if (force_expo || x >= BIG_EXP || x <= TINY_EXP ) {
			
			int expo2;
			
			// usage of log10() optimized away
			// as suggested by Claudio
			// < ibl ; 2005-02-19 >
			
			frexp(x,&expo2);
			expo = (int) (expo2*M_LN2/M_LN10);
			x *= ipow(10.0,-expo);
		}

		fp = modf(x,&ip);
		lltoa((LONGLONG) ip,integral,10); 
		
		do {
			x = 10.0 * fp;
			fraction[digits++] = (int) x + 0x30;
			fp = x - (int) x;
		} while ( fp > 0.0  && digits < MAXDIGITS );
	
	}

	// Now truncate to the actually requested number of digits
	fraction[max_digits] = '\0';

	sprintf(buf,"%s%s%s%s",minus ? "-" : "",integral,max_digits ? get_decimal_separator() : "",fraction);
	
	if (force_expo || expo) { 
		sprintf(exps,"e%d",expo);
		strcat(buf,exps);
	}
	
	return buf; 
	
}
