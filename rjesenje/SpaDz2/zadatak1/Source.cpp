#include <iostream>
#include "windows.h"
#include "tocka.h"

using namespace std;

const int BROJ_REDAKA = 20;
const int BROJ_STUPACA = 40;

void postavi_polje(char polje[][BROJ_STUPACA], Tocka& a, Tocka& b) {
	for (int i = 0; i < BROJ_REDAKA; i++) {
		for (int j = 0; j < BROJ_STUPACA; j++) {
			if (i == a.redak - 1 && j == a.stupac - 1) {
				polje[i][j] = 'A';
			}
			else if (i == b.redak - 1 && j == b.stupac - 1) {
				polje[i][j] = 'B';
			}
			else { polje[i][j] = '-'; }
		}
	}
}

void azuriraj_polje(char polje[][40], Tocka &A, Tocka &B, Tocka &X) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (i == A.redak - 1 && j == A.stupac - 1) {
				polje[i][j] = 'A';
			}
			else if (i == B.redak - 1 && j == B.stupac - 1) {
				polje[i][j] = 'B';
			}
			else if (i == X.redak - 1 && j == X.stupac - 1) {
				polje[i][j] = 'x';
			}
			else { polje[i][j] = '-'; }
		}
	}
}

void iscrtaj_polje(char polje[][40]) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			cout << polje[i][j];
		}
		cout << endl;
	}
}

bool provjeri_granice(Tocka& tocka)
{
	return !(tocka.redak > 0 && tocka.redak <= BROJ_REDAKA && tocka.stupac > 0 && tocka.stupac <= BROJ_STUPACA);
}

int main() {

	Tocka tocka_A;
	Tocka tocka_B;

	do {
		cout << "Redak A: ";
		cin >> tocka_A.redak;
		cout << "Stupac A: ";
		cin >> tocka_A.stupac;
	} while (provjeri_granice(tocka_A));

	do {
		cout << "Redak B: ";
		cin >> tocka_B.redak;
		cout << "Stupac B: ";
		cin >> tocka_B.stupac;
	} while (provjeri_granice(tocka_B));

	char polje[BROJ_REDAKA][BROJ_STUPACA];
	postavi_polje(polje, tocka_A, tocka_B);

	system("cls");

	Tocka tocka_x;
	tocka_x.redak = tocka_A.redak;
	tocka_x.stupac = tocka_A.stupac;

	iscrtaj_polje(polje);

	system("cls");

	while (tocka_x.redak != tocka_B.redak && tocka_x.stupac != tocka_B.stupac)
	{
		do {

			if (tocka_B.stupac < tocka_A.stupac) {
				tocka_x.stupac--;
			}
			else
			{
				tocka_x.stupac++;
			}

			azuriraj_polje(polje, tocka_A, tocka_B, tocka_x);

			iscrtaj_polje(polje);

			Sleep(100);

			system("cls");
		} while (tocka_x.stupac != tocka_B.stupac);

		do {

			if (tocka_B.redak < tocka_A.redak) 
			{
				tocka_x.redak--;
			}
			else 
			{ 
				tocka_x.redak++; 
			}

			azuriraj_polje(polje, tocka_A, tocka_B, tocka_x);

			iscrtaj_polje(polje);

			Sleep(100);

			system("cls");

		} while (tocka_x.redak != tocka_B.redak);
	}

	return 0;
}