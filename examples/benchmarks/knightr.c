#include "local_includes.h"

/*
	The Knight's Tour
	Brute force iterative backtracking algorithm
	
	IBL 2003
	
*/

// define OPTIMIZE for n=8 board only !
#define OPTIMIZE 0

#define N 8
#define NSQ (N*N)

#if (N==8 && OPTIMIZE)
#define ROW(x) ((x)>>3)
#define COL(x) ((x) & 7)
#define BOARD(x,y) b[((x)<<3) + (y)]
#else
#define ROW(x) ((x) / n)
#define COL(x) ((x) % n)
#define BOARD(x,y) b[n*(x) + (y)]
#endif

#define INBOUNDS(x) ((x) >= 0 && (x) < n) 
#define go(x0,y0) x = x0;y = y0;p++;sx[p] = x;sy[p] = y;BOARD(x,y) = p+1


int getTime() // in seconds
{
	return RTC_seconds();
}


void printSolution(int b[],int n)
{
	int i;
	int nsq = n*n;
	
	for ( i = 1; i <= nsq; i++) 
		printf("%2d%c",b[i-1],i % n == 0 ? '\n' : ' ');
		
	
}
	
int main()
{
	int i;
	int x0,y0;
	
	int b[NSQ],w[NSQ],sx[NSQ],sy[NSQ];
	int dx[8]={-2,-1,	1,	2,	2,	1,	-1,	-2};
	int dy[8]={1,	2,	2,	1,	-1,	-2,	-2,	-1};

	int p,x,y,n,nsq,nsq1,t0;
	int timed_out = 0;
	unsigned  tries_l,tries_h ;
	
	#define TIME_OUT 300
	
	sys_intOff();
	clearScreen();
	
	//n = N;
	n = 6;
	
	x0 = rand() % n;
	y0 = rand() % n;
	
	nsq = n * n;
	
	
	printf("*** The Knight's Tour ***\n");
	printf("Starting at (%d,%d) ; n=%d.\n\n",x0,y0,n);
	
	memset(w,0,sizeof(int)*nsq);
	memset(b,0,sizeof(int)*nsq);
	
	t0 = getTime();
	tries_l = tries_h = 0;
	
	p = -1;
	go(x0,y0);
	
	nsq1 = nsq-1;
	while ( p < nsq1 ){
		
		int gx,gy,i,done; 
		
		done  = 0;
		
		
		
		for (i = w[p]; i < 8; i++) {
		
			gx = x + dx[i];
			gy = y + dy[i];
			
			tries_l++;
			if(((tries_l & 0xFFFFF) == 0xFFFFF) && (timed_out = getTime()-t0 > TIME_OUT))
				goto finish;
			
			if( ! tries_l )
				tries_h++;


			if (INBOUNDS(gx) && INBOUNDS(gy) && ! BOARD(gx,gy)) {
				w[p] = i + 1;
				go(gx,gy);
				done = 1;
				break;
			}
			
		}
			
		if (! done ) { // retreat
			BOARD(x,y) = 0;
			w[p] = 0;
			if (--p >= 0) {
				x = sx[p];
				y = sy[p];
			}
			else
				break; // No solution
		}
		
	}

finish:
	
	beep();
	
	if(timed_out)
		goto finish1;
		//printf("\nTimed out...\n");
		
	else if ( p == nsq1 )
		printSolution(b,n);
		else
			printf("No solution.\n");
	
	printf("\n%d secs/",getTime()-t0);
	if (tries_h)
		printf("(%u %u)",tries_h,tries_l);
	else
		printf("%u",tries_l);
		
	printf(" tries");
	
	
	while (! keyb_isON());

finish1:
	
	sys_intOn();
	
	
	return 0;
}


	
	
	

