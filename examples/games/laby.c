/*
 * EXAMPLE: Laby - A Labyrinth Game
 *
 * STORY: You are stuck in a labyrinth, and you need to get out.  Each level
 * of the labyrinth has a portal (shaped like a circle) that takes you to the
 * next level.
 *
 * KEYS:
 *
 *    Up Arrow:    Move forward
 *    Down Arrow:  Move backward
 *    Right Arrow: Turn right
 *    Left Arrow:  Turn left
 *
 *    ALPHA:       Toggle map
 *    ON:          Quit game
 *
 * On each level, you are given a starting point, and must find the portal.
 * You have a blank map, which will automatically be updated with information
 * you gather as you travel around the maze.  When you find the portal, you
 * are automatically transported into the next level, and you start over
 * with a new map.
 */

#include <hpgcc49.h>
#include <hpgraphics.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

typedef struct
{
    /* Boolean fields indicate locations of rooms */
    unsigned up : 1;
    unsigned down : 1;
    unsigned left : 1;
    unsigned right : 1;

    unsigned visited : 1;
    unsigned exit : 1;
} room;

typedef struct
{
    signed char x;
    signed char y;
} loc;

static room rooms[MAZE_WIDTH][MAZE_HEIGHT];

#define DIR_UP 0
#define DIR_RIGHT 1
#define DIR_DOWN 2
#define DIR_LEFT 3

static int player_x, player_y;
static int player_dir;
static int show_map = 0;

static int should_quit = 0;

static int clockwise_dir(int orig)
{
    int dir = orig;

    dir += 1;
    if (dir > 3) dir -= 4;

    return dir;
}

static int opposite_dir(int orig)
{
    int dir = orig;

    dir += 2;
    if (dir > 3) dir -= 4;

    return dir;
}

static int counterclockwise_dir(int orig)
{
    int dir = orig;

    dir += 3;
    if (dir > 3) dir -= 4;

    return dir;
}

static int in_bounds(loc l)
{
    if (l.x < 0) return 0;
    if (l.y < 0) return 0;
    if (l.x >= MAZE_WIDTH) return 0;
    if (l.y >= MAZE_HEIGHT) return 0;

    return 1;
}

static loc move(loc start, int dir, int amt)
{
    loc result;

    switch (dir)
    {
        case DIR_UP:
            result.x = start.x; result.y = start.y - amt; return result;
        case DIR_DOWN:
            result.x = start.x; result.y = start.y + amt; return result;
        case DIR_LEFT:
            result.x = start.x - amt; result.y = start.y; return result;
        case DIR_RIGHT:
            result.x = start.x + amt; result.y = start.y; return result;
    }

    return start;
}

static unsigned is_wall(room r, int dir)
{
    switch (dir)
    {
        case DIR_UP: return r.up;
        case DIR_DOWN: return r.down;
        case DIR_LEFT: return r.left;
        case DIR_RIGHT: return r.right;
    }

    return 1;
}

static void set_wall(room *r, int dir, unsigned val)
{
    switch (dir)
    {
        case DIR_UP: r->up = val; break;
        case DIR_DOWN: r->down = val; break;
        case DIR_LEFT: r->left = val; break;
        case DIR_RIGHT: r->right = val; break;
    }
}

