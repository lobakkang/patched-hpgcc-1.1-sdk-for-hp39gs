//& ****************************************************************************
//&
//& Written by Benjamin Maurin, September 2004
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

#ifndef _HPKEYB49_H
#define _HPKEYB49_H

// LONG TYPE DEFINITION, ADDED BY CLAUDIO 01/14/05
#ifndef _LONGLONG_DEF
typedef unsigned long long ULONGLONG;
typedef long long LONGLONG;
#define _LONGLONG_DEF
#endif

/*!
 * \file hpkeyb49.h
 * \brief Keyboard management routines for the HP49.
 *
 * Interaction with the calculator keyboard can be done at a high level, or a
 * low level.  Functions defined in this file are used to interact at a low
 * level with the calculator keyboard.  For higher-level user input routines,
 * see ::getchar, ::gets, ::getkey, ::readint, ::readuint, ::readhex,
 * ::readlonglong, ::readulonglong, and ::readdouble.
 *
 * At the moment, keys are identified in various hodge-podge manners by the
 * various functions defined in this file.  Here is a compilation of them
 * all. Logical rows and columns are for the HP49G+; these values probably
 * apply to the HP48gII as well, but this fact has not been verified.  The
 * HP39G+ has a somewhat different keyboard layout, which is not yet
 * documented.
 *
 * - \b F1 (A):      row=0, col=5, id=75,  matrixid=KB_A
 * - \b F2 (B):      row=1, col=5, id=76,  matrixid=KB_B
 * - \b F3 (C):      row=2, col=5, id=77,  matrixid=KB_C
 * - \b F4 (D):      row=3, col=5, id=78,  matrixid=KB_D
 * - \b F5 (E):      row=4, col=5, id=79,  matrixid=KB_E
 * - \b F6 (F):      row=5, col=5, id=80,  matrixid=KB_F
 * - \b APPS (G):    row=6, col=5, id=81,  matrixid=KB_G
 * - \b MODE (H):    row=4, col=6, id=94,  matrixid=KB_H
 * - \b TOOL (I):    row=5, col=6, id=95,  matrixid=KB_I
 * - \b VAR (J):     row=6, col=6, id=96,  matrixid=KB_J
 * - \b STO (K):     row=0, col=7, id=105, matrixid=KB_K
 * - \b NXT (L):     row=1, col=7, id=106, matrixid=KB_L
 * - \b HIST (M):    row=0, col=4, id=60,  matrixid=KB_M
 * - \b EVAL (N):    row=0, col=3, id=45,  matrixid=KB_N
 * - \b ' (O):       row=0, col=2, id=30,  matrixid=KB_O
 * - \b SYMB (P):    row=0, col=1, id=15,  matrixid=KB_P
 * - \b Y^X (Q):     row=1, col=4, id=61,  matrixid=KB_Q
 * - \b Sqrt(X) (R): row=1, col=3, id=46,  matrixid=KB_R
 * - \b SIN (S):     row=1, col=2, id=31,  matrixid=KB_S
 * - \b COS (T):     row=1, col=1, id=16,  matrixid=KB_T
 * - \b TAN (U):     row=1, col=0, id=1,   matrixid=KB_U
 * - \b EEX (V):     row=2, col=4, id=62,  matrixid=KB_V
 * - \b +/- (W):     row=2, col=3, id=47,  matrixid=KB_W
 * - \b X (X):       row=2, col=2, id=32,  matrixid=KB_X
 * - \b 1/X (Y):     row=2, col=1, id=17,  matrixid=KB_Y
 * - \b / (Z):       row=2, col=0, id=2,   matrixid=KB_DIV
 * - \b Backspace:   row=0, col=0, id=0,   matrixid=KB_BKS
 * - \b 0:           row=6, col=3, id=51,  matrixid=KB_0
 * - \b 1:           row=5, col=3, id=50,  matrixid=KB_1
 * - \b 2:           row=5, col=2, id=35,  matrixid=KB_2
 * - \b 3:           row=5, col=1, id=20,  matrixid=KB_3
 * - \b 4:           row=4, col=3, id=49,  matrixid=KB_4
 * - \b 5:           row=4, col=2, id=34,  matrixid=KB_5
 * - \b 6:           row=4, col=1, id=19,  matrixid=KB_6
 * - \b 7:           row=3, col=3, id=48,  matrixid=KB_7
 * - \b 8:           row=3, col=2, id=33,  matrixid=KB_8
 * - \b 9:           row=3, col=1, id=18,  matrixid=KB_9
 * - \b *:           row=3, col=0, id=3,   matrixid=KB_MUL
 * - \b -:           row=4, col=0, id=4,   matrixid=KB_SUB
 * - \b +:           row=5, col=0, id=5,   matrixid=KB_ADD
 * - \b .:           row=6, col=2, id=36,  matrixid=KB_DOT
 * - \b SPC:         row=6, col=1, id=21,  matrixid=KB_SPC
 * - \b ENTER:       row=6, col=0, id=6,   matrixid=KB_ENT
 * - \b UP:          row=0, col=6, id=90,  matrixid=KB_UP
 * - \b LEFT:        row=1, col=6, id=91,  matrixid=KB_DN
 * - \b DOWN:        row=2, col=6, id=92,  matrixid=KB_LF
 * - \b RIGHT:       row=3, col=6, id=93,  matrixid=KB_RT
 * - \b ALPHA:                             matrixid=KB_ALPHA
 * - \b LSHIFT:                            matrixid=KB_LSHIFT
 * - \b RSHIFT:                            matrixid=KB_RSHIFT
 * - \b ON:                                matrixid=KB_ON
 *
 * \todo Include a diagram of key positions
 * \todo Document keyboard constants and layout for the HP48gII and HP39G+.
 * \todo Define separate constants for letters versus the function key.  That
 *       way, on the HP39G+, they can be set to different values because the
 *       letters are in different places.
 */

