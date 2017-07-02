#include "ZmijaBezRepa.h"

zmijaBezRepa::zmijaBezRepa()
{	//konstruktor postavlja polje i postavlja igraca i voce na pocetne pozicije

	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			if (i == 0 || i == REDAK - 1 || j == 0 || j == STUPAC - 1)
			{
				polje[i][j] = '#';
			}
			else
			{
				polje[i][j] = ' ';
			}
		}
	}

	igrac.redak = REDAK / 2;
	igrac.stupac = STUPAC / 2;
	polje[igrac.redak][igrac.stupac] = 'X';

	promijeni_lokaciju_voca();
	polje[voce.redak][voce.stupac] = 'D';

	naredba = 'd';
}

bool zmijaBezRepa::sljedeci_korak()
{	
	unesena_naredba();
	if (naredba == 'k')
	{
		return false;
	}
	promijeni_lokaciju_igraca();
	if (voce.stupac == igrac.stupac && voce.redak == igrac.redak)
	{
		promijeni_lokaciju_voca();
	}
	if (igrac.redak == 0 || igrac.redak == REDAK - 1 || igrac.stupac == 0 || igrac.stupac == STUPAC - 1)
	{
		return false;
	}
	return true;
}

void zmijaBezRepa::iscrtaj()
{	//iscrtavanje polja
	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			cout << polje[i][j];
		}
		cout << endl;
	}
}

int zmijaBezRepa::random_broj(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void zmijaBezRepa::promijeni_lokaciju_voca()
{	//mijenjanje lokacije voca
	srand(time(nullptr));
	voce.redak = random_broj(1, REDAK - 2);
	voce.stupac = random_broj(1, STUPAC - 2);
	if (voce.stupac == igrac.stupac && voce.redak == igrac.redak)
	{	//ako je voce na istoj lokaciji kao i igrac opet mijenjaj poziciju
		promijeni_lokaciju_voca();
	}
	polje[voce.redak][voce.stupac] = 'D';
}

void zmijaBezRepa::promijeni_lokaciju_igraca()
{	//mijenjanje lokacije igraca ovisno o unosu korisnika
	switch (naredba)
	{
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
	case 'w':
		polje[igrac.redak][igrac.stupac] = ' ';
		igrac.redak--;
		polje[igrac.redak][igrac.stupac] = 'X';
		break;
	default:
		break;
	}
}

void zmijaBezRepa::unesena_naredba()
{
	char slovo;
	if (_kbhit())
	{
		slovo = tolower(_getch());
		if (slovo == 'a' || slovo == 's' || slovo == 'd' || slovo == 'w' || slovo == 'k' )
		{
			this->naredba = slovo;
		}
	}
}
