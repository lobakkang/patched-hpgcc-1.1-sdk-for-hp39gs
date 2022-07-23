// MFLOPS estimate using Monte Carlo PI approximation
//
// IBL 2004
//

#include "local_includes.h"
#include "math.h"

void
center(char *s)
{
	char filler[20];
	memset(filler,0,20);
	memset(filler,' ',(screen_width()-strlen(s))/2);
	printf("%s%s\n",filler,s);
}
	
int
main()
{
	double x,y;
	int i,steps,c,t0,delta,dummy;
	
	sys_intOff();
	clearScreen();
	
	//set_decimal_separator(",");
	set_decimal_digits(5);
	
	
	center( "*** Monte Carlo PI ***");
	printf("\n");
	center("This will take ~ 20 sec...");
	printf("\n");
	
	putchar(16);
	t0 = RTC_seconds();
	steps = 1000000;
	
	int t_null = RTC_seconds();
	volatile int n;
	c = 0;
	for (n = 0; n < steps; n++) c++ ;
	
	t_null = sys_delta_seconds(t_null,RTC_seconds());
	
	for(i = c = dummy = 0; i < steps; i++) {
		x = random();
		y = random();
		if (x*x+y*y <= 1.0)
			c++;
		else
			dummy++;
	}
	printf("%c ~ %f (%d iterations)\n",135,4.0*c/steps,steps);
	printf("\nRuntime = %d sec\n",delta=sys_delta_seconds(t0,RTC_seconds())-t_null);
	printf("MFLOPS ~ %f\n",9.0*steps/delta/1000000.0);
	beep();
	
	while (! keyb_isON());
	sys_intOn();
	
	return 0;
}

