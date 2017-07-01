#include"igra.h"

igra::igra(int igracX, int igracY, int metaX, int metaY)
{
	this->igracX = igracX;
	this->igracY = igracY;
	this->metaX = metaX;
	this->metaY = metaY;
}

bool igra::meta_pronadena()
{
	if (igracX == metaX && igracY == metaY) return true;

	return false;
}

void igra::sljedeci_korak()
{
	kretanje();
	iscrtaj();
	Sleep(100);
}

void igra::iscrtaj()
{
	system("cls");
	for (int i = 0; i < broj_redaka; i++) {
		for (int j = 0; j < broj_stupaca; j++) {
			if (i == 0 || i == broj_redaka - 1 || j == 0 || j == broj_stupaca - 1) {
				cout << '#';
			}
			else if (i == igracX && j == igracY) {
				cout << 'X';
			}
			else if (i == metaX && j == metaY) {
				cout << 'B';
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}
}

void igra::kretanje()
{
	if (igracX < metaX) igracX++;
	else if (igracX > metaX) igracX--;
	else {
		if (igracY < metaY) igracY++;
		else igracY--;
	}
}
