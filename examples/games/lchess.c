/* Simple chess game for the HP49G+ calculator in C. 

$Header: /cvsroot/hpgcc/examples/games/lchess.c,v 1.4 2005/04/04 13:09:09 alborowski Exp $

*/

#include <hpgcc49.h>
#include <hpgraphics.h>

/*
 * Search depth; increase for longer thoughts but better moves; decrease for
 * quicker, less skilled play by the computer.  Even numbers are usually best.
 */
#define DEPTH 2

/* Generic sized types -- adjust per platform.  These appear to be okay for
 * the ARM.
 */

typedef unsigned char          uint8;
typedef unsigned short int     uint16;
typedef unsigned long int      uint32;
typedef unsigned long long int uint64;

/* Format for storage of a chess piece:
 *
 * 8 bits unsigned: x y y y 0 0 0 0
 * where x   = the color (0 for white, 1 for black)
 *       yyy = the piece (see defines below for codes)
 *
 * The bottom four bits are simply padding to fit the piece into a byte of
 * storage on the host.
 */
typedef uint8 piece;

#define P_K       0x10
#define P_Q       0x20
#define P_R       0x30
#define P_B       0x40
#define P_N       0x50
#define P_P       0x60

#define WHITE 0x00
#define BLACK 0x80

/*
 * Macros to build pieces.  WPIECE and BPIECE are just there for convenience
 * when the color of the piece being built is known in advance (notably when
 * defining the board initializer).
 */
#define PIECE(type, color)          ((type) | (color))
#define WPIECE(type)                (PIECE((type), WHITE))
#define BPIECE(type)                (PIECE((type), BLACK))

/*
 * Macros to get information about an existing piece.
 */
#define PCOLOR(piece)               ((piece) & 0x80)
#define PTYPE(piece)                ((piece) & 0x70)

#define OPPCOLOR(color)             ((color) ^ 0x80)

/*
 * Definition of the character representations of pieces.  Standard
 * chess notation is used, with the convention that white pieces are
 * upper-case, while black pieces are lower-case.
 */
static const char charof[128] =
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x08, 0x1C, 0x08, 0x14, 0x14, 0x22, 0x7F, 0x00,
	  0x1C, 0x22, 0x1C, 0x08, 0x14, 0x22, 0x7F, 0x00,
	  0x00, 0x2A, 0x36, 0x22, 0x22, 0x22, 0x3E, 0x00,
	  0x00, 0x08, 0x14, 0x14, 0x14, 0x08, 0x3E, 0x00,
	  0x00, 0x1C, 0x22, 0x32, 0x0A, 0x14, 0x3E, 0x00,
	  0x00, 0x00, 0x08, 0x14, 0x08, 0x14, 0x1C, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	  0x08, 0x1C, 0x08, 0x1C, 0x1C, 0x3E, 0x7F, 0x00,
	  0x1C, 0x3E, 0x1C, 0x08, 0x1C, 0x3E, 0x7F, 0x00,
	  0x00, 0x2A, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x00,
	  0x00, 0x08, 0x1C, 0x1C, 0x1C, 0x08, 0x3E, 0x00,
	  0x00, 0x1C, 0x3E, 0x3E, 0x0E, 0x1C, 0x3E, 0x00,
	  0x00, 0x00, 0x08, 0x1C, 0x08, 0x1C, 0x1C, 0x00,
	  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

#define PCHAROF(piece)              ((char *) (charof + 8 * (piece >> 4)))

/*
 * Definition of the value of a piece for computer thinking.  Normal chess
 * values are used.
 */
static const int valof[7] = {0, 0, 9, 5, 3, 3, 1 };
#define PVALOF(piece)               (valof[PTYPE(piece) >> 4])

/* Format for storage of a board position:
 *
 * 8 bits unsigned: 0 x x x 0 y y y
 * where xxx = row, 0 through 7, beginning with black's home row (ie backwards)
 *       yyy = col, 0 through 7, normal direction
 */
typedef uint8 boardpos;

/*
 * Macros to build and get properties of a position on the board.
 */
#define POS(row, col)               (((row) << 4) | (col))
#define POSROW(pos)                 ((pos) >> 4)
#define POSCOL(pos)                 ((pos) & 0x0F)

/* Format for a move:
 *
 * 16 bits unsigned; basically two positions, starting and ending, concatenated
 * onto each other.
 */
typedef uint16 boardmove;

/*
 * Macros to build and get properties of a move.
 */
#define MOVE(from, to)              (((from) << 8) | (to))
#define MOVEFROM(move)              ((char)((move) >> 8))
#define MOVETO(move)                ((char)((move) & 0xFF))
#define PMOVING(b, move)            (GETPIECE((b), MOVEFROM(move)))

/* Board coverage format:
 *
 * This is a generic form to represent board coverage of any side.  The format
 * is simply a series of bits; 1 if a square is covered or 0 if not.  The
 * board coverage is used in computer thinking, but also in determining game
 * results (whether the king is in check) and legal moves (king can't move
 * into check or castle across check).
 */
typedef uint64 boardcov;

/*
 * COVMARK: Macro to set a bit of the board coverage map corresponding to the
 * given row and column.
 */
#define COVMARK(cov, row, col) ((cov) |= ((uint64)1 << (8 * (row) + (col))))

/*
 * ISCOV: Macro to query the board coverage of a specific position.
 */
