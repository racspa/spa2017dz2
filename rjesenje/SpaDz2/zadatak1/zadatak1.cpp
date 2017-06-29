#include<iostream>
#include<Windows.h>
#include"polje.h"
using namespace std;
int main() {
	int ax, ay, bx, by;
	cout << "A Redak:";
	cin >> ay;
	cout << "A Stupac:";
	cin >> ax;
	cout << "B Redak:";
	cin >> by;
	cout << "B Stupac:";
	cin >> bx;
	Polje polje(ax, ay, bx, by);
	while (polje.moveX()) {		//igraj dok mozes
		polje.updateScreen();	//iscrtaj plocu
		Sleep(100);				//cekaj 100ms
	}
	return 0;
}