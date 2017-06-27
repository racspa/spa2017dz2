#ifndef IGRA_TOCKE_H
#define IGRA_TOCKE_H

#include <iostream>
#include "Tocka.h"
using namespace std;

class IgraTocke
{
public:
	IgraTocke(Tocka A, Tocka B);
	void Iscrtaj();
	void SljedeciGrid();
	Tocka NoviX();
	bool Alive();


private:
	static const int granica_x = 20;
	static const int granica_y = 40;
	Tocka A, B, x;
	char grid[granica_x][granica_y];
	char sljedeciGrid[granica_x][granica_y];
};

#endif // !IGRA_TOCKE_H
