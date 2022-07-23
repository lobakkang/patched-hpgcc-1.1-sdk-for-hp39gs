    //include everything
#include <hpgcc49.h>

//shows how to use some KOS functions

int main(){

     int * p; //an example pointer, to allocate ARM memory

     kos_ClearLcd(); //use the built in routine to clear the screen

     kos_PutString(1,1,"KOS Test!"); //write a string with the built in functions
  
     char * b = kos_malloc(100); //allocate 100 bytes of hidden ARM memory

     kos_PutString(1,12,"Got RAM At:");
     kos_PutHexNumber(1,20, (int)p); //write the address of the free RAM

     kos_free(b); //make sure to free it! (need to be careful using the hidden RAM)

     kos_PutString(5,40,"Alpha quits...");  //quit when ALPHA is pressed
   
     while(!keyb_isAlpha()); //wait for alpha pressed
     


}
