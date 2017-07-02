#include<iostream>
#include"ZmijaBezRepa.h"
#include<Windows.h>

using namespace std;



int main() {


	zmijaBezRepa zmija;
	while (true)
	{
		system("cls");
		zmija.iscrtaj();
		if (!zmija.sljedeci_korak())
		{
			break;
		}
		Sleep(100);
	}




	return 0;
}