#define ISCOV(cov, row, col)   ((cov) & ((uint64)1 << (8 * (row) + (col))))

/*
 * This initializer should be used as an initial value for building a board
 * coverage map.  It represents no coverage at all.
 */
#define BCOV_INITIALIZER       (uint64)0

/* Board format:
 *
 * An 8 x 8 array of pieces, representing the pieces on the board.  A value of
 * 0 (which is not a valid piece) in the most significant four bits means that
 * the square is empty; otherwise, the most significant four bits match a piece
 * value for the piece on that square.
 * 
 * Additional game state is stored in the least significant bits as follows:
 * 
 * The first square's ([0][0]) least significant four bits are:
 *
 * a b c d, where a == 1 if black can still castle queen side
 *                b == 1 if black can still castle king side
 *                c == 1 if white can still castle queen side
 *                d == 1 if white can still castle king side
 *
 * The least significant four bits of the second square ([0][1]) form the
 * number of a column on the board.  This number is set to the column number of
 * a pawn that moved two squares from it's starting position on the last move,
 * and is then reset for the next move.  If the last move was not a pawn moving
 * two squares, then this number is set to 0x0F to indicate that.  This value
 * can be used to determine the legality of a move in which a pawn is taken en
 * passant.
 *
 * The justification for sticking these values into the board structure is that
 * if that is done, then the entire state of a game (minus whose move it is,
 * which is always tracked implicitly) can fit into a 64-byte board structure,
 * which is a nice round number and more likely to fit into cache on some
 * architectures.
 */
typedef piece board[8][8];

/*
 * GETPIECE and SETPIECE: macros to get and set the contents of certain
 * squares of the board.  'b' is the board; 'p' is the piece, and 'pos' is the
 * board position.
 */
#define GETPIECE(b, pos)            ((b)[POSROW(pos)][POSCOL(pos)] & 0xF0)
#define SETPIECE(b, p, pos)         ((b)[POSROW(pos)][POSCOL(pos)] =          \
                                     ((b)[POSROW(pos)][POSCOL(pos)] & 0x0F) | \
                                     (p))

/*
 * CASTLEK and CASTLEQ: macros to check if the given color may still castle
 * on one side of the board.
 */
#define CASTLEK(b, color)           ((b)[0][0] & ((color) ? 0x04 : 0x01))
#define CASTLEQ(b, color)           ((b)[0][0] & ((color) ? 0x08 : 0x02))

/*
 * ENPASSCOL: determine the column of a pawn which may be taken en passant
 * this move, or 0x0F if no such pawn exists.
 */
#define ENPASSCOL(b)                ((b)[0][1] & 0x0F)

/*
 * Macros to prevent castling.  NOCASTLE prevents any castling from the given
 * side, and is to be used when the king is moved.  NOKCASTLE and NOQCASTLE
 * prevent castling, respectively, just on king-side or queen-side, and are
 * to be used when the rook is moved.
 */
#define NOCASTLE(b, color)          ((b)[0][0] &= ((color) ? 0xF3 : 0xFC))
#define NOKCASTLE(b, color)         ((b)[0][0] &= ((color) ? 0xFB : 0xFE))
#define NOQCASTLE(b, color)         ((b)[0][0] &= ((color) ? 0xF7 : 0xFD))

/*
 * SETENPASS: Macro to set the column of the pawn which may be taken en passant
 * this move.  0x0F should be passed to indicate that there is no such pawn.
 */
#define SETENPASS(b, col)           ((b)[0][1] = ((b)[0][1] & 0xF0) | (col))

/*
 * This initializer for a chess board.  This sets up a pristine board for a
 * new game.
 */
#define BOARD_INITIALIZER {                                         \
{ BPIECE(P_R) | 0x0F, BPIECE(P_N) | 0x0F, BPIECE(P_B), BPIECE(P_Q), \
    BPIECE(P_K), BPIECE(P_B), BPIECE(P_N), BPIECE(P_R) },           \
{ BPIECE(P_P), BPIECE(P_P), BPIECE(P_P), BPIECE(P_P),               \
    BPIECE(P_P), BPIECE(P_P), BPIECE(P_P), BPIECE(P_P) },           \
{ 0, 0, 0, 0, 0, 0, 0 },                                            \
{ 0, 0, 0, 0, 0, 0, 0 },                                            \
{ 0, 0, 0, 0, 0, 0, 0 },                                            \
{ 0, 0, 0, 0, 0, 0, 0 },                                            \
{ WPIECE(P_P), WPIECE(P_P), WPIECE(P_P), WPIECE(P_P),               \
    WPIECE(P_P), WPIECE(P_P), WPIECE(P_P), WPIECE(P_P) },           \
{ WPIECE(P_R), WPIECE(P_N), WPIECE(P_B), WPIECE(P_Q),               \
    WPIECE(P_K), WPIECE(P_B), WPIECE(P_N), WPIECE(P_R) }            \
}

/*
 * MIN and MAX: obvious; used in minimax implementation
 */
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

/*
 * The board as it is, physically, at this point in the game.
 */
board master_board = BOARD_INITIALIZER;

void writeLetMF2(char a,int x, int y)
{
	char st[2];
	st[0]=a;
	st[1]=0;
	hpg_draw_text(st, x, y);
}


