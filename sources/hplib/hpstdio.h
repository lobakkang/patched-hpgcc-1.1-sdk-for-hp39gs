
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

// $Header: /cvsroot/hpgcc/sources/hplib/hpstdio.h,v 1.11 2005/04/30 10:17:55 iblank Exp $

#ifndef __HPSTDIO_H
#define __HPSTDIO_H

// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif


#include <hpsys.h>
#include <kos.h>
#include <stdarg.h>

typedef struct
{
	H_FILE	handle;
} FILE;

// open file list handling < ibl ; 2005-02-06 >

typedef struct _open_list_entry {
	FILE *file;
	struct _open_list_entry *next;
} OPEN_LIST_ENTRY;


FILE *fopen(const char *fn, const char *mode);

int fclose(FILE *f);

int fgetc(FILE *f);

char * fgets(char *buf, int n, FILE *f);

int fputc(int c, FILE *f);

int fputs(const char *s, FILE *f);

SIZE_T fread(void *buf, SIZE_T size, SIZE_T cnt, FILE *f);

SIZE_T fwrite(const void *buf, SIZE_T size, SIZE_T cnt, FILE *f);

// fseek() replaced with macro for code size optimization < ibl; 2005-04-30 >
// int fseek (FILE *f, long offset, int mode);
#define fseek(fp,ofs,mode) kos_fseek((fp)->handle,(S32)(ofs),(U32)(mode))



//! RETURN THE CURRENT CALCULATOR MINIFONT
/** USES THE (STABLE) MINI_FONT ENTRY IN RAM (NOT ROM, SO THIS WON'T MOVE)
 * 
 * THIS IS 0x812CF IN SATURN DOMAIN. NOTICE THAT THE FONT IS NOT BYTE-ALIGNED
 * THE ACTUAL FONT STARTS 7 NIBBLES AFTER THIS ADDRESS
 */
void *get_minifont();

// Note: Bigfont is always 8*8 pixels
//       Height is for display puposes only
//       Width is normally 6 pixels
char *get_bigfont();
int get_bigfontheight();


/*!	\fn	int		readint()
	\brief	Read numbers from keyboard
	\retval The appropriate number, read until end of input ,i.e. \\r, or syntax error position.
*/
int		readint();

/*!	\fn	unsigned	readuint()
	\brief	Read numbers from keyboard
	\retval The appropriate number, read until end of input ,i.e. \\r, or syntax error position.
*/
unsigned	readuint();

/*!	\fn	unsigned	readhex()
	\brief	Read numbers from keyboard
	\retval The appropriate number, read until end of input ,i.e. \\r, or syntax error position.
*/
unsigned	readhex();

/*!	\fn	LONGLONG	readlonglong()
	\brief	Read numbers from keyboard
	\retval The appropriate number, read until end of input ,i.e. \\r, or syntax error position.
*/
LONGLONG	readlonglong();

/*!	\fn	ULONGLONG readulonglong()
	\brief	Read numbers from keyboard
	\retval The appropriate number, read until end of input ,i.e. \\r, or syntax error position.
*/
ULONGLONG	readulonglong();

/*!	\fn	double 		readdouble()
	\brief	Read numbers from keyboard
	\retval The appropriate number, read until end of input ,i.e. \\r, or syntax error position.
*/
double	readdouble();


/*!	\fn int puts(const char *buf)
	\brief Writes a string pointed to by \a buf to the screen and returns the number of characters written.
	\param buf Pointer to zero delimited string
	\retval Number of characters written
*/
EXTERN int puts(const char *);

/*!	\fn	int putchar(int c)
	\brief	Writes a single character \a c to the screen and returns it's argument.
	\param c Character to be written
	\retval Unchanged argument or -1 if error
	
*/
EXTERN int putchar(int);

/*!	\fn	char	*gets(char *buf)
	\brief	Reads a string from the keyboard.
	\param	buf Pointer to buffer, large enough to hold the string.
	\retval	The argument pointer
*/

// standard file functions

int write(int fd, const char *buf, size_t count);
int isatty(int fd);

#ifdef NO_ASSEMBLY_GETS
EXTERN char	*_gets(char *buf);
#define gets _gets
#else
EXTERN char	*gets(char *buf);
#endif

// console io

/*!	\fn	int	printf(const char *fmt, ...)
	\brief  Stripped down printf surrogate
	Refer to the source for format restrictions.
*/

int printf(const char *fmt, ...);
int sprintf(char *out, const char *fmt, ...);
int vsprintf(char *out,const char *fmt, va_list argp);
int fprintf(FILE *f, const char *fmt, ...);


// Stripped down Integer versions of *printf
// These are lacking floating point formats

int iprintf(const char *fmt, ...);
int isprintf(char *out, const char *fmt, ...);
int ivsprintf(char *out,const char *fmt, va_list argp);
int ifprintf(FILE *f, const char *fmt, ...);


#ifdef TINY_PRINTF
#define printf iprintf
#define sprintf isprintf
#define vsprintf ivsprintf
#define fprintf ifprintf
#endif


#ifndef DOXYGEN_SKIP
int get_decimal_digits();
void set_decimal_digits(int v);
char *get_decimal_separator();
void set_decimal_separator(char a);
#endif



#endif // __HPSTDIO_H
