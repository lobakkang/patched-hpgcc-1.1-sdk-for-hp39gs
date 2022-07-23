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


/* $Header: /cvsroot/hpgcc/sources/hplib/sys/realloc.c,v 1.2 2005/01/06 18:17:46 cdsmith Exp $ */


#include <hpstdlib.h>
#include <hpstring.h> // for memcpy

#define CAST_INT	int
#define BRKSIZE		4096

#define PTRSIZE		((int) sizeof(void *))
#define ALIGN(x,a)	(((x) + (a - 1)) & ~(a - 1))
#define NEXT_SLOT(p)	(* (void **) ((p) - PTRSIZE))
#define NEXT_FREE(p)	(* (void **) (p))

extern void * _malloc_empty;

void *
realloc(void *oldp, size_t size)
{
  register char *prev, *p, *next, *new;
  char *old = oldp;
  register size_t len, n;

  if (!old) return malloc(size);
  else if (!size) {
	free(oldp);
	return NULL;
  }
  len = ALIGN(size, PTRSIZE) + PTRSIZE;
  next = NEXT_SLOT(old);
  n = (int)(next - old);			
 
  for (prev = 0, p = _malloc_empty; p != 0; prev = p, p = NEXT_FREE(p)) {
	if (p > next)
		break;
	if (p == next) {	
		NEXT_SLOT(old) = NEXT_SLOT(p);
		if (prev)
			NEXT_FREE(prev) = NEXT_FREE(p);
		else
			_malloc_empty = NEXT_FREE(p);
		next = NEXT_SLOT(old);
		break;
	}
  }
  new = old + len;
  
  if (new <= next && new >= old) {		
	if (new + PTRSIZE < next) {		
		NEXT_SLOT(new) = next;
		NEXT_SLOT(old) = new;
		free(new);
	}
	return old;
  }
  if ((new = malloc(size)) == NULL)		
	return NULL;
  memcpy(new, old, n);				
  free(old);
  return new;
}