static void get_coverage_king(board b, boardpos p, boardcov *pcov)
{
    int i, j, r, c, rstart, rend, cstart, cend;

    r = POSROW(p);
    c = POSCOL(p);

    rstart = (r == 0) ? 0 : (r - 1);
    rend = (r == 7) ? 7 : (r + 1);
    cstart = (c == 0) ? 0 : (c - 1);
    cend = (c == 7) ? 7 : (c + 1);

    for (i = rstart; i <= rend; i++)
        for (j = cstart; j <= cend; j++)
        {
            COVMARK(*pcov, i, j);
        }
}

static void get_coverage_rook(board b, boardpos p, boardcov *pcov)
{
    int i, r, c;

    r = POSROW(p);
    c = POSCOL(p);

    for (i = r + 1; i < 8; i++)
    {
        COVMARK(*pcov, i, c);
        if (GETPIECE(b, POS(i, c)) != 0) break;
    }

    for (i = r - 1; i >= 0; i--)
    {
        COVMARK(*pcov, i, c);
        if (GETPIECE(b, POS(i, c)) != 0) break;
    }

    for (i = c + 1; i < 8; i++)
    {
        COVMARK(*pcov, r, i);
        if (GETPIECE(b, POS(r, i)) != 0) break;
    }

    for (i = c - 1; i >= 0; i--)
    {
        COVMARK(*pcov, r, i);
        if (GETPIECE(b, POS(r, i)) != 0) break;
    }
}

static void get_coverage_bishop(board b, boardpos p, boardcov *pcov)
{
    int i, r, c;

    r = POSROW(p);
    c = POSCOL(p);

    for (i = 1; ((r + i) < 8) && ((c + i) < 8); i++)
    {
        COVMARK(*pcov, r + i, c + i);
        if (GETPIECE(b, POS(r + i, c + i)) != 0) break;
    }

    for (i = 1; ((r + i) < 8) && ((c - i) >= 0); i++)
    {
        COVMARK(*pcov, r + i, c - i);
        if (GETPIECE(b, POS(r + i, c - i)) != 0) break;
    }

    for (i = 1; ((r - i) >= 0) && ((c + i) < 8); i++)
    {
        COVMARK(*pcov, r - i, c + i);
        if (GETPIECE(b, POS(r - i, c + i)) != 0) break;
    }

    for (i = 1; ((r - i) >= 0) && ((c - i) >= 0); i++)
    {
        COVMARK(*pcov, r - i, c - i);
        if (GETPIECE(b, POS(r - i, c - i)) != 0) break;
    }
}

static void get_coverage_queen(board b, boardpos p, boardcov *pcov)
{
    get_coverage_rook(b, p, pcov);
    get_coverage_bishop(b, p, pcov);
}

static void get_coverage_knight(board b, boardpos p, boardcov *pcov)
{
    int r, c;

    r = POSROW(p);
    c = POSCOL(p);

    if ((r > 1) && (c < 7)) COVMARK(*pcov, r - 2, c + 1);
    if ((r > 0) && (c < 6)) COVMARK(*pcov, r - 1, c + 2);
    if ((r < 7) && (c < 6)) COVMARK(*pcov, r + 1, c + 2);
    if ((r < 6) && (c < 7)) COVMARK(*pcov, r + 2, c + 1);
    if ((r < 6) && (c > 0)) COVMARK(*pcov, r + 2, c - 1);
    if ((r < 7) && (c > 1)) COVMARK(*pcov, r + 1, c - 2);
    if ((r > 0) && (c > 1)) COVMARK(*pcov, r - 1, c - 2);
    if ((r > 1) && (c > 0)) COVMARK(*pcov, r - 2, c - 1);
}

static void get_coverage_pawn(board b, boardpos p, boardcov *pcov)
{
    int dir, r, c;

    dir = (PCOLOR(GETPIECE(b, p)) == BLACK) ? 1 : -1;

    r = POSROW(p);
    c = POSCOL(p);

    if (c > 0) COVMARK(*pcov, r + dir, c - 1);
    if (c < 7) COVMARK(*pcov, r + dir, c + 1);
}

static boardcov get_board_coverage(board b, int color)
{
    int i, j;
    boardcov cov;

    cov = BCOV_INITIALIZER;

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {
            boardpos pos = POS(i, j);
            piece p = GETPIECE(b, pos);

            if ((PTYPE(p) == 0) || (PCOLOR(p) != color)) continue;
            switch (PTYPE(p))
            {
                case P_K:
                    get_coverage_king(b, pos, &cov);
                    break;

                case P_Q:
                    get_coverage_queen(b, pos, &cov);
                    break;

                case P_R:
                    get_coverage_rook(b, pos, &cov);
                    break;

                case P_B:
                    get_coverage_bishop(b, pos, &cov);
                    break;

                case P_N:
                    get_coverage_knight(b, pos, &cov);
                    break;

                case P_P:
                    get_coverage_pawn(b, pos, &cov);
                    break;
            }
        }
    return cov;
}

