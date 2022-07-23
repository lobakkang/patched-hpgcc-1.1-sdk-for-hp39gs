
#include <hpgcc49.h>

#include <ggl.h>

// GGL demo file


int main()
{

	// initialization sequence

	// create a buffer to save LCD state
	int *savestate=malloc(STATEBUFSIZE);

	// save LCD state
	ggl_save(savestate);


	// declare a surface
	gglsurface screen;

	// allocate memory for screen buffer
	// it can be done 'by hand' using
	// screen.addr=sys_map_v2p(sys_phys_malloc(BUFSIZE<<1));
	// address must be physical and continuous
	ggl_initscr(&screen);
	// to use with HPG, simply initialize HPG and replace the line above with:
	// ggl_gethpgscreen(&screen);

	// set 16-gray mode, not needed if used with HPG
	ggl_setmode(screen.addr);


	// clear the screen
	memsetw(screen.addr,0,SCREENBUFSIZE);

	// show all solid grey colors

	int f;

	for(f=0;f<16;++f)
	{
		ggl_rect(&screen,f*8,0,f*8+7,30,ggl_mkcolor(f));
	}

	// create a solid black pattern
	int black=ggl_mkcolor(15);


	// draw some buttons in the softmenu area

	ggl_hline(&screen,72,0,16,black);
	ggl_hline(&screen,79,0,16,black);
	ggl_vline(&screen,0,72,79,black);
	ggl_vline(&screen,16,72,79,black);
	// middle grey background
	ggl_rect(&screen,1,73,15,78,ggl_mkcolor(7));
	
	// shades and hilights
	ggl_hline(&screen,73,1,15,ggl_mkcolor(0));
	ggl_vline(&screen,1,73,78,ggl_mkcolor(0));
	ggl_hline(&screen,78,1,16,ggl_mkcolor(9));
	ggl_vline(&screen,15,73,78,ggl_mkcolor(9));

	// copy the button
	gglsurface source,dest;

	// fill the appropriate source surface
	// take the address of the screen buffer
	source.addr=screen.addr;
	// same width as the screen
	source.width=screen.width;
	// origin of the surface at the corner of the button
	source.x=0;
	source.y=72;
	
	// destination surface
	// take the screen address for a screen-to-screen bitblt
	dest.addr=screen.addr;
	dest.width=screen.width;
	// destination coordinates
	dest.x=16;
	dest.y=72;
	
	// use normal bitblt since areas overlap only horizontally
	ggl_bitblt(&dest,&source,17,8);
	dest.x+=16;
	ggl_bitblt(&dest,&source,17,8);
	dest.x+=16;
	ggl_bitblt(&dest,&source,17,8);


	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	// try some custom filter operations
	// choose the filter type (declaration is only for clarity,
	// not really needed)
	gglfilter funcptr=&ggl_fltdarken;

	dest.x=dest.y=0;

	ggl_filter(&dest,131,80,2,funcptr);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	ggl_filter(&dest,131,80,2,funcptr);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	funcptr=&ggl_fltlighten;

	ggl_filter(&dest,131,80,2,funcptr);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;
	
	ggl_filter(&dest,131,80,2,funcptr);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	// capture a region for mask test

	gglsurface transp;

	// allcate a buffer
	transp.addr=malloc(10000);
	// set an arbitrary width
	transp.width=128;
	transp.x=transp.y=0;

	// copy from the origin
	source.x=source.y=0;

	ggl_bitblt(&transp,&source,128,30);

	// 32 color test (pattern test)

	// 8x8 pattern buffer
	int pat2[8];

	for(f=0;f<31;++f)
	{
		ggl_mkcolor32(f,pat2);
		ggl_rectp(&screen,f*4,32,f*4+3,70,pat2);
	}


	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	// partial screen erase using rectangles

	ggl_rect(&screen,0,0,128,30,0);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;


	// user defined patterns test
	int pattern[8]={ 0x2468acef,
					0x468acef2,
					0x68acef24,
					0x8acef246,
					0xacef2468,
					0xcef2468a,
					0xef2468ac,
					0xf2468ace
	};



	for(f=0;f<=15;++f)
	{
		ggl_rect(&screen,f,f,100-f,60-f*2,ggl_mkcolor(f));
	}
	
	ggl_rectp(&screen,f,f,100-f,60-f*2,pattern);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;


	// screen motion demo

	dest.y=16;
	dest.x=0;

	source.y=16;

	for(f=50;f>10;--f)
	{
		source.x=f;
		dest.x=f-1;
		ggl_bitblt(&dest,&source,30,20);
	}

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	// circular scroll demo

	// auxiliar surface
	gglsurface surf;
	
	source.x=dest.x=0;
	source.y=0;
	dest.y=59;

	surf.addr=malloc(10000);
	surf.x=surf.y=0;
	surf.width=100;

	

	while(!keyb_isAnyKeyPressed())
	{
	// obtain the area that will be rolled out
	ggl_bitblt(&surf,&source,100,1);
	// scroll the area 1 pixel up
	ggl_scrollup(&source,100,60,1);
	// copy back the line at the bottom to create circular scroll
	ggl_bitblt(&dest,&surf,100,1);
	}

	while(keyb_isAnyKeyPressed()) ;
	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	// horizontal scroll demo
	
	dest.y=0;
	source.y=0;
	source.x=99;
	dest.x=0;

	// change the width of the temporary surface to
	// store the vertical strip in a more compact way
	surf.width=1;
	while(!keyb_isAnyKeyPressed())
	{
		// get the strip from the right
		ggl_bitblt(&surf,&source,1,60);
		// scroll to the right
		ggl_scrollrt(&dest,100,60,1);
		// copy back the strip at the left
		ggl_bitblt(&dest,&surf,1,60);
	}

	while(keyb_isAnyKeyPressed()) ;
	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;


	// masked bitblt demo
	
	// restore the saved grey bands but selecting
	// a transparency operation

	ggloperator gop=&ggl_optransp;
	// set destination arbitrary position
	dest.x=0;
	dest.y=3;

	// arbitrary partial section to copy
	transp.x=0;
	transp.y=0;
	
	ggl_bitbltoper(&dest,&transp,128,30,12,gop);


	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	ggl_bitbltoper(&dest,&transp,128,30,8,gop);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	ggl_bitbltoper(&dest,&transp,128,30,4,gop);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;

	ggl_bitbltoper(&dest,&transp,128,30,0,gop);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;


	// clear the screen
	memsetw(screen.addr,0,SCREENBUFSIZE>>1);

	// initialize antialiased lines
	ggl_initaline();


	for(f=4;f<125;f+=10) {
	ggl_aline(&screen,128-f,77,f,3);
	}
	ggl_aline(&screen,2,2,126,2);
	ggl_aline(&screen,126,2,126,78);
	ggl_aline(&screen,126,78,2,78);
	ggl_aline(&screen,2,78,2,2);

	while(!keyb_isAnyKeyPressed()) ;
	while(keyb_isAnyKeyPressed()) ;



	// cleanup sequence

	// terminate antialiased lines
	ggl_endaline();

	// restore LCD state
	ggl_restore(savestate);


	// free temporary buffers
	free(surf.addr);
	free(transp.addr);
	free(savestate);

	// careful! free() can't take a physical address
	// so the screen buffer needs to be converted to virtual first
	free((void *)sys_map_p2v((int)screen.addr));

	return 0;
}

