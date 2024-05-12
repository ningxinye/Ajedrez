#include "Peon.h"
#include <math.h>

bool Peon::puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
	if (destino.c == origen.c)
	{
		if (casillas[origen.f][origen.c]->getColor() == Blanca) {
			if (((destino.f - origen.f) == 1)) {
				return true;
			}
			
			else { return false; }
		}
		else if (casillas[origen.f][origen.c]->getColor() == Negra)
		{
			if (((destino.f - origen.f) == -1)) {
				return true;
			}

			else { return false; }
		}
	}
	else { return false; }
}

bool Peon::puedecomer(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
	if (abs(destino.c - origen.c) == 1)
	{
		if (casillas[origen.f][origen.c]->getColor() == 0) {
			if ((destino.f - origen.f) == 1) { return true; }
			else { return false; }
		}
		else if (casillas[origen.f][origen.c]->getColor() == 1)
		{
			if ((origen.f - destino.f) == 1) { return true; }
			else { return false; }
		}
	}
	else { return false; }
}