/*!
 * \brief Tests the current state of a key.
 *
 * The key to be tested is identified by the row and col parameters.  These
 * parameters, however, do not identify the physical position of the key on
 * the keyboard.  Instead, they refer to the key's "logical" position.  Refer
 * to the documentation for the header file hpkeyb49.h for a list of keys with
 * their logical rows and columns.
 *
 * Certain keys, namely ON, ALPHA, and both shift keys, cannot be tested with
 * this function.  Instead, please use ::keyb_isON, ::keyb_isAlpha,
 * ::keyb_isLS, and keyb_isRS to test these keys.  As a convenience, the
 * functions ::keyb_isLeft, ::keyb_isRight, ::keyb_isUp, and ::keyb_isDown
 * are also provided, although those keys can be tested using this function
 * as well.
 * 
 * \param col The logical column of the key to test.
 * \param row The logical row of the key to test.
 * 
 * \return 1 if the key is pressed; 0 otherwise
 * 
 * \note Hardware registers in use: GPFDAT, GPGCON
 */
int keyb_isKeyPressed(unsigned char col, unsigned char row);



/*!
 * \brief Tests whether any key is being pressed on the keyboard.
 * \return 1 if a key is pressed; 0 otherwise
 * 
 * \note Hardware registers in use: GPFDAT, GPGCON
 */
int keyb_isAnyKeyPressed(void);

/*!
 * \brief Waits for a key to be pressed.
 *
 * This convenience function waits for a key to be completely pressed and
 * released.  It can be used to wait for user acknowledgement of some kind.
 * Because the function does not return until the key has been released, it
 * can be used without worrying about the key registering later in the
 * application code.
 */
void keyb_waitKeyPressed(void);

/*!
 * \brief Tests if the left arrow key is down.
 *
 * This is a convenience function.  It behaves exactly like
 * ::keyb_isKeyPressed \c (6,1) does.
 *
 * \return 1 if the key is pressed; 0 otherwise
 */
int keyb_isLeft(void);

/*!
 * \brief Tests if the right arrow key is down.
 *
 * This is a convenience function.  It behaves exactly like
 * ::keyb_isKeyPressed \c (6,3) does.
 *
 * \return 1 if the key is pressed; 0 otherwise
 */
int keyb_isRight(void);

/*!
 * \brief Tests if the up arrow key is down.
 *
 * This is a convenience function.  It behaves exactly like
 * ::keyb_isKeyPressed \c (6,0) does.
 *
 * \return 1 if the key is pressed; 0 otherwise
 */
