#include <hpscreen.h>


//!test a variable height 4-bit sprite for collision
/**
 * This function is used to test any 'collision'.
 * Using AND, we test for collision.
 * \param sprite [in] pointer to a valid 4-bit aligned sprite
 * \param height [in] size of the sprite
 * \param x [in] position of the sprite in pixels
 * \param y [in] position of the sprite in pixels
 * \return 1 if collision\n0 else.
 */
int		testBlock4bitC(unsigned char* sprite, int height, int x, int y)
{
	volatile char* LCDPos = getLCDPointer(x,y); // get the position to read from
	unsigned char left, right; // the split bytes
	unsigned char odd=0;  //odd or even row ?
	unsigned char buf;  // half byte to store current row
	
	int ali = x & 0x7; // x mod 8

	while (height-->0)
	{  //while there are more half bytes to draw...

		buf=((*sprite)>>(odd<<2))&0xf;		//first/second 4bit row
		odd = !odd;							

		left = (buf<<ali)&0xff;

		if (*LCDPos & left)	return(1);

		if (ali>4)
		{
			right =(buf>>(8-ali))&0xff;
			if (*(LCDPos+1)&right)	return(1);
		}

        LCDPos += 0x14; //Y=Y+1
        if (!odd) sprite++; //look at the next byte

	}
	return(0);
}
