#include <hpstdlib.h>
#include <hpsys.h>
#include <hpstring.h>
#include <hpconio.h>
#include <hpstdio.h>
#include <hpkeyb49.h>

char KEYTAB[9];

int main(void)
{

	sys_intOff();
	//sys_slowOn();
	clear_screen();
	int j;
	unsigned int volatile * GPFDAT = (int*) 0x7A00054; //data
	unsigned int volatile * GPGDAT = (int*) 0x7A00064; //data
	unsigned int volatile * GPGCON = (int*) 0x7A00060; //control
	unsigned int volatile control;
	
	while(!keyb_isAlpha())
	{
		for (j=0;j<8;j++)
		{
			control = 1<<(16+j*2);
			*GPGCON = control | 0xAAAA; // write the new control value.
			// Wait until port G says OK for this line
			while( (((*GPGDAT) >>8) | 1<<j) != 0xFF) ;
			KEYTAB[j] = (*GPGDAT)&0xFF;
		}
		
		for (j=0;j<8;j++)
		{
			printf("Con%d: ",j);
			printf("%b\n",KEYTAB[j]|0x100);
		}

		KEYTAB[8] = (char)(*GPFDAT);
		printf("ON: %b\n",KEYTAB[8]);

		sys_longWait(1);					
	}
	
	//sys_slowOff();
	sys_intOn();
	return(1);
}






