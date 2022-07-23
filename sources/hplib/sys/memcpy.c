//& ****************************************************************************
//&
//& Written by Claudio Lapilli, August 2004
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

#include <hpstdlib.h>

// Simpliest version that works
// SLOWEST version that works !

/*
void *memcpy(void *_dest, const void *_source, size_t nbytes)
{
	register char *dest= (char *) _dest;
	register char *source= (char *) _source;
	while(nbytes--) 
		*dest++=*source++;
	
	
	return _dest;
}
*/


/*
void *memcpy(void *_dest, const void *source, size_t nbytes)
{
	register void *dest=_dest;
	while(nbytes&3) 
	{
		*((char *)dest)=*((char *)source);
		++((char *)dest);
		++((char *)source);
		--nbytes;
	}
	while(nbytes>=4) 
	{
		*((int *)dest)=*((int *)source);
		++((int *)dest);
		++((int *)source);
		--nbytes;
	}
	while(nbytes) 
	{
		*((char *)dest)=*((char *)source);
		++((char *)dest);
		++((char *)source);
		--nbytes;
	}
	return _dest;
}
*/


// FASTEST that works

void *
memcpy(void *trg, const void *src, size_t n)
{
	void *r  = trg;
	char *t8 = (char *) trg;
	char *s8 = (char *) src;
	
	#define ESIZE sizeof(size_t)
	#define CSIZE (4*ESIZE)
	
	if (n >= CSIZE &&  ! ( ((unsigned)t8 & (ESIZE-1)) || ((unsigned)s8 & (ESIZE-1)) ) ) {
	
		// source & target properly aligned
		// use word copy...
	
		size_t *T,*S;
	
		
		T = (size_t *) t8;
		S = (size_t *) s8;
		
		for (; n >= CSIZE ;) {
			*T++ = *S++;
			*T++ = *S++;
			*T++ = *S++;
			*T++ = *S++;
			n -= CSIZE;
		}
			
		for (; n >= ESIZE ;) {
			*T++ = *S++;
			n -= ESIZE;
		}
		
		if ( n > 0 ) {
			
			t8 = (char *) T;
			s8 = (char *) S;
				
			for (; n-- ;)
				*t8++ = *s8++;
		}
	}
	else if(n > 0) 
		for (; n-- ;)
			*t8++ = *s8++;
	
		
	return r;
}



