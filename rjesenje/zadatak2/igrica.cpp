#include"igrica.h"
#include<Windows.h>
#include<conio.h>
#include<ctime>

igrica::igrica()
{
	srand(time(nullptr));

	igracX = broj_redaka / 2;
	igracY = broj_stupaca / 2;
	stvoriVocku();
}

void igrica::sljedeci_korak()
{
	get_user_input();
	kretanje();
	sudaranje();
	iscrtaj();
	Sleep(100);
}

bool igrica::gotovo()
{
	return igraZavrsena;
}

void igrica::iscrtaj()
{
	system("cls");
	for (int i = 0; i < broj_redaka; i++) {
		for (int j = 0; j < broj_stupaca; j++) {
			if (i == 0 || i == broj_redaka - 1 || j == 0 || j == broj_stupaca - 1) {
				cout << '#';
			}
			else if (i == igracX && j == igracY) {
				cout << 'X';
			}
			else if (i == vockaX && j == vockaY) {
				cout << 'D';
			}
			else {
				cout << ' ';
			}
		}
		cout << endl;
	}
}

void igrica::kretanje()
{
	switch (smjer_kretanja) {
		case lijevo:
			igracY--;
			break;
		case desno:
			igracY++;
			break;
		case gore:
			igracX--;
			break;
		case dolje:
			igracX++;
			break;
	}
}

void igrica::sudaranje()
{
	if (igracX == 0 || igracX == broj_redaka - 1 || igracY == 0 || igracY == broj_stupaca - 1) {
		igraZavrsena = true;
		return;
	}
	if (igracX == vockaX && igracY == vockaY) {
		stvoriVocku();
	}
}

void igrica::stvoriVocku()
{
	do {
		vockaX = random_number_generator(1, broj_redaka - 2);
		vockaY = random_number_generator(1, broj_stupaca - 2);
	} while (vockaX != igracX && vockaY != igracY);
}

void igrica::get_user_input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
		case 'A':
			smjer_kretanja = lijevo;
			break;
		case 's':
		case 'S':
			smjer_kretanja = dolje;
			break;
		case 'd':
		case 'D':
			smjer_kretanja = desno;
			break;
		case 'w':
		case 'W':
			smjer_kretanja = gore;
			break;
		case 'k':
		case 'K':
			igraZavrsena = true;
			break;
		}
	}
}

int igrica::random_number_generator(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}
