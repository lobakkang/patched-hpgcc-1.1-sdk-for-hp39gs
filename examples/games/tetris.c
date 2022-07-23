//------------------------------------------------------------------
/** tetris.c:
 * Tetris demo of HPGE/HPGCC program
 *
 * \author	Maurin Benjamin
 * \date	12/08/04
 * \version	1.0
 * 
 * Log:\n
 * - 12/08/04 First public version

$Header: /cvsroot/hpgcc/examples/games/tetris.c,v 1.6 2005/04/04 13:09:10 alborowski Exp $

 */
//------------------------------------------------------------------

// Copyright (C) 2004 Benjamin Maurin

//
// This file is part of HP-GCC.

//
// HP-GCC is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
// 
// HP-GCC is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with HP-GCC; see the file COPYING. 

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

// Written by Nathan Sidwell, Codesourcery LLC, <nathan@codesourcery.com>
//------------------------------------------------------------------



#include <hpgcc49.h>
#include <hpgraphics.h>

#define TABLE_X 13
#define TABLE_Y 20

#define NB_PIECES 10



//! The table containing the blocks
unsigned char Table[TABLE_Y][TABLE_X];


//! A 4x4 pixels sprite block
unsigned char filled_block[2]={0xFF,0xFF};
//! A 4x4 pixels sprite block
unsigned char piece_block[2]={0x9F,0xF9};


//! The structure of a piece
typedef struct
{
	unsigned char block_representation[4][4];
	unsigned char size_x;
	unsigned char size_y;
} piece;


int			level = 0;

int			speed = 400;

int			score=0;

int			lines=0;


//! number of ! pieces in the tetris puzzle
piece Pieces[NB_PIECES];


//! Current piece of the puzzle
piece		Current;

//! Next piece of the puzzle
int			Next;



//! General QUIT flag
int			Continu=1;


//! Current horizontal direction
int			Hdirection=0;


//! Need to go down 1 pixel next turn because of game speed
int			Timeout=0;


//! position in pixels
int			Posx, Posy;





void Init_Pieces(piece *_pieces)
{
	unsigned int i,j,k;

	for(k=0; k<NB_PIECES; k++)
	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
		_pieces[k].block_representation[i][j] = 0;

	// A 2x2 square block structure
	_pieces[0].size_y = 2;
	_pieces[0].size_x = 2;
	_pieces[0].block_representation[0][0] = 1;
	_pieces[0].block_representation[1][0] = 1;
	_pieces[0].block_representation[0][1] = 1;
	_pieces[0].block_representation[1][1] = 1;

	// A 4x1 bar structure
	_pieces[1].size_y = 4;
	_pieces[1].size_x = 3;
	_pieces[1].block_representation[0][1] = 1;
	_pieces[1].block_representation[1][1] = 1;
	_pieces[1].block_representation[2][1] = 1;
	_pieces[1].block_representation[3][1] = 1;

	// A 3x2 right L structure
	_pieces[2].size_y = 3;
	_pieces[2].size_x = 3;
	_pieces[2].block_representation[0][1] = 1;
	_pieces[2].block_representation[1][1] = 1;
	_pieces[2].block_representation[2][1] = 1;
	_pieces[2].block_representation[2][2] = 1;


	// A 3x2 left L structure
	_pieces[3].size_y = 3;
	_pieces[3].size_x = 3;
	_pieces[3].block_representation[0][1] = 1;
	_pieces[3].block_representation[1][1] = 1;
	_pieces[3].block_representation[2][0] = 1;
	_pieces[3].block_representation[2][1] = 1;

	// A 3x2 left N structure
	_pieces[4].size_y = 3;
	_pieces[4].size_x = 2;
	_pieces[4].block_representation[0][0] = 1;
	_pieces[4].block_representation[1][0] = 1;
	_pieces[4].block_representation[1][1] = 1;
	_pieces[4].block_representation[2][1] = 1;

	// A 3x2 left N structure
	_pieces[5].size_y = 3;
	_pieces[5].size_x = 2;
	_pieces[5].block_representation[0][1] = 1;
	_pieces[5].block_representation[1][1] = 1;
	_pieces[5].block_representation[1][0] = 1;
	_pieces[5].block_representation[2][0] = 1;

	// A 1x1 . structure
	_pieces[6].size_y = 1;
	_pieces[6].size_x = 1;
	_pieces[6].block_representation[0][0] = 1;

	// A 3x3 T structure
	_pieces[7].size_y = 3;
	_pieces[7].size_x = 3;
	_pieces[7].block_representation[0][0] = 1;
	_pieces[7].block_representation[0][1] = 1;
	_pieces[7].block_representation[0][2] = 1;
	_pieces[7].block_representation[1][1] = 1;
	_pieces[7].block_representation[2][1] = 1;

	// A 4x2 U structure
	_pieces[8].size_y = 4;
	_pieces[8].size_x = 3;
	_pieces[8].block_representation[0][1] = 1;
	_pieces[8].block_representation[0][2] = 1;
	_pieces[8].block_representation[1][1] = 1;
	_pieces[8].block_representation[2][1] = 1;
	_pieces[8].block_representation[3][1] = 1;
	_pieces[8].block_representation[3][2] = 1;

	// A 3x3 + structure
	_pieces[9].size_y = 3;
	_pieces[9].size_x = 3;
	_pieces[9].block_representation[0][1] = 1;
	_pieces[9].block_representation[1][0] = 1;
	_pieces[9].block_representation[1][1] = 1;
	_pieces[9].block_representation[1][2] = 1;
	_pieces[9].block_representation[2][1] = 1;
}


