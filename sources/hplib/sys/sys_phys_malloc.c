//& ****************************************************************************
//&
//& Written by Ingo Blank & Claudio Lapilli
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

#include <hpsys.h>
#include <hpstdlib.h>

int
sys_mem_classify(int addr)
{
	int r,a = (addr >> 16) & 0xf;
	
	// 0 OR 1 --> SYSTEM MEMORY
	// 2 OR 3 --> PORT1
	// 4 THRU 7 --> MAIN RAM
	
	if (a < 2)
		r = 0;
	else if (a > 3)
		r = 2;
	else
		r = 1;
		
	return r;
}


static int
is_continuous(void *ptr, int size)
{
	int start = sys_map_v2p((int)ptr);
	int end   = sys_map_v2p((int)ptr+size);
	
	return(sys_mem_classify(start)==sys_mem_classify(end));

}

// TODO: unit test, stress test

void
*sys_phys_malloc(size_t size)
{
	#define TRIES 5
	void *p[TRIES];
	int i,tries = 0;
	
	do {
		p[tries] = malloc(size);
		if(is_continuous(p[tries],size)) 
			break;
	} while (++tries < TRIES);
	
	for(i = 0; i < tries; i++)
		free(p[i]);

	if(tries < TRIES) {
		// ADDED FLUSH CACHES ON VIRTUAL ADDRESSES - CLAUDIO 01/09/05
		sys_flush_cache(p[tries],size);
		return p[tries];
	}
	else return NULL;
	
	
}




