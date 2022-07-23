#include <hpstdlib.h>
#include <hpkeyb49.h>
#include <hpmath.h>
#include <hpgraphics.h>


// "Big Balls"
//
// I called this "Big Balls", because it's about bouncing balls,
// which reminds me on a song of that Australian Band "AC/DC", which
// always impressed me with their tendre and empathique lyrics.
//
// Simple animated grphics demo using hpg double buffering
// Ingo Blank 2004-10-26


int main(void)
{

	#define MAX_X 130
	#define MAX_Y 80
	#define MAX_R 7
	#define N 100
	
	
	unsigned char old_ticks = sys_setRTCTickPeriod(1);
	
	// ... and hpg
	
	hpg_set_mode_mono(1);
	hpg_set_color(hpg_stdscreen,HPG_COLOR_BLACK);
	
	// Randomly setup elements
	
	int pos_x[N],pos_y[N],dx[N],dy[N],r[N];
	int i;
	
	for(i = 0; i < N ; i ++) {
		
		pos_x[i] = 10 + rand() % 100;
		pos_y[i] = 10 + rand() % 50;
		dx[i] = (random() < 0.5 ? 1 : -1) * (rand() % 5 + 1);
		dy[i] = (random() < 0.5 ? 1 : -1) * (rand() % 5 + 1);
		r[i] = rand() % MAX_R + 1;
	}
		
	int delay = 8;
	int elems = 10;

	for(;;) {
		
		int new_x, new_y;
		
		hpg_clear();
		
		for ( i = 0; i < elems ; i++ ){
			
			hpg_fill_circle(pos_x[i],pos_y[i],r[i]);	
			
			new_x = pos_x[i] + dx[i];
			
			if (new_x < r[i] || new_x > (MAX_X-r[i])) {
				dx[i] = -dx[i];
				new_x = pos_x[i] + dx[i];
			}
			
			new_y = pos_y[i] + dy[i];
			
			if (new_y < r[i] || new_y > (MAX_Y-r[i])) {
				dy[i] = -dy[i];
				new_y = pos_y[i] + dy[i];	
			}
			
			pos_x[i] = new_x;
			pos_y[i] = new_y;
		}
		
		if (keyb_isDown()) 
			delay++;
		
		if (keyb_isUp() && delay > 1) 
			delay--;
		
		if ( keyb_isRight() && elems < (N-1) )
			elems++;
			
		if ( keyb_isLeft() && elems > 1 )
			elems--;
			
		hpg_flip();
		sys_waitRTCTicks(delay);

		
		if (keyb_isON())
			break;
	}
	
	
	// Terminate cleanly ...
	

	sys_setRTCTickPeriod(old_ticks); // reset system default ( 8 Hz tick )
	
	return 0;
}

