#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#include "Dotty.h"

using namespace std;

int mover = 3;

char get_user_input() {
    if (_kbhit()) {
        return _getch();
    }
    return 0;
}
unsigned int random(int min, int max) {
    return rand() % (max - min + 1) + min;
}
void rand_bookva(int s, int r, Dotty &bookva, Dotty &player) {
    do
    {
        bookva.x = random(2, s - 2);
        bookva.y = random(2, r - 2);
    } while (bookva.x == player.x && bookva.y == player.y);
}
void draw(int s, int r, Dotty &player, Dotty &bookva) {
    system("cls");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            if (i == 0 || i == r - 1 || j == 0 || j == s - 1)
            {
                cout << '#';
            }
            else if (i == player.y && j == player.x)
            {
                cout << 'X';
            }
            else if (i == bookva.y && j == bookva.x)
            {
                cout << 'D';
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
void check() {
    switch (get_user_input())
    {
    case 'w':
        mover = 5;
        break;
    case 's':
        mover = 2;
        break;
    case 'd':
        mover = 3;
        break;
    case 'a':
        mover = 1;
        break;
    case 'k':
        exit(0);
    }
}
bool looky(int STUPAC, int REDAK, Dotty &player, Dotty &bookva) {
    return(player.x == 0 || player.x == STUPAC - 1 || player.y == 0 || player.y == REDAK - 1);
}
void move(Dotty &player, Dotty &bookva, int move, int STUPAC, int REDAK) {
    switch (move)
    {
    case 5:
        player.y--;
        break;
    case 3:
        player.x++;
        break;
    case 1:
        player.x--;
        break;
    case 2:
        player.y++;
        break;
    default:
        break;
    }
    if (player.x == bookva.x && player.y == bookva.y)
    {
        rand_bookva(STUPAC, REDAK, bookva, player);
    }
    draw(STUPAC, REDAK, player, bookva);
}





int main() {
    srand(time(nullptr));
    Dotty bookva;
    Dotty player;
    int REDAK = 25;
    int STUPAC = 30;
    player.x = STUPAC / 2;
    player.y = REDAK / 2;
    rand_bookva(STUPAC, REDAK, bookva, player);
    bool dalje = true;
    while (dalje)
    {
        check();
        if (looky(STUPAC, REDAK, player, bookva))
        {
            exit(0);
        }
        move(player, bookva, mover, STUPAC, REDAK);
        Sleep(100);

    }

        return 0;
}