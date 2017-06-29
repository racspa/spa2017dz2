#include<iostream>
#include<Windows.h>
#include<ctime>
#include"polje.h"
using namespace std;
int main() {
	srand(time(nullptr));
	char smjer = 'd',temp = 'd';
	Polje polje;
	while (polje.moveX(smjer)) {	//igraj dok mozes
		polje.updateScreen();		//iscrtaj plocu
		Sleep(100);					//cekaj 100ms
		temp = polje.get_input();	//provijeri sto je igrac stisnuo
		if (temp == 'w' || temp == 'a' || temp == 's' || temp == 'd' || temp == 'k') {
			smjer = temp;	//ako je igrac stisnuo tipku koje se koristi onda ju postavi kao smjer
		}
	}
	return 0;
}