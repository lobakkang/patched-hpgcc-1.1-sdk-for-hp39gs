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

#ifndef _WINIMG_H_
#define _WINIMG_H_

/*!
 * \file winimg.h
 * \brief Fuctions to display an image widget in the window system.
 *
 * Image widgets are used to place images or patterns on the screen as
 * decoration or for informational purposes.  They are useful on their own,
 * or to place underneath an existing transparent widget or oversized box cell
 * as a background.
 */

/*!
 * \brief Creates a new image widget.
 *
 * Allocates and returns a new image widget, with its image and pattern set
 * to the given values.
 *
 * \return A pointer to the newly allocated image widget.
 */
win_widget_t *win_img_new(hpg_pattern_t *pattern, hpg_t *image);

#endif /* _WINIMG_H_ */
