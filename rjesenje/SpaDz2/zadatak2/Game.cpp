#include<iostream>
#include<ctime>
#include<Windows.h>
#include<conio.h>
#include "Game.h"

using namespace std;

game::game() {
	xplayer = visina / 2;
	yplayer = sirina / 2;
	for (int i = 0; i < visina; i++) {
		for (int j = 0; j < sirina; j++) {
			if (i == 0 || i == (visina - 1) || j == 0 || j == (sirina - 1)) {
				_polje[i][j] = '#';
				continue;
			}
			_polje[i][j] = ' ';
		}
	}
	_polje[xplayer][yplayer] = znakp;
	srand(time(NULL));
	newVocka();
}

char game::get_user_input() {
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}

void game::d() {
	_polje[xplayer][yplayer] = ' ';
	yplayer++;
	_polje[xplayer][yplayer] = znakp;
}

void game::s() {
	_polje[xplayer][yplayer] = ' ';
	xplayer++;
	_polje[xplayer][yplayer] = znakp;
}

void game::a() {
	_polje[xplayer][yplayer] = ' ';
	yplayer--;
	_polje[xplayer][yplayer] = znakp;
}

void game::w(){
	_polje[xplayer][yplayer] = ' ';
	xplayer--;
	_polje[xplayer][yplayer] = znakp;
}

bool game::end() {
	for (int i = 0; i < visina; i++) {
		for (int j = 0; j < sirina; j++) {
			if (get_user_input() == 'k' || _polje[0][j] == znakp || _polje[visina - 1][j] == znakp || _polje[i][0] == znakp || _polje[i][sirina - 1] == znakp) {
				return true;
			}
		}
	}
	return false;
}


void game::newVocka() {
	do {
		xvocka = rand() % (visina - 2) + 1;
		yvocka = rand() % (sirina - 2) + 1;
		_polje[xvocka][yvocka] = znakv;
	} while (xvocka == xplayer && yvocka == yplayer);
}

void game::play_game() {
	char p;
	do {
		system("cls");
		Sleep(100);
		for (int i = 0; i < visina; i++) {
			for (int j = 0; j < sirina; j++) {
				cout << _polje[i][j];
			}
			cout << endl;
		}
		p = get_user_input();

		if (p == 'a' || p == 's' || p == 'd' || p == 'w') {
			unos = p;
		}
		switch (unos) {
		case 'w':w();
			break;
		case 's':s();
			break;
		case 'a':a();
			break;
		case'd':d();
			break;
		default:d();
			break;
		}
		if (xplayer == xvocka && yplayer == yvocka) {
			newVocka();
		}
		p = get_user_input();

	} while (!end());
}
