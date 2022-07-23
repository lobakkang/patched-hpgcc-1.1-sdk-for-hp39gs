//Property of the HP-GCC Project
//First revision Al Borowski, 18th Feb, '05

// see http://hpgcc.org for license stuff

// Basically, this takes in an RPL List, a number of digits
// a 'negative' flag (TRUE means the number is negative) and
// a binary series of numerical digits (value 0 to 9, NOT ASCII '0' to '9')

//It constructs a ZINT out of those digits and adds it to the list

#include <hpgcc49.h>


void sat_list_add_zint_array(SAT_LIST list, unsigned int digits, unsigned int negative, unsigned char * source ){

	//adds an array of digits to a list, as a zint

	char zint[digits/2 + 25]; //make array big enough to hold zint representation

	sat_convert_zint_array (digits, negative, source, zint); //get the zint representation

	unsigned int zintSize = digits + 5 + 5+ 1; //the zint size (data + prologue + size field + sign)

	sat_concatnib(list->data, list->size, zint, zintSize); //add the zint representation 
	list->size=list->size+zintSize; //increase the list size
	return;
}
