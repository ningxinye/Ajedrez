#pragma once
#include "Pieza.h"


class caballo
{
public:
    // Función para verificar los movimientos posibles de un caballo
    static bool SePuedeMover(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);

};
