
/*
This is a helper function for the Saturn domain. Basically, its like strcat, but works on binary strings
of Saturn data.

It itaks in a destination (dest), and the current dest size in nibbles (destLen)
source is a binary string to add to dest, and sourceLen is the number of nibbles
to add. It returns a pointer to the destination.


-Al, 18 Feb '05

*/

#include <hpgcc49.h>


unsigned char * sat_concatnib (unsigned char * dest, unsigned int destLen,  unsigned char* source, unsigned int sourceLen){

	int i;

	if(!(destLen%2)){ //even number of nibbles, so no messy alignment problems



	for(i=0;i<=sourceLen/2;i++){
			dest[i+destLen/2]=source[i]; //straight case
		}

	} 

	else{ //odd number of nibbles, so need to shift

		//I really, really hate the Saturn. 

		dest[destLen/2 ] = (dest[destLen/2 ] &0x0f)| (source[0]<<4); //take care of first nibble

		for(i=1;i<=sourceLen/2;i++){
			dest[i+destLen/2]=((source[i-1])>>4)|(source[i]<<4);
		}
	}

	return dest;
} 
