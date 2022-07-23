void LCDOn()
{
	volatile unsigned int *LCDCON1 = (unsigned int*)0x7F00000;
	*LCDCON1=(*LCDCON1)|(0x1);
}
