#include "tablica.h"
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;


Tablica::Tablica()
{
	PostaviRandSeed();
	DobijNovuVocku();
}

void Tablica::GetLastKey()
{
	if (_kbhit()) {
		tempkey= _getch();
	}
	if (tempkey == 'a' || tempkey == 'w' || tempkey == 's' || tempkey == 'd' || tempkey == 'k') {
		lastKey = tempkey;
		 }
}

int Tablica::Dobij_Pauzu()
{
	return pauza;
}

bool Tablica::IgracNaVocki()
{
	if (Igrac_Stupac == Vocka_Stupac && Igrac_Redak == Vocka_Redak) {
		return true;
	}
	return false;
}

void Tablica::Iscrtaj()
{
	system("cls");
	for (short unsigned int r = 0; r < R;r++) {
		for (short unsigned int s = 0; s < S;s++) {
			if (s == Igrac_Stupac & r == Igrac_Redak) { cout << 'X'; }
			else if (s == Vocka_Stupac & r == Vocka_Redak) { cout << 'D'; }
			else if (s == 0 || r == 0 || s == S-1 || r == R-1) { cout << '#'; }
			else { cout << '-'; }
		}
		cout << endl;
	}
}

void Tablica::Korak()
{
	GetLastKey();

	if (lastKey == 'k') {
		exit(0);
	}
	else if (lastKey == 'a') {
		Igrac_Stupac--;
	}
	else if (lastKey == 'd') {
		Igrac_Stupac++;
	}
	else if (lastKey == 'w') {
		Igrac_Redak--;
	}
	else if (lastKey == 's') {
		Igrac_Redak++;
	}
	
	if (Igrac_Stupac == 0 || Igrac_Redak == 0 || Igrac_Stupac == S - 1 || Igrac_Redak == R - 1) { 
		exit(0); 
	}

	if (IgracNaVocki()) {
		while (Vocka_Redak == Igrac_Redak && Vocka_Stupac == Igrac_Stupac) {
			DobijNovuVocku();
		}
	}
	
}

void Tablica::PostaviRandSeed()
{
	srand(time(NULL));
}

void Tablica::DobijNovuVocku()
{
	Vocka_Redak = rand() % (R - 2) + 1;
	Vocka_Stupac = rand() % (S - 2) + 1;

	while (Vocka_Redak == R / 2 && Vocka_Stupac == S / 2) {
		Vocka_Redak = rand() % (R - 2) + 1;
		Vocka_Stupac = rand() % (S - 2) + 1;
	}
}
