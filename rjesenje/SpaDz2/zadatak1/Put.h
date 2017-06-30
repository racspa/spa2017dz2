#ifndef PUT_H_
#define PUT_H_
#include "Tocka.h"
#include <iostream>
typedef Tocka ELTYPE;
typedef int POSITION;
class Put
{
public:
	void unos(ELTYPE &A, ELTYPE &B);
	void crtaj();
	void umetni(ELTYPE &A,ELTYPE &B);
	void putovanje(ELTYPE &A, ELTYPE &B);
	void stavi_x(ELTYPE &A);
	void swap(ELTYPE &A);
	void swap_A(ELTYPE &A);
	Put();

private:
	static const unsigned int REDAKA = 21;
	static const unsigned int STUPACA = 41;
	char _polje_tocaka[REDAKA][STUPACA];
	char znak_tockaA = 'A';
	char znak_tockaB = 'B';
	char znak_put = 'X';
	char znak_prazno = '-';

};

#endif // !PUT_H_

