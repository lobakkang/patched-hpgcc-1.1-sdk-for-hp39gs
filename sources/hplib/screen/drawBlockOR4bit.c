#include <hpscreen.h>


//!draws a varible height 4-bit sprite using OR logic
/**
 *
 */
void		drawBlockOR4bit(unsigned char* sprite, int height, int x, int y)
{
	volatile char* LCDPos = getLCDPointer(x,y); // get the position to write to
	unsigned char left, right; // the split bytes
	unsigned char odd=0;  //odd or even row ?
	unsigned char buf;  // half byte to store current row
	
	int ali = x & 0x7; // x mod 8

	while (height-->0)
	{  //while there are more half bytes to draw...

		buf=((*sprite)>>(odd<<2))&0xf;		//first/second 4bit row
		odd = !odd;							

        left = (buf<<ali)&0xff;


        *LCDPos = (*LCDPos) | left; //save the left
		if (ali>4)
		{
			right =(buf>>(8-ali))&0xff;
			*(LCDPos + 1) = *(LCDPos + 1) | right; //and the right
		}

        LCDPos += 0x14; //Y=Y+1
        if (!odd) sprite++; //look at the next byte

	}
}
