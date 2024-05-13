#include "Peon.h"
#include <math.h>
#include <iostream> 

bool Peon::puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
	std::cout << "Comprobando movimiento del pe¨®n: desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";
	if (destino.c == origen.c)
	{
		int diferenciaDeFilas = destino.f - origen.f;
		std::cout << "Movimiento en la misma columna. Cambio de fila: " << diferenciaDeFilas << "\n";

		if (casillas[origen.f][origen.c]->getColor() == Blanca) {
			std::cout << "Intento de movimiento de una pieza blanca.\n";
			if (((destino.f - origen.f) == 1)) {
				std::cout << "Tipo de pieza en destino: " << casillas[destino.f][destino.c]->getTipo() << ", Color: " << casillas[destino.f][destino.c]->getColor() << "\n";
				if (casillas[destino.f][destino.c]->getTipo() == No_pieza) {  
					return true;
				}
			}
		
		}
		else if (casillas[origen.f][origen.c]->getColor() == Negra)
		{
			if (((destino.f - origen.f) == -1)) {

				if (casillas[destino.f][destino.c]->getTipo() == No_pieza) {
					return true;
				}
				
			}

	
		}
	}
return false; 
}

bool Peon::puedecomer(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
	if (abs(destino.c - origen.c) == 1) 
	{
		if (casillas[origen.f][origen.c]->getColor() == Blanca) {
			if ((destino.f - origen.f) == 1) { return true; }
			else { return false; }
		}
		else if (casillas[origen.f][origen.c]->getColor() == Negra)
		{
			if ((destino.f - origen.f) == -1) { return true; }
			else { return false; }
		}
	}
	else { return false; }
}

