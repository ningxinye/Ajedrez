#pragma once
#include "Pieza.h"


class Peon// : public Pieza //La clase Pe車n hereda de la clase Pieza.
{
public:
 

    // Funci車n para verificar los movimientos posibles de un pe車n
    static bool Mov(Casilla cd, Casilla co, Pieza** tab);

    // Funci車n para comer el piezas
    static bool Comer(Casilla cd, Casilla co, Pieza** tab);
 
};

