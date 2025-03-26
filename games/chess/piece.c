#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef uint8_t U8;
typedef uint16_t U16;

typedef enum : U16 {
	PIECE_0 = 1UL << -1, // none
	PIECE_W = 1UL << 0, // white
	PIECE_P = 1UL << 1, // pawn
	PIECE_R = 1UL << 2, // rook
	PIECE_N = 1UL << 3, // knight
	PIECE_B = 1UL << 4, // bishop
	PIECE_Q = 1UL << 5, // queen
	PIECE_K = 1UL << 6, // king
	PIECE_S = 1UL << 7, // shadow
	PIECE_U = 1UL << 8, // unmoved
	PIECE_A = 1UL << 9, // attack
	PIECE_PR = 1UL << 10, // promote rook
	PIECE_PN = 1UL << 11, // promote knight
	PIECE_PB = 1UL << 12, // promote bishop
	PIECE_PQ = 1UL << 13, // promote queen
	PIECE_BO = 1UL << 14, // boundary
} Piece;

typedef U16 Board[100];

typedef struct {
	int8_t Y, X;
} YX;

typedef struct {
	Piece checks[3];
	Piece moves[3];
	Piece name;
	YX check_indexes[3];
	YX move_indexes[3];
	YX index;
} Move;

int main()
{
	/*char move[] = "w p -1 0 ; 0 -1 0 ; 0 1 0 , w p -1 0";*/

	Move move = (Move){
		.name = PIECE_W | PIECE_P,
		.index = {-1, 0},
		.checks = { PIECE_0 },
		.check_indexes = { {-1, 0} },
		.moves = { PIECE_W | PIECE_P },
		.move_indexes = { {-1, 0} },
	};
	return 0;
}
