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

// TODO: Finish glyphs -- only capital alphanumerics are done.

#include "hpgraphics.h"
#include "hpgpriv.h"

static char bigfont_data[] = {
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, // #0, NUL
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, // #27, ESC
    0x08, 0x0C, 0x1E, 0x1F, 0x1E, 0x0C, 0x08, 0x00,
    0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x15, 0x15, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x08, 0x08, 0x08, 0x08, 0x00, 0x08, 0x00, // '!'
    0x0A, 0x0A, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, // '\"'
    0x0A, 0x0A, 0x1F, 0x0A, 0x1F, 0x0A, 0x0A, 0x00, // '#'
    0x04, 0x1E, 0x05, 0x0E, 0x14, 0x0F, 0x04, 0x00, // '$'
    0x03, 0x13, 0x08, 0x04, 0x02, 0x19, 0x18, 0x00, // '%'
    0x02, 0x05, 0x05, 0x02, 0x15, 0x09, 0x16, 0x00, // '&'
    0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, // '\''
    0x08, 0x04, 0x02, 0x02, 0x02, 0x04, 0x08, 0x00, // '('
    0x02, 0x04, 0x08, 0x08, 0x08, 0x04, 0x02, 0x00, // ')'
    0x00, 0x0A, 0x04, 0x1F, 0x04, 0x0A, 0x00, 0x00, // '*'
    0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x00, 0x00, // '+'
    0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x04, 0x02, // ','
    0x00, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, // '-'
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, // '.'
    0x00, 0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, // '/'
    0x0E, 0x11, 0x19, 0x15, 0x13, 0x11, 0x0E, 0x00, // '0'
    0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00, // '1'
    0x0E, 0x11, 0x10, 0x0C, 0x02, 0x01, 0x1F, 0x00, // '2'
    0x0E, 0x11, 0x10, 0x0E, 0x10, 0x11, 0x0E, 0x00, // '3'
    0x08, 0x0C, 0x0A, 0x09, 0x1F, 0x08, 0x08, 0x00, // '4'
    0x1F, 0x01, 0x0F, 0x10, 0x10, 0x11, 0x0E, 0x00, // '5'
    0x0C, 0x02, 0x01, 0x0F, 0x11, 0x11, 0x0E, 0x00, // '6'
    0x1F, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02, 0x00, // '7'
    0x0E, 0x11, 0x11, 0x0E, 0x11, 0x11, 0x0E, 0x00, // '8'
    0x0E, 0x11, 0x11, 0x1E, 0x10, 0x08, 0x06, 0x00, // '9'
    0x00, 0x06, 0x06, 0x00, 0x06, 0x06, 0x00, 0x00, // ':'
    0x00, 0x06, 0x06, 0x00, 0x06, 0x06, 0x04, 0x02, // ';'
    0x08, 0x04, 0x02, 0x01, 0x02, 0x04, 0x08, 0x00, // '<'
    0x00, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x00, 0x00, // '='
    0x01, 0x02, 0x04, 0x08, 0x04, 0x02, 0x01, 0x00, // '>'
    0x0E, 0x11, 0x10, 0x08, 0x04, 0x00, 0x04, 0x00, // '?'
    0x0E, 0x11, 0x15, 0x1D, 0x05, 0x01, 0x1E, 0x00, // '@'
    0x0E, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x00, // 'A'
    0x0F, 0x11, 0x11, 0x0F, 0x11, 0x11, 0x0F, 0x00, // 'B'
    0x0E, 0x11, 0x01, 0x01, 0x01, 0x11, 0x0E, 0x00, // 'C'
    0x07, 0x09, 0x11, 0x11, 0x11, 0x09, 0x07, 0x00, // 'D'
    0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x1F, 0x00, // 'E'
    0x1F, 0x01, 0x01, 0x0F, 0x01, 0x01, 0x01, 0x00, // 'F'
    0x0E, 0x11, 0x01, 0x01, 0x19, 0x11, 0x1E, 0x00, // 'G'
    0x11, 0x11, 0x11, 0x1F, 0x11, 0x11, 0x11, 0x00, // 'H'
    0x0E, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00, // 'I'
    0x10, 0x10, 0x10, 0x10, 0x11, 0x11, 0x0E, 0x00, // 'J'
    0x11, 0x09, 0x05, 0x03, 0x05, 0x09, 0x11, 0x00, // 'K'
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x1F, 0x00, // 'L'
    0x11, 0x1B, 0x15, 0x15, 0x11, 0x11, 0x11, 0x00, // 'M'
    0x11, 0x11, 0x13, 0x15, 0x19, 0x11, 0x11, 0x00, // 'N'
    0x0E, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, // 'O'
    0x0F, 0x11, 0x11, 0x0F, 0x01, 0x01, 0x01, 0x00, // 'P'
    0x0E, 0x11, 0x11, 0x11, 0x15, 0x09, 0x16, 0x00, // 'Q'
    0x0F, 0x11, 0x11, 0x0F, 0x05, 0x09, 0x11, 0x00, // 'R'
    0x0E, 0x11, 0x01, 0x0E, 0x10, 0x11, 0x0E, 0x00, // 'S'
    0x1F, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, // 'T'
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, // 'U'
    0x11, 0x11, 0x11, 0x0A, 0x0A, 0x04, 0x04, 0x00, // 'V'
    0x11, 0x11, 0x11, 0x15, 0x15, 0x1B, 0x11, 0x00, // 'W'
    0x11, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x11, 0x00, // 'X'
    0x11, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x04, 0x00, // 'Y'
    0x1F, 0x10, 0x08, 0x04, 0x02, 0x01, 0x1F, 0x00, // 'Z'
    0x0E, 0x02, 0x02, 0x02, 0x02, 0x02, 0x0E, 0x00, // '['
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x00, 0x00, // '\'
    0x0E, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0E, 0x00, // ']'
    0x04, 0x0A, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, // '^'
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00, // '_'
    0x02, 0x02, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, // '`'
    0x00, 0x00, 0x0E, 0x10, 0x1E, 0x11, 0x1E, 0x00, // 'a'
    0x01, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x0F, 0x00, // 'b'
    0x00, 0x00, 0x1E, 0x01, 0x01, 0x01, 0x1E, 0x00, // 'c'
    0x10, 0x10, 0x1E, 0x11, 0x11, 0x11, 0x1E, 0x00, // 'd'
    0x00, 0x00, 0x0E, 0x11, 0x1F, 0x01, 0x0E, 0x00, // 'e'
    0x04, 0x0A, 0x02, 0x07, 0x02, 0x02, 0x02, 0x00, // 'f'
    0x00, 0x00, 0x0E, 0x11, 0x11, 0x1E, 0x10, 0x0E, // 'g'
    0x01, 0x01, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x00, // 'h'
    0x04, 0x00, 0x06, 0x04, 0x04, 0x04, 0x0E, 0x00, // 'i'
    0x08, 0x00, 0x0C, 0x08, 0x08, 0x08, 0x09, 0x06, // 'j'
    0x01, 0x01, 0x09, 0x05, 0x03, 0x05, 0x09, 0x00, // 'k'
    0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0E, 0x00, // 'l'
    0x00, 0x00, 0x0B, 0x15, 0x15, 0x15, 0x11, 0x00, // 'm'
    0x00, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x11, 0x00, // 'n'
    0x00, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, // 'o'
    0x00, 0x00, 0x0F, 0x11, 0x11, 0x0F, 0x01, 0x01, // 'p'
    0x00, 0x00, 0x1E, 0x11, 0x11, 0x1E, 0x10, 0x10, // 'q'
    0x00, 0x00, 0x1D, 0x03, 0x01, 0x01, 0x01, 0x00, // 'r'
    0x00, 0x00, 0x1E, 0x01, 0x0E, 0x10, 0x0F, 0x00, // 's'
    0x02, 0x02, 0x07, 0x02, 0x02, 0x0A, 0x04, 0x00, // 't'
    0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x1E, 0x00, // 'u'
    0x00, 0x00, 0x11, 0x11, 0x11, 0x0A, 0x04, 0x00, // 'v'
    0x00, 0x00, 0x11, 0x11, 0x15, 0x15, 0x0A, 0x00, // 'w'
    0x00, 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, // 'x'
    0x00, 0x00, 0x11, 0x11, 0x11, 0x1E, 0x10, 0x0E, // 'y'
    0x00, 0x00, 0x1F, 0x08, 0x04, 0x02, 0x1F, 0x00, // 'z'
    0x0C, 0x02, 0x02, 0x01, 0x02, 0x02, 0x0C, 0x00, // '{'
    0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, // '|'
    0x06, 0x08, 0x08, 0x10, 0x08, 0x08, 0x06, 0x00, // '}'
    0x00, 0x00, 0x02, 0x15, 0x08, 0x00, 0x00, 0x00, // '~'
    0x15, 0x0A, 0x15, 0x0A, 0x15, 0x0A, 0x15, 0x00, // #127, DEL
    0x00, 0x10, 0x08, 0x04, 0x06, 0x09, 0x1F, 0x00, // #128
    0x1F, 0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, // #129
    0x00, 0x1F, 0x11, 0x0A, 0x0A, 0x04, 0x00, 0x00, // #130
    0x1C, 0x04, 0x04, 0x04, 0x05, 0x06, 0x04, 0x00, // #131
    0x08, 0x14, 0x04, 0x04, 0x04, 0x05, 0x02, 0x00, // #132
    0x1F, 0x12, 0x04, 0x08, 0x04, 0x12, 0x1F, 0x00, // #133
    0x03, 0x07, 0x0F, 0x1F, 0x0F, 0x07, 0x03, 0x00, // #134
    0x00, 0x00, 0x1F, 0x0A, 0x0A, 0x0A, 0x0A, 0x00, // #135
    0x02, 0x04, 0x08, 0x1E, 0x11, 0x11, 0x0E, 0x00, // #136
    0x10, 0x08, 0x04, 0x02, 0x1F, 0x00, 0x1F, 0x00, // #137
    0x01, 0x02, 0x04, 0x08, 0x1F, 0x00, 0x1F, 0x00, // #138
    0x00, 0x08, 0x1F, 0x04, 0x1F, 0x02, 0x00, 0x00, // #139
    0x00, 0x00, 0x00, 0x16, 0x09, 0x09, 0x16, 0x00, // #140
    0x00, 0x04, 0x08, 0x1F, 0x08, 0x04, 0x00, 0x00, // #141
    0x00, 0x04, 0x02, 0x1F, 0x02, 0x04, 0x00, 0x00, // #142
    0x04, 0x04, 0x04, 0x04, 0x15, 0x0E, 0x04, 0x00, // #143
    0x04, 0x0E, 0x15, 0x04, 0x04, 0x04, 0x04, 0x00, // #144
    0x00, 0x00, 0x12, 0x15, 0x08, 0x08, 0x08, 0x00, // #145
    0x04, 0x02, 0x04, 0x0E, 0x09, 0x09, 0x06, 0x00, // #146
    0x00, 0x00, 0x0E, 0x01, 0x0F, 0x01, 0x0E, 0x00, // #147
    0x00, 0x00, 0x0A, 0x15, 0x14, 0x14, 0x10, 0x10, // #148
    0x06, 0x09, 0x09, 0x0F, 0x09, 0x09, 0x06, 0x00, // #149
    0x00, 0x01, 0x01, 0x02, 0x04, 0x0A, 0x11, 0x00, // #150
    0x00, 0x0C, 0x12, 0x12, 0x0E, 0x02, 0x02, 0x01, // #151
    0x00, 0x00, 0x1E, 0x09, 0x09, 0x09, 0x06, 0x00, // #152
    0x00, 0x00, 0x1E, 0x05, 0x04, 0x14, 0x08, 0x00, // #153
    0x00, 0x00, 0x09, 0x11, 0x15, 0x15, 0x0A, 0x00, // #154
    0x00, 0x00, 0x04, 0x0A, 0x11, 0x1F, 0x00, 0x00, // #155
    0x1F, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A, 0x00, // #156
    0x0E, 0x11, 0x11, 0x11, 0x11, 0x0A, 0x1B, 0x00, // #157
    0x00, 0x00, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x00, // #158
    0x00, 0x00, 0x0A, 0x15, 0x15, 0x0A, 0x00, 0x00, // #159
    0x0C, 0x12, 0x07, 0x02, 0x07, 0x12, 0x0C, 0x00, // #160
    0x04, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, // #161
    0x00, 0x04, 0x1E, 0x05, 0x05, 0x1E, 0x04, 0x00, // #162
    0x0C, 0x12, 0x02, 0x07, 0x02, 0x02, 0x1F, 0x00, // #163
    0x11, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x11, 0x00, // #164
    0x11, 0x11, 0x0A, 0x1F, 0x04, 0x1F, 0x04, 0x00, // #165
    0x04, 0x04, 0x04, 0x00, 0x04, 0x04, 0x04, 0x00, // #166
    0x0C, 0x02, 0x0E, 0x11, 0x0E, 0x08, 0x06, 0x00, // #167
    0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // #168
    0x0E, 0x11, 0x17, 0x13, 0x17, 0x11, 0x0E, 0x00, // #169
    0x06, 0x08, 0x0E, 0x09, 0x06, 0x0F, 0x00, 0x00, // #170
    0x00, 0x14, 0x0A, 0x05, 0x0A, 0x14, 0x00, 0x00, // #171
    0x00, 0x00, 0x00, 0x0F, 0x08, 0x00, 0x00, 0x00, // #172
    0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x00, // #173
    0x0E, 0x11, 0x17, 0x17, 0x1B, 0x11, 0x0E, 0x00, // #174
    0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // #175
    0x0E, 0x0A, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, // #176
    0x00, 0x04, 0x04, 0x1F, 0x04, 0x04, 0x1F, 0x00, // #177
    0x0E, 0x08, 0x0E, 0x02, 0x0E, 0x00, 0x00, 0x00, // #178
    0x0E, 0x08, 0x0E, 0x08, 0x0E, 0x00, 0x00, 0x00, // #179
    0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // #180
    0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x17, 0x01, // #181
    0x1E, 0x17, 0x17, 0x16, 0x14, 0x14, 0x16, 0x00, // #182
    0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, // #183
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0x06, // #184
    0x06, 0x04, 0x04, 0x0E, 0x00, 0x00, 0x00, 0x00, // #185
    0x0E, 0x11, 0x11, 0x0E, 0x00, 0x1F, 0x00, 0x00, // #186
    0x00, 0x05, 0x0A, 0x14, 0x0A, 0x05, 0x00, 0x00, // #187
    0x01, 0x09, 0x05, 0x02, 0x15, 0x1C, 0x10, 0x00, // #188
    0x01, 0x09, 0x05, 0x1A, 0x11, 0x08, 0x18, 0x00, // #189
    0x03, 0x12, 0x0B, 0x06, 0x17, 0x1C, 0x10, 0x00, // #190
    0x04, 0x00, 0x04, 0x02, 0x01, 0x11, 0x0E, 0x00, // #191
    0x02, 0x04, 0x0E, 0x11, 0x1F, 0x11, 0x11, 0x00, // #192
    0x08, 0x04, 0x0E, 0x11, 0x1F, 0x11, 0x11, 0x00, // #193
    0x04, 0x0A, 0x0E, 0x11, 0x1F, 0x11, 0x11, 0x00, // #194
    0x0A, 0x05, 0x0E, 0x11, 0x1F, 0x11, 0x11, 0x00, // #195
    0x0A, 0x00, 0x0E, 0x11, 0x1F, 0x11, 0x11, 0x00, // #196
    0x0E, 0x0A, 0x0E, 0x11, 0x1F, 0x11, 0x11, 0x00, // #197
    0x1A, 0x05, 0x05, 0x1F, 0x05, 0x05, 0x1D, 0x00, // #198
    0x0E, 0x11, 0x01, 0x01, 0x11, 0x0E, 0x08, 0x06, // #199
    0x02, 0x04, 0x1F, 0x01, 0x0F, 0x01, 0x1F, 0x00, // #200
    0x08, 0x04, 0x1F, 0x01, 0x0F, 0x01, 0x1F, 0x00, // #201
    0x04, 0x0A, 0x1F, 0x01, 0x0F, 0x01, 0x1F, 0x00, // #202
    0x0A, 0x00, 0x1F, 0x01, 0x0F, 0x01, 0x1F, 0x00, // #203
    0x02, 0x04, 0x0E, 0x04, 0x04, 0x04, 0x0E, 0x00, // #204
    0x08, 0x04, 0x0E, 0x04, 0x04, 0x04, 0x0E, 0x00, // #205
    0x04, 0x0A, 0x0E, 0x04, 0x04, 0x04, 0x0E, 0x00, // #206
    0x0A, 0x00, 0x0E, 0x04, 0x04, 0x04, 0x0E, 0x00, // #207
    0x06, 0x0A, 0x12, 0x17, 0x12, 0x0A, 0x06, 0x00, // #208
    0x14, 0x0A, 0x11, 0x13, 0x15, 0x19, 0x11, 0x00, // #209
    0x02, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, // #210
    0x08, 0x04, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, // #211
    0x04, 0x0A, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, // #212
    0x0A, 0x05, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, // #213
    0x0A, 0x00, 0x0E, 0x11, 0x11, 0x11, 0x0E, 0x00, // #214
    0x00, 0x11, 0x0A, 0x04, 0x0A, 0x11, 0x00, 0x00, // #215
    0x10, 0x0E, 0x19, 0x15, 0x13, 0x0E, 0x01, 0x00, // #216
    0x02, 0x04, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, // #217
    0x08, 0x04, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, // #218
    0x04, 0x0A, 0x00, 0x11, 0x11, 0x11, 0x0E, 0x00, // #219
    0x0A, 0x00, 0x11, 0x11, 0x11, 0x11, 0x0E, 0x00, // #220
    0x08, 0x04, 0x11, 0x0A, 0x04, 0x04, 0x04, 0x00, // #221
    0x07, 0x02, 0x0E, 0x12, 0x0E, 0x02, 0x07, 0x00, // #222
    0x0E, 0x11, 0x0F, 0x11, 0x11, 0x0F, 0x01, 0x01, // #223
    0x02, 0x04, 0x0E, 0x10, 0x1E, 0x11, 0x1E, 0x00, // #224
    0x08, 0x04, 0x0E, 0x10, 0x1E, 0x11, 0x1E, 0x00, // #225
    0x04, 0x0A, 0x0E, 0x10, 0x1E, 0x11, 0x1E, 0x00, // #226
    0x0A, 0x05, 0x0E, 0x10, 0x1E, 0x11, 0x1E, 0x00, // #227
    0x0A, 0x00, 0x0E, 0x10, 0x1E, 0x11, 0x1E, 0x00, // #228
    0x0E, 0x0A, 0x0E, 0x10, 0x1E, 0x11, 0x1E, 0x00, // #229
    0x00, 0x00, 0x1B, 0x14, 0x1F, 0x05, 0x1F, 0x00, // #230
    0x00, 0x00, 0x1E, 0x01, 0x01, 0x1E, 0x08, 0x06, // #231
    0x02, 0x04, 0x0E, 0x11, 0x1F, 0x01, 0x0E, 0x00, // #232
    0x08, 0x04, 0x0E, 0x11, 0x1F, 0x01, 0x0E, 0x00, // #233
    0x04, 0x0A, 0x0E, 0x11, 0x1F, 0x01, 0x0E, 0x00, // #234
    0x0A, 0x00, 0x0E, 0x11, 0x1F, 0x01, 0x0E, 0x00, // #235
    0x02, 0x04, 0x00, 0x06, 0x04, 0x04, 0x0E, 0x00, // #236
    0x08, 0x04, 0x00, 0x06, 0x04, 0x04, 0x0E, 0x00, // #237
    0x04, 0x0A, 0x00, 0x06, 0x04, 0x04, 0x0E, 0x00, // #238
    0x0A, 0x00, 0x00, 0x06, 0x04, 0x04, 0x0E, 0x00, // #239
    0x08, 0x1C, 0x08, 0x0E, 0x09, 0x09, 0x06, 0x00, // #240
    0x14, 0x0A, 0x00, 0x0F, 0x11, 0x11, 0x11, 0x00, // #241
    0x02, 0x04, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00, // #242
    0x08, 0x04, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00, // #243
    0x04, 0x0A, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00, // #244
    0x14, 0x0A, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00, // #245
    0x0A, 0x00, 0x00, 0x0E, 0x11, 0x11, 0x0E, 0x00, // #246
    0x00, 0x04, 0x00, 0x1F, 0x00, 0x04, 0x00, 0x00, // #247
    0x00, 0x00, 0x16, 0x09, 0x15, 0x12, 0x0D, 0x00, // #248
    0x02, 0x04, 0x00, 0x11, 0x11, 0x11, 0x1E, 0x00, // #249
    0x08, 0x04, 0x00, 0x11, 0x11, 0x11, 0x1E, 0x00, // #250
    0x04, 0x0A, 0x00, 0x11, 0x11, 0x11, 0x1E, 0x00, // #251
    0x0A, 0x00, 0x00, 0x11, 0x11, 0x11, 0x1E, 0x00, // #252
    0x08, 0x04, 0x00, 0x11, 0x11, 0x1E, 0x10, 0x0E, // #253
    0x00, 0x01, 0x07, 0x09, 0x09, 0x07, 0x01, 0x01, // #254
    0x0A, 0x00, 0x00, 0x11, 0x11, 0x1E, 0x10, 0x0E, // #255
};

static struct hpg_font bigfont;

hpg_font_t *hpg_get_bigfont()
{
    hpg_init();

    bigfont.buffer = bigfont_data;
    bigfont.count = 256;
    bigfont.height = 8;
    bigfont.advance = 6;

    return &bigfont;
}
