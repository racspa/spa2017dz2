#include "IgraTocke.h"
#include <Windows.h>

IgraTocke::IgraTocke(Tocka A, Tocka B)
{
	this->x = x;
	this->A = A;
	this->B = B;

	if (A.x < B.x)
	{
		x.x = A.x;
		x.y = A.y + 1;
	}
	if (A.x > B.x)
	{
		x.x = A.x;
		x.y = A.y - 1;
	}

	//prvi grid
	for (int i = 1; i <= granica_x; i++)
	{
		for (int j = 1; j <= granica_y; j++)
		{
			if (A.x == i && A.y == j)
			{
				this->grid[i][j] = 'A';
			}
			else if (B.x == i && B.y == j)
			{
				this->grid[i][j] = 'B';
			}
			else if (x.x == i && x.y == j)
			{
				this->grid[i][j] = 'x';
			}

			else
			{
				this->grid[i][j] = '-';
			}
		}
	}

	
}

Tocka IgraTocke::NoviX()
{
	Tocka noviX;

	if (x.y != B.y)
	{
		if (x.y < B.y)
		{
			noviX.x = x.x;
			noviX.y = x.y + 1;
		}
		else if (x.y > B.y)
		{
			noviX.x = x.x;
			noviX.y = x.y - 1;
		}
	}
	else if (x.y = B.y)
	{
		if (x.x < B.x)
		{
			noviX.x = x.x + 1;
			noviX.y = x.y;
		}
		else if (x.x > B.x)
		{
			noviX.x = x.x - 1;
			noviX.y = x.y;
		}
	}

	x.x = noviX.x;
	x.y = noviX.y;

	return x;
}

void IgraTocke::SljedeciGrid()
{
	NoviX();

	for (int i = 1; i <= granica_x; i++)
	{
		for (int j = 1; j <= granica_y; j++)
		{
			if (A.x == i && A.y == j)
			{
				sljedeciGrid[i][j] = 'A';
			}
			else if (B.x == i && B.y == j)
			{
				sljedeciGrid[i][j] = 'B';
			}
			else if (x.x == i && x.y == j)
			{
				sljedeciGrid[i][j] = 'x';
			}
			else
			{
				sljedeciGrid[i][j] = '-';
			}
		}
	}


	for (int i = 1; i <= granica_x; i++)
	{
		for (int j = 1; j <= granica_y; j++)
		{
			grid[i][j] = sljedeciGrid[i][j];
		}
	}
}

void IgraTocke::Iscrtaj()
{
	system("CLS");

	for (int i = 1; i <= granica_x; i++)
	{
		for (int j = 1; j <= granica_y; j++)
		{
			cout << grid[i][j];
		}

		cout << endl;
	}

	Sleep(100);
}

bool IgraTocke::Alive()
{
	if (x.x == B.x && x.y == B.y)
	{
		return false;
	}
}
