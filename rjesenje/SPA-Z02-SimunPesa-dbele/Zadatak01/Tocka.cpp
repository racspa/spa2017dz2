#include "Tocka.h"

//Inicijalizacija po danim parametrima
void Tocka::init()
{
    
    Tocka A;
    Tocka B;
    Tocka X;
   
    do
    {
        cout << "A redak: " << endl;
        cin >> A.redak;
        cout << "A stupac: " << endl;
        cin >> A.stupac;
    } while (!(A.redak > 0 && A.redak <= REDAKA && A.stupac > 0 && A.stupac <= STUPACA));

    do
    {
        cout << "B redak: " << endl;
        cin >> B.redak;
        cout << "B stupac: " << endl;
        cin >> B.stupac;
    } while (!(B.redak > 0 && B.redak <= REDAKA && B.stupac > 0 && B.stupac <= STUPACA));
    
    X.redak = A.redak;
    X.stupac = A.stupac;
    pomicanje(A, B, X);
    system("cls");
}
//Puni polje!
void Tocka::punjenje_polja(Tocka &A, Tocka &B, Tocka &X)
{
    
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            {
                polje[i][j] = '-';
            }
        }
    }
    polje[X.redak - 1][X.stupac - 1] = 'X';
    polje[A.redak - 1][A.stupac - 1] = 'A';
    polje[B.redak - 1][B.stupac - 1] = 'B';
}

//Iscrtavanje dvodimenzionalnog polja
void Tocka::iscrtaj()
{
    system("cls");
    for (int i = 0; i < REDAKA; i++)
    {
        for (int j = 0; j < STUPACA; j++)
        {
            cout << polje[i][j];
        }
        cout << endl;
    }
}

//Pomicanje X-a (X trazi B)
void Tocka::pomicanje(Tocka &A, Tocka &B, Tocka &X)
{

    while (X.stupac != B.stupac)
    {
        punjenje_polja(A, B, X);
        iscrtaj();
        Sleep(100);

        if (X.stupac > B.stupac)
        {
            X.stupac--;
        }
        if (X.stupac < B.stupac)
        {
            X.stupac++;
        }
    }
    
    while (X.redak != B.redak)
    {
         punjenje_polja(A, B, X);
         iscrtaj();
         Sleep(100);

         if (X.redak > B.redak)
         {
             X.redak--;
         }
         else
         {
             X.redak++;
         }
     } 
}
