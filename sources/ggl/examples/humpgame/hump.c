#include <hpgcc49.h>
#include <ggl.h>

#include "humpgraph/backgnd.c"
#include "humpgraph/humphrey.c"
#include "humpgraph/Testmap.c"
#include "humpgraph/enemies.c"

#define MAX_SPRITES 30
#define HUMP_MAXSIZE 36

#define NUM_LEVELS 1
#define NUM_FLIES 4
#define HUMP_LEFT   0x8
#define HUMP_RIGHT 0x10
#define HUMP_JUMP  0x80
#define HUMP_FALL  0x20
#define HUMP_DIE   0x40

#define ENEM_RIGHT 0x80

#define KB_MASKJUMP ( KB_MASK64(KB_A) | KB_MASK64(KB_G) | KB_MASK64(KB_J) )


#define B_PAINTED  0x10
#define B_SPECIAL  0x40

typedef struct {
unsigned int widthheight;
int *data;
} animphase;

typedef struct {
	int x,y;
	animphase *phase;
	int phasecount;
	int dead;
	int ticks;
	int *backsave;
	int backx,backy;
	int backwidth,backheight;
} sprite;

typedef struct {
	int x,y;
	animphase *phase;
	int phasecount;
	int dead;
	int ticks;
	int *backsave;
	int backx,backy;
	int backwidth,backheight;
	int *shsave;
	int shx,shy;
	int shwidth,shheight;
	int *trajectory;
	int incx,incy;
} enemy;


// BACKGROUND GRAPHICS
int **BackList;
// MAIN CHARACTER GRAPHICS
animphase *HumpList;
sprite Humphrey;
sprite Shade;
int xoffset,yoffset;
int xblock,yblock;
int jumplength;



// MAPS
char **LevelMaps;
// SPRITES
animphase *EnemList;
enemy *Enemies;
int EnemNum;

// COLLISION DETECTION 
int Collision;


// GAME MAIN SURFACE
gglsurface Fullmap;
char *CurrentMap=NULL;
int Mapwidth,Mapheight;
int MapStartx,MapStarty;
int MapCount,MapLimit;

