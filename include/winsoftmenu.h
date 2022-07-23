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

#ifndef _WINSOFTMENU_H_
#define _WINSOFTMENU_H_

/*!
 * \file winsoftmenu.h
 * \brief Fuctions to display a soft menu in the window system.
 *
 * Soft menus are the six buttons along the bottom edge of the calculator
 * screen.  They are generally associated with graphical boxes along the
 * bottom of the screen.  The user can choose the menu with the F1 through
 * F6 keys, and can scroll through menu options with the NXT and PREV
 * buttons.
 *
 * A soft menu widget ignores its location and size, and always takes up the
 * bottom of the screen.
 */

/*!
 * \brief Maximum number of items that can be added to a menu.
 *
 * Constant representing the maximum number of items that can exist on a
 * menu.  This can be greater than the number of visible menu items, which is
 * always 6, and the NXT and PREV keys will navigate the menu.
 */
#define WIN_SOFTMENU_MAX_ITEMS 30

/*!
 * \brief Data structure to hold information about menu button presses.
 *
 * Instances of this data structure are allocated temporarily and dispatched
 * to event handlers when soft menu buttons are pressed.
 */
typedef struct
{
    /*!
     * \brief State of the left shift key.
     *
     * This field represents the state of left shift when the menu item was
     * selected.  It is set to one of ::WIN_KEYSTATE_ON, ::WIN_KEYSTATE_OFF,
     * or ::WIN_KEYSTATE_PRESSED.
     */
    unsigned lshift : 2;

    /*!
     * \brief State of the right shift key.
     *
     * This field represents the state of right shift when the menu item was
     * selected.  It is set to one of ::WIN_KEYSTATE_ON, ::WIN_KEYSTATE_OFF,
     * or ::WIN_KEYSTATE_PRESSED.
     */
    unsigned rshift : 2;

    /*!
     * \brief Extra data associated with the key.
     *
     * This is a data field that is associated with the key using any of
     * ::win_softmenu_set_item, ::win_softmenu_add_item, or
     * ::win_softmenu_insert_item.  It is passed verbatim to any event
     * handlers that are called as a result of selecting that menu item.
     *
     * The meaning and interpretation of this field is left to the application.
     * It should be cast to the appropriate data type before use.
     */
    void *extra_data;
} win_softmenu_event_t;

/*!
 * \brief Creates a new soft menu widget.
 *
 * Allocates and returns a new soft menu widget.  Initially, the menu has
 * no items.
 *
 * \return A pointer to the newly allocated soft menu widget.
 */
win_widget_t *win_softmenu_new(void);

/*!
 * \brief Sets the menu item at the given position.
 *
 * This function is used for direct control of the positions of menu items.
 * If there is already a menu item at the given position, it is overwritten
 * by the new item.
 *
 * \param menu       The menu on which to put the item.
 * \param pos        The position of the menu item, beginning at zero.
 * \param label      The text that will appear on the new item.
 * \param event_num  The number of the event to fire when the item is selected.
 * \param extra_data Arbitrary data to send to the event handler.
 */
void win_softmenu_set_item(
    win_widget_t *menu, int pos, char *label,
    int event_num, void *extra_data);

/*!
 * \brief Adds the menu item in the first unused position.
 *
 * This function is used for indirect control menu items when the precise
 * location of each item is not important.  The menu item will be added at the
 * first available location on the menu.
 *
 * \param menu       The menu on which to put the item.
 * \param label      The text that will appear on the new item.
 * \param event_num  The number of the event to fire when the item is selected.
 * \param extra_data Arbitrary data to send to the event handler.
 *
 * \return The position where the menu was added, or -1 if the menu is full.
 */
int win_softmenu_add_item(
    win_widget_t *menu, char *label,
    int event_num, void *extra_data);

/*!
 * \brief Inserts the menu item into the given position.
 *
 * This function is used for general control of the positions of menu items.
 * Any menu items at or after the inserted position will be pushed to the
 * right, filling any unused spaces.  If the menu is full, then the last item
 * will be dropped from the menu.
 *
 * \param menu       The menu on which to put the item.
 * \param pos        The position of the menu item, beginning at zero.
 * \param label      The text that will appear on the new item.
 * \param event_num  The number of the event to fire when the item is selected.
 * \param extra_data Arbitrary data to send to the event handler.
 */
void win_softmenu_insert_item(
    win_widget_t *menu, int pos, char *label,
    int event_num, void *extra_data);

/*!
 * \brief Deletes an item from a menu.
 *
 * Optionally, the items after the deleted item can be shifted backward to
 * fill the empty space.
 *
 * \param menu The menu from which to delete the item.
 * \param pos  The position of the menu item, beginning at zero.
 * \param pack The last index to be shifted to the left to fill empty space.
 *             To disable this behavior, pass 0 for the pack parameter.  To
 *             pack all items, it is sufficient to pass a very large value
 *             such as 1000.
 */
void win_softmenu_delete_item(win_widget_t *menu, int pos, int pack);

/*!
 * \brief Sets the active colors for a menu item.
 */
void win_softmenu_set_colors(win_widget_t *menu, int pos,
    unsigned char fg_color, unsigned char bg_color);

/*!
 * \brief Sets the disabled colors for a menu item.
 */
void win_softmenu_set_disable_colors(win_widget_t *menu, int pos,
    unsigned char fg_color, unsigned char bg_color);

/*!
 * \brief Enables or disables a menu item.
 */
void win_softmenu_set_enabled(win_widget_t *menu, int pos, int val);

#endif /* _WINSOFTMENU_H_ */
