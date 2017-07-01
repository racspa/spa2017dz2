#include "igra.h"

tocka igra::slucajna_vrijednost()
{
	D.x = rand() % STUPACA;
	D.y = rand() % REDAKA;
	if ( D.x == 0 || D.x == STUPACA - 1 || D.y == 0 || D.y == REDAKA-1) {
		return slucajna_vrijednost();
}
	else if (D.x == X.x && D.y == X.y) {
		return slucajna_vrijednost();
	}
	else { return D; }
}

igra::igra()

{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			if (i == 0 || i == REDAKA - 1 || j == 0 || j == STUPACA - 1) {
				this->grid[i][j] = '#';
			}
			else if (i == 12 && j == 15) {  this->X.x = j; this->X.y = i; this->grid[X.y][X.x] = 'X';
			}
			else { this->grid[i][j] = ' '; }
		}
	}
	srand(time(nullptr));
	this->D = slucajna_vrijednost();
	this->grid[D.y][D.x] = 'D';
}


void igra::ispis()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			cout << grid[i][j];
		}
		cout << endl;
	}
	
}

void igra::kretnja(char odabir)
{
	switch (odabir)
	{	
	case 'd':
		grid[X.y][X.x] = ' ';				//desno 
	X.x++;
	grid[X.y][X.x] = 'X';
			break;
	case 'a':
		grid[X.y][X.x] = ' ';				//lijevo
		X.x--;
		grid[X.y][X.x] = 'X';
		break;
	case 'w':
		grid[X.y][X.x] = ' ';				//gore 
		X.y--;
		grid[X.y][X.x] = 'X';
		break;
	case 's':
		grid[X.y][X.x] = ' ';				//dolje
		X.y++;
		grid[X.y][X.x] = 'X';
		break;
	}
	
}

void igra::povratak_iz_mrtvih()

{

	if (grid[D.y][D.x] == ' ') {
		D = slucajna_vrijednost();
		grid[D.y][D.x] = 'D';

	}
}

bool igra::provjera_granica()
{
	if (X.x == 0 || X.x == STUPACA - 1 || X.y == 0 || X.y == REDAKA - 1) {
		return false;
	}
	else { return true; }
}

char igra::get_user_input()
{
	
		if (_kbhit()) {
			return _getch();
		}
		else { return -1; }
	
}

