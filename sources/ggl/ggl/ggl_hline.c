#include <hpgcc49.h>

#include "gglpr.h"


void ggl_hline(gglsurface *srf,int y,int xl,int xr, int color)
{
	// PAINTS A HORIZONTAL LINE FROM xl TO xr BOTH INCLUSIVE
	// color=COLORED PATTERN TO USE, 8 PIXELS - 1 NIBBLE PER PIXEL
	//		 PATTERN IS ALWAYS WORD ALIGNED

	// RESTRICTIONS: xr>=xl
	//				 y MUST BE VALID

	register int *left=(int *)srf->addr+ ((y*srf->width+xl)>>3);
	register int *right=(int *)srf->addr+ ((y*srf->width+xr)>>3);
	int ml=ggl_leftmask(xl),mr=ggl_rightmask(xr);

	if(left==right) {
		// single word operation
		ml|=mr;
		*left=  (*left & ml) | (color & (~ml));
		return;
	}

	*left=  (*left & ml) | (color & (~ml));
	++left;
	while(left!=right)
	{
		*left=color;
		++left;
	}

	*right=  (*right & mr) | (color & (~mr));

}

