//& ****************************************************************************
//&
//&
//& This file is part of HP-GCC.
//&
//& HP-GCC is free software; you can redistribute it and/or modify
//& it under the terms of the GNU General Public License as published by
//& the Free Software Foundation; either version 2, or (at your option)
//& any later version.
//& 
//& HP-GCC is distributed in the hope that it will be useful,
//& but WITHOUT ANY WARRANTY; without even the implied warranty of
//& MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//& GNU General Public License for more details.
//& 
//& You should have received a copy of the GNU General Public License
//& along with HP-GCC; see the file COPYING. 
//&
//& As a special exception, you may use this file as part of a free software
//& library without restriction.  Specifically, if other files instantiate
//& templates or use macros or inline functions from this file, or you compile
//& this file and link it with other files to produce an executable, this
//& file does not by itself cause the resulting executable to be covered by
//& the GNU General Public License.  This exception does not however
//& invalidate any other reasons why the executable file might be covered by
//& the GNU General Public License.
//&
//& ****************************************************************************

#ifndef _KOS_H
#define _KOS_H



typedef unsigned int U32;
typedef int S32;
typedef unsigned short U16;
typedef short S16;
typedef unsigned char U8,*P_U8;
typedef char S8;
typedef char BYTE;
typedef char *P_BYTE;
typedef int BOOL;
typedef void *P_VOID;

#ifndef size_t
#define size_t unsigned int
#endif /* size_t */

#ifndef SIZE_T
#define SIZE_T size_t
#endif


//Al 19th Nov '04
#ifndef NULL
#define NULL 0
#endif

// < ibl ; 2004-10-28 >
#define TIME_T unsigned int 

typedef U32 (*FUNC_PTR)();
typedef U32 (*FUNC0PTR)();
typedef U32 (*FUNC1PTR)(U32);
typedef U32 (*FUNC2PTR)(U32,U32);
typedef U32 (*FUNC3PTR)(U32,U32,U32);



#ifndef FALSE
#define FALSE 0
#define TRUE (! FALSE)
#endif

// memory alloc type define
#define KOS_MEM_FREE                        0x0000
// memory not allocated
#define KOS_MEM_GLOBAL                      0x1000
// global memory type
#define KOS_MEM_LOCAL                       0x2000
// local (task) memory type
#define KOS_MEM_HEAP0                       0x0100
// heap number

#define KOS_MODULE_FILESYSTEM 1

#define KOS_FUNC_FOPEN	0
#define KOS_FUNC_FREAD	1
#define KOS_FUNC_FWRITE	2
#define KOS_FUNC_FCLOSE	3
#define KOS_FUNC_FSEEK	4
#define KOS_FUNC_FDELETE 5


#define KOS_READMODE 1		
#define KOS_WRITEMODE 2

// Filesystem (fs.h)

// we don't have that...
// #include "kgeneraldef.h"

#define FAT32_SUPPORT  1

#define NEW_FILE_NAME

// FIXME: uncomment the following struct, when KDATE* structs are known

/*
typedef struct __file_dir_info
{
       KDATETIME       last_modifier;
       KDATETIME       create_date;
       KDATE           last_access_date;
#ifdef  NEW_FILE_NAME
       BYTE            file_name[13];
#else
       BYTE            extension[4];
       BYTE            name[9];
#endif
       U8                      attribute;
       U16                     ext_attr;
       U32                     size;
}FILE_INFO, DIR_INFO, *P_FILE_INFO, *P_DIR_INFO;
*/



typedef S32     H_FILE;

#define FILE_READONLY   0x00000001      //mode parameter in kos_fopen
#define FILE_READWRITE  0x00000002
#define FILE_APPEND     0x00000003

#define FS_SEEK_SET             0
#define FS_SEEK_CUR             1
#define FS_SEEK_END             2

#define ERR_FS_INVALID_NAME                     -1
#define ERR_FS_FILE_OPENED                      -2
#define ERR_FS_INVALID_HANDLE                   -3
#define ERR_FS_INVALID_INDEX                    -4
#define ERR_FS_INVALID_MODE                     -5
#define ERR_FS_DISK_FULL                        -6
#define ERR_FS_DISK_ERROR                       -7
#define ERR_FS_DISK_CHANGE                      -8
#define ERR_FS_NO_SDCARD                        -9
#define ERR_FS_NO_MEMORY                       -10
#define ERR_FS_NOT_SUPPORT                     -11
#define ERR_FS_PROTECT                         -13
#define ERR_FS_NOTFIND                         -14
#define ERR_FS_DISK_REMOVE                     -15
#define ERR_FS_FILE_NOTEXIST                   -16
#define ERR_FS_UNKNOWN                        -100



// Errors

#define SUCCESS 0
#define EOF -1
#define KOS_ERR_INVALIDPTR	-200 // FIXME: random guess

// Kernel

FUNC_PTR kos_GetFuncEntry(U32 module, U32 index);

// Filesystem

H_FILE kos_fopen(P_BYTE fname, U8 mode);
SIZE_T kos_fread(H_FILE fd, P_BYTE buf, U32 length);
SIZE_T kos_fwrite(H_FILE fd, P_BYTE buf, U32 length);
S32 kos_fseek(H_FILE fd, S32 offset, U32 mode);
S32 kos_fclose(H_FILE fd);
S32 fdelete(P_BYTE fname);


//Edit by Al 19th October
//Include more of HP's KOS functions

//TODO: Add the rest (except maybe the dangerous ones)

//memory management

void *kos_malloc(SIZE_T size); //malloc. ~100kb free on 49g+, <30k free on 39g+
S32 kos_free(void *pMemory); //free
 

//display routines

void kos_ClearLcd(void); //clears the LCD
U32 kos_PutString(U32 dx, U32 dy, P_VOID ptr); //writes a string, in large 5 x 8 font
void kos_PutHexNumber(U32 dx, U32 dy, U32 value); //write a number in hex
void kos_PutDecNumber(U32 dx, U32 dy, U32 value, U32 bit); //writes a number in base-10

U32 kos_LCDGetContrast(void); //gets and sets LCD contrast
void kos_LCDSetContrast(U32 contrast);

//misc routines

P_BYTE kos_getSerialNumber(void); //seems to return garbage, and a Kinpo copyright. 
void kos_Reset(void); // reset OS + emulator?
S32 kos_beep(U32 freq, TIME_T time, U32 override);

// Time

U32 kos_GetSysTickTime();



#endif
