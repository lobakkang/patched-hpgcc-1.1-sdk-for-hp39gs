#include <hpscreen.h>


void print(char * string, int x, int y)
{

	int i;
	int pos=x;
	for(i=0; string[i] != '\0'; i++)
	{
		if (string[i]>30)
		{
			
			drawBlockXOR4bitC(getMF(string[i]),6,pos,y);
			pos+=4;
			if (pos>131) break;
		}

	}
}
