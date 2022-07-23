/*
*First revision: Al Borowski, 18th Feb '05
*
*Adds a LONGLONG to an RPL list as a ZINT
*
*/

#include <hpgcc49.h>

void sat_list_add_zint(SAT_LIST list, LONGLONG num){

	char buffer[300]; //reserve room for 300 digits.

	int negative=(num<0); //if num is less then zero, its negative
	
	num=abs(num);//force it to be positive
	
	lltoa(num, buffer, 10); //buffer now contains the number as a string, in ASCII form
	int digits=strlen(buffer); //number of digits

	int i;
	
	for (i=0;i<digits;i++){
	
		buffer[i]=buffer[i]-'0'; //remove ASCII offset.
	
	}

	sat_list_add_zint_array(list, digits, negative, buffer); //add the zint

	return; //done

}
