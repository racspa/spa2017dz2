#include <iostream>
#include "igra.h"
using namespace std;
int main() {
	char temp;
	igra a;
	a.odabir = 'd';
	
	do
	{
		
	
			system("cls");
			a.ispis();
			a.kretnja(b.odabir);
			Sleep(100);
			temp = a.get_user_input();
			if (temp == 'd' || temp == 'w' || temp == 'a' || temp == 's') {
				a.odabir = temp;
	}
			b.povratak_iz_mrtvih();
			
			
	} while (temp!='k' && a.provjera_granica());
	
	return 0;
}