static void search_endpoints(int parent_x, int parent_y, int x, int y,
    int *deepest_x, int *deepest_y, int *depth,
    int *longest_x1, int *longest_x2,
    int *longest_y1, int *longest_y2,
    int *length)
{
    int i;

    int sec_deep_x, sec_deep_y, sec_depth;

    int dx[] = { 0, -1, 0, 1 };
    int dy[] = { 1, 0, -1, 0 };
    int nd[] = { DIR_DOWN, DIR_LEFT, DIR_UP, DIR_RIGHT };

    *depth = 0;
    sec_depth = 0;
    *length = 0;

    *deepest_x = x;
    *deepest_y = y;
    sec_deep_x = x;
    sec_deep_y = y;

    *longest_x1 = x;
    *longest_x2 = x;
    *longest_y1 = y;
    *longest_y2 = y;

    for (i = 0; i < 4; i++)
    {
        int sub_deep_x, sub_deep_y, sub_depth;
        int sub_long_x1, sub_long_x2, sub_long_y1, sub_long_y2, sub_length;

        int child_x = x + dx[i];
        int child_y = y + dy[i];

        if ((child_x < 0) || (child_x >= MAZE_WIDTH)) continue;
        if ((child_y < 0) || (child_y >= MAZE_HEIGHT)) continue;
        if ((child_x == parent_x) && (child_y == parent_y)) continue;
        if (is_wall(rooms[x][y], nd[i])) continue;

        search_endpoints(x, y, child_x, child_y,
            &sub_deep_x, &sub_deep_y, &sub_depth,
            &sub_long_x1, &sub_long_x2,
            &sub_long_y1, &sub_long_y2, &sub_length);

        if (sub_depth + 1 > *depth)
        {
            sec_depth = *depth;
            sec_deep_x = *deepest_x;
            sec_deep_y = *deepest_y;

            *depth = sub_depth + 1;
            *deepest_x = sub_deep_x;
            *deepest_y = sub_deep_y;
        }
        else if (sub_depth + 1 > sec_depth)
        {
            sec_depth = sub_depth + 1;
            sec_deep_x = sub_deep_x;
            sec_deep_y = sub_deep_y;
        }

        if (sub_length > *length)
        {
            *length = sub_length;
            *longest_x1 = sub_long_x1;
            *longest_x2 = sub_long_x2;
            *longest_y1 = sub_long_y1;
            *longest_y2 = sub_long_y2;
        }
    }

    if (*depth + sec_depth > *length)
    {
        /*
         * Build a new longest path.
         */

        *length = *depth + sec_depth;
        *longest_x1 = *deepest_x;
        *longest_y1 = *deepest_y;
        *longest_x2 = sec_deep_x;
        *longest_y2 = sec_deep_y;
    }
}

static void get_furthest_endpoints(int *x1, int *y1, int *x2, int *y2)
{
    int deep_x, deep_y, depth, length;

    search_endpoints(-1, -1, 0, 0,
        &deep_x, &deep_y, &depth,
        x1, x2, y1, y2, &length);
}

static void generate_recursive(int x, int y)
{
    unsigned neighbors, target, i;

    /*
     * Color this room.
     */
    rooms[x][y].visited = 0;

    while (1)
    {
        loc l = { x, y };
        int dir;

        /*
         * Count unvisited neighbors.
         */
        neighbors = 0;

        for (dir = 0; dir < 4; dir++)
        {
            loc nl = move(l, dir, 1);
            if (!in_bounds(nl)) continue;

            if (rooms[nl.x][nl.y].visited == 1) neighbors++;
        }

        if (neighbors == 0) return;

        /*
         * Pick a random unvisited neighbor.
         */
        target = rand() % neighbors;

        /*
         * Find the target neighbor and process it.
         */
        i = -1;
        for (dir = 0; dir < 4; dir++)
        {
            loc nl = move(l, dir, 1);
            if (!in_bounds(nl)) continue;

            if (rooms[nl.x][nl.y].visited == 1)
            {
                if (++i == target)
                {
                    set_wall(&(rooms[l.x][l.y]), dir, 0);
                    set_wall(&(rooms[nl.x][nl.y]), opposite_dir(dir), 0);

                    generate_recursive(nl.x, nl.y);
                }
            }
        }
    }
}

