#include"Tocka.h"

void Tocka::iscrtaj()
{
	for (int i = 1; i <= REDAKA; i++)//red
	{
		for (int j = 1; j <= STUPACA; j++)//stupac
		{
			if (i == ar && j == as)
			{
				cout << "A";

			}
			else if (i == br &&j == bs)
			{
				cout << "B";

			}
			else if (i == zr && j == zs)
			{
				cout << "*";

			}
			else
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}

void Tocka::provjera()
{
	if (br<zr)
	{
		zr--;
	}
	else if (zr<br)
	{
		zr++;
	}
	else if (zs>bs)	//ako je b veci od a
	{
		zs--;
	}
	else if (zr == br && zs < bs)
	{
		zs++;
	}
	else if (zr == br && zs>bs)
	{
		zs--;
	}
}

void Tocka::petlja()
{
	do
	{
		system("cls");

		provjera();
		iscrtaj();
		_sleep(100);
	} while (zs != bs);
}

void Tocka::unos()
{
	cout << "A redak:";
	cin >> ar;
	cout << "A stupac:";
	cin >> as;
	cout << "B redak:";
	cin >> br;
	cout << "B stupac:";
	cin >> bs;
	zr = ar;
	zs = as;
}

void Tocka::go()
{
	unos();

	petlja();
}
