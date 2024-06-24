
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


char* INPUT[10];

void solve(char* puzzle) {
	printf("Solving %s\n", puzzle);
	run(puzzle);
}

void run(char* puzzle) {
	int zeroCount = countZeroesOf(puzzle);
	int zeroIndexes[zeroCount];
	getZeroIndexesOf(puzzle, zeroIndexes);
	int intPuzzle[strlen(puzzle)];
	charToIntArray(puzzle, intPuzzle);
	loop(intPuzzle, puzzle, zeroIndexes, zeroCount, 0);
	for (int i=0; i<strlen(puzzle); i++) {
		printf("%i", intPuzzle[i]);
	}
	printf("\n");
}

int loop(int* intPuzzle, const char* puzzle, const int* zeroIndexes, const int zeroCount, const int j) {
	int zeroIndex = zeroIndexes[j];
	if (j == zeroCount) {
		return 1;
	}
	for (int i=0; i<9; i++) {
		intPuzzle[zeroIndex] = i + 1;
		if (isWrong(intPuzzle, zeroIndex))
			continue;
		int mustEnd = loop(intPuzzle, puzzle, zeroIndexes, zeroCount, j + 1);
		if (mustEnd)
			return 1;
	}
	intPuzzle[zeroIndex] = 0;
	return 0;
}

int isWrong(int* intPuzzle, int zeroIndex) {
	fgets(INPUT, sizeof(INPUT), stdin);
	if (isBoxOkay(intPuzzle, zeroIndex))
		return 0;
	if (isRowOkay(intPuzzle, zeroIndex))
		return 0;
	if (isColOkay(intPuzzle, zeroIndex))
		return 0;
	return 1;
}

int isColOkay(int* intPuzzle, int zeroIndex) {
	int col = zeroIndex%9;
	int sum = 0;
	for (int i=0; i<9; i++) {
		int index = i*9 + col;
		sum += intPuzzle[index];
		printf("col: %i\n", index);
	}
	if (sum > 45)
		return 0;
	return 1;
}

int isBoxOkay(int* intPuzzle, int zeroIndex) {
	int row = floor(zeroIndex/9.0f);
	int boxRow = floor(row/3.0f);
	int boxCol = floor(zeroIndex%9/3.0f);
	int sum = 0;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++) {
			int index = boxRow*27 + i*9 + boxCol*3 + j;
			sum += intPuzzle[index];
			printf("box: %i %i %i %i %i\n", index, boxRow, i, boxCol, j);
	}
	if (sum > 45)
		return 0;
	return 1;
}

int isRowOkay(int* intPuzzle, int zeroIndex) {
	int row = floor(zeroIndex/9);
	int sum = 0;
	for (int i=0; i<9; i++) {
		int index = row*9 + i;
		sum += intPuzzle[index];
		printf("row: %i\n", index);
	}
	if (sum > 45)
		return 0;
	return 1;

}
int getZeroIndexesOf(char* puzzle, int* zeroIndexes) {
	int zeroCount = 0;
	for (int i=0; i<strlen(puzzle); i++) {
		if (puzzle[i] == '0') {
			zeroIndexes[zeroCount] = i;
			zeroCount++;
		}
	}
}

int countZeroesOf(char* puzzle) {
	int zeroCount = 0;
	for (int i=0; i<strlen(puzzle); i++) {
		if (puzzle[i] == '0')
			zeroCount++;	
	}
	return zeroCount;
}

void charToIntArray(char* puzzle, int* intPuzzle) {
	for (int i=0; i<strlen(puzzle); i++) {
		intPuzzle[i] = puzzle[i] - 48;
	}
}

