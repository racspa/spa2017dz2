#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;

const int brojStupaca = 30;
const int brojRedaka = 25;
int Rezultat = 0;

void Start() {
	cout << "Upute:  Gore (w)\n\tDolje (s)\n\tLijevo (a)\n\tDesno (d)\n\nPritisnite [SPACE] za pokretanje igre." << endl;
	while (_getch() != ' ');
}

void Draw(int sVocka, int rVocka, int sIgrac, int rIgrac) {
	system("cls");
	for (int redak = 1; redak <= brojRedaka; redak++)
	{
		for (int stupac = 1; stupac <= brojStupaca; stupac++)
		{
			if (stupac == 1 || redak == 1 || stupac == brojStupaca || redak == brojRedaka) {
				cout << "#";
			}
			else if (stupac == sIgrac && redak == rIgrac) {
				cout << "X";
			}
			else if (stupac == sVocka && redak == rVocka) {
				cout << "D";
			}
			else {
				cout << " ";
			}
			if (stupac == brojStupaca) { cout << endl; }
		}
	}
}

int Generate_Random(int min, int max) {
	return rand() % (min - max + 1) + min;
}

void Generate_Fruit(int sx, int rx, int &sv, int &rv) {
	do
	{
		sv = Generate_Random(2, brojStupaca);
		rv = Generate_Random(2, brojRedaka);
	} while (sv == sx && rv == rx);
}

bool GotFruit(int sx, int rx, int sv, int rv) {
	if (sx == sv && rx == rv) {
		Rezultat++;
		return true;
	}
	return false;
}

bool HitFence(int sx, int rx) {
	if (sx == 1 || sx == brojStupaca || rx == 1 || rx == brojRedaka) {
		return true;
	}
	return false;
}


void Update_Game(char Smjer, int &sX, int &rX, int &sV, int &rV) {
	switch (Smjer)
	{
	case 'w': rX--;
		break;
	case 'a': sX--;
		break;
	case 's': rX++;
		break;
	case 'd': sX++;
		break;
	default:
		break;
	}

	if (GotFruit(sX, rX, sV, rV)) {
		Generate_Fruit(sX, rX, sV, rV);
	}


	Draw(sV, rV, sX, rX);
}

int main() {

	Start();
	srand(time(nullptr));
	
	int sIgrac = brojStupaca / 2;
	int rIgrac = brojRedaka / 2;
	int sVocka, rVocka;
	Generate_Fruit(sIgrac, rIgrac, sVocka, rVocka);
	char Smjer = 'd';
	
	 
	while (true)
	{
		if (_kbhit()) {
			Smjer = _getch();
		}
		if (HitFence(sIgrac, rIgrac) || Smjer == 'k') {
			cout << "Ukupan rezultat: " << Rezultat << endl;
			return 0;
		}
		Update_Game(Smjer, sIgrac, rIgrac, sVocka, rVocka);
		Sleep(100);
	}

	return 0;
}