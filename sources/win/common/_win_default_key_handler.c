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

extern void *alloca(int size);

char _win_alpha = WIN_KEYSTATE_OFF;
char _win_lshift = WIN_KEYSTATE_OFF;
char _win_rshift = WIN_KEYSTATE_OFF;

char _win_alpha_p = 0;
char _win_lshift_p = 0;
char _win_rshift_p = 0;

static char get_char(int keycode)
{
    if (_win_lshift == 0 && _win_rshift == 0)
    {
        switch (keycode)
        {
            case KB_0: return '0';
            case KB_1: return '1';
            case KB_2: return '2';
            case KB_3: return '3';
            case KB_4: return '4';
            case KB_5: return '5';
            case KB_6: return '6';
            case KB_7: return '7';
            case KB_8: return '8';
            case KB_9: return '9';
            case KB_BKS: return '\b';
            case KB_MUL: return '*';
            case KB_ADD: return '+';
            case KB_SUB: return '-';
            case KB_DOT: return '.';
            case KB_SPC: return ' ';
            case KB_ENT: return '\n';
            case KB_ON: return '\x1B'; // Escape
        }

        if (_win_alpha > 0)
        {
            switch (keycode)
            {
                case KB_A: return 'A';
                case KB_B: return 'B';
                case KB_C: return 'C';
                case KB_D: return 'D';
                case KB_E: return 'E';
                case KB_F: return 'F';
                case KB_G: return 'G';
                case KB_H: return 'H';
                case KB_I: return 'I';
                case KB_J: return 'J';
                case KB_K: return 'K';
                case KB_L: return 'L';
                case KB_M: return 'M';
                case KB_N: return 'N';
                case KB_O: return 'O';
                case KB_P: return 'P';
                case KB_Q: return 'Q';
                case KB_R: return 'R';
                case KB_S: return 'S';
                case KB_T: return 'T';
                case KB_U: return 'U';
                case KB_V: return 'V';
                case KB_W: return 'W';
                case KB_X: return 'X';
                case KB_Y: return 'Y';
                case KB_Z: return 'Z';
            }
        }
        else
        {
            switch (keycode)
            {
                case KB_O: return '\'';
                case KB_Q: return '^';
                case KB_X: return 'X';
                case KB_Z: return '/';
            }
        }

        return '\0';
    }

    else if (_win_lshift > 0)
    {
        switch (keycode)
        {
            case KB_3: return '#';
            case KB_BKS: return '\x7F'; // Delete
            case KB_MUL: return '[';
            case KB_ADD: return '{';
            case KB_SUB: return '(';
            case KB_DOT: return ':';
        }

        if (_win_alpha > 0)
        {
            switch (keycode)
            {
                case KB_A: return 'a';
                case KB_B: return 'b';
                case KB_C: return 'c';
                case KB_D: return 'd';
                case KB_E: return 'e';
                case KB_F: return 'f';
                case KB_G: return 'g';
                case KB_H: return 'h';
                case KB_I: return 'i';
                case KB_J: return 'j';
                case KB_K: return 'k';
                case KB_L: return 'l';
                case KB_M: return 'm';
                case KB_N: return 'n';
                case KB_O: return 'o';
                case KB_P: return 'p';
                case KB_Q: return 'q';
                case KB_R: return 'r';
                case KB_S: return 's';
                case KB_T: return 't';
                case KB_U: return 'u';
                case KB_V: return 'v';
                case KB_W: return 'w';
                case KB_X: return 'x';
                case KB_Y: return 'y';
                case KB_Z: return 'z';
            }
        }
        else
        {
            switch (keycode)
            {
                case KB_I: return 'i';
            }
        }

        return '\0';
    }

    else if (_win_rshift > 0)
    {
        switch (keycode)
        {
            case KB_MUL: return '\"';
            case KB_SUB: return '_';
            case KB_DOT: return '\r';
            case KB_SPC: return ',';
        }

        if (_win_alpha == 0)
        {
            switch (keycode)
            {
                case KB_I: return '|';
                case KB_W: return '=';
                case KB_X: return '<';
                case KB_Y: return '>';
            }
        }

        return '\0';
    }
}

