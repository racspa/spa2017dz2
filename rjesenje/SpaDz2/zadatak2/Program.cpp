#include<iostream>
#include<Windows.h>
#include"FruitGame.h"

using namespace std;

int main() {

	FruitGame game;
	while (true)
	{
		system("cls");
		game.iscrtaj();
		if (!game.sljedeci_korak()) break;
		Sleep(100); //PROMJENOM VRIJEDNOSTI U FUNKCIJI SE MIJENJA BRZINA IGRE(LEVEL)
	}

	cout << "GAME OVER!!!!!!!!"<<endl;

	return 0;
}