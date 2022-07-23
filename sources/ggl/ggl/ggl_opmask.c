#include <hpgcc49.h>

#include "gglpr.h"

unsigned int ggl_opmask(unsigned int dest,unsigned int src, int tcol)
{
	// APPLY 100% TRANSPARENCY MASK
	// tcol = TRANSPARENT COLOR IN src
	register int f;
	register unsigned int res  asm("r5")=0;
	for(f=0;f<8;++f,src>>=4,dest>>=4)
	{
		if((src&0xf)==tcol) res|=dest&0xf;
		else res|=src&0xf;
		res= (res>>4) | (res<<28);


	}
	return res;
}


