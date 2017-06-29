#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <ctime>
#include <conio.h>
#include "Point.h"
using namespace std;

const unsigned HEIGHT = 25;
const unsigned WIDTH = 30;

const long long GAME_SPEED = 100;
const char KEY_W = 'w';
const char KEY_A = 'a';
const char KEY_S = 's';
const char KEY_D = 'd';



void drawLine()
{
	for (int i = 0; i < WIDTH; i++) {
		cout << '#';
	}
	cout << endl;
}

void genFruit(default_random_engine &e, Point &fruit)
{
	uniform_int_distribution<unsigned> uw(1, WIDTH - 2);
	uniform_int_distribution<unsigned> uh(1, HEIGHT - 4);
	fruit.col = uw(e);
	fruit.row = uh(e);
}


void drawBoard(const Point &player, Point &fruit, default_random_engine &e)
{

	drawLine();
	for (int i = 0; i < HEIGHT -2; i++) {
		for (int j = 0; j < WIDTH; j++) {

			if (player.col < 0 || player.col >= WIDTH || player.row < 0 || player.row >= HEIGHT) {
				exit(0);
			}
			else if (j == 0) {
				cout << '#';
			}
			else if(j == WIDTH -1)
			{
				cout << '#';
			}
			else if (i == player.row && j == player.col) {
				cout << 'x';

			}
			else if(i == fruit.row && j == fruit.col)
			{
				cout << 'D';
			}
			else if (player.row == fruit.row && player.col == fruit.col) {
				genFruit(e, fruit);
			}
			else
			{
				cout << ' ';
			}
			
		}
		cout << endl;
	}
	drawLine();
}



void getKey(char &currentKey)
{
	if (_kbhit())
	{
		char key = _getch();
		if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D) {
			currentKey = key;
		}
	}

}

void movePlayer(Point &player,char &currentKey)
{
	
	switch (currentKey)
	{
	case KEY_W: {
		player.row--;
		break;
	}
	case KEY_A: {
		player.col--;
		break;
	}

	case KEY_S: {
		player.row++;
		break;
	}

	case KEY_D: {
		player.col++;
		break;
	} 
	}
}

int main()
{

	char currentKey = KEY_D;
	default_random_engine e(time(0));
	Point player, fruit;
	player.col = (WIDTH / 2) - 1;
	player.row = (HEIGHT /2) -1;
	genFruit(e, fruit);
	

	while (true)
	{
			drawBoard(player, fruit,e);
			getKey(currentKey);
			movePlayer(player,currentKey);
			this_thread::sleep_for(chrono::milliseconds(GAME_SPEED));
			system("cls");
	}
	
	return 0;
}