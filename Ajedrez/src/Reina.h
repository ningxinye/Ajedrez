#pragma once
#include "Pieza.h"


class Reina
{
public:

    // Funcion para verificar los movimientos posibles de la reina
    static bool esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);
};
