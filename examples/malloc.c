#include <hpstdlib.h>
#include <hpsys.h>
#include <hpstring.h>
#include <hpconio.h>
#include <hpstdio.h>
#include <hpkeyb49.h>

int *tst;

int main(void)
{
	int *tst2;
	
	sys_intOff();
	sys_slowOn();
	clear_screen();
	printf("%i\n",10);


	tst = (int *) malloc(2000*sizeof(int));
	tst2 = (int *) malloc(2000*sizeof(int));
	int i;
	for(i=0; i<2000;i++)
	{
		tst[i] = i;
		tst2[i]= tst[i];
	}
	
	while(!keyb_isON()) 
	{
		if (i++>=2000) i=0;
		clear_screen();
		printf("%i\n",tst[i]);
		printf("%i\n",tst2[i]);
		sys_waitRTCTicks(1); //wait 1/8th second
	}

		
	free(tst2);
	free(tst);
	
	sys_slowOff();
	sys_intOn();
	
	return(1);
}






