#include <iostream>
#include <string>
#include "Igra1.h"
void main() {

	
	cout << "A redak: ";
	int ax;
	cin >> ax;

	cout << "A stupac: ";
	int ay;
	cin >> ay;

	cout << "B redak: ";
	int bx;
	cin >> bx;

	cout << "B stupac: ";
	int by;
	cin >> by;

	Igra1 i(ax, ay, bx, by);
	i.put();


}