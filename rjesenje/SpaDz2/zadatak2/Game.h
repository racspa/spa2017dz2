#ifndef _GAME_H_
#define _GAME_H_

using namespace std;

class game {
private:
	char unos;
	static const int visina = 25;
	static const int sirina = 30;
	char _polje[visina][sirina];
	int xplayer;
	int yplayer;
	static const char znakp = 'X';
	int xvocka;
	int yvocka;
	static const char znakv = 'D';
public:
	game();
	char get_user_input();
	void d();
	void s();
	void a();
	void w();
	bool end();
	void newVocka();
	void play_game();
};

#endif

