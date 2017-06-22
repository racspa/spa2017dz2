#include "Table.h"
#include "Helper.h"
#include <ctime>
#include <iostream>

using namespace std;

void main()
{
	srand(time(nullptr));

	table tab(35, 25);

	const int FIRST_ROW = 0;
	const int LAST_ROW = tab.rowCount() - 1;
	const int FIRST_COLUMN = 0;
	const int LAST_COLUMN = tab.columnCount() - 1;

	tab.insert(' ');

	insertInRow(tab, FIRST_ROW, '#');
	insertInRow(tab, LAST_ROW, '#');
	insertInColumn(tab, FIRST_COLUMN, '#');
	insertInColumn(tab, LAST_COLUMN, '#');

	game(tab, tab.rowCount() / 2, tab.columnCount() / 2, FIRST_ROW + 1, LAST_ROW - 1, FIRST_COLUMN + 1, LAST_COLUMN - 1);

	std::cout << "Game over!" << std::endl;
}