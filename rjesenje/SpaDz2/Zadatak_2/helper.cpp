#include "Helper.h"
#include <iostream>
#include <Windows.h>

bool isInRange(int value, int min, int max)
{
	if (value < min || value > max)
	{
		return false;
	}

	return true;
}

void printTable(table& tab)
{
	system("cls");

	int rows = tab.rowCount();
	int columns = tab.columnCount();

	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			std::cout << tab.getValue(row, column) << " ";
		}

		std::cout << std::endl;
	}

	Sleep(100);
}

void insertInRow(table& tab, int row, VALTYPE value)
{
	for (int column = 0; column < tab.columnCount(); column++)
	{
		tab.insert(value, row, column);
	}
}

void insertInColumn(table& tab, int column, VALTYPE value)
{
	for (int row = 0; row < tab.rowCount(); row++)
	{
		tab.insert(value, row, column);
	}
}

int randomInRangeWithout(int min, int max, int forbidden)
{
	int result = min + rand() % (max - min + 1);

	if (result == forbidden)
	{
		result < max ? result-- : result++;
	}

	return result;
}

char getPressedKey()
{
	if (_kbhit()) 
	{
		return _getch();
	}

	return 0;
}

void changePlayerDirection(direction & playerDirection)
{
	char key = getPressedKey();

	switch (key)
	{
	case'k':
		playerDirection = none;
		break;
	case 'a':
		playerDirection = left;
		break;
	case 'w':
		playerDirection = up;
		break;
	case 'd':
		playerDirection = right;
		break;
	case 's':
		playerDirection = down;
		break;
	}
}

void game(table& tab, int playerRow, int playerColumn, int firstRow, int lastRow, int firstColumn, int lastColumn)
{
	tab.insert('D', randomInRangeWithout(firstRow, lastRow, playerRow), randomInRangeWithout(firstColumn, lastColumn, playerColumn));
	tab.insert('X', playerRow, playerColumn);

	direction playerDirection = right;
	char key = getPressedKey();

	while (true)
	{
		printTable(tab);
		tab.replaceLastValue(' ');
		changePlayerDirection(playerDirection);

		switch (playerDirection)
		{
		case none:
			return;
		case left:
			playerColumn--;
			break;
		case up:
			playerRow--;
			break;
		case right:
			playerColumn++;
			break;
		case down:
			playerRow++;
			break;
		}

		if (isInRange(playerRow, firstRow, lastRow) && isInRange(playerColumn, firstColumn, lastColumn)) 
		{
			if (tab.getValue(playerRow, playerColumn) == 'D')
			{
				tab.insert('D', randomInRangeWithout(firstRow, lastRow, playerRow), randomInRangeWithout(firstColumn, lastColumn, playerColumn));
			}

			tab.insert('X', playerRow, playerColumn);
		}
		else
		{
			return;
		}

		Sleep(100);
	}

	printTable(tab);
}