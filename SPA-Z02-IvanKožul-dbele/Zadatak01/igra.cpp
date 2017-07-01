#include "igra.h"

igra::igra()
{
	cout << "Unesi redak tocke A";
	cin >> this->To1.x;
	cout << "Unesi stupac tocke A";
	cin >> this->To1.y;
	system("cls");

	cout << "Unesi redak tocke B";
	cin >> this->To2.x;
	cout << "Unesi stupac tocke B";
	cin >> this->To2.y;
	system("cls");

	this->grid[To1.x-1][To1.y-1] = 'A';
	this->grid[To2.x - 1][To2.y - 1] = 'B';

	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if ((i != To1.x-1 || j != To1.y-1) && (i != To2.x - 1 || j != To2.y - 1)) {
				this->grid[i][j] = '-';
			}
		}
		
	}
}

void igra::ispis()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			cout <<grid[i][j] ;
		}
		cout << endl;
	}
}

bool igra::kretnja_x()
{

	
		if (To1.x < To2.x ) {	//dolje
			grid[To1.x - 1][To1.y - 1] = '-';
			grid[To1.x][To1.y - 1] = 'A';
			To1.x++;
			return true;
		}
		else if (To1.x > To2.x) {	//gore
			grid[To1.x - 1][To1.y - 1] = '-';
			grid[To1.x - 2][To1.y - 1] = 'A';
			To1.x--;
			return true;
		}
		else return false;
		
	}

bool igra::kretnja_y()
{
	if (To1.y < To2.y) {	//desno
		grid[To1.x - 1][To1.y - 1] = '-';
		grid[To1.x-1][To1.y] = 'A';
		To1.y++;
		return true;
	}
	else if (To1.y > To2.y) {	//levo
		grid[To1.x - 1][To1.y - 1] = '-';
		grid[To1.x - 1][To1.y - 2] = 'A';
		To1.y--;
		return true;
	}
	else return false;
}
