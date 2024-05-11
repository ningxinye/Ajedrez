#include "Peon.h"
#include <math.h>

bool Peon::puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
    int direccion = (getColor() == Blanca) ? 1 : -1;
    if (destino.c == origen.c && destino.f == origen.f + direccion) {
        if (casillas[destino.f][destino.c] == nullptr) {
            return true;
        }
    }

    if (abs(destino.c - origen.c) == 1 && destino.f == origen.f + direccion) {
        Pieza* piezaDestino = casillas[destino.f][destino.c];
        if (piezaDestino != nullptr && piezaDestino->getColor() != getColor()) {
            return true;
        }
    }

    return false;
}

