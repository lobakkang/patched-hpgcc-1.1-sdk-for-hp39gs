#include <hpgcc49.h>

void sys_lcdrestore(int *buf)
{
register int *lcdr=(int *)LCD_REGS;
// DISABLE LCD WHILE PROGRAMMING IT
*buf&=0x3fffe;
// RESTORE FIRST 11 REGISTERS
memcpyw(lcdr,buf,11);

// RESTORE LAST 6 REGISTERS
memcpyw(lcdr+0x13,buf+11,6);

// TURN LCD ON
*lcdr|=1;

}
