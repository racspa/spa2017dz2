#include <iostream>
#include <Windows.h>
#include "Aplikacija.h"

using namespace std;

int main() {

	app app;

	app.user_input();
	app.tocke_init();

	while (true)
	{
		app.map_init();
		app.move();

		Sleep(100);
	}

	return 0;
}