#ifndef _GAME_H_
#define _GAME_H_

#include"Point.h"
#include<iostream>
using namespace std;

enum class MoveDir
{
	RIGHT, LEFT, UP, DOWN
};

class Game
{
public:

	Game(Point& player, Point& target, const int fieldWidth, const int fieldHeight);

	bool movePlayer();
	void printField();

	~Game();

private:

	//Checks if the player is allowed to move to the specified point
	bool fieldAllowed(Point& pointToCheck);

	//Distance between two points
	double distance(Point& point1, Point& point2);
	//Used to figure out if player can move into the specified spot on the field
	//and to setup value for the distance from that point to the target
	void calcDistanceToTarget(Point& point, double& currentDistance);
	//Calculates which direction gets player closest to the target point
	MoveDir bestMoveDir();

	static const char PLAYER_CHAR = 'X';
	static const char START_CHAR = 'A';
	static const char TARGET_CHAR = 'B';
	static const char WALL_CHAR = '#';
	static const char EMPTY_SPOT_CHAR = '.';

	Point _playerPosition;
	Point _targetPosition;

	char** _field;

	int _fieldWidth;
	int _fieldHeight;

};

#endif // !_GAME_H_