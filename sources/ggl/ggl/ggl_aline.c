#include <hpgcc49.h>

#include "gglpr.h"

// ANTIALIASED LINES
#define N_COLORS 16
#define COL_BITS 4

#define SCR_WIDTH	(srf->width)		// screen width in nibbles


// TABLE IS THE FUNCTION
// sqrt(1.0+(deltay/deltax)*(deltay/deltax))/2.0*0.66*256.0;
int *Table_sqrt;

void ggl_initaline()
{
int f;
Table_sqrt=malloc(257*sizeof(int));
// sqrt(1.0+(deltay/deltax)*(deltay/deltax))/2.0*0.66*256.0;
for(f=0;f<257;++f)
{
Table_sqrt[f]=sqrt( ((float)f/256.0)*((float)f/256.0)+1.0 )/2.0*0.66*4096.0;
}

}

void ggl_endaline()
{
free(Table_sqrt);
}


void ggl_aline(gglsurface *srf,int x1, int y1, int x2, int y2)
{

short comp1,deltax;
short lim1,lim2;
unsigned long int addr;
short int inc_updn;
int inc_noup,inc_up;

short yr;
short int deltay;
short int f;

deltax=(short)x2-(short)x1;
deltay=(short)y2-(short)y1;

if(abs(deltay)>abs(deltax)) {
	// VERTICAL LINE
	deltax^=deltay;
	deltay^=deltax;
	deltax^=deltay;
	if(deltax<0) {
		inc_noup=-SCR_WIDTH;
		if(deltay<0) { inc_up=-(SCR_WIDTH+1); inc_updn=-1; deltay=-deltay; } else { inc_up=-(SCR_WIDTH-1); inc_updn=1; }
		deltax=-deltax;
		}
	else {
		inc_noup=SCR_WIDTH;
		if(deltay<0) { inc_up=SCR_WIDTH-1; inc_updn=-1; deltay=-deltay; } else { inc_up=SCR_WIDTH+1; inc_updn=1; }
	}
}
else {
	if(deltax<0) {
		inc_noup=-1;
		if(deltay<0) { inc_up=-(SCR_WIDTH+1); inc_updn=-SCR_WIDTH; deltay=-deltay; } else { inc_up=SCR_WIDTH-1; inc_updn=SCR_WIDTH; }
		deltax=-deltax;
		}
	else {
		inc_noup=1;
		if(deltay<0) { inc_up=-(SCR_WIDTH-1); inc_updn=-SCR_WIDTH; deltay=-deltay; } else { inc_up=SCR_WIDTH+1; inc_updn=SCR_WIDTH; }
	}

}

yr=0;

addr=(x1+SCR_WIDTH*y1); // center pixel

deltay=(deltay<<12)/deltax;

lim1=Table_sqrt[deltay>>4];
lim2=lim1+2*4096;

comp1=4096-lim1;

for(f=0;f<=deltax;++f)
{

if(yr<=lim1) ggl_pltnib(srf->addr,addr,N_COLORS-1);
	else ggl_pltnib(srf->addr,addr,(lim2-yr)>>(13-COL_BITS));

yr+=deltay;

if(yr>=4096) { yr-=4096; addr+=inc_up; }
	else { addr+=inc_noup; }

}

yr=0;

addr=(x1+SCR_WIDTH*y1)-inc_updn; // down pixel



for(f=0;f<=deltax;++f)
{

if(((lim2-yr-4096)>>(13-COL_BITS))>4) ggl_pltnib(srf->addr,addr,(lim2-yr-4096)>>(13-COL_BITS));

yr+=deltay;

if(yr>=4096) { yr-=4096; addr+=inc_up; }
	else { addr+=inc_noup; }

}

yr=0;

addr=(x1+SCR_WIDTH*y1)+inc_updn; // up pixel


for(f=0;f<=deltax;++f)
{
if(yr>=comp1) ggl_pltnib(srf->addr,addr,N_COLORS-1);
else ggl_pltnib(srf->addr,addr,(lim2+yr-4096)>>(13-COL_BITS));

yr+=deltay;

if(yr>=4096) { yr-=4096; addr+=inc_up; }
	else { addr+=inc_noup; }

}


yr=0;

addr=(x1+SCR_WIDTH*y1)+(inc_updn<<1); // upper pixel


for(f=0;f<=deltax;++f)
{

if(((lim2+yr-8192)>>(13-COL_BITS))>4) ggl_pltnib(srf->addr,addr,(lim2+yr-8192)>>(13-COL_BITS));

yr+=deltay;

if(yr>=4096) { yr-=4096; addr+=inc_up; }
	else { addr+=inc_noup; }

}


}

