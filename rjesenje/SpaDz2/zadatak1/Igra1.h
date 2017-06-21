#ifndef IGRA1_H_
#define IGRA1_H_
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Igra1 {
private:
	int ax, ay, bx, by;
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	char ploca[REDAKA][STUPACA];

public:
	Igra1(int a1,int a2,int b1,int b2);
	void put();
};

#endif