void init_sprites()
// INITIALIZE MAPS AND SPRITES
{
	int f;
	gglsurface block;

	BackList=(int **)malloc(256*sizeof(int *));
	// NON-WALKABLE SURFACES
	BackList[0]=(int *)&Blk_block;	// block
	BackList[1]=(int *)&Blk_sky1;	// sky
	BackList[2]=(int *)&Blk_sky2;	// sky2
	BackList[3]=(int *)&Blk_sky3;	// sky3

	// GAME SURFACE
	BackList[4]=(int *)&Blk_normal;	// NORMAL

	// 5 TO 15 RESERVED FOR DIFFERENT TYPES OF FLOOR


	// PAINTED FLOOR
	block.x=block.y=0;
	block.width=12;

	for(f=4;f<5;++f)
	{
	block.addr=BackList[B_PAINTED+f]=(int *)malloc(12*12/2);	// NORMAL
	memcpy(BackList[B_PAINTED+f],BackList[f],12*12/2);
	ggl_filter(&block,12,12,2,&ggl_fltdarken);
	}

	// SPECIAL BLOCKS

	BackList[B_SPECIAL+0]=(int *)&Blk_trap;	// DEATH
	BackList[B_SPECIAL+1]=(int *)&Blk_trap2;	// DEATH

	BackList[B_SPECIAL+4]=(int *)&Blk_left;	// PUSHES LEFT
	BackList[B_SPECIAL+5]=(int *)&Blk_left2;	// ANIMATION
	BackList[B_SPECIAL+6]=(int *)&Blk_left3;	// ANIMATION

	BackList[B_SPECIAL+8]=(int *)&Blk_left3;	// PUSHES RIGHT
	BackList[B_SPECIAL+9]=(int *)&Blk_left2;	// ANIMATION
	BackList[B_SPECIAL+10]=(int *)&Blk_left;	// ANIMATION

	BackList[B_SPECIAL+12]=(int *)&Blk_up3;	// PUSH UP
	BackList[B_SPECIAL+13]=(int *)&Blk_up2;	// PUSH UP
	BackList[B_SPECIAL+14]=(int *)&Blk_up;	// PUSH UP

	BackList[B_SPECIAL+16]=(int *)&Blk_up;	// PUSH DOWN
	BackList[B_SPECIAL+17]=(int *)&Blk_up2;	// PUSH
	BackList[B_SPECIAL+18]=(int *)&Blk_up3;	// PUSH

	BackList[B_SPECIAL+20]=(int *)&Blk_skull;	// SKULL
	BackList[B_SPECIAL+21]=(int *)&Blk_skull2;
	// UPPER BITS RESERVED FOR ANIMATIONS




	// INITIALIZE MAPS
	LevelMaps=(char **)malloc(NUM_LEVELS*sizeof(int **));

	LevelMaps[0]=(char *)&Level1;

	// INITIALIZE GAME SURFACE
	Fullmap.addr=NULL;
	Fullmap.width=0;
	Fullmap.x=0;
	Fullmap.y=0;

	// INITIALIZE MAIN CHARACTER SPRITES

	HumpList=(animphase *)malloc(256*sizeof(animphase));


	HumpList[0].data=(int *)&HumpStop;
	HumpList[0].widthheight=0x000c000c;
	HumpList[HUMP_RIGHT].data=(int *)&HumpRun1;
	HumpList[HUMP_RIGHT].widthheight=0x000c000c;
	HumpList[HUMP_RIGHT+1].data=(int *)&HumpRun2;
	HumpList[HUMP_RIGHT+1].widthheight=0x000c000c;
	HumpList[HUMP_LEFT].data=(int *)&HumpRun1r;
	HumpList[HUMP_LEFT].widthheight=0x000c000c;
	HumpList[HUMP_LEFT+1].data=(int *)&HumpRun2r;
	HumpList[HUMP_LEFT+1].widthheight=0x000c000c;
	HumpList[HUMP_JUMP].data=(int *)&HumpJump1;
	HumpList[HUMP_JUMP].widthheight=0x0014000e;
	HumpList[HUMP_JUMP+1].data=(int *)&HumpJump2;
	HumpList[HUMP_JUMP+1].widthheight=0x00240015;
	HumpList[HUMP_JUMP+2].data=(int *)&HumpJump3;
	HumpList[HUMP_JUMP+2].widthheight=0x00240015;
	HumpList[HUMP_JUMP+4].data=(int *)&HumpJump1;
	HumpList[HUMP_JUMP+4].widthheight=0x0014000e;

	HumpList[HUMP_FALL].data=(int *)&HumpFall1;
	HumpList[HUMP_FALL].widthheight=0x000e000a;
	HumpList[HUMP_FALL+1].data=(int *)&HumpFall2;
	HumpList[HUMP_FALL+1].widthheight=0x000a0007;

	HumpList[HUMP_DIE+1].data=(int *)&HumpDie1;
	HumpList[HUMP_DIE+1].widthheight=0x000c000c;
	HumpList[HUMP_DIE+2].data=(int *)&HumpDie2;
	HumpList[HUMP_DIE+2].widthheight=0x000c000c;
	HumpList[HUMP_DIE+3].data=(int *)&HumpDie3;
	HumpList[HUMP_DIE+3].widthheight=0x000c000c;
	HumpList[HUMP_DIE+4].data=(int *)&HumpDie4;
	HumpList[HUMP_DIE+4].widthheight=0x000c000c;

	// todo: ADD MORE HERE

	Humphrey.x=Humphrey.y=0;

	Humphrey.phase=&(HumpList[0]);
	Humphrey.phasecount=0;
	Humphrey.ticks=0;
	Humphrey.backsave=(int *)malloc(HUMP_MAXSIZE*HUMP_MAXSIZE/2);
	Humphrey.backwidth=0;

	// INITIALIZE SHADE
	Shade.backsave=(int *)malloc(HUMP_MAXSIZE*HUMP_MAXSIZE/2);
	Shade.backwidth=0;


	// INITIALIZE ENEMY SPRITES
	Enemies=(enemy *)malloc(MAX_SPRITES*sizeof(enemy));
	memset((void *)Enemies,0,MAX_SPRITES*sizeof(enemy));
	// ANIMATION PHASE LIST
	EnemList=(animphase *)malloc(256*sizeof(animphase));
	memset((void *)EnemList,0,256*sizeof(animphase));


	EnemList[0].data=(int *)&EnemFly1r;
	EnemList[0].widthheight=0x000c000c;
	EnemList[1].data=(int *)&EnemFly2r;
	EnemList[1].widthheight=0x000c000c;
	EnemList[ENEM_RIGHT+0].data=(int *)&EnemFly1;
	EnemList[ENEM_RIGHT+0].widthheight=0x000c000c;
	EnemList[ENEM_RIGHT+1].data=(int *)&EnemFly2;
	EnemList[ENEM_RIGHT+1].widthheight=0x000c000c;


	// CREATE EMPTY TEMPLATES
	for(f=0;f<MAX_SPRITES;++f)
	{
	Enemies[f].dead=1; // SET ALL ENEMIES DEAD
	// ALLOCATE BACKFROUND SAVE AREA FOR ALL SPRITES
	Enemies[f].backsave=(int *)malloc(HUMP_MAXSIZE*HUMP_MAXSIZE/2);
	Enemies[f].shsave=(int *)malloc(HUMP_MAXSIZE*HUMP_MAXSIZE/2);
	}

	EnemNum=0;

}

// GGL OPERATOR FOR SHADE CREATION

