#include <hpscreen.h>


//!draws a variable height 4-bit sprite using XOR logic
/**
 * This function call also be used to test any 'collision'.
 * Using AND&XOR, we test for collision.
 * \param sprite [in] pointer to a valid 4-bit aligned sprite
 * \param height [in] size of the sprite
 * \param x [in] position of the sprite in pixels
 * \param y [in] position of the sprite in pixels
 * \return 1 if collision\n0 else.
 */
int		drawBlockXOR4bitC(unsigned char* sprite, int height, int x, int y)
{
	volatile char* LCDPos = getLCDPointer(x,y); // get the position to write to
	unsigned char left, right; // the split bytes
	unsigned char odd=0;  //odd or even row ?
	unsigned char buf;  // half byte to store current row
	register int collision=0;
	
	int ali = x & 0x7; // x mod 8

	while (height-->0)
	{  //while there are more half bytes to draw...

		buf=((*sprite)>>(odd<<2))&0xf;		//first/second 4bit row
		odd = !odd;							

		left = (buf<<ali);

		if (*LCDPos & left)	collision=1;
		*LCDPos = (*LCDPos) ^ left; //xor

		if (ali>4)
		{
			right =(buf>>(8-ali));
			if (*(LCDPos+1)&right)	collision=1;
			*(LCDPos + 1) = *(LCDPos + 1) ^ right; //and the right
		}

        LCDPos += 0x14; //Y=Y+1
        if (!odd) sprite++; //look at the next byte

	}
	return(collision);
}
