#pragma once
#include "Pieza.h"


class Peon
{
public:
    // Funcion para verificar los movimientos posibles de un peon
    static bool esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);
};