unsigned int ggl_opshade(unsigned int dest,unsigned int src, int tcol)
{
	// DARKEN BY tcol WITH MASK
	// MASKED OPERATION
	// TRANSPARENT COLOR FIXED TO 1

	register int f;
	register unsigned int res=0;
	for(f=0;f<8;++f,src>>=4,dest>>=4)
	{
		if((src&0xf)==1) res|=dest&0xf;
		else {
			if( ((dest&0xf)+tcol)>0xf) res|=0xf;
			else 	res|=(dest&0xf)+tcol;
		}
		res= (res>>4) | (res<<28);


	}
	return res;
}









void SaveAndDraw()
{
int f;
gglsurface enem;

enem.x=enem.y=0;


// SHADES FIRST

if(Humphrey.phasecount&HUMP_JUMP) {
// SHADE ONLY WHEN JUMPING
	int shadeoff=2;
	if((Humphrey.phasecount&3)>0) shadeoff+=6;
Shade.backheight=HumpList[HUMP_JUMP].widthheight&0xffff;
enem.width=Shade.backwidth=HumpList[HUMP_JUMP].widthheight>>16;
Shade.backx=Fullmap.x=Humphrey.x+18-Shade.backwidth/2+shadeoff;
Shade.backy=Fullmap.y=Humphrey.y+18-Shade.backheight/2+shadeoff;
enem.addr=Shade.backsave;
ggl_bitblt(&enem,&Fullmap,enem.width,Shade.backheight);
enem.addr=HumpList[HUMP_JUMP].data;
ggl_bitbltoper(&Fullmap,&enem,enem.width,Shade.backheight,4,&ggl_opshade);
}


// GROUND ENEMIES SECOND

for(f=NUM_FLIES;f<EnemNum;++f)
{
	if(Enemies[f].dead) { Enemies[f].backwidth=0; continue; }
	// SAVE BACKGROUND
	Enemies[f].backheight=Enemies[f].phase->widthheight&0xffff;
	enem.width=Enemies[f].backwidth=Enemies[f].phase->widthheight>>16;
	Fullmap.x=Enemies[f].backx=Enemies[f].x+12;
	Fullmap.y=Enemies[f].backy=Enemies[f].y+12;
	enem.addr=Enemies[f].backsave;
	ggl_bitblt(&enem,&Fullmap,enem.width,Enemies[f].backheight);
	// DRAW
	enem.addr=Enemies[f].phase->data;
	ggl_bitbltoper(&Fullmap,&enem,enem.width,Enemies[f].backheight,1,&ggl_opmask);
}

// MAIN CHARACTER

// SAVE BACKGROUND
if(Humphrey.dead && (Humphrey.phasecount==HUMP_DIE+5)) { Humphrey.backwidth=0; }
else {
enem.width=Humphrey.backwidth=Humphrey.phase->widthheight>>16;
Humphrey.backheight=Humphrey.phase->widthheight&0xffff;
Humphrey.backx=Fullmap.x=Humphrey.x+18-enem.width/2;
Humphrey.backy=Fullmap.y=Humphrey.y+18-Humphrey.backheight/2;
enem.addr=Humphrey.backsave;
ggl_bitblt(&enem,&Fullmap,enem.width,Humphrey.phase->widthheight&0xffff);
// DRAW
enem.addr=Humphrey.phase->data;
ggl_bitbltoper(&Fullmap,&enem,enem.width,Humphrey.phase->widthheight&0xffff,1,&ggl_opmask);
}


// AIR ENEMIES LAST

for(f=0;f<EnemNum && f<NUM_FLIES;++f)
{
	if(Enemies[f].dead) { Enemies[f].backwidth=0; continue; }
	// SAVE BACKGROUND
	Enemies[f].shheight=Enemies[f].backheight=Enemies[f].phase->widthheight&0xffff;
	enem.width=Enemies[f].shwidth=Enemies[f].backwidth=Enemies[f].phase->widthheight>>16;
	Fullmap.x=Enemies[f].shx=Enemies[f].x+12+6;
	Fullmap.y=Enemies[f].shy=Enemies[f].y+12+6;
	enem.addr=Enemies[f].shsave;
	ggl_bitblt(&enem,&Fullmap,enem.width,Enemies[f].shheight);
	// DRAW
	enem.addr=Enemies[f].phase->data;
	ggl_bitbltoper(&Fullmap,&enem,enem.width,Enemies[f].shheight,4,&ggl_opshade);

	Fullmap.x=Enemies[f].backx=Enemies[f].x+12;
	Fullmap.y=Enemies[f].backy=Enemies[f].y+12;
	enem.addr=Enemies[f].backsave;
	ggl_bitblt(&enem,&Fullmap,enem.width,Enemies[f].backheight);
	// DRAW
	enem.addr=Enemies[f].phase->data;
	ggl_bitbltoper(&Fullmap,&enem,enem.width,Enemies[f].backheight,1,&ggl_opmask);
}




}


