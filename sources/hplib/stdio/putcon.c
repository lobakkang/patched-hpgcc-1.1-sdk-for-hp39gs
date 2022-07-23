//& ****************************************************************************
//&
//& Written by Claudio Lapilli, October 2004
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

#include <hpkeyb49.h>
#include <hpstdio.h>
#include <hpconio.h>
#include <kos.h>
#include <hpstring.h>


extern unsigned int __display_buf; //default monochrome display buffer

// CONVERTED FROM putcon.s
// ORIGINAL WORK BY Ingo Blank

#define _TAB_SIZE 4

int __scr_h = 13, __scr_w = 33;
int __pos_x=0,__pos_y=0,__ch_w=4,__ch_h=6;
char *__decimal_separator=".";
int __decimal_digits=6;

int __auto_cr=1;


// GENERAL INTERNAL FUNCTIONS

int get_decimal_digits() { return __decimal_digits; }
void set_decimal_digits(int v) { __decimal_digits=v; }
char *get_decimal_separator() { return __decimal_separator; }
void set_decimal_separator(char a) { *__decimal_separator=a; }

void beep()
{
	 // parameters just work correctly @ 75 MHz < ibl ; 2004-10-28 >
	kos_beep(880,100,2);
	return;
}

extern void memsetw(void *dest,int value, int nwords);
extern void memcpyw(void *dest,const void *source,int nwords);

void _clear_screen()
{
	memsetw((void *)__display_buf,0,5*sys_lcdgetheight());
	// it's assumed, that the programmer also wants to set the cursor at home
	// < ibl ; 2004-10-28 >
	home();
}




void scroll()
{

	int nwords=5*sys_lcdgetheight();
	// AREN'T WE SCROLLING THE ANNUNCIATORS TOO WHEN DOING THIS?

	//memcpyw((void *)__display_buf,(void *)(__display_buf+__ch_h+(__ch_h<<2)),400-__ch_h-(__ch_h<<2));
	
	// nb of words per line: 5
	// nb of lines to scroll: __ch_h
	// -> nb of words to skip = 5*__ch_h = __ch_h<<2+__ch_h
	memcpyw((void *)__display_buf,
		(void *)((int *)__display_buf+(__ch_h+(__ch_h<<2))),
		nwords-__ch_h-(__ch_h<<2));

	// smooth option not supported
	
	memsetw((void *) ((int *)(__display_buf+nwords*4)-(__ch_h+(__ch_h<<2))),0,__ch_h+(__ch_h<<2));

}


void putcon_stdscreen(c)
{
void *minif=get_minifont();

int cdatalow,cdatahigh;
int offset,rot,rotx;
char *scrptr=(char *)__display_buf;
char mask;
int f;

// POINT TO START OF LINE
scrptr+=__pos_y*__ch_h*20;
scrptr+=__pos_x>>1;
rotx=__pos_x&1;
mask=(rotx)? 0xf0:0x0f;

// CALC OFFSET IN NIBBLES
offset=c*__ch_h+7;
// OFFSET IN NIBBLES
rot=offset&7;
// WORD WITH THE START OF CHAR
offset&=0xfffffff8;
// READ THE DATA CHARACTER
cdatalow=*(int *)(minif+(offset>>1));
cdatahigh=*(int *)(minif+4+(offset>>1));

// PUT DATA IN POSITION
while(rot<rotx)
{
cdatahigh= (cdatahigh<<4) | (cdatalow>>28);
cdatalow<<=4;

++rot;
}

while(rot>rotx) {
cdatalow= (cdatalow>>4) | (cdatahigh<<28);
cdatahigh>>=4;
--rot;
}

for(f=0;f<__ch_h;++f)
{
	*scrptr= ((*scrptr)&(mask^0xff))|(cdatalow&mask);
	scrptr+=20;
	cdatalow= (cdatalow>>4) | (cdatahigh<<28);
	cdatahigh>>=4;
}


}

void (*__putcon_hook)(int) = NULL;

void putcon(int c)
{
	if (__putcon_hook == NULL)
		__putcon_hook = putcon_stdscreen;
	
	(*__putcon_hook)(c);
	
}

void putc(int c)
{
	putcon(c);
	++__pos_x;
	if(__pos_x>=__scr_w) {
		__pos_x= 0;
		++__pos_y;
		if(__pos_y>=__scr_h) { scroll(); --__pos_y; }
	}
}


int putchar_console(int c)
{

if(c<5||c>=17) putc(c);

switch(c)
{
case 5:
	clreol(); // < ibl ; 2004-10-28 >
	return c;
case 7:
	beep();
	return c;
case 8:
	--__pos_x;
	if(__pos_x<0) { __pos_x=__scr_w; if(__pos_y>0) __pos_y--;  }
    putcon(c);
	return c;
case 9:
	while( __pos_x & (_TAB_SIZE-1)) putc(32);
	return c;
case 10:
	++__pos_y;
	if(__auto_cr) __pos_x= 0;
	if(__pos_y>=__scr_h) { scroll(); --__pos_y; }
	return c;
case 11:
	putc(c);
	return c;
case 12:
	_clear_screen();
	__pos_y=__pos_x=0;
	return c;
case 13:
	__pos_x=0;
	return c;
/*
case 14:
	// siso ???
	return c;
case 15:
	// ul -> underlined?
	return c;
case 16:
	// smooth ???
	return c;
*/

	
}

return c;	
}

int (*__putchar_hook)(int) = NULL;

int
putchar(int c)
{
	if (__putchar_hook == NULL)
		__putchar_hook = putchar_console;
	
	return (*__putchar_hook)(c);
}

