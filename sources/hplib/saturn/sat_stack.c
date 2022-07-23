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


//$Header: /cvsroot/hpgcc/sources/hplib/saturn/sat_stack.c,v 1.2 2004/11/25 02:09:34 iblank Exp $

#include <hpgcc49.h>

//@</head>

int
sat_stack_depth()
{
	unsigned stack_ptr,p;
	int depth;
	stack_ptr = sat_peek_sat_addr(SAT_DSKTOP);
	for (depth = 0 ;  (p = sat_peek_sat_addr(stack_ptr)) ; depth++, stack_ptr += 5) ;
	return depth;
}



int	
sat_get_stack_element(int index, SAT_STACK_ELEMENT *p)
{
	
	p->addr = p->prologue = 0;
	
	if (index > 0 && index <= sat_stack_depth()) {	
			p->addr 	= sat_peek_sat_addr(sat_peek_sat_addr(SAT_DSKTOP)+5*(index-1));
			p->prologue = sat_peek_sat_addr(p->addr);
			return 0;
		
	}
	
	return -1;
}


int
sat_stack_levels_avail()
{
	return (SAT_DSKTOP & 0x1FFF) / 5;
}



unsigned
sat_stack_init()
{
	// temporarily remove ("pseudo drop") the level 1 element (launcher bias)
	
	unsigned stack_ptr = sat_peek_sat_addr(SAT_DSKTOP);	
	unsigned stack_bias = sat_peek_sat_addr(stack_ptr);
	sat_poke_sat_addr(SAT_DSKTOP,stack_ptr+5);
	
	return stack_bias;
}

void
sat_stack_exit(unsigned stack_bias)
{
	// restore stack bias, so that the launcher can pop it's data off the stack
	
	unsigned stack_ptr = sat_peek_sat_addr(SAT_DSKTOP);
	sat_poke_sat_addr(SAT_DSKTOP,stack_ptr-5);
	sat_poke_sat_addr(stack_ptr-5,stack_bias);
}



	








