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

#ifndef _WINPRIV_H_
#define _WINPRIV_H_

#include <hpgcc49.h>
#include <hpgraphics.h>
#include <hpsys.h>
#include "win.h"

#define EQ_LEV1SIZE 64
#define EQ_LEV2SIZE 64

#define LAST_SYS_EVENT 7

/*
 * Private data structure for the event queue.
 */
struct win_eventqueue
{
    /*
     * The next event to be registered.  This is just a counter to ensure
     * that events don't conflict with each other.
     */
    unsigned next_event : 12;

    /*
     * Boolean flag telling the event queue to exit.
     */
    unsigned exit       : 1;

    /*
     * Pointers to the event handler sets.  Each set contains up to EQ_LEV2SIZE
     * handler chains.  Each chain contains handlers for a single registered
     * event type.  This two-level scheme allows up to EQ_LEV1SIZE *
     * EQ_LEV2SIZE different events to be registered, but only requires
     * 4 * (EQ_LEV1SIZE + EQ_LEV2SIZE) bytes of memory for the event tables in
     * the common case (assuming 32-bit pointers, and less than EQ_LEV2SIZE
     * registered events).  For the default settings, that's 4096 events but
     * 512 bytes for the table.
     */
    struct win_eventhandler **handler_chains[EQ_LEV1SIZE];
};

/*
 * A linked list entry for event handlers.  A handler function receives
 * two parameters: event data, which is sent with the event; and
 * application data, which is associated with the handler from within the
 * application.
 */
struct win_eventhandler
{
    int (*handler) (void *event_data, void *app_data);
    void *app_data;
    int priority;

    struct win_eventhandler *next;
};

extern struct win_eventqueue _win_sysqueue;

int _win_default_key_handler(void *event_data, void *app_data);
int _win_indicator_paint(void *event_data, void *app_data);
int _win_key_generator(void *event_data, void *app_data);

extern char _win_alpha;
extern char _win_lshift;
extern char _win_rshift;

extern char _win_alpha_p;
extern char _win_lshift_p;
extern char _win_rshift_p;

/*
 * Structure representing a timer callback.
 */
struct win_timer
{
    /*
     * The function to call when this timer is fired.  The return value
     * indicates whether the timer should be rescheduled (zero) or terminated
     * (non-zero).
     */
    int (*func) (void *app_data);

    /*
     * Opaque data field to echo back to the application handler.
     */
    void *app_data;

    /*
     * Event number and data.  This is ignored for application-registered
     * timer callbacks.  The default event callback, though, uses the
     * information in here to determine the event to send and the data to
     * pass to that event.
     */
    int event_num;
    void *event_data;

    /*
     * Nanoseconds remaining until the next time this event handler should
     * be called.
     */
    ULONGLONG next_time;

    /*
     * The scheduling interval for the function.
     */
    unsigned int interval;

    /*
     * If 1, then an attempt is made to schedule the event such that it
     * averages running once per requested interval.  If 0, then the
     * scheduling tries to run the event with the given delay, which causes
     * cumulative timing error so that the actual period will be slightly
     * longer.
     */
    unsigned periodic : 1;

    /*
     * Next pointer for the list.
     */
    struct win_timer *next;
};

extern struct win_timer *_win_timer_list;
extern sys_timer_t _win_sys_timer;

int _win_timer_generator(void *app_data, void *event_data);
void _win_push_timer(struct win_timer *timer);
int _win_timer_event(void *app_data);

/*
 * Data structure for a widget.  A widget is really little more than a
 * group of related event handlers to be added to the system event queue.
 */
struct win_widget
{
    /*
     * Common functions.  These functions are used to perform certain common
     * tasks to widgets, allowing all widgets to be treated in uniform ways.
     */
    void (*install) (win_widget_t *widget);
    void (*deinstall) (win_widget_t *widget);
    void (*destroy) (win_widget_t *widget);
    void (*pref_size) (win_widget_t *widget, int *width, int *height);

    void (*focus_lost)(win_widget_t *widget);
    void (*focus_gained)(win_widget_t *widget);

    /*
     * Location and size of the widget.
     */
    int x, y, w, h;

    /*
     * Component colors.
     */
    unsigned char bgcolor;
    unsigned char fgcolor;

    /*
     * Font.
     */
    hpg_font_t *font;

    /*
     * Flags:
     */
    unsigned focusable   : 1; // Can the component receive focus?
    unsigned transparent : 1; // Should the component clear its background?
    unsigned focus       : 1; // Does the component have input focus?

    /*
     * An opaque data field used to hold the widget-specific data structures.
     */
    void *widget_data;
};

extern int _win_need_repaint;
int _win_repaint_generator(void *event_data, void *app_data);

struct win_focus_node
{
    win_widget_t *widget;
    struct win_focus_node *next;
    struct win_focus_node *prev;
};

extern struct win_focus_node *_win_focus_list;

#endif /* _WINPRIV_H_ */
