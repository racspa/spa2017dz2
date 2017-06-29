#ifndef POLJE_H
#define POLJE_H
class Polje {
private:
	int tocke[4];
public:
	Polje();
	void updateScreen();
	bool moveX(char smjer);
	char get_input();
	void placeD();
};

#endif