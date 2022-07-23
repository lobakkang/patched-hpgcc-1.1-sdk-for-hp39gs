//& ****************************************************************************
//&
//& Written by Ingo Blank, August 2004
//& Donated to the HP-GCC Development Team
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


/*!	\file	hpctype.h
	\brief	The C type definitions
*/

#ifndef _CTYPE_H_
#define _CTYPE_H_

// ctype

#define _islower(c) ('a' <= (c) && (c) <= 'z')
#define _isupper(c) ('A' <= (c) && (c) <= 'Z')
#define _isdigit(c) ('0' <= (c) && (c) <= '9')
#define _isalpha(c) (_islower(c) || _isupper(c))
#define _toupper(c) (_islower((c)) ? ((c)-32) : (c))
#define _tolower(c) (_isupper((c)) ? ((c)+32) : (c))



// wrappers for above macros for pointer security
// iblank 2004-10-26

inline int islower(int c);
inline int isupper(int c);
inline int isdigit(int c); 
inline int isalpha(int c); 
inline int toupper(int c); 
inline int tolower(int c); 


#endif //_CTYPE_H_
