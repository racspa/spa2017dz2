#include<iostream>
#include<windows.h>
#include "Board.h"

using namespace std;

board::board(int a, int b, int c, int d) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			array[i][j] = '-';
			if (i == a - 1 && j == b - 1) {
				array[i][j] = 'A';
			}
			if (i == c - 1 && j == d - 1) {
				array[i][j] = 'B';
			}
		}
	}
}

void board::create_board(int x, int y) {
	Sleep(100);
	system("cls");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			array[x][y] = 'x';
			cout << array[i][j];
			array[x][y] = '-';
		}
		cout << endl;
	}
}

void board::run_game(int a, int b, int c, int d) {
	int temp;
	bool stop = false;
	if (a < c && b < d) {
		for (int i = a - 1; i <= c - 1; i++) {
			if (stop) {
				create_board(i, temp);
				continue;
			}
			for (int j = b; j <= d - 1; j++) {
				temp = j;
				create_board(i, j);
			}
			if (temp == d - 1) {
				stop = true;
			}
		}
	}
	if (a < c && b > d) {
		for (int i = a - 1; i <= c - 1; i++) {
			if (stop) {
				create_board(i, temp);
				continue;
			}
			for (int j = b - 2; j >= d - 1; j--) {
				temp = j;
				create_board(i, j);
			}
			if (temp == d - 1) {
				stop = true;
			}
		}
	}
	if (a < c && b == d) {
		for (int i = a; i <= c - 1; i++) {
			create_board(i, b - 1);
		}
	}
	if (a > c && b < d) {
		for (int i = a - 1; i >= c - 1; i--) {
			if (stop) {
				create_board(i, temp);
				continue;
			}
			for (int j = b; j <= d - 1; j++) {
				temp = j;
				create_board(i, j);
			}
			if (temp == d - 1) {
				stop = true;
			}
		}
	}
	if (a > c && b > d) {
		for (int i = a - 1; i >= c - 1; i--) {
			if (stop) {
				create_board(i, temp);
				continue;
			}
			for (int j = b - 2; j >= d - 1; j--) {
				temp = j;
				create_board(i, j);
			}
			if (temp == d - 1) {
				stop = true;
			}
		}
	}
	if (a > c && b == d) {
		for (int i = a - 2; i >= c - 1; i--) {
			create_board(i, b - 1);
		}
	}
	if (a == c && b < d) {
		for (int i = b; i <= d - 1; i++) {
			create_board(a - 1, i);
		}
	}
	if (a == c && b > d) {
		for (int i = b - 2; i >= d - 1; i--) {
			create_board(a - 1, i);
		}
	}
	if (a == c && b == d) {
		cout << "Pokusaj ponovo!" << endl;
	}
}
