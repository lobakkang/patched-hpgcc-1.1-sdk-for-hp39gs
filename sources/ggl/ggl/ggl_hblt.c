#include <hpgcc49.h>

#include "gglpr.h"

void ggl_hblt(int *dest,int destoff,int *src,int srcoff, int npixels)

{

// COPIES npixels NIBBLES FROM src TO dest
// dest AND src ARE WORD ALIGNED ADDRESSES
// destoff AND srcoff ARE OFFSETS IN NIBBLES (PIXELS) FROM dest AND src
// RESTRICTIONS:
//	npixels<=512 (NO CHECKS MADE HERE)


	int tempmem[HBLT_BUFFER];

	// CALCULATE ROTATION
	int rot= ((srcoff&7)-(destoff&7))*4;
	unsigned a,b;
	int *ptr=tempmem,*start=src+(srcoff>>3),*end=src+((srcoff+npixels-1)>>3);

	// FIRST STAGE: COPY AND ROTATION

	++end;
	if(rot<0) {
		// ROTATION RIGHT
		rot=-rot;
		while(start<=end)
		{
			a=*start;
			*ptr= (a<<rot) | (b>>(32-rot));
			b=a;
			++ptr;
			++start;
		} 
	}
	else if(rot>=0) {
		// ROTATION LEFT
		b=*start;
		++start;
		while(start<=end)
		{
			a=*start;
			*ptr= (b>>rot) | (a<<(32-rot));
			b=a;
			++ptr;
			++start;
		} 
	}


	// SECOND STAGE: MASK AND UPDATE

	int ml=ggl_leftmask(destoff),mr=ggl_rightmask(destoff+npixels-1);
	ptr=tempmem;
	start=dest+(destoff>>3);
	end=dest+((destoff+npixels-1)>>3);

	if(start==end) {
		// single word operation
		ml|=mr;
		*start=  (*start & ml) | (*ptr & (~ml));
		return;
	}

	*start= (*start & ml) | (*ptr & (~ml));
	++start;
	++ptr;

	while(start!=end)
	{
		*start=*ptr;
		++start;
		++ptr;
	}

	*start= (*start & mr) | (*ptr & (~mr));

}
