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

#ifndef _WIN_H_
#define _WIN_H_

/*!
 * \mainpage HPGCC Window System
 *
 * The HPGCC window system will provides a small collection of common
 * graphical user interface building blocks, from which interactive
 * applications can be built in HPGCC.
 *
 * The main features of the window system include:
 *
 * \li A general-purpose event queue to deliver both standard and custom
 *     events to all interested parties.
 * \li A simple widget model allowing developers to write re-usable
 *     graphical widgets.
 * \li An implementation of the standard HP calculator keyboard operation,
 *     including correct operation of shift and alpha keys.
 * \li A soft menu widget to associate operations with function keys.
 */

/*!
 * \file win.h
 *
 * \brief General include file for the HPGCC window system.
 */

#include <winevent.h>
#include <winwidget.h>
#include <winkeys.h>
#include <wintimer.h>
#include <winsoftmenu.h>
#include <wintext.h>
#include <winprogress.h>
#include <wincheckbox.h>
#include <winbox.h>
#include <winchoose.h>
#include <winimg.h>

#endif /* _WIN_H_ */
