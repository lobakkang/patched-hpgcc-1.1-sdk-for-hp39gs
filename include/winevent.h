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

#ifndef _WIN_EVENT_H_
#define _WIN_EVENT_H_

/*!
 * \file winevent.h
 *
 * \brief Event queue for the HPGCC window system.
 *
 * The foundation of the HPGCC window system is the event queue.  The API here
 * is the foundation of the event queue.
 *
 * \section overview Overview
 *
 * The event queue is fairly simple in design.  It solves several problems:
 *
 * \li Getting various sorts of information to an interested party.
 * \li Allowing for busy polling of various resources.
 * \li Implementing both event-based and procedural program models.
 *
 * \note Contrary to the implications of words like "queue" and "post", event
 *       delivery in the HPGCC window system is never deferred to a later
 *       point in time.
 * 
 * \section basics The Basics
 * 
 * Use of the event queue follows these general steps:
 *
 * \li Initialize the window system.
 * \li Register any custom events that are needed.
 * \li Add any event handlers that are needed.
 * \li Call ::win_event_loop to process events.
 * \li Call ::win_event_quit to exit the event loop.
 *
 * \subsection init Intializing the window system.
 *
 * All window system code begins with a call to ::win_init.  This function
 * must be called prior to any use of the HPGCC window system.  It initializes
 * fundamental data structures, including the system event queue.  Any
 * application that calls other window system functions without calling
 * ::win_init first is likely to crash the calculator.
 *
 * \code
 * win_init();
 * \endcode
 *
 * \subsection regevent Registering Events
 *
 * The event queue is capable of delivering arbitrary events to handlers.
 * However, each events requires an identifying event number.  In software
 * that consists of one or more third-party libraries, keeping event numbers
 * unique can present a definite challenge.  Because event numbers are likely
 * to conflict with each other, ::win_register_event is provided to retrieve
 * unique event numbers for custom events.
 *
 * \note Although event registration is provided to help you avoid event
 *       number conflicts, you \b must register all of your custom events
 *       even if you are not concerned about these conflicts.
 *
 * Once an event has been registered, the event number should be stored and
 * made available to any other modules that need it.  You do not supply any
 * information about your event when registering it, and there is no
 * mechanism within the window system to learn about events that have
 * already been registered.  The module that registers the event is
 * responsible for meeting that need.
 *
 * \code
 * int event = win_register_event();
 * \endcode
 *
 * A certain number of system events are provided by the window system, and
 * are provided for free.  Many simple applications may not need to register
 * any events.  However, application authors should not underestimate the
 * utility of creating and sending custom events when interesting things
 * occur within the application.
 *
 * Because there is a limited number of events, event numbers should be used
 * to distinguish between kinds of events, rather than individual instances of
 * the event or individual event sources.  Any software module that uses events
 * should typically register all events as it is initialized.  Event handlers
 * may later access instance-specific or source-specific information using the
 * \c app_data and \c event_data parameters described below.
 *
 * \subsection createhandler Creating Event Handlers
 *
 * Next, event handlers are added.  In a typical application using the window
 * system, all interesting work is performed by event handlers.  The next step
 * is to register those handlers.  Event handlers receive two pieces of
 * information: event data, and application data.  Handlers return an integer.
 *
 * \code
 * int my_event_handler(void *event_data, void *app_data)
 * {
 *     ...
 * }
 * \endcode
 *
 * The meaning of the \c event_data parameter depends on the event being
 * handled.  The meaning of the \c app_data parameter depends on the event
 * handler itself.  Both of these parameters should be cast to their
 * appropiate types, if they are needed, and used accordingly.  For example,
 * the \c event_data parameter to a handler for ::WIN_KEY_PRESSED is actually
 * an integer, so it can be used like this:
 *
 * \code
 * int keycode = (int) event_data;
 * if (keycode == KB_ON) ...
 * \endcode
 *
 * More commonly, these parameters are set to \c NULL if they are not used,
 * or are used as pointers to some structure containing a variety of
 * information.
 *
 * The \c app_data parameter belongs to the handler, not the event.  It is
 * specified when adding the handler, and is passed unchanged to the event
 * handler each time it is called.  This is generally used to provide context
 * for the event handler.  For example, the event handler can be given a
 * specific data structure in which to store its results as it operates.
 *
 * All event handlers return an integer.  If that result is zero, then the
 * dispatch of the event continues.  If it is non-zero, the event is
 * \i consumed and will not be forwarded to any more event handlers.
 * Although the event queue itself does not distinguish between non-zero
 * results, other application logic may use this return value in more
 * sophisticated ways.
 *
 * \subsection addhandler Adding Event Handlers
 *
 * Once an event handler has been written, it must be added to a specific
 * event as follows:
 *
 * \code
 * win_add_event_handler(event_num, priority, my_event_handler, app_data);
 * \endcode
 *
 * The \c event_num is the number of the event to be handled.  This is either
 * a system event number, or the result of a previous call to
 * ::win_register_event.  The third and fourth parameters provide the function
 * to call and the \c app_data parameter to pass to that function,
 * respectively.
 *
 * The priority represents the order in which multiple event handlers will be
 * called for the same event.  Event handlers with a higher priority will be
 * called first, and therefore get a chance to consume the event (by returning
 * non-zero from the handler function) before low-priority events see it.
 * Priorities can span the full range of an integer, from approximately
 * negative to positive two billion.  The following ranges are reserved for
 * specific purposes:
 *
 * \li Absolute value greater than 2 billion.  These priorities are reserved
 *     for the event queue system.
 * \li Absolute value between 1 billion and 2 billion.  These priorities are
 *     reserved for use by widgets that are integrated and distributed with
 *     the HPGCC libraries.
 * \li Absolute value between zero and one thousand.  These priorities are
 *     reserved for use directly by the end-user application.
 *
 * All remaining priorities may be used by libraries or reusable code.  These
 * are rough guidelines, and may be revised as time reveals better practices.
 * 
 * \subsection win_event The Event Loop
 *
 * Once event handlers have been added, the ::win_event_loop function can be
 * called.  In most applications using the HPGCC window system, the
 * ::win_event_loop function begins the main part of the application, in which
 * all work is done in event handlers.  Once this function has been called,
 * the event queue will be used to manage the application's actions.  The event
 * queue continues to run until some event handler calls ::win_event_quit.
 *
 * \section send Sending Events
 *
 * Although applications are often on the receiving end of events, events can
 * also be sent through the event queue.  This is accomplished using the
 * function ::win_post_event.  The application need only supply an event
 * number (either a system event number or one returned from a prior call to
 * ::win_register_event), and the \c event_data parameter to accompany the
 * event.
 *
 * \code
 * int result = win_post_event(event_number, event_data);
 * \endcode
 *
 * The return value from win_post_event is zero if no handler consumed the
 * event, or is the return value from the handler that did consume the event.
 * Because this exact value is preserved, it is possible to use
 * ::win_post_event to retrieve simple information from event handlers.
 * However, this should be considered an advanced use of the function.
 *
 * Often, applications that use ::win_post_event are effectively creating a
 * bridge from one event type to another.  In that case, it is recommended
 * that the return value from ::win_post_event is used as the return value
 * for the original event as well.  However, there are exceptions to this rule.
 * For example, applications should avoid returning non-zero from
 * ::WIN_REPAINT_EVENT handlers, even if they generate other events from that
 * handler.
 *
 * \section polling Generating New Low-Level Events
 *
 * One common way to generate new events is to poll some hardware system and
 * post an event when something interesting occurs.  For example, an event-
 * based driver for the IrDA serial port could conceivably be written using
 * the event queue.  This is accomplished by polling the device in an event
 * handler for ::WIN_IDLE_EVENT.
 * 
 * ::WIN_IDLE_EVENT is a special system event that is generated constantly on
 * a regular basis.  It is the source of all other events in the system.  For
 * this reason, it is important not to interfere with its functioning.  The
 * following guidelines apply to event handlers for ::WIN_IDLE_EVENT.
 *
 * \li Handlers for ::WIN_IDLE_EVENT should not consume the event by returning
 *     a non-zero result.  This would prevent any events from being generated
 *     by a lower-priority handler.
 *
 * \li ::WIN_IDLE_EVENT handlers should not run for significant amounts of
 *     time.  Other handlers may depend on being called on a very frequent
 *     basis in order to operate correctly.  For example, a long running idle
 *     handler could cause the keyboard to miss keystrokes.
 *
 * \section proc The Pseudo-Procedural Model
 *
 * For the most part, applications using the system event queue are entirely
 * event-driven.  That means that the entirety of their work is done in event
 * handlers.  The application sets up these event handlers, calls
 * ::win_event_loop, and then exists when the event loop is finished.  In some
 * cases, though, that may not be the best way for the application to function.
 * Some applications may need to perform long computations or other tasks
 * which are not easily broken into small pieces to be run in event handlers.
 *
 * This latter class of applications is suited to the window system's
 * pseudo-procedural model.  In this model, the application performs most of
 * its own work, but occasionally steps aside to allow event handlers to run.
 * Event handlers are run by sending a ::WIN_IDLE_EVENT to the system event
 * queue to inform it that the application intends to wait for a moment and
 * process events.
 */

