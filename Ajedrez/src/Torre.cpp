#include"Torre.h"
#include <math.h>
#include <iostream> 

bool Torre::esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
	std::cout << "Comprobando movimiento de la torre: desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";

	int diferenciaDeFilas = destino.f - origen.f;
	int diferenciaDeColumnas = destino.c - origen.c;
	int Fila, Columna;

	if (casillas[origen.f][origen.c]->getColor() == Blanca) {
		std::cout << "Intento de movimiento de una pieza blanca.\n";

		// Se comprueba si la líena es recta o no
		if (diferenciaDeFilas != 0 && diferenciaDeColumnas != 0) {
			std::cout << "No es un movimiento rectilínea\n";
			return false;
		}
		//Moviemiento de la torre

		if (diferenciaDeFilas != 0) {
			Fila = diferenciaDeFilas / abs(diferenciaDeFilas);
		}
		else {
			Fila = 0;
		}


		if (diferenciaDeColumnas != 0) {
			Columna = diferenciaDeColumnas / abs(diferenciaDeColumnas);
		}
		else {
			Columna = 0;
		}
		// Verificar si hay piezas en el camino
		int f = origen.f + Fila;
		int c = origen.c + Columna;
		while (f != destino.f || c != destino.c) {
			if (casillas[f][c]->getTipo() != No_pieza) {
				std::cout << "Hay una pieza en el camino en (" << f << ", " << c << ")\n";
				return false;
			}
			f += Fila;
			c += Columna;
		}


		if (casillas[destino.f][destino.c]->getTipo() == No_pieza || casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
			return true;
		}
	}
	else if (casillas[origen.f][origen.c]->getColor() == Negra) {
		std::cout << "Intento de movimiento de una pieza negra.\n";

		// Se comprueba si la líena es recta o no
		if (diferenciaDeFilas != 0 && diferenciaDeColumnas != 0) {
			std::cout << "No es un movimiento rectilínea\n";
			return false;
		}
		if (diferenciaDeFilas != 0) {
			Fila = diferenciaDeFilas / abs(diferenciaDeFilas);
		}
		else {
			Fila = 0;
		}


		if (diferenciaDeColumnas != 0) {
			Columna = diferenciaDeColumnas / abs(diferenciaDeColumnas);
		}
		else {
			Columna = 0;
		}

		// Verificar si hay piezas en el camino
		int f = origen.f + Fila;
		int c = origen.c + Columna;
		while (f != destino.f || c != destino.c) {
			if (casillas[f][c]->getTipo() != No_pieza) {
				std::cout << "Hay una pieza en el camino en (" << f << ", " << c << ")\n";
				return false;
			}
			f += Fila;
			c += Columna;
		}


		if (casillas[destino.f][destino.c]->getTipo() == No_pieza || casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
			return true;
		}
	}

	return false; 

}