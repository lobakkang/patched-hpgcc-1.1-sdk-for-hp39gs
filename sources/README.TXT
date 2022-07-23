HP-GCC sources tree
-------------------
Copyright (C) 2004 The HP-GCC Development Team
http://hpgcc.sourceforge.net/
Version 1.0


1. CVS retrieval

2. Required tools

3. Building process for sources tree and elf2hp

4. Examples

5. Known bugs

6. Using hpgcc

7. Running C programs

8. Publishing C programs

9. Contact



1. CVS retrieval
----------------
You can download the lattest CVS sources from our cvs page hosted on sourceforge. Please see
http://sourceforge.net/cvs/?group_id=115846 for an explanation of CVS checkout. Two modules
are required : at least the "elf2hp" module and the "sources" modules.

- download the CVS tree of sources in a CVS dir.
- download the CVS tree of elf2hp in the previous CVS
dir.
Now you should have a structure like:
CVS + elf2hp
    |
    + sources


2. Required tools
-----------------
To build the tree, you need a Un*x like environment such as cygwin for windows or linux. You
also need gcc and binutils for arm-elf with soft-fpu architecture. You can check
http://hpgcc.sourceforge.net/ to find precompiled components for windows.

In case you don't have them, you must download the source package of binutilsxxx.tar.bz2  and
gcc-core-3XX.tar.bz2 from gnu.org. You also need the following utilities to build gcc  and
binutils (ready to use on your platform): gcc, make, flex and bison.

To build the ARM toochain for soft-fpu (HP49g+, armv4t arch). Please follow the next steps:

*Run a bash shell.

mkdir c:/arm-hp
cd c:/arm-hp
mkdir bin
mkdir build
cd build

*Put binutilsxxx.tar.bz2, gcc-core-3XX.tar.bz2 in build directory.

tar xjvf binutilsxxx.tar.bz2
tar xjvf gcc-3XX.tar.bz2

cd binxxx
./configure --target=arm-elf --prefix=c:/arm-hp
make all
make install
export PATH=$PATH/cygdrive/c/arm-hp/bin

cd ..
cd gccxxx
./configure --target=arm-elf --prefix=c:/arm-hp --with-arch=armv4t --with-float=soft --with-newlib --enable-softfloat --disable-thread --disable-shared --disable-win32-registry --disable-nls
make all
make install

It's finished. Only gcc is made at this stage. If you want to try the newlib from redhat, download 
and unpack it, then:

./configure --target=arm-elf --prefix=c:/arm-hp --with-arch=armv4t --with-float=soft --enable-softfloat --disable-thread --disable-shared
make all
make install

Now you can remove the 'build' directory under c:\arm-hp.
To have access to all the tools, just add the following string to your PATH
variable:
(from DOS/windows) PATH=%PATH%;c:\arm-hp\bin
(from cygwin)      export PATH=$PATH:c:\\arm-hp\\bin   (note the \\ instead of \)

libgcc.a and libm.a are now used by gcc.



3. Building process for sources tree and elf2hp
-----------------------------------------------

First, you need the following directory structure:

CVS + elf2hp
    |
    + include
    |
    + lib 
    |
    + sources
	
The elf2hp directory has the CVS files retrieved for elf2hp module.
The lib folder is where the .a and .o files are copied during the building process. 
The include folder is where the .h files are copied during the building process.
The sources directory has the CVS files retrieved for sources module.
The filenames are case sensitive.


The makefile in sources can build the correct directory structure if it does not exist.
To make it, type from a cygwin bash shell:

maurin@mypc/home/maurin$ cd /CVS; cd sources
maurin@mypc/CVS/sources$ make directories



To build the elf2hp binary, you need the ELFIO library. Go inside the elf2hp directory and
untar the ELFIO library.

maurin@mypc/CVS/sources$ cd ../elf2hp
maurin@mypc/CVS/elf2hp$ tar xvzf ELFIO-1.0.0.tar.gz

Then install it:

maurin@mypc/CVS/elf2hp$ cd ELFIO-1.0.0
maurin@mypc/CVS/elf2hp/ELFIO-1.0.0$ ./configure
maurin@mypc/CVS/elf2hp/ELFIO-1.0.0$ make && make install

Finally, compile elf2hp:

maurin@mypc/CVS/elf2hp/ELFIO-1.0.0$ cd ..
maurin@mypc/CVS/elf2hp$ make clean; make

If you have downloaded the cygwin dll then you might have an error. Please remove the
cygwin1.dll and cygz.dll that are inside elf2hp directory to avoid it.


To compile the sources tree of HPgcc:

maurin@mypc/CVS/elf2hp$ cd ../sources
maurin@mypc/CVS/sources$ make install

Now you have lib/ and include/ with the proper files.



4. Examples
-----------


To build the examples of hpg (you need to go to sources/hpg/examples), simply type 'make'.
To build the tetris example, download it in a proper directory and type:

maurin@mypc/CVS/example$ arm-elf-gcc -mtune=arm920t -mcpu=arm920t -mapcs-32 -fPIC -mpic-register=r10 -msingle-pic-base -mlittle-endian -fomit-frame-pointer -Wall -O3 -I../include -L../lib  -c tetris.c
maurin@mypc/CVS/example$ arm-elf-ld -L../lib -T MMUld.script ../lib/crt0.o  tetris.o -lhplib -lhpmath -lgcc -o tetris.exe
maurin@mypc/CVS/example$ ../elf2hp/elf2hp.exe -k tetris.exe tetris.hp


5. Known bugs
-------------

It seems that you must have at least 1 read-only string in your elf executable to avoid the
relocation bug of ld. To avoid it, add a "BUG" string inside your function.

Example:

int main()
{
	char bugfix[] = "BUG";
	...
	return 0;
}


6. Using hpgcc
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
-lhplib
-lhpmath
-lhpg
-lgcc

if you are not using the ARM ld version downloaded from the hpgcc site, you might also need:
-n


After obtaining the executable, you need to use elf2hp to convert it to a string suitable for
use in the calculator.
Use the option -k as in:

elf2hp -k <your-exe-here.exe> <your-hp-string.hp>

Done, your ARM C program is ready to use.


7. Running C programs
---------------------

Transfer the generated .hp (string) file to the calculator (via USB or using an SD card)

Put the program string on the calculator stack.

Use the command StrRUN from the ARM Toolbox library (you need to have the library installed in
the calculator). This command will run the program.


8. Publishing C programs
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


9. Contact
----------
Please write to the mailing-list of hpgcc hosted on sourceforge, or to one of the members.

