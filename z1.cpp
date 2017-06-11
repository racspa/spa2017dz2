#include <iostream>
#include <Windows.h>

using namespace std;

void Input(int *rA, int *sA, int *rB, int *sB, int *rX, int *sX) {
	cout << "Unesite redak tocke A: ";
	cin >> *rA;

	cout << "Unesite stupac tocke A: ";
	cin >> *sA;

	cout << "Unesite redak tocke B: ";
	cin >> *rB;

	cout << "Unesite stupac tocke B: ";
	cin >> *sB;

	*rX = *rA;
	*sX = *sA;
}

bool End(int rX, int sX, int rB, int sB) {
	if (rX == rB && sX == sB) {
		return true;
	}
	return false;
}

void Draw(int rA, int sA, int rB, int sB, int sX, int rX, bool last) {
	system("cls");
	for (int redak = 1; redak <= 20; redak++)
	{
		for (int stupac = 1; stupac <= 40; stupac++) {
			if (redak == rA && stupac == sA) {
				cout << "A";
			}
			else if (redak == rB && stupac == sB) {
				cout << "B";
			}
			else if (redak == rX && stupac == sX) {
				if (last == false) { cout << "x"; }
				else { cout << "-"; }
			}
			else {
				cout << "-";
			}
			if (stupac == 40) { cout << "\n"; }
		}
	}
}

int main() {
	int rA, sA, rB, sB, rX, sX;
	Input(&rA, &sA, &rB, &sB, &rX, &sX);
	int count = 0;

	do
	{
		count++;
		Draw(rA, sA, rB, sB, sX, rX, 0);
		if (rX < rB) { rX++; }
		else if (rX > rB) { rX--; }
		else {
			if (sX < sB) { sX++; }
			else if (sX > sB) { sX--; }
		}
		Sleep(100);
	} while (!End(rX, sX, rB, sB));

	Draw(rA, sA, rB, sB, sX, rX, 1); //rjesi se X-a u crtezu tako da posaljes true (zadnji argument)
	cout << "Kraj. Ukupno koraka: " << count << "."<<endl;

	return 0;
}