int keyb_isUp(void);

/*!
 * \brief Tests if the down arrow key is down.
 *
 * This is a convenience function.  It behaves exactly like
 * ::keyb_isKeyPressed \c (6,2) does.
 *
 * \return 1 if the key is pressed; 0 otherwise
 */
int keyb_isDown(void);

/*!
 * \brief Tests if the alpha key is down.
 * \return 1 if the key is pressed; 0 otherwise
 *
 * \note Hardware registers in use: GPFDAT
 */
int keyb_isAlpha(void);

/*!
 * \brief Tests if the left shift key is down.
 * \return 1 if the key is pressed; 0 otherwise
 *
 * \note Hardware registers in use: GPFDAT
 */
int keyb_isLS(void);

/*!
 * \brief Tests if the right shift key is down.
 * \return 1 if the key is pressed; 0 otherwise
 *
 * \note Hardware registers in use: GPFDAT
 */
int keyb_isRS(void);

/*!
 * \brief Tests if the on key is down.
 * \return 1 if the key is pressed; 0 otherwise
 *
 * \note Hardware registers in use: GPFDAT
 */
int keyb_isON(void);

/*!
 * \brief Returns an identifier for the first key pressed.
 *
 * Optionally waits for a key to be pressed, and then returns an identifier
 * specifying which key was pressed.  The identifier is calculated from the
 * logical row and column of the key, according to the formula
 * \c col \c * \c 0xf \c + \c row .
 *
 * If the wait parameter is non-zero, this function does not return until a
 * key has been completely pressed and released.  If multiple keys are pressed
 * simultaneously, the function does not return until all keys have been
 * released; but the return value will be the identifier of the first key.
 * If the wait parameter is zero, the function will wait neither for a key
 * to be pressed or released.
 *
 * \param wait If 0, return a 0 identifier if no key is pressed;
 *             If non-zero, wait until a key is pressed.
 *
 * \return An identifier for the key pressed, or 0 if no key was pressed and
 *         the wait parameter was zero.
 *
 * \note Hardware registers in use: GPGDAT, GPGCON
 *
 * \bug  If wait is non-zero, a race condition makes it possible for the
 *       function to return 0 after a key press.  This only occurs if the
 *       key is released too quickly for the software to read the value.
 *
 * \bug  The backspace key returns 0, which is the same value that means
 *       no key.
 */
char keyb_getkey(int wait);


// KEYBOARD MATRIX HANDLING ROUTINE, ADDED BY CLAUDIO

/* 

KEYBOARD BIT MAP
----------------
This is the bit number in the 64-bit keymatrix.
Bit set means key is pressed.

    A]-+  B]-+  C]-+  D]-+  E]-+  F]-+  
    |41|  |42|  |43|  |44|  |45|  |46|
    +--+  +--+  +--+  +--+  +--+  +--+  

    G]-+  H]-+  I]-+        UP]+        
    |47|  |53|  |54|        |49|      
    +--+  +--+  +--+  LF]+  +--+  RT]+  
                      |50|  DN]+  |52|
    J]-+  K]-+  L]-+  +--+  |51|  +--+  
    |55|  |57|  |58|        +--+    
    +--+  +--+  +--+                    

    M]--+  N]--+  O]--+  P]--+  BKS]+
    | 33|  | 25|  | 17|  | 09|  | 01|
    +---+  +---+  +---+  +---+  +---+

    Q]--+  R]--+  S]--+  T]--+  U]--+
    | 34|  | 26|  | 18|  | 10|  | 02|
    +---+  +---+  +---+  +---+  +---+

    V]--+  W]--+  X]--+  Y]--+  /]--+
    | 35|  | 27|  | 19|  | 11|  | 03|
    +---+  +---+  +---+  +---+  +---+
    
    AL]-+  7]--+  8]--+  9]--+  *]--+
    | 60|  | 28|  | 20|  | 12|  | 04|
    +---+  +---+  +---+  +---+  +---+
    
    RS]-+  4]--+  5]--+  6]--+  -]--+
    | 61|  | 29|  | 21|  | 13|  | 05|
    +---+  +---+  +---+  +---+  +---+
    
    LS]-+  1]--+  2]--+  3]--+  +]--+
    | 62|  | 30|  | 22|  | 14|  | 06|
    +---+  +---+  +---+  +---+  +---+
    
    ON]-+  0]--+  .]--+  SP]-+  EN]-+
    | 63|  | 31|  | 23|  | 15|  | 07|
    +---+  +---+  +---+  +---+  +---+

*/

