
/*


$Header: /cvsroot/hpgcc/sources/crt0/crt0.c,v 1.17 2005/04/28 23:05:46 cdlapilli Exp $


*/

int main(); //hack by Al


extern unsigned int *__exit_stk_state;
extern int _exit_save(unsigned int *ptr);
extern void __exit_cleanup();

extern void sys_intOff();
extern void sys_intOn();
extern void sys_slowOff();
extern void sys_slowOn();
extern int	keyb_isAnyKeyPressed (void);

extern void sys_lcdfix();
extern int  sys_lcdgetheight();
extern void sys_lcdsave(int *buffer);
extern void sys_lcdrestore(int *buffer);
extern void sys_clksave(int *buf);
extern void sys_clkrestore(int *buf);



unsigned int __display_buf; //default monochrome display buffer


void _start()
{

	//modification by Al 13/3/05 - create a global that contains the address
	//of the Video Buffer

	unsigned int volatile * LCDSADDR1 = (unsigned volatile int*) 0x7300014;

	__display_buf = (*LCDSADDR1 &0xffff)*2 + 0x7f00000; //read in the buffer address
	//this should work as long as Kinpo doesn't make too many changes, and only
	//shifts the buffer slightly.

	//it assumes that the MMU mappings have not changed & the buffer is in the 4kb SRAM

	// SET THE SCREEN HEIGHT FOR stdio MODULE
	extern int __scr_h;
	
	__scr_h=(sys_lcdgetheight()==64)? 10:13;

	
	// REORGANIZED FOR BETTER HARDWARE MANAGEMENT, CLAUDIO - Apr 2005

	// DECLARE LOCALLY TO REDUCE EXECUTABLE SIZE
	unsigned int state_buffer[4],lcd_buffer[17],clk_buffer[6];

	__exit_stk_state=state_buffer;


	sys_intOff(); //Interrupts off so we can use the screen. 

	// SAVE HARDWARE STATE
	sys_lcdsave(lcd_buffer);
	sys_clksave(clk_buffer);
	sys_slowOn(); //Slow mode on by default - makes sense in the majority of applications 
	
	
	// WILL RETURN 0 WHEN EXITTING
	if(_exit_save((unsigned int *)state_buffer)) { 
	
	main(); 
	__exit_cleanup(); 
	}

	while(keyb_isAnyKeyPressed()); //make sure that the user is not holding down a key, or it will
									//be passed to the emulated OS (very annoying)

	// SLOWOFF NOT NEEDED, RESTORE ORIGINAL HARDWARE VALUES
	sys_lcdrestore(lcd_buffer);
	sys_clkrestore(clk_buffer);
	sys_intOn(); //interrupts on for the OS


}
