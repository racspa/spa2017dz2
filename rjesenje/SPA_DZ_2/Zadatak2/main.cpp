#include<Windows.h>
#include<conio.h>
#include"Game.h"

char getUserInput() {

	if (_kbhit()) {
		return _getch();
	}

	return 0;
}

int main() {

	Game game;

	bool isDone = false;

	while (!isDone) {

		isDone = game.update(getUserInput());

		Sleep(100);
	}

	return 0;
}