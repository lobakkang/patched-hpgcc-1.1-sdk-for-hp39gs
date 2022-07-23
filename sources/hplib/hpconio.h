//& ****************************************************************************
//&
//& Written by Ingo Blank, August 2004
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



/*!	\file hpconio.h
	\brief Header file for HP49 console I/O
*/

#ifndef _HPCONIO_H
#define _HPCONIO_H

#include <stddef.h>
#include <hpstdlib.h>

// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif


/*!	\fn int puts(const char *buf)
	\brief Writes a string pointed to by \a buf to the screen and returns the number of characters written.
	\param buf Pointer to zero delimited string
	\retval Number of characters written
*/

/*!	\fn char *ints(int num ,int base)
	\brief Returns a pointer to a base \a base string representation of \a num
	\param num Number to be written
	\param base The base, where 2 <= base <= 36
	\retval Pointer to a zero delimited string
	
	\warning The string pointed to is static and must therefore instantly be copied, if intended for later usage.
*/

/*!	\fn  char *uints(unsigned num ,int base)
	\brief Returns a pointer to a base \a base string representation of \a num
	\param num Number to be written
	\param base The base, where 2 <= base <= 36
	\retval Pointer to a zero delimited string
	\warning The string pointed to is static and must therefore instantly be copied, if intended for later usage.
	
*/

/*!	\fn	int putchar(int c)
	\brief	Writes a single character \a c to the screen and returns it's argument.
	\param c Character to be written
	\retval Unchanged argument or -1 if error
	
*/

/*!	\fn	void putint(int num)
	\brief	Writes an integer \a num to the screen.
	\param	num Number to be written
	
*/


/*!	\fn 	void putintb(int num ,int base)
	\brief	Writes a base \a base representation of \a num to the screen.
	\param num Number to be written
	\param base The base, where 2 <= base <= 36
*/


/*!	\fn	void beep()
	\brief	Beeps the speaker.
*/


/*!	\fn	void home();
	\brief	Positions the virtual write mark at screen position (0,0), i.e. 'home'
*/

/*!	\fn	int getx()
	\brief	Returns the current write mark's x-component.
	\retval	Current screen position x
*/

/*!	\fn	int gety()
	\brief	Returns the current write mark's y-component.
	\retval	Current screen position y
*/

/*!	\fn	void clreol()
	\brief	Clear to End-Of-Line from current write mark position.
*/
	
/*!	\fn	void _clear_screen()
	\brief	Clears the entire screen
*/

/*!	\def	clear_screen _clear_screen
	\brief	A synonym for _clear_screen
*/
 
/*!	\fn	void gotoxy(int x,int y)
	\brief	Position write mark
	\param	x x-position to go to
	\param 	y y-position to go to
*/

/*!	\fn	int screen_width()
	\brief	Returns screen width in character units.
	\retval	Screen width
*/

/*!	\fn	int screen_height()
	\brief	Returns screen height in character units.
	\retval	Screen height
*/


/*!	\fn	int get_tabsize()
	\brief	Returns current tab width in character units.
	\retval	Tab width
*/

/*!	\fn	void set_tabsize(int width)
	\brief	Sets current tab width in character units.
	\param	width New tab width
*/

/*!	\fn int getchar()
	\brief Reads a character from keyboard
	\retval ASCII code of entered character
*/


/*!	\fn	int	getkey(int wait)
	\brief	Reads a keystroke and returns immediately if no key is pressed and \a wait is zero.
	\param	wait Wait for keystroke (0/1)
	\retval	Zero if no key pressed, the key's ASCII code otherwise.
*/

/*!	\fn	char	*gets(char *buf)
	\brief	Reads a string from the keyboard.
	\param	buf Pointer to buffer, large enough to hold the string.
	\retval	The argument pointer
*/







// crt0

EXTERN int puts(const char *);
EXTERN char *ints(int,int);
EXTERN char *uints(unsigned,int);
EXTERN int putchar(int);
EXTERN void putint(int);
EXTERN void putintb(int,int);
EXTERN unsigned randx();
EXTERN int delta_seconds(int,int);
EXTERN void beep();

// console io 

EXTERN void home();
EXTERN int getx();
EXTERN int gety();
EXTERN void clreol();
#define clear_screen _clear_screen
EXTERN void _clear_screen();
EXTERN void gotoxy(int,int);
EXTERN int screen_width();
EXTERN int screen_height();
EXTERN int get_tabsize();
EXTERN void set_tabsize(int);
EXTERN int getchar();
EXTERN int getkey(int wait);
#ifdef NO_ASSEMBLY_GETS
EXTERN char	*_gets(char *buf);
#define gets _gets
#else
EXTERN char	*gets(char *buf);
#endif

int get_decimal_digits();
void set_decimal_digits(int v);
char *get_decimal_separator();
void set_decimal_separator(char a);


#endif 

