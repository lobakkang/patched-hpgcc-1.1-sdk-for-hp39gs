
/*
HP-Daleks 
Al Borowski 

$Header: /cvsroot/hpgcc/examples/games/daleks.c,v 1.3 2005/04/04 13:09:09 alborowski Exp $

*/

#include <hpgcc49.h>
#include <hpgraphics.h>

//grid parameters

#define X_SIZE 16
#define Y_SIZE 9
#define SQUARE_SIZE 8


//define the directons

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UPLEFT 4
#define UPRIGHT 5
#define DNLEFT 6
#define DNRIGHT 7

//and the state

#define DEAD 0
#define LIVE 1

typedef struct { //an Dalek
           int X,Y, state;
        } dalek;

typedef char dir; //dalek direction


dalek* daleks; // an array of the daleks
dalek player; //treat the player as a dalek.
int numberOfDaleks; //total number of daleks in play

int screwdriversLeft; //number of screwdrivers left

dir calcDirection(int X, int Y, int playerX, int playerY){
	//calculates the directon the dalek should move. 

	if (Y==playerY){
	//the player is directly to the left or right of us
	
		if(X>playerX)
			return LEFT; //need to move left 
		return RIGHT; //otherwise move to the right
	}

	if(X==playerX){
	//player is directly above or below us
	
		if(Y>playerY)
			return UP; //move down
		return DOWN; //move up
	
	}
	
	//here, the player is not directly up, down, left or right. So we move
	//diagonally towards them.
	
	if(X>playerX&&Y>playerY)
		return UPLEFT;

	if(X>playerX&&Y<playerY)
		return DNLEFT;

	if(X<playerX&&Y>playerY)
		return UPRIGHT;
		
	return DNRIGHT;
}


void moveDalek(dalek* dal){
	//move the dalek towards the player, if it is alive
	
	if(dal->state==DEAD)
	return; //dalek is dead, so don't move it!
	
	   switch( calcDirection(dal->X, dal->Y, player.X, player.Y) )
     {
        case UP : dal->Y--; //calculate the direction, and move accordingly
                   break;
        case DOWN : dal->Y++;
                   break;
        case LEFT : dal->X--;
                   break;
        case RIGHT : dal->X++;
                   break;
        case UPRIGHT : dal->X++;
						dal->Y--;
                   break;				   
        case DNRIGHT : dal->X++;
						dal->Y++;
                   break;				   
        case UPLEFT  : dal->X--;
						dal->Y--;
                   break;				   
        case DNLEFT  : dal->X--;
						dal->Y++;
                   break;				   

	default  : invertScreen(); //we should never get here!
                   break;
	}	
}

void moveAllDaleks(){
//moves all the daleks towards the player.

	int i;
	for(i=0;i<numberOfDaleks;i++){ //for all daleks
	
		moveDalek(&daleks[i]); //move it towards the player
	}

}

void checkCollision(){

	//checks for collisions between all daleks, and any other dalek.
	
int i,j;

	for(i=0;i<numberOfDaleks;i++){

		for(j=i+1;j<numberOfDaleks;j++){
		
			if((daleks[i].X==daleks[j].X)&&(daleks[i].Y==daleks[j].Y)){
			
			daleks[i].state=DEAD; //kill both daleks
			daleks[j].state=DEAD;
			
						
			}
		
		
		}
		
		if((daleks[i].X==player.X)&&(daleks[i].Y==player.Y)){
		
		player.state=DEAD; //kill the player
		
		}


	}
}


void drawGrid(){

//draws the grid 

	hpg_set_color(hpg_stdscreen, HPG_COLOR_GRAY_5); //light grey
	
	int x,y;
	
	for(y=0;y<=Y_SIZE;y++) //horizitontal lines
			hpg_draw_line(0,y*SQUARE_SIZE,SQUARE_SIZE*X_SIZE,y*SQUARE_SIZE);

	for(x=0;x<=X_SIZE;x++) //vertical lines
			hpg_draw_line(x*SQUARE_SIZE,0, x*SQUARE_SIZE,SQUARE_SIZE*Y_SIZE);
	


}

