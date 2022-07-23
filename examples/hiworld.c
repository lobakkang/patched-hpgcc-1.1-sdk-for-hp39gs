/*

'Hello World' 

$Header: /cvsroot/hpgcc/examples/hiworld.c,v 1.3 2005/03/31 10:30:01 alborowski Exp $



*/



#include <hpgcc49.h> //the standard HP lib

int main(void){

	clear_screen(); //clear the screen

	printf("Hello, World!!"); //prints "hello world"

	while(!keyb_isON()); //loop until ON pressed

}
