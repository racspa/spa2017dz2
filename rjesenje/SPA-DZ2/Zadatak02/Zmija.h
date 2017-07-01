#ifndef ZMIJA_H
#define ZMIJA_H

#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

class Zmija
{
public:
	Zmija();
	void map_init();
	void fruit_init();
	void player_init();
	char get_user_input();
	void move(char smijer);
	void random_broj();
	int igrac_redak = REDAKA / 2;
	int igrac_stupac = STUPACA / 2;
	int random_stupac_vocka = NULL;
	int random_redak_vocka = NULL;
	void valid_input(char& smjer_kretanja, char& smjer);

private:
	static const unsigned int REDAKA = 25;
	static const unsigned int STUPACA = 30;
	char igraca_ploca[REDAKA][STUPACA];
	
};
#endif // !ZMIJA_H