static int get_valid_moves_king(board b, boardpos p, boardmove moves[])
{
    int n, color, i, j, r, c, rstart, rend, cstart, cend;

    color = PCOLOR(GETPIECE(b, p));

    r = POSROW(p);
    c = POSCOL(p);

    rstart = (r == 0) ? 0 : (r - 1);
    rend = (r == 7) ? 7 : (r + 1);
    cstart = (c == 0) ? 0 : (c - 1);
    cend = (c == 7) ? 7 : (c + 1);

    n = 0;

    /* normal king moves */
    for (i = rstart; i <= rend; i++)
        for (j = cstart; j <= cend; j++)
        {
            piece pd;

            if ((i == r) && (j == c)) continue;

            pd = GETPIECE(b, POS(i, j));
            if ((pd == 0) || (PCOLOR(pd) != color))
                moves[n++] = MOVE(p, POS(i, j));
        }

    if ((CASTLEK(b, color)) && (GETPIECE(b, POS(r, 5)) == 0) &&
        (GETPIECE(b, POS(r, 6)) == 0))
    {
        moves[n++] = MOVE(p, POS(r, 6));
    }

    if ((CASTLEQ(b, color)) && (GETPIECE(b, POS(r, 1)) == 0) &&
        (GETPIECE(b, POS(r, 2)) == 0) && (GETPIECE(b, POS(r, 3)) == 0))
    {
        moves[n++] = MOVE(p, POS(r, 2));
    }

    return n;
}

static int get_valid_moves_rook(board b, boardpos p, boardmove moves[])
{
    int n, color, i, r, c;

    color = PCOLOR(GETPIECE(b, p));

    r = POSROW(p);
    c = POSCOL(p);

    n = 0;

    for (i = r + 1; i < 8; i++)
    {
        piece pd;
        pd = GETPIECE(b, POS(i, c));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(i, c));
        if (pd != 0) break;
    }

    for (i = r - 1; i >= 0; i--)
    {
        piece pd;
        pd = GETPIECE(b, POS(i, c));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(i, c));
        if (pd != 0) break;
    }

    for (i = c + 1; i < 8; i++)
    {
        piece pd;
        pd = GETPIECE(b, POS(r, i));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r, i));
        if (pd != 0) break;
    }

    for (i = c - 1; i >= 0; i--)
    {
        piece pd;
        pd = GETPIECE(b, POS(r, i));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r, i));
        if (pd != 0) break;
    }

    return n;
}

static int get_valid_moves_bishop(board b, boardpos p, boardmove moves[])
{
    int n, color, i, r, c;

    color = PCOLOR(GETPIECE(b, p));

    r = POSROW(p);
    c = POSCOL(p);

    n = 0;

    for (i = 1; ((r + i) < 8) && ((c + i) < 8); i++)
    {
        piece pd;
        pd = GETPIECE(b, POS(r + i, c + i));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + i, c + i));
        if (pd != 0) break;
    }

    for (i = 1; ((r + i) < 8) && ((c - i) >= 0); i++)
    {
        piece pd;
        pd = GETPIECE(b, POS(r + i, c - i));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + i, c - i));
        if (pd != 0) break;
    }

    for (i = 1; ((r - i) >= 0) && ((c + i) < 8); i++)
    {
        piece pd;
        pd = GETPIECE(b, POS(r - i, c + i));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r - i, c + i));
        if (pd != 0) break;
    }

    for (i = 1; ((r - i) >= 0) && ((c - i) >= 0); i++)
    {
        piece pd;
        pd = GETPIECE(b, POS(r - i, c - i));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r - i, c - i));
        if (pd != 0) break;
    }

    return n;
}

static int get_valid_moves_queen(board b, boardpos p, boardmove moves[])
{
    int n;

    n = get_valid_moves_rook(b, p, moves);
    n += get_valid_moves_bishop(b, p, moves + n);

    return n;
}

static int get_valid_moves_knight(board b, boardpos p, boardmove moves[])
{
    int n, color, r, c;
    piece pd;

    color = PCOLOR(GETPIECE(b, p));

    r = POSROW(p);
    c = POSCOL(p);

    n = 0;

    if ((r > 1) && (c < 7))
    {
        pd = GETPIECE(b, POS(r - 2, c + 1));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r - 2, c + 1));
    }

    if ((r > 0) && (c < 6))
    {
        pd = GETPIECE(b, POS(r - 1, c + 2));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r - 1, c + 2));
    }

    if ((r < 7) && (c < 6))
    {
        pd = GETPIECE(b, POS(r + 1, c + 2));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + 1, c + 2));
    }

    if ((r < 6) && (c < 7))
    {
        pd = GETPIECE(b, POS(r + 2, c + 1));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + 2, c + 1));
    }

    if ((r < 6) && (c > 0))
    {
        pd = GETPIECE(b, POS(r + 2, c - 1));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + 2, c - 1));
    }

    if ((r < 7) && (c > 1))
    {
        pd = GETPIECE(b, POS(r + 1, c - 2));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + 1, c - 2));
    }

    if ((r > 0) && (c > 1))
    {
        pd = GETPIECE(b, POS(r - 1, c - 2));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r - 1, c - 2));
    }

    if ((r > 1) && (c > 0))
    {
        pd = GETPIECE(b, POS(r - 2, c - 1));
        if ((pd == 0) || (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r - 2, c - 1));
    }

    return n;
}

