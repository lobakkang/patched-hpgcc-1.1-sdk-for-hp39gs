HP-GCC BINARY PACKAGE (+ LIBRARY SOURCES) FOR LINUX
---------------------------------------------------
Copyright (C) 2004,2005 The HP-GCC Development Team
http://www.hpgcc.org/
Version 1.1


0. License

1. Installation

2. Using hpgcc

3. Running C programs

4. Publishing C programs

5. Examples

6. Known bugs

7. Contact



0. License
----------

English:

This entire project, including the libraries, is released under the GPL. Under the terms of the GPL, you are required to release any software that uses these libraries under the GPL as well (eg, if you use hplib.a, you must make copies of your source code freely available).

Understandably, a large number of developers would prefer to keep their source code private. To solve this issue, additional rights are granted to non-profit developers. For non profit use only, you may use the libs without putting your code under the GPL.

Legalese:

HP-GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.
 
HP-GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with HP-GCC; see the file COPYING. 

As a special exception, you may use this file as part of a free software
library without restriction.  Specifically, if other files instantiate
templates or use macros or inline functions from this file, or you compile
this file and link it with other files to produce an executable, this
file does not by itself cause the resulting executable to be covered by
the GNU General Public License.  This exception does not however
invalidate any other reasons why the executable file might be covered by
the GNU General Public License.


1. Installation
----------------

Unpack the directory in c: to obtain c:\arm-hp.
To have access to all the tools, just add the following string to your PATH
variable:

(from DOS/windows) PATH=%PATH%;c:\arm-hp\bin
(from cygwin)      export PATH=$PATH:c:\\arm-hp\\bin   (note the \\ instead of \)
(from Linux)	   export PATH=$PATH:$HOME/arm-hp/bin (provided you installed in $HOME)

If you have downloaded cygwin then you might have an error (not always the case). 
Please remove the cygwin1.dll and cygz.dll that are inside the c:\arm-hp\bin directory to avoid it.

Give a first try to see if the tools work (here with cygwin):

maurin@mypc /cygdrive/c/arm-hp$ arm-elf-gcc
 arm-elf-gcc: no input files

And:

maurin@mypc /cygdrive/c/arm-hp$ elf2hp
Error, not enough arguments were given. Need 2 filenames.
Try elf2hp -h.

this means that the installation is OK since you can use the tools.

2. Using hpgcc
--------------

To compile you own programs, you need to call arm-elf-gcc with the following options:

-mtune=arm920t
-mcpu=arm920t
-mapcs-32
-fPIC
-mpic-register=r10
-msingle-pic-base
-mlittle-endian
-fomit-frame-pointer

if you are not using the ARM gcc version downloaded from the hpgcc site, you might also need:
-msoft-float

and optionally you can use:
-O3

for the paths use:
-I<your-include-path>
-L<your-lib-path>


To link your programs, use the following options for arm-elf-ld:

-L <your-lib-path>
-T <your-lib-path>/MMUld.script

and link against the following modules (it's best in the order shown):

<your-lib-path>/crt0.o
<all-your-object-files-here.o>
-lhpg
-lhplib
-lgcc

if you are not using the ARM ld version downloaded from the hpgcc site, you might also need:
-n


After obtaining the executable, you need to use elf2hp to convert it to a string suitable for
use in the calculator.
Use the option -k as in:

elf2hp <your-exe-here.exe> <your-hp-string.hp>

Done, your ARM C program is ready to use.




3. Running C programs
---------------------

Transfer the generated .hp (string) file to the calculator (via USB or using an SD card)

Put the program string on the calculator stack.

Use the command StrRUN from the ARM Toolbox library 275 (you need to have the library installed in
the calculator). This command will run the program.


4. Publishing C programs
------------------------

C programs can be published in many ways:

  a) As a program string (not very elegant...).
  b) As a stand-alone executable program. To create a stand-alone program, put the program
     string in the calculator stack and run either S->Prg or S->Exe commands from the ARM
     Toolbox. S->Prg will generate a program that needs the toolbox itself to be installed
     in order to run the program. S->Exe generates a true stand-alone program that can be run
     in any calculator without the ARM Toolbox (it adds 600 bytes to the size of the program).
  c) As a regular HP library. To create a library containing a C program, create an empty
     directory in the calculator and create the following variables:

     $ROMID    ->  Store a real with the ROMID number of your library
     $TITLE    ->  Store a string with the title of your library
     $CONFIG   ->  1 (store the real number 1, this is required)
     $VISIBLE  ->  {RunMyProg} (list containing the ID RunMyProg and any other command you
                    want to make visible to the final user)
     $HIDDEN   ->  {ARMCODE} (list containing the ARMCODE ID)
     RunMyProg ->  :: ' ID ARMCODE xPrgRUN ; (a simple SysRPL program to launch your C program)
                   or << ' ID ARMCODE PrgRUN >> (alternatively you can use a UserRPL program)
     ARMCODE   ->  Store your C program string in this variable

     Run the CRLIB command from the development library (lib 256 must be attached) to create
     your library. The library requires the ARM Toolbox to be installed in the target calculator
     in order to store the library in Port memory and run the program.

Advantages and disadvantages of each method:

  Method a) can be simple for the developer but final users may not know how to run the program.
  Method b) is better for final users. True stand-alone programs waste 600 bytes but they can
            be used without the Toolbox.
  Method c) is more complicated for both the developer and the final user. It has the advantage
            that the C program can be stored in Port2 (Flash ROM), leaving more free RAM. Only
            advantageous for large executables needing lots of free RAM.

5. Examples
-----------

To build the examples of hpg (you need to go to sources/hpg/examples and have make installed), 
simply type 'make'.
To build the other examples, download them in a proper directory and type:

maurin@mypc /cygdrive/c/arm-hp/examples/games$ arm-elf-gcc -mtune=arm920t -mcpu=arm920t -mapcs-32 -fPIC -mpic-register=r10 -msingle-pic-base -mlittle-endian -fomit-frame-pointer -Wall -O3 -I../../include -L../../lib  -c tetris.c
maurin@mypc /cygdrive/c/arm-hp/examples/games$ arm-elf-ld -L../../lib -T MMUld.script ../../lib/crt0.o  tetris.o -lhpg -lhplib -lgcc -o tetris.exe
maurin@mypc /cygdrive/c/arm-hp/examples/games$ elf2hp.exe -k tetris.exe tetris.hp


6. Known bugs
-------------




7. Contact
----------
Please write to the mailing-list of hpgcc hosted on sourceforge, or to one of the members.