static int do_typed(int origevent, int keycode)
{
    if (origevent == WIN_KEY_PRESSED)
    {
        win_keytyped_t *newevent = (win_keytyped_t *)
            alloca(sizeof(win_keytyped_t));

        newevent->keycode = keycode;
        newevent->ascii = get_char(keycode);
        newevent->alpha = _win_alpha_p ? WIN_KEYSTATE_PRESSED : _win_alpha;
        newevent->lshift = _win_lshift_p ? WIN_KEYSTATE_PRESSED : _win_lshift;
        newevent->rshift = _win_rshift_p ? WIN_KEYSTATE_PRESSED : _win_rshift;

        if (_win_lshift == WIN_KEYSTATE_ON) _win_lshift = WIN_KEYSTATE_OFF;
        if (_win_rshift == WIN_KEYSTATE_ON) _win_rshift = WIN_KEYSTATE_OFF;
        if (_win_alpha == WIN_KEYSTATE_ON) _win_alpha = WIN_KEYSTATE_OFF;

        return win_post_event(WIN_KEY_TYPED, (void *) newevent);
    }
    else return 0;
}

int _win_default_key_handler(void *event_data, void *app_data)
{
    int origevent = (int) app_data;
    int keycode = (int) event_data;

    int orig_alpha = _win_alpha_p ? WIN_KEYSTATE_PRESSED : _win_alpha;
    int orig_lshift = _win_lshift_p ? WIN_KEYSTATE_PRESSED : _win_lshift;
    int orig_rshift = _win_rshift_p ? WIN_KEYSTATE_PRESSED : _win_rshift;

    int result = 0;

    if (keycode == KB_ALPHA)
    {
        if ((_win_lshift > 0) || (_win_rshift > 0))
        {
            /*
             * Alpha acts like a normal key when it is shifted.
             */
            result = do_typed(origevent, keycode);
        }
        else if (origevent == WIN_KEY_PRESSED)
        {
            _win_alpha_p = 1;

            if (_win_alpha == WIN_KEYSTATE_OFF) _win_alpha = WIN_KEYSTATE_ON;
            else if (_win_alpha == WIN_KEYSTATE_ON) _win_alpha = WIN_KEYSTATE_LOCK;
            else if (_win_alpha == WIN_KEYSTATE_LOCK) _win_alpha = WIN_KEYSTATE_OFF;
        }
        else
        {
            _win_alpha_p = 0;
        }
    }
    else if (keycode == KB_LSHIFT)
    {
        if (origevent == WIN_KEY_PRESSED)
        {
            _win_rshift = 0;
            _win_lshift_p = 1;

            if (_win_lshift == WIN_KEYSTATE_OFF) _win_lshift = WIN_KEYSTATE_ON;
            else if (_win_lshift == WIN_KEYSTATE_ON) _win_lshift = WIN_KEYSTATE_OFF;
        }
        else
        {
            _win_lshift_p = 0;
        }
    }
    else if (keycode == KB_RSHIFT)
    {
        if (origevent == WIN_KEY_PRESSED)
        {
            _win_lshift = 0;
            _win_rshift_p = 1;

            if (_win_rshift == WIN_KEYSTATE_OFF) _win_rshift = WIN_KEYSTATE_ON;
            else if (_win_rshift == WIN_KEYSTATE_ON) _win_rshift = WIN_KEYSTATE_OFF;
        }
        else
        {
            _win_rshift_p = 0;
        }
    }
    else
    {
        result = do_typed(origevent, keycode);
    }

    int new_alpha = _win_alpha_p ? WIN_KEYSTATE_PRESSED : _win_alpha;
    int new_lshift = _win_lshift_p ? WIN_KEYSTATE_PRESSED : _win_lshift;
    int new_rshift = _win_rshift_p ? WIN_KEYSTATE_PRESSED : _win_rshift;

    if (orig_alpha != new_alpha)
    {
        win_post_event(WIN_ALPHA_CHANGED, (void *) new_alpha);
        win_post_event(WIN_REPAINT_EVENT, NULL);
    }
    if (orig_lshift != new_lshift)
    {
        win_post_event(WIN_LSHIFT_CHANGED, (void *) new_lshift);
        win_post_event(WIN_REPAINT_EVENT, NULL);
    }
    if (orig_rshift != new_rshift)
    {
        win_post_event(WIN_RSHIFT_CHANGED, (void *) new_rshift);
        win_post_event(WIN_REPAINT_EVENT, NULL);
    }

    return result;
}
