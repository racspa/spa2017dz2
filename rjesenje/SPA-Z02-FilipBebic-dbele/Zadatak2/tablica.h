#ifndef _TABLICA_H_
#define _TABLICA_H_

const int S = 30;
const int R = 25;

const int pauza = 100;

class Tablica
{
private:
	bool igracNaVocki =false;
	int Vocka_Redak;
	int Vocka_Stupac;
	int Igrac_Redak=R/2;
	int Igrac_Stupac=S/2;

public:
	char lastKey = 'd';
	char tempkey = 'd';
	Tablica();
	void GetLastKey();
	int Dobij_Pauzu();
	bool IgracNaVocki();
	void Iscrtaj();
	void Korak();
	void PostaviRandSeed();
	void DobijNovuVocku();
};



#endif // _TABLICA_H_
