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



/*!	\file hpsys.h
	\brief Header file for system functions
*/

#ifndef _HPSYS_H
#define _HPSYS_H

// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif


#include <kos.h>

#ifndef EXTERN
#define EXTERN extern
#endif

#ifndef NULL
#define NULL 0
#endif


// atexit machinery added by ibl 2005-01-31

typedef void (*ATEXITFUNC)();

typedef struct _atexit_entry {
	ATEXITFUNC f;
	struct _atexit_entry *next;
} ATEXIT_ENTRY;

int atexit(ATEXITFUNC f);

//! Convert a BCD format number to an hexa value
char  *sys_bcd2str(unsigned int BCD);

//! Convert a BCD format BYTE (least significant 2 digits) to an integer value
#define sys_bcd2bin(BCD) sys_bcd2bin_nibbles(BCD,2)
//! Convert the least significant n (=nibbles, max. 8) digits of a BCD formatted number to it's integer value 
unsigned int sys_bcd2bin_nibbles(unsigned int  BCD,int nibbles);





// arithmetics

 typedef struct
 {
 LONGLONG quot;
 LONGLONG rem;
 } lldiv_t;

 lldiv_t lldiv(LONGLONG,LONGLONG);

/*!	\fn	unsigned divlu2(unsigned num_h,unsigned num_l,unsigned den,unsigned *rem)
	\brief	Unsigned 64/32 bit division
*/

/*!	\fn	ULONGLONG udiv64(ULONGLONG nom, unsigned den, unsigned *rem)
	\brief	Unsigned 64/32 bit division with 64 bit quotient.
*/

/*!	\fn	LONGLONG sdiv64(LONGLONG nom, int den, int *rem)
	\brief	Signed 64/32 bit division with 64 bit quotient.
*/



unsigned divlu2(unsigned num_h,unsigned num_l,unsigned den,unsigned *rem);

ULONGLONG
udiv64(ULONGLONG nom, unsigned den, unsigned *rem);

LONGLONG
sdiv64(LONGLONG nom, int den, int *rem);


// loader globals

//! Value of r1 register at the begining of execution
/**
 * See post of Robert Hildinger:
 * "The R1 register contains the base address for all the ARM
 * globals, which can be used to access all of the Saturn registers.
 * Altering this register will not affect the calling code. The LR
 * register contains the return address to get back into Saturn
 * emulation."
 *
 * API INFORMATION\n
 * ---------------
 *
 * So far there is no real API information available, although
 * experimentally I've been able to determine the following offsets from
 * the global base register for accessing the emulated Saturn CPU
 * registers:\n
 * 
 * Base (R1) offset      Description\n
 * ---------------------------------------
 *
 * 0x90C                 Saturn register A (low order 8 nibbles)\n
 * 0x910                 Saturn register A (high order 8 nibbles)\n 
 * 0x914                 Saturn register B (low order 8 nibbles)\n 
 * 0x918                 Saturn register B (high order 8 nibbles)\n 
 * 0x91C                 Saturn register C (low order 8 nibbles)\n 
 * 0x920                 Saturn register C (high order 8 nibbles)\n 
 * 0x924                 Saturn register D (low order 8 nibbles)\n 
 * 0x928                 Saturn register D (high order 8 nibbles)\n 
 * \n
 * 0x92C                 Saturn register R0 (low order 8 nibbles)\n 
 * 0x930                 Saturn register R0 (high order 8 nibbles)\n 
 * 0x934                 Saturn register R1 (low order 8 nibbles)\n 
 * 0x938                 Saturn register R1 (high order 8 nibbles)\n 
 * 0x93C                 Saturn register R2 (low order 8 nibbles)\n 
 * 0x940                 Saturn register R2 (high order 8 nibbles)\n 
 * 0x944                 Saturn register R3 (low order 8 nibbles)\n 
 * 0x948                 Saturn register R3 (high order 8 nibbles)\n 
 * 0x94C                 Saturn register R4 (low order 8 nibbles)\n 
 * 0x950                 Saturn register R4 (high order 8 nibbles)\n 
 * \n
 * 0x954                 Saturn register d0\n
 * 0x958                 Saturn register d1\n
 * 0x95C                 Saturn register P\n
 * 0x968                 Saturn register ST\n
 * 0x96C                 Saturn register HST\n
 * 0x970                 Saturn CARRY flag\n
 * 0x974                 Saturn DECIMAL_MODE flag\n
 * 
 *
 */
 
// Now defined in "saturn.h"
// <ibl ; 2004-11-24>
// EXTERN unsigned int _saturn_cpu; 

