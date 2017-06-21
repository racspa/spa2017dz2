#ifndef _GAME_H_
#define _GAME_H_

#include"Point.h"
#include<iostream>
#include<vector>
using namespace std;

enum class MoveDir
{
	LEFT, RIGHT, UP, DOWN
};

class Game
{
public:

	Game();

	//Moves the player and prints the board
	bool update(char input);

private:

	void initField();

	bool handleInput(char input);

	bool movePlayer();

	void updatePlayerPosition();

	bool tailHit(Point& pointToCheck);
	void extendTail();

	void summonFruit();

	//Checks if the player is allowed to move to the specified point
	bool fieldAllowed(Point& pointToCheck);
	//Returns the char that the player stepped on
	char fieldHit(Point& pointToCheck);

	void printBoard();

	int getRandomInt(double from, double to);

	static const int FIELD_WIDTH = 32;
	static const int FIELD_HEIGHT = 27;
	char _field[FIELD_HEIGHT][FIELD_WIDTH];
	
	static const char WALL_CHAR = '#';
	static const char PLAYER_CHAR = 'X';
	static const char FRUIT_CHAR = 'D';
	static const char EMPTY_SPOT_CHAR = ' ';

	MoveDir _moveDir = MoveDir::RIGHT;

	vector<Point> _snake;

};

#endif // !_GAME_H_

