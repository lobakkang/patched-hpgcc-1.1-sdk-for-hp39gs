#include "local_includes.h"
#include "math.h"


int
main()
{
	double x,y,approxPI,bestPI,chiSquare,minChiSquare,deltaPercent;
	int i,steps,hits,t0,sx,sy;
	char *head = "*** Monte Carlo PI ***";
	
	sys_intOff();
	clearScreen();
	
	set_decimal_digits(10);
	
	printf("%s\n\n",head);
	printf("Press ON to exit ...\n\n");
	
	sy = gety();
	sx = 12;
	
	minChiSquare = M_PI;
	deltaPercent = 1.0;
	
	t0 = RTC_seconds();
	
	for ( steps = hits = 0; !CancelHit() && deltaPercent >= 1.0e-4; steps++ ) {
		
		x = random();
		y = random();
		if (x*x+y*y <= 1.0)
			hits++;
		
		if ( 1 /*steps % 10000 == 0*/ ) {
			
			approxPI = 4.0*hits/steps;
			chiSquare  = square(M_PI-approxPI)/M_PI;
			
			if (chiSquare < minChiSquare) {
				minChiSquare = chiSquare;
				bestPI = approxPI;
				deltaPercent = (max(bestPI,M_PI)/min(bestPI,M_PI)-1.0) * 100.0;
			}
			
			gotoxy(0,sy);
			
			printf("Steps:"); gotoxy(sx,gety()); printf("\005%17d\n",steps);
			printf("Hits:");  gotoxy(sx,gety()); printf("\005%17d\n",hits);
			printf("Time:"); gotoxy(sx,gety()); printf("\005%17d\n",sys_delta_seconds(t0,RTC_seconds()));
			printf("\nPI approx."); gotoxy(sx,gety()); printf("\005%17f\n",approxPI);
			printf("chi-square:"); gotoxy(sx,gety()); printf("\005%17f\n",chiSquare);
			printf("Best approx."); gotoxy(sx,gety()); printf("\005%17f\n",bestPI);
			printf("Delta-%%:"); gotoxy(sx,gety()); printf("\005%17f\n",deltaPercent);
		}
		
		
	}
	
	beep();
	
	while (! keyb_isON());
	sys_intOn();
	
	return 0;
}