EXTERN unsigned int _ram_base_addr;
EXTERN unsigned int _mmu_table_addr;
EXTERN unsigned int ram_size;
EXTERN unsigned int _heap_base_addr;
EXTERN unsigned int _code_base_addr;

// HARDWARE CONSTANTS

#define LCD_REGS	0x07300000
#define CLK_REGS	0x07200000

//ARM interrupts
void sys_intOff(); 
void sys_intOn();

// power management routines
void sys_slowOn(); 
void sys_slowOff();
// CPU CLOCK SAVE/RESTORE
//! Save CPU clock state to a buffer (6-words)
void sys_clksave(int *buf);
//! Restore CPU clock from a buffer (6-words)
void sys_clkrestore(int *buf);




// time related routines

typedef struct
{
    ULONGLONG current;
    unsigned last_val : 16;
    unsigned timer : 3;
    unsigned inited : 1;
} sys_timer_t;

#define SYS_TIMER_INITIALIZER { 0, 0, 0, 0 }
#define SYS_TIMER_INITIALIZER_NUM(n) { 0, 0, n, 0 }

ULONGLONG sys_updateTimer(sys_timer_t *timer);

void sys_sleep(unsigned int millis);

//! numers of ticks at 750kHz to wait for
void sys_waitTicks(unsigned int time); 
void sys_setupTimers();
void sys_restoreTimers();


//! Get PWM counter 0
/**	
 *	\return	The current value
 *
 *	The counter goes from 0 to 65536.
 */
unsigned short int sys_getPWMCounter0();


//! Get date in seconds from RTC
/**	
 *	\return	The current time in seconds
 *
 *	The total number of seconds 3600*H+60*M+S.
 */
int sys_RTC_seconds();



// VIDEO MODE CONSTANTS
#define MODE_MONO 0
#define MODE_4GRAY 1
#define MODE_16GRAY 2

//! Wait for LCD synchro
void sys_LCDSynch();
//! Fix LCD clock rate at any CPU speed
void sys_lcdfix();
//! Save LCD controller state (buffer size must be 17 words min.)
void sys_lcdsave(int *buffer);
//! Restore LCD controller state from buffer (saved by sys_lcdsave)
void sys_lcdrestore(int *buffer);
/*!	\fn	int sys_lcdsetmode(int mode,int *physicalbuffer)
	\brief	Sets the corresponding video mode. Returns scanline width in bytes.
	\param	mode = MODE_MONO (=0), MODE_4GRAY (=1) or MODE_16GRAY (=2)
	\param	physicalbuffer = Video frame memory, pointing to physical address
*/
int sys_lcdsetmode(int mode,int *physicalbuffer);
// ! Returns the screen height in pixels
int sys_lcdgetheight();




// mmu mapping functions
//! Convert a virtual address to its physical bus address
EXTERN int sys_map_v2p(unsigned int vaddr);
//! Convert a physical bus address to its virtual address 
EXTERN int sys_map_p2v(unsigned int paddr);
//! Classify a memory address 0=System; 1=Port1; 2=Main 
int sys_mem_classify(int addr);
//! Flush write-back caches on the specified block of memory
void sys_flush_cache(int *ptr,int size);

// mmu independent physical malloc

void *sys_phys_malloc(size_t);


// particular functions

/*!	\fn	void playTone(unsigned freq, unsigned duration)
	\brief	Toggle the speaker according to the input parameters.
	\param	freq frequency
	\param	duration duration
	\warning Not yet fully implemented, parameter interpretation may be wrong
*/
EXTERN void sys_playTone(unsigned int tone, unsigned int duration);
EXTERN void sys_waitTicks (unsigned int time);
EXTERN void setDisplayPlane(unsigned char * plane);

EXTERN void sys_playTone2(unsigned int time, unsigned int duration);

//! Returns '1' if an RTC Interrupt Tick has occured since it was last called
int sys_isRTCTick();
//! Ajdusts the rate of the RTC Tick. Remember to restore the default when done!
unsigned char sys_setRTCTickPeriod(unsigned char n);
//! Waits for 'count' RTC Ticks to elapse.
void sys_waitRTCTicks(int count);


// < ibl >

/*!
	\fn int sys_delta_seconds(int t_start, int t_end)
	\brief Compute the time span (in seconds) between t_start and t_end. 
	Account for possible wrap around at midnight.
	\param t_start Start time
	\param t_end End time
*/

	
int sys_delta_seconds(int t_start, int t_end);

// < ibl ; 2005-02-08 >

/*!
	\fn void sys_error(const char *msg, int code)
	\brief Output msg to screen, set errno=code and exit if code < 0
	\param msg The message text or \c NULL for none
	\param code The error code, forwarded to exit()
	
*/

void sys_error(const char *msg, int code);


#endif 

