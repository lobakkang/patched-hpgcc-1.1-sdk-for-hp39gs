//pops ZINTs off the stack and into a long long
//usual GPL/License stuff goes here
//First revision by Al Borowski 19 Jan '05

#include <hpgcc49.h>


int ___sat_get_nibble(char * data, int nibble){ //helper function, ignore
						//gets a nibble from a packed BCD array

	if(nibble&1){ //nibble is odd
	
	return (data[nibble/2]>>4)&0xf;
	
	}

	//else, if nibble is even
	
	return (data[nibble/2])&0xf;


}

void ___read_sat_mem(int source, char * dest, int bytes){ 

//helper function, ignore
//fills 'dest' with 'bytes' bytes of nibbles from 'source'. Source is a saturn address 

	int i=0;
	
	for(i=0;i<bytes;i++){
	
	dest[i] = sat_peek(source+i*2,2);
	
	}


}


LONGLONG sat_pop_zint_llong(){
//pops a zint off the stack into a long long (64 bits)
//only crude checking is done - returns 0 on error. 
//Also does not pop object off the stack in case of type error


	if (sat_stack_depth==0)
	return 0; //nothing no stack, so bail out

	LONGLONG num=0;

	SAT_STACK_ELEMENT e; //   Get element at level #1, i.e. stack-top
    sat_get_stack_element(1,&e);
	
	if (e.prologue!=SAT_DOINT) //yay, lets use a confusing non descriptive name. Thanks HP.
	return 0; //not a ZINT, so bail out
	
	unsigned int zintSize = (sat_peek(e.addr+5,8)&0xfffff) - 5;  //size of the zint 
	unsigned char data[zintSize/2 + 50]; //make room for zint
	___read_sat_mem(e.addr+10,data, zintSize/2+1); //read it into data
	
	unsigned int i=zintSize-1; //start from end (highest digit)
	
	while(i!=0){ //convert to binary
	i--;
	num=num*10+___sat_get_nibble(data,i);
	
	}
	
	if(___sat_get_nibble(data, zintSize-1)==9){ //adjust sign
	
		num=0-num ; //make negative if needed
	
	}
	sat_stack_drop (); //pop the number off
	return num ; //we're done
	
}
