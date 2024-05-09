#pragma once

#include "Pieza.h"


class Peon
{
public:
 

    // Funci¨®n para verificar los movimientos posibles de un pe¨®n
    static bool Mov(Casilla cd, Casilla co, Pieza** tab);

    // Funci¨®n para comer el piezas
    static bool Comer(Casilla cd, Casilla co, Pieza** tab);
 
};

