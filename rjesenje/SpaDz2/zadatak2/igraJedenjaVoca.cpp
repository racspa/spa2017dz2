#include "igraJedenjaVoca.h"
#include <ctime>
#include <Windows.h>
#include <conio.h>


// konstruktor postavlja nasumicno vocku, igraca na sredinu polja i pocetni smjer kretanja u desno, a zatim napravi i iscrta polje
igraJedenjaVoca::igraJedenjaVoca()
{
	postaviVocku();
	igrac.x = REDAKA / 2;
	igrac.y = STUPACA / 2;
	smjer = DESNO;
	popuniPolje();
	iscrtaj();
}


// funkcija za iduci korak igre
bool igraJedenjaVoca::iduciKorak()
{
	// poziva se funkcija koja mijenja smjer kretanja igraca ukoliko je neka tipka pritisnuta
	smjerNew = tipka();
	smjer = smjerNew;
	// ako je igrac pritisnuo 'k' za kraj ili se zabio u rub igrace ploce, funkcija vraca false
	if (smjer == KRAJ || igrac.x==0 || igrac.x==REDAKA-1 || igrac.y==0 || igrac.y==STUPACA-1) {
		return false;
	}
	// ako je igrac pojeo vocku, ista se postavlja na novu lokaciju sve dok ne postane razlicita od igraca
	while (vocka.x == igrac.x && vocka.y == igrac.y) {
		postaviVocku();
	}
	// poziva se funkcija za novu poziciju igraca, radi polje i vraca uspjeh
	novaPozicijaIgraca();
	popuniPolje();
	return true;
}


// slucajan broj za postavljanje vocke
int igraJedenjaVoca::slucajanBroj(int min, int max)
{
	return rand() % (max - min + 1) + min;
}


// funkcija za postavljanje vocke, unutar polja (bez ruba)
void igraJedenjaVoca::postaviVocku()
{
	srand(time(nullptr));
	vocka.x = slucajanBroj(1, REDAKA - 2);
	vocka.y = slucajanBroj(1, STUPACA - 2);
}


// funkcija koja ovisno o mogucem unosu s tipkovnice vraca novi smjer kretanja igraca
Smjer igraJedenjaVoca::tipka()
{
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': return LIJEVO;
		case 'w': return GORE;
		case 'd': return DESNO;
		case 's': return DOLJE;
		case 'k': return KRAJ;
		default: return smjer;
		}
	}
	return smjer;
}


// preko smjera funkcija racuna novu poziciju igraca
void igraJedenjaVoca::novaPozicijaIgraca()
{
	switch (smjer) {
	case DESNO: igrac.y++;
		break;
	case LIJEVO: igrac.y--;
		break;
	case GORE: igrac.x--;
		break;
	case DOLJE: igrac.x++;
		break;
	default:
		break;
	}
}


// funkcija za popunjavanje polja
void igraJedenjaVoca::popuniPolje()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (j == 0 || j == STUPACA - 1 || i == 0 || i == REDAKA - 1) {
				igracePolje[i][j] = Znakovi::RUB;
			}
			else {
				igracePolje[i][j] = Znakovi::PRAZNO;
			}
		}
	}
	igracePolje[igrac.x][igrac.y] = Znakovi::IGRAC;
	igracePolje[vocka.x][vocka.y] = Znakovi::VOCKA;
}


// iscrtavanje polja
void igraJedenjaVoca::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (igracePolje[i][j] == Znakovi::PRAZNO) {
				cout << " ";
			}
			else if (igracePolje[i][j] == Znakovi::RUB) {
				cout << "#";
			}
			else if (igracePolje[i][j] == Znakovi::VOCKA) {
				cout << "D";
			}
			else {
				cout << "X";
			}
		}
		cout << endl;
	}
	Sleep(100);
	system("CLS");
}