//! Constant for the F1 (A) key
#define KB_A   41
//! Constant for the F2 (B) key
#define KB_B   42
//! Constant for the F3 (C) key
#define KB_C   43
//! Constant for the F4 (D) key
#define KB_D   44
//! Constant for the F5 (E) key
#define KB_E   45
//! Constant for the F6 (F) key
#define KB_F   46
//! Constant for the APPS (G) key
#define KB_G   47
//! Constant for the MODE (H) key
#define KB_H   53
//! Constant for the TOOL (I) key
#define KB_I   54
//! Constant for the VAR (J) key
#define KB_J   55
//! Constant for the STO (K) key
#define KB_K   57
//! Constant for the NXT (L) key
#define KB_L   58
//! Constant for the HIST (M) key
#define KB_M   33
//! Constant for the EVAL (N) key
#define KB_N   25
//! Constant for the ' (O) key
#define KB_O   17
//! Constant for the SYMB (P) key
#define KB_P    9
//! Constant for the Y^X (Q) key
#define KB_Q   34
//! Constant for the Sqrt (R) key
#define KB_R   26
//! Constant for the SIN (S) key
#define KB_S   18
//! Constant for the COS (T) key
#define KB_T   10
//! Constant for the TAN (U) key
#define KB_U    2
//! Constant for the EEX (V) key
#define KB_V   35
//! Constant for the +/- (W) key
#define KB_W   27
//! Constant for the X (X) key
#define KB_X   19
//! Constant for the 1/X (Y) key
#define KB_Y   11
//! Constant for the / (Z) key
#define KB_Z KB_DIV
//! Constant for the 0 key
#define KB_0   31
//! Constant for the 1 key
#define KB_1   30
//! Constant for the 2 key
#define KB_2   22
//! Constant for the 3 key
#define KB_3   14
//! Constant for the 4 key
#define KB_4   29
//! Constant for the 5 key
#define KB_5   21
//! Constant for the 6 key
#define KB_6   13
//! Constant for the 7 key
#define KB_7   28
//! Constant for the 8 key
#define KB_8   20
//! Constant for the 9 key
#define KB_9   12
//! Constant for the backspace key
#define KB_BKS  1
//! Constant for the / (Z) key
#define KB_DIV  3
//! Constant for the * key
#define KB_MUL  4
//! Constant for the + key
#define KB_ADD  6
//! Constant for the - key
#define KB_SUB  5
//! Constant for the . key
#define KB_DOT 23
//! Constant for the SPC key
#define KB_SPC 15
//! Constant for the ENT key
#define KB_ENT  7
//! Constant for the up arrow key
#define KB_UP  49
//! Constant for the down arrow key
#define KB_DN  51
//! Constant for the left arrow key
#define KB_LF  50
//! Constant for the right arrow key
#define KB_RT  52
//! Constant for the ALPHA key
#define KB_ALPHA   60
//! Constant for the left shift key
#define KB_LSHIFT  61
//! Constant for the right shift key
#define KB_RSHIFT  62
//! Constant for the ON key
#define KB_ON  63

// MACROS TO CREATE KEYBOARD MASKS
/*!
 * \brief Create a bitmask representing the given key.
 *
 * The bitmask returned by this macro can be compared with the keymatrix::full
 * field of a ::keymatrix result.
 */
#define KB_MASK64(a) (((ULONGLONG)1)<<(a))

/*!
 * \brief Create a bitmask representing the given key (32-bit)
 *
 * The bitmask returned by this macro can be compared with the keymatrix::hiword
 * or keymatrix::loword field of a ::keymatrix result. When the key is known, it's
 * more efficient to compare a 32-bit number than a 64-bit number.
 */
#define KB_MASK32(a) (((unsigned int)1)<<(a&31))

/*!
 * \brief Create a bitmask representing the given key (8-bit)
 *
 * The bitmask returned by this macro can be compared with the keymatrix::bytes[]
 * field of a ::keymatrix result. When the column of the key is known, single-byte
 * comparisons might be more efficient than a 64-bit number.
 */
