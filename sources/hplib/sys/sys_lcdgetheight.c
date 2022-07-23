#include <hpgcc49.h>

int sys_lcdgetheight()
{
return (*((int *) (LCD_REGS+0xc)))>>8;
}