static int get_valid_moves_pawn(board b, boardpos p, boardmove moves[])
{
    int color, dir, r, c, n;

    color = PCOLOR(GETPIECE(b, p));
    dir = (color == BLACK) ? 1 : -1;

    r = POSROW(p);
    c = POSCOL(p);

    n = 0;

    if (GETPIECE(b, POS(r + dir, c)) == 0)
    {
        /* normal pawn move */
        moves[n++] = MOVE(p, POS(r + dir, c));

        if (((color == WHITE) && (r == 6)) || ((color == BLACK) && (r == 1)))
        {
            /* starting two-square movement */
            if (GETPIECE(b, POS(r + 2 * dir, c)) == 0)
                moves[n++] = MOVE(p, POS(r + 2 * dir, c));
        }
    }

    /* capture moves */
    if (c > 0)
    {
        piece pd = GETPIECE(b, POS(r + dir, c - 1));
        if (pd && (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + dir, c - 1));
    }

    if (c < 7)
    {
        piece pd = GETPIECE(b, POS(r + dir, c + 1));
        if (pd && (PCOLOR(pd) != color))
            moves[n++] = MOVE(p, POS(r + dir, c + 1));
    }

    /* en passant captures */
    if (((color == WHITE) && (r == 3)) || ((color == BLACK) && (r == 4)))
    {
        if (ENPASSCOL(b) == c + 1)
        {
            piece pd = GETPIECE(b, POS(r, c + 1));
            if (pd && (PCOLOR(pd) != color))
                moves[n++] = MOVE(p, POS(r + dir, c + 1));
        }
        else if (ENPASSCOL(b) == c - 1)
        {
            piece pd = GETPIECE(b, POS(r, c - 1));
            if (pd && (PCOLOR(pd) != color))
                moves[n++] = MOVE(p, POS(r + dir, c - 1));
        }
    }

    return n;
}

static void do_move(board b, boardmove move)
{
    if ((POSCOL(MOVEFROM(move)) == 4) && (POSCOL(MOVETO(move)) == 6) &&
        (PTYPE(GETPIECE(b, MOVEFROM(move))) == P_K))
    {
        /* king castle: move the rook first and don't allow a second castle */
        NOCASTLE(b, PCOLOR(PMOVING(b, move)));
        SETPIECE(b, PIECE(P_R, PCOLOR(PMOVING(b, move))),
                 POS(POSROW(MOVETO(move)), 5));
        SETPIECE(b, 0, POS(POSROW(MOVETO(move)), 7));
    }
    else if ((POSCOL(MOVEFROM(move)) == 4) && (POSCOL(MOVETO(move)) == 2) &&
        (PTYPE(GETPIECE(b, MOVEFROM(move))) == P_K))
    {
        /* queen castle: move the rook first and don't allow a second castle */
        NOCASTLE(b, PCOLOR(PMOVING(b, move)));
        SETPIECE(b, PIECE(P_R, PCOLOR(PMOVING(b, move))),
                 POS(POSROW(MOVETO(move)), 3));
        SETPIECE(b, 0, POS(POSROW(MOVETO(move)), 0));
    }
    else if (PTYPE(PMOVING(b, move)) == P_K)
    {
        NOCASTLE(b, PCOLOR(PMOVING(b, move)));
    }
    else
    {
        int color, oppcolor;

        /* check whether either side can still castle on either side */
        color = PCOLOR(PMOVING(b, move));
        oppcolor = OPPCOLOR(color);

        if (MOVEFROM(move) == POS((color) ? 0 : 7, 0)) NOQCASTLE(b, color);
        if (MOVEFROM(move) == POS((color) ? 0 : 7, 7)) NOKCASTLE(b, color);
        if (MOVETO(move) == POS((oppcolor) ? 0 : 7, 0)) NOQCASTLE(b, oppcolor);
        if (MOVETO(move) == POS((oppcolor) ? 0 : 7, 7)) NOKCASTLE(b, oppcolor);
    }

    if (PTYPE(PMOVING(b, move)) == P_P)
    {
        int d;

        if ((GETPIECE(b, MOVETO(move)) == 0) &&
            (POSCOL(MOVETO(move)) != POSCOL(MOVEFROM(move))))
        {
            /* this is an en passant take -- remove the piece taken */
            SETPIECE(b, 0, POS(POSROW(MOVEFROM(move)), POSCOL(MOVETO(move))));
        }

        d = POSROW(MOVETO(move)) - POSROW(MOVEFROM(move));
        if ((d == 2) || (d == -2))
        {
            /* this is a two-square pawn move -- allow en passant takes */
            SETENPASS(b, POSCOL(MOVETO(move)));
        }
        else
        {
            if ((POSROW(MOVETO(move)) == 0) || (POSROW(MOVETO(move)) == 7))
            {
                /* promote the pawn -- code below moves it into place */
                SETPIECE(b, PIECE(P_Q, PCOLOR(PMOVING(b, move))),
                         MOVEFROM(move));
            }

            /* this is a normal pawn move -- disallow en passant takes */
            SETENPASS(b, 0x0F);
        }
    }
    else SETENPASS(b, 0x0F);

    SETPIECE(b, PMOVING(b, move), MOVETO(move));
    SETPIECE(b, 0, MOVEFROM(move));
}

