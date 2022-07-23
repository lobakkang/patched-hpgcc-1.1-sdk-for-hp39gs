//& <prolog>
//& ****************************************************************************
//&
//& Written by Ingo Blank & Claudio Lapilli October 2004
//& 
//& Copyright (C) 2004 HP-GCC Development Team
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

//& </prolog>


// $Header: /cvsroot/hpgcc/sources/hplib/saturn.h,v 1.15 2005/02/18 12:56:47 alborowski Exp $

#ifndef __SATURN_H
#define __SATURN_H


#ifdef HP49
#include "hp49.h"
#endif


// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif


/*!
 * \file saturn.h
 * 
 * \brief Saturn domain "hacking" and RPL stack manipulation library for the
 *        HP-49g+ calculator
 *
 * This library contains routines, that enable an applications programmer to access the RPL data
 * on the calculator's stack and performing generalized data exchange with the Saturn emulator.
 * The latter - "hacking" functions - consist mainly of a set of "peek" and "poke" functions for various
 * data entities like "nibbles","bytes","words" and "strings" and address translation functions ARM <-> Saturn.
 * There are just a few, easy to remember, high level API functions, which allow for complete control over
 * the stack. The programmer does not need to know about Saturn internals.
 *
 * \section overview Overview
 *
 * The features include:
 *
 * \li Stack access primitives (GET,DEPTH,DROP,PUSH)
 * \li Encoding/Decoding of string data 
 * \li Address translation Saturn -> ARM
 * \li Various peek and poke functions for different data entities 
 *
 *
 * \section qstart Quick Start Examples
 *
 * The following program pushes the string "Hello, World!" onto the RPL Stack
 * Note that before doing _any_ stack operations, you must call sat_stack_init()
 * Save the value it returns, then use it as a parameter to sat_stack_exit at the end.
 *
 * \code
 *
 * #include <hpgcc49.h> 
 *
 * int main()
 * {
 *	// Initialize RPL stack
 *	unsigned rpl_stack_bias = sat_stack_init();
 *
 *	sat_stack_push_string("Hello, World!");
 *	
 *	sat_stack_exit(rpl_stack_bias); //close it
 *	return 0;
 * }
 *
 * \endcode
 *
 * This program takes an integer (a'Zint' in HP terms) off the stack, doubles it, and pushes the result. 
 * This example has minimal error checking. Ideally you would use sat_stack_depth to detect if the stack
 * is empty first, and check the type before usage.
 * 
 * \code
 *
 * #include <hpgcc49.h> 
 *
 * int main()
 * {
 *	// Initialize RPL stack 
 *	unsigned rpl_stack_bias = sat_stack_init();
 *
 *	sat_push_zint_llong(sat_pop_zint_llong()*2);
 *	
 *	sat_stack_exit(rpl_stack_bias); //close it
 *	return 0;
 * }
 *
 * \endcode
 *
 *
 *
 * This program pops 2 ZINTs off the stack, adds them, and pushes the result. It is more complicated
 * because it does error checking. IT checks that at least 2 items are on the stack, and that they 
 * are both of type ZINT
 *
 * \code
 *
 * #include <hpgcc49.h> 
 *
 * int main()
 * {
 *	// Initialize stack access
 *	unsigned rpl_stack_bias = sat_stack_init();
 *
 *	if (sat_stack_depth()<2){ //check for enough items
 *	sat_stack_push_string("Error: Too Few Arguments!");
 *	goto exit;
 * } 
 *	
 *	SAT_STACK_ELEMENT first; //examine the elements on stack
 *	SAT_STACK_ELEMENT second; //we don't pop them yet.
 *	
 *	sat_get_stack_element(1,&first); //look at first element from stack
 *	sat_get_stack_element(2,&second);//look at second element from stack
 *	
 *	//Now, check that both 'first' and 'second' are ZINTs
 *	//One way to do this is by checking the 'prologue'. It identifies
 *	//the type of the object. Use 'SAT_DOINT' to check for ZINTs
 *	if( (first.prologue!=SAT_DOINT)||(second.prologue!=SAT_DOINT)){
 *	
 *	sat_stack_push_string("Error: Bad Argument Type!"); //bail out
 *	goto exit;	
 *	
 *	}
 *	
 *	//now, pop the actual values off the stack
 *	
 *	LONGLONG first_val = sat_pop_zint_llong(); //first element value
 *	LONGLONG second_val = sat_pop_zint_llong(); //second element value
 *	
 *	sat_push_zint_llong(first_val+second_val); //push the addition
 *
 * exit:
 *	sat_stack_exit(rpl_stack_bias);
 *	return 0;
 * }
 *
 * \endcode
 *
 * The following program expects two exact integer values, converted to strings, on
 * the stack.  It performs some operations with them and pushes a result back.
 * As a string as well. It treats the stack as parameters to a classic C program 
 * using 'argc' and 'argv' values. 
 *
 *
 *
 * \note \b In this example, all data exchange is done with strings. This seems to be a
 *       limitiation. Actually it can be very useful. Remember that there are the \b STR-> and
 *       \b ->STR functions at the emulator's end, which are rather powerful.
 *	 It is easy to pass complicated objects by converting them to strings.
 *       In C we have conversion routines for the basic C data types "int"
 *       [atoi()] and "double" [atof()]. Output conversion, for pushing
 *       results, may be done with  "sprintf".
 *
 * \code
 *
 * #include <hpgcc49.h>
 *
 * // Template for RPL stack pop/push usage
 * // Ingo Blank, 2004-11-24
 *
 *
 * int
 * main()
 * {
 *     // argument counter
 *     int argc = 0;
 *
 *     // Initialize stack access
 *     unsigned rpl_stack_bias = sat_stack_init();
 *
 *     // Determine number of elements in the stack
 *     int level = sat_stack_depth();
 *
 *     // Dynamically dimension argument vector just as big as needed
 *     char *argv[level];
 *
 *     while (sat_stack_depth()) {
 *
 *         SAT_STACK_ELEMENT e;
 *         SAT_STACK_DATA d;
 *
 *         // Get element at level #1, i.e. stack-top
 *         sat_get_stack_element(1,&e);
 *
 *         // decode it ...
 *         sat_decode_stack_element(&d,&e);
 *
 *         // check validity and store in argument vector
 *
 *         // Note that elements are stored in *reverse* order, since
 *         // the stack is a LIFO structure
 *         if (d.type == SAT_DATA_TYPE_STRING)
 *     		// remove single quotes from algebraic objects (if present)
 *     		argv[++argc,--level] = str_unquote(d.sval,'\'');
 *         else
 *     		; // unsupported data type, error message, bail out, ignore ...
 *
 *         // pop one element off the stack and continue loop
 *         sat_stack_drop();
 *     }
 *
 *     // Now all RPL data is stored in the argv[] vector
 *
 *     // your program here ...
 *
 *
 *     // Since the program does no screen output, skip init sequence
 *
 *     //sys_intOff();
 *     //sys_slowOn(); 
 *     //clear_screen();
 *
 *     // Demo: take two arguments, convert them to integers and apply the 4
 *     // basic arithmetic operations to them
 *
 *     if (argc >= 2) {
 *         int x = atoi(argv[0]);
 *         int y = atoi(argv[1]);
 *         char buf[64];
 *
 *         // print the result formatted as an HP list object {,,,}
 *         sprintf(buf,"{%d %d %d %d}",x+y,x-y,x*y,y ? x/y : 0);
 *
 *         // push the string back to the stack
 *         // the receiving (User)RPL pogram can convert it with STR-> to a
 *         // proper list object
 *         sat_stack_push_string(buf);
 *     }
 *
 *     // Finalize stack access
 *     // NEVER forget that, or risk a device crash!
 *     sat_stack_exit(rpl_stack_bias);
 *
 *     // Since the program does no screen output, skip exit sequence
 *
 *     //sys_slowOff();
 *     //sys_intOn();
 *
 *     return 0;
 * }
 *
 * \endcode
 */

