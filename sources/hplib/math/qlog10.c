//& ****************************************************************************
//&
//& Written by Daniel Herring, January 2005
//& Donated to the HP-GCC Development Team
//& Copyright (C) 2004,2005 The HP-GCC Development Team
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

/*	qlog10.c "Quick" log10
	20050123 Daniel Herring
	Provide a "quick" >low-memory-footprint< method for base-10 logarithms.
	Taylored for the HP series calculators which only have exponents up
	to +/- 500.

	Uses at most 30 multiplies (over the range 10^(+/-1000)).

	There are numerically better methods, but this was easy to implement.

	Believed to be correct, but should be double-checked.
*/


/**
 * find y and return so that x=y*(10**return)
 *
 * @param x source number
 * @param *y location for the remainder term
 * @return integer log10 of x
 */
 
#include <hpsys.h>
#include <hpmath.h>


int qlog10(double x, double *y)
{
	int power=0;
	
	if ( x <= 0.0 )
		sys_error("qlog10: Invalid Argument",-1);
	
	if(x>1)
	{
		while(x>1E100)
		{
			x*=1E-100;
			power+=100;
		}
		while(x>1E10)
		{
			x*=1E-10;
			power+=10;
		}
		while(x>1)
		{
			x*=0.1;
			power+=1;
		}
	}
	else if(x<1)
	{
		while(x<1E-100)
		{
			x*=1E100;
			power-=100;
		}
		while(x<1E-10)
		{
			x*=1E10;
			power-=10;
		}
		while(x<1)
		{
			x*=10;
			power-=1;
		}
	}

	*y=x;
	return power;
}