static int get_all_moves(board b, int color, boardmove moves[])
{
    int i, j, n, krow, kcol;

    n = 0;
    krow = 0;
    kcol = 0;

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {
            boardpos pos = POS(i, j);
            piece p = GETPIECE(b, pos);

            if ((PTYPE(p) == 0) || (PCOLOR(p) != color)) continue;
            switch (PTYPE(p))
            {
                case P_K:
                    krow = i;
                    kcol = j;
                    n += get_valid_moves_king(b, pos, moves + n);
                    break;

                case P_Q:
                    n += get_valid_moves_queen(b, pos, moves + n);
                    break;

                case P_R:
                    n += get_valid_moves_rook(b, pos, moves + n);
                    break;

                case P_B:
                    n += get_valid_moves_bishop(b, pos, moves + n);
                    break;

                case P_N:
                    n += get_valid_moves_knight(b, pos, moves + n);
                    break;

                case P_P:
                    n += get_valid_moves_pawn(b, pos, moves + n);
                    break;
            }
        }

    i = 0;

    while (i < n)
    {
        board bnew;
        boardcov bnewcov;
        int knewrow, knewcol;

		int ii;
		for (ii = 0; ii < sizeof(board); ii++)
		{
			*((char *)bnew + ii) = *((char *)b + ii);
		}

        do_move(bnew, moves[i]);
        bnewcov = get_board_coverage(bnew, OPPCOLOR(color));

        if (MOVEFROM(moves[i]) == POS(krow, kcol))
        {
            knewrow = POSROW(MOVETO(moves[i]));
            knewcol = POSCOL(MOVETO(moves[i]));
        }
        else
        {
            knewrow = krow;
            knewcol = kcol;
        }

        if (ISCOV(bnewcov, knewrow, knewcol)) moves[i] = moves[--n];
        else i++;
    }

    return n;
}

static int eval_board(board b, int color)
{
    boardcov cov, oppcov;
    int i, j;
    int tval, tcov;

    tval = 0;
    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {
            piece p;
            p = GETPIECE(b, POS(i, j));
            if (PCOLOR(p) == color) tval += PVALOF(p);
            else tval -= PVALOF(p);
        }

    tcov = 0;
    cov = get_board_coverage(b, color);
    oppcov = get_board_coverage(b, OPPCOLOR(color));

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
        {
            int d = 0;
            if (ISCOV(cov, i, j)) d++;
            if (ISCOV(oppcov, i, j)) d--;

            if (((i == 3) || (i == 4)) && ((j == 3) || (j == 4))) d *= 2;
            if (((i == 2) || (i == 5)) && ((j == 2) || (j == 5))) d *= 2;

            tcov += d;
        }

    return (30 * tval) + tcov;
}

/*
 * Sorts moves from best to worst from the perspective of the moving color.
 * This helps the alpha-beta pruning to become more effective.
 * 
 * For now, this will be a bubble-sort; it would probably be worthwhile to
 * use a faster sort algorithm here.
 */
static void sort_moves(board b, int color_move,
	boardmove moves[], int nmoves)
{
    board bnew;
	int move_scores[256];
	int i, ii;

	for (i = 0; i < nmoves; i++)
	{
		int ii;
		for (ii = 0; ii < sizeof(board); ii++)
		{
			*((char *)bnew + ii) = *((char *)b + ii);
		}

        do_move(bnew, moves[i]);
        move_scores[i] = eval_board(bnew, color_move);
    }

	for (i = 0; i < nmoves - 1; i++)
	{
		for (ii = 0; ii < nmoves - 1 - i; ii++)
		{
			if (move_scores[ii + 1] > move_scores[ii])
			{
				int tscore;
				boardmove tmove;

				tscore = move_scores[ii + 1];
				move_scores[ii + 1] = move_scores[ii];
				move_scores[ii] = tscore;

				tmove = moves[ii + 1];
				moves[ii + 1] = moves[ii];
				moves[ii] = tmove;
			}
		}
	}
}

static int eval_board_recursive(board b, int color_eval,
    int color_move, int nrecurses, int alpha, int beta)
{
    if (nrecurses == 0)
    {
    	return eval_board(b, color_eval);
    }
    else if (keyb_isON() || keyb_isAlpha())
    {
    	/*
    	 * Immediately fail anything not yet evaluated, and go with the
    	 * earlier options that looked better.
    	 */
    	if (color_eval == color_move) return -999999;
    	else return 999999;
    }
    else
    {
        boardmove moves[256];
        board bnew;
        int n, i;

        n = get_all_moves(b, color_move, moves);
        if (nrecurses > 1) sort_moves(b, color_move, moves, n);
        if (n == 0)
        {
            /* Decide if this is a checkmate or a draw */
            int j, krow, kcol, found;
            boardcov cov;

            cov = get_board_coverage(b, OPPCOLOR(color_move));

            found = 0;
            krow = 0;
            kcol = 0;

            for (i = 0; !found && (i < 8); i++)
                for (j = 0; !found && (j < 8); j++)
                    if (GETPIECE(b, POS(i, j)) == PIECE(P_K, color_move))
                    {
                        krow = i;
                        kcol = j;
                        found = 1;
                    }

            if (ISCOV(cov, krow, kcol))
            {
                /* checkmate!!!! */
                if (color_move == color_eval) return -999999;
                else return 999999;
            }
            else
            {
                /* draw */
                return 0;
            }
        }

		int nalpha = -999999;
		int nbeta = 999999;

		for (i = 0; i < n; i++)
		{
			int val, ii;
			for (ii = 0; ii < sizeof(board); ii++)
			{
				*((char *)bnew + ii) = *((char *)b + ii);
			}

            do_move(bnew, moves[i]);

			if (color_move == color_eval)
			{
	            val = eval_board_recursive(bnew, color_eval,
    	            OPPCOLOR(color_move), nrecurses - 1,
        	        MAX(alpha, nalpha), beta);
        	    nalpha = MAX(nalpha, val);
        	    if (nalpha >= beta) return nalpha;
			}
			else
			{
	            val = eval_board_recursive(bnew, color_eval,
    	            OPPCOLOR(color_move), nrecurses - 1,
        	        alpha, MIN(beta, nbeta));
        	    nbeta = MIN(nbeta, val);
        	    if (alpha >= nbeta) return nbeta;
			}
		}

        if (color_move == color_eval) return nalpha;
        else return nbeta;
    }
}

