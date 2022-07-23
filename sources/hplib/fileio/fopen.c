
// Simple Stream Library for HP49g+

//& ****************************************************************************
//&
//& Written by Ingo Blank, September 2004
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

#include "hpstdio.h"
#include "hpstdlib.h"
#include "kos.h"

extern OPEN_LIST_ENTRY *open_file_list;

FILE *fopen(const char *fn, const char *mode)
{
	U32 fmode;
	FILE *f;
	H_FILE h;
	
	fmode = FILE_READONLY; // default
	
	if (*mode == 'w') 
		fmode = FILE_READWRITE;
		
	else if (*mode == 'a')
		fmode = FILE_APPEND;
	
	if ((h = kos_fopen((P_BYTE) fn,fmode)) >= 0) {
		
		OPEN_LIST_ENTRY *q;
		
		f = (FILE *) malloc(sizeof(FILE));
		f->handle = h;
		
		// open file list handling < ibl ; 2005-02-06 >
		
		q = (OPEN_LIST_ENTRY *) malloc(sizeof(OPEN_LIST_ENTRY));
		q->file = f;
		q->next = open_file_list;
		open_file_list = q;

	}
	else {
		// errno = h;
		f = NULL;
	}
	
	return f;
}


