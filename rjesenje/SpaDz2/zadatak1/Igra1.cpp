#include "Igra1.h"
#include <ctime>

Igra1::Igra1(int a1, int a2, int b1, int b2)
{
	system("cls");
	a1--;
	a2--;
	b1--;
	b2--;

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (a1 == i && a2 == j) {
				
				ploca[i][j]='A';
				this->ax = i;
				this->ay = j;
				
			}
		
			else if (b1 == i && b2 == j) {
				ploca[i][j] = 'B';
				this->bx = i;
				this->by = j;
		
			}
			else {
				ploca[i][j] = '-';
			}
		}
	}
}


void Igra1::put()
{
	if (ax < bx && ay < by) {
		do {
			for (int i = 0; i < REDAKA; i++) {
				for (int j = 0; j < STUPACA; j++) {
					if (ax == i && (j == ay && j <= by)) {
						cout << "x";
					}
					else {
						cout << ploca[i][j];
					}
				}
				cout << endl;
			}

			ay++;
			Sleep(100); // Pauziraj
			system("cls"); // Ocisti
		} while (ay != by);

		do {

			for (int i = 0; i < REDAKA; i++) {
				for (int j = 0; j < STUPACA; j++) {
					if (ax == i && (j == ay && i <= bx)) {
						cout << "x";
					}
					else {
						cout << ploca[i][j];
					}
				}
				cout << endl;
			}

			ax++;
			Sleep(100); // Pauziraj
			system("cls"); // Ocisti

		} while (ax != bx);

	}
	else {
		do {
			for (int i = 0; i < REDAKA; i++) {
				for (int j = 0; j < STUPACA; j++) {
					if (ax == i && (j == ay && j >= by)) {
						cout << "x";
					}
					else {
						cout << ploca[i][j];
					}
				}
				cout << endl;
			}

			ay--;
			Sleep(100); // Pauziraj
			system("cls"); // Ocisti
		} while (ay != by);

		do {

			for (int i = 0; i < REDAKA; i++) {
				for (int j = 0; j < STUPACA; j++) {
					if (ax == i && (j == ay && i >= bx)) {
						cout << "x";
					}
					else {
						cout << ploca[i][j];
					}
				}
				cout << endl;
			}

			ax--;
			Sleep(100); // Pauziraj
			system("cls"); // Ocisti

		} while (ax != bx);

	}

}
