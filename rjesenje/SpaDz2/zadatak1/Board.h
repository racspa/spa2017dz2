#ifndef _BOARD_H_
#define _BOARD_H_

using namespace std;

class board {
private:
	char array[20][40];
public:
	board(int a, int b, int c, int d);
	void create_board(int x, int y);
	void run_game(int a, int b, int c, int d);
};


#endif
