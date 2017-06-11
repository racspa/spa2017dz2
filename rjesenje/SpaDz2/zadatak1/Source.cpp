#include "PronalazenjePuta.h"

int main()
{
	igraPronalazenjaPuta igra;
	while (igra.iduciKorak()) {
		igra.iscrtaj();
	}
	return 0;
}