/*
 * Clears a section 4 pixels wide by 5 pixels tall
 */
void clearLetMF(int x, int y)
{
	int length = 5;
    volatile char* LCDPos = getLCDPointer(x,y);
    char left, right; // the split bytes

    int ali = x & 0x7; // x mod 8

    while (length>0)
    {
        left = (0xff<<ali)&0xff;
        right =(0xff>>(8-ali))&0xff;

        *LCDPos = (*LCDPos) & ~left;
        *(LCDPos + 1) = *(LCDPos + 1) & ~right;

        LCDPos=LCDPos + 0x14; //Y=Y+1
        length--;
    }
}

static boardmove get_move_human(board b, int color)
{
    boardmove mv = 0;
    boardmove possibles[256];
    int npossible, move_valid = 0;

    npossible = get_all_moves(b, color, possibles);
    if (npossible == 0)
    {
        /* Decide if this is a checkmate or a draw */
        int i, j, krow, kcol, found;
        boardcov cov;

        cov = get_board_coverage(b, OPPCOLOR(color));

        found = 0;
        krow = 0;
        kcol = 0;

        for (i = 0; !found && (i < 8); i++)
        {
            for (j = 0; !found && (j < 8); j++)
            {
                if (GETPIECE(b, POS(i, j)) == PIECE(P_K, color))
                {
                    krow = i;
                    kcol = j;
                    found = 1;
                }
            }
        }

        if (ISCOV(cov, krow, kcol))
        {
			hpg_draw_text("Checkmate!", 84, 32);
        }
        else
        {
			hpg_draw_text("Draw!", 84, 32);
        }

		return 0;
    }

	sys_slowOn();
    do {
    	if (color == WHITE) hpg_draw_text("White", 84, 8);
    	else hpg_draw_text("Black", 84, 8);
		hpg_draw_text("Move:", 84, 16);

		int srcRank = -1;
		int srcFile = -1;
		int dstRank = -1;
		int dstFile = -1;

		int pos = 0;

		while ((pos < 4))
		{
			if (keyb_isON())
			{
				sys_slowOff();
				return 0;
			}

			if (keyb_isKeyPressed(5, 0))
			{
				/* File A */
				pos++;
				if (pos == 1) srcFile = 0;
				else if (pos == 3) dstFile = 0;
				else pos--;
			}
			else if (keyb_isKeyPressed(5, 1))
			{
				/* File B */
				pos++;
				if (pos == 1) srcFile = 1;
				else if (pos == 3) dstFile = 1;
				else pos--;
			}
			else if (keyb_isKeyPressed(5, 2))
			{
				/* File C */
				pos++;
				if (pos == 1) srcFile = 2;
				else if (pos == 3) dstFile = 2;
				else pos--;
			}
			else if (keyb_isKeyPressed(5, 3))
			{
				/* File D */
				pos++;
				if (pos == 1) srcFile = 3;
				else if (pos == 3) dstFile = 3;
				else pos--;
			}
			else if (keyb_isKeyPressed(5, 4))
			{
				/* File E */
				pos++;
				if (pos == 1) srcFile = 4;
				else if (pos == 3) dstFile = 4;
				else pos--;
			}
			else if (keyb_isKeyPressed(5, 5))
			{
				/* File F */
				pos++;
				if (pos == 1) srcFile = 5;
				else if (pos == 3) dstFile = 5;
				else pos--;
			}
			else if (keyb_isKeyPressed(5, 6))
			{
				/* File G */
				pos++;
				if (pos == 1) srcFile = 6;
				else if (pos == 3) dstFile = 6;
				else pos--;
			}
			else if (keyb_isKeyPressed(6, 4))
			{
				/* File H */
				pos++;
				if (pos == 1) srcFile = 7;
				else if (pos == 3) dstFile = 7;
				else pos--;
			}
			else if (keyb_isKeyPressed(3, 5))
			{
				/* Rank 1 */
				pos++;
				if (pos == 2) srcRank = 7;
				else if (pos == 4) dstRank = 7;
				else pos--;
			}
			else if (keyb_isKeyPressed(2, 5))
			{
				/* Rank 2 */
				pos++;
				if (pos == 2) srcRank = 6;
				else if (pos == 4) dstRank = 6;
				else pos--;
			}
			else if (keyb_isKeyPressed(1, 5))
			{
				/* Rank 3 */
				pos++;
				if (pos == 2) srcRank = 5;
				else if (pos == 4) dstRank = 5;
				else pos--;
			}
			else if (keyb_isKeyPressed(3, 4))
			{
				/* Rank 4 */
				pos++;
				if (pos == 2) srcRank = 4;
				else if (pos == 4) dstRank = 4;
				else pos--;
			}
			else if (keyb_isKeyPressed(2, 4))
			{
				/* Rank 5 */
				pos++;
				if (pos == 2) srcRank = 3;
				else if (pos == 4) dstRank = 3;
				else pos--;
			}
			else if (keyb_isKeyPressed(1, 4))
			{
				/* Rank 6 */
				pos++;
				if (pos == 2) srcRank = 2;
				else if (pos == 4) dstRank = 2;
				else pos--;
			}
			else if (keyb_isKeyPressed(3, 3))
			{
				/* Rank 7 */
				pos++;
				if (pos == 2) srcRank = 1;
				else if (pos == 4) dstRank = 1;
				else pos--;
			}
			else if (keyb_isKeyPressed(2, 3))
			{
				/* Rank 8 */
				pos++;
				if (pos == 2) srcRank = 0;
				else if (pos == 4) dstRank = 0;
				else pos--;
			}
			else if (keyb_isKeyPressed(0, 0))
			{
				/* Backspace key */
				if (pos > 0) pos--;
			}
			else
			{
				/* No key pressed; skip redrawing */
				continue;
			}

			if (pos < 1) clearLetMF(110, 16);
			if (pos < 2) clearLetMF(114, 16);
			if (pos < 2) clearLetMF(118, 16);
			if (pos < 3) clearLetMF(122, 16);
			if (pos < 4) clearLetMF(126, 16);

			if (pos > 0) writeLetMF2('A' + srcFile, 110, 16);
			if (pos > 1) writeLetMF2('1' + (7 - srcRank), 114, 16);
			if (pos > 1) writeLetMF2('-', 118, 16);
			if (pos > 2) writeLetMF2('A' + dstFile, 122, 16);
			if (pos > 3) writeLetMF2('1' + (7 - dstRank), 126, 16);
		}

        mv =  MOVE(POS(srcRank, srcFile),
	               POS(dstRank, dstFile));

        move_valid = 0;

        int i;
	    for (i = 0; i < npossible; i++)
    	{
        	if (mv == possibles[i]) move_valid = 1;
        }

		if (!move_valid)
		{
			hpg_draw_text("Invalid Move", 84, 32);
		}
    } while (!move_valid);

	sys_slowOff();

    return mv;
}

