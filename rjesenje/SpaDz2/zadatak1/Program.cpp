#include<iostream>
#include<Windows.h>
#include"PathGame.h"

using namespace std;


int main() {
	
	PathGame game;
	
	while (true)
	{
		system("cls");
		game.iscrtaj();
		if (!game.sljedeci_korak()) break;
		Sleep(100);		//delay od 100ms
	}
	
	return 0;
}