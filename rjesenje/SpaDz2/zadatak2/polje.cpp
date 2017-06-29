#include "polje.h"
#include <conio.h>
#include<iostream>
using namespace std;

Polje::Polje(){
	int random;
	tocke[0] = 15;	//x kordinata igraca (tocka X)
	tocke[1] = 13;	//y kordinata igraca (tocka X)
	placeD();		//stavi vocku na plocu (tocka D)
}

void Polje::updateScreen(){
	system("CLS");
	for (int i = 0; i < 27; i++) {
		for (int j = 0; j < 33; j++) {
			if (i == 0 || j == 0 || j == 32 || i ==26) {
				cout << "#";	//ispisi rub ploce
			}
			else if(tocke[0]==j && tocke[1]==i){
				cout << "X";	//ispisi igraca
			}
			else if(tocke[2] == j && tocke[3] == i) {
				cout << "D";	//ispisi vocku
			}
			else {
				cout << " ";	//ispisi sve ostalo
			}
		}
		cout << endl;
	}
}

bool Polje::moveX(char smjer){
	if (smjer == 'w') {
		tocke[1]--;	//idi napred
	}
	if (smjer == 'a') {
		tocke[0]--;	//idi lijevo
	}
	if (smjer == 's') {
		tocke[1]++;	//idi nazad
	}
	if (smjer == 'd') {
		tocke[0]++;	//idi desno
	}
	if (tocke[0] == tocke[2] && tocke[1] == tocke[3]) {
		placeD();	//ako je igrac na istom mjestu kao i vocka pomakni ju na drugo mjesto
	}
	if (tocke[0] > 30 || tocke[1] > 25 || tocke[0] < 1 || tocke[1] < 1 || smjer == 'k') {
		return false;	//ako je igrac dotaknuo rub ili pritisnuo k zavrsi igru
	}
	return true;
}

char Polje::get_input(){
	if (_kbhit()) {
		return _getch();
	}
	return 0;
}

void Polje::placeD(){
	do { //vrti dok je vocka na na istom mjestu kao i igrac
	tocke[2] = rand() % 30 + 1;	//random postavi x kordinatu
	tocke[3] = rand() % 25 + 1;	//random postavi y kordinatu
	} while (tocke[0] == tocke[2] && tocke[1] == tocke[3]);
}
