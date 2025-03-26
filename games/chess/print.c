#pragma once

#include <stdio.h>
#include "typedefs.h"

void Print(Context* ctx)
{
	static char white_tile[] = "\033[48;5;225m";
	static char black_tile[] = "\033[48;5;228m";
	static char black_piece[] = "\033[1;38;5;0m";
	static char white_piece[] = "\033[1;38;5;62m";
	static char border[] = "\033[1;38;5;35m";
	static char reset[] = "\033[0m";
	static char bar[] = "█";
	for (U8 i = 0; i < 64; i++)
	{
		Square square = ctx->board[i];
		if (i == 0)
		{
			fprintf(stdout, "\n%s", border);
			for (U8 j = 0; j < 2*8 + 4; j++)
			{
				fprintf(stdout, "%s", bar);
			}
			fprintf(stdout, "\n");
		}
		if (i % 8 == 0)
		{
			fprintf(stdout, "%s%s%s", border, bar, bar);
		}
		fprintf(stdout, "%s", (i + i / 8 % 2) % 2 ? black_tile : white_tile);
		fprintf(stdout, "%s", square.color == COLOR_WHITE ? white_piece : black_piece);
		char* type_ch = " ";
		if (square.exists)
		{
			switch (square.type)
			{
				case TYPE_PAWN: type_ch = "󰡙"; break;
				case TYPE_ROOK: type_ch = "󰡛"; break;
				case TYPE_KNIGHT: type_ch = "󰡘"; break;
				case TYPE_BISHOP: type_ch = "󰡜"; break;
				case TYPE_QUEEN: type_ch = "󰡚"; break;
				case TYPE_KING: type_ch = "󰡗"; break;
			}
		}
		fprintf(stdout, "%s", type_ch);
		char* info_ch = " ";
		for (U8 j = 0; j < sizeof(ctx->castlemoves)/sizeof(CastleMove); j++)
		{
			if (!ctx->castlemoves[j].exists) continue;
			if (i != ctx->castlemoves[j].rook.src.index) continue;
			info_ch = "⇌";
		}
		if (square.type == TYPE_KING && square.color == ctx->active)
		{
			info_ch = "⁺";
		}
		if (ctx->enpassant.exists && square.index == ctx->enpassant.index)
		{
			info_ch = "×";
		}
		fprintf(stdout, "%s", info_ch);
		if (i % 8 == 7)
		{
			fprintf(stdout, "%s%s%s%s\n", reset, border, bar, bar);
		}
		if (i == 63)
		{
			fprintf(stdout, "%s", border);
			for (U8 j = 0; j < 2*8 + 4; j++)
			{
				fprintf(stdout, "%s", bar);
			}
			fprintf(stdout, "\n");
		}
		fprintf(stdout, "%s", reset);
	}
}
