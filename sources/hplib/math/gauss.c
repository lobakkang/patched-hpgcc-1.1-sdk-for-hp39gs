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

#include <hpstdlib.h>
#include <hpmath.h>


		
double
gauss()
{
	static int have_next_gaussian = 0;
	static double next_gaussian;
	double s,v1,v2,mult;
	
	if (have_next_gaussian) {
		have_next_gaussian = 0;
		return next_gaussian;
	}
	
	s = 0.0;
	do {
		v1 = 2.0 * random() - 1.0;
		v2 = 2.0 * random() - 1.0;
		s  = v1*v1 + v2*v2;
	} while ( s >= 1.0 );
	mult = sqrt(-2.0 * log(s)/s);
	next_gaussian = mult * v2;
	have_next_gaussian = 1;
	
	return mult * v1;
}

double
normal(double mu, double sigma)
{
	return gauss()*sigma + mu;
}


