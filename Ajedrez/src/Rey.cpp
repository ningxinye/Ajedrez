#include "Rey.h"
#include <iostream>
#include <cmath>

bool Rey::esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]) {
    std::cout << "Comprobando movimiento del rey: desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";

    int diferenciaDeFilas = abs(destino.f - origen.f);
    int diferenciaDeColumnas = abs(destino.c - origen.c);
    //Movimiento del rey

    if (diferenciaDeFilas <= 1 && diferenciaDeColumnas <= 1) {
       
        if (casillas[destino.f][destino.c]->getTipo() == No_pieza || casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
            return true;
        }
    }

    return false;
}