void New_Piece(piece *_piece, piece *Pieces, int n)
{
	memcpy((char*)_piece, (char*)&Pieces[Next],
	sizeof(piece));
	Next = sys_getPWMCounter0()%n;
}


void RotateRight_Piece(piece *_piece)
{
	unsigned int i,j;
	unsigned char tmp[4][4];

	// rotate the block structure, store it in tmp
	for(i=0; i<_piece->size_y; i++)
		for(j=0; j<_piece->size_x; j++)
		{
			tmp[j][_piece->size_y-1-i] = _piece->block_representation[i][j];
		}
	// swap col&line attribute
	i = _piece->size_x;
	_piece->size_x = _piece->size_y;
	_piece->size_y = i;
	// copy tmp in piece
	for(i=0; i<_piece->size_y; i++)
		for(j=0; j<_piece->size_x; j++)
		{
			_piece->block_representation[i][j] = tmp[i][j];
		}
}

void RotateLeft_Piece(piece *_piece)
{
	unsigned int i,j;
	unsigned char tmp[4][4];

	// rotate the block structure, store in tmp
	for(i=0; i<_piece->size_y; i++)
		for(j=0; j<_piece->size_x; j++)
		{
			tmp[_piece->size_x-1-j][i] = _piece->block_representation[i][j];
		}
	// swap attribute structure
	i = _piece->size_x;
	_piece->size_x = _piece->size_y;
	_piece->size_y = i;
	// copy tmp in piece
	for(i=0; i<_piece->size_y; i++)
		for(j=0; j<_piece->size_x; j++)
		{
			_piece->block_representation[i][j] = tmp[i][j];
		}
}


int Test_Piece(piece* _piece, int px, int py)
{
	unsigned int i,j;
	for(i=0; i<_piece->size_y; i++)
		for(j=0; j<_piece->size_x; j++)
		{
			if (_piece->block_representation[i][j])
				if (testBlock4bitC(filled_block,4,px+j*4,py+i*4)) return(1);
		}
	return(0);
}

int DrawXORTest_Piece(piece* _piece, int px, int py)
{
	unsigned int i,j,collision=0;
	for(i=0; i<_piece->size_y; i++)
		for(j=0; j<_piece->size_x; j++)
		{
			if (_piece->block_representation[i][j])
				if (drawBlockXOR4bitC(piece_block,4,px+j*4,py+i*4)) collision=1;
		}
	return(collision);
}










void Draw_Table(unsigned char Table[TABLE_Y][TABLE_X])
{
	unsigned int i,j;
	for (i=0; i<TABLE_Y; i++)
		for (j=0; j<TABLE_X; j++)
		{
			if (Table[i][j]==1) drawBlockXOR4bitC(filled_block,4,j*4,i*4); // j*4 i*4
			if (Table[i][j]==2) drawBlockXOR4bitC(piece_block,4,j*4,i*4); // j*4 i*4
		}
}


void Add_One_Line_Table(unsigned char Table[TABLE_Y][TABLE_X])
{
	unsigned int i,j;
	for (i=0; i<TABLE_Y-2; i++)
	{
		for (j=1; j<(TABLE_X-1); j++)
			Table[i][j]=Table[i+1][j];
	}
	for (j=1; j<TABLE_X-1; j++)
	{
		Table[TABLE_Y-2][j]=1;
	}
	Table[TABLE_Y-2][sys_getPWMCounter0()%(TABLE_X-3)+1]=0;
}


void Init_Table(unsigned char Table[TABLE_Y][TABLE_X], int niveau)
{
	unsigned int i;
	for (i=0; i<TABLE_Y; i++)
		Table[i][0]=1;

	for (i=0; i<TABLE_Y; i++)
		Table[i][TABLE_X-1]=1;

	for (i=0; i<TABLE_X; i++)
		Table[TABLE_Y-1][i]=1;
/*	for (i=0;i<niveau; i++)
		Add_One_Line_Table(Table);*/
}


void Remove_One_Line_Table(unsigned int line, unsigned char Table[TABLE_Y][TABLE_X])
{
	unsigned int i,j;
	for (i=line; i>0; i--)
	{
		for (j=1; j<(TABLE_X-1); j++)
			Table[i][j]=Table[i-1][j];
	}
	for (j=1; j<(TABLE_X-1); j++)
		Table[0][j]=0;
}


void Remove_Lines_Table(unsigned char Table[TABLE_Y][TABLE_X])
{
	unsigned int i,j,flag,count=0;
	for (i=0; i<(TABLE_Y-1); i++)
	{
		flag=1;
		for (j=1; j<(TABLE_X-1); j++)
			flag=flag&&Table[i][j];
		if (flag) 
		{
			Remove_One_Line_Table(i,Table);
			count++;
		}
	}
	switch(count)
	{
		case 0:
			score+=1;
			break;
		case 1:
			score+=10;
			break;
		case 2:
			score+=20;
			break;
		case 3:
			score+=40;
			break;
		case 4:
			hpg_draw_text("4x Combo!!", 60, 50);
			score+=75;
			sys_waitRTCTicks(8); // wait a second
			break;
		default:
			hpg_draw_text("ERROR", 60, 60);
			keyb_waitKeyPressed();
			break;
	}
	level = score/100;
	lines += count;

	if (level<10)
		speed = 400-level*35;
	else if (level<16)
	{
		speed = 100-level*5;
		if (lines%10==0) Add_One_Line_Table(Table);
	}
	else 
	{
		speed=25;
		if (lines%10==0) Add_One_Line_Table(Table);
	}
}


void Read_Keys(void)
{
	//! LS RS Keypressed information
	static unsigned char	Key[2]={0,0};	//to store keypress information
	if (keyb_isON()) Continu=0;
	if (keyb_isLS())
	{
		if (!Key[0])
		{
			RotateLeft_Piece(&Current);
			// Verify that the rotation is possible:
			if (Test_Piece(&Current, Posx, Posy))
				RotateRight_Piece(&Current);
			
			Key[0]=1;
		}
	}
	else
		Key[0] = 0;
	if (keyb_isRS())
	{
		if (!Key[1])
		{
			RotateRight_Piece(&Current);
			// Verify that the rotation is possible:
			if (Test_Piece(&Current, Posx, Posy))
				RotateLeft_Piece(&Current);
			
			Key[1]=1;
		}
	}
	else
		Key[1] = 0;
/*
	if (isLeft()) Hdirection = -1;
	if (isRight()) Hdirection = 1;
	if (isDown()) Timeout = 1;
*/
	if (keyb_isKeyPressed(6,1)) Hdirection = -1;
	if (keyb_isKeyPressed(6,3)) Hdirection = 1;
	if (keyb_isKeyPressed(6,2)) Timeout = 1;
	if (keyb_isAlpha()) 
	{
		hpg_set_mode(hpg_stdscreen,HPG_MODE_XOR);
		while(keyb_isAlpha()) ;
		hpg_draw_text("PAUSE",20,0);
		while(!keyb_isAlpha()) ;
		hpg_draw_text("PAUSE",20,0);		
		while(keyb_isAlpha()) ;
		hpg_set_mode(hpg_stdscreen,HPG_MODE_PAINT);
	}
}


void Put_Piece_In_Table(piece *_piece, unsigned char table[TABLE_Y][TABLE_X], int y, int x)
{
	unsigned int i,j;
	for(i=0; i<_piece->size_y; i++)
		for(j=0; j<_piece->size_x; j++)
		{
			if (_piece->block_representation[i][j])
				table[y+i][x+j] = 2;
		}
}

void Screen_Init()
{
	char	buffer[20];
	hpg_clear();
	Draw_Table(Table);
	
	hpg_draw_text("HPGCC - TETRIS",60,10);
	hpg_draw_text("--------------",60,14);
	hpg_draw_text("Level:",80,30);
	itoa(level, buffer,10);
	hpg_draw_text(buffer,110,30);

	hpg_draw_text("Score:",80,36);
	itoa(score, buffer,10);
	hpg_draw_text(buffer,110,36);

	hpg_draw_text("Lines:",80,42);
	itoa(lines, buffer,10);
	hpg_draw_text(buffer,110,42);

	hpg_draw_text("(c)2004 Maurin B.",55,64);
	hpg_draw_text("      & Borowski Al",55,70);
}


