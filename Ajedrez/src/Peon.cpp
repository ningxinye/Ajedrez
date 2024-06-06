#include "Peon.h"
#include <math.h>
#include <iostream> 



bool Peon::esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
	std::cout << "Comprobando movimiento del peon: desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";

	int diferenciaDeFilas = destino.f - origen.f;
	int diferenciaDeColumnas = destino.c - origen.c;

	if (casillas[origen.f][origen.c]->getColor() == Blanca) {
		std::cout << "Intento de movimiento de una pieza blanca.\n";

		// Movimiento hacia adelante
		if (diferenciaDeColumnas == 0 && diferenciaDeFilas == 1) {
			std::cout << "Movimiento en la misma columna. Cambio de fila: " << diferenciaDeFilas << "\n";
			if (casillas[destino.f][destino.c]->getTipo() == No_pieza) {
				return true;
			}
		}

		// Movimiento para comer
		if (abs(diferenciaDeColumnas) == 1 && diferenciaDeFilas == 1) {
			if (casillas[destino.f][destino.c]->getColor() == Negra) {
				return true;
			}
		}
	}
	else if (casillas[origen.f][origen.c]->getColor() == Negra) {
		std::cout << "Intento de movimiento de una pieza negra.\n";

		// Movimiento hacia adelante
		if (diferenciaDeColumnas == 0 && diferenciaDeFilas == -1) {
			std::cout << "Movimiento en la misma columna. Cambio de fila: " << diferenciaDeFilas << "\n";
			if (casillas[destino.f][destino.c]->getTipo() == No_pieza) {
				return true;
			}
		}

		// Movimiento para comer
		if (abs(diferenciaDeColumnas) == 1 && diferenciaDeFilas == -1) {
			if (casillas[destino.f][destino.c]->getColor() == Blanca) {
				return true;
			}
		}
	}

	return false;
}
