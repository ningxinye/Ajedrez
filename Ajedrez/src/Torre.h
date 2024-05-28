#pragma once
#include "Pieza.h"
class Torre
{
public:

    // Función para verificar los movimientos posibles de una torre
    static bool esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);
};

