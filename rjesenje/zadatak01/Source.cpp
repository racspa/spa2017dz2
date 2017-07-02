#include<iostream>
#include"PronadiPut.h"
#include<Windows.h>
using namespace std;


int main() {


	
	PronadiPut put;

	put.iscrtaj();


	while (true)
	{
		system("cls");
		put.iscrtaj();
		if (!put.sljedeci_korak())
		{
			break;
		}
		Sleep(100);
	}










	return 0;
}