#define KB_MASK8(a)  (((unsigned int)1)<<(a&7))

// COMMON KEYBOARD MASKS
// ALL CURSOR KEYS

/*!
 * \brief A bitmask to represent the arrow keys.
 *
 * The keymatrix::full field of a ::keymatrix can be combined with this mask
 * via a bitwise and (&) to eliminate everything except the state of the
 * arrow keys (aka cursor keys).  This is a convenience constant, and its
 * value is equivalent to: \c KB_MASK64(KB_UP) \c | \c KB_MASK64(KB_DN)
 * \c | \c KB_MASK64(KB_LF) \c | \c KB_MASK64(KB_RT).
 */
#define KB_CURS ((ULONGLONG)0x001e000000000000)

// USE WITH HIWORD ONLY
/*!
 * \brief A bitmask to represent the arrow keys (32-bit).
 *
 * The keymatrix::hiword field of a ::keymatrix can be combined with this mask
 * via a bitwise and (&) to eliminate everything except the state of the
 * arrow keys (aka cursor keys).  This is a convenience constant, and its
 * value is equivalent to: \c KB_MASK32(KB_UP) \c | \c KB_MASK32(KB_DN)
 * \c | \c KB_MASK32(KB_LF) \c | \c KB_MASK32(KB_RT).
 */
#define KBH_CURS32 ((unsigned int)0x001e0000)

// ALL FUNCTION KEYS (A-F)
/*!
 * \brief A bitmask to represent the function keys.
 *
 * The keymatrix::full field of a ::keymatrix can be combined with this mask
 * via a bitwise and (&) to eliminate everything except the state of the
 * function keys.  This is a convenience constant, and its value is equivalent
 * to: \c KB_MASK64(KB_A) \c | \c KB_MASK64(KB_B) \c | \c KB_MASK64(KB_C)
 * \c | \c KB_MASK64(KB_D) \c | \c KB_MASK64(KB_E) \c | \c KB_MASK64(KB_F).
 */
#define KB_FUNC ((ULONGLONG)0x00007e0000000000)
// USE WITH HIWORD ONLY
/*!
 * \brief A bitmask to represent the function keys (32-bit).
 *
 * The keymatrix::hiword field of a ::keymatrix can be combined with this mask
 * via a bitwise and (&) to eliminate everything except the state of the
 * function keys.  This is a convenience constant, and its value is equivalent
 * to: \c KB_MASK64(KB_A) \c | \c KB_MASK64(KB_B) \c | \c KB_MASK64(KB_C)
 * \c | \c KB_MASK64(KB_D) \c | \c KB_MASK64(KB_E) \c | \c KB_MASK64(KB_F).
 */
#define KBH_FUNC32 ((unsigned int)0x00007e00)


// SHIFT CONSTANTS FOR HIGH-LEVEL KEYBOARD FUNCTIONS

//! Shift constant to use in a combined shiftcode. Left Shift.
#define SHFT_LS		0x40000000
//! Shift constant to use in a combined shiftcode. Right Shift.
#define SHFT_RS 	0x20000000
//! Shift constant to use in a combined shiftcode. Alpha.
#define SHFT_ALPHA	0x10000000
//! Shift constant to use in a combined shiftcode. On key.
#define SHFT_ON		0x80000000
//! Shift constant to use in a combined shiftcode. Any Shift or ON.
#define SHFT_ANY	0xf0000000	


//! Extracts a keycode from a combined shiftcode.
#define KEYCODE(shftcode) ((shftcode)&0xff)
//! Extracts shift plane from a combined shiftcode.
#define SHFTPLANE(shftcode) ((shftcode)&0xf0000000)


// KEYMATRIX TYPE DEFINITION
/*!
 * \brief A matrix of simultaneous key states.
 *
 * This data type is used to represent the complete state of the keyboard.
 * It can be accessed as either a single 64-bit mask, a pair of two 32-bit
 * masks representing the high and low halves of the entire mask, or as
 * individual bytes, each representing a logical column of the keyboard.
 */
typedef union {
	ULONGLONG full;
	struct { unsigned int loword,hiword; };
	unsigned char bytes[8];
} keymatrix;