void RestoreAll()
{
// RESTORE SAVED BACKGROUND FOR ALL SPRITES
	int f;
	gglsurface enem;


enem.x=enem.y=0;

	// ENEMIES IN REVERSE ORDER
for(f=( (EnemNum>NUM_FLIES)? NUM_FLIES-1:EnemNum-1);f>=0;--f)
	{
		if(Enemies[f].backwidth!=0) {
			Fullmap.x=Enemies[f].backx;
			Fullmap.y=Enemies[f].backy;
			enem.width=Enemies[f].backwidth;
			enem.addr=Enemies[f].backsave;
			ggl_bitblt(&Fullmap,&enem,Enemies[f].backwidth,Enemies[f].backheight);
			Enemies[f].backwidth=0;

		}
		if(Enemies[f].shwidth!=0) {
			Fullmap.x=Enemies[f].shx;
			Fullmap.y=Enemies[f].shy;
			enem.width=Enemies[f].shwidth;
			enem.addr=Enemies[f].shsave;
			ggl_bitblt(&Fullmap,&enem,Enemies[f].shwidth,Enemies[f].shheight);
			Enemies[f].shwidth=0;
		}
	}



// MAIN CHARACTER FIRST
	if(Humphrey.backwidth!=0) {
		Fullmap.x=Humphrey.backx;
		Fullmap.y=Humphrey.backy;
		enem.width=Humphrey.backwidth;
		enem.addr=Humphrey.backsave;
		ggl_bitblt(&Fullmap,&enem,Humphrey.backwidth,Humphrey.backheight);
		Humphrey.backwidth=0;
	}

	// ENEMIES IN REVERSE ORDER
	for(f=EnemNum-1;f>=NUM_FLIES;--f)
	{
		if(Enemies[f].backwidth!=0) {
			Fullmap.x=Enemies[f].backx;
			Fullmap.y=Enemies[f].backy;
			enem.width=Enemies[f].backwidth;
			enem.addr=Enemies[f].backsave;
			ggl_bitblt(&Fullmap,&enem,Enemies[f].backwidth,Enemies[f].backheight);
			Enemies[f].backwidth=0;

		}
	}


	// SHADE
		if(Shade.backwidth!=0) {
		Fullmap.x=Shade.backx;
		Fullmap.y=Shade.backy;
		enem.width=Shade.backwidth;
		enem.addr=Shade.backsave;
		ggl_bitblt(&Fullmap,&enem,Shade.backwidth,Shade.backheight);
		Shade.backwidth=0;
	}

}






gglsurface Screen;
int *LCDstate;

void start_graphics()
{
	// INITIALIZE GRAPHICS LIBRARY

	LCDstate=(int *)malloc(STATEBUFSIZE);
	ggl_save(LCDstate);
	ggl_initscr(&Screen);
	// CLEAR SCREEN
	ggl_rect(&Screen,0,0,132,79,0);
	ggl_setmode(Screen.addr);

}

void end_graphics()
{
	// CLOSE GRAPHICS LIBRARY
	ggl_restore(LCDstate);
	free((int *)sys_map_p2v((unsigned int)Screen.addr));
	free(LCDstate);
}

int getblocktype(int x,int y)
{
return (int) *(CurrentMap+y*Mapwidth+x);
}


int *getshadeaddr(int x,int y)
{

int cnt=0;
if(x>0) cnt=getblocktype(x-1,y)? 0:1;	// LEFT
if( (x>0) && (y>0) ) cnt+=getblocktype(x-1,y-1)? 0:2; //TOP-LEFT
if(y>0) cnt+=getblocktype(x,y-1)? 0:4; //TOP

switch(cnt)
{
	case 1:
		return (int *)&Shade_Left;
	case 2:
		return (int *)&Shade_Corner;
	case 3:
		return (int *)&Shade_LCont;
	case 4:
		return (int *)&Shade_Top;
	case 5:
	case 7:
		return (int *)&Shade_L;
	case 6:
		return (int *)&Shade_TCont;
	default:
		return NULL;
}


}




void drawmap(int map)
{
// DRAWS MAP INTO THE GAME SURFACE

	int i,j;
	char *ptr=LevelMaps[map];

	Mapwidth=(int) (*ptr);
	++ptr;
	Mapheight=(int) (*ptr);
	++ptr;
	MapStartx=(int) (*ptr);
	++ptr;
	MapStarty=(int) (*ptr);
	++ptr;
	MapStartx*=12;
	MapStarty*=12;

	if(CurrentMap!=NULL) free(CurrentMap);
	CurrentMap=(char *)malloc(Mapheight*Mapwidth*sizeof(char));
	memcpy(CurrentMap,ptr,Mapheight*Mapwidth*sizeof(char));


	MapLimit=MapCount=0;
	if(Fullmap.addr!=NULL) free(Fullmap.addr);

	Fullmap.addr=(int *)malloc( ( (Mapwidth+2)*(Mapheight+2))*144/2 );
	Fullmap.width=(Mapwidth+2)*12;

	gglsurface block,shade;
	block.width=shade.width=12;
	block.x=block.y=shade.x=shade.y=0;

	Fullmap.y=12;

	for(i=0;i<Mapheight;++i)
	{
		Fullmap.x=12;

		for(j=0;j<Mapwidth;++j)
		{
			if( (*ptr&0xf)>3 && !(*ptr&B_SPECIAL)) ++MapLimit;	// COUNT IF WALKABLE
			block.addr=BackList[(int)*ptr];
			ggl_bitblt(&Fullmap,&block,12,12);
			if( *ptr>3) {
				// PROJECT SHADES
				if( (shade.addr=getshadeaddr(j,i))!=NULL) ggl_bitbltoper(&Fullmap,&shade,12,12,8,&ggl_opshade);
			}
			Fullmap.x+=12;
			++ptr;

		}
		Fullmap.y+=12;
	}
}


