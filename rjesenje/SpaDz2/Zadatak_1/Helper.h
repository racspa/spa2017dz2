#ifndef _HELPER_H_
#define _HELPER_H_

#include "Table.h"
#include <string>

bool isInRange(int value, int min, int max);
int getInteger(std::string message);
int getInteger(std::string message, int min, int max);
void printTable(table& tab);
void step(int& start, int destination);
void traverse(table& tab, char mark, int startRow, int startColumn, int destinationRow, int destinationColumn);

#endif
