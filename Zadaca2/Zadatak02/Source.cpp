#include "Igra_zmijica.h"

int main() {

	Igra_zmijica igra;
	igra.odabir = 'd';

	do
	{
		igra.iscrtaj();
		igra.NoviGrid(igra.odabir);

		char unos = igra.get_user_input();
		if (unos == 'd' || unos == 'a' || unos == 'w' || unos == 's')
		{
			igra.odabir = unos;
		}

	} while (!igra.dead());

	return 0;
}