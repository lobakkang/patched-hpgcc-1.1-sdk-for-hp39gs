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

#include <hpsys.h>


#define LCD_TARGET_FREQ 500000


void sys_lcdfix()
{
volatile unsigned int *CLKPTR=(unsigned int *)CLK_REGS;
volatile unsigned int *LCDPTR=(unsigned int *)LCD_REGS;
int mpllcon=CLKPTR[1],clkslow=CLKPTR[4],clkdivn=CLKPTR[5];
// INITIAL CLOCK FREQUENCY
int freq=12000000,clkval;

// CALCULATE ACTUAL WORKING CALCULATOR FREQUENCY
if(clkslow&0x10)
{
int slow_val=clkslow&7;
if(slow_val) freq/=slow_val<<1;
}
else {
int mdiv=(mpllcon>>12)&0xff,pdiv=(mpllcon>>4)&0x3f,sdiv=mpllcon&0x3;
freq*=mdiv+8;
freq/=pdiv+2;
freq>>=sdiv;
}
// HERE FREQ=CPU CLOCK FREQUENCY FCLK

if(clkdivn&2) freq/=2;

// HERE FREQ=HCLK 

clkval=freq/LCD_TARGET_FREQ;
clkval+=1;
clkval>>=1; // ROUND TOWARDS SLOWER SPEED


int linecnt,lineblank;

// SET A REASONABLE LINEBLANK FOR SLOW HCLK
if(freq<=12000000) lineblank=3; else lineblank=8;

// LCD OFF
LCDPTR[0]&=0xFFFFFFFE;
linecnt=LCDPTR[0]&0xff;
linecnt|=clkval<<8;

// FIX LINEBLANK AND FORCE WDLY=0;
LCDPTR[2]&=0x7ff00;
LCDPTR[2]|=lineblank;

// FORCE WLH=0;
LCDPTR[3]&=0xFFFFFF00;

// FIX CLKVAL AND TURN ON
LCDPTR[0]=linecnt|1;


}
