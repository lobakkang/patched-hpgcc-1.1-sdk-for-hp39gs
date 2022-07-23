#include <hpgcc49.h>


#define LCD_W 160
#define HOZVAL ((LCD_W>>2)-1)


// SETS VIDEO MODE AND RETURNS WIDTH OF THE SCREEN IN BYTES

int sys_lcdsetmode(int mode, int *physbuf)
{

// mode=0 -> Mono
//     =1 -> 4-gray
//     =2 -> 16-gray
// physbuf MUST be the physical address

volatile unsigned int *lcdreg=(unsigned int *)LCD_REGS;
int height=(lcdreg[3])>>8, pagewidth=LCD_W>>(4-mode);

// TURN OFF
lcdreg[0]&=0xfffffffe;

// set LINEVAL to height+5-1 (like ROM does)
// when LINECNT<5 is safe for updating display
lcdreg[1]=(height+4)<<14;
// set HOZVAL, but leave LINEBLANK for sys_lcdfix()
lcdreg[2]=HOZVAL<<8;

// leave MVAL alone (used for screen height determination)

// set proper byte swapping, ensure the rest at 0
lcdreg[4]=(2-mode);

// set LCDBANK and LCDBASEU
lcdreg[5]=((unsigned int)physbuf)>>1;

// set LCDBASEL
lcdreg[6]=(((unsigned int)physbuf)>>1)+(height+5)*pagewidth;

// set PAGEWIDTH
lcdreg[7]=pagewidth;

// set palette lookup for 4-GRAY mode. ignored for other modes
lcdreg[10]=0xfa70;

// set dither mode only when in grayscale
if(mode) lcdreg[19]=0x12210; else lcdreg[19]=0;

// set video mode, overwrite CLKVAL
lcdreg[0]=32+(mode<<1);

// fix CLKVAL and other clock dependent constants
// and turn on
sys_lcdfix();

return pagewidth<<1;
}