void drawDaleks(){

	//draws the daleks, and the player
	
	hpg_set_color(hpg_stdscreen, HPG_COLOR_BLACK); //black
	
	int i;
	
	for(i=0;i<numberOfDaleks;i++){
	
	
		if(daleks[i].state==LIVE){ //a black circle is a living dalek
			hpg_fill_circle((daleks[i].X+1)*SQUARE_SIZE-(SQUARE_SIZE/2),(daleks[i].Y+1)*SQUARE_SIZE-(SQUARE_SIZE/2),3);
		
		}
		else{ //dalek is dead
	
			hpg_draw_text("X",daleks[i].X*SQUARE_SIZE+3, daleks[i].Y*SQUARE_SIZE+3);
	
		}
	
	
	}
	
	//hpg_set_color(hpg_stdscreen, HPG_COLOR_GRAY_10); //dark grey
	hpg_set_color(hpg_stdscreen, HPG_COLOR_BLACK); //black	
	//smaller circle for player
	hpg_fill_circle((player.X+1)*SQUARE_SIZE-(SQUARE_SIZE/2),(player.Y+1)*SQUARE_SIZE-(SQUARE_SIZE/2),2);

}

void redrawScreen(){

//redraws the screen

	hpg_clear(); //clear the screen
	
	drawGrid(); //draw the grid
	drawDaleks(); //and the daleks
	hpg_flip(); //display the new screen

}

void teleport(){
	//teleports the player
	
	player.X=abs(rand())%X_SIZE;
	player.Y=abs(rand())%Y_SIZE;
	
	unsigned int volatile *LCDCON5 = (int * ) 0x7300010;
	
	sys_waitRTCTicks(1);
	*LCDCON5=*LCDCON5^0x80; //toggle LCD to black
	sys_waitRTCTicks(2);	
	*LCDCON5=*LCDCON5^0x80; //and back again to normal ('special effect')

	checkCollision(); //run the collision detection routine, in case teleported on a dalek
	
}


void placeDaleks(){

	int i;
	
	for(i=0;i<numberOfDaleks;i++){
	
		daleks[i].X=abs(rand())%(X_SIZE-2); //dalek
		daleks[i].Y=abs(rand())%(Y_SIZE-2);
		daleks[i].state=LIVE;
	
	}


}

BOOL daleksAreDead(){
	//returns TRUE if all daleks are dead

	int i;
	
	for(i=0;i<numberOfDaleks;i++){
	
		if(	daleks[i].state==LIVE)
			return FALSE; //at least 1 dalek is still alive
	
	}

	return TRUE; //all are dead
}

void useSonicScrewdriver(){
	//this uses the 'Sonic Screwdriver' which destroys all daleks adjacent to the player
	
	if(screwdriversLeft==0) return ; //none left!
	screwdriversLeft--; //use a screwdriver, so decrease the count
	
	int i, xDif, yDif;

	for(i=0;i<numberOfDaleks;i++){

		xDif=daleks[i].X-player.X;
		yDif=daleks[i].Y-player.Y;
		if(abs(xDif)<2&&abs(yDif)<2){ //if adjacent 
			daleks[i].state=DEAD; //kill it
		}
	
	}

}