/*!
 * \brief Event number for the system idle event.
 *
 * The system idle event is the most important event in the HPGCC window
 * system.  It is the fundamental event that causes other events to occur.
 * The idle event itself may be generated either by calling ::win_event_loop
 * or by periodically calling ::win_post_event with the appropriate arguments.
 * (The second option is known as the pseudo-procedural model for programming
 * the event queue.)
 *
 * Handlers for ::WIN_IDLE_EVENT have two unique requirements beyond handlers
 * for other events.  First, the handler should run and return in the minimum
 * possible amount of time.  Second, the handler should always return zero,
 * since the system depends on this event being dispatched to all of its
 * handlers.
 *
 * The event data field for idle events is not defined, and is generally set
 * to \c NULL.
 */
#define WIN_IDLE_EVENT     0

/*!
 * \brief An event handler function.
 *
 * This is the required signature for event handler functions.
 *
 * \param event_data A data object describing the event that occurred.
 * \param app_data   A data object associated with this event handler.
 *
 * \return Zero to continue dispatching the event to other handlers; or
 *         non-zero to stop the event from being further processed.
 */
typedef int (*win_eventhandler) (void *event_data, void *app_data);

/*!
 * \brief Initializes the window system.
 *
 * This function \b must be called before using any of the window system.
 * It initializes internal data structures such as the event queue.
 */
