#ifndef _TABLE_H_
#define _TABLE_H_

typedef char VALTYPE;

class table
{
private:
	int rows;
	int columns;
	VALTYPE** data;
	VALTYPE* lastValue;
	bool isPointValid(int row, int column);
public:
	table(int rows, int columns);
	bool insert(VALTYPE value, int row, int column);
	bool insert(VALTYPE value);
	VALTYPE& getValue(int row, int column);
	int rowCount();
	int columnCount();
	void replaceLastValue(VALTYPE value);
	void clearLast();
	~table();
};

#endif