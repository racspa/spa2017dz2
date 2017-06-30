#include "Put.h"
#include <ctime>
#include <iostream>
#include <Windows.h>

using namespace std;
void Put::unos(ELTYPE &A,ELTYPE &B)
{
	do
	{
		cout << "Unesite redak tocke A: ";
		cin >> A.x;
	} while (A.x<1 ||A.x>REDAKA);
	do
	{
		cout << "Unesite stupac tocke A: ";
		cin >> A.y;
	} while (A.y<1 || A.y>STUPACA);
	do
	{
		cout << "Unesite redak tocke B: ";
		cin >> B.x;
	} while (B.x<1 || B.x>REDAKA);
	do
	{
		cout << "Unesite stupac tocke B: ";
		cin >> B.y;
	} while (B.y<1 || B.y>STUPACA);
	
}
void Put::crtaj()
{
	
	for (POSITION i = 1; i < REDAKA; i++)
	{
		for (POSITION j = 1; j <STUPACA; j++)
		{
			cout << _polje_tocaka[i][j];

		}
		cout << endl;
	}
	Sleep(100);
}

void Put::umetni(ELTYPE &A,ELTYPE &B)
{
	_polje_tocaka[A.x][A.y] = znak_tockaA;
	_polje_tocaka[B.x][B.y] = znak_tockaB;
	

	
}

void Put::putovanje(ELTYPE &A, ELTYPE &B)
{
	Tocka x;
	x = A;

	
	while  (A.x < B.x)
		{
			system("cls");
			swap(A);
			A.x++;
			swap_A(x);
			stavi_x(A);
			crtaj();
			while (A.y < B.y)
			{
				system("cls");
				swap(A);
				A.y++;
				stavi_x(A);
				crtaj();
			}
			while (A.y>B.y)
			{
				system("cls");
				swap(A);
				A.y--;
				stavi_x(A);
				crtaj();
			}

		}


		while  (A.x > B.x)
		{
			system("cls");
			swap(A);
			A.x--;
			swap_A(x);
			stavi_x(A);
			crtaj();
			while (A.y > B.y)
			{
				system("cls");
				swap(A);
				A.y--;
				stavi_x(A);
				crtaj();
			}

		}
		while (A.x == B.x && A.y > B.y)
		{
			system("cls");
			swap_A(x);
			A.y--;
			swap_A(x);
			stavi_x(A);
			crtaj();
		}
		while (A.x == B.x && A.y < B.y)
		{
			system("cls");
			swap(A);
			A.y++;
			swap_A(x);
			stavi_x(A);
			crtaj();
		}



		while (A.x > B.x && A.y == B.y)
		{
			system("cls");
			swap_A(x);
			A.x--;
			swap_A(x);
			stavi_x(A);
			crtaj();
		}
		while (A.x < B.x && A.y == B.y)
		{
			system("cls");
			swap(A);
			A.x++;
			swap_A(x);
			stavi_x(A);
			crtaj();
		}
}

void Put::stavi_x(ELTYPE &A)
{
	_polje_tocaka[A.x][A.y] = znak_put;
}

void Put::swap(ELTYPE & A)
{
	_polje_tocaka[A.x][A.y] = znak_prazno;
}

void Put::swap_A(ELTYPE & A)
{
	_polje_tocaka[A.x][A.y] = znak_tockaA;
}

Put::Put()
{
	for (POSITION i = 1; i < REDAKA; i++)
	{
		for (POSITION j = 1; j <STUPACA; j++)
		{
			_polje_tocaka[i][j] = znak_prazno;

		}
	}
}





