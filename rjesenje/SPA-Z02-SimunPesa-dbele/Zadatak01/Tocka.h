#ifndef TOCKA_H_
#define TOCKA_H_
#include<Windows.h>
#include<iostream>
#include<string>
using namespace std;


class Tocka
{
public:
    void init();
    
private:
    void punjenje_polja(Tocka &A, Tocka &B, Tocka &X);
    void pomicanje(Tocka &A, Tocka &B, Tocka &X);
    void iscrtaj();
    int redak;
    int stupac;
    static const unsigned int STUPACA = 40;
    static const unsigned int REDAKA = 20;
    char polje[REDAKA][STUPACA]; 

};

#endif // !TOCKA_H_
