
ARM ToolBox 2.0
----------------

by Claudio Lapilli


The ARM ToolBox is provided as is, with no warranty of any kind. Use it at your own risk. I am not responsilbe
for any memory losses and/or data corruption that this library may cause.


Changes from version 1.6:
-------------------------
* FixSto never fails when trying to store objects in flash.
* Strings can be stored in any port (0,1,2) without the need for creating a library
* Launcher accepts ID's pointing to ARM code to minimize memory movements
* Added support for calculator stack growth
* Simplified naming and operation
* Reduced size

Changes from version 1.21:
-------------------------
* All launchers now feature memory packer to launch C programs with maximum memory (up to 400 kbytes)

Changes from version 1.2:
------------------------
* Changes logic for allocating flash memory in FixSto. Now it seems to be more consistent with the STO
  behavior.

Changes from version 1.1:
------------------------
* Fixes bug in memory size
* Adds creation of standalone executables from ARM code strings

Changes from version 1.0:
------------------------

* Eliminated safety check in linkers to solve unpredictable behavior of ARMSAT/ARMSYS. The linkers now will
  crash the calculator if the ARM MMU is not at the default configuration. This will almost never happen
  since the default configuration is always active when in Saturn mode. However, if an ARM program messes up
  the MMU and the OS does not crash (which is nearly impossible, but...), then the ARM Toolbox will.

* Minor simplifications of the code in the launchers and the examples.

* Added example of how to publish ARM code.



What's in ARM ToolBox:
---------------------

ARM ToolBox is a collection of programs to help users and developers in using ARM code.
The programs in the library are for final users and for developers:

Programs for final users:

* FixSto:   Aligns the ARM code within a library and stores it in Port1 or Port2 for use.
            Libraries containing ARM code cannot be stored in Port memory using the regular
            STO or the Filer because the ARM code needs to be properly aligned before the
            library is stored in memory. This program does exactly that.

            Use:
                 Put the Library you want to install on level 2
                 Put the port number on level 1

                 Run FixSto

            Or for other types of code:
                 Put the code string on the stack level 2
                 Put a tagged ID on level 1

                 Run FixSto

           
* PrRUN:    Launches an ARM program. See the Library Format document for more information.

            Use:
                 Put ARM code (any form) on level 1

                 Run PrRUN

* FnRUN:    Calls an ARM function within a library. See the Library Format document for
            more information.

            Use:
                 Put ARM code (any form) on level 2
                 Put the function number on level 1 (hex string or system bint)

                 Run FnRUN

* ALIGN:    Aligns a string or hex string in a byte-boundary. Only (n-1) nibbles are moved,
            where n=size of the string. This means the string should have at least one
            padding nibble at the end. Useful to pass arguments to ARM functions.

* DEALIGN:  De-aligns a string or hex string in a byte-boundary. Only (n-1) nibbles are moved,
            where n=size of the string. This means the string should have at least one
            padding nibble at the end. It reverses the effect of ALIGN. It allows reading
            results returned by ARM code.


Programs for developers:

* PrLNK:    Obtains the address and the RAM requirements of an ARM program. See the
            Library Format document for more information.

            Use:
                 Put ARM code (any form) on level 2.
                 Put the function number on level 1 (hex string or system bint) - use
                 $FFFFF for ptimary entry point.

                 Run PrLNK

                 Leaves the ARM code on level 2 and the address+ram requirements on
                 level 1

* PrFIX:   Aligns ARM code contained in a string in TempOb or UserOb.

            Use:
                 Put ARM code (any form, but it must not be in flash memory or embedded
                 within a library in Port0) on level 1.

                 Run PrFIX

                 This program leaves the original argument on the stack.


            NOTE: Use with caution - Strings in TempOb and UserOb are moved frequently by the OS, so
                  the address obtained may not be valid if the system moves the code.

* ARMJmp    Calls ARM code.

             Use:
                 Put a hex string on the stack with the address+ram requirements (normally
                 obtained by calling PrLNK).

             Leaves the original argument on the stack. If the ARM program pushes an argument
             to the stack, it will be on level 2. Level 1 will always contain the address.


* S->Prg:   Converts a string containing ARM code to an executable format. The executable can only be
            run if the ARM Toolbox is installed in the calculator.

            Use:
                 Put the code string on level 1.

                 Run S->Prg

                 This routine leaves a program on the stack.

* S->Exe:   Converts a string containing ARM code to an executable format. As opposed to S->Prg, in
            this case the executable is absolutely stand-alone and DOES NOT require the ARM Toolbox
            to be installed. It adds approximately 1000 bytes to the total size.

            Use:
                 Put the code string on level 1.

                 Run S->Exe

                 This routine leaves a program on the stack.


Notes:
-----

The current version is a release 2.0 version. It was tested to the best of my knowledge but it still
may contain bugs.


Enjoy,

Claudio Lapilli
cdlapilli_AT(you know what to do with this)_hotmail_DOT_com



