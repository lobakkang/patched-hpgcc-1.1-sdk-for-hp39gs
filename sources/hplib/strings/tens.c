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


#include <hpmath.h>

#define LOCAL_TENS 


#define NUMBER_TENS  50

LOCAL_TENS
double
tinytens[]={
	1.0,
	1e-1,1e-2,1e-3,1e-4,1e-5,
	1e-6,1e-7,1e-8,1e-9,1e-10,
	1e-11,1e-12,1e-13,1e-14,1e-15,
	1e-16,1e-17,1e-18,1e-19,1e-20,
	1e-21,1e-22,1e-23,1e-24,1e-25,
	1e-26,1e-27,1e-28,1e-29,1e-30,
	1e-31,1e-32,1e-33,1e-34,1e-35,
	1e-36,1e-37,1e-38,1e-39,1e-40,
	1e-41,1e-42,1e-43,1e-44,1e-45,
	1e-46,1e-47,1e-48,1e-49,1e-50 };

LOCAL_TENS
double
bigtens[]={
	1.0,
	1e1,1e2,1e3,1e4,1e5,
	1e6,1e7,1e8,1e9,1e10,
	1e11,1e12,1e13,1e14,1e15,
	1e16,1e17,1e18,1e19,1e20,
	1e21,1e22,1e23,1e24,1e25,
	1e26,1e27,1e28,1e29,1e30,
	1e31,1e32,1e33,1e34,1e35,
	1e36,1e37,1e38,1e39,1e40,
	1e41,1e42,1e43,1e44,1e45,
	1e46,1e47,1e48,1e49,1e50 };



	

LOCAL_TENS
double
make_expo(double tens[], int exp)
{
	double expo = 1.0;
	
	while (exp) {
		int d;
		d = min(exp,NUMBER_TENS);
		expo *= tens[d];
		exp -= d;
	}
	
	return expo;
}

