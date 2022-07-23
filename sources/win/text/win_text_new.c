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

#include <hpstdlib.h>
#include <hpstring.h>
#include <hpkeyb49.h>
#include <hpgraphics.h>

#include <win.h>
#include <wincore.h>

#include "textpriv.h"

static int paint(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    struct win_text *text = (struct win_text *) win_wcore_get_data(widget);

    win_wcore_paint_base(widget);

    int x, y;
    win_widget_get_location(widget, &x, &y);
    x++;
    y++;

    if (win_widget_has_focus(widget) && text->cursor_vis)
    {
        hpg_font_t *font = win_widget_get_font(widget);

        char tmpchar = text->text[text->pos];
        text->text[text->pos] = '\0';

        hpg_draw_text(text->text, x, y);
        text->text[text->pos] = tmpchar;

        hpg_draw_letter((char) 28,
            x + text->pos * hpg_font_get_advance(font), y);

        if (text->pos < strlen(text->text))
        {
            hpg_draw_text(text->text + text->pos + 1,
                x + (text->pos + 1) * hpg_font_get_advance(font), y);
        }
    }
    else
    {
        hpg_draw_text(text->text, x, y);
    }

    return 0;
}

static int keyhandler(void *event_data, void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    if (!win_widget_has_focus(widget)) return 0;

    struct win_text *text = (struct win_text *) win_wcore_get_data(widget);
    win_keytyped_t *event = (win_keytyped_t *) event_data;

    switch (event->keycode)
    {
        case KB_UP:
            win_focus_prev();
            return 1;

        case KB_DN:
            win_focus_next();
            return 1;

        case KB_LF:
            if (text->pos > 0) text->pos--;
            else win_focus_prev();
            win_repaint();
            return 1;

        case KB_RT:
            if (text->pos < strlen(text->text)) text->pos++;
            else win_focus_next();
            win_repaint();
            return 1;

        case KB_BKS:
            if (event->lshift > 0)
            {
                /*
                 * Delete the character at the cursor position.
                 */
                int len = strlen(text->text);
                int i;
                for (i = text->pos; i < len; i++)
                {
                    text->text[i] = text->text[i + 1];
                }
            }
            else if (event->rshift > 0)
            {
                /*
                 * Delete the entire text.
                 */
                text->pos = 0;
                text->text[0] = 0;
            }
            else
            {
                /*
                 * Delete the character prior to the cursor position.
                 */
                if (text->pos > 0)
                {
                    int len = strlen(text->text);
                    int i;
                    for (i = text->pos - 1; i < len; i++)
                    {
                        text->text[i] = text->text[i + 1];
                    }

                    text->pos--;
                }
            }

            win_repaint();
            return 1;

        default:
            if (event->ascii > 0)
            {
                int len = strlen(text->text);
                if (len < text->size)
                {
                    char ch = event->ascii;
                    int i;

                    for (i = text->pos; i <= (len + 1); i++)
                    {
                        char temp = text->text[i];
                        text->text[i] = ch;
                        ch = temp;
                    }

                    text->pos++;
                }

                win_repaint();
                return 1;
            }
    }

    return 0;
}

static int cursorflash(void *app_data)
{
    win_widget_t *widget = (win_widget_t *) app_data;
    if (win_widget_has_focus(widget))
    {
        struct win_text *text = (struct win_text *) win_wcore_get_data(widget);

        text->cursor_vis = !text->cursor_vis;
        win_repaint();
    }

    return 0;
}

static void install(win_widget_t *widget)
{
    win_add_event_handler(WIN_REPAINT_EVENT,
        1000000000, paint, (void *) widget);
    win_add_event_handler(WIN_KEY_TYPED,
        1000000000, keyhandler, (void *) widget);
    win_add_timer(cursorflash, (void *) widget, 500, 1);
}

static void deinstall(win_widget_t *widget)
{
    win_remove_event_handler(WIN_REPAINT_EVENT, paint, (void *) widget);
    win_remove_event_handler(WIN_KEY_TYPED, keyhandler, (void *) widget);
    win_remove_timer(cursorflash, (void *) widget);
}

static void destroy(win_widget_t *widget)
{
    struct win_text *text = (struct win_text *) win_wcore_get_data(widget);
    free(text->text);
    free(text);
}

static void pref_size_label(win_widget_t *widget, int *width, int *height)
{
    struct win_text *text = (struct win_text *) win_wcore_get_data(widget);

    int line = 0;
    int max_col = 0;
    int col = 0;

    char *p = text->text;

    while (1)
    {
        if (*p == '\0')
        {
            if (col > 0) line++;
            break;
        }
        else if (*p == '\n')
        {
            line++;
            col = 0;
        }
        else
        {
            if (++col > max_col) max_col = col;
        }

        p++;
    }

    hpg_font_t *font = win_widget_get_font(widget);

    *width = max_col * hpg_font_get_advance(font) + 1;
    *height = line * hpg_font_get_height(font) + 1;
}

static void pref_size_entry(win_widget_t *widget, int *width, int *height)
{
    struct win_text *text = (struct win_text *) win_wcore_get_data(widget);

    hpg_font_t *font = win_widget_get_font(widget);

    *width = (text->size + 1) * hpg_font_get_advance(font) + 1;
    *height = hpg_font_get_height(font) + 1;
}

static win_widget_t *create(char *text, int len)
{
    struct win_text *text_data = (struct win_text *)
        malloc(sizeof(struct win_text));
    memset((void *) text_data, 0, sizeof(struct win_text));

    text_data->text = (char *) malloc((len + 1) * sizeof(char));
    text_data->text[0] = '\0';
    text_data->size = len;
    text_data->pos = 0;
    text_data->cursor_vis = 0;

    if (text != NULL) strcpy(text_data->text, text);

    return win_wcore_alloc(
        install, deinstall, destroy,
        (text == NULL) ? pref_size_entry : pref_size_label,
        (text == NULL), (void *) text_data);
}

win_widget_t *win_text_new_label(char *text)
{
    return create(text, strlen(text));
}

win_widget_t *win_text_new_entry(int len)
{
    return create(NULL, len);
}
