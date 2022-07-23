//& ****************************************************************************
//&
//& Written by Maurin Benjamin, October 2004
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

// $Header: /cvsroot/hpgcc/sources/hplib/hpstring.h,v 1.11 2005/04/03 11:56:32 njz3 Exp $


/*!	\file	hpstring.h
	\brief	Standard String functions
*/

#ifndef _HPSTRING_H
#define _HPSTRING_H

// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif


#include <hpctype.h>
#include <kos.h>


//!	Length of s
int	strlen(const char *s);

//!	Copy source to destination
char	*strcpy(char *dest, const char *src);

//!	Copy n chars of src in dest
char 	*strncpy(char *dest, char *src, int n);

//!	Append source after enf of destination.  */
char	*strcat(char *dest, const char *src);

//!	Compare s1 and s2 (<0 ==0 or >0)
int	strcmp(register const char *s1, register const char *s2);

//!	Compare n chars of s1 and s2 (<0 ==0 or >0)
int strncmp ( const char *s1, const char *s2, int num);

//!	Convert int to a string with specific base
char 	*itoa(int z, char * buff, int base);

//!	\fn	char 	*utoa(unsigned z, char * buff, int base)
char 	*utoa(unsigned z, char * buff, int base);

//!	\fn	char	*lltoa(LONGLONG, char *,int base)
char	*lltoa(LONGLONG, char *,int base);

//!	\fn 	char	*ulltoa(ULONGLONG, char *, int base)
char	*ulltoa(ULONGLONG, char *, int base);

/*!	\fn	char 	*upper(char *t,char *s)
	\brief	Convert string to uppercase
	\param	t pointer to target
	\param	s pointer to source
	\retval	pointer to target
*/
char 	*upper(char *t,char *s);

/*!	\fn	char 	*lower(char *t,char *s)
	\brief	Convert string to uppercase
	\param	t pointer to target
	\param	s pointer to source
	\retval	pointer to target

*/

char *str_unquote(char *s, char c);
char *strdup(const char *s);

char 	*lower(char *t,char *s);

#ifndef DOXYGEN_SKIP


char *dtoa(double x, char *buf, int force_expo);

char 	*xpad(char *t, char *s, int n, int left, char c);

int		atoi_base(char *, int base);
unsigned	atoui_base(char *, int base);
LONGLONG	atoll_base(char *, int base);
ULONGLONG	atoull_base(char *, int base);

#endif

int		atoi(char *);
unsigned	atoui(char *);
LONGLONG 	atoll(char *);

char *
ints(int z, int base);

char *
uints(unsigned z, int base);


ULONGLONG	atoull(char *);


double		atof(char *);

void* memcpy(void *out, const void *in, int n);
void memcpyw(void *dest,const void *source,int nwords);
void * memset (char * dest, int C, int LENGTH);
void memsetw(void *dest,int value, int nwords);
void *memmove(void *_dest, const void *_source, size_t nbytes);
//Additional string functions
//Added by Al Borowski, 19th Nov, 2004
//TODO: Add proper documentation?

char *(strchr)(const char *s, int c);
char *(strncat)(char *s1, const char * s2, size_t n);
char *(strrchr)(const char *s, int c);
size_t (strcspn)(const char *s1, const char *s2);
char *(strpbrk)(const char *s1, const char *s2);
char *(strtok)(char *s1, const char *s2);
char *(strstr)(const char *s1, const char *s2);
size_t (strspn)(const char *s1, const char *s2);


#endif 