void showmap(int x,int y)
{

	Screen.x=0;
	Screen.y=0;
	Fullmap.x=x+12;
	Fullmap.y=y+12;
	ggl_bitblt(&Screen,&Fullmap,100,72);

}



void mapenemies(int map)
{

	// todo: everything

// FOR TEST PURPOSES ONLY
	EnemNum=2;

	Enemies[0].x=20;
	Enemies[0].y=30;
	Enemies[0].incx=3;
	Enemies[0].incy=1;
	Enemies[0].phase=&EnemList[Enemies[0].phasecount];

	Enemies[0].dead=0;
	Enemies[1].x=40;
	Enemies[1].y=30;
	Enemies[1].incx=3;
	Enemies[1].incy=1;
	Enemies[1].phase=&EnemList[Enemies[0].phasecount];

	Enemies[1].dead=0;



}


void animenemies()
{

	int f,phase;

	for(f=0;(f<NUM_FLIES) && (f<EnemNum);++f)
	{
		if(!Enemies[f].dead) {

			// FOLLOW TRAJECTORY FOR FLIES
				Enemies[f].x+=Enemies[f].incx;
				Enemies[f].y+=Enemies[f].incy;
				if(Enemies[f].ticks>20) { Enemies[f].incy=-Enemies[f].incy; Enemies[f].ticks=0; }
				if(Enemies[f].x>(Mapwidth-1)*12) Enemies[f].incx=-abs(Enemies[f].incx);
					else {
					if(Enemies[f].x<0) { Enemies[f].incx=abs(Enemies[f].incx); }
					else {
				if((rand()&0x1f)==9) Enemies[f].incx=-Enemies[f].incx;
				}
				}
				if(Enemies[f].y>(Mapheight-1)*12) Enemies[f].incy=-abs(Enemies[f].incy);
				else {
					if(Enemies[f].y<0) { Enemies[f].incy=abs(Enemies[f].incy); }
				else {
				if((rand()&0x1f)==9) Enemies[f].incy=-Enemies[f].incy;
				}
				}
				if(Enemies[f].incx<0) Enemies[f].phasecount|=0x80;
				else Enemies[f].phasecount&=0x7f;

				phase=Enemies[f].phasecount;
				if( (phase&7)==7) phase&=0xf8;
				else phase++;
				if(EnemList[phase].data==NULL) phase&=0xf8;
				Enemies[f].phasecount=phase;
				Enemies[f].phase=&EnemList[phase];

				Enemies[f].ticks++;

		}

	}


}




// MAIN CHARACTER FUNCTIONS

void hump_left()
{
Humphrey.x-=2;
xoffset-=2;
if(xoffset<0) { xoffset+=12; xblock--; }
}

void hump_right()
{
Humphrey.x+=2;
xoffset+=2;
if(xoffset>11) { xoffset-=12; xblock++; }
}

void hump_up()
{
Humphrey.y-=2;
yoffset-=2;
if(yoffset<0) { yoffset+=12; yblock--; }
}

void hump_down()
{
Humphrey.y+=2;
yoffset+=2;
if(yoffset>11) { yoffset-=12; yblock++; }
}


void setblocktype(int x,int y,int type)
{
	gglsurface m;
	*(CurrentMap+y*Mapwidth+x)=(char)type;
	m.x=0;
	m.y=0;
	m.width=12;
	m.addr=BackList[type];
	Fullmap.x=(x+1)*12;
	Fullmap.y=(y+1)*12;
	ggl_bitblt(&Fullmap,&m,12,12);
	if( type>3 ) {

	if( (m.addr=getshadeaddr(x,y))!=NULL) ggl_bitbltoper(&Fullmap,&m,12,12,8,&ggl_opshade);
	}
}


int isokposition()
{
if(xblock<0) return 0;
if(xblock>=Mapwidth) return 0;
if((xoffset>0) && (xblock>=Mapwidth-1)) return 0;
if(yblock<0) return 0;
if(yblock>=Mapheight) return 0;
if((yoffset>0) && (yblock>=Mapheight-1)) return 0;

if(getblocktype(xblock,yblock)==0) return 0;
if( (xoffset>0) && (getblocktype(xblock+1,yblock)==0)) return 0;
if( (yoffset>0) && (getblocktype(xblock,yblock+1)==0)) return 0;
if( (xoffset>0) && (yoffset>0) && (getblocktype(xblock+1,yblock+1)==0)) return 0;
return 1;
}

