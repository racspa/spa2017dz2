#ifndef  PLOCA_H_
#define  PLOCA_H_

#include<Windows.h>
#include<iostream>
#include<ctime>
#include<conio.h>
#include<string>
using namespace std;

class Ploca
{
public:

    void init();

private:
    
    void kretnja();
    void slucajna_vrijednost(Ploca &igrac, Ploca &vocka);
    void punjenje_polja(Ploca &igrac, Ploca &vocka);
    void smjer(Ploca &igrac, char &unos);
    void iscrtaj();
    char get_user_input();
    
    int redak;
    int stupac;
    static const unsigned int REDAKA = 25;
    static const unsigned int STUPACA = 30;
    char polje[REDAKA][STUPACA];
    
};

#endif // ! PLOCA_H_
