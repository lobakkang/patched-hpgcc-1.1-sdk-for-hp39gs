void invertScreen(){

        unsigned int volatile *lcd; 


          lcd = (int * ) 0x7300010;
          *lcd = 0x82;
          return;

}
