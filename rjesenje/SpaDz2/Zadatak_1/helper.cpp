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

int getInteger(std::string message)
{
	std::cout << message << std::endl;

	int value;
	std::cin >> value;

	return value;
}

int getInteger(std::string message, int min, int max)
{
	int value;

	while (true)
	{
		value = getInteger(message);

		if (isInRange(value, min, max))
		{
			break;
		}
	}

	return value;
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
			std::cout << tab.getValue(row, column);
		}

		std::cout << std::endl;
	}

	Sleep(100);
}

void step(int& start, int destination)
{
	if (start > destination)
	{
		start--;
	}
	else
	{
		start++;
	}
}

void traverse(table& tab, char mark, int currentRow, int currentColumn, int destinationRow, int destinationColumn)
{
	char value = '#';

	while (currentRow != destinationRow)
	{
		printTable(tab);

		tab.replaceLastValue('-');

		step(currentRow, destinationRow);

		tab.insert(value, currentRow, currentColumn);
	}

	while (currentColumn != destinationColumn)
	{
		printTable(tab);

		tab.replaceLastValue('-');

		step(currentColumn, destinationColumn);

		tab.insert(value, currentRow, currentColumn);
	}

	printTable(tab);
}