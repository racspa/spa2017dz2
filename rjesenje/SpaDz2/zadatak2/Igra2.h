#ifndef IGRA2_H_
#define IGRA2_H_
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <Windows.h>
using namespace std;

class Igra2 {
private:
	static const unsigned int STUPACA = 30;
	static const unsigned int REDAKA =25;
	int Ax = 12;
	int Ay = 15;
	int Vockicax;
	int Vockicay;
	char znak;
	int random(int min,int max);
	char ploca[REDAKA][STUPACA];
	bool Vockica();
	bool pogoden(int ax, int ay, int VockicaX, int VockicaY);
	char get_user_input();
	int pomakniAxGore(int &Ax,int &Ay);
	int pomakniAyDesno(int &Ax, int &Ay);
	int pomakniAxDolje(int &Ax, int &Ay);
	int pomakniAyLijevo(int &Ax, int &Ay);
	void igraj(char znak);

public:
	Igra2();

};

#endif
