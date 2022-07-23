//& ****************************************************************************
//&
//& Written by Al Borowski, August 2004
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



/*!	\file hpscreen.h
	\brief Header file for system screen functions
*/

#ifndef _HPSCREEN_H
#define _HPSCREEN_H

// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif

// particular functions
void print(char * string, int x, int y);
volatile char* getLCDPointer(int x, int y);
void drawBlockOR (unsigned char* sprite, int length, int x, int y);
void drawBlockXOR (unsigned char* sprite, int length, int x, int y);
int  drawBlockXOR4bitC(unsigned char* sprite, int height, int x, int y);
int	testBlock4bitC(unsigned char* sprite, int height, int x, int y);

void fillTiles(unsigned char* sprite, int length, int x,int y, int right, int down);
void clearScreen();

char *getMF(int z);



#endif 

