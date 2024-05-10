#pragma once
#include "Pieza.h"


class Peon : public Pieza //La clase Pe¨®n hereda de la clase Pieza.
{
public:

    // Funci¨®n para verificar los movimientos posibles de un pe¨®n
    bool puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]);

    
};

