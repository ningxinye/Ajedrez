#include "caballo.h"
#include <iostream>
#include <cmath>

bool caballo::SePuedeMover(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
    std::cout << "Comprobando movimiento del caballo: desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";

    int diferenciaDeFilas = destino.f - origen.f;
    int diferenciaDeColumnas = destino.c - origen.c;
    int Fila, Columna;

    if (casillas[origen.f][origen.c]->getColor() == Blanca) {
        std::cout << "Intento de movimiento de una pieza blanca.\n";

        // Comprabacion
   
        if (abs(diferenciaDeColumnas) != 2 && abs(diferenciaDeColumnas) != 1)
        {
            std::cout << "Movimiento no es en L\n";
            return false;
        }
        else if (abs(diferenciaDeColumnas) ==2 ) {
            if (abs(diferenciaDeFilas) != 1) {
                std::cout << "Movimiento no es en L\n";
                return false;
            }
            
        }
        else if (abs(diferenciaDeColumnas) == 1) {
            if (abs(diferenciaDeFilas) != 2) {
                std::cout << "Movimiento no es en L\n";
                return false;
            }

        }
                 
       

        if (casillas[destino.f][destino.c]->getTipo() != No_pieza && casillas[destino.f][destino.c]->getColor() == casillas[origen.f][origen.c]->getColor()) {
            std::cout << "Hay una pieza del mismo color en el destino en (" << destino.f << ", " << destino.c << ")\n";
            return false;
        }
        else if (casillas[destino.f][destino.c]->getTipo() == No_pieza || casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
            return true;
        }
    }
    else if (casillas[origen.f][origen.c]->getColor() == Negra) {
        std::cout << "Intento de movimiento de una pieza negra.\n";

        // Comprabacion
        if (abs(diferenciaDeColumnas) != 2 && abs(diferenciaDeColumnas) != 1)
        {
            std::cout << "Movimiento no es en L\n";
            return false;
        }
        else if (abs(diferenciaDeColumnas) == 2) {
            if (abs(diferenciaDeFilas) != 1) {
                std::cout << "Movimiento no es en L\n";
                return false;
            }

        }
        else if (abs(diferenciaDeColumnas) == 1) {
            if (abs(diferenciaDeFilas) != 2) {
                std::cout << "Movimiento no es en L\n";
                return false;
            }

        }

        if (casillas[destino.f][destino.c]->getTipo() != No_pieza && casillas[destino.f][destino.c]->getColor() == casillas[origen.f][origen.c]->getColor()) {
            std::cout << "Hay una pieza del mismo color en el destino en (" << destino.f << ", " << destino.c << ")\n";
            return false;
        }
        else if (casillas[destino.f][destino.c]->getTipo() == No_pieza || casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
            return true;
        }
    }

    return false;


}
