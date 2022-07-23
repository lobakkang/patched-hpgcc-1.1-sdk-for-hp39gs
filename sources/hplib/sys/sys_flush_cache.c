//& ****************************************************************************
//&
//& Written by HP-GCC Team, January 2005
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


static void _flush_MVA(void) __attribute__ ((naked));
static void _flush_MVA(void)
{
	// REMOVED NOP'S, SEEMS TO WORK FINE 01/09/05

    asm volatile ("stmfd sp!, {r0, r14}");
	asm volatile ("___looplabel:");
	// CLEAN SINGLE ENTRY USING MVA
    asm volatile ("mcr p15, 0, r0, c7, c10, 1");
	// next MVA
	asm volatile ("add r0,r0,#0x20");
	asm volatile ("teq r0,r1");
	asm volatile ("bne ___looplabel");
    asm volatile ("ldmfd sp!, {r0, r14}");
    asm volatile ("movs pc, r14");
}

static void __go_superv(int firstMVA,int lastMVA) __attribute__ ((naked));
static void __go_superv(int firstMVA,int lastMVA)
{
    asm volatile ("stmfd sp!, {r2-r3, lr}");

	// CODE TO FOOL THE COMPILER, MAY NOT WORK IN FUTURE VERSIONS...
	// THE COMPILER OPTIMIZES THIS CODE AWAY, BUT AT LEAST IT 
	// DOES NOT ELIMINATE THE ENTIRE _flush_buf_handler FUNCTION.

	register int fptr asm("r3");
	fptr=(int)_flush_MVA;


	// STANDARD CODE FROM HERE

    asm volatile ("mov r2, #0x8000000");
    asm volatile ("add r2, r2, #8");
    asm volatile ("adr r3, _flush_MVA");
    asm volatile ("swp r3, r3, [r2]");
    asm volatile ("add lr, pc, #0");
    asm volatile ("swi #0");
    asm volatile ("str r3, [r2]");
    asm volatile ("ldmfd sp!, {r2-r3, pc}");
}

// FLUSH THE D-CACHE IN A BLOCK OF size BYTES

void sys_flush_cache(int *ptr,int size)
{
	int firstMVA=(int)ptr;
	int lastMVA=firstMVA+size+32;
	firstMVA&=0xffffffe0;
	lastMVA&=0xffffffe0;
	__go_superv(firstMVA,lastMVA);
}

