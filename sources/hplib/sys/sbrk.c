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


#define ALIGN4(x) (((unsigned)(x)+3) & 0xFFFFFFFCU)

#include <hpstdlib.h>

// <Benjamin>
// replace _heap_bottom by _heap_base_addr
extern unsigned _heap_base_addr;
// </Benjamin>

char *heap_ptr = 0;


// Changed overflow/stack collision checking method to manually calculating virtual stack pointer address.
// According to Claudio's instructions in his mail from 2004-10-05
// [ibl 04/10/05]

// Changed back to virtual stack pointer comparison, suitable for new "memory packing" loader
// <ibl; 2004-11-07>

int
_brk(char *top)
{
	
	register unsigned int stack_ptr asm("sp");
	
	
	if (top < (char *) stack_ptr && top > (char *)_heap_base_addr) {
		heap_ptr = (char *) ALIGN4(top);
		return 0;
	}
	else
		return -1;
}

int
brk(char *top)
{
	return _brk(top);
}


char *
sbrk(int incr)
{	
	char *base,*new_heap;
	register unsigned int stack_ptr asm("sp");
	
	
	if (heap_ptr == 0) 		
		heap_ptr = (char *)_heap_base_addr;
	
	base = heap_ptr;
	
	new_heap = (char *)ALIGN4(heap_ptr + incr);
	
	if ((new_heap > (char *) stack_ptr) ||  (new_heap < (char *)_heap_base_addr))
		return (char *) -1;
	
	heap_ptr = new_heap;
	return base;

}

char *
_sbrk(int incr)
{
	return sbrk(incr);
}



	
	
