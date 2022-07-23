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

#ifndef _WINBOX_H_
#define _WINBOX_H_

/*!
 * \file winbox.h
 * \brief Include for box widget to group other widgets.
 *
 * The box widget is an invisible widget, whose purpose is to group
 * other widgets so that they can be added and removed from the window
 * system as a group.
 * 
 * Boxes are also capable of laying out their children according to a grid
 * model.  When each widget is added to the box, it can be given a position
 * and a slew of other parameters controlling its layout.  Calling
 * ::win_box_layout will change the positions and sizes of the components
 * in the box to fit the desired layout.
 */

/*!
 * \brief Alignment to the leading edge (left or top).
 */
#define WIN_BOX_LEADING -1

/*!
 * \brief Alignment to the center.
 */
#define WIN_BOX_CENTER 0

/*!
 * \brief Alignment to the trailing edge (right or bottom).
 */
#define WIN_BOX_TRAILING 1

/*!
 * \brief Alignment filling the space to both edges.
 */
#define WIN_BOX_FILL -2

/*!
 * \brief Creates a new box.
 *
 * The result of this call is a new box, which can be used to group items
 * onto the page.  The box has an initial padding of 0 pixels between cells.
 *
 * \return A pointer to the new box widget.
 */
win_widget_t *win_box_new(void);

/*!
 * \brief Creates a new box with cell padding.
 *
 * The result of this call is a new box, which can be used to group items
 * onto the page.  The box will lay out its contents with the given padding
 * between cells in the x and y dimensions.
 *
 * \param xpad  The padding between cells in the horizontal direction.
 * \param ypad  The padding between cells in the vertical direction.
 *
 * \return A pointer to the new box widget.
 */
win_widget_t *win_box_new_padding(int xpad, int ypad);

/*!
 * \brief Adds a widget to a box.
 *
 * The child widget will be added at location (0, 0) and have defaults for
 * all layout parameters.  Typically, this function is used when there is
 * no intent to call ::win_box_layout.
 *
 * \param widget  The box widget.
 * \param child   The widget to be added.
 */
void win_box_add(win_widget_t *widget, win_widget_t *child);

/*!
 * \brief Adds a widget to a box at a specific location.
 *
 * The child widget will be added at a specific location within the box,
 * with defaults for all other layout parameters.  The widget will not
 * physically move, however, until ::win_box_layout is called.
 *
 * \param widget  The box widget.
 * \param child   The widget to be added.
 * \param row     The zero-indexed row number to which to add the widget.
 * \param col     The zero-indexed column number to which to add the widget.
 */
void win_box_add_at(win_widget_t *widget,
    win_widget_t *child, int row, int col);

/*!
 * \brief Adds a widget to a box with specific layout parameters.
 *
 * The child widget will be added at a specific location within the box,
 * with given values for all layout parameters.  The widget will not
 * physically move, however, until ::win_box_layout is called.
 *
 * \param widget  The box widget.
 * \param child   The widget to be added.
 * \param row     The zero-indexed row number to which to add the widget.
 * \param col     The zero-indexed column number to which to add the widget.
 * \param xweight The widget weight in the x dimension.
 * \param yweight The widget weight in the y dimension.
 * \param pwidth  The effective preferred width (or -1 to ask the widget).
 * \param pheight The effective preferred height (or -1 to ask the widget).
 * \param align_x The x dimension alignment to be used when there is extra
 *                space beyond the preferred size of the widget.  Possible
 *                values are ::WIN_BOX_LEADING, ::WIN_BOX_CENTER,
 *                ::WIN_BOX_TRAILING, and ::WIN_BOX_FILL.
 * \param align_y The y dimension alignment to be used when there is extra
 *                space beyond the preferred size of the widget.  Possible
 *                values are ::WIN_BOX_LEADING, ::WIN_BOX_CENTER,
 *                ::WIN_BOX_TRAILING, and ::WIN_BOX_FILL.
 */
void win_box_add_with(win_widget_t *widget, win_widget_t *child,
    int row, int col, double xweight, double yweight,
    int pwidth, int pheight, int align_x, int align_y);

/*!
 * \brief Removes a widgets from a box.
 *
 * The widget will be removed from the box.  If the box does not contain
 * this widget, then the function has no effect.
 *
 * \param widget  The box widget.
 * \param child   The widget to be removed from the box.
 */
void win_box_remove(win_widget_t *widget, win_widget_t *child);

/*!
 * \brief Moves the widgets in this box into their proper position.
 *
 * The widgets will be moved into a grid formation, according to the layout
 * parameters attached to each widget.
 */
void win_box_layout(win_widget_t *widget);

#endif /* _WINBOX_H_ */
