#include "Peon.h"
#include <math.h>

bool Peon::Mov(Casilla cd, Casilla co, Pieza** tab)
{
	//verificar la posicion de la piaza de ahora y posicion objetiva tiene la misma columna
    if (cd.c == co.c) {

		if (tab[co.f][co.c].getColor() == Blanca) {
			if (((cd.f - co.f) == 1)) {
				return true;
			}
		
			else { return false; }
		}
		else if (tab[co.f][co.c].getColor() == Negra)
		{
			if (((cd.f - co.f) == -1)) {
				return true;
			}
			
			else { return false; }
		}
	}
	else { return false; }
	
}

bool Peon::Comer(Casilla cd, Casilla co, Pieza** tab)
{
    return false;
}