int playGame(){

	//heres where the action is!
		redrawScreen();
	
	while(1){ 
	
	if(player.state==DEAD)
		return -1; //player died, bail out
	
	if(daleksAreDead())
		return 1; //all daleks are dead
	
	while(!keyb_isAnyKeyPressed()); //wait until a key is pressed
	

		if(keyb_isON()) return -1;//bail out when ON is pressed
		
		if(keyb_isAlpha()){
			useSonicScrewdriver(); //use the Sonic Screwdriver
		}
	
		if(keyb_isUp()||keyb_isKeyPressed(2,3))
				player.Y--; //move up
		if(keyb_isDown()||keyb_isKeyPressed(2,5))
				player.Y++; //move down
		if(keyb_isLeft()||keyb_isKeyPressed(3,4))
				player.X--; //move up
		if(keyb_isRight()||keyb_isKeyPressed(1,4))
				player.X++; //move up			
	
		//now check for diagonal movement
		
		if(keyb_isKeyPressed(1,3)){ //9 key, upper right
			player.X++;
			player.Y--;
		}
		if(keyb_isKeyPressed(3,3)){ //7 key, upper left
			player.X--;
			player.Y--;
		}
		if(keyb_isKeyPressed(3,5)){ //1 key, lower left
			player.X--;
			player.Y++;
		}
		if(keyb_isKeyPressed(1,5)){ //3 key, lower right
			player.X++;
			player.Y++;
		}	
		
		if(keyb_isLS()){
			teleport(); //randomly teleport the player
		}


		//check that we haven't moved the player off the screen
		
		if(player.X<0) player.X=0;
		if(player.Y<0) player.Y=0;
		if(player.Y>=Y_SIZE) player.Y=Y_SIZE-1;
		if(player.X>=X_SIZE) player.X=X_SIZE-1;	
		moveAllDaleks(); //move the daleks
		checkCollision(); //check for a collision
		redrawScreen();
		while(keyb_isAnyKeyPressed()); //wait until no key pressed
		sys_waitRTCTicks(2); //wait a bit
	}


}	


void drawTitleScreen(){


	//draws the title screen at the beginning of the game

    hpg_set_font(hpg_stdscreen, hpg_get_bigfont());
    hpg_set_color(hpg_stdscreen, HPG_COLOR_BLACK);
 
    hpg_clear();
    hpg_draw_text("HP-Daleks", 25, 0);
    hpg_draw_text("Http://Hpgcc.Org", 5, 12);
	hpg_set_font(hpg_stdscreen, hpg_get_minifont());
	hpg_draw_text("This is an example program\ndemonstrating the C Compiler\nand the HPG Graphics Library.\nThe source is freely available.", 0, 26);
	hpg_draw_text("Blue Shift Teleports, ON Quits,\nAlpha for Sonic Screwdriver", 0, 54); //build date		
	hpg_draw_text(__DATE__, 0, 70); //build date	
	hpg_flip();
	
	sys_waitRTCTicks(2); //wait a bit 
	while(keyb_isAnyKeyPressed()); //wait until no key pressed
	sys_waitRTCTicks(2); //wait a bit
	while(!keyb_isAnyKeyPressed()); //wait until a key pressed 
	sys_waitRTCTicks(2); //wait a bit 
	while(keyb_isAnyKeyPressed()); //wait until no key pressed



}

	
int main(){


	hpg_set_mode_gray4(1); //double buffered 4 colour greyscale

	daleks=(dalek*)malloc(sizeof(dalek)*150); //allocate ram for daleks
	if(daleks==0) goto exit;//bail out if not enough ram for daleks (paranonia)

	drawTitleScreen(); //title screen

	srand(sys_RTC_seconds()); //seed the random number generator from the realtime clock

	numberOfDaleks = 2;

	do{
		numberOfDaleks+=2;
		placeDaleks();
		screwdriversLeft = 1; //1 screwdriver per level
		player.X=X_SIZE-1; //setup the player in the lower right corner
		player.Y=Y_SIZE-1;
		player.state=LIVE;
	}
		while(playGame()==1); //keep going until player is dead, or aborts.
	
	
	hpg_clear();
 
	hpg_set_font(hpg_stdscreen, hpg_get_bigfont());
	hpg_set_color(hpg_stdscreen, HPG_COLOR_BLACK);
 
	hpg_clear();
	hpg_draw_text("GAME OVER!", 5, 5);
	hpg_flip();
	
	sys_waitRTCTicks(2); //wait a bit 
	while(keyb_isAnyKeyPressed()); //wait until no key pressed
	sys_waitRTCTicks(2); //wait a bit
	while(!keyb_isAnyKeyPressed()); //wait until a key pressed 
	sys_waitRTCTicks(2); //wait a bit 
	while(keyb_isAnyKeyPressed()); //wait until no key pressed
	
exit:	
	 
	free(daleks);

	 
     return 0;


}
