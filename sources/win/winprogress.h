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

#ifndef _WINPROGRESSBAR_H_
#define _WINPROGRESSBAR_H_

#include <winwidget.h>

/*!
 * \file winprogress.h
 * \brief Fuctions to display a progress widget.
 *
 * The progress widget is used to visually display a value between two bounds.
 * It can be made focusable (in which case it acts like a slider control for
 * user adjustment), or it can be made non-focusable to function as a progress
 * bar.
 */

/*!
 * \brief Horizontal left-to-right orientation for a progress widget.
 *
 * This orientation causes a progress widget to draw itself horizontally and
 * fill from left to right.
 */
#define WIN_PROGRESS_HORIZ 0

/*!
 * \brief Vertical bottom-to-top orientation for a progress widget.
 *
 * This orientation causes a progress widget to draw itself vertically and
 * fill from bottom to top.
 */
#define WIN_PROGRESS_VERT 1

/*!
 * \brief Horizontal right-to-left orientation for a progress widget.
 *
 * This orientation causes a progress widget to draw itself horizontally and
 * fill from right to left.
 */
#define WIN_PROGRESS_HORIZ_RIGHT 2

/*!
 * \brief Vertical top-to-bottom orientation for a progress widget.
 *
 * This orientation causes a progress widget to draw itself vertically and
 * fill from top to bottom.
 */
#define WIN_PROGRESS_VERT_TOP 3

/*!
 * \brief Creates a new progress widget.
 *
 * Allocates and returns a new progress widget.
 *
 * \param slider  Indicates if the widget can be used as a slider (1)
 *                or just as a progress bar (0)
 *
 * \return A pointer to the newly allocated progress bar component.
 */
win_widget_t *win_progress_new (int slider);

/*!
 * \brief Sets the progress bar at the given value.
 *
 * This function is used to set the progress bar value.
 *
 * \param bar    The progress bar.
 * \param value  The progress value. If it is out of the range [min, max],
 *               it is set to the min / max value.
 */
void win_progress_set_value(win_widget_t *bar, double value);

/*!
 * \brief Gets the progress bar current value.
 *
 * This function is used to get the progress bar value. It is useful when the
 * progress bar is configured as a slider.
 *
 * \param bar  The progress widget to query.
 * \return     The progress value.
 */
double win_progress_get_value(win_widget_t *bar);

/*!
 * \brief Sets the increment value of the progress widget.
 *
 * This function is used to set the progress bar increment value, when it is
 * used as a slider with the arrow keys.
 *
 * \param bar  The progress bar.
 * \param inc  The increment value.
 */
void win_progress_set_inc(win_widget_t *bar, double inc);

/*!
 * \brief Sets orientation of the progress bar
 *
 * This function is used to set the progress bar orientation.  The four values
 * for orientation are ::WIN_PROGRESS_HORIZ, ::WIN_PROGRESS_VERT,
 * ::WIN_PROGRESS_HORIZ_RIGHT, and ::WIN_PROGRESS_VERT_TOP.
 *
 * \param bar     The progress bar.
 * \param orient  The progress bar orientation.
 */
void win_progress_set_orient(win_widget_t *bar, int orient);

/*!
 * \brief Sets the progress bar range.
 *
 * This function is used to set minimal and maximal value corresponding
 * respectively to 0% and 100% of the progress bar.  If the current value is
 * out of range in either direction, it will be set to the minimum or maximum
 * value, respectively.
 *
 * \param bar  The progress bar
 * \param min  Minimum value
 * \param max  Maximum value
 */
void win_progress_set_range(win_widget_t *bar, double min, double max);

/*!
 * \brief Sets the slider auto-repeat parameters
 *
 * This functions sets up the auto-repeat times for the component.  Auto-repeat
 * provides both a delay before the first auto-repeat, and a delay for each
 * subsequent auto-repeat click.
 *
 * \param bar    The progress bar
 * \param first  Delay before auto-repeat, in milliseconds.
 * \param next   Delay between repetitions, in milliseconds.
 */
void win_progress_set_delay(win_widget_t *widget, int first, int next);

/*!
 * \brief Sets the slider event
 *
 * This function is used to set the event sent by the slider when it is
 * changed.
 *
 * \param bar    The progress bar.
 * \param event  Event number to send for value changes.
 */
void win_progress_set_event(win_widget_t *widget, int event);

#endif /* _WINPROGRESSBAR_H_ */
