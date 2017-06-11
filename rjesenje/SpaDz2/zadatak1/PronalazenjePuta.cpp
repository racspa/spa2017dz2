#include "PronalazenjePuta.h"
#include <Windows.h>
using namespace std;


// Konstruktor poziva funkcije za unos tocaka A i B (ceka ispravan unos, unutar redaka i stupaca) te nalazi poziciju igraca dok je pocetna tocka A
igraPronalazenjaPuta::igraPronalazenjaPuta()
{
	while (!unesiTocke()) {
		system("CLS");
		cout << "Nedopusten unos. POVRATAK";
		Sleep(1000);
		system("CLS");
	};
	igrac = pozicijaIgraca(A, B);
	popuniPolje();
	iscrtaj();
}


// funkcija od korisnikovih unosa kreira dvije tocke i umanji koordinate da odgovaraju indeksima polja
bool igraPronalazenjaPuta::unesiTocke()
{
	cout << "Unesite dvije tocke, A i B, unutar (1-" << REDAKA << ") redaka i (1-" << STUPACA << ") stupaca." << endl;
	cout << "Tocka A, red: ";
	cin >> A.x;
	A.x--;
	cout << "Tocka A, stupac: ";
	cin >> A.y;
	A.y--;
	cout << "Tocka B, red: ";
	cin >> B.x;
	B.x--;
	cout << "Tocka B, stupac: ";
	cin >> B.y;
	B.y--;
	system("CLS");
	// u slucaju da je korisnik nepristojan, vraca se false pa mora ponovo unositi
	if (A.x <= 0 || A.x >= REDAKA || A.y <= 0 || A.y >= STUPACA || B.x <= 0 || B.x >= REDAKA || B.y <= 0 || B.y >= STUPACA) {
		return false;
	}
	return true;
}


// Funkcija na temelju pocetne tocke P i krajnje tocke K pronalazi novu tocku novaT (koja ce biti nova tocka pozicije igraca)
Tocka igraPronalazenjaPuta::pozicijaIgraca(Tocka P, Tocka K)
{
	Tocka novaT;
	// prvo gleda hoce li mijenjati stupac
	if (K.y > P.y) {
		novaT.y = P.y + 1;
		novaT.x = P.x;
		return novaT;
	}
	else if (P.y > K.y) {
		novaT.y = P.y - 1;
		novaT.x = P.x;
		return novaT;
	}
	else {
		novaT.y = P.y;
	}
	// ako se nije pomaknuo za stupac, mice se po redovima
	if (K.x > P.x) {
		novaT.x = P.x + 1;
	}
	else if (P.x > K.x) {
		novaT.x = P.x - 1;
	}
	else {
		novaT.x = P.x;
	}
	return novaT;
}


// U iducim koracima nova pozicija igraca se trazi po staroj. Radi se i polje svaki put, odnosno funkcija vraca false kada nema iduceg koraka (kad je igrac dosao do tocke B)
bool igraPronalazenjaPuta::iduciKorak()
{
	if (igrac.x == B.x && igrac.y == B.y) {
		return false;
	}
	igracNew = pozicijaIgraca(igrac,B);
	igrac = igracNew;
	popuniPolje();
	return true;
}


// funkcija za popunjavanje polja
void igraPronalazenjaPuta::popuniPolje()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			igracePolje[i][j] = Znakovi::PRAZNO;
		}
	}
	igracePolje[A.x][A.y] = Znakovi::A;
	igracePolje[B.x][B.y] = Znakovi::B;
	igracePolje[igrac.x][igrac.y] = Znakovi::IGRAC;
}


// funkcija za iscrtavanje polja
void igraPronalazenjaPuta::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (igracePolje[i][j] == Znakovi::PRAZNO) {
				cout << "-";
			}
			else if (igracePolje[i][j] == Znakovi::A) {
				cout << "A";
			}
			else if (igracePolje[i][j] == Znakovi::B) {
				cout << "B";
			}
			else {
				cout << "x";
			}
		}
		cout << endl;
	}
	Sleep(100);
	system("CLS");
}