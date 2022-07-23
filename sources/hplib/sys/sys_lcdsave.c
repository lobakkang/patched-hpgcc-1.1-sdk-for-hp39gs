#include <hpgcc49.h>

void sys_lcdsave(int *buf)
{
// SAVE FIRST 11 REGISTERS
memcpyw(buf,(int *)LCD_REGS,11);

// SAVE LAST 6 REGISTERS
memcpyw(buf+11,(int *) (LCD_REGS+0x4c),6);
}
