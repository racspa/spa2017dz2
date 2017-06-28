#include <iostream>
#include <Windows.h>
#include "tablica.h"
using namespace std;

int main() {

	Tablica tab;
	tab.Upisi();
	
	while (!tab.Dovrseno()) {
		tab.Iscrtaj();
		Sleep(tab.Dobij_Pauzu());
		tab.Korak();
	}
	
	//system("exit");

	return 0;
}