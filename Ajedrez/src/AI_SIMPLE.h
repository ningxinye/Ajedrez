#pragma once
#include "Tablero.h"
#include "Casilla.h"
#include <vector>

class AI {
public:
    AI();
    ~AI();

    void realizarMovimiento(Tablero& tablero, int color);
private:
    std::vector<std::pair<Casilla, Casilla>> obtenerMovimientosValidos(Tablero& tablero, int color);
    std::pair<Casilla, Casilla> seleccionarMejorMovimiento(const std::vector<std::pair<Casilla, Casilla>>& movimientos);
};
