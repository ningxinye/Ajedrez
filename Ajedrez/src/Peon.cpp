#include "Peon.h"
#include <math.h>

bool Peon::puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
    //El color del pe¨®n determina la direcci¨®n del progreso.
    int direction = (getColor() == Blanca) ? 1 : -1;

    // Verifica si el movimiento es hacia adelante
    if (destino.c == origen.c && destino.f == origen.f + direction) {
        // posicion objetiva debe ser vacia
        if (casillas[destino.f][destino.c] == nullptr) {
            return true;
        }
    }


    // Verifica movimiento diagonal para comer piezas
    if (abs(destino.c - origen.c) == 1 && destino.f == origen.f + direction) {
        Pieza* destinoPieza = casillas[destino.f][destino.c];
        // Comprobar si hay una pieza del oponente en la posici¨®n objetivo
        if (destinoPieza != nullptr && destinoPieza->getColor() != casillas[origen.f][origen.c]->getColor()) {
            return true;
        }
    }
    return false; // Movimiento no v¨¢lido
}
