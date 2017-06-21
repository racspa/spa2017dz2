#include "Game.h"

Game::Game(Point& player, Point& target, const int fieldWidth, const int fieldHeight)
{

	//+2 -> for the walls
	_fieldWidth = fieldWidth + 2;
	_fieldHeight = fieldHeight + 2;

	_field = new char*[_fieldHeight];

	for(int i = 0; i < _fieldHeight; i++)
	{
		
		_field[i] = new char[_fieldWidth];

	}

	//Init field
	for (int i = 0; i < _fieldHeight; i++) {
		for (int j = 0; j < _fieldWidth; j++) {

			if (i == player.y && j == player.x) {
				_field[i][j] = START_CHAR;
			}

			else if (i == target.y && j == target.x) {
				_field[i][j] = TARGET_CHAR;
			}

			else if (i == 0 || i == _fieldHeight - 1 || j == 0 || j == _fieldWidth - 1) {
				_field[i][j] = WALL_CHAR;
			}

			else {
				_field[i][j] = EMPTY_SPOT_CHAR;
			}

		}
	}

	_playerPosition = player;
	_targetPosition = target;

}

bool Game::movePlayer()
{

	//Current player position -> set it to empty
	if(_field[_playerPosition.y][_playerPosition.x] != START_CHAR)
		_field[_playerPosition.y][_playerPosition.x] = EMPTY_SPOT_CHAR;

	switch (bestMoveDir()) {

	case MoveDir::DOWN:

		_playerPosition.y++;

		break;
	case MoveDir::UP:

		_playerPosition.y--;

		break;
	case MoveDir::LEFT:

		_playerPosition.x--;

		break;
	case MoveDir::RIGHT:

		_playerPosition.x++;

		break;

	}

	//Updated player position -> set it to player
	_field[_playerPosition.y][_playerPosition.x] = PLAYER_CHAR;

	if (_playerPosition.x == _targetPosition.x && _playerPosition.y == _targetPosition.y) {
		return true; //target found!
	}

	return false;

}

void Game::printField()
{
	system("cls");
	for (int i = 0; i < _fieldHeight; i++) {
		for (int j = 0; j < _fieldWidth; j++) {

			cout << _field[i][j];

		}
		cout << endl;
	}
}

Game::~Game()
{

	for (int i = 0; i < _fieldHeight; i++)
	{

		delete[] _field[i];

	}

	delete[] _field;

}

bool Game::fieldAllowed(Point& pointToCheck) {
	if (
		pointToCheck.x > 0 && pointToCheck.x < _fieldWidth - 1 &&
		pointToCheck.y > 0 && pointToCheck.y < _fieldHeight - 1) {

		if (_field[pointToCheck.y][pointToCheck.x] == EMPTY_SPOT_CHAR ||
			_field[pointToCheck.y][pointToCheck.x] == TARGET_CHAR) {
			return true;
		}

	}

	return false;
}

double Game::distance(Point& point1, Point& point2)
{
	return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
}

void Game::calcDistanceToTarget(Point& point, double& currentDistance) {
	if (fieldAllowed(point)) currentDistance = distance(point, _targetPosition);

	else currentDistance = DBL_MAX; //numeric_limits<double>::max() [#include<limits>]
}

MoveDir Game::bestMoveDir()
{
	double distances[4];

	calcDistanceToTarget(Point(_playerPosition.x - 1, _playerPosition.y), distances[0]); //left
	calcDistanceToTarget(Point(_playerPosition.x + 1, _playerPosition.y), distances[1]); //right
	calcDistanceToTarget(Point(_playerPosition.x, _playerPosition.y + 1), distances[2]); //down
	calcDistanceToTarget(Point(_playerPosition.x, _playerPosition.y - 1), distances[3]); //up

	double minDistance = distances[0];

	//find which direction has the smallest distance to target
	for (int i = 1; i < 4; i++)
		if (distances[i] < minDistance) minDistance = distances[i];

	if (minDistance == distances[0]) return MoveDir::LEFT;
	if (minDistance == distances[1]) return MoveDir::RIGHT;
	if (minDistance == distances[2]) return MoveDir::DOWN;
	return MoveDir::UP;
}