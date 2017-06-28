#include "tablica.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


int Tablica::Dobij_Pauzu()
{
	return pauza;
}

void Tablica::Upisi()
{
	short unsigned int r0, s0, r1, s1;
	cout << "A Redak: ";
	cin >> r0;
	cout << "A Stupac: ";
	cin >> s0;
	cout << "B Redak: ";
	cin >> r1;
	cout << "B Stupac: ";
	cin >> s1;

	this->Pocetna_Redak = r0-1;
	this->Pocetna_Stupac = s0-1;
	this->Krajnja_Redak = r1-1;
	this->Krajnja_Stupac = s1-1;

	this->Trenutna_Redak = r0-1;
	this->Trenutna_Stupac = s0-1;
}

bool Tablica::Dovrseno()
{

	return dovrseno;
}

void Tablica::Iscrtaj()
{
	system("cls");
	for (short unsigned int r = 0; r < R;r++) {
		for (short unsigned int s = 0; s < S;s++) {
			if (s == Trenutna_Stupac & r == Trenutna_Redak) { cout << 'X'; }
			else if (s == Krajnja_Stupac & r == Krajnja_Redak) { cout << 'B'; }
			else if (s == Pocetna_Stupac & r == Pocetna_Redak) { cout << 'A'; }
			else { cout << '-'; }
		}
		cout << endl;
	}
}

void Tablica::Korak()
{
	if (abs(Trenutna_Redak - Krajnja_Redak) > abs(Trenutna_Stupac - Krajnja_Stupac)) {
		if (Trenutna_Redak < Krajnja_Redak) {
			Trenutna_Redak++;
		}
		else {
			Trenutna_Redak--;
		}
	}
	else {
		if (Trenutna_Stupac < Krajnja_Stupac) {
			Trenutna_Stupac++;
		}
		else {
			Trenutna_Stupac--;
		}
	}

	if (Trenutna_Stupac == Krajnja_Stupac && Trenutna_Redak == Krajnja_Redak) { 
		dovrseno = true;
		Zadnji_Korak();
	}
}

void Tablica::Zadnji_Korak()
{
	Trenutna_Redak = Krajnja_Redak;
	Trenutna_Stupac = Krajnja_Stupac;

	Krajnja_Redak = R + 2;
	Krajnja_Stupac = S + 2;

	Iscrtaj();
}
