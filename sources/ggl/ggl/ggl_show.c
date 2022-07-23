#include <hpgcc49.h>
#include "gglpr.h"


void ggl_show(int *framebuf)
{
volatile int *lcd=(int *)LCD_REGS;
int bufsize=lcd[6]-lcd[5];
lcd[5]=((int)framebuf)>>1;
lcd[6]= ( (((int)framebuf)>>1) + bufsize )&0x1fffff;

}