/*!
 * \brief Swap low and high nibbles in a byte
 */
 
#define SWAP4(x) (((x) << 4) | ((x) >> 4))

/*!
 * \brief Align an address \a 'x' to a \a 'a' bit boundary
 */
 
#define ALIGN(x,a) (((unsigned)(x)+(a)-1) & (~((unsigned)(a)-1)))

/*!
 * \brief Standard definition for BOOLEAN type 
 */
 
#ifndef BOOL
#define BOOL int
#endif

/*!
 * \brief The BOOLEAN constant \c FALSE
 */

#ifndef FALSE
#define FALSE 0
#endif

/*!
 * \brief The BOOLEAN constant \c TRUE
 */

#ifndef TRUE
#define TRUE !FALSE
#endif

/*!
 * \brief The emulated Saturn CPU as a memory area in ARM domain
 
 \code
 
typedef

struct _sat_cpu {
	
	unsigned int 	Read[257];
	unsigned int 	Write[257];
	unsigned char 	unknown_data[260];
	unsigned int	A;
	unsigned int	Ah;
	unsigned int	B;
	unsigned int	Bh;
	unsigned int	C;
	unsigned int	Ch;
	unsigned int	D;
	unsigned int	Dh;
	
	unsigned int	R0;
	unsigned int	R0h;
	unsigned int	R1;
	unsigned int	R1h;
	unsigned int	R2;
	unsigned int	R2h;
	unsigned int	R3;
	unsigned int	R3h;
	unsigned int	R4;
	unsigned int	R4h;
	
	unsigned int	D0;
	unsigned int	D1;
	unsigned int	P;
	unsigned int	ST;
	unsigned int	HST;
	unsigned int	CARRY;
	unsigned int	DECIMAL_MODE;
	
} SAT_CPU, *SAT_PCPU;

\endcode

 */
 
