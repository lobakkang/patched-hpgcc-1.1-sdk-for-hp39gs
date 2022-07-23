
//takes in a double, called 'number' and some space 'realStr'
//transforms the double into a HP object of type 'real'
//realStr should be 14 bytes or more.

//First revision Al Borowski, 18th Feb '05


#include <hpgcc49.h>


	unsigned char *  sat_convert_double_real(double number, unsigned char * realStr){



	int exponent;
	int i;

	LONGLONG mantissa;

	if (abs(number)>1E-505){ //decent sized number


/////////////
//Following fix by Wesley Loewer
 
   double lognumber;

  lognumber = log10(abs(number));
  if (abs(number) >= 1.0)
    exponent = (int)lognumber;   //get exponent - its positive, so round down
  else
  {
    if (lognumber == floor(lognumber))    // is the log an exact integer?
      exponent = (int)lognumber;          // if so, just get exponent
    else
      exponent = (int)lognumber - 1;      // if not, it's 1 less
  }


//////////////

	//now extract the mantissa
	
	if(exponent>=0){
		number = number/ipow (10.0, exponent);
	}
	
	else{ //negative exponent
		number = number*ipow (10.0, abs(exponent));
	}
	

	mantissa = number * 1000000000000.0; // scale it
	
	if(exponent<-499){ //make sure we're not outside the HP's range
		//exponent=-499; //debug - force to zero
			exponent=0;
			mantissa=0;
	}

	if(exponent>499)
		exponent=499;
	
	if (exponent<0){
		exponent = 1000-abs(exponent);
	}

	}
	
	else{ //its too small, so make it zero

		exponent = 0;
		mantissa=0;
	}

	unsigned char mantStr[25];//a string representation of the Mantissa
	
		
	lltoa(abs(mantissa), mantStr, 10); //convert to string representation
		
	
	
	if(mantStr[0]=='0'){
	
	//mantissa is zero
	
		for(i=0;i<20;i++){
		mantStr[i]='0'; //write all character zeros
	}
	
	if(mantStr[12]>'5'){ //if last digit is greater then five
		mantissa++; //round up, to prevent those annoying trailing 9's
		lltoa(abs(mantissa), mantStr, 10); //convert to string representation again
		
	}	


	}
	

//========================

//Here we've broken the double into a suitable mantissa and exponent
//now we have to convert it into HP's weirdo memory format.

/*

real format:

1.23456789E123 = 

	realStr[0]=0x33; <-- prologue (02933)
	realStr[1]=0x29; 
	realStr[2]=0x30; <-- exponent (123)
	realStr[3]=0x12; 
	realStr[4]=0x00; <-- mantissa (123456789000)
	realStr[5]=0x90;
	realStr[6]=0x78;
	realStr[7]=0x56;
	realStr[8]=0x34;
	realStr[9]=0x12; 
	realStr[10]=0x0S; <-- S = Sign (0 for +'ve, 9 for -'ve)

Actually this may be incorrect, you should go by the code, not by this comment.


*/


//save prologue

	realStr[0]=0x33; 
	realStr[1]=0x29; 

//save exponent 
	
	
	realStr[2]=(exponent%10) <<4 ; //leave low nibble 0 for prologue
	realStr[3] = ((exponent/10)%10)|( ((exponent/100)%10)<<4);
	
	//save mantissa
	//start with realStr[9]

	i=9;
	while(i!=3){
		realStr[i]= ((mantStr[18-2*i ]-'0') <<4)| (mantStr[19-2*i]-'0' );
		i--;
	}
	
	//now adjust sign of mantissa
	
	
	
	if(mantissa<0){ //if negative
		realStr[10] = 0x09; //make last nib 9
	}
	else{
		realStr[10]=0; //positive
	}


	return realStr; //return the built Real


}

