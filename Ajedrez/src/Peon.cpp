#include "Peon.h"
#include <math.h>

bool Peon::puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
    int direction = (getColor() == Blanca) ? 1 : -1;

    // Verifica si el movimiento es hacia adelante
    if (destino.c == origen.c) {
        // Permite mover un paso hacia adelante si la casilla est¨¢ vac¨ªa
        if (destino.f == origen.f + direction && casillas[destino.f][destino.c] == nullptr) {
            return true;
        }
        // Permite mover dos pasos hacia adelante desde la posici¨®n inicial
        if (!getMovida() && destino.f == origen.f + (2 * direction) && casillas[destino.f][destino.c] == nullptr &&
            casillas[origen.f + direction][origen.c] == nullptr) {
            return true;
        }
    }

    // Verifica movimiento diagonal para comer piezas
    if (abs(destino.c - origen.c) == 1 && destino.f == origen.f + direction) {
        Pieza* destinoPieza = casillas[destino.f][destino.c];
        // Permite comer si la casilla de destino contiene una pieza del color opuesto
        return destinoPieza != nullptr && destinoPieza->getColor() != getColor();
    }

    return false; // Movimiento no v¨¢lido
}