static void generate_maze()
{
    int x, y, i;

    for (x = 0; x < MAZE_WIDTH; x++)
    {
        for (y = 0; y < MAZE_HEIGHT; y++)
        {
            rooms[x][y].up = 1;
            rooms[x][y].down = 1;
            rooms[x][y].left = 1;
            rooms[x][y].right = 1;

            rooms[x][y].visited = 1;
            rooms[x][y].exit = 0;
        }
    }

    generate_recursive(rand() % MAZE_WIDTH, rand() % MAZE_HEIGHT);

    get_furthest_endpoints(&player_x, &player_y, &x, &y);

    rooms[player_x][player_y].visited = 1;
    for (i = 0; i < 4; i++)
    {
        if (!is_wall(rooms[player_x][player_y], i))
        {
            player_dir = i;
            break;
        }
    }

    rooms[x][y].exit = 1;
/*
    switch (rand() % 4)
    {
        case 0: rooms[0][0].exit = 1; break;
        case 1: rooms[MAZE_WIDTH - 1][0].exit = 1; break;
        case 2: rooms[0][MAZE_HEIGHT - 1].exit = 1; break;
        case 3: rooms[MAZE_WIDTH - 1][MAZE_HEIGHT - 1].exit = 1; break;
    }
*/
}

#define SZ 4

static void draw_map()
{
    int i, j;

    hpg_set_color(hpg_stdscreen, HPG_COLOR_WHITE);
    hpg_fill_rect(0, 0, SZ * MAZE_WIDTH, SZ * MAZE_HEIGHT);

    for (i = 0; i < MAZE_WIDTH; i++)
    {
        for (j = 0; j < MAZE_HEIGHT; j++)
        {
            int x1 = i * SZ;
            int x2 = (i + 1) * SZ;
            int y1 = j * SZ;
            int y2 = (j + 1) * SZ;

            if (rooms[i][j].visited)
            {
                hpg_set_color(hpg_stdscreen, HPG_COLOR_BLACK);

                if (rooms[i][j].up) hpg_draw_line(x1, y1, x2, y1);
                if (rooms[i][j].down) hpg_draw_line(x1, y2, x2, y2);
                if (rooms[i][j].left) hpg_draw_line(x1, y1, x1, y2);
                if (rooms[i][j].right) hpg_draw_line(x2, y1, x2, y2);
            }
            else
            {
                if (i > 0) x1++;
                if (j > 0) y1++;
                if (i < MAZE_WIDTH - 1) x2--;
                if (j < MAZE_HEIGHT - 1) y2--;

                hpg_set_color(hpg_stdscreen, HPG_COLOR_GRAY_8);
                hpg_fill_rect(x1, y1, x2, y2);
            }
        }
    }

    hpg_set_color(hpg_stdscreen, HPG_COLOR_BLACK);
    hpg_draw_rect(0, 0, SZ * MAZE_WIDTH, SZ * MAZE_HEIGHT);
    hpg_draw_circle(
        player_x * SZ + SZ / 2,
        player_y * SZ + SZ / 2,
        SZ / 2 - 1);
}

#define HORIZON 3
#define SCALE 35

