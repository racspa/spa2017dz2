#include"Game.h"
#include<string>
#include<Windows.h>

Point getUserInput(string pointName, int minX, int maxX, int minY, int maxY) {

	Point point;

	do {
		system("cls");
		cout << pointName + " redak(" << minY << " - " << maxY << "): ";
		cin >> point.y;
	} while (point.y > maxY || point.y < minY);

	do {
		system("cls");
		cout << pointName + " stupac(" << minX << " - " << maxX << "): ";
		cin >> point.x;
	} while (point.x > maxX || point.x < minX);

	return point;

}

int main() {

	const int NUM_ROWS = 20; //y
	const int NUM_COLUMNS = 40; //x

	Point player = getUserInput("A", 1, NUM_COLUMNS, 1, NUM_ROWS);
	Point target = getUserInput("B", 1, NUM_COLUMNS, 1, NUM_ROWS);

	Game game(player, target, NUM_COLUMNS, NUM_ROWS);
	bool isDone = false;

	//Print the field before the game starts
	game.printField();
	Sleep(100);

	while (!isDone) {

		isDone = game.movePlayer();
		game.printField();

		Sleep(100);

	}

	return 0;
}