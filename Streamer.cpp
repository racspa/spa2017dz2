#include<iostream>
#include<ctime>
#include<Windows.h>
#include "Streamer.h"

using namespace std;
    

void Traveling::input(ELTYPE & A, ELTYPE & B)
{
    do
    {
        cout << "Unesite redak za tocku A: ";
        cin >> A.x;
    } while (A.x<1 || A.x>REDAK);

    do
    {
        cout << "Unesite stupac za tocku A: ";
        cin >> A.y;
    } while (A.y<1 || A.y>STUPAC);

    do
    {
        cout << "Unesite redak za tocku B: ";
        cin >> B.x;
    } while (B.x<1 || B.x>REDAK);

    do
    {
        cout << "Unesite stupac za tocku B: ";
        cin >> B.y;
    } while (B.y<1 || B.y>STUPAC);

}

void Traveling::draw()
{
    for (POSITION i = 1; i < REDAK; i++) {
        for (POSITION j = 1; j < STUPAC; j++) {
            cout << _field_dot[i][j];
        }
        cout << endl;
    }
    Sleep(100);
}

void Traveling::put(ELTYPE & A, ELTYPE & B)
{

    _field_dot[A.x][A.y] = char_pointA;
    _field_dot[B.x][B.y] = char_pointB;

}

void Traveling::Streaming(ELTYPE & A, ELTYPE & B)
{
    Point x;
    x = A;
    while (A.x < B.x)
    {
        system("cls");
        swap(A);
        A.x++;
        swap_A(x);
        putt_x(A);
        draw();
        while (A.y < B.y)
        {
            system("cls");
            swap(A);
            A.y++;
            putt_x(A);
            draw();
        }
        while (A.y>B.y)
        {
            system("cls");
            swap(A);
            A.y--;
            putt_x(A);
            draw();
        }
    }
    while (A.x > B.x)
    {
        system("cls");
        swap(A);
        A.x--;
        swap_A(x);
        putt_x(A);
        draw();
        while (A.y > B.y)
        {
            system("cls");
            swap(A);
            A.y--;
            putt_x(A);
            draw();
        }
    }
    while (A.x == B.x && A.y > B.y)
    {
        system("cls");
        swap_A(x);
        A.y--;
        swap_A(x);
        putt_x(A);
        draw();
    }
    while (A.x == B.x && A.y < B.y)
    {
        system("cls");
        swap(A);
        A.y++;
        swap_A(x);
        putt_x(A);
        draw();
    }
    while (A.x > B.x && A.y == B.y)
    {
        system("cls");
        swap_A(x);
        A.x--;
        swap_A(x);
        putt_x(A);
        draw();
    }
    while (A.x < B.x && A.y == B.y)
    {
        system("cls");
        swap(A);
        A.x++;
        swap_A(x);
        putt_x(A);
        draw();
    }


}

void Traveling::putt_x(ELTYPE & A)
{
    _field_dot[A.x][A.y] = char_traveling;
}

void Traveling::swap(ELTYPE & A)
{
    _field_dot[A.x][A.y] = char_empty;
}

void Traveling::swap_A(ELTYPE & A)
{
    _field_dot[A.x][A.y] = char_pointA;
}

Traveling::Traveling()
{

    for (POSITION i = 1; i < REDAK; i++)
    {
        for (POSITION j = 1; j <STUPAC; j++)
        {
            _field_dot[i][j] = char_empty;
        }
    }

}

