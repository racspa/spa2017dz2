#ifndef POLJE_H
#define POLJE_H
#include<iostream>
using namespace std;
class Polje {
private:
	int tocke[6];
public:
	Polje(int ax, int ay, int bx, int by);
	void updateScreen();
	bool moveX();
};

#endif