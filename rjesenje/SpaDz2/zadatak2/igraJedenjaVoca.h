#ifndef IGRAJEDENJAVOCA_H_
#define IGRAJEDENJAVOCA_H_

#include "Tocka.h"

// moguci znakovi na ploci
enum Znakovi {
	IGRAC, VOCKA, PRAZNO, RUB
};

// moguci smjerovi kretanja igraca
enum Smjer {
	DESNO, LIJEVO, GORE, DOLJE, KRAJ
};

class igraJedenjaVoca
{
public:
	igraJedenjaVoca();
	bool iduciKorak();
	void iscrtaj();
private:
	static const int REDAKA = 25;
	static const int STUPACA = 30;
	Znakovi igracePolje[REDAKA][STUPACA];
	void popuniPolje();
	Smjer smjer, smjerNew;
	Tocka igrac, vocka, igracNew;
	int slucajanBroj(int min, int max);
	void postaviVocku();
	Smjer tipka();
	void novaPozicijaIgraca();
};

#endif // !IGRAJEDENJAVOCA_H_