int getmainblocktype()
{
int x=xblock,y=yblock;

if(xoffset>6) x++;
if(yoffset>6) y++;

return getblocktype(x,y);

}

void setmainblocktype(int type)
{
int x=xblock,y=yblock;

if(xoffset>6) x++;
if(yoffset>6) y++;
setblocktype(x,y,type);

}

void floorreaction()
{
	int type;

	type=getmainblocktype();
	if(type&B_SPECIAL) {

		// SPECIAL BLOCK REACTIONS

		if( (type&0x3e)==0) {	// CLOSED OR OPEN TRAP
			
			if( !(Humphrey.phasecount&HUMP_JUMP)) {
				// KILL THE CHARACTER
				
				setmainblocktype(B_SPECIAL+1);	// OPEN THE TRAP
				
				Humphrey.phasecount=HUMP_FALL;
				Humphrey.phase=&HumpList[Humphrey.phasecount];
				// CENTER CHARACTER IN MAIN BLOCK
				if(xoffset>6) ++xblock;
				if(yoffset>6) ++yblock;
				xoffset=0;
				yoffset=0;
				
				Humphrey.x=xblock*12;
				Humphrey.y=yblock*12;
				Humphrey.ticks=0;
				return;
				
			}
		}

		if( (type&0x3c)==4 ) { // PUSH LEFT

			if( !(Humphrey.phasecount&HUMP_JUMP)) {
				hump_left();
				hump_left();
				if(!isokposition()) { hump_right(); hump_right(); }
				return;
			}
			else jumplength=0;


		}

		if( (type&0x3c)==8 ) { // PUSH RIGHT
			if( !(Humphrey.phasecount&HUMP_JUMP)) {
				hump_right();
				hump_right();
				if(!isokposition()) { hump_left(); hump_left(); }
				return;
			}
			else jumplength=0;

		}
		if(  (type&0x3c)==12 ) { // PUSH UP
			if( !(Humphrey.phasecount&HUMP_JUMP)) {
				hump_up();
				hump_up();
				if(!isokposition()) { hump_down(); hump_down(); }
				return;
			}
			else jumplength=0;

		}
		if(  (type&0x3c)==16 ) { // PUSH DOWN
			if( !(Humphrey.phasecount&HUMP_JUMP)) {
				hump_down();
				hump_down();
				if(!isokposition()) { hump_up(); hump_up(); }
				return;
			}
			else jumplength=0;

		}
		if(  (type&0x3c)==20 ) { // SKULL
			if( !(Humphrey.phasecount&HUMP_JUMP)) {

				// UN-PAINT A REGION AROUND THE SKULL

				int xmin,ymin,xmax,ymax;
				int f,g,typ;
				xmin=xblock-3;
				ymin=yblock-3;
				if(xoffset>6) ++xmin;
				if(yoffset>6) ++ymin;
				xmax=xmin+6;
				ymax=ymin+6;

				if(xmin<0) xmin=0;
				if(xmax>=Mapwidth) xmax=Mapwidth-1;
				if(ymin<0) ymin=0;
				if(ymax>=Mapheight) ymax=Mapheight-1;

				for(f=xmin;f<=xmax;++f)
				{
					for(g=ymin;g<=ymax;++g)
					{
						typ=getblocktype(f,g);
						if( (typ& (B_SPECIAL | B_PAINTED)) ==B_PAINTED )
						{
							setblocktype(f,g,typ&0xf);
						}
					}
				}
		
				
				return;
			}

		}


	}
	else {

		if(! (Humphrey.phasecount&HUMP_JUMP)) {
	if(type<4) {	// FALL ON SPACE
		Humphrey.phasecount=HUMP_FALL;
		Humphrey.phase=&HumpList[Humphrey.phasecount];
		// CENTER CHARACTER IN MAIN BLOCK
		if(xoffset>6) ++xblock;
		if(yoffset>6) ++yblock;
		xoffset=0;
		yoffset=0;

		Humphrey.x=xblock*12;
		Humphrey.y=yblock*12;
		Humphrey.ticks=0;
		return;
	}
	if( (type&0xf)>3 ) { // IS WALKABLE SURFACE
		if((type&B_PAINTED)==0) { setmainblocktype(type|B_PAINTED); ++MapCount; }
	}

		}
	}
}


void flooranimation()
{

	int i,j;
	char *ptr=CurrentMap;

	for(i=0;i<Mapheight;++i)
	{

		for(j=0;j<Mapwidth;++j,++ptr)
		{

			if(*ptr&B_SPECIAL) {
				if( (*ptr&0x1c)<20 && (*ptr&0x1c)>0 ) {
						// ANIMATE CONVEYOR BELTS
					++(*ptr);
					if( ((*ptr)&3)==3 ) *ptr-=3;
					setblocktype(j,i,(int)*ptr);

				}
				if( (*ptr&0x1c)==20 ) {
						// ANIMATE SKULL
					setblocktype(j,i,(int) ((*ptr)^1));

				}

			}



		}
	}
}




