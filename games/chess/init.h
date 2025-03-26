#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "string.h"
#include "typedefs.h"

int Init(Context* ctx, String fen)
{
	// ctx
	*ctx = (Context){};
	char ch;
	Type type;
	// Board
	U8 fen_index = 0;
	U8 square_index = 0;
	U8 ncols = 0;
	while (square_index < 64)
	{
		ch = fen.chars[fen_index++];
		if (ch == '\0') return 1;
		else if (ch == '/')
		{
			if (ncols != 8) return 1;
			ncols = 0;
		}
		else if (ch >= '1' && ch <= '8')
		{
			square_index += ch - '0';
			ncols += ch - '0';
		}
		else if (strchr("prnbqk", tolower(ch)))
		{
			switch (tolower(ch))
			{
				case 'p': type = TYPE_PAWN; break;
				case 'r': type = TYPE_ROOK; break;
				case 'n': type = TYPE_KNIGHT; break;
				case 'b': type = TYPE_BISHOP; break;
				case 'q': type = TYPE_QUEEN; break;
				case 'k': type = TYPE_KING; break;
			}
			ctx->board[square_index] = (Square){
				.type = type,
				.color = islower(ch) ? COLOR_BLACK : COLOR_WHITE,
				.index = square_index,
				.exists = true,
			};
			square_index++;
			ncols++;
		}
		else return 1;
	}
	if (fen.chars[fen_index++] != ' ') return 1;
	// Color
	ch = fen.chars[fen_index++];
	if (!strchr("wb", ch)) return 1;
	ctx->active = ch == 'w' ? COLOR_WHITE : COLOR_BLACK;
	if (fen.chars[fen_index++] != ' ') return 1;
	// Castles
	ch = fen.chars[fen_index++];
	if (ch == '-')
	{
		ch = fen.chars[fen_index++];
	}
	else
	{
		U8 ncastles = 0;
		char castles[4] = {};
		while (strchr("KQkq", ch))
		{
			if (strchr(castles, ch)) return 1;
			castles[ncastles++] = ch;
			ch = fen.chars[fen_index++];
		}
	}
	if (ch != ' ') return 1;
	// Enpassant
	ch = fen.chars[fen_index++];
	if (ch != '-')
	{
		U8 index = 0;
		if (ch < 'a' || ch > 'h') return 1;
		index += ch - 'a';
		ch = fen.chars[fen_index++];
		if (ch < '1' || ch > '8') return 1;
		index += (ch - '1') * 8;
		ctx->enpassant = (Square){
			.exists = true,
			.index = index,
			.color = ctx->active == COLOR_WHITE ? COLOR_BLACK : COLOR_WHITE,
			.type = TYPE_PAWN,
		};
	}
	// nhalfmoves
	ch = fen.chars[fen_index++];
	U16 sums[2] = {0};
	for (U8 i = 0; i < 2; i++)
	{
		if (ch != ' ') return	1;
		U8 ndigits = 0;
		while (true)
		{
			ch = fen.chars[fen_index++];
			if (!isdigit(ch))
			{
				if (ndigits == 0) return 1;
				break;
			}
			if (ndigits == 0 && ch == '0') return 1;
			sums[i] = sums[i] * 10 + ch - '0';
			ndigits++;
		}
	}
	ctx->nhalfmoves = sums[0];
	// nfullmoves
	if (sums[1] < 1) return 1;
	ctx->nfullmoves = sums[1];
	
	return 0;
}
