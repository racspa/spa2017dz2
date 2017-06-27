#include "Igra_zmijica.h"
#include <ctime>
#include <Windows.h>
#include <conio.h>

Igra_zmijica::Igra_zmijica()
{
	this->D = D;
	this->X = X;

	X.y = 13;
	X.x = 15;

	srand(time(nullptr));
	get_random_D();

	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			if (i == 0 || i == max_y - 1 || j == 0 || j == max_x - 1)
			{
				this->grid[i][j] = '#';
			}
			else if (D.y == i && D.x == j)
			{
				this->grid[i][j] = 'D';
			}
			else if (i == 13 && j == 15)
			{
				this->grid[i][j] = 'X';
			}
			else
			{
				this->grid[i][j] = ' ';
			}
		}
	}
}

Tocka Igra_zmijica::get_random_D()
{
	D.x = rand() % max_x;
	D.y = rand() % max_y;

	if (D.x == 0 || D.x == max_x - 1 || D.y == 0 || D.y == max_y - 1) {
		return get_random_D();
	}
	else if (D.x == X.x && D.y == X.y) {
		return get_random_D();
	}
	else { 
		return D; 
	}
}

void Igra_zmijica::iscrtaj()
{
	system("CLS");

	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			cout << grid[i][j];
		}

		cout << endl;
	}

	Sleep(100);
}

Tocka Igra_zmijica::novi_x(char odabir)
{
	Tocka noviX;

	switch (odabir)
	{
	case 'd':
		noviX.x = X.x + 1;
		noviX.y = X.y;
		break;
	case 'a':
		noviX.x = X.x - 1;
		noviX.y = X.y;
		break;
	case 'w':
		noviX.x = X.x;
		noviX.y = X.y - 1;
		break;
	case 's':
		noviX.x = X.x;
		noviX.y = X.y + 1;
		break;
	}

	X.x = noviX.x;
	X.y = noviX.y;

	return X;
}

Tocka Igra_zmijica::novi_d()
{
	if (X.x == D.x && X.y == D.y)
	{
		get_random_D();
		return D;
	}
}

bool Igra_zmijica::dead()
{
	if (odabir == 'k' || X.x == 0 || X.x == max_x || X.y == 0 || X.y == max_y)
	{
		return true;
	}

	return false;
}

void Igra_zmijica::NoviGrid(char odabir)
{
	novi_x(odabir);
	novi_d();
	
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			if (i == 0 || i == max_y - 1 || j == 0 || j == max_x - 1)
			{
				this->novi_grid[i][j] = '#';
			}
			else if (D.y == i && D.x == j)
			{
				this->novi_grid[i][j] = 'D';
			}
			else if (X.y == i && X.x == j)
			{
				this->novi_grid[i][j] = 'X';
			}
			else
			{
				this->novi_grid[i][j] = ' ';
			}
		}
	}

	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			grid[i][j] = novi_grid[i][j];
		}
	}

	
}

char Igra_zmijica::get_user_input()
{
	if (_kbhit()) {
		return _getch();
	}
	return 2;
}

