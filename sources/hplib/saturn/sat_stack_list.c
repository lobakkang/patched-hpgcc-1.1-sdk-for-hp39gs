
/*
* This file contains the minimum functions needed to create, destroy, and push a List
* They're all in the 1 file because generally all are needed if using lists.
*
* This can be optimized later if need be.
*
* Al Borowski
* 18th Feb '05
*/


#include <hpgcc49.h>


SAT_LIST sat_list_create(unsigned int maxSize){

//creates an RPL list, holding up to 'maxSize' bytes
//this size must account for the 5 byte prologue and epilogue.

	unsigned char * data =(unsigned char *) malloc(maxSize); //get some RAM
	if(maxSize==0){
	
		return 0; //bail out, not enough memory for the data portion
	
	}

	SAT_LIST list = (SAT_LIST)malloc(sizeof(SAT_LIST)); //create the list structure

	if(list==0){
		free(data); //return to the heap
		return 0; //not enough RAM so quit
	
	}

	list->size = 5; //initally 5 nibbles, for prologue
	list->data= data; 
	
	//setup the prologue (0x02A74)

	data[0]=0x74; 
	data[1]=0x2A;
	data[2]=0x00;	

	return list;

}


void sat_list_destroy(SAT_LIST list){

	//frees memory allocated for an RPL List

	if(list!=0){
	
		free(list->data);
		free(list);

	
	}

}

//==========================

//This pushes an RPL list to the RPL Stack.
//It returns TRUE on sucess, FALSE if not enough Saturn space.

BOOL sat_push_list(SAT_LIST list){

	if(list==0) return FALSE; //bad list


	int sataddr=sat_createtemp(list->size+5); //get room to put it (account for epilogue)
	if(sataddr==0) return FALSE; //no room
		
	unsigned char ep[5]; //room for the epilogue (0x0312B)
	
	ep[0]=0x2B;
	ep[1]=0x31;
	ep[2]=0x00;	
	
	sat_poke_nibbles(sataddr,list->data,list->size); //write the representation to Saturn RAM 
	//now need to write the epilogue
	sat_poke_nibbles(sataddr+list->size, ep, 5); 

	// done with object creation

	sat_pushptr(sataddr); //push a pointer to it on te RPL Stack
	return TRUE;

}

