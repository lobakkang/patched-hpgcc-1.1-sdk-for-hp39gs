//ZINT Helper functions, for pushing ZINTs onto the RPL Stack
//TODO: Clean up this file. It could be shrunk a fair bit.
//by not using these helper functions.

//first revision by Al, 7/1/2005

#include <hpgcc49.h>

/*      
*first we have sat_stoZintAli and sat_stoZintNAli. These functions 
*accept an array of digits, and convert them into ZINT style
*nybble packed format. They also need the number od digits in the
*array, a 'negative' flag (if true, then the number is negative), 
*and the source and dest buffers.
*
*Due to nybble addressing, 2 routines are used, for even and odd
*numbers of digits. 
*/


void sat_stoZintAli(unsigned int digits, unsigned int negative, char * source, char * dest){

//even number of digits

	unsigned int numBytes = digits / 2; //aligned
	if (negative){
		dest[numBytes]=0x09; // make negative
	}
	else{
		dest[numBytes]=0x00; // make positive	
	}


	unsigned int i=0;

	while(numBytes>0){ //now pack ZINT
	numBytes--;
	
	dest[numBytes]=(source[2*i]<<4)|(source[2*i+1]);

	i++;
	}

return;

}


void sat_stoZintNAli(unsigned int digits, unsigned int negative, char * source, char * dest){

//odd number of digits

	unsigned int byteCount = digits / 2; //not aligned
	
	dest[byteCount] = source[0]; // 
	
	if (negative){
		dest[byteCount]=dest[byteCount]|0x90; // make negative
	}

	unsigned int i=1;

	while(byteCount>0){ //now pack ZINT
	byteCount--;
	
	dest[byteCount]=(source[2*i-1]<<4)|(source[2*i]);

	i++;
	}

return; 

}



/*
*Next, we have sat_convert_zint_array.
*This function is accepts an array of digits, eg
*char zint[20] = {1,2,3,4,5,6,7,8,9}; for 123456789.
*It also accepts the negative flag and number of digits.
*and a destination address
*
*It returns a binary string containing the Saturn
*representaton of the array as a ZINT
*/



char * sat_convert_zint_array (unsigned int digits, unsigned int negative, unsigned char * source, unsigned char * dest){

	//puts a 'ZINT' into the 'dest' array
	//TODO: Clean this mess up

	//prologue
	dest[0]=0x14;
	dest[1]=0x26;
	dest[2]=0x00; //<-- right nibble must be zero, left nibble is part of size field
	
	//now do the size fields
	
	unsigned int size = digits + 5 + 1; //account for size field and sign nibble
	
	dest[2]=(size&0xf)<<4 ; //lowest nibble of size 
	dest[3]=size>>4 ; //next 2 nibbles
	dest[4]=size>>12; //final 2 nibbles
	
	
	char encodedZint[(digits/2)+5];//safety - leave room for the encoded zint

	//First, convert the digit array into ZINT packed nybble format - with sign. 

	if(digits&1){ //odd number of digits
		sat_stoZintNAli(digits,negative,source,encodedZint);
	}

	else{ //even number
		sat_stoZintAli(digits,negative,source,encodedZint);
	}
	
	
	sat_concatnib (dest,10, encodedZint,digits+1); //concat
	
	return dest;
	
	
} 

