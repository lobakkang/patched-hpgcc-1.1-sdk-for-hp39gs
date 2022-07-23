#include <hpstdlib.h>

// Added by iblank 2004-10-23

RNDFUNC rand_hook = (RNDFUNC) NULL;

extern int __srand_initialized;

unsigned int
rand_bits(int bits)
{
	// FIXME: workaround for broken compile time pointers
	if (!rand_hook)
		rand_hook = mwc;
	
	return (*rand_hook)(bits);
}

unsigned int
rand()
{
	// Conforms to UNIX manpage, ANSI ?
	// <ibl ; 2005-03-29>
	if (! __srand_initialized )
		srand(1);
	
	return rand_bits(32);
}


