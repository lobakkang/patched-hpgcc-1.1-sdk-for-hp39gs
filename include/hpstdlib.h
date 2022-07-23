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


/*!	\file	hpstdlib.h
	\brief	Standard library
*/

#ifndef _HPSTDLIB_H
#define _HPSTDLIB_H


// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif



#include <hpsys.h>

// TODO: Doxygen (ibl)
// abstract PRNG descriptor
typedef unsigned (*RNDFUNC)(int);
typedef void (*SRNDFUNC)(unsigned);

// dispatch pointer
extern RNDFUNC rand_hook;
extern SRNDFUNC srand_hook;


/*!	\fn	void *malloc(size_t)
	\brief	Standard C library function
*/
void 	*malloc(size_t);


/*!	\fn	void free(void *)
	\brief	Standard C library function
*/
void 	free(void *);


/*!	\fn	void *calloc(size_t nelem, size_t elsize)
	\brief 	Standard C library function
*/
void 	*calloc(size_t, size_t);

/*!	\fn	void *realloc(void *oldp, size_t size)
	\brief 	Standard C library function
*/

void * realloc(void *oldp, size_t size);




// runtime

/*!	\fn	void	exit(int)
	\brief	Standard C library function
*/
void	exit(int);


/*!	\fn	int	atexit(void(*__func)(void))
	\brief	Standard C library function
*/
int	atexit(void(*__func)(void));



// misc

/*!	\fn	unsigned mwc(int bits)	
	\brief	32 bit multiply with carry pseudo RNG
	\retval "bits" bit pseudo random number.
	
	Very fast PRNG with extreme cycle length.
	\warning Don't use for cryptography.
*/

unsigned	mwc(int bits);	// multiply with carry 32 bit pseudo RNG


// misc

/*!	\fn	unsigned rand()	
	\brief	wrapper for concrete PRNG implementation
	\retval 32 bit pseudo random number.
	
	\warning Don't use for cryptography. Use srand() first!
*/

unsigned	int rand(void);
unsigned 	int rand_bits(int bits);


// misc

/*!	\fn	unsigned srand()	
	\brief	seeds the random sequence
	
	\warning Don't use for cryptography.
*/

void	srand(unsigned int seed);	// multiply with carry 32 bit pseudo RNG


int (memcmp)(const void *s1, const void *s2, size_t n); //Memory Compare
//Al Nov '04 - TODO: Documentation?

#endif 
