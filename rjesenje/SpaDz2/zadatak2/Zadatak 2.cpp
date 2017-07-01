//
//  Zadatak2.cpp
//  Zadatak1
//
//  Created by Mark Tselikov on 23.06.17.
//  Copyright � 2017 Mark Tselikov. All rights reserved.
//

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

const int X_SIZE = 25;
const int Y_SIZE = 30;

// constants-indexes for directions
const int RIGHT = 1;
const int LEFT = 2;
const int UP = 3;
const int DOWN = 4;

// labels for the cells
const char EMPTY = ' ';
const char GOAL = 'X';
const char PLAYER = 'D';
const char BORDER = '#';

bool loseCond = false;
int goalX;
int goalY;
int currentX;
int currentY;
int direction = RIGHT;

char grid[X_SIZE][Y_SIZE];

void printBoard();
void move();
void getDirection();


int main() {

	// setting up the board
	for (int i = 0; i < X_SIZE; i++) {
		for (int j = 0; j < Y_SIZE; j++) {
			grid[i][j] = EMPTY;
		}
	}

    // setting up the borders
	for (int i = 0; i < X_SIZE; i++) grid[i][0] = BORDER;
	for (int i = 0; i < X_SIZE; i++) grid[i][Y_SIZE - 1] = BORDER;
	for (int i = 0; i < Y_SIZE; i++) grid[0][i] = BORDER;
	for (int i = 0; i < Y_SIZE; i++) grid[X_SIZE - 1][i] = BORDER;

	// setting up the positions of player and goal on the board
	currentY = rand() % Y_SIZE;
	currentX = rand() % X_SIZE;
	grid[currentX][currentY] = PLAYER;
	// making sure the goal doesn't appear on top of the players point
	do {
		goalX = rand() % X_SIZE;
		goalY = rand() % Y_SIZE;
	} while (currentX == goalX && currentY == goalY);
	grid[goalX][goalY] = GOAL;

	// the actual game starts here
	while (true) {

		getDirection();
		move();
		Sleep(100);
		printBoard();

		// if player crossed the borders, the game ends with a delay
		if (loseCond) {
			cout << "You lost :(" << endl;
			Sleep(3000);
			break;
		}

		// if the player reached the goal, a new goal point appears on the board
		if (currentX == goalX && currentY == goalY) {
			goalX = rand() % X_SIZE;
			goalY = rand() % Y_SIZE;
			grid[goalX][goalY] = GOAL;
		}
	}

	return 0;
}


// function that displays the board at its current state
void printBoard() {

	for (int i = 0; i < X_SIZE; i++) {
		for (int j = 0; j < Y_SIZE; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
}


// function that moves the player acros the board based on direction and checks if the player crossed the borders
void move() {

	if (direction == RIGHT) {
		if (grid[currentX][currentY + 1] == '#') loseCond = true;
		grid[currentX][currentY] = EMPTY;
		currentY += 1;
		grid[currentX][currentY] = PLAYER;
	}
	if (direction == LEFT) {
		if (grid[currentX][currentY - 1] == '#') loseCond = true;
		grid[currentX][currentY] = EMPTY;
		currentY -= 1;
		grid[currentX][currentY] = PLAYER;
	}
	if (direction == UP) {
		if (grid[currentX - 1][currentY] == '#') loseCond = true;
		grid[currentX][currentY] = EMPTY;
		currentX -= 1;
		grid[currentX][currentY] = PLAYER;
	}
	if (direction == DOWN) {
		if (grid[currentX + 1][currentY] == '#') loseCond = true;
		grid[currentX][currentY] = EMPTY;
		currentX += 1;
		grid[currentX][currentY] = PLAYER;
	}
}


// function that gets the direction of the player movement based on the key pressed
void getDirection() {
	
	if (_kbhit()) {
		char input = getch();
		if (input == 119) direction = UP;
		if (input == 115) direction = DOWN;
		if (input == 100) direction = RIGHT;
		if (input == 97) direction = LEFT;
	}
}
