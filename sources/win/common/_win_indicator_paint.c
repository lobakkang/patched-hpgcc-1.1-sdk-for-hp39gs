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

#include <hpstdlib.h>
#include <hpkeyb49.h>
#include <hpgraphics.h>
#include "winpriv.h"

static void set_indicator(int state, int ind)
{
    if (state == WIN_KEYSTATE_ON) hpg_set_indicator(ind, HPG_COLOR_BLACK);
    if (state == WIN_KEYSTATE_PRESSED) hpg_set_indicator(ind, HPG_COLOR_BLACK);
    if (state == WIN_KEYSTATE_OFF) hpg_set_indicator(ind, HPG_COLOR_WHITE);

    /*
     * Just as an experiment, let's set keys to gray 9 when locked,
     * providing some kind of visual indicator of the locked state.
     * If I get complaints, I'll probably remove that.
     */
    if (state == WIN_KEYSTATE_LOCK) hpg_set_indicator(ind, HPG_COLOR_GRAY_9);
}

int _win_indicator_paint(void *event_data, void *app_data)
{
    int alpha = _win_alpha_p ? WIN_KEYSTATE_PRESSED : _win_alpha;
    int lshift = _win_lshift_p ? WIN_KEYSTATE_PRESSED : _win_lshift;
    int rshift = _win_rshift_p ? WIN_KEYSTATE_PRESSED : _win_rshift;

    set_indicator(alpha, HPG_INDICATOR_ALPHA);
    set_indicator(lshift, HPG_INDICATOR_LSHIFT);
    set_indicator(rshift, HPG_INDICATOR_RSHIFT);

    return 0;
}
