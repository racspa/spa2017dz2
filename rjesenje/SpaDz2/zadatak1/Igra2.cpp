#include "Igra2.h"

int Igra2::random(int min, int max)
{
	return rand()%(max - min + 1) + min;
}

bool Igra2::Vockica()
{
	int VockicaX = random(1, 23);
	int VockicaY = random(1, 28);


	this->Vockicax = VockicaX;
	this->Vockicay = VockicaY;

	if (Vockicax != 12 || Vockicay != 15) {
		for (int i = 0; i < REDAKA; i++) {
			for (int j = 0; j < STUPACA; j++) {
				if (i == Vockicax && j == Vockicay) {
					ploca[i][j] = 'D';
				}
				
			}
		}
	}
	else {
		Vockica();
	}
	
	return true;
}

char Igra2::get_user_input()
{
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}

int Igra2::pomakniAxGore(int &Ax, int& Ay)
{      
	Ax--;
	char ch;
	if (Ax > 0) {
		do {
			ch = get_user_input();
			if (Ax == Vockicax && Ay == Vockicay) {
				ploca[Ax][Ay] = ' ';
				Vockica();
			}
			else {
				for (int i = 0; i < REDAKA; i++) {
					for (int j = 0; j < STUPACA; j++) {
						if (Ax == i &&  Ay == j) {
							cout << 'X';
						}
						else {
							cout << ploca[i][j];
						}

					}

					cout << endl;
				}
				if (ch != 0) {
					igraj(ch);
					break;
				}
				else {
					Ax--;
				}
				Sleep(100);
				system("cls");
			}


		} while (Ax != 0);
	}
	return 0;
}

int Igra2::pomakniAyDesno(int &Ax, int &Ay){
char ch;
 Ay++;

 if (Ay < 29) {
	do {
		ch = get_user_input();
		if (Ax == Vockicax && Ay == Vockicay) {
			ploca[Ax][Ay] = ' ';
			Vockica();
		}
		else {
			for (int i = 0; i < REDAKA; i++) {
				for (int j = 0; j < STUPACA; j++) {
					if (Ax == i &&  Ay == j) {
						cout << 'X';
					}
					else {
						cout << ploca[i][j];
					}

				}

				cout << endl;
			}
			if (ch != 0) {
				igraj(ch);
				break;
			}
			else {
				Ay++;
			}
			

			Sleep(100);
			system("cls");
		}


	} while (Ay != 29);
}
return 0;
}

int Igra2::pomakniAxDolje(int &Ax, int &Ay)
{
	Ax++;
	char ch;
	if (Ax < 24) {
		do {
			ch = get_user_input();
			if (Ax == Vockicax && Ay == Vockicay) {
				ploca[Ax][Ay] = ' ';
				Vockica();
			}
			else {
				for (int i = 0; i < REDAKA; i++) {
					for (int j = 0; j < STUPACA; j++) {
						if (Ax == i &&  Ay == j) {
							cout << 'X';
						}
						else {
							cout << ploca[i][j];
						}

					}

					cout << endl;
				}
				if (ch != 0) {
					igraj(ch);
					break;
				}
				else {
					Ax++;
				}
				Sleep(100);
				system("cls");
			}

		} while (Ax != 24);
	}
	return 0;
}
int Igra2::pomakniAyLijevo(int &Ax, int &Ay)
{
	Ay--;
	char ch;
	if (Ay > 0) {

		do {
			ch = get_user_input();
			if (Ax == Vockicax && Ay == Vockicay) {
				ploca[Ax][Ay] = ' ';
				Vockica();
			}
			else {
				for (int i = 0; i < REDAKA; i++) {
					for (int j = 0; j < STUPACA; j++) {
						if (Ax == i &&  Ay == j) {
							cout << 'X';
						}
						else {
							cout << ploca[i][j];
						}

					}

					cout << endl;
				}
				if (ch != 0) {
					igraj(ch);
					break;
				}
				else {

					Ay--;
				}

				Sleep(100);
				system("cls");

			}

		} while (Ay != 0);
	}
	return 0;
}
Igra2::Igra2()
{
	srand(time(nullptr));
	

	for (int i = 0; i < REDAKA; i++) {
		ploca[i][0] = '#';
		for (int j = 1; j < STUPACA; j++) {
			if (i == 0 || i == REDAKA - 1) {
				ploca[i][j] = '#';
			}
		
			else {
				ploca[i][j] = ' ';
			}
		}
		ploca[i][STUPACA - 1] = '#';
	}
	Vockica();
	znak = 'd';
	igraj(znak);
}

void Igra2::igraj(char znak)
{
	Sleep(100);
	system("cls");
	
	switch (znak) {
	case 'w':
		if ((pomakniAxGore(Ax, Ay)) == 0) {
			return;
		}
		break;

	case 'a':

		if ((pomakniAyLijevo(Ax, Ay)) == 0) {
			return;
		}
		break;
	case 's':
		if ((pomakniAxDolje(Ax, Ay)) == 0) {
			return;
		}
		break;
	case'd':
		if ((pomakniAyDesno(Ax, Ay)) == 0) {
			return;
		}
		break;
	case 'k':
		break;
	default:
		break;
	}

	return;
}
