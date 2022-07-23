#include <hpstdlib.h>
#include <hpsys.h>
#include <hpconio.h>
#include <hpstdio.h>
#include <hpkeyb49.h>

int f(int x)
{
	return(x+10);
}

int g(int (*func)(int), int x)
{
	return(func(x)-10);
}


int main(void)
{

	sys_intOff();
	sys_slowOn();
	clear_screen();

	printf("d0:%d\n",g(f,5));

	while(!keyb_isON()) ;

	sys_slowOff();
	sys_intOn();
	return(1);
}