void detectcollision()
{
	
	// DETECT ENEMY COLLISION

	int f;
	int x1,y1,x2,y2;
	int hx1,hx2,hy1,hy2;
	
	
	hx1=Humphrey.x+2;
	hy1=Humphrey.y+2;
	hx2=hx1+8;
	hy2=hy1+8;
	
	for(f=0;f<EnemNum;++f)
	{
		if(Enemies[f].dead==0) {
			
			x1=Enemies[f].x;
			y1=Enemies[f].y;
			x2=x1+(Enemies[f].phase->widthheight>>16);
			y2=y1+(Enemies[f].phase->widthheight&0xffff);
			
			// DETECT RECTANGLE INTERSECTION
			
			x1=max(x1,hx1);
			x2=min(x2,hx2);
			y1=max(y1,hy1);
			y2=min(y2,hy2);
			
			if(y2<=y1) continue;
			if(x2<=x1) continue;
			
				// KILL THE MAIN CHARACTER AND RETURN

			if( ((f<NUM_FLIES) && ((Humphrey.phasecount&(HUMP_JUMP|3))>HUMP_JUMP)) || ((f>=NUM_FLIES) && ( (Humphrey.phasecount&HUMP_JUMP)==0)) ) {
				
				Humphrey.dead=1;
				Humphrey.phasecount=HUMP_DIE;
				Humphrey.ticks=0;
				Humphrey.phase=&HumpList[Humphrey.phasecount];
				
				return;
			}
				
		}
		
		
		
	}
	
	
}