void win_init(void);

/*!
 * \brief Registers a new event type.
 *
 * Any applications or widgets that send events of their own types should
 * register those events using this function.  The main purpose of event
 * registration is to be sure that applications and libraries don't use the
 * same event number for different purposes.
 *
 * \return The newly registered event number.  This number should be saved
 *         and used later for calls to ::win_add_event_handler and
 *         ::win_post_event.
 */
int win_register_event(void);

/*!
 * \brief Dispatches a new event to any handlers.
 *
 * The event information passed to this function will be sent along to any
 * event handlers that have been added for the given message type.  The
 * message is sent to handlers in the opposite order that they were added, so
 * the most recently added handler is the first to receive the message.  More
 * handlers will be called until one of them returns a non-zero value to
 * indicate that it has completely handled the message.
 *
 * \param event       The event number for the event to post.
 * 
 * \param event_data  A data object.  The meaning of this object is dependent
 *                    on the event number, and it can be cast to the correct
 *                    type by the event handler.
 *
 * \return Zero if no event handlers returned non-zero; otherwise, the return
 *         value of the first handler to return non-zero.
 */
int win_post_event(int event, void *event_data);

/*!
 * \brief Adds a new event handler.
 *
 * A new handler will be added to the list of handlers for the event type
 * indicated by the \c event parameter.
 *
 * \note Modifying the list of handlers has no effect on any event dispatch
 *       that is already in progress.  The change will take effect for any
 *       future calls to ::win_post_event.
 *
 * \param event     The event number for which the handler should be called.
 * \param priority  The priority; the higher this number, the sooner the
 *                  handler is called for its event type.  Priorities can be
 *                  any valid number in the \c int range, including negative
 *                  numbers.
 * \param handler   The callback function to be notified about this event.
 *
 * \param app_data  An arbitrary piece of data to send along with any event
 *                  notifications to this handler.  The interpretation of this
 *                  parameter is dependent on the event handler function.  The
 *                  handler function may cast it to the desired type.
 */
void win_add_event_handler(
    int event, int priority, win_eventhandler handler, void *app_data);

/*!
 * \brief Removes an event handler.
 *
 * The most recently added event handler with the given function \b and
 * data object will be removed.  If there is no such handler, then the
 * function has no effect.
 *
 * \note Modifying the list of handlers has no effect on any event dispatch
 *       that is already in progress.  The change will take effect for any
 *       future calls to ::win_post_event.  If the \c app_data parameter
 *       points to a dynamically allocated data structure, that memory
 *       should not be released until it can be guaranteed that all event
 *       dispatches that were begun at the time this event handler was called
 *       are completed.
 *
 * \param event     The event number for which the handler should be removed.
 * \param handler   The handler callback function that was added.
 * \param app_data  The data object specified when the handler was added.
 */
void win_remove_event_handler(
    int event, win_eventhandler handler, void *app_data);

/*!
 * \brief Waits for events.
 *
 * This function forms the main section of most applications using the HPGCC
 * window system.  It causes events to be detected and dispatched.  It does
 * not return until some event handler calls ::win_event_quit.
 */
void win_event_loop(void);

/*!
 * \brief Causes the event loop to exit.
 */
void win_event_quit(void);

#endif /* _WIN_EVENT_H_ */
