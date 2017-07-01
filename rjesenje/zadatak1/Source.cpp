#include"igra.h"

void main() {

	int igracX, igracY, metaX, metaY;

	cout << "A redak: ";
	cin >> igracX;
	cout << "A stupac: ";
	cin >> igracY;
	cout << "B redak: ";
	cin >> metaX;
	cout << "B stupac: ";
	cin >> metaY;

	igra igra(igracX, igracY, metaX, metaY);

	while (!igra.meta_pronadena()) igra.sljedeci_korak();

}