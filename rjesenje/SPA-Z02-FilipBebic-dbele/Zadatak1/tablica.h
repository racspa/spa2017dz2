#ifndef _TABLICA_H_
#define _TABLICA_H_

const int S = 40;
const int R = 20;

const int pauza = 100;

class Tablica
{
private:
	bool dovrseno=false;
	int Pocetna_Redak;
	int Pocetna_Stupac;
	int Krajnja_Redak;
	int Krajnja_Stupac;
	int Trenutna_Redak;
	int Trenutna_Stupac;

public:
	int Dobij_Pauzu();
	void Upisi();
	bool Dovrseno();
	void Iscrtaj();
	void Korak();
	void Zadnji_Korak();
};



#endif // _TABLICA_H_
