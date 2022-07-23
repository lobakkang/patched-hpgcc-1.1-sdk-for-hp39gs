//& ****************************************************************************
//&
//& Written by Al Borowski
//& Donated to the HP-GCC Development Team
//& Copyright (C) 2004 The HP-GCC Development Team
//&
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

//Warning: Don't use this function for now...


#include <hpsys.h>

#define DEFAULT_PLANE  ((char *) 0x7f00260) 

void setDisplayPlane(unsigned char * plane){ //sets a different video plane
                                             //to display
        //The pointer must be aligned properly in memory (use alignPlane)
     unsigned int volatile * LCDCON1 = (int*) 0x7300000;
     unsigned int volatile * LCDSADDR1 = (int*) 0x7300014;
     unsigned int volatile * LCDSADDR2 = (int*) 0x7300018;

      sys_LCDSynch(); //prevent flicker

        if ((int)plane==(int)DEFAULT_PLANE){
          *LCDSADDR1=0x20000130;   //special banking options needed for the default
          *LCDSADDR2=0x482;
        }

        else{

         *LCDSADDR1=((int)plane>>1); 
         *LCDSADDR2=((int)plane>>1) + (0x482-0x130);
        }

     *LCDCON1=*LCDCON1|1; //turn on LCD, set lowest bit

      while( ((*LCDCON1)&~(0x3ffff))==0){
      } // wait until line count isn't equal to zero, to prevent
      //the next LCDSynch() returning true right away next time.  

}