static void draw_3d()
{
    int i, j;
    loc start = { player_x, player_y };

    hpg_clear();

    for (i = HORIZON; i >= 0; i--)
    {
        for (j = HORIZON; j >= 0; j--)
        {
            int xvert[4], yvert[4];

            int color = 12 - 12 * (i * i + j * j) / (2 * HORIZON * HORIZON);

            if (j == 0)
            {
                /*
                 * Draw center room.
                 */
                loc cur = start;
                cur = move(cur, player_dir, i);

                if (in_bounds(cur))
                {
                    room r = rooms[cur.x][cur.y];

                    if (is_wall(r, player_dir))
                    {
                        /*
                         * Draw back wall.
                         */

                        xvert[0] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                        yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                        xvert[1] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                        yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                        xvert[2] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                        yvert[2] = -2 * SCALE / (i * 4 + 2) + 40;

                        xvert[3] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                        yvert[3] = 2 * SCALE / (i * 4 + 2) + 40;

                        hpg_set_color(hpg_stdscreen, color * 16);
                        hpg_fill_polygon(xvert, yvert, 4);
                        hpg_set_color(hpg_stdscreen, color * 16 + 16);
                        hpg_draw_polygon(xvert, yvert, 4);
                    }
                    if (is_wall(r, counterclockwise_dir(player_dir)))
                    {
                        /*
                         * Draw left wall.
                         */

                        xvert[0] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                        yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                        xvert[1] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                        yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                        if (i == 0)
                        {
                            xvert[2] = SCALE * (-j * 4 - 2) / (i * 4 + 1) + 65;
                            yvert[2] = -2 * SCALE / (i * 4 + 1) + 40;

                            xvert[3] = SCALE * (-j * 4 - 2) / (i * 4 + 1) + 65;
                            yvert[3] = 2 * SCALE / (i * 4 + 1) + 40;
                        }
                        else
                        {
                            xvert[2] = SCALE * (-j * 4 - 2) / (i * 4 - 2) + 65;
                            yvert[2] = -2 * SCALE / (i * 4 - 2) + 40;

                            xvert[3] = SCALE * (-j * 4 - 2) / (i * 4 - 2) + 65;
                            yvert[3] = 2 * SCALE / (i * 4 - 2) + 40;
                        }

                        hpg_set_color(hpg_stdscreen, color * 16);
                        hpg_fill_polygon(xvert, yvert, 4);
                        hpg_set_color(hpg_stdscreen, color * 16 + 16);
                        hpg_draw_polygon(xvert, yvert, 4);
                    }
                    if (is_wall(r, clockwise_dir(player_dir)))
                    {
                        /*
                         * Draw right wall.
                         */

                        xvert[0] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                        yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                        xvert[1] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                        yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                        if (i == 0)
                        {
                            xvert[2] = SCALE * (-j * 4 + 2) / (i * 4 + 1) + 65;
                            yvert[2] = -2 * SCALE / (i * 4 + 1) + 40;

                            xvert[3] = SCALE * (-j * 4 + 2) / (i * 4 + 1) + 65;
                            yvert[3] = 2 * SCALE / (i * 4 + 1) + 40;
                        }
                        else
                        {
                            xvert[2] = SCALE * (-j * 4 + 2) / (i * 4 - 2) + 65;
                            yvert[2] = -2 * SCALE / (i * 4 - 2) + 40;

                            xvert[3] = SCALE * (-j * 4 + 2) / (i * 4 - 2) + 65;
                            yvert[3] = 2 * SCALE / (i * 4 - 2) + 40;
                        }

                        hpg_set_color(hpg_stdscreen, color * 16);
                        hpg_fill_polygon(xvert, yvert, 4);
                        hpg_set_color(hpg_stdscreen, color * 16 + 16);
                        hpg_draw_polygon(xvert, yvert, 4);
                    }
                    if ((i != 0) && r.exit)
                    {
                        /*
                         * Draw exit.
                         */

                        int r;
                        r = SCALE / (i + 1);

                        hpg_set_color(hpg_stdscreen, HPG_COLOR_WHITE);
                        hpg_fill_circle(65, 40, r);
                        hpg_set_color(hpg_stdscreen, color * 16 + 16);
                        hpg_draw_circle(65, 40, r);
                    }
                }
            }
            else
            {
                /*
                 * Draw left room.
                 */
                {
                    loc cur = start;
                    cur = move(cur, player_dir, i);
                    cur = move(cur, clockwise_dir(player_dir), -j);

                    if (in_bounds(cur))
                    {
                        room r = rooms[cur.x][cur.y];

                        if (is_wall(r, player_dir))
                        {
                            /*
                             * Draw back wall.
                             */

                            xvert[0] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                            xvert[1] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                            xvert[2] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[2] = -2 * SCALE / (i * 4 + 2) + 40;

                            xvert[3] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[3] = 2 * SCALE / (i * 4 + 2) + 40;

                            hpg_set_color(hpg_stdscreen, color * 16);
                            hpg_fill_polygon(xvert, yvert, 4);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_polygon(xvert, yvert, 4);
                        }
                        if (is_wall(r, counterclockwise_dir(player_dir)))
                        {
                            /*
                             * Draw left wall.
                             */

                            xvert[0] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                            xvert[1] = SCALE * (-j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                            if (i == 0)
                            {
                                xvert[2] = SCALE * (-j * 4 - 2) / (i * 4 + 1) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 + 1) + 40;

                                xvert[3] = SCALE * (-j * 4 - 2) / (i * 4 + 1) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 + 1) + 40;
                            }
                            else
                            {
                                xvert[2] = SCALE * (-j * 4 - 2) / (i * 4 - 2) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 - 2) + 40;

                                xvert[3] = SCALE * (-j * 4 - 2) / (i * 4 - 2) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 - 2) + 40;
                            }

                            hpg_set_color(hpg_stdscreen, color * 16);
                            hpg_fill_polygon(xvert, yvert, 4);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_polygon(xvert, yvert, 4);
                        }
                        if ((i != 0) && r.exit)
                        {
                            /*
                             * Draw exit.
                             */

                            int x, r;
                            x = SCALE * (-j * 4) / (i * 4) + 65;
                            r = SCALE / (i + 1);

                            hpg_set_color(hpg_stdscreen, HPG_COLOR_WHITE);
                            hpg_fill_circle(x, 40, r);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_circle(x, 40, r);
                        }
                        if (is_wall(r, clockwise_dir(player_dir)))
                        {
                            /*
                             * Draw right wall.
                             */

                            xvert[0] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                            xvert[1] = SCALE * (-j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                            if (i == 0)
                            {
                                xvert[2] = SCALE * (-j * 4 + 2) / (i * 4 + 1) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 + 1) + 40;

                                xvert[3] = SCALE * (-j * 4 + 2) / (i * 4 + 1) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 + 1) + 40;
                            }
                            else
                            {
                                xvert[2] = SCALE * (-j * 4 + 2) / (i * 4 - 2) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 - 2) + 40;

                                xvert[3] = SCALE * (-j * 4 + 2) / (i * 4 - 2) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 - 2) + 40;
                            }

                            hpg_set_color(hpg_stdscreen, color * 16);
                            hpg_fill_polygon(xvert, yvert, 4);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_polygon(xvert, yvert, 4);
                        }
                    }
                }

                /*
                 * Draw right room.
                 */
                {
                    loc cur = start;
                    cur = move(cur, player_dir, i);
                    cur = move(cur, clockwise_dir(player_dir), +j);

                    if (in_bounds(cur))
                    {
                        room r = rooms[cur.x][cur.y];

                        if (is_wall(r, player_dir))
                        {
                            /*
                             * Draw back wall.
                             */

                            xvert[0] = SCALE * (j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                            xvert[1] = SCALE * (j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                            xvert[2] = SCALE * (j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[2] = -2 * SCALE / (i * 4 + 2) + 40;

                            xvert[3] = SCALE * (j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[3] = 2 * SCALE / (i * 4 + 2) + 40;

                            hpg_set_color(hpg_stdscreen, color * 16);
                            hpg_fill_polygon(xvert, yvert, 4);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_polygon(xvert, yvert, 4);
                        }
                        if (is_wall(r, clockwise_dir(player_dir)))
                        {
                            /*
                             * Draw right wall.
                             */

                            xvert[0] = SCALE * (j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                            xvert[1] = SCALE * (j * 4 + 2) / (i * 4 + 2) + 65;
                            yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                            if (i == 0)
                            {
                                xvert[2] = SCALE * (j * 4 + 2) / (i * 4 + 1) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 + 1) + 40;

                                xvert[3] = SCALE * (j * 4 + 2) / (i * 4 + 1) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 + 1) + 40;
                            }
                            else
                            {
                                xvert[2] = SCALE * (j * 4 + 2) / (i * 4 - 2) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 - 2) + 40;

                                xvert[3] = SCALE * (j * 4 + 2) / (i * 4 - 2) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 - 2) + 40;
                            }

                            hpg_set_color(hpg_stdscreen, color * 16);
                            hpg_fill_polygon(xvert, yvert, 4);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_polygon(xvert, yvert, 4);
                        }
                        if ((i != 0) && r.exit)
                        {
                            /*
                             * Draw exit.
                             */

                            int x, r;
                            x = SCALE * (j * 4) / (i * 4) + 65;
                            r = SCALE / (i + 1);

                            hpg_set_color(hpg_stdscreen, HPG_COLOR_WHITE);
                            hpg_fill_circle(x, 40, r);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_circle(x, 40, r);
                        }
                        if (is_wall(r, counterclockwise_dir(player_dir)))
                        {
                            /*
                             * Draw left wall.
                             */

                            xvert[0] = SCALE * (j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[0] = 2 * SCALE / (i * 4 + 2) + 40;

                            xvert[1] = SCALE * (j * 4 - 2) / (i * 4 + 2) + 65;
                            yvert[1] = -2 * SCALE / (i * 4 + 2) + 40;

                            if (i == 0)
                            {
                                xvert[2] = SCALE * (j * 4 - 2) / (i * 4 + 1) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 + 1) + 40;

                                xvert[3] = SCALE * (j * 4 - 2) / (i * 4 + 1) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 + 1) + 40;
                            }
                            else
                            {
                                xvert[2] = SCALE * (j * 4 - 2) / (i * 4 - 2) + 65;
                                yvert[2] = -2 * SCALE / (i * 4 - 2) + 40;

                                xvert[3] = SCALE * (j * 4 - 2) / (i * 4 - 2) + 65;
                                yvert[3] = 2 * SCALE / (i * 4 - 2) + 40;
                            }

                            hpg_set_color(hpg_stdscreen, color * 16);
                            hpg_fill_polygon(xvert, yvert, 4);
                            hpg_set_color(hpg_stdscreen, color * 16 + 16);
                            hpg_draw_polygon(xvert, yvert, 4);
                        }
                    }
                }
            }
        }
    }
}

