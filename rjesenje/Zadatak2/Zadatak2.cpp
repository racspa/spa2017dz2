#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>

#include "Tocka.h"
using namespace std;

typedef unsigned int uint;

constexpr uint REDAKA = 25;
constexpr uint STUPACA = 30;

Tocka igrac;
Tocka vocka;

// 0 - gore, 1 - dolje, 2 - lijevo, 3 desno
uint smjer_kretanja = 3;

char get_user_input() {
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}

uint random_broj(uint min, uint max) {
	return rand() % (max - min + 1) + min;
}

Tocka random_tocka() {
	Tocka t;
	
	t.Y = random_broj(1, REDAKA - 2);
	t.X = random_broj(1, STUPACA - 2);

	return t;
}

void random_vocka() {
	do {
		vocka = random_tocka();
	} while (vocka.X == igrac.X && vocka.Y == igrac.Y);
}

void iscrtaj() {
	system("cls");

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (i == 0 || i == REDAKA - 1 || j == 0 || j == STUPACA - 1)
				cout << '#';
			else if (i == igrac.Y && j == igrac.X)
				cout << 'X';
			else if (i == vocka.Y && j == vocka.X)
				cout << 'D';
			else
				cout << ' ';
		}

		cout << endl;
	}
}

void update() {
	switch (smjer_kretanja) {
		case 0: {
			igrac.Y--;
			break;
		}
		case 1: {
			igrac.Y++;
			break;
		}
		case 2: {
			igrac.X--;
			break;
		}
		case 3: {
			igrac.X++;
			break;
		}
	}

	if (igrac.X == 0 || igrac.X == STUPACA - 1 || igrac.Y == 0 || igrac.Y == REDAKA - 1) {
		// igrac je udario u rub povrsine - gotova igra
		exit(0);
	}
	else if (igrac.X == vocka.X && igrac.Y == vocka.Y) {
		// igrac je pokupio vocku - stvori novu
		random_vocka();
	}

	iscrtaj();
}

int main() {
	srand(static_cast<uint>(time(nullptr)));

	igrac.X = STUPACA / 2;
	igrac.Y = REDAKA / 2;

	random_vocka();

	while (true) {
		switch (tolower(get_user_input())) {
			case 'w': {
				smjer_kretanja = 0;
				break;
			}
			case 's': {
				smjer_kretanja = 1;
				break;
			}
			case 'a': {
				smjer_kretanja = 2;
				break;
			}
			case 'd': {
				smjer_kretanja = 3;
				break;
			}
			case 'k':
				exit(0);
		}

		update();
		_sleep(100);
	}

	return 0;
}