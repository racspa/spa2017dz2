#ifndef _IGRA_H_
#define _IGRA_H_

#include<iostream>
#include<Windows.h>
using namespace std;

class igra
{
public:
	igra(int igracX, int igracY, int metaX, int metaY);
	bool meta_pronadena();
	void sljedeci_korak();

private:

	void iscrtaj();
	void kretanje();

	int igracX, igracY;
	int metaX, metaY;

	const int broj_redaka = 22;
	const int broj_stupaca = 42;
};

#endif // !_IGRA_H_