int main()
{


int x=0,y=0;
keymatrix a;

sys_intOff();
sys_slowOn();

start_graphics();
sys_setRTCTickPeriod(15);
init_sprites();

srand(0);

drawmap(0);

mapenemies(0);


Humphrey.x=MapStartx;
Humphrey.y=MapStarty;

xoffset=Humphrey.x%12;
xblock=Humphrey.x/12;
yoffset=Humphrey.y%12;
yblock=Humphrey.y/12;

do {


// READ KEYBOARD AND UPDATE POSITION

keyb_getmatrix(&a);
if(!((Humphrey.phasecount&HUMP_FALL)||Humphrey.dead)) {
if( (a.full & KB_MASKJUMP) && !(Humphrey.phasecount&HUMP_JUMP) )
{
	// START A JUMP
Humphrey.phasecount=HUMP_JUMP;
Humphrey.ticks=0;
jumplength=14;
}



if(a.full & KB_MASK64(KB_LF)) {
	a.full&=KB_MASKJUMP;
	hump_left();
	if(isokposition()) {

		if(!(Humphrey.phasecount&HUMP_JUMP)) {

			if(Humphrey.ticks>1) {
				Humphrey.phasecount+=1;
				Humphrey.phasecount&=1;
				Humphrey.phasecount|=HUMP_LEFT;
				Humphrey.phase=&HumpList[Humphrey.phasecount];
				Humphrey.ticks=0;
			}
		
	
		}
		
	}
	else {
		hump_right();
		// TODO: UPDATE ANIMATION PHASE - STOP
	}
}
if(a.full & KB_MASK64(KB_RT)) {
	a.full&=KB_MASKJUMP;
hump_right();
if(isokposition()) {
		if(!(Humphrey.phasecount&HUMP_JUMP)) {
			// TODO: UPDATE ANIMATION PHASE
	if(Humphrey.ticks>1) {
			Humphrey.phasecount+=1;
			Humphrey.phasecount&=1;
			Humphrey.phasecount|=HUMP_RIGHT;
			Humphrey.phase=&HumpList[Humphrey.phasecount];
			Humphrey.ticks=0;
	}

		}
}
else {
	hump_left();
	// TODO: UPDATE ANIMATION PHASE - STOP
}

}
if(a.full & KB_MASK64(KB_UP)) {
	a.full&=KB_MASKJUMP;
hump_up();
if(isokposition()) {
			// TODO: UPDATE ANIMATION PHASE
		if(!(Humphrey.phasecount&HUMP_JUMP)) {
	if(Humphrey.ticks>1) {
			if( Humphrey.phasecount& (HUMP_LEFT | HUMP_RIGHT) )	Humphrey.phasecount=Humphrey.phasecount^1;
			else Humphrey.phasecount=HUMP_RIGHT;
			Humphrey.phase=&HumpList[Humphrey.phasecount];
			Humphrey.ticks=0;
	}

		}
}
else {
	hump_down();
}
}
if(a.full & KB_MASK64(KB_DN)) {
	a.full&=KB_MASKJUMP;
hump_down();
if(isokposition()) {
		if(!(Humphrey.phasecount&HUMP_JUMP)) {
			// TODO: UPDATE ANIMATION PHASE
	// TODO: UPDATE ANIMATION PHASE - STOP
	if(Humphrey.ticks>1) {
			if( Humphrey.phasecount& (HUMP_LEFT | HUMP_RIGHT) )	Humphrey.phasecount=Humphrey.phasecount^1;
			else Humphrey.phasecount=HUMP_RIGHT;
			Humphrey.phase=&HumpList[Humphrey.phasecount];
			Humphrey.ticks=0;
	}

		}
}
else {
	hump_up();
	// TODO: UPDATE ANIMATION PHASE - STOP
}
}

}

		// UPDATE ANIMATION IN FALLS
if(Humphrey.phasecount&HUMP_FALL) {
	if(Humphrey.ticks>0) { ++Humphrey.phasecount; Humphrey.ticks=0; }
		if((Humphrey.phasecount&0xf)>1) {
				Humphrey.dead=1;
				Humphrey.phasecount=HUMP_DIE;
				Humphrey.ticks=0;
		}
		Humphrey.phase=&HumpList[Humphrey.phasecount];
}


		// UPDATE ANIMATION PHASE IN JUMPS
		if(Humphrey.phasecount&HUMP_JUMP) {

			if( (Humphrey.phasecount&7)==0 ) {
				if(Humphrey.ticks>1) {
					if(a.full & KB_MASKJUMP ) {
						// CHANGE TO FULL HEIGHT (LONG JUMP)
						Humphrey.phasecount=(1+(Humphrey.ticks&1))|HUMP_JUMP;
					}
					else {
						// SHORT JUMP, WAIT FOR MORE TICKS
						if(Humphrey.ticks>=3) {
							Humphrey.phasecount=0;
							Humphrey.ticks=0;

						}
					}
				}
				
			}
			else {
				if((Humphrey.phasecount&7)<4) {
					// STILL JUMPING
					if(a.full & KB_MASKJUMP ) {
						// KEEP JUMPING
						if(Humphrey.ticks<jumplength)	Humphrey.phasecount=(1+(Humphrey.ticks&1))|HUMP_JUMP;
						else { Humphrey.phasecount=4|HUMP_JUMP; Humphrey.ticks=0; } // START FALLING
					}
					else {
						// END JUMP NOW
						Humphrey.phasecount=4|HUMP_JUMP;
						Humphrey.ticks=0;
					}
					
				}
				else {
					if(Humphrey.ticks>1) {
					// END JUMP
					Humphrey.phasecount=0;
					Humphrey.ticks=0;

					}



				}
				
			}	
		
			Humphrey.phase=&HumpList[Humphrey.phasecount];

		}


		
		if(!Humphrey.dead) {
// DETECT FLOOR AND REACT
		if(!(Humphrey.phasecount&HUMP_FALL)) {
			// DONT DETECT FLOORS IF IT'S FALLING

		// FLOOR REACTION WHEN STANDING

			floorreaction();

		}
		}

// ANIMATE FLOOR
		flooranimation();

// UPDATE ENEMIES
		animenemies();


// CHECK FOR ENEMY COLLISION
		if(!Humphrey.dead) { 

			detectcollision();

		}

// REVIVE IF DEAD
		if(Humphrey.dead) {

			if(Humphrey.phasecount!=HUMP_DIE+5) {
			
				if( (Humphrey.ticks&1)==0) {
				Humphrey.phasecount++;
				Humphrey.phase=&HumpList[Humphrey.phasecount];
				}
			}

			if(Humphrey.ticks>20) {
			
			Humphrey.x=MapStartx;
			Humphrey.y=MapStarty;

			xoffset=Humphrey.x%12;
			xblock=Humphrey.x/12;
			yoffset=Humphrey.y%12;
			yblock=Humphrey.y/12;

			Humphrey.phasecount=0;
			Humphrey.phase=&HumpList[Humphrey.phasecount];

			Humphrey.ticks=0;

			// TODO: CHECK IF MORE LIVES AVAILABLE, DECREASE LIVES COUNTER

			Humphrey.dead=0;

			}


		}

// SCROLL SCREEN IF NEEDED
		if(Humphrey.dead) {

			if(Humphrey.ticks>14) {
				x=MapStartx-40;
				y=MapStarty-24;
			}

		}
		else {
			if(Humphrey.x-x>48) x+=2;
			if(Humphrey.x-x<40) x-=2;
			if(Humphrey.y-y>36) y+=2;
			if(Humphrey.y-y<24) y-=2;
		}
if(y<0) y=0;
if(y>=Mapheight*12-72) y=Mapheight*12-72;
if(x<0) x=0;
if(x>=Mapwidth*12-100) x=Mapwidth*12-100;


SaveAndDraw();
showmap(x,y);
Humphrey.ticks++;
RestoreAll();
sys_waitRTCTicks(1);

} while( !(a.hiword & KB_MASK32(KB_ON)));


end_graphics();
sys_setRTCTickPeriod(15);
sys_slowOff();
sys_intOn();

return 0;

}

