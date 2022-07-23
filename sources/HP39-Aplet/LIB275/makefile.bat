@echo off
sasm -e -N SUPROM39

rplcomp lib275.s _LIB.A _LIB.EXT
echo 	NIBASC	\HP39BinH\     > _BDL.A
echo 	CON(2)	((Name)-(*)-2)/2 >> _BDL.A
echo 	NIBASC	\ARMToolbox39\        >> _BDL.A
echo Name                       >> _BDL.A

sasm -e -N _BDL
rplcomp lib275.s _LIB.A _LIB.EXT
SASM -e -N _LIB

echo TITLE ARMToolbox39					    > _BUILD.MN
echo OUTPUT __LIB.O					   >> _BUILD.MN
echo LLIST _.LR 					   >> _BUILD.MN
echo CONFIGURE ARMTbxConfig			   >> _BUILD.MN
echo NAME ARMToolbox 39 1.0 >> _BUILD.MN
echo ROMPHEAD _HEAD.A					   >> _BUILD.MN
echo REL _LIB.O 					   >> _BUILD.MN
echo SEARCH    SUPROM39.O 				   >> _BUILD.MN
echo TABLE _HASH.A					   >> _BUILD.MN
echo FINISH _END.A					   >> _BUILD.MN
echo END						   >> _BUILD.MN

makerom _BUILD.MN _BUILD.M


sasm -e -N _HEAD
sasm -e -N _HASH
sasm -e -N _END

echo TITLE ARMToolbox39					    > _LOADER.M
echo OUTPUT LIB275L.000				   >> _LOADER.M
echo OPTION CODE					   >> _LOADER.M
echo LLIST LIB275L.LR					   >> _LOADER.M
echo SUPPRESS XR					   >> _LOADER.M
echo SEARCH SUPROM39.O					   >> _LOADER.M
echo REL _BDL.O 					   >> _LOADER.M
echo REL __LIB.O					   >> _LOADER.M
echo CK LIB113 SYSEND113			   >> _LOADER.M

sload _BUILD.M
sload -H _LOADER.M

rem quit

REM CLEANUP
del _loader.m
del _build.mn
del _build.m
del *.o
del _head.a
del _hash.a
del _end.a
del _lib.ext
del _.lr
del _bdl.a
del lib275l.lr
del _lib.a

echo Done!

