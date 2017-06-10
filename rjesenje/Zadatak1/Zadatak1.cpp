#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include "Tocka.h"

typedef unsigned int uint;

constexpr uint REDAKA = 20;
constexpr uint STUPACA = 40;

using namespace std;

double udaljenost_izmedu_tocki(Tocka& A, Tocka& B) {
	return sqrt(pow(B.X - A.X, 2) + pow(B.Y - A.Y, 2));
}

bool sort_po_udaljenosti(Tocka& A, Tocka& B) { 
	return A.d > B.d;
}

Tocka najbliza_tocka_u_vektoru(vector<Tocka>& vt) {
	sort(vt.begin(), vt.end(), sort_po_udaljenosti);
	return vt.back();
}

Tocka sljedeca_najbliza_tocka(Tocka& trenutna_tocka, Tocka& krajnja_tocka) {
	vector<Tocka> vt;
	Tocka temp;

	if (trenutna_tocka.X > 0) {
		temp.X = trenutna_tocka.X - 1;
		temp.Y = trenutna_tocka.Y;

		vt.push_back(temp);

		if (trenutna_tocka.Y > 0) {
			temp.X = trenutna_tocka.X - 1;
			temp.Y = trenutna_tocka.Y - 1;

			vt.push_back(temp);
		}

		if (trenutna_tocka.Y + 1 < REDAKA) {
			temp.X = trenutna_tocka.X - 1;
			temp.Y = trenutna_tocka.Y + 1;

			vt.push_back(temp);
		}
	}

	if (trenutna_tocka.X + 1 < STUPACA) {
		temp.X = trenutna_tocka.X + 1;
		temp.Y = trenutna_tocka.Y;

		vt.push_back(temp);

		if (trenutna_tocka.Y > 0) {
			temp.X = trenutna_tocka.X + 1;
			temp.Y = trenutna_tocka.Y - 1;

			vt.push_back(temp);
		}

		if (trenutna_tocka.Y + 1 < REDAKA) {
			temp.X = trenutna_tocka.X + 1;
			temp.Y = trenutna_tocka.Y + 1;

			vt.push_back(temp);
		}
	}

	if (trenutna_tocka.Y > 0) {
		temp.X = trenutna_tocka.X;
		temp.Y = trenutna_tocka.Y - 1;

		vt.push_back(temp);
	}

	if (trenutna_tocka.Y + 1 < REDAKA) {
		temp.X = trenutna_tocka.X;
		temp.Y = trenutna_tocka.Y + 1;

		vt.push_back(temp);
	}

	for (auto& tocka : vt)
		tocka.d = udaljenost_izmedu_tocki(tocka, krajnja_tocka);

	return najbliza_tocka_u_vektoru(vt);
}

void iscrtaj(Tocka& A, Tocka& B, Tocka trenutna_lokacija) {
	system("cls");

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (i == trenutna_lokacija.Y && j == trenutna_lokacija.X)
				cout << 'x';
			else if (i == A.Y && j == A.X)
				cout << 'A';
			else if (i == B.Y && j == B.X)
				cout << 'B';
			else
				cout << '-';
		}
		cout << endl;
	}

	if (trenutna_lokacija.X == B.X && trenutna_lokacija.Y == B.Y)
		return;

	_sleep(100);
	iscrtaj(A, B, sljedeca_najbliza_tocka(trenutna_lokacija, B));
}

int main() {

	Tocka A, B;

	do {
		cout << "A redak: ";
		cin >> A.Y;
	} while (A.Y < 1 || A.Y > REDAKA);

	do {
		cout << "A stupac: ";
		cin >> A.X;
	} while (A.X < 1 || A.X > STUPACA);

	do {
		cout << "B redak: ";
		cin >> B.Y;
	} while (B.Y < 1 || B.Y > REDAKA);

	do {
		cout << "B stupac: ";
		cin >> B.X;
	} while (B.X < 1 || B.X > STUPACA);

	A.Y--;
	A.X--;
	B.Y--;
	B.X--;

	iscrtaj(A, B, A);

	return 0;
}