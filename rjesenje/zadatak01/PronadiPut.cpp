#include "PronadiPut.h"

PronadiPut::PronadiPut()
{	//konstruktor postavlja polje i gdje se nalaze tocke A i B
	cout << "A redak: ";
	cin >> A.redak;
	A.redak--;
	cout << "A stupac: ";
	cin >> A.stupac;
	A.stupac--;
	cout << "B redak: ";
	cin >> B.redak;
	B.redak--;
	cout << "B stupac: ";
	cin >> B.stupac;
	B.stupac--;
	X.redak = A.redak;
	X.stupac = A.stupac;
	

	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			polje[i][j] = '-';
		}
	}
	polje[A.redak][A.stupac] = 'A';
	polje[B.redak][B.stupac] = 'B';
}

void PronadiPut::iscrtaj()
{	//iscrtavanje polja
	for (int i = 0; i < REDAK; i++)
	{
		for (int j = 0; j < STUPAC; j++)
		{
			if (X.redak == i && X.stupac == j)
			{
				cout << 'X';
			}
			else
			{
				cout << polje[i][j];
			}
		}
		cout << endl;
	}
}

bool PronadiPut::sljedeci_korak()
{	//kad x dode do B gotovo
	if (X.redak == B.redak && X.stupac == B.stupac)
	{
		return false;
	}
	//ako je A prije B
	if (X.redak <= B.redak)
	{
		if (X.stupac < B.stupac)
		{
			X.stupac++;
		}
		else
		{
			X.redak++;
		}
	}
	//ako je B prije A
	if (X.redak >= B.redak)
	{
		if (X.stupac > B.stupac)
		{
			X.stupac--;
		}
		else
		{
			X.redak--;
		}
	}

	return true;
}
