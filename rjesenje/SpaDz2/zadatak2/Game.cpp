#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include "GameDot.h"
using namespace std;

int kretanje = 3;

char get_user_input() {
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}
unsigned int random(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void rand_vocka(int s, int r, GameDot &vocka, GameDot &igrac) {
	do
	{
		vocka.x = random(2, s - 2);
		vocka.y = random(2, r - 2);
	} while (vocka.x == igrac.x && vocka.y == igrac.y);
}

void crtaj(int s, int r, GameDot &igrac, GameDot &vocka) {
	system("cls");

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (i == 0 || i == r - 1 || j == 0 || j == s - 1)
			{
				cout << '#';
			}
			else if (i == igrac.y && j == igrac.x)
			{
				cout << 'X';
			}
			else if (i == vocka.y && j == vocka.x)
			{
				cout << 'D';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
}

void ispitaj( ) {

	switch (get_user_input())
	{
	case 'w':
		kretanje = 5;
		break;
	case 's':
		kretanje = 2;
		break;
	case 'd':
		kretanje = 3;
		break;
	case 'a':
		kretanje = 1;
		break;
	case 'k':
		exit(0);

	}
}
bool provjeri(int STUPACA, int REDAKA, GameDot &igrac, GameDot &vocka) {
	return(igrac.x == 0 || igrac.x == STUPACA - 1 || igrac.y == 0 || igrac.y == REDAKA - 1);
	
}
void move(GameDot &igrac, GameDot &vocka, int kretanje, int STUPACA, int REDAKA) {

	switch (kretanje)
	{
	case 5:
		igrac.y--;
		break;
	case 3:
		igrac.x++;
		break;
	case 1:
		igrac.x--;
		break;
	case 2:
		igrac.y++;
		break;
	default:
		break;
	}

	if (igrac.x == vocka.x && igrac.y == vocka.y)
	{
		rand_vocka(STUPACA, REDAKA, vocka, igrac);

	}

	crtaj(STUPACA, REDAKA, igrac, vocka);

}

int main() {
	srand(time(nullptr));
	GameDot vocka;
	GameDot igrac;
	int REDAKA = 25;
	int STUPACA = 30;
	igrac.x = STUPACA / 2;
	igrac.y = REDAKA / 2;
	rand_vocka(STUPACA, REDAKA, vocka, igrac);
	bool dalje = true;
	while (dalje)
	{
		ispitaj();
		if (provjeri(STUPACA, REDAKA, igrac, vocka))
		{
			exit(0);
		}
		move(igrac, vocka, kretanje, STUPACA, REDAKA);
		Sleep(100);
	}
	return 0;
}