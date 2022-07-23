#include <hpgcc49.h>

//Pops a real from the stack, as a double. Returns 0.0 on error.
//First revision Al Borowski 22nd Jan '05. 

//Insert License stuff here. 


double sat_pop_real(){


	if(sat_stack_depth()==0){
			return 0.0; //error: too few arguments
	}

	SAT_STACK_ELEMENT e; //   Get element at level #1, i.e. stack-top
    sat_get_stack_element(1,&e);
	
	if (e.prologue!=SAT_DOREAL){
		return 0.0; //error: not a real
	}
	
	int exponent= sat_peek(e.addr+5,1)+10*sat_peek(e.addr+6,1)+100*sat_peek(e.addr+7,1);  //the exponent uin BCD
	unsigned int sign = sat_peek(e.addr+20,1) ;  //the sign

	int i;
	
	LONGLONG mantissa=0; //the mantissa, in binary. LONGLONG will hold ~19 digits
	
	for(i=11;i>0;i--){
		mantissa=mantissa*10+sat_peek(e.addr+8+i,1); //get the next digit
	}
	
	if(exponent>499){ //exponent is negative
		exponent = 0- (1000-exponent); //make suitably negative
	}


	if (sign == 9){ //mantissa is negative	
		mantissa = 0-mantissa; //make negative
	}

	double number = mantissa; //initally mantissa
	number = number / 10000000000.0; // scale it
	//now add in exponent
	
	if(exponent>=0){
		number = number*ipow (10.0, exponent);
	}
	
	else{ //negative exponent, so divide
		number = number/ipow (10.0, abs(exponent));
	}
	
	sat_stack_drop(); //pop the real from the stack
	return number;

}

