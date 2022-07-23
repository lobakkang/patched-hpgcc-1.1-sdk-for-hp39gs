//& ****************************************************************************
//&
//& Written by Al Borowski, September 2004
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

int keyb_isKeyPressed(unsigned char col, unsigned char row)
{
	//returns 1 if the key at logical column 'col', logical row 'row', is pressed
	//0 otherwise.

	unsigned int volatile * GPGDAT = (int*) 0x7A00064; //data
	unsigned int volatile * GPGCON = (int*) 0x7A00060; //control
	int volatile i=0;
	int keyPress = 0;

	if (!keyb_isAnyKeyPressed())
	{
		return 0; //bail out right away if no key is pressed
	}

	unsigned int control = 1<<((col+8)*2); //set the correct col pin to output, others inputs
	control = control | 0xAAA9; //fix up the lower bits
	*GPGCON = control; // write the new control value.

	//wait a little while to take effect. Delay valid for slow mode
	for (i=0;i<100;i++)
	{}

	keyPress = !( (  (*GPGDAT)  >> (row+1)  )  &1);

	*GPGCON = 0x5555AAA9; //restore default
	//wait a little while to take effect.
	for (i=0;i<100;i++)
	{}
	
	return keyPress;
}
