#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

class Snake
{
private:
	int x = 15;
	int y = 12;
	const static int visina = 30;
	const static int sirina = 25;
	int dr = random_broj(visina - 1);//vocka Red
	int ds = random_broj(sirina - 1);;//vocka Stupac
	bool kraj = false;
	char temp;
	char znak;

public:
	//Snake();
	char get_user_input();
	int random_broj(int max);
	void iscrtaj();
	void smjer();
	void end_new();
	void nobutton();
	void go();
};

#endif