int main(void)
{
	
	volatile unsigned short int	_ticks;
	int			_t1, i;
	unsigned int	_prev_x, _prev_y;
	char	buffer[20];


	Init_Table(Table,0);
	
	Init_Pieces(Pieces);
	
	Next = sys_getPWMCounter0()%6;
	
	New_Piece(&Current,Pieces,6);
	
	Posy	= 1*4;
	Posx	= 5*4;
	_prev_y	= Posy;
	_prev_x	= Posx;

	
	Screen_Init();
	DrawXORTest_Piece(Pieces+Next, 60, 30);
	DrawXORTest_Piece(&Current, _prev_x, _prev_y);
	
	sys_waitRTCTicks(8);
	
	_t1 = sys_getPWMCounter0();
	
	
	while(Continu)
	{
		for(i=0; i<(40000); i++) ; // This is because ARM is to fast !
		sys_LCDSynch();
		
		_ticks = sys_getPWMCounter0();
		if ((abs((int)_t1-(int)_ticks)>speed)||(abs((int)_ticks-(int)_t1)>speed))
		{
			_t1 = _ticks;
			Timeout = 1;
		}
		
/*		print(dbuffer,80,50);
		itoa(abs((int)_t1-(int)_ticks), dbuffer);
		print(dbuffer,80,50);
*/
		// clear the previous position on the screen
		DrawXORTest_Piece(&Current, _prev_x, _prev_y);

		Read_Keys();


		if (!Test_Piece(&Current,Posx+Hdirection,Posy))
		{
			Posx+=Hdirection;
/*			if (Posx<4) Posx=4;
			if (Posx>44) Posx=44;*/
		}
		
		if ((Posx%4)==0)
			Hdirection=0;

		if (Timeout)
		{
			//Look also if we are in a left/right movement
			if (Hdirection!=0)
			{
				// If so, finish it:
				while((Posx%4)!=0)
				{
					Posx += Hdirection;
					// draw on the screen
					DrawXORTest_Piece(&Current, Posx, Posy);
					for(i=0; i<(42000); i++) ; // This is because ARM is to fast !
					sys_LCDSynch();
					// clear the screen
					DrawXORTest_Piece(&Current, Posx, Posy);
				}
				Hdirection=0;
			}
			if (Test_Piece(&Current,Posx,Posy+1))
			{
				// Put the piece here
				DrawXORTest_Piece(&Current, Posx, Posy);
				Put_Piece_In_Table(&Current,Table, Posy/4, Posx/4);
				Remove_Lines_Table(Table);
				Screen_Init();
				if (level<6)
					New_Piece(&Current,Pieces,6);
				else if (level<10)
					New_Piece(&Current,Pieces,6+(level-5));
				else
					New_Piece(&Current,Pieces,10);
				Posx=5*4;
				Posy=1*4;
				DrawXORTest_Piece(Pieces+Next, 60, 30);
				sys_LCDSynch();
				sys_waitRTCTicks(1);

				if (Test_Piece(&Current,Posx,Posy))
				{
					hpg_clear();
					hpg_draw_text("YOUR SCORE:",6,6);
					itoa(score,buffer,10);
					hpg_draw_text(buffer,50,12);
					hpg_draw_text("YOUR LEVEL:",6,18);
					itoa(level,buffer,10);
					hpg_draw_text(buffer,50,24);
					hpg_draw_text("YOUR LINES:",6,30);
					itoa(level,buffer,10);
					hpg_draw_text(buffer,50,36);

					hpg_draw_text("Your grade:",6,56);
					if (score<300)	hpg_draw_text("Tetrineager",50,62);
					else if (score<500)	hpg_draw_text("Apprentice",50,62);
					else if (score<700)	hpg_draw_text("Padawan",50,62);
					else if (score<1000)	hpg_draw_text("Tetrimaster",50,62);
					else	hpg_draw_text("Still human?",50,62);

					sys_waitRTCTicks(10);
					while(!keyb_isON()) ;
					return(1);
				}
			}
			else
			{
				Posy+=1;
			}
			Timeout=0;
		}
				

		//Draws the piece at new location
		DrawXORTest_Piece(&Current,Posx,Posy);
		_prev_x = Posx;
		_prev_y = Posy;
		
		
	}

	
	return(1);
}






