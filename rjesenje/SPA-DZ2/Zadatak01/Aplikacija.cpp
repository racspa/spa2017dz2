#include "Aplikacija.h"

app::app()
{

	for (int i = 1; i <= REDAKA; i++)
	{
		for (int j = 1; j <= STUPACA; j++)		//ploca
		{
			igraca_ploca[i][j] = '-';
		}
	}
}

void app::map_init()
{

	system("cls");
	for (int i = 1; i <= REDAKA; i++)
	{
		for (int j = 1; j <= STUPACA; j++)		//iscrtavanje mape
		{
			cout << igraca_ploca[i][j];
		}
		cout << endl;
	}

}

void app::user_input()
{

	cout << "A redak: ";
	cin >> a_redak;

	cout << "A stupac: ";
	cin >> a_stupac;

	cout << "B redak: ";
	cin >> b_redak;

	cout << "B stupac: ";
	cin >> b_stupac;

	igrac_redak = a_redak;				//pocetno mjesto igraca je A
	igrac_stupac = a_stupac;

}

void app::tocke_init()
{
	igraca_ploca[a_redak][a_stupac] = 'A';
	igraca_ploca[b_redak][b_stupac] = 'B';
}

void app::move()
{	

	delete_player();			//makni igraca s prethodnog mjesta, ako stoji na mjestu od A nemoj

	if (igrac_stupac < b_stupac)
	{
		igrac_stupac++;
	}
	else if (igrac_stupac > b_stupac)
	{
		igrac_stupac--;
	}
	else if (igrac_stupac == b_stupac && igrac_redak < b_redak)
	{
		igrac_redak++;
	}
	else if (igrac_stupac == b_stupac && igrac_redak > b_redak)
	{
		igrac_redak--;
	}

	player_init();

}

void app::player_init()
{

	if (igrac_redak == b_redak && igrac_stupac == b_stupac)
	{
		exit(0);
	}
	
	igraca_ploca[igrac_redak][igrac_stupac] = 'x';

}

void app::delete_player()
{
	if (igrac_redak == a_redak && igrac_stupac == a_stupac)
	{
		igraca_ploca[igrac_redak][igrac_stupac] = 'A';
	}
	else
	{
		igraca_ploca[igrac_redak][igrac_stupac] = '-';
	}
}
