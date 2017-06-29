#include "polje.h"

Polje::Polje(int ax, int ay, int bx, int by){
	tocke[0] = ax - 1;	//postavi x kordinate A tocke
	tocke[1] = ay - 1;	//postavi y kordinate A tocke
	tocke[2] = bx - 1;	//postavi x kordinate B tocke
	tocke[3] = by - 1;	//postavi y kordinate B tocke
	tocke[4] = ax - 1;	//postavi x kordinate X tocke
	tocke[5] = ay - 1;	//postavi y kordinate X tocke
}

void Polje::updateScreen(){
	system("CLS");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 40; j++) {
			if (i == tocke[0] && j == tocke[1]) {
				cout << "A";	//ispisi A tocku
			}
			else if (i == tocke[2] && j == tocke[3]) {
				cout << "B";	//ispisi B tocku
			}
			else if (i == tocke[4] && j == tocke[5]) {
				cout << "X";	//ispisi X tocku
			}
			else {
				cout << "-";	//ispisi polje
			}
		}
		cout << endl;
	}
}

bool Polje::moveX(){
	if (tocke[5] < tocke[3]) {
		tocke[5]++;	//pomakni X prema gore
		return true;
	}
	if (tocke[5] > tocke[3]) {
		tocke[5]--;	//pomakni X prema dolje
		return true;
	}
	if (tocke[4] < tocke[2]) {
		tocke[4]++;	//pomakni X u desno
		return true;
	}
	if (tocke[4] > tocke[2]) {
		tocke[4]--;	//pomakni X u lijevo
		return true;
	}
	return false;
}
