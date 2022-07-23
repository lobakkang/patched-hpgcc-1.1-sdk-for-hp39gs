//& <prolog>
//& ****************************************************************************
//&
//& Written by Ingo Blank, October 2004
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

//& </prolog>


// $Header: /cvsroot/hpgcc/sources/hplib/saturn/sat_decode_data.c,v 1.3 2005/01/14 23:11:56 cdlapilli Exp $

#include <hpgcc49.h>


char *
_sat_decode_string(unsigned sat_adr)
{
	#define _SAT_DECODE_STRING_BUFLEN 512
	static char buf[_SAT_DECODE_STRING_BUFLEN+1];
	int nchars = min((sat_peek_sat_addr(sat_adr+5) - 5) / 2,_SAT_DECODE_STRING_BUFLEN);
	memset(buf,0,_SAT_DECODE_STRING_BUFLEN+1);
	return (char *) sat_peek_sat_bytes(buf,sat_adr+10,nchars);
}

/*
double
_sat_decode_real(unsigned d)
{
	// TODO: implement
	return 3.1415;
}

LONGLONG
_sat_decode_long(unsigned l)
{
	// TODO: implement
	return -9999LL;
}

*/

int
sat_decode_stack_element(SAT_STACK_DATA *data, SAT_STACK_ELEMENT *stack)
{
	int r = 0;
	
	if(stack->prologue == SAT_DOCSTR) {
		data->type = SAT_DATA_TYPE_STRING;
		data->sval = strdup(_sat_decode_string(stack->addr));
		
	}
	/*
	else if(stack->prologue == SAT_DOHXS) {
		data->type = SAT_DATA_TYPE_LONG;
		data->lval = _sat_decode_long(stack->addr);
		// TODO: convert to INT, if possible
	}
	
	else if(stack->prologue == SAT_DOREAL) {
		data->type = SAT_DATA_TYPE_REAL;
		data->dval = _sat_decode_real(stack->addr);
		
	}
	*/
	else {
		data->type = SAT_DATA_TYPE_UNSUPPORTED;
		r = -1;
	}
	
	return r;
}
