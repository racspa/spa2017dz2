#ifndef _HELPER_H_
#define _HELPER_H_

#include "Table.h"
#include <string>
#include <conio.h>
#include <Windows.h>

enum direction
{
	none,
	left,
	up,
	right,
	down
};

bool isInRange(int value, int min, int max);
void printTable(table& tab);
void insertInRow(table& tab, int row, VALTYPE value);
void insertInColumn(table& tab, int column, VALTYPE value);
int randomInRangeWithout(int min, int max, int forbidden);
char getPressedKey();
void changePlayerDirection(direction& playerDirection);
void game(table& tab, int playerRow, int playerColumn, int firstRow, int lastRow, int firstColumn, int lastColumn);

#endif