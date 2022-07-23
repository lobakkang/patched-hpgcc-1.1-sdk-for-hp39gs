
//Property of the HP-GCC Project
//First revision Al Borowski, 18th Feb, '05

// see http://hpgcc.org for license stuff


#include <hpgcc49.h>

void sat_list_add_real(SAT_LIST list, double num){

	//adds a real to a list, as a double

	unsigned char realStr[20]; //real representation space
	sat_convert_double_real(num, realStr); //convert the double into a real object

	sat_concatnib(list->data, list->size, realStr, 21); //add the 21 nibble real representation 
	list->size=list->size+21; //increase the list size by 21 nibbles
	return;


}
