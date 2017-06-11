#include"PathGame.h"

using namespace std;


PathGame::PathGame() {
	cout << "Unesite tocke:" << endl;

	while (!unos_podataka())
	{
		cout << "Neispravan unos!!" << endl << "Unesite ponovno:" << endl;
	}

	a.redak--;
	a.stupac--;
	b.redak--;			//UMANJUJE VRIJEDNOSTI ZA 1 JER INDEX POLJA POÈINJE OD 0, A ISPRAVNA TOCKA OD 1
	b.stupac--;
	this->trenutna_lok.redak = a.redak;
	this->trenutna_lok.stupac = a.stupac;

	//POSTAVLJANJE POLJA CHAROVA NA POCETNE VRIJEDNOSTI(A I B NA ZADANE POZICIJE)
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (i == a.redak && j == a.stupac)
			{
				polje[i][j] = 'A';
			}
			else if (i == b.redak && j == b.stupac)
			{
				polje[i][j] = 'B';
			}
			else
			{
				polje[i][j] = '-';
			}
		}
	}
}

bool PathGame::unos_podataka() {
	cout << "Unesite redak za tocku A (ispravan unos 1-" << this->REDAKA << "): ";
	cin >> a.redak;
	cout << "Unesite stupac za tocku A (ispravan unos 1-" << this->STUPACA << "): ";
	cin >> a.stupac;
	cout << "Unesite redak za tocku B (ispravan unos 1-" << this->REDAKA << "): ";
	cin >> b.redak;
	cout << "Unesite stupac za tocku B (ispravan unos 1-" << this->STUPACA << "): ";
	cin >> b.stupac;

	//VRACA FALSE AKO KORISNIK NE UNESE ISPRAVNE TOCKE 
	if (a.redak < 1 || a.redak > REDAKA || a.stupac < 1 || a.stupac > STUPACA || b.redak < 1 || b.redak > REDAKA || b.stupac < 1 || b.stupac > STUPACA)
	{
		return 0;
	}
	return 1;
}

void PathGame::iscrtaj() {

	//ISPIS POLJA CHAROVA I "X" ZA POZICIJU NA KOJOJ SE NALAZIMO
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (trenutna_lok.redak == i && trenutna_lok.stupac == j)
			{
				cout << 'x';
			}
			else
			{
				cout << polje[i][j];
			}
		}
		cout << endl;
	}
}


bool PathGame::sljedeci_korak() {

	// VRACA FALSE AKO SMO DOSLI DO TOCKE B DA ZAUSTAVIMO WHILE PETLJU U MAINU
	if (b.redak == trenutna_lok.redak && b.stupac == trenutna_lok.stupac)
	{
		return 0;
	}

	//SMJER KRETANJA AKO JE B POSLIJE A
	if (a.redak <= b.redak)
	{
		if (this->trenutna_lok.stupac < this->b.stupac)
		{
			trenutna_lok.stupac += 1;
		}
		else
		{
			trenutna_lok.redak += 1;
		}
	}

	//SMJER KRETANJA AKO JE B PRIJE A
	else
	{
		if (this->trenutna_lok.stupac > this->b.stupac)
		{
			trenutna_lok.stupac -= 1;
		}
		else
		{
			trenutna_lok.redak -= 1;
		}
	}
	return 1;
}
