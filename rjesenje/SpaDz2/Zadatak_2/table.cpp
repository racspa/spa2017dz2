#include "Table.h"

table::table(int rows, int columns)
{
	this->rows = rows;
	this->columns = columns;

	this->lastValue = new VALTYPE;

	data = new VALTYPE*[rows];

	for (int row = 0; row < rows; row++)
	{
		data[row] = new VALTYPE[columns];
	}
}

bool table::isPointValid(int row, int column)
{
	if (row < 0 || column < 0 || row >= rows || column >= columns)
	{
		return false;
	}

	return true;
}

bool table::insert(VALTYPE value, int row, int column)
{
	if (isPointValid(row, column) == true)
	{
		data[row][column] = value;
		lastValue = &data[row][column];
		return true;
	}

	return false;
}

bool table::insert(VALTYPE value)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			data[row][column] = value;
		}
	}

	return true;
}

VALTYPE& table::getValue(int row, int column)
{
	VALTYPE* value = new VALTYPE;

	if (isPointValid(row, column) == true)
	{
		*value = data[row][column];
	}

	return *value;
}

int table::rowCount()
{
	return rows;
}

int table::columnCount()
{
	return columns;
}

void table::replaceLastValue(VALTYPE value)
{
	*lastValue = value;
}

void table::clearLast()
{
	lastValue = new VALTYPE;
}

table::~table()
{
	for (int row = 0; row < rows; row++)
	{
		delete[] data[row];
	}

	delete[] data;
}