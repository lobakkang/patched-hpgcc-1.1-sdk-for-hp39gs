//& ****************************************************************************
//&
//& Written by HPGCC Team
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
#include <hpstdio.h>


unsigned int *__exit_stk_state;

unsigned int errno;

// atexit machinery added by ibl 2005-01-31

ATEXIT_ENTRY *atexit_vector = NULL;

// semaphore added by ibl 2005-02-04
int _exit_lock = 0;

// open file list handling ibl 2005-02-06

OPEN_LIST_ENTRY *open_file_list = NULL;


int _exit_save(unsigned int *ptr)
{
asm volatile ("stmia r0,{r11-r14}");
return 1;
}

void __exit(unsigned int *ptr)
{
	asm volatile ("ldmia r0,{r11-r14}");
	asm volatile ("mov r0,#0");
	return;
}



void __exit_cleanup()
{
	

// COMPLETELY REWRITTEN BY CLAUDIO - JAN 2005

	
	// atexit handling added: < ibl ; 2005-01-31 >
	
	ATEXIT_ENTRY *q,*p = atexit_vector;
	
	// ensure exactly one entry	and signal exit() in progress
	
	if (_exit_lock++) return;

	while ((q=p)) {
		(*(p->f))();
		p = p->next;
		// free()'ing the memory is actually superfluous, since we are exit()'ing ...
		free(q);
		// ... but let's keep up the good style anyway 
	}
	
	// close all open files ...
	
	OPEN_LIST_ENTRY *g,*f = open_file_list;
	
	while((g=f)) {
		fclose(f->file);
		f = f->next;
		free(g);
	}
	

	// ADD MORE CLEANUP HERE

}

void exit(int code)
{
	__exit_cleanup();

	// RETURN TO _start
	__exit(__exit_stk_state);
}

