#include "Game.h"
#include<random>

Game::Game()
{
	
	initField();

}

bool Game::update(char input)
{

	bool isDone = false;

	if (handleInput(input)) isDone = true;

	if (movePlayer()) isDone = true;

	printBoard();

	return isDone;

}

void Game::initField()
{

	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {

			if (i == 0 || i == FIELD_HEIGHT - 1 || j == 0 || j == FIELD_WIDTH - 1) {
				_field[i][j] = WALL_CHAR;
			}

			else {
				_field[i][j] = EMPTY_SPOT_CHAR;
			}

		}
	}

	_snake.clear();
	_snake.push_back(Point(FIELD_WIDTH / 2, FIELD_HEIGHT / 2));

	_field[_snake.back().y][_snake.back().x] = PLAYER_CHAR;

	summonFruit();

}

bool Game::handleInput(char input)
{

	switch (input) {

	case 'a':
	case 'A':

		if(_snake.size() == 1 || (_snake.size() > 1 && _moveDir != MoveDir::RIGHT))
			_moveDir = MoveDir::LEFT;

		break;

	case 's':
	case 'S':

		if (_snake.size() == 1 || (_snake.size() > 1 && _moveDir != MoveDir::UP))
			_moveDir = MoveDir::DOWN;

		break;

	case 'd':
	case 'D':

		if (_snake.size() == 1 || (_snake.size() > 1 && _moveDir != MoveDir::LEFT))
			_moveDir = MoveDir::RIGHT;

		break;

	case 'w':
	case 'W':

		if (_snake.size() == 1 || (_snake.size() > 1 && _moveDir != MoveDir::DOWN))
			_moveDir = MoveDir::UP;

		break;

	case 'k':
	case 'K':

		return true;

	}

	return false;

}

bool Game::movePlayer()
{

	updatePlayerPosition();

	if (fieldAllowed(_snake.front())) {

		switch (fieldHit(_snake.front())) {

		case FRUIT_CHAR:

			_field[_snake.front().y][_snake.front().x] = PLAYER_CHAR;

			extendTail();

			summonFruit();

			break;

		case EMPTY_SPOT_CHAR:

			_field[_snake.front().y][_snake.front().x] = PLAYER_CHAR;

			break;

		case WALL_CHAR:
		case PLAYER_CHAR:

			return true;

		}

	}

	//Error?
	else initField();

	return false;

}

void Game::updatePlayerPosition()
{

	_field[_snake.back().y][_snake.back().x] = EMPTY_SPOT_CHAR;

	if (_snake.size() > 2) {
		for (int i = _snake.size() - 1; i >= 1; i--) {

			_snake[i] = _snake[i - 1];

		}
	}
	else if (_snake.size() == 2) {

		_snake[1] = _snake[0];

	}

	switch (_moveDir) {

	case MoveDir::DOWN:

		_snake.front().y++;

		break;
	case MoveDir::UP:

		_snake.front().y--;

		break;
	case MoveDir::LEFT:

		_snake.front().x--;

		break;
	case MoveDir::RIGHT:

		_snake.front().x++;

		break;

	}

	for (int i = 1; i < _snake.size(); i++) {

		_field[_snake[i].y][_snake[i].x] = PLAYER_CHAR;

	}

}

bool Game::tailHit(Point& pointToCheck)
{
	if (fieldHit(pointToCheck) == PLAYER_CHAR) {
		if (pointToCheck.x == _snake[_snake.size() - 2].x &&
			pointToCheck.y == _snake[_snake.size() - 2].y)

			return true;

	}

	return false;
}

void Game::extendTail()
{

	if (_snake.size() > 1) {

		Point right = Point(_snake.back().x + 1, _snake.back().y);
		Point left = Point(_snake.back().x - 1, _snake.back().y);
		Point up = Point(_snake.back().x, _snake.back().y - 1);
		Point down = Point(_snake.back().x, _snake.back().y + 1);

		if (tailHit(left)) _snake.push_back(right);
		if (tailHit(right)) _snake.push_back(left);
		if (tailHit(up)) _snake.push_back(down);
		if (tailHit(down)) _snake.push_back(up);

	}

	else {

		switch (_moveDir) {

		case MoveDir::DOWN:

			_snake.push_back(Point(_snake.back().x, _snake.back().y - 1));

			break;
		case MoveDir::UP:

			_snake.push_back(Point(_snake.back().x, _snake.back().y + 1));

			break;
		case MoveDir::LEFT:

			_snake.push_back(Point(_snake.back().x + 1, _snake.back().y));

			break;
		case MoveDir::RIGHT:

			_snake.push_back(Point(_snake.back().x - 1, _snake.back().y));

			break;

		}

	}

}

void Game::summonFruit()
{

	int fruitX, fruitY;

	do {
		fruitX = getRandomInt(1, FIELD_WIDTH - 2);
		fruitY = getRandomInt(1, FIELD_HEIGHT - 2);
	} while (fieldHit(Point(fruitX, fruitY)) != EMPTY_SPOT_CHAR);

	_field[fruitY][fruitX] = FRUIT_CHAR;

}

bool Game::fieldAllowed(Point& pointToCheck) {
	if (
		pointToCheck.x >= 0 && pointToCheck.x < FIELD_WIDTH &&
		pointToCheck.y >= 0 && pointToCheck.y < FIELD_HEIGHT) {

			return true;

	}

	return false;
}

char Game::fieldHit(Point & pointToCheck)
{
	return _field[pointToCheck.y][pointToCheck.x];
}

void Game::printBoard()
{
	system("cls");

	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {

			cout << _field[i][j];

		}
		cout << endl;
	}

	//cout << "Apples eaten: " << _snake.size() - 1;

}

int Game::getRandomInt(double from, double to)
{
	if (to < from) {
		double temp = from;
		from = to;
		to = temp;
	}

	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(from, to);

	return round(dist(mt));
}
