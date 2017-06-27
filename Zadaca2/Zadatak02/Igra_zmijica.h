#ifndef IGRA_ZMIJICA_H
#define IGRA_ZMIJICA_H

#include <iostream>
#include "Tocka.h"
using namespace std;

class Igra_zmijica
{
public:
	Igra_zmijica();
	Tocka get_random_D();
	void iscrtaj();
	void NoviGrid(char odabir);
	char get_user_input();
	Tocka novi_x(char odabir);
	Tocka novi_d();
	char odabir;
	bool dead();
private:
	static const int max_x = 32;
	static const int max_y = 27;
	char grid[max_y][max_x];
	char novi_grid[max_y][max_x];
	Tocka X, D;
	
	
};

#endif // !IGRA_ZMIJICA_H
