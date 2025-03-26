#include "string.h"
#include "init.c"
#include "print.c"

void test(String fen)
{
	Context ctx;
	Init(&ctx, fen);
	Print(&ctx);
}

U64 PawnMoves(U8 index, Context* ctx)
{
	ctx->board[index - 8];
}

int main()
{
	String fen = STRING_CONST("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
	test(fen);
	test(STRING("rnbqkbnr/pppppppp/8/8/2P5/8/PP1PPPPP/RNBQKBNR b KQkq c3 1 1"));
	return 0;
}
