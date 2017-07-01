#include <iostream>
#include "igra.h"
using namespace std;
int main() {
	igra i;
	do
	{
		system("cls");
		i.ispis();
		ib.kretnja_x();
		Sleep(100);
	} while (i.kretnja_x());

	do
	{
		system("cls");
		i.ispis();
		i.kretnja_y();
		Sleep(100);
	} while (i.kretnja_y());
	

	return 0;
}