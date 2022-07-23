/*
*sat_push_zint_array.
*This function is accepts an array of digits, eg
*char zint[20] = {1,2,3,4,5,6,7,8,9}; for 123456789.
*It also accepts the negative flag and number of digits.
*
*It then pushes a ZINT onto stack, as per the parameters.
*It returns TRUE on sucess.
*/

#include <hpgcc49.h>

 BOOL sat_push_zint_array(unsigned int digits, unsigned int negative, unsigned char * source){

	char encodedZint[(digits/2)+30]; //safety - leave room for the encoded zint

	unsigned int zintSize = digits+5+5+1; //size fo Zint in nibbles (number of digits + size field + prologue + sign)

	int sataddr=sat_createtemp(zintSize); //get room to put it 
	if(sataddr==0) return FALSE; //no room

	
	sat_convert_zint_array (digits, negative, source, encodedZint); //encode it to Saturn format

	
	sat_poke_nibbles(sataddr, encodedZint, zintSize); //poke the nibbles into the Saturn domain 


	sat_pushptr(sataddr); //push a pointer to it on teh RPL Stack
	return TRUE;

}  
