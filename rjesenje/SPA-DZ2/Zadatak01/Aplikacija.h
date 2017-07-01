#ifndef APLIKACIJA_H
#define APLIKACIJA_H

#include <iostream>

using namespace std;

class app
{
public:
	app();
	void map_init();
	void user_input();
	void tocke_init();
	void move();
	void player_init();
	void delete_player();
	int a_redak, a_stupac, b_redak, b_stupac;
	int igrac_redak;
	int igrac_stupac;

private:
	static const unsigned int REDAKA = 20;
	static const unsigned int STUPACA = 40;
	char igraca_ploca[REDAKA][STUPACA];

};
#endif // !APLIKACIJA_H
