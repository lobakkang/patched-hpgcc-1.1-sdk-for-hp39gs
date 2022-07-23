/*
*First revision: Al Borowski, 7th Jan '05
*
*Pushes a LONGLONG onto the RPL stack as a ZINT
*
*/

#include <hpgcc49.h>

BOOL sat_push_zint_llong(LONGLONG num){

	char buffer[300]; //reserve room for 300 digits.

	int negative=(num<0); //if num is less then zero, its negative
	
	num=abs(num);//force it to be positive
	
	lltoa(num, buffer, 10); //buffer now contains the number as a string, in BCD form
	int digits=strlen(buffer); //number of digits

	int i;
	
	for (i=0;i<digits;i++){
	
		buffer[i]=buffer[i]-'0'; //remove ASCII offset.
	
	}



	return sat_push_zint_array( digits, negative, buffer); //push the array
}

