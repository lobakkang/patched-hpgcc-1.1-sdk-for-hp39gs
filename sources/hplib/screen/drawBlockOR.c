#include <hpscreen.h>

void drawBlockOR (unsigned char* sprite, int length, int x, int y){
                   //draws a varible length sprite using OR logic

       volatile char* LCDPos = getLCDPointer(x,y); // get the position to write to

        char left, right; // the split bytes
//        char oldLeft, oldRight; // the old data at that position

        int ali = x & 0x7; // x mod 8

        while (length>0){  //while there are more bytes to draw...

        left = ((*sprite)<<ali)&0xff;
        right =((*sprite)>>(8-ali))&0xff;


        *LCDPos = (*LCDPos) | left; //save the left
        *(LCDPos + 1) = *(LCDPos + 1) | right; //and the right
 
        LCDPos=LCDPos + 0x14; //Y=Y+1
        sprite++; //look at the next byte
        length--;
        }

    }
