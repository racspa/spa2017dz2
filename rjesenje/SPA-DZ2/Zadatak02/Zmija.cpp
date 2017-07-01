#include "Zmija.h"

Zmija::Zmija()
{

	for (int i = 1; i < REDAKA; i++)
	{
		for (int j = 1; j < STUPACA; j++)		//praznina u ploci
		{
			igraca_ploca[i][j] = ' ';
		}
	}


		for (int j = 0; j <= STUPACA; j++)
		{
			igraca_ploca[0][j] = '#';				//gornji zid
		}


	for (int i = 0; i <= REDAKA; i++)
	{
		igraca_ploca[i][STUPACA] = '#';		//desni zid
	}


		for (int j = STUPACA; j >= 0; j--)
		{
			igraca_ploca[REDAKA][j] = '#';		//donji zid
		}


	for (int i = REDAKA; i >= 0; i--)
	{
		igraca_ploca[i][0] = '#';				//lijevi zid
		}


}

void Zmija::map_init()
{
	system("cls");
	for (int i = 0; i <= REDAKA; i++)
	{
		for (int j = 0; j <= STUPACA; j++)		//iscrtavanje mape
		{
			cout << igraca_ploca[i][j];
		}
		cout << endl;
	}
}

void Zmija::fruit_init()
{

	if (random_stupac_vocka == NULL && random_redak_vocka == NULL)				//stavi prvu vocku u polje
	{
		random_broj();
		igraca_ploca[random_redak_vocka][random_stupac_vocka] = 'D';
	}
	else if (igrac_redak == random_redak_vocka && igrac_stupac == random_stupac_vocka)				//stavi novu vocku u polje ako igrac stane na mjesto na kojem se nalazi trenutna vocka
	{
		random_broj();
		igraca_ploca[random_redak_vocka][random_stupac_vocka] = 'D';
	}

}

void Zmija::player_init()
{

	if (igrac_redak == 0 || igrac_stupac == 0 || igrac_redak == REDAKA || igrac_stupac == STUPACA)			//ako je igrac udario u zid izadi
	{
		exit(0);
	}
	else																								//u protivnom stavi X na to mjesto na kojem je igrac
	{
		igraca_ploca[igrac_redak][igrac_stupac] = 'X';
	}
	

}

char Zmija::get_user_input()
{

		if (_kbhit()) {										//vrati tipku s tipkovnice, u protivnom vrati NULL
			char key = _getch();
			if (key == 'w' || key == 'a' || key == 's' || key == 'd' || key == 'k')
			{
				return key;
			}
		}
		return NULL;
	}

void Zmija::move(char smijer)
{
	igraca_ploca[igrac_redak][igrac_stupac] = ' ';			//obrisi igraca sa starog mjesta
	switch (smijer)
	{
	case 'w':
		igrac_redak--;
		break;
	case 'a':
		igrac_stupac--;
		break;
	case 's':
		igrac_redak++;
		break;
	case 'd':
		igrac_stupac++;
		break;
	case 'k':
		exit(0);
		break;
	}

}

void Zmija::random_broj()
{
	srand(time(nullptr));
	random_stupac_vocka = rand() % (STUPACA - 2) + 1;
	random_redak_vocka = rand() % (REDAKA - 2) + 1;

}

void Zmija::valid_input(char& smjer_kretanja, char& smjer)
{
	if (smjer_kretanja == NULL)
	{
		smjer = smjer;
	}
	else
	{
		smjer = smjer_kretanja;
	}
}

