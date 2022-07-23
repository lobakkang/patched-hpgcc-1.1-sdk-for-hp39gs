//& ****************************************************************************
//&
//& Written by Al Borowski, September 2004
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

char keytab[]=
{
	// part #1 - unshifted

	8,
	112,//'p'
	111,	// 'o'
	110,	// 'n'
	109,	// 'm'
	97,	// 'a'
	0,
	107,	// 'k'
	117,	// 'u'
	116,	// 't'
	115,	// 's'
	114,	// 'r'
	113,	// 'q'
	98,	// 'b'
	0,
	108,	// 'l'
	122,	// 'z'
	121,	// 'y'
	120,	// 'x'
	119,	// 'w'
	118,	// 'v'
	99,	// 'c'
	0,
	0,
	42,	// '*'
	57,	// '9'
	56,	// '8'
	55,	// '7'
	0,
	100,	// 'd'
	0,
	0,
	45,	// '-'
	54,	// '6'
	53,	// '5'
	52,	// '4'
	0,
	101,	// 'e'
	104,	// 'h'
	0,
	43,	// '+'
	51,	// '3'
	50,	// '2'
	49,	// '1'
	0,
	102,	// 'f'
	105,	// 'i'
	0,
	13,
	32,	// ' '
	46,	// '.'
	48,	// '0'
	0,
	103,	// 'g'
	106,	// 'j'
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
};
/*
// part #2 - shifted (LS)

	8
	80	// 'P'
	79	// 'O'
	78	// 'N'
	77	// 'M'
	65	// 'A'
	0
	75	// 'K'
	85	// 'U'
	84	// 'T'
	83	// 'S'
	82	// 'R'
	81	// 'Q'
	66	// 'B'
	0
	76	// 'L'
	90	// 'Z'
	89	// 'Y'
	88	// 'X'
	87	// 'W'
	86	// 'V'
	67	// 'C'
	0
	0
	42	// '*'
	57	// '9'
	56	// '8'
	55	// '7'
	0
	68	// 'D'
	0
	0
	95	// '_'
	54	// '6'
	53	// '5'
	52	// '4'
	0
	69	// 'E'
	72	// 'H'
	0
	43	// '+'
	51	// '3'
	50	// '2'
	49	// '1'
	0
	70	// 'F'
	73	// 'I'
	0
	13
	44	// ','
	46	// '.'
	48	// '0'
	0
	71	// 'G'
	74	// 'J'
	0
	0
	0
	0
	0
	0
	0
	0
	0

// part #3 - shifted (RS)

	8
	80	// 'P'
	79	// 'O'
	78	// 'N'
	77	// 'M'
	65	// 'A'
	0
	75	// 'K'
	85	// 'U'
	84	// 'T'
	83	// 'S'
	82	// 'R'
	81	// 'Q'
	66	// 'B'
	0
	76	// 'L'
	90	// 'Z'
	89	// 'Y'
	88	// 'X'
	87	// 'W'
	86	// 'V'
	67	// 'C'
	0
	0
	42	// '*'
	57	// '9'
	56	// '8'
	55	// '7'
	0
	68	// 'D'
	0
	0
	45	// '-'
	54	// '6'
	53	// '5'
	52	// '4'
	0
	69	// 'E'
	72	// 'H'
	0
	43	// '+'
	51	// '3'
	50	// '2'
	49	// '1'
	0
	70	// 'F'
	73	// 'I'
	0
	13
	32	// ' '
	46	// '.'
	48	// '0'
	0
	71	// 'G'
	74	// 'J'
	0
	0
	0
	0
	0
	0
	0
	0
	0

// part #4 - shifted (Alpha)

	8
	80	// 'P'
	79	// 'O'
	78	// 'N'
	77	// 'M'
	65	// 'A'
	0
	75	// 'K'
	85	// 'U'
	84	// 'T'
	83	// 'S'
	82	// 'R'
	81	// 'Q'
	66	// 'B'
	0
	76	// 'L'
	47	// '/'
	89	// 'Y'
	88	// 'X'
	87	// 'W'
	86	// 'V'
	67	// 'C'
	0
	0
	42	// '*'
	57	// '9'
	56	// '8'
	55	// '7'
	0
	68	// 'D'
	0
	0
	45	// '-'
	54	// '6'
	53	// '5'
	52	// '4'
	0
	69	// 'E'
	72	// 'H'
	0
	43	// '+'
	51	// '3'
	50	// '2'
	49	// '1'
	0
	70	// 'F'
	73	// 'I'
	0
	13
	32	// ' '
	46	// '.'
	48	// '0'
	0
	71	// 'G'
	74	// 'J'
	0
	0
	0
	0
	0
	0
	0
	0
	0
};
*/

char getchar()
{
	unsigned int volatile * GPGDAT = (int*) 0x7A00064;

	// Wait for a key to be pressed (except alpha/on/LS/RS)
	while( (*GPGDAT & 0xff)!=0xFF)
	{}

	// Look for alpha key
	if (keyb_isAlpha())
	{
	}
	return(0);
}