typedef

struct _sat_cpu {
	
	unsigned int 	Read[257];
	unsigned int 	Write[257];
	unsigned char 	unknown_data[260];
	unsigned int	A;
	unsigned int	Ah;
	unsigned int	B;
	unsigned int	Bh;
	unsigned int	C;
	unsigned int	Ch;
	unsigned int	D;
	unsigned int	Dh;
	
	unsigned int	R0;
	unsigned int	R0h;
	unsigned int	R1;
	unsigned int	R1h;
	unsigned int	R2;
	unsigned int	R2h;
	unsigned int	R3;
	unsigned int	R3h;
	unsigned int	R4;
	unsigned int	R4h;
	
	unsigned int	D0;
	unsigned int	D1;
	unsigned int	P;
	unsigned int	ST;
	unsigned int	HST;
	unsigned int	CARRY;
	unsigned int	DECIMAL_MODE;
	
} SAT_CPU, *SAT_PCPU;


/*!
 * \brief An RPL List Object. 
 */

typedef struct { //an RPL List Object - Al, Feb '05
           unsigned int size;
           unsigned char * data;
        } *SAT_LIST;

extern SAT_CPU *_saturn_cpu;

// SATURN Stack

/*!
 * \brief How many stack levels are used by the launcher
 */

#define SAT_STACK_BIAS 1 


/*!
 * \brief A descriptor for an RPL stack element in Saturn notation

\code
typedef struct _sat_stack_element
{
	unsigned	addr;
	unsigned	prologue;
	
} SAT_STACK_ELEMENT, *SAT_PSTACK_ELEMENT;
\endcode

 */

typedef struct _sat_stack_element
{
	unsigned	addr;
	unsigned	prologue;
	
} SAT_STACK_ELEMENT, *SAT_PSTACK_ELEMENT;


// ALL PROLOGUE CONSTANTS RENAMED BY CLAUDIO
// TO MATCH THE SYSRPL NAMES 01/08/05

/*!
 * \brief Saturn data prologue: ZINT (Typical Exact Integer)
 */
#define SAT_DOINT 0x2614
/*!
 * \brief Saturn data prologue: STRING
 */
#define SAT_DOCSTR		0x2a2c
/*!
 * \brief Saturn data prologue: REAL
 */
#define SAT_DOREAL		0x2933
/*!
 * \brief Saturn data prologue: UINT (HEX STRING)
 */
#define SAT_DOHXS		0x2a4e
/*!
 * \brief Saturn data prologue: BINT
 */
#define SAT_DOBINT		0x2911
/*!
 * \brief Saturn data prologue: COMPLEX
 */
#define SAT_DOCMP		0x2977
/*!
 * \brief Saturn data prologue: CHAR
 */
#define SAT_DOCHAR		0x29BF
/*!
 * \brief Saturn data prologue: ARRAY
 */
#define SAT_DOARRY		0x29e8
/*!
 * \brief Saturn data prologue: ID (variable name)
 */
#define SAT_DOIDNT		0x2e48
/*!
 * \brief Saturn data prologue: XLIB (ROM Pointer)
 */
