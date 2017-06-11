#ifndef _FRUITGAME_H_
#define _FRUITGAME_H_
#include<iostream>
#include<ctime>
#include<conio.h>
#include<cctype>

struct Lokacija
{
	unsigned int redak;
	unsigned int stupac;
};

class FruitGame
{
private:
	static const int REDAKA = 25;
	static const int STUPACA = 30;
	char polje[REDAKA][STUPACA];
	Lokacija igrac;
	Lokacija voce;
	char trenutna_naredba;
	void pomakni_voce();
	int random_generator(int min, int max);
	void input_naredbe();
	void pomakni_igraca();

public:
	FruitGame();
	void iscrtaj();
	bool sljedeci_korak();
	
};


#endif // !_FRUITGAME_H_
