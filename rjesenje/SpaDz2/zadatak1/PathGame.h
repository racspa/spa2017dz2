#ifndef _PATHGAME_H_
#define _PATHGAME_H_

#include<iostream>

using namespace std;

struct Lokacija
{
	int redak;
	int stupac;
};

class PathGame
{
private:
	static const int REDAKA=20;
	static const int STUPACA = 40;
	Lokacija a;
	Lokacija b;
	Lokacija trenutna_lok;
	char polje[REDAKA][STUPACA];
	bool unos_podataka();
	
public:
	PathGame();
	void iscrtaj();
	bool sljedeci_korak();
};

#endif // !_PATHGAME_H_
