#include"FruitGame.h"

using namespace std;

FruitGame::FruitGame() {
	
	//POSTAVLJANJE PLOCE
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (i==0 || i==REDAKA-1 || j == 0 || j == STUPACA-1)
			{
				polje[i][j] = '#';
			}
			else
			{
				polje[i][j] = ' ';
			}
		}
	}

	//POSTAVLJANJE IGRACA NA SREDINU
	igrac.redak = REDAKA / 2;
	igrac.stupac = STUPACA / 2;
	polje[igrac.redak][igrac.stupac] = 'X';

	//POSTAVLJANJE VOCA
	pomakni_voce();
	polje[voce.redak][voce.stupac] = 'D';

	//POCETNI SMJER KRETANJA
	trenutna_naredba = 'd';
}

void FruitGame::iscrtaj() {
	for (int i = 0; i <REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			cout << polje[i][j];
		}
		cout << endl;
	}
}

void FruitGame::pomakni_voce() {
	srand(time(nullptr));

	voce.redak = random_generator(1, REDAKA - 2);
	voce.stupac = random_generator(1, STUPACA - 2);
	//AKO JE VOCE NA LOKACIJI IGRACA POMAKNI PONOVNO
	if (voce.redak==igrac.redak && voce.stupac==igrac.stupac)
	{
		pomakni_voce();
	}
	polje[voce.redak][voce.stupac] = 'D';
}

int FruitGame::random_generator(int min, int max) {
	return rand() % (max - min + 1) + min;
}

bool FruitGame::sljedeci_korak() {
	input_naredbe();
	if (trenutna_naredba == 'k') {
		return 0;
	}
	
	pomakni_igraca();
	
	//POMAKNI VOCE AKO GA JE IGRAC POJEO
	if (voce.redak == igrac.redak && voce.stupac == igrac.stupac)
	{
		pomakni_voce();
	}

	//ZAVRSI AKO IGRAC POGODI ZID
	if (igrac.redak == 0 || igrac.redak == REDAKA - 1 || igrac.stupac == 0 || igrac.stupac == STUPACA - 1)
	{
		return 0;
	}

	return 1;
}

void FruitGame::input_naredbe() {	//filtrirani lowercase inputa s tipkovnice
	char temp;
	if (_kbhit()) 
	{
		temp = tolower(_getch());
		if (temp=='w' || temp == 'a' || temp == 's' || temp == 'd' || temp == 'k')
		{
			this->trenutna_naredba = temp;
		}
	}
}

void FruitGame::pomakni_igraca() {
	switch (trenutna_naredba)
	{
	case 'w':
		polje[igrac.redak][igrac.stupac] = ' ';
		igrac.redak--;
		polje[igrac.redak][igrac.stupac] = 'X';
		break;
	case 'a':
		polje[igrac.redak][igrac.stupac] = ' ';
		igrac.stupac--;
		polje[igrac.redak][igrac.stupac] = 'X';
		break;
	case 's':
		polje[igrac.redak][igrac.stupac] = ' ';
		igrac.redak++;
		polje[igrac.redak][igrac.stupac] = 'X';
		break;
	case 'd':
		polje[igrac.redak][igrac.stupac] = ' ';
		igrac.stupac++;
		polje[igrac.redak][igrac.stupac] = 'X';
		break;
	default:
		break;
	}
}