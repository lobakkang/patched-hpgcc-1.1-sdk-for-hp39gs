@@& ****************************************************************************
@@&
@@& Written by Ingo Blank, August 2004
@@& Donated to the HP-GCC Development Team
@@& Copyright (C) 2004 The HP-GCC Development Team
@@&
@@& ****************************************************************************
@@&
@@&
@@& This file is part of HP-GCC.
@@&
@@& HP-GCC is free software; you can redistribute it and/or modify
@@& it under the terms of the GNU General Public License as published by
@@& the Free Software Foundation; either version 2, or (at your option)
@@& any later version.
@@& 
@@& HP-GCC is distributed in the hope that it will be useful,
@@& but WITHOUT ANY WARRANTY; without even the implied warranty of
@@& MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
@@& GNU General Public License for more details.
@@& 
@@& You should have received a copy of the GNU General Public License
@@& along with HP-GCC; see the file COPYING. 
@@&
@@& As a special exception, you may use this file as part of a free software
@@& library without restriction.  Specifically, if other files instantiate
@@& templates or use macros or inline functions from this file, or you compile
@@& this file and link it with other files to produce an executable, this
@@& file does not by itself cause the resulting executable to be covered by
@@& the GNU General Public License.  This exception does not however
@@& invalidate any other reasons why the executable file might be covered by
@@& the GNU General Public License.
@@&
@@& ****************************************************************************



	.global kb_scan
	.global getkey
	.global gets
	

	
kb_scan:
	STMFD SP!, {R4-R5,LR}
	
	mov	r4,#0		@ col
kbs_1:
	mov	r5,#0		@ row
kbs_2:
	mov	r0,r4
	mov	r1,r5
	bl	keyb_isKeyPressed(PLT)
	tst	r0,#1
	bne	kbs_hit
	add	r5,r5,#1
	cmp	r5,#7
	bne	kbs_2
	add	r4,r4,#1
	cmp	r4,#8
	bne	kbs_1
	mov	r0,#0xFF
	b	kbs_q
kbs_hit:
	mov	r1,r5
	mov	r1,r1,lsl#4
	orr	r1,r1,r4
	mov	r1,r1,lsl#4
	bl	shiftState
	mov	r3,r0
	orr	r1,r1,r0
	mov	r0,r1
	
	mov	r1,r5
	mov	r2,r4
	
	@ r0 = composite RCS (Row,Column,Shift) nibbles
	@ r1 = row
	@ r2 = col
	@ r3 = shift
	
kbs_q:

	LDMFD SP!, {R4-R5,PC}
	
shiftState:
	STMFD SP!, {R1,LR}
	
	bl	keyb_isLS(PLT)
	teq	r0,#1
	beq	shst_q
	bl	keyb_isRS(PLT)
	teq	r0,#1
	moveq	r0,#2
	beq	shst_q
	bl	keyb_isAlpha(PLT)
	teq	r0,#1
	moveq	r0,#3
	
	@ r0 	== 0 -> no shift
	@	== 1 -> LS
	@	== 2 -> RS
	@	== 3 -> Alpha
	
shst_q:
	LDMFD SP!, {R1,PC}
	

getkey:
	STMFD SP!, {R1-R4,LR}
	
	@ r0 != 0 => wait for keypress

	
	mov	r4,r0
	
getch_w:
	bl	kb_scan
	teq	r0,#0xFF
	bne	getch_hit
	@moveq	r0,#0
	teq	r4,#0
	beq	getch_q
	b	getch_w
getch_hit:
	
	adr	r4,keytab
	mov	r3,r3,lsl#6	@ r3 = 64*shift
	add	r4,r4,r3
	mov	r1,r1,lsl#3	@ r1 = 8*row
	add	r4,r4,r1
	ldrb	r0,[r4,r2]
	mov	r4,r0
getch_debounce:
	bl	kb_scan
	teq	r0,#0xFF
	bne	getch_debounce
	
getch_q:
	mov	r0,r4
	
	LDMFD SP!, {R1-R4,PC}
	
