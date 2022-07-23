#include <hpstdlib.h>
#include <hpsys.h>
#include <hpconio.h>
#include <hpstdio.h>
#include <hpkeyb49.h>

extern unsigned int _save_lr;
extern unsigned int _save_sp;

int main(void)
{	

	sys_intOff();
	sys_slowOn();
	clear_screen();
	printf("%x\n",_save_lr);
	printf("%x\n",_save_sp);
	
	while(!keyb_isON()) ;
	
	
	// Now we call exit() without restoring interrupts
	exit(0);
	// And exit() calls the intOn() function, restore SP and LR which return to
	// _start().
	
	return(1);
}






