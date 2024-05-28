#pragma once
#include "Pieza.h"


class Peon
{
public:
    
// Función para verificar los movimientos posibles de un pe¨®n
    static bool esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);
};

