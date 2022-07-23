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

/*
 * EVENT INFORMATION: This header defines system event numbers 1 through
 *                    6.  They are WIN_KEY_PRESSED, WIN_KEY_RELEASED,
 *                    WIN_KEY_TYPED, WIN_ALPHA_CHANGED, WIN_LSHIFT_CHANGED,
 *                    and WIN_RSHIFT_CHANGED.
 */

#ifndef _WINKEYS_H_
#define _WINKEYS_H_

/*!
 * \file winkeys.h
 *
 * \brief Window system keyboard events
 *
 * These functions provide the basis of the HPGCC window system's keyboard
 * support.
 */

/*!
 * \brief Event number for key pressed events.
 *
 * A key pressed event occurs whenever the user presses any key on the
 * keyboard.
 *
 * The event data field for this event type is an \c int containing the
 * key code for the key that was pressed.  The key code is a constant defined
 * in \c hpkeyb49.h and beginning with the \c KB_ prefix.
 *
 * \warning Consuming events of this type can interfere with the operation of
 *          the shift keys.
 */
#define WIN_KEY_PRESSED     1

/*!
 * \brief Event number for key released events.
 *
 * A key released event occurs whenever the user releases any key on the
 * keyboard.
 *
 * The event data field for this event type is an \c int containing the
 * key code for the key that was pressed.  The key code is a constant defined
 * in \c hpkeyb49.h and beginning with the \c KB_ prefix.
 *
 * \warning Consuming events of this type can interfere with the operation of
 *          the shift keys.
 */
#define WIN_KEY_RELEASED    2

/*!
 * \brief Event number for key typed events.
 *
 * A key typed event occurs whenever a keypress should be handled at the
 * application level.  This is a higher-level event than key pressed, and more
 * suitable for application tasks.  Key typed events are generated for key
 * presses that were not consumed by a ::WIN_KEY_PRESSED handler, and which are
 * not shift keys.  Unlike ::WIN_KEY_PRESSED, the event field for this event
 * contains semantic information like the logical shift key state and
 * equivalent ASCII character.
 *
 * This event is not generated for shift keys (left shift, right shift, and
 * alpha).  To detect actions on these keys, see the ::WIN_ALPHA_CHANGED,
 * ::WIN_LSHIFT_CHANGED, and ::WIN_RSHIFT_CHANGED events.
 *
 * The event data field for this event type is a pointer to ::win_keytyped_t,
 * which contains a variety of information about the event.
 *
 * \see win_keytyped_t
 */
#define WIN_KEY_TYPED       3

/*!
 * \brief Event number for changes in the alpha key's state.
 *
 * An alpha changed event occurs whenever the state of the alpha key is
 * changed.  This is a high-level event involving the interpretation of
 * keys.  It only operates for key events that were not consumed by handlers
 * for ::WIN_KEY_PRESSED and ::WIN_KEY_RELEASED.
 *
 * The event data field for this event type is one of the key state constants,
 * ::WIN_KEYSTATE_OFF, ::WIN_KEYSTATE_ON, ::WIN_KEYSTATE_LOCK, or
 * ::WIN_KEYSTATE_PRESSED.
 */
#define WIN_ALPHA_CHANGED   4

/*!
 * \brief Event number for changes in the left shift key's state.
 *
 * A left shift changed event occurs whenever the state of the left shift key
 * is changed.  This is a high-level event involving the interpretation of
 * keys.  It only operates for key events that were not consumed by handlers
 * for ::WIN_KEY_PRESSED and ::WIN_KEY_RELEASED.
 *
 * The event data field for this event type is one of the key state constants,
 * ::WIN_KEYSTATE_OFF, ::WIN_KEYSTATE_ON, or ::WIN_KEYSTATE_PRESSED.  (The
 * semantics for left shift dictate that it can never be locked.)
 */
#define WIN_LSHIFT_CHANGED  5

/*!
 * \brief Event number for changes in the right shift key's state.
 *
 * A right shift changed event occurs whenever the state of the right shift
 * key is changed.  This is a high-level event involving the interpretation of
 * keys.  It only operates for key events that were not consumed by handlers
 * for ::WIN_KEY_PRESSED and ::WIN_KEY_RELEASED.
 *
 * The event data field for this event type is one of the key state constants,
 * ::WIN_KEYSTATE_OFF, ::WIN_KEYSTATE_ON, or ::WIN_KEYSTATE_PRESSED.  (The
 * semantics for right shift dictate that it can never be locked.)
 */
#define WIN_RSHIFT_CHANGED  6

/*!
 * \brief Constant for a shift key that is not active.
 */
#define WIN_KEYSTATE_OFF     0

/*!
 * \brief Constant for a shift key that is active.
 *
 * \note In most cases, applications should test for \c shift \c > \c 0 rather
 *       that comparing the shift state against this constant.  Other non-zero
 *       values, such as locked, are generally equivalent.
 */
#define WIN_KEYSTATE_ON      1

/*!
 * \brief Constant for a shift key that is locked.
 */
#define WIN_KEYSTATE_LOCK    2

/*!
 * \brief Constant for a shift key that is being held down.
 */
#define WIN_KEYSTATE_PRESSED 3

/*!
 * \brief Event data for ::WIN_KEY_TYPED events.
 *
 * This data structure contains information about a key that was typed.
 */
typedef struct
{
    /*!
     * \brief The keycode for the key that was typed.
     *
     * This code will match one of the key code constants defined in
     * \c hpheyb49.h of the form \c KB_XXX.
     */
    unsigned keycode : 8;

    /*!
     * \brief The ASCII equivalent of the key that was typed.
     *
     * If the key maps to an ASCII character, this field provides the ASCII
     * code of the character represented by this key.  If the key does not
     * have an equivalent ASCII character, this field is set to NUL (\c '\0').
     */
    char ascii;

    /*!
     * \brief State of the left shift key.
     *
     * This field represents the state of the left shift key when this key
     * was typed.  It is set to one of ::WIN_KEYSTATE_ON, ::WIN_KEYSTATE_OFF,
     * or ::WIN_KEYSTATE_PRESSED.
     */
    unsigned lshift : 2;

    /*!
     * \brief State of the right shift key.
     *
     * This field represents the state of the right shift key when this key
     * was typed.  It is set to one of ::WIN_KEYSTATE_ON, ::WIN_KEYSTATE_OFF,
     * or ::WIN_KEYSTATE_PRESSED.
     */
    unsigned rshift : 2;

    /*!
     * \brief State of the right shift key.
     *
     * This field represents the state of the alpha key when this key was
     * typed.  It is set to one of ::WIN_KEYSTATE_ON, ::WIN_KEYSTATE_OFF,
     * ::WIN_KEYSTATE_LOCK, or ::WIN_KEYSTATE_PRESSED.
     */
    unsigned alpha : 2;
} win_keytyped_t;

#endif /* _WINKEYS_H_ */
