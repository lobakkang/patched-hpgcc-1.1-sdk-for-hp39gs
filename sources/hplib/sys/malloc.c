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


/* $Header: /cvsroot/hpgcc/sources/hplib/sys/malloc.c,v 1.4 2004/11/10 14:37:31 iblank Exp $ */


#include <hpstdlib.h>

extern int errno;

#ifndef ENOMEM
#define ENOMEM -90012
#endif

#define CAST_INT	int
#define BRKSIZE		4096

#define PTRSIZE		((int) sizeof(void *))
#define ALIGN(x,a)	(((x) + (a - 1)) & ~(a - 1))
#define NEXT_SLOT(p)	(* (void **) ((p) - PTRSIZE))
#define NEXT_FREE(p)	(* (void **) (p))


extern void *_sbrk(int);
extern int _brk(void *);
void *_malloc_bottom, *_malloc_top, *_malloc_empty;


void free(void *ptr);

static int grow(size_t len)
{
  register char *p;

  errno = ENOMEM;
  if ((char *) _malloc_top + len < (char *) _malloc_top
      || (p = (char *)ALIGN((CAST_INT)_malloc_top + len, BRKSIZE)) < (char *) _malloc_top 
      || _brk(p) != 0)
	return(0);
  NEXT_SLOT((char *)_malloc_top) = p;
  NEXT_SLOT(p) = 0;
  free(_malloc_top);
  _malloc_top = p;
  return 1;
}


void *
malloc(size_t size)
{
  register char *prev, *p, *next, *new;
  register unsigned len, ntries;

  if (size == 0) return NULL;
  errno = ENOMEM;
  for (ntries = 0; ntries < 2; ntries++) {
	if ((len = ALIGN(size, PTRSIZE) + PTRSIZE) < 2 * PTRSIZE)
		return NULL;
	if (_malloc_bottom == 0) {
		if ((p = _sbrk(2 * PTRSIZE)) == (char *) -1)
			return NULL;
		p = (char *) ALIGN((CAST_INT)p, PTRSIZE);
		p += PTRSIZE;
		_malloc_top = _malloc_bottom = p;
		NEXT_SLOT(p) = 0;
	}

	for (prev = 0, p = _malloc_empty; p != 0; prev = p, p = NEXT_FREE(p)) {
		next = NEXT_SLOT(p);
		new = p + len;	
		if (new > next || new <= p)
			continue;		
		if (new + PTRSIZE < next) {	
			NEXT_SLOT(new) = next;
			NEXT_SLOT(p) = new;
			NEXT_FREE(new) = NEXT_FREE(p);
			NEXT_FREE(p) = new;
		}
		if (prev)
			NEXT_FREE(prev) = NEXT_FREE(p);
		else
			_malloc_empty = NEXT_FREE(p);

		return p;
	}
	if (grow(len) == 0)
		break;
  }

  return NULL;
}


void
free(void *ptr)
{
  register char *prev, *next;
  char *p = ptr;

  if (!p) return;

  for (prev = 0, next = _malloc_empty; next != 0; prev = next, next = NEXT_FREE(next))
	if (p < next)
		break;
  NEXT_FREE(p) = next;
  if (prev)
	NEXT_FREE(prev) = p;
  else
	_malloc_empty = p;
  if (next) {
	if (NEXT_SLOT(p) == next) {		
		NEXT_SLOT(p) = NEXT_SLOT(next);
		NEXT_FREE(p) = NEXT_FREE(next);
	}
  }
  if (prev) {
	if (NEXT_SLOT(prev) == p) {		
		NEXT_SLOT(prev) = NEXT_SLOT(p);
		NEXT_FREE(prev) = NEXT_FREE(p);
	}
  }
}