// SCANS THE KEYBOARD AND STORES THE 64-BIT MATRIX IN ptr
/*!
 * \brief Retrieves the state of the complete keyboard.
 *
 * This function retrieves the state of the entire keyboard in one
 * operation. The result can then be inspected using the various \c KB_*
 * preprocessor macros and constants.
 *
 * \param ptr A pointer to a ::keymatrix, which will hold the result.
 */
extern void keyb_getmatrix(keymatrix *ptr);

/*!
 * \brief Tests the current state of a key. Keymatrix version
 *
 * This function detects if a key is pressed. Unlike the row/column version,
 * (keyb_isKeyPressed) this routine can detect all the keys.
 *
 * \param keycode The KB_... constant of a key.
 * \return 1 if the key is pressed; 0 otherwise
 * 
 * \note Hardware registers in use: GPFDAT, GPGCON

 */
int keyb_isKeyPrM(int keycode);

/*!
 * \brief Tests the current state of a key with shift plane
 *
 * This function detects if a shifted key is pressed.
 *
 * \param shiftcode The KB_... constant of a key, combined (OR '|') with
 * one or more SHFT_... constants.
 * For example, to detect Left-Shift A, the argument should be KB_A | SHFT_LS
 * \return 1 if the key is pressed; 0 otherwise
 * 
 * \note Hardware registers in use: GPFDAT, GPGCON

 */
int keyb_isShiftKeyPrM(int shiftcode);


/*!
 * \brief Returns the shiftcode for the first key pressed.
 *
 * Optionally waits for a non-shift key to be pressed, and then returns a 
 * shiftcode specifying which key was pressed and the shift state.
 *
 * If the wait parameter is non-zero, this function does not return until a
 * key has been completely pressed and released (only the key, shift can remain
 * pressed). If multiple keys are pressed simultaneously, the function does
 * not return until all keys have been released; but the return value will be
 * the identifier of the first key.
 * If the wait parameter is zero, the function will wait neither for a key
 * to be pressed or released.
 * The ON key is detected as a normal key, but Shift-ON is not detected.
 *
 * \param wait If 0, return a 0 identifier if no key is pressed;
 *             If non-zero, wait until a key is pressed.
 *
 * \return A shiftcode for the key pressed, or 0 if no key was pressed and
 *         the wait parameter was zero. The shiftcode will be comprised of
 *         a KB_... constant and a combination of the SHFT_... constants.
 *         Use the KEYCODE() macro to extract the keycode from the shiftcode.
 *         For example,
 *                    int key=keyb_getkeyM(1);
 *         To check for A regardless of shift state:
 *                    if(KEYCODE(key)==KB_A) ...
 *         To check for LS-A (LS only):
 *                    if(key==(KB_A | SHFT_LS)) ...
 *         or         if(KEYCODE(key)==KB_A && SHFTPLANE(key)==SHFT_LS)
 *
 * \note Hardware registers in use: GPGDAT, GPGCON
 */
int keyb_getkeyM(int wait);

/*!
 * \brief Gets the keycode for the next key pressed in a key combination.
 *
 * When multiple keys are expected to be pressed at the same time, this
 * function aids in detecting all the keys correctly.
 * Given a keymatrix, this function returns the keycode of the next key
 * pressed in the matrix, or 0 when no more keys are pressed. Notice that
 * the keyboard is not read by this function.
 * A valid keymatrix is expected as an input argument.
 * To use this function:
 *                 keymatrix mat;
 *                 keyb_getmatrix(&mat);	// read keyboard
 *                 int key=keyb_getnextkey(&mat,-1); // get first key
 *                 while (key!=0) {
 *                    ... process the key ...
 *                 key=keyb_getnextkey(&mat,key); // get the next keycode
 *                 }
 *
 * \param ptr Pointer to the keymatrix to be processed.
 * \param keycode Keycode of the last key returned by this function.
 *                Use -1 to retrieve the first key in the group. 
 *
 * \return A keycode for the key pressed, or 0 if no more keys are pressed
 *         in the given matrix. 

 * \note Hardware registers in use: GPGDAT, GPGCON
 */
int keyb_getnextkey(keymatrix *ptr,int keycode);

#endif 
