#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef uint8_t U8;
typedef uint16_t U16;
typedef uint32_t U32;
typedef uint64_t U64;
typedef enum : U8 {
	TYPE_PAWN,
	TYPE_KNIGHT,
	TYPE_BISHOP,
	TYPE_ROOK,
	TYPE_QUEEN,
	TYPE_KING,
} Type;
typedef enum : U8 {
	COLOR_WHITE,
	COLOR_BLACK,
} Color;
typedef enum : U8 {
	STATE_WIN,
	STATE_MOVE,
	STATE_DRAW,
} State;
typedef struct {
	U8 index;
	Type type;
	Color color;
	bool exists;
} Square;
typedef Square Board[64];
typedef struct {
	Square src, dst;
} Move;
typedef enum : U8 {
	CASTLE_BQ,
	CASTLE_BK,
	CASTLE_WQ,
	CASTLE_WK,
} Castle;
typedef struct {
	Move king, rook;
	bool exists;
} CastleMove;
typedef struct {
	Board board;
	CastleMove castlemoves[4];
	Square enpassant;
	Color active;
	State state;
	U16 nhalfmoves;
	U16 nfullmoves;
} Context;
