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

#ifndef _WIN_TIMER_H_
#define _WIN_TIMER_H_

/*!
 * \file  wintimer.h
 * \brief Functions related to setting and executing timers.
 *
 * Timers provide a way for an application using the HPGCC window system
 * to perform periodic tasks, such as updating a clock, progressing to
 * the next frame of an animation, or flashing a text cursor.
 */

/*!
 * \brief Function signature for a timer callback.
 *
 * \param app_data A data field with arbitrary contents.  This value is
 *                 passed to ::win_add_timer, and is returned to the callback
 *                 function when a timer fires.
 *
 * \return Zero if the timer should continue firing; non-zero to drop the
 *         timer.
 */
typedef int (*win_timerfunc_t) (void *app_data);

/*!
 * \brief Adds a timer to call a registered callback function.
 *
 * \param func         Pointer to the timer callback function.
 * \param app_data     An arbitrary data field that is kept, and passed to the
 *                     callback function every time it is invoked.
 * \param interval_ms  The interval between successive calls to the callback
 *                     function, measured in milliseconds.
 * \param periodic     If non-zero, then \c interval_ms specifies the period
 *                     of the repetitive action.  If zero, then \c interval_ms
 *                     is the delay between actions.  The difference is that
 *                     when \c periodic is zero, certain error terms - such as
 *                     the time taken to execute the callback, and any lateness
 *                     of the callback being run, are cumulative.  When
 *                     \c periodic is non-zero, the next delay is shortened to
 *                     correct for that kind of error, so the error does
 *                     not accumulate.
 */
void win_add_timer(win_timerfunc_t func,
    void *app_data, int interval_ms, int periodic);

/*!
 * \brief Adds a timer to generate events on the event queue.
 *
 * \param event_num    The event number to generate when the timer fires.
 * \param event_data   An arbitrary data field that is kept, and passed to the
 *                     event when it is delivered.
 * \param interval_ms  The interval between successive calls to the callback
 *                     function, measured in milliseconds.
 * \param periodic     If non-zero, then \c interval_ms specifies the period
 *                     of the repetitive action.  If zero, then \c interval_ms
 *                     is the delay between actions.  The difference is that
 *                     when \c periodic is zero, certain error terms - such as
 *                     the time taken to execute the callback, and any lateness
 *                     of the callback being run, are cumulative.  When
 *                     \c periodic is non-zero, the next delay is shortened to
 *                     correct for that kind of error, so the error does
 *                     not accumulate.
 */
void win_add_timer_event(int event_num, void *event_data,
    int interval_ms, int periodic);

/*!
 * \brief Removes a callback-style timer.
 *
 * There are two ways to remove a timer.  One way is to call this function to
 * remove it explicitly.  The other is to return a non-zero value from the
 * timer callback itself.
 *
 * \param func     The callback function to remove
 * \param app_data The data field for the callback to remove
 */
void win_remove_timer(win_timerfunc_t func, void *app_data);

/*!
 * \brief Removes an event-style timer.
 *
 * There are two ways to remove an event timer.  One way is to call this
 * function to remove it explicitly.  The other is to return a non-zero value
 * from an event handler registered for that event.
 *
 * \param event_num   The event number of the event timer to remove
 * \param event_data  The event data field for the event timer to remove
 */
void win_remove_timer_event(int event_num, void *event_data);

#endif /* _WIN_TIMER_H_ */
