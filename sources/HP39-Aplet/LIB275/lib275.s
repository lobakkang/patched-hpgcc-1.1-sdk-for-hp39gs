**********************************************************
*                 ARM Toolbox for HP39G+
**********************************************************

xROMID 113

 TITLE ARMToolbox39

**********************************************************
*          FIRST ROMP = PrRUN
**********************************************************

ASSEMBLE
     CON(1) 8
RPL
xNAME PrRUN

** LAUNCHES ARM CODE
** Entry:
**       ARM Code on stack, in CSTR, HXS, CODE or LIBDATA

INCLUDE SEXE.S


**********************************************************
*          SECOND ROMP = ShSPLASH
**********************************************************


ASSEMBLE
     CON(1) 8
RPL
xNAME ShSPLASH
::

** SHOWS CUSTOM SPLASH SCREEN
** Entry:
**       	$ "Customized Title"
**			$ "by Author"
**			GROB
**		    X_position for GROB
**		    Y_position for GROB



	TURNMENUOFF
	HARDBUFF
	ZEROZERO BINT_131d SIXTYFOUR
	GROB!ZERODRP

	HARDBUFF
	UNROT
	GROB!

	DUPLEN$ #2* 66 SWAP#-
	SWAP $>grob SWAP THIRTYTWO
    HARDBUFF UNROT
	GROB!

	DUPLEN$ THREE #* 66 SWAP#-
	SIXTEEN Put5x7

;

ASSEMBLE
     CON(1) 8
RPL
xNAME HpgccABOUT
::
	TURNMENUOFF
	HARDBUFF
	ZEROZERO BINT_131d SIXTYFOUR
	GROB!ZERODRP

    GROB 0011A 11000E30008302F31CB0CB0CB08302F52E52E52E528302F22F02F02F028302302703703703C10930A308308300CF29F19308308300C719F2D15D10C100C10979C92D10C100E08C10C10D10C100E08C10C38C38C380E08C108588588580E0FC1002E026026000000000000000000000000000000000FFFFFFFFFFFFF5900000000000000000FFFFFFFFFFFA4000
	HARDBUFF
	SIXTYEIGHT
	FORTYSEVEN
	GROB!

    $ "HPGCC Aplet Builder"
	NINE ZERO Put5x7
	NINE NINE 123 NINE LINEON
	$ "by HPGCC Team:"
	$>grob HARDBUFF ZERO EIGHTEEN GROB!
	$ "    Al Borowski"
	$>grob HARDBUFF ZERO TWENTYFOUR GROB!
	$ "    Benjamin Maurin"
	$>grob HARDBUFF ZERO THIRTY GROB!
	$ "    Chris Smith"
	$>grob HARDBUFF ZERO THIRTYSIX GROB!
	$ "    Claudio Lapilli"
	$>grob HARDBUFF ZERO FORTYTWO GROB!
	$ "    Ingo Blank"
	$>grob HARDBUFF ZERO FORTYEIGHT GROB!

    $ "BACK" MakeInvLabel HARDBUFF ZERO FIFTYSIX GROB!

;

NULLNAME ARMTbxConfig
::
 # 113 TOSRRP
 ;
