#ifndef ZMIJA_BEZ_REPA_H
#define ZMIJA_BEZ_REPA_H
#include"Tocka.h"
#include<iostream>
#include<ctime>
#include<conio.h>	
using namespace std;


class zmijaBezRepa
{
public:
	zmijaBezRepa();
	bool sljedeci_korak();
	void iscrtaj();

private:
	static const unsigned int REDAK = 27;
	static const unsigned int STUPAC = 32;
	char polje[REDAK][STUPAC];
	int random_broj(int min, int max);
	Tocka igrac;
	Tocka voce;
	void promijeni_lokaciju_voca();
	void promijeni_lokaciju_igraca();
	char naredba;
	void unesena_naredba();
};











#endif // !ZMIJA_BEZ_REPA_H

