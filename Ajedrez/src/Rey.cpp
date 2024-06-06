#include "Rey.h"
#include <iostream>
#include <cmath>

bool Rey::esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
    std::cout << "Comprobando movimiento del rey desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";

    int diferenciaDeFilas = destino.f - origen.f;
    int diferenciaDeColumnas = destino.c - origen.c;

	if (casillas[origen.f][origen.c]->getColor() == Blanca)
	{

		std::cout << "Intento de movimiento de una pieza blanca.\n";

		// Movimiento hacia adelante
		if (diferenciaDeFilas <= 1 && diferenciaDeColumnas <= 1)
		{
			std::cout << "Movimiento en la misma columna. Cambio de fila: " << diferenciaDeFilas << "\n";
			if (casillas[destino.f][destino.c]->getTipo() == No_pieza) {
				return true;
			}
			if (casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
				return true;
			}
		}
	}
	else if (casillas[origen.f][origen.c]->getColor() == Negra) 
	{
		std::cout << "Intento de movimiento de una pieza negra.\n";
		if (diferenciaDeFilas <= 1 && diferenciaDeColumnas <= 1) 
		{
			std::cout << "Movimiento en la misma columna. Cambio de fila: " << diferenciaDeFilas << "\n";
			if (casillas[destino.f][destino.c]->getTipo() == No_pieza) 
			{
				return true;
			}
			if (casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor())
			{
				return true;
			}
		}

		return false;


	}


}