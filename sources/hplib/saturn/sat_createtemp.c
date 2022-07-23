//@<head>
//& <prolog>
//& ****************************************************************************
//&
//& Written by Ingo Blank & Claudio Lapilli, October 2004
//&
//& Copyright (C) 2004 HP-GCC Development Team
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

//& </prolog>

// $Header: /cvsroot/hpgcc/sources/hplib/saturn/sat_createtemp.c

#include <hpgcc49.h>

//@</head>

//@<func name="sat_createtemp">
int
sat_createtemp(int objsize)
{
	
	// CREATETEMP IMPLEMENTATION
	// objsize=size of object including prolog
	// in nibbles

	extern unsigned _mmu_table_addr;
	
	int ttop=sat_peek(SAT_TEMPTOP,5);
	int rstk=sat_peek(SAT_RSKTOP,5);
	int size=rstk-ttop;
	int freemem,freeend;
	int ptr;

	// check for enough room here
	freeend=sys_map_v2p(_mmu_table_addr);
	freeend<<=1;
	freeend&=0x000FFFFF;
	if(rstk+11+objsize>=freeend)
	{
	// insufficient memory to create object
	return 0;
	}


	// make room in memory
	sat_moveup(ttop,ttop+objsize+6,size);
	
	// adjust tempob chain
	
	ptr=ttop+1+objsize;
	sat_poke(ptr,objsize+6,6);
	
	// adjust pointers
	
	// RSKTOP
	sat_poke(SAT_RSKTOP,sat_peek(SAT_RSKTOP,5)+objsize+6,5);
	
	// TEMPTOP
	sat_poke(SAT_TEMPTOP,sat_peek(SAT_TEMPTOP,5)+objsize+6,5);
	
	// adjust free memory
	freemem=sat_peek(SAT_DSKTOP,5)-sat_peek(SAT_RSKTOP,5);
	freemem/=5;
	sat_poke(SAT_AVMEM,freemem,5);
	
	// return addr to prolog of new object
	return ttop+1;

}
//@</func>