#define SAT_DOROMP		0x2e92
/*!
 * \brief Saturn data prologue: RRP (Directory objects)
 */
#define SAT_DORRP		0x2a96
/*!
 * \brief Saturn data prologue: SYMBOLIC
 */
#define SAT_DOSYMB		0x2AB8
/*!
 * \brief Saturn data prologue: LIST
 */
#define SAT_DOLIST		0x2A74
/*!
 * \brief Saturn data prologue: SECONDARY (Programs)
 */
#define SAT_DOCOL		0x2D9D
/*!
 * \brief Saturn data prologue: GROB
 */
#define SAT_DOGROB		0x2D9D
/*!
 * \brief Saturn composite object terminator: SEMI
 */
#define SAT_SEMI		0x312b

// OBSOLETE CONSTANTS: KEPT FOR COMPATIBILITY ONLY
// CHANGED BY CLAUDIO 01/08/05
#define SAT_PROLOGUE_STRING SAT_DOCSTR
#define SAT_PROLOGUE_UINT SAT_DOHXS

/*!
 * \brief HP calculator Data Type: INT
 */

#define SAT_DATA_TYPE_INT		28

/*!
 * \brief HP calculator Data Type: LONG
 */
 
#define SAT_DATA_TYPE_LONG		10

/*!
 * \brief HP calculator Data Type: STRING
 */
 
#define SAT_DATA_TYPE_STRING		2

/*!
 * \brief HP calculator Data Type: REAL
 */
 
#define SAT_DATA_TYPE_REAL		0

/*!
 * \brief Marker for unsupported Data Type
 */
 

#define SAT_DATA_TYPE_UNSUPPORTED -999

/*!
 * \brief Data structure, that models a single stack element

\code
typedef struct _sat_stack_data
{
	int	type;
	union {
		int		ival;
		double		dval;
		LONGLONG	lval;
		char		*sval;
	};
} SAT_STACK_DATA, *SAT_PSTACK_DATA;
 \endcode
 
 */

typedef struct _sat_stack_data
{
	int	type;
	union {
		int		ival;
		double		dval;
		LONGLONG	lval;
		char		*sval;
	};
} SAT_STACK_DATA, *SAT_PSTACK_DATA;


// general SAT hacking functions

/*!
 * \brief Poke up to 8 nibbles of data to Saturn domain
 *
 * This function stores up to 32 bit data in 4 bit chunks (nibbles) to Saturn memory.
 * \param sat_addr The address in Saturn domain
 * \param val The datum itself
 * \param nibbles Number of nibbles to poke
 */

void sat_poke(int sat_addr,unsigned val,int nibbles);

/*!
 * \brief Poke many nibbles to Saturn domain
 *
 * This function stores 2*strlen(data) nibbles to Saturn memory.
 * It calls sat_poke() as it's "work-horse".

 * \param sat_addr The address in Saturn domain
 * \param data The data string
 * \param nibbles Number of nibbles to poke
 */

void sat_poke_nibbles(unsigned sat_addr, const char *data, int nibbles);

/*!
 * \brief Peek up to 8 nibbles of data from Saturn domain
 *
 * This function reads up to 32 bit data in 4 bit chunks (nibbles) from Saturn memory.
 * \param sat_addr The address in Saturn domain
 * \param nibbles Number of nibbles to poke
 * \return The datum itself
 */
 
unsigned sat_peek(int sat_addr,int nibbles);

/*!
 * \brief C implementation of Saturn MOVEUP
 *
 * This function moves a number of nibbles in Saturn domain
 *
 * \param satsrc The source address in Saturn domain
 * \param satdest The destination address in Saturn domain
 * \param nibbles Number of nibbles to move
 */
 
void sat_moveup(int satsrc,int satdest,int nibbles);

/*!
 * \brief Create a temporary object in the Saturn Heap
 *
 * C implementation of the HP49's ROM library routine
 *
 * \param objsize Size of object in nibbles
 * \return Pointer to prologue of newly created object or \c NULL on error
 */
 

int sat_createtemp(int objsize);

/*!
 * \brief Push a string on the RPL stack
 *
 * This function works with ZINT,HXS,CSTR,LIBDATA and CODE data types
 *
 * \param type_prolog The data type's prologue
 * \param size_nibbles Number of nibbles to push
 * \param data Pointer to data string
 * \return \c TRUE on success
 */
 