static boardmove get_move_computer(board b, int color)
{
    boardmove possibles[256];
    int highval, highmove;
    int npossible, i;

    npossible = get_all_moves(b, color, possibles);
    sort_moves(b, color, possibles, npossible);

    if (npossible == 0)
    {
        /* Decide if this is a checkmate or a draw */
        int i, j, krow, kcol, found;
        boardcov cov;

        cov = get_board_coverage(b, OPPCOLOR(color));

        found = 0;
        krow = 0;
        kcol = 0;

        for (i = 0; !found && (i < 8); i++)
            for (j = 0; !found && (j < 8); j++)
                if (GETPIECE(b, POS(i, j)) == PIECE(P_K, color))
                {
                    krow = i;
                    kcol = j;
                    found = 1;
                }

        if (ISCOV(cov, krow, kcol))
        {
			hpg_draw_text("Checkmate!", 84, 32);
        }
        else
        {
			hpg_draw_text("Draw!", 84, 32);
        }

        return 0;
    }

	if (color == WHITE) hpg_draw_text("White", 84, 8);
	else hpg_draw_text("Black", 84, 8);
	hpg_draw_text("Thinking...", 84, 16);

	highmove = 0;
	highval = -999999;

    for (i = 0; i < npossible; i++)
    {
        int v, ii;
	    board bnew;

		for (ii = 0; ii < sizeof(board); ii++)
		{
			*((char *)bnew + ii) = *((char *)b + ii);
		}

	    do_move(bnew, possibles[i]);

	    v = eval_board_recursive(bnew, color, OPPCOLOR(color),
	    	DEPTH, highval, 999999);

        if (v > highval)
        {
            highval = v;
            highmove = possibles[i];
        }

		if (highval == 999999) break;
    }

    return highmove;
}

static void draw_board(board b)
{
    int i, j;

    for (j = 0; j < 8; j++)
    {
    	int x = (j * 8) + 16;

        writeLetMF2('A' + j, x, 0);
    }

    for (i = 0; i < 8; i++)
    {
    	int y = (i * 8) + 16;
    	writeLetMF2(7 - i + '1', 0, y);

        for (j = 0; j < 8; j++)
        {
        	int x = (j * 8) + 16;
			char sprite[8];
			char *form;
			int k;

            piece p = GETPIECE(b, POS(i, j));
            form = PCHAROF(p);
			int sqcolor = ((i % 2) == (j % 2)) ? WHITE : BLACK;

			for (k = 0; k < 8; k++)
			{
				char c = form[k];
				if (sqcolor == BLACK) c ^= 0xFF;
				sprite[k] = c;
			}

            drawBlockOR(sprite, 8, x - 2, y - 2);
        }
    }
}

int main(void)
{
    boardmove (*whiteplay)(board, int);
    boardmove (*blackplay)(board, int);

	
	hpg_clear();
	
	whiteplay = get_move_human;
	blackplay = get_move_computer;

    while (!keyb_isON())
    {
        boardmove mv;

		hpg_clear();
		draw_board(master_board);
        mv = (*whiteplay)(master_board, WHITE);
        if (mv == 0)
        {
        	while (!keyb_isON());
        	break;
       	}
        do_move(master_board, mv);

		hpg_clear();
		draw_board(master_board);
        mv = (*blackplay)(master_board, BLACK);
        if (mv == 0)
        {
        	while (!keyb_isON());
        	break;
       	}
        do_move(master_board, mv);
    }

	

    return 0;
}
