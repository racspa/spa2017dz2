#ifndef PRONADI_PUT_H_
#define PRONADI_PUT_H_

#include<iostream>
using namespace std;
#include"Tocka.h"


class PronadiPut
{
public:
	PronadiPut();
	void iscrtaj();
	bool sljedeci_korak();

private:
	static const unsigned int REDAK = 20;
	static const unsigned int STUPAC = 40;
	Tocka A;
	Tocka B;
	Tocka X;
	char polje[REDAK][STUPAC];


};









#endif // !PRONADI_PUT_H_