BOOL sat_push_string(int type_prolog,int size_nibbles,const char *data);

/*!
 * \brief Translate a Saturn memory address to ARM domain
 *
 * \param sat_addr Memory address in Saturn domain
 * \return Address in ARM domain
 */
 

unsigned int sat_map_s2a(unsigned int sat_addr);


/*!
 * \brief Convenience macro for peeking Saturn addresses (5 nibbles)
 */
 
#define sat_peek_sat_addr(sat_addr) sat_peek((sat_addr),5)

/*!
 * \brief Convenience macro for peeking one byte (2 nibbles)
 */
 
#define sat_peek_sat_byte(sat_addr) ((unsigned char) sat_peek((sat_addr),2))

/*!
 * \brief Peek many nibbles from Saturn domain into ARM memory
 *
 * This function copies 2*strlen(data) nibbles from Saturn to ARM memory.
 
 * \param target Pointer to (allocated) memory in ARM domain
 * \param sat_addr Source address in Saturn domain
 * \param nbytes Number of bytes to copy
 */


void *sat_peek_sat_bytes(void *target, unsigned sat_addr, int nbytes);


/*!
 * \brief Combines 2 strings of binary Saturn data
 *
 * This helper function acts like a strcat, but for binary Saturn data.
 * Note: This function still needs more testing.

 * \param dest Pointer to destination space
 * \param destLen size of 'dest' in nibbles
 * \param source Pointer to source data
 * \param destLen size of 'source' in nibbles
 */


unsigned char * sat_concatnib (unsigned char * dest, unsigned int destLen,  unsigned char* source, unsigned int sourceLen);



/*!
 * \brief Convenience macro for poking a single byte (2 nibbles) to Saturn memory
 */

#define sat_poke_sat_byte(sat_addr,val) sat_poke((sat_addr), (unsigned) (val), 2)

/*!
 * \brief Convenience macro for poking many bytes (2*n nibbles) to Saturn memory
 */
 
#define sat_poke_sat_bytes(sat_addr, bytes, n) sat_poke_nibbles((sat_addr), (bytes), (2*(n)))

/*!
 * \brief Convenience macro for poking a Saturn address (5 nibbles) to Saturn memory
 */
 
#define sat_poke_sat_addr(sat_addr,val) sat_poke((sat_addr), (val), 5)

// Saturn register save area

/*!
 * \brief Saturn CPU storage area: D0
 */
 
#define SAT_INTRPPTR 0x8076B 	/* D0 */

/*!
 * \brief Saturn CPU storage area: D1
 */
 
#define SAT_DSKTOP   0x806F8	/* D1 */

/*!
 * \brief Saturn CPU storage area: B
 */
 
#define SAT_RSKTOP   0x806F3	/* B */

/*!
 * \brief Saturn CPU storage area: D
 */
 
#define SAT_AVMEM    0x80E9B	/* D */

/*!
 * \brief Saturn emu storage area: TEMPTOP
 */
 
#define SAT_TEMPTOP  0x806EE

							  
// RPL stack 

/*!
 * The High Level RPL Stack API
 */

/*!
 * \brief Initialize RPL stack access
 * This function MUST be called \b before any other high level stack API function.
 * The returned value is \b NOT intended for any usage other then storing it!
 *
 * \return a transparent pointer to a stack bias element in Saturn memory
 */
 
unsigned sat_stack_init();

/*!
 * \brief Finalize RPL stack access
 * This function MUST be called \b before exiting the program
 * Failing this may cause a calculator crash!
*/

void sat_stack_exit(unsigned rpl_stack_bias);

/*!
 * \brief Get number of elements on the RPL stack (DEPTH)
 * \return Number of elements on stack or zero if empty
 */
 
int sat_stack_depth();

/*!
 * \brief Get a stack element (GET)
 * \param index Stack Index [1..DEPTH]
 * \param element Pointer to a SAT_STACK_ELEMENT structure
 * \return zero on success or -1 on error
 */
 
int sat_get_stack_element(int index, SAT_STACK_ELEMENT *element);

/*!
 * \brief Pop one element off the stack (DROP)
 * \return Number of dropped elements (1 on success)
 */
 
int sat_stack_drop();

/*!
 * \brief Pop many elements off the stack (DROPN)
 * \return Number of dropped elements 
 */
 
int sat_stack_dropn(int n);

/*!
 * \brief Swap elements on level 1 and 2 (SWAP)
 * \return Number of swaps (1 on success)
 */
 

int sat_stack_swap();

/*!
 * \brief Swap then drop (NIP)
 * \return Number of dropped elements (1 on success)
 */
 
 
int sat_stack_nip();

// push primitives

/*!
 * \brief Push a string onto the RPL stack
 * \param str Pointer to (zero delimited) string
 * \return Number of bytes pushed ( 0 on error )
 */
 
int sat_stack_push_string(const char *str);

/*!
 * \brief Push a string representation of an integer onto the stack
 * The integer is converted to a string and then pushed via sat_stack_push_string()
 * \param z an Integer
 * \param radix The base
 * \param binary 1=use "#zzz[o|d|h]" representation
 * \return Number of bytes pushed ( 0 on error )
 */

int _sat_stack_push_int(int z, int radix, int binary);

/*!
 * \brief Push a string representation (base=10) of an integer onto the stack
 * The integer is converted to a string and then pushed via sat_stack_push_string()
 * \param z an Integer
 * \return Number of bytes pushed ( 0 on error )
 */

int sat_stack_push_int(int z);

/*!
 * \brief Push a string representation of a double onto the stack
 * The double value is converted to a string and then pushed via sat_stack_push_string()
 * \param d a double
 * \return Number of bytes pushed ( 0 on error )
 */

int sat_stack_push_double(double d);

/*!
 * \brief Push a LONGLONG onto the RPL stack as a ZINT
 * Accepts a number of Type 'LONGLONG', and pushes it as an Exact Integer (ZINT)
 * \param num the number to push as a ZINT (LONGLONG).
 * \return TRUE if sucessful.
 */


BOOL sat_push_zint_llong(LONGLONG num);

/*!
* \brief Helper function for pushing ZINTs onto the Stack
* Accepts an array of binary digits, and pushes then onto the stack
* egc {1,2,3,4,5,6,7,8,9} for 123456789.
* It also accepts a negative flag (if TRUE, number is treated as negative)
* and number of digits.
*
* \param digits Number of digits in \a source
* \param negative Set to \c TRUE for negative numbers
* \param source the number as an array. Include binary values 0-9 ONLY.  
* \return TRUE if sucessful.
*/


BOOL sat_push_zint_array (unsigned int digits, unsigned int negative, unsigned char * source);


/*!
 * \brief Pop a ZINT off the RPL stack into a LONGLONG 
 * Pop a ZINT (exact integer) off the RPL stack into a LONGLONG (64 bit signed integer)
 * \return the value off the stack, or 0 if error.
 */

LONGLONG sat_pop_zint_llong();

/*!
 * \brief Creates an RPL List Object
 * Creates a List object of type SAT_LIST, used for holding multiple Saturn objects
 * \param maxSize the size allocates for the List object, in Bytes 
 * \return an RPL List Object, of type 'SAT_LIST'. 0 If not enough RAM.
 */

SAT_LIST sat_list_create(unsigned int maxSize);


/*!
 * \brief destroys an RPL List Object
 * Frees the memory takes by a SAT_LIST
 * \param list the list to free
 */

void sat_list_destroy(SAT_LIST list);

/*!
 * \brief Pushes an RPL List Object (of type SAT_LIST) onto the RPL Stack 
 * \param list the List object to push.
 * \return Returns TRUE if sucessful
 */

BOOL sat_push_list(SAT_LIST list);


/*!
 * \brief adds a Double to an RPL List as a Real 
 * \param list the List object
 * \param num a number to add as a Real
 */

void sat_list_add_real(SAT_LIST list, double num);

/*!
* \brief Helper function for adding ZINTs to an RP List
* Accepts an array of binary digits, and adds to a List
* eg {1,2,3,4,5,6,7,8,9} for 123456789.
* It also accepts a negative flag (if TRUE, number is treated as negative)
* and number of digits.
*
* \param list the RPL List
* \param digits Number of digits in \a source
* \param negative Set to \c TRUE for negative numbers
* \param source the number as an array. Include binary values 0-9 ONLY.  
*/

void sat_list_add_zint_array(SAT_LIST list, unsigned int digits, unsigned int negative, unsigned char * source );

