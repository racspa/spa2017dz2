#include <iostream>
#include <chrono>
#include <thread>
#include "Point.h"
using namespace std;


void getPoint(Point &p,const char letter)
{
	cout << letter  << " redak: ";
	cin >> p.row;
	cout << letter << " stupac ";
	cin >> p.col;
}



void drawBoard(const Point &a,const Point &b,const Point &x)
{

	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 40; j++) {
			if (i == a.row && j == a.col) {
				cout << 'A';
			}
			else if(i == b.row && j == b.col)
			{
				cout << 'B';
			}
			else if(i == x.row && j == x.col)
			{
				cout << 'x';
			}
			else
			{
				cout << '-';
			}
		}
		cout << endl;
	}

}


void checkValues(const Point &b,Point &x) 
{
	
	if (x.col != b.col) {
		if (x.col < b.col) {
			x.col++;
		}
		else {
			x.col --;
		}
	}
	else
	{
		if (x.row < b.row) {
			x.row++;
		}
		else {
			x.row--;
		}


	}

	
}

int main()
{
	Point a, b, x;
	getPoint(a,'A');
	getPoint(b, 'B');
	x = a;

	while (true)
	{
		drawBoard(a, b, x);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		system("cls");
		checkValues(b, x);
		if (x.col == b.col && x.row == b.row) {
			exit(0);
		}
	}
	

	return 0;
}