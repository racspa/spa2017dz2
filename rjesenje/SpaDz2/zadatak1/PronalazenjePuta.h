#ifndef PRONALAZENJEPUTA_H_
#define PRONALAZENJEPUTA_H_

#include "Tocka.h"

enum Znakovi {
	A, B, PRAZNO, IGRAC
};

class igraPronalazenjaPuta {
public:
	igraPronalazenjaPuta();
	bool iduciKorak();
	void iscrtaj();
private:
	static const int REDAKA = 20;
	static const int STUPACA = 40;
	Znakovi igracePolje[REDAKA][STUPACA];
	Tocka A, B, igrac, igracNew;
	Tocka pozicijaIgraca(Tocka P, Tocka K);
	bool unesiTocke();
	void popuniPolje();
};

#endif // !PRONALAZENJEPUTA_H_
