#include <iostream>
#include <Windows.h>
#include "Zmija.h"

using namespace std;

int main() {

	Zmija z;

	char smjer = 'd';
	char smjer_kretanja;
	
	while (true)
	{
		z.player_init();
		z.fruit_init();
		z.map_init();

		smjer_kretanja = z.get_user_input();
		z.valid_input(smjer_kretanja, smjer);

		z.move(smjer);
		Sleep(100);
	} 

	return 0;
}