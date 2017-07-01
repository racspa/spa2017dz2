#ifndef _IGRA_H_
#define _IGRA_H_
#include "pozicija.h"
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
class igra
{
public:
	igra();
	void ispis();
	bool kretnja_x();
	bool kretnja_y();
private:
	static const int REDAKA=20;
	static const int STUPACA=40;
	char grid[REDAKA][STUPACA];
	pozicija To1;
	pozicija To2;
};





#endif // !_IGRA_H_
