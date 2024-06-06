#pragma once
#include "Pieza.h"


class alfil
{
public:
    // Función para verificar los movimientos posibles de un pe¨®n
    static bool SePuedeMover(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);

};
