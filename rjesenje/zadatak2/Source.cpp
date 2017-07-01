#include"igrica.h"

void main() {
	igrica igra;
	while (!igra.gotovo())igra.sljedeci_korak();
}