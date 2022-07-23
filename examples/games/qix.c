#include <hpgcc49.h>
#include <hpgraphics.h>
/*
 * Initial bounds of the field.
 */
#define FIELD_X1 5
#define FIELD_X2 124
#define FIELD_Y1 10
#define FIELD_Y2 76

/*
 * Size of the players.
 */
#define BALL_RADIUS 5
#define YOU_RADIUS  2

/*
 * Number of lives.
 */
#define NLIVES 3

/*
 * Current bounds of the field.
 */
static int x1 = FIELD_X1, y1 = FIELD_Y1, x2 = FIELD_X2, y2 = FIELD_Y2;

/*
 * Position and velocity of the ball.
 */
static int ball_x = (FIELD_X1 + FIELD_X2) / 2;
static int ball_y = (FIELD_Y1 + FIELD_Y2) / 2;
static int ball_vx = 1, ball_vy = 1;

/*
 * Position and velocity of the player.
 */
static int you_x = FIELD_X1;
static int you_y = FIELD_Y1;
static int you_vx = 0, you_vy = 0;

/*
 * Current number of lives left.
 */
static int lives = NLIVES;

/*
 * Point at which the player left the side of the box.
 */
static int x_start, y_start;

/*
 * Flag indicating that the player wishes to quit.
 */
static int should_exit = 0;

static int kludge = 8000;

static int is_on_horiz_wall()
{
    return (you_y == y1) || (you_y == y2);
}

static int is_on_vert_wall()
{
    return (you_x == x1) || (you_x == x2);
}

static int is_on_wall()
{
    return is_on_horiz_wall() || is_on_vert_wall();
}

static void draw_screen()
{
    unsigned int i;
    char buf[5];

    i = (x2 - x1) * (y2 - y1);
    i *= 100;
    i /= (FIELD_X2 - FIELD_X1) * (FIELD_Y2 - FIELD_Y1);

    utoa(i, buf, 10);
    strcat(buf, "%");

    hpg_clear();

    hpg_draw_text(buf, 131 - 20, FIELD_Y1 - (6 + 1));
    for (i = 0; i < lives; i++)
    {
        hpg_fill_circle(FIELD_X1 + (2 * i * (YOU_RADIUS + 1)),
            FIELD_Y1 - (6 + 1), YOU_RADIUS);
    }

    hpg_draw_rect(x1, y1, x2, y2);

    hpg_fill_circle(ball_x, ball_y, BALL_RADIUS);
    hpg_fill_circle(you_x, you_y, YOU_RADIUS);

    hpg_draw_line(x_start, y_start, you_x, you_y);
}

int main()
{
    int old_rtc;

    sys_setupTimers();
    hpg_set_mode_mono(1);

    hpg_clear();
    hpg_flip();
    hpg_clear();

    while (!should_exit)
    {
        int was_wall;

        if (is_on_wall())
        {
            you_vx = 0;
            you_vy = 0;

            x_start = you_x;
            y_start = you_y;

            was_wall = 1;

            if (keyb_isUp())
            {
                you_vx = 0;
                you_vy = -1;
            }
            else if (keyb_isDown())
            {
                you_vx = 0;
                you_vy = 1;
            }
            else if (keyb_isRight())
            {
                you_vx = 1;
                you_vy = 0;
            }
            else if (keyb_isLeft())
            {
                you_vx = -1;
                you_vy = 0;
            }
        }
        else
        {
            int path_x1, path_x2, path_y1, path_y2;

            was_wall = 0;

            path_x1 = min(x_start, you_x);
            path_x2 = max(x_start, you_x);

            path_y1 = min(y_start, you_y);
            path_y2 = max(y_start, you_y);

            if ((ball_x >= path_x1 - BALL_RADIUS)
                && (ball_x <= path_x2 + BALL_RADIUS)
                && (ball_y >= path_y1 - BALL_RADIUS)
                && (ball_y <= path_y2 + BALL_RADIUS))
            {
                /* Collision! */

                if (--lives < 0)
                {
                    /* Game over */

                    x1 = FIELD_X1;
                    y1 = FIELD_Y1;
                    x2 = FIELD_X2;
                    y2 = FIELD_Y2;

                    you_x = FIELD_X1;
                    you_y = FIELD_Y1;
                    you_vx = you_vy = 0;

                    x_start = you_x;
                    y_start = you_y;

                    was_wall = 1;
                    lives = NLIVES;
                }
                else
                {
                    /* Restore state from before collision */

                    you_x = x_start;
                    you_y = y_start;
                    you_vx = you_vy = 0;

                    was_wall = 1;
                }
            }
        }

        if (keyb_isON()) should_exit = 1;
        if (keyb_isKeyPressed(0, 5) && (kludge >= 100)) kludge -= 100;
        if (keyb_isKeyPressed(0, 4) && (kludge <= 32000)) kludge += 100;

        if ((you_vx == -1) && (you_x <= x1)) you_vx = 0;
        if ((you_vx == 1) && (you_x >= x2)) you_vx = 0;

        if ((you_vy == -1) && (you_y <= y1)) you_vy = 0;
        if ((you_vy == 1) && (you_y >= y2)) you_vy = 0;

        if (((ball_vx == -1) && (ball_x <= x1 + BALL_RADIUS))
            || ((ball_vx == 1) && (ball_x >= x2 - BALL_RADIUS)))
        {
            ball_vx = -ball_vx;
        }

        if (((ball_vy == -1) && (ball_y <= y1 + BALL_RADIUS))
            || ((ball_vy == 1) && (ball_y >= y2 - BALL_RADIUS)))
        {
            ball_vy = -ball_vy;
        }

        you_x += you_vx;
        you_y += you_vy;
        ball_x += ball_vx;
        ball_y += ball_vy;

        if (!was_wall && is_on_wall())
        {
            if (you_x == x_start)
            {
                if (ball_x > you_x) x1 = you_x;
                else x2 = you_x;
            }
            else
            {
                if (ball_y > you_y) y1 = you_y;
                else y2 = you_y;
            }
        }

        draw_screen();
        hpg_flip(); //swapped positions of calls, reduces flicker
        sys_waitTicks(kludge);

    }


    sys_restoreTimers();

}
