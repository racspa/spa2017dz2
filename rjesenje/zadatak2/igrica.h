#ifndef _IGRICA_H_
#define _IGRICA_H_
#include<iostream>
using namespace std;

class igrica
{
public:
	igrica();
	void sljedeci_korak();
	bool gotovo();
private:
	void iscrtaj();
	void kretanje();
	void sudaranje();

	void stvoriVocku();

	void get_user_input();
	int random_number_generator(int min, int max);

	int igracX, igracY;
	int vockaX, vockaY;

	int smjer_kretanja = 1;

	bool igraZavrsena = false;

	const int broj_redaka = 30;
	const int broj_stupaca = 25;

	static const int lijevo = 0, desno = 1, gore = 2, dolje = 3;
};

#endif // !_IGRICA_H_

