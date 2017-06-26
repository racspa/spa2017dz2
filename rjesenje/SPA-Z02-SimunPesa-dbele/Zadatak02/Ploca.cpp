#include "Ploca.h"

void Ploca::init()
{
    srand(time(nullptr));

    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
                polje[i][j] = '#';
        }
    }
    kretnja();
    system("cls");
}

void Ploca::slucajna_vrijednost(Ploca &igrac, Ploca &vocka)
{
    vocka.redak = rand() % (REDAKA - 2) + 1;
    vocka.stupac = rand() % (STUPACA - 2) + 1;

    if (vocka.redak == igrac.redak && vocka.stupac == igrac.stupac)
    {
    slucajna_vrijednost(igrac,vocka);
    }
}

void Ploca::iscrtaj()
{
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            cout << polje[i][j];
        }
        cout << endl;
    }
}

void Ploca::punjenje_polja(Ploca &igrac, Ploca &vocka)
{
    for (int i = 1; i < REDAKA - 1; i++)
    {
        for (int j = 1; j < STUPACA - 1; j++)
        {
            {
                polje[i][j] = ' ';
            }
        }
    }
    polje[igrac.redak][igrac.stupac] = 'X';
    polje[vocka.redak][vocka.stupac] = 'D';
}

void Ploca::kretnja()
{
    Ploca igrac;
    Ploca vocka;

    igrac.redak = (REDAKA - 2) / 2;
    igrac.stupac = (STUPACA - 2) / 2;
    slucajna_vrijednost(igrac, vocka);
    char unos = '0';
    char zadnji_unos = '0';
    
    while (true)
    {
        system("cls");
        smjer(igrac, unos);
        zadnji_unos = unos;
        punjenje_polja(igrac, vocka);
        iscrtaj();
        Sleep(100);

        if (_kbhit())
        {
             unos = get_user_input();
        }
        if (!(unos == 'k' || unos == 'w' || unos == 'a' || unos == 's' || unos == 'd'))
        {
            unos = zadnji_unos;
        }
        if ( unos == 'k' || igrac.redak == 0 || igrac.redak == REDAKA - 1 || igrac.stupac == 0 || igrac.stupac == STUPACA - 1)
        {
            break;
        }
        if (igrac.redak == vocka.redak && igrac.stupac == vocka.stupac)
        {
            slucajna_vrijednost(igrac, vocka);
        }
    }
}

void Ploca::smjer(Ploca &igrac, char &unos)
{
    switch (unos)
    {
    case '0':
        igrac.stupac++;
        break;
    case 'w':
        igrac.redak--;
        break;
    case 's':
        igrac.redak++;
        break;
    case 'a':
        igrac.stupac--;
        break;
    case 'd':
        igrac.stupac++;
        break;
    }
}

char Ploca::get_user_input()
{
    if (_kbhit())
     {
         return _getch();        
     }
  return 0;
}