/*!
* \brief Helper function for converting an array of digits to a Zint.
* Accepts an array of binary digits, and creates a binary Zint object
* eg {1,2,3,4,5,6,7,8,9} for 123456789.
* It also accepts a negative flag (if TRUE, number is treated as negative)
* and number of digits.
*
* \param digits Number of digits in \a source
* \param negative Set to \c TRUE for negative numbers
* \param source the number as an array. Include binary values 0-9 ONLY.  
* \param dest storage space for the encoded ZINT. 
*/

char * sat_convert_zint_array (unsigned int digits, unsigned int negative, unsigned char * source, unsigned char * dest);


/*!
 * \brief adds a LONGLONG to an RPL List as a ZINT
 * \param list the List object
 * \param num a 64 bit number to add as a ZINT
 */


void sat_list_add_zint(SAT_LIST list, LONGLONG num);


/*!
 * \brief Helper function that dakes in a double, and returns a binary Real Object
 * \param number the Number to transform into a Real
 * \param realStr some storage space to put the binary representation (use at least 14 bytes)
 * \return pointer to the result (same as realStr)
 */

unsigned char *  sat_convert_double_real(double number, unsigned char * realStr);


/*!
 * \brief Inquiry function that tells how many stack levels are available for pushing
 * \return Number of available levels (0 = stack is full)
 */


int sat_stack_levels_avail();

// Saturn data codec

/*!
 * \brief Decode a Saturn string object
 * \param sat_addr address of object in Saturn doamin
 * \return Pointer to decoded string
 * \note Internal primitive, don't use in applications
 */


char *_sat_decode_string(unsigned sat_addr);

/*!
 * \brief Decode a stack element to a SAT_STACK_DATA type
 * \param data Pointer to decoded structure
 * \param stack Pointer to a raw stack element
 * \return 0 = success, -1 = error

 */

int sat_decode_stack_element(SAT_STACK_DATA *data, SAT_STACK_ELEMENT *stack);


/*!
 * \brief Pop a Real from the Stack, as a Double. 
 * The Real object is popped from the RPL stack, and transformed into a double
 * \return The Real, as a double. If there was an error returns 0.0
 */

double sat_pop_real();


// LOW-LEVEL ROUTINES FOR DIRECT OBJECT ACCESS

/*!
 * \brief Push a pointer in the stack
 *
 * Pushes a data pointer to the stack and adjusts the available memory.
 *
 * \param sataddr Saturn address of the object
 */

void sat_pushptr(int sataddr);




/*!
 * \brief Push a string on the RPL stack
 *
 * This function works with ZINT,HXS,CSTR,LIBDATA and CODE data types
 *
 * \param type_prolog The data type's prologue
 * \param size_nibbles Number of nibbles to push
 * \param data Pointer to data string
 * \return \c TRUE on success
 */
 

BOOL sat_push_string(int type_prolog,int size_nibbles,const char *data);

/*!
 * \brief Push a bint on the RPL stack
 *
 * Pushes a sysRPL BINT object on the stack
 *
 * \param bint 20-bit unsigned number
 * \return \c TRUE on success
 */

BOOL sat_push_bint(int bint);

/*!
 * \brief Push a real on the RPL stack
 *
 * Pushes a double, as a 'real' number on the RPL stack
 *
 * \param number A 'Double' floating point number.
 * \return \c TRUE on success
 */

BOOL sat_push_real(double number);

/*!
 * \brief Push a char on the RPL stack
 *
 * Pushes a character on the stack
 *
 * \param byte 8-bit character
 * \return \c TRUE on success
 */

BOOL
sat_push_char(char byte);

/*!
 * \brief Push a complex number on the RPL stack
 *
 * Pushes a complex number on the stack
 *
 * \param real 64-bit BCD calculator real number
 * \param imag 64-bit BCD calculator real number
 * \return \c TRUE on success
 */

BOOL
sat_push_comp(ULONGLONG real,ULONGLONG imag);


/*!
 * \brief Push a real array on the RPL stack
 *
 * Pushes an array of real numbers on the stack
 *
 * \param rows Number of rows in the matrix
 * \param columns Number of columns in the matrix
 * \param arry Pointer to an array of (rows*columns) 64-bit BCD calculator real numbers
 * \return \c TRUE on success
 */

BOOL
sat_push_realarray(int rows,int columns,ULONGLONG *arry);

#endif // __SATURN_H