static void draw_screen()
{
    draw_3d();
    if (show_map) draw_map();

    hpg_flip();
}

static void check_exit()
{
    if (rooms[player_x][player_y].exit)
    {
        hpg_set_color(hpg_stdscreen, HPG_COLOR_WHITE);
        hpg_fill_rect(0, 0, 131, 80);

        hpg_flip();
        sys_waitTicks(100000);

        hpg_set_color(hpg_stdscreen, HPG_COLOR_BLACK);
        hpg_fill_rect(0, 0, 131, 80);

        hpg_flip();
        sys_waitTicks(100000);

        generate_maze();
    }
}

int main(void)
{
    srand(sys_RTC_seconds());
    generate_maze();

    sys_setupTimers();

    hpg_set_mode_gray16(1);

    draw_screen();

    while (!should_quit)
    {
        if (keyb_isON())
        {
            should_quit = 1;
        }
        else if (keyb_isUp())
        {
            while (keyb_isAnyKeyPressed());

            room r = rooms[player_x][player_y];
            if (player_dir == DIR_UP && !r.up) player_y--;
            if (player_dir == DIR_DOWN && !r.down) player_y++;
            if (player_dir == DIR_LEFT && !r.left) player_x--;
            if (player_dir == DIR_RIGHT && !r.right) player_x++;

            rooms[player_x][player_y].visited = 1;

            check_exit();
            draw_screen();
        }
        else if (keyb_isDown())
        {
            while (keyb_isAnyKeyPressed());

            room r = rooms[player_x][player_y];
            if (player_dir == DIR_DOWN && !r.up) player_y--;
            if (player_dir == DIR_UP && !r.down) player_y++;
            if (player_dir == DIR_RIGHT && !r.left) player_x--;
            if (player_dir == DIR_LEFT && !r.right) player_x++;

            rooms[player_x][player_y].visited = 1;

            check_exit();
            draw_screen();
        }
        else if (keyb_isLeft())
        {
            while (keyb_isAnyKeyPressed());
            if (--player_dir < 0) player_dir += 4;

            draw_screen();
        }
        else if (keyb_isRight())
        {
            while (keyb_isAnyKeyPressed());
            if (++player_dir > 3) player_dir -= 4;

            draw_screen();
        }
        else if (keyb_isAlpha())
        {
            while (keyb_isAnyKeyPressed());
            show_map = !show_map;

            draw_screen();
        }

    }

    sys_restoreTimers();

}
