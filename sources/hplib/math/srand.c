#include <hpstdlib.h>


// Added by iblank 2004-10-23

SRNDFUNC srand_hook = (SRNDFUNC) NULL;
int __srand_initialized = 0;

extern void srand_mwc(unsigned);

void
srand(unsigned int seed)
{
	// FIXME: workaround for broken compile time pointers
	
	if(!srand_hook)
		srand_hook = srand_mwc; 
	
	(*srand_hook)(seed);
	
	__srand_initialized = 1;
	
}



/*
//seeds a semi-random number generator, using "feedback taps"
//see the "Art of Electronics", page 656

//m = 31, n = 28




unsigned int __shiftReg; //the shift register, 31 bits long

void srand(unsigned int seed){
   
   if (seed&0xfffffff==0){ //paranonia, in case we get fed a zero
      __shiftReg = 1;         //prevent constant stream of zeros
   }
   else{
      __shiftReg = seed;
   }
}
*/
