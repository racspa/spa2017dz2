#include "Snake.h"

char Snake::get_user_input()
{
	if (_kbhit()) {		//dozvola za samo definirana slova i uredjivanje ako je ukljucen caps lock
		temp = tolower(_getch());
		if (temp=='w' || temp =='s' || temp =='a' || temp =='d' || temp =='k')
		{
			return temp;
		}
	}
	return 0;
}

int Snake::random_broj(int max)
{
	srand(time(nullptr));
	int min = 2;
	return rand() % (max - min + 1) + min;
}

void Snake::iscrtaj()
{
	for (int i = 1; i <= visina; i++)//red
	{
		for (int j = 1; j <=  sirina; j++)//stupac
		{
			if (i == 1 || i ==  visina || j == 1 || j ==  sirina)
			{
				cout << "#";
			}
			else if (i == dr &&j == ds)
			{
				cout << "D";
			}
			else if (i == y && j == x)
			{
				cout << "X";
			}
			else
			{
				cout << ' ';
			}
		}
		cout << endl;
	}
}

void Snake::smjer()
{
	switch (znak)
	{
	case 'w':
		y--;
		break;
	case 's':
		y++;
		break;
	case 'a':
		x--;
		break;
	case 'd':
		x++;
		break;
	case 'k':
		kraj = true;
	default:
		znak = 'w';	//da na startu krene prema gore,bez defaulta bi stajao i cekao pritisak tipke koje je po meni bolje za start...
		break;
	}
	if (znak != 0)	//nastavlja ako nije stisnut gumb
	{
		temp = znak;
	}
}

void Snake::end_new()	//provjera ako zavrsava igra ili se stvara novo voce 'D'
{
	if (x == 1 || x == sirina || y == 1 || y == visina)
	{
		kraj = true;
	}
	else if (x == ds && y == dr)
	{
		dr = random_broj(visina-1);//-1 zastita od ruba
		ds = random_broj(sirina-1);
	}
}

void Snake::nobutton()	//provjera unosa
{
	znak = get_user_input();
	if (znak == 0)
	{
		znak = temp;
	}
}

void Snake::go()
{
	do
	{
		system("cls");
		nobutton();
		iscrtaj();
		smjer();
		end_new();
		Sleep(100);
	} while (!kraj);
}
