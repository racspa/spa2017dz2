#ifndef TOCKA_H
#define TOCKA_H
#include <iostream>
using namespace std;

class Tocka
{
private:
	int ar, as, br, bs, zr, zs;//red,stupac,zvjezdica
	static const int  REDAKA = 20;
	static const int  STUPACA = 40;

public:
	//Tocka();
	void iscrtaj();
	void provjera();
	void petlja();
	void unos();
	void go();
	
};

#endif//TOCKA_H
