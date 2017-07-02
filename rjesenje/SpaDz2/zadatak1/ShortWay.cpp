#include<iostream>
#include"Board.h"

using namespace std;

int main() {

	cout << "--------------------------------------------------------" << endl;
	cout << "Game SHORTWaY" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Unesite kordinate pocetne toèke A (redak i stupac) i " << endl;
	cout << "odredisne tocke B (redak i stupac)" << endl;
	cout << "Broj retka od 1 do 20, broj stupca od 1 do 40" << endl;
	cout << "Program ce izracunati najkraci put od tocke A do tocke B" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;

	int a, b, c, d;
	char next;

	do {

		do {
			cout << "Unesi A redak: ";
			cin >> a;
			if (a < 0 || a > 20) {
				cout << "Pogresan broj!" << endl;
			}
		
			cout << "Unesi A stupac: ";
			cin >> b;
			if (b < 0 || b > 40) {
				cout << "Pogresan broj!" << endl;
			}
			cout << "Unesi B redak: ";
			cin >> c;
			if (c < 0 || c > 20) {
				cout << "Pogresan broj!" << endl;
			}

			cout << "Unesi B stupac: ";
			cin >> d;
			if (d < 0 || d > 40) {
				cout << "Pogresan broj!" << endl;
			}

		} while (!(a > 0 && a < 21 && b > 0 && b < 41 && c > 0 && c < 21 && d > 0 && d < 41));

		board input(a, b, c, d);
		input.run_game(a, b, c, d);

		cout << "Zelite li novu igru? (d/n) > ";
		cin >> next;

		system("CLS");

	} while (next == 'd');


	return 0;
}