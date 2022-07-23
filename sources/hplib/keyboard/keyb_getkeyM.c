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


int keyb_getkeyM(int wait)
{
// by Claudio
	keymatrix m;
	keyb_getmatrix(&m);

	if(wait) {
		// wait for a non-shift key to be pressed
		while( ((m.hiword&0x8fffffff)|m.loword )==0 ) keyb_getmatrix(&m);
	}

	int kcode,shft=SHFTPLANE(m.hiword);

	int k;
	for(k=0,kcode=0;k<8;++k,kcode+=8)
	{
		if(m.bytes[k]!=0) {
			k=m.bytes[k];
			while( !(k&1) ) {
				k>>=1;
				++kcode;
				}
		break;
		}
	}


	if(wait) {
	while( ((m.hiword&0x8fffffff)|m.loword )!=0 ) keyb_getmatrix(&m);
	if(kcode>=60) kcode=63;
	}
	
	if(kcode<60) return kcode | shft;
	if(kcode<64) return kcode;
	return 0;

}
