#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "tablica.h"

using namespace std;

int main() {

	Tablica tab;

	while (true) {
		tab.Iscrtaj();
		Sleep(tab.Dobij_Pauzu());
		tab.Korak();
	}

	return 0;
}