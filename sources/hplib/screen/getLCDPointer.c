
extern unsigned int __display_buf; //default monochrome display buffer

 volatile char* getLCDPointer(int x, int y){ //given an X and Y position
                        //returns a pointer into video memory
 return (volatile char * )(__display_buf+x/8+0x14*y);
}