gets:
	STMFD SP!, {R1-R6,LR}
	
	@ r0 = char * to buffer
	
	mov	r4,r0
	mov	r5,r4
	
	mov	r0,#1
	@ bl	set_speed(PLT) - changed by Al 9/10/04 - speed is programmers responsibility for now
	mov	r6,r0
	
gets_1:
	mov	r0,#1
	bl	getkey
	cmp	r0,#13
	beq	gets_q
	strb	r0,[r4],#1
	teq	r0,#8
	bne	gets_2
	sub	r2,r4,r5
	cmp	r2,#1
	subeq	r4,r4,#1
	subne	r4,r4,#2
gets_2:
	bl	putchar(PLT)
	b	gets_1
gets_q:
	mov	r0,#0
	strb	r0,[r4]
	
	mov	r0,r6
	@ bl	set_speed(PLT) - changed by Al 9/10/04 - speed is programmers responsibility for now 
	
	mov	r0,r5
	
	@ r0 = char * to buffer
	
	LDMFD SP!, {R1-R6,PC}
	
keytab:
	@ part #1 - unshifted
	
	.byte	8
	.byte	112	@ 'p'
	.byte	111	@ 'o'
	.byte	110	@ 'n'
	.byte	109	@ 'm'
	.byte	97	@ 'a'
	.byte	0
	.byte	107	@ 'k'
	.byte	117	@ 'u'
	.byte	116	@ 't'
	.byte	115	@ 's'
	.byte	114	@ 'r'
	.byte	113	@ 'q'
	.byte	98	@ 'b'
	.byte	0
	.byte	108	@ 'l'
	.byte	122	@ 'z'
	.byte	121	@ 'y'
	.byte	120	@ 'x'
	.byte	119	@ 'w'
	.byte	118	@ 'v'
	.byte	99	@ 'c'
	.byte	0
	.byte	0
	.byte	42	@ '*'
	.byte	57	@ '9'
	.byte	56	@ '8'
	.byte	55	@ '7'
	.byte	0
	.byte	100	@ 'd'
	.byte	0
	.byte	0
	.byte	45	@ '-'
	.byte	54	@ '6'
	.byte	53	@ '5'
	.byte	52	@ '4'
	.byte	0
	.byte	101	@ 'e'
	.byte	104	@ 'h'
	.byte	0
	.byte	43	@ '+'
	.byte	51	@ '3'
	.byte	50	@ '2'
	.byte	49	@ '1'
	.byte	0
	.byte	102	@ 'f'
	.byte	105	@ 'i'
	.byte	0
	.byte	13
	.byte	32	@ ' '
	.byte	46	@ '.'
	.byte	48	@ '0'
	.byte	0
	.byte	103	@ 'g'
	.byte	106	@ 'j'
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0

	@ part #2 - shifted (LS)
	
	.byte	8
	.byte	80	@ 'P'
	.byte	79	@ 'O'
	.byte	78	@ 'N'
	.byte	77	@ 'M'
	.byte	65	@ 'A'
	.byte	0
	.byte	75	@ 'K'
	.byte	85	@ 'U'
	.byte	84	@ 'T'
	.byte	83	@ 'S'
	.byte	82	@ 'R'
	.byte	81	@ 'Q'
	.byte	66	@ 'B'
	.byte	0
	.byte	76	@ 'L'
	.byte	90	@ 'Z'
	.byte	89	@ 'Y'
	.byte	88	@ 'X'
	.byte	87	@ 'W'
	.byte	86	@ 'V'
	.byte	67	@ 'C'
	.byte	0
	.byte	0
	.byte	42	@ '*'
	.byte	57	@ '9'
	.byte	56	@ '8'
	.byte	55	@ '7'
	.byte	0
	.byte	68	@ 'D'
	.byte	0
	.byte	0
	.byte	95	@ '_'
	.byte	54	@ '6'
	.byte	53	@ '5'
	.byte	52	@ '4'
	.byte	0
	.byte	69	@ 'E'
	.byte	72	@ 'H'
	.byte	0
	.byte	43	@ '+'
	.byte	51	@ '3'
	.byte	50	@ '2'
	.byte	49	@ '1'
	.byte	0
	.byte	70	@ 'F'
	.byte	73	@ 'I'
	.byte	0
	.byte	13
	.byte	44	@ ','
	.byte	46	@ '.'
	.byte	48	@ '0'
	.byte	0
	.byte	71	@ 'G'
	.byte	74	@ 'J'
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	
	@ part #3 - shifted (RS)
	
	.byte	8
	.byte	80	@ 'P'
	.byte	79	@ 'O'
	.byte	78	@ 'N'
	.byte	77	@ 'M'
	.byte	65	@ 'A'
	.byte	0
	.byte	75	@ 'K'
	.byte	85	@ 'U'
	.byte	84	@ 'T'
	.byte	83	@ 'S'
	.byte	82	@ 'R'
	.byte	81	@ 'Q'
	.byte	66	@ 'B'
	.byte	0
	.byte	76	@ 'L'
	.byte	90	@ 'Z'
	.byte	89	@ 'Y'
	.byte	88	@ 'X'
	.byte	87	@ 'W'
	.byte	86	@ 'V'
	.byte	67	@ 'C'
	.byte	0
	.byte	0
	.byte	42	@ '*'
	.byte	57	@ '9'
	.byte	56	@ '8'
	.byte	55	@ '7'
	.byte	0
	.byte	68	@ 'D'
	.byte	0
	.byte	0
	.byte	45	@ '-'
	.byte	54	@ '6'
	.byte	53	@ '5'
	.byte	52	@ '4'
	.byte	0
	.byte	69	@ 'E'
	.byte	72	@ 'H'
	.byte	0
	.byte	43	@ '+'
	.byte	51	@ '3'
	.byte	50	@ '2'
	.byte	49	@ '1'
	.byte	0
	.byte	70	@ 'F'
	.byte	73	@ 'I'
	.byte	0
	.byte	13
	.byte	32	@ ' '
	.byte	46	@ '.'
	.byte	48	@ '0'
	.byte	0
	.byte	71	@ 'G'
	.byte	74	@ 'J'
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0

	@ part #4 - shifted (Alpha)
	
	.byte	8
	.byte	80	@ 'P'
	.byte	79	@ 'O'
	.byte	78	@ 'N'
	.byte	77	@ 'M'
	.byte	65	@ 'A'
	.byte	0
	.byte	75	@ 'K'
	.byte	85	@ 'U'
	.byte	84	@ 'T'
	.byte	83	@ 'S'
	.byte	82	@ 'R'
	.byte	81	@ 'Q'
	.byte	66	@ 'B'
	.byte	0
	.byte	76	@ 'L'
	.byte	47	@ '/'
	.byte	89	@ 'Y'
	.byte	88	@ 'X'
	.byte	87	@ 'W'
	.byte	86	@ 'V'
	.byte	67	@ 'C'
	.byte	0
	.byte	0
	.byte	42	@ '*'
	.byte	57	@ '9'
	.byte	56	@ '8'
	.byte	55	@ '7'
	.byte	0
	.byte	68	@ 'D'
	.byte	0
	.byte	0
	.byte	45	@ '-'
	.byte	54	@ '6'
	.byte	53	@ '5'
	.byte	52	@ '4'
	.byte	0
	.byte	69	@ 'E'
	.byte	72	@ 'H'
	.byte	0
	.byte	43	@ '+'
	.byte	51	@ '3'
	.byte	50	@ '2'
	.byte	49	@ '1'
	.byte	0
	.byte	70	@ 'F'
	.byte	73	@ 'I'
	.byte	0
	.byte	13
	.byte	32	@ ' '
	.byte	46	@ '.'
	.byte	48	@ '0'
	.byte	0
	.byte	71	@ 'G'
	.byte	74	@ 'J'
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.byte	0

	

	
	
	
	

