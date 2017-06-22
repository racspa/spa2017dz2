#include <iostream>
#include <string>
#include <Windows.h>
#include "Table.h"
#include "Helper.h"

using namespace std;

void main()
{
	table tab(20, 40);

	tab.insert('-');

	int rowA = getInteger("A redak: ", 1, tab.rowCount()) - 1;
	int columnA = getInteger("A stupac: ", 1, tab.columnCount()) - 1;

	tab.insert('A', rowA, columnA);

	int rowB = getInteger("B redak: ", 1, tab.rowCount()) - 1;
	int columnB = getInteger("B stupac: ", 1, tab.columnCount()) - 1;

	tab.insert('B', rowB, columnB);

	tab.clearLast();

	traverse(tab, '#', rowA, columnA, rowB, columnB);
}