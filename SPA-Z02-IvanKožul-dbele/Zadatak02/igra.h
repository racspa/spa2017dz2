#ifndef _IGRA_H_
#define _IGRA_H_
#include "tocka.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;
class igra
{

private:
	static const int REDAKA=27;
	static const int STUPACA=32;
	char grid[REDAKA][STUPACA];
	tocka X;
	tocka D;
	tocka slucajna_vrijednost();
public:
	igra();
	void ispis();
	void kretnja(char odabir);
	char odabir;
	void povratak_iz_mrtvih();
	bool provjera_granica();
	char get_user_input();
};





#endif // !_IGRA_H_

