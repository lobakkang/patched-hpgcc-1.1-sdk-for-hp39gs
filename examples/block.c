

/*
Move a block around the screen, with the arrow keys
press ON to quit
Al Borowski & D Herring

$Header: /cvsroot/hpgcc/examples/block.c,v 1.4 2005/03/31 10:30:01 alborowski Exp $

*/


#include <hpgcc49.h>

int main(void){

	char b[] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}; //a sprite to draw, in this case a solid block. Change this data to get different shapes.

	int y = 50;

	int x = 40; // initial position of sprite

	clearScreen(); //clear the screen initially.

	drawBlockOR(b,8,x,y); //and draw the block

	while (!keyb_isON()){ // bail out if ON pressed

		if (keyb_isUp() && y>0) y--; //adjust block position depending on keys.

		if (keyb_isDown() && y<72) y++;

		if (keyb_isLeft() && x>0) x--;
		
		if (keyb_isRight() && x<123) x++;

		if(keyb_isAnyKeyPressed()){ //redraw the screen if any key pressed

			sys_LCDSynch(); //wait for LCD Refresh

			clearScreen();

			drawBlockOR(b,8,x,y); //and draw the block on top of it.

			sys_waitRTCTicks(1); //wait 1/8th of a sec (default setting, no need to alter it)

		}

	}

} 
