//& ****************************************************************************
//&
//& Copyright (C) 2004 HP-GCC Team
//&
//& ****************************************************************************
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

#include "hpgraphics.h"
#include "hpgpriv.h"

void hpg_blit(hpg_t *src, int sx, int sy, int w, int h,
              hpg_t *dst, int dx, int dy)
{
    hpg_init();

    unsigned char saved_color = dst->color;

    int xoff = dx - sx;
    int yoff = dy - sy;

    int x, y;
    for (x = sx; x < sx + w; x++)
    {
        int tx = x + xoff;
        for (y = sy; y < sy + h; y++)
        {
            int ty = y + yoff;
            dst->color = hpg_get_pixel(src, x, y);
            hpg_draw_pixel_on(dst, tx, ty);
        }
    }

    dst->color = saved_color;
}
