#include <iostream>
#include "windows.h"
#include "conio.h"
#include <ctime>
#include "pozicija.h"

using namespace std;

const int BROJ_REDAKA = 30;
const int BROJ_STUPACA = 25;

void iscrtaj_polje(char polje[][BROJ_STUPACA]) {
	for (int i = 0; i < BROJ_REDAKA; i++) {
		for (int j = 0; j < BROJ_STUPACA; j++) {
			cout << polje[i][j];
		}
		cout << endl;
	}
}

void odredi_poziciju_vocke(Pozicija& igrac, Pozicija& vocka) {
	while (true)
	{
		vocka.x = rand() % 28 + 1;
		vocka.y = rand() % 23 + 1;

		if (vocka.x != igrac.x && vocka.y != igrac.y) {
			break;
		}
	}
}

void kreiraj_polje(char polje[][BROJ_STUPACA], Pozicija& igrac, Pozicija& vocka)
{
	for (int i = 0; i < BROJ_REDAKA; i++) 
	{
		for (int j = 0; j < BROJ_STUPACA; j++)
		{
			if (i == 0 || i == BROJ_REDAKA - 1 || j == 0 || j == BROJ_STUPACA - 1)
			{
				polje[i][j] = '#';
			}
			else if (i == igrac.x && j == igrac.y)
			{
				polje[i][j] = 'X';
			}
			else if (i == vocka.x && j == vocka.y)
			{
				polje[i][j] = 'D';
			}
			else { polje[i][j] = ' '; }
		}
	}
}

void azuriraj_polje(char polje[][BROJ_STUPACA], Pozicija& igrac, Pozicija& vocka) {
	for (int i = 1; i < BROJ_REDAKA - 1; i++) 
	{
		for (int j = 1; j < BROJ_STUPACA - 1; j++) 
		{
			if (i == igrac.x && j == igrac.y) 
			{
				polje[i][j] = 'X';
			}
			else if (i == vocka.x && j == vocka.y) 
			{
				polje[i][j] = 'D';
			}
			else 
			{ 
				polje[i][j] = ' '; 
			}
		}
	}
}

char get_user_input() 
{
	if (_kbhit()) {
		return _getch();
	}

	return '0';
}

void sljedeca_pozicija_igraca(Pozicija &igrac, char &key) {
	switch (key) {
	case 'w':
		igrac.x--;
		break;
	case 's':
		igrac.x++;
		break;
	case 'a':
		igrac.y--;
		break;
	case 'd':
		igrac.y++;
		break;
	}
}

int main() {

	srand(time(nullptr));

	Pozicija pozicija_igraca;
	pozicija_igraca.x = BROJ_REDAKA / 2;
	pozicija_igraca.y = BROJ_STUPACA / 2;

	Pozicija pozicija_vocke;
	odredi_poziciju_vocke(pozicija_igraca, pozicija_vocke);

	char polje[BROJ_REDAKA][BROJ_STUPACA];
	kreiraj_polje(polje, pozicija_igraca, pozicija_vocke);
	iscrtaj_polje(polje);

	char key = '0';
	char key_temp;

	while (true)
	{
		if (_kbhit()) {

			system("cls");

			key_temp = get_user_input();
			key = key_temp;

			sljedeca_pozicija_igraca(pozicija_igraca, key);

			if (pozicija_igraca.x == pozicija_vocke.x && pozicija_igraca.y == pozicija_vocke.y) {
				odredi_poziciju_vocke(pozicija_igraca, pozicija_vocke);
			}

			azuriraj_polje(polje, pozicija_igraca, pozicija_vocke);

			iscrtaj_polje(polje);
		}

		if (pozicija_igraca.x == 0 || pozicija_igraca.x == BROJ_REDAKA - 1 || pozicija_igraca.y == 0 || pozicija_igraca.y == BROJ_STUPACA - 1 || key == 'k') {
			break;
		}
	}

	return 0;
}