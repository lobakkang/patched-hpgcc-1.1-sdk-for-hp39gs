//& ****************************************************************************
//&
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

#include <hpkeyb49.h>


void __keybdelay()
{
	// REPLACE BY SOMETHING MORE SOPHISTICATED LATER
	int k;

	for(k=0;k<100;++k) ;
}

void keyb_getmatrix(keymatrix *m)
{
// by Claudio, with portions (well, most of it) of code by Al

	unsigned int volatile * GPGDAT = (int*) 0x7A00064; //data
	unsigned int volatile * GPGCON = (int*) 0x7A00060; //control

	int lo=0,hi=0;

	int col;
	unsigned int control;

	for(col=7;col>=4;--col)
	{
	
	control = 1<<((col+8)*2); //set the correct col pin to output, others inputs
	control = control | 0xAAA9; //fix up the lower bits
	*GPGCON = control; // write the new control value.


	// DELAY 100us APPROX.
	__keybdelay();


	hi=(hi<<8) | ((~(*GPGDAT))&0xfe);

	}

	for(;col>=0;--col)
	{
	
	control = 1<<((col+8)*2); //set the correct col pin to output, others inputs
	control = control | 0xAAA9; //fix up the lower bits
	*GPGCON = control; // write the new control value.

	// DELAY 100us APPROX.
	__keybdelay();

	lo=(lo<<8) | ((~(*GPGDAT))&0xfe);

	}

	*GPGCON = 0x5555AAA9; //restore default

	unsigned int volatile GPFDAT = *((int*) 0x7A00054);

	hi |=  (GPFDAT&0x70)<<24;
	hi |=  GPFDAT<<31;

	m->loword=lo;
	m->hiword=hi;

	return;
}
