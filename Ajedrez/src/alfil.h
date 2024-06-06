#pragma once
#include "Pieza.h"


class alfil
{
public:
    // Funci¨®n para verificar los movimientos posibles de un alfil
    static bool SePuedeMover(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);

};