#include "IgraTocke.h"

int main(){

	Tocka A, B;

	//tocka A
	cout << "A redak: ";
	cin >> A.x;
	cout << "A stupac: ";
	cin >> A.y;

	//tocka B
	cout << "B redak: ";
	cin >> B.x;
	cout << "B stupac: ";
	cin >> B.y;

	IgraTocke game(A, B);
	
	while (game.Alive())
	{
		game.Iscrtaj();
		game.SljedeciGrid();
	}

	return 0;
}