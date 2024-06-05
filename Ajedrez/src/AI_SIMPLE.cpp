#include "AI_SIMPLE.h"
#include <cstdlib>
#include <ctime>

// Constructor de la clase AI
AI::AI() {
    std::srand(std::time(0)); // Inicializa el generador de números aleatorios con el tiempo actual
}

// Destructor de la clase AI
AI::~AI() {
}

// Método para realizar un movimiento
void AI::realizarMovimiento(Tablero& tablero, int color) {
    auto movimientos = obtenerMovimientosValidos(tablero, color); // Obtiene todos los movimientos válidos para el color dado
    if (!movimientos.empty()) { // Si hay movimientos válidos disponibles
        auto movimiento = seleccionarMejorMovimiento(movimientos); // Selecciona el mejor movimiento (en este caso, de manera aleatoria)
        tablero.actualizarMovimiento(movimiento.first, movimiento.second); // Actualiza el tablero con el movimiento seleccionado
    }
}

// Método para obtener todos los movimientos válidos
std::vector<std::pair<Casilla, Casilla>> AI::obtenerMovimientosValidos(Tablero& tablero, int color) {
    std::vector<std::pair<Casilla, Casilla>> movimientos; // Vector para almacenar los movimientos válidos
    for (int i = 0; i < 5; ++i) { // Recorre todas las filas del tablero
        for (int j = 0; j < 5; ++j) { // Recorre todas las columnas del tablero
            Casilla origen(i, j); // Define la casilla de origen
            if (tablero.getColor(origen) == color) { // Si la pieza en la casilla de origen es del color del jugador actual
                tablero.PosiblesMovimientos(origen); // Obtiene todos los movimientos posibles para la pieza en la casilla de origen
                for (int k = 0; k < 5; ++k) { // Recorre todas las filas del tablero para los movimientos posibles
                    for (int l = 0; l < 5; ++l) { // Recorre todas las columnas del tablero para los movimientos posibles
                        Casilla destino(k, l); // Define la casilla de destino
                        if (tablero.validarMovimiento(origen, destino)) { // Si el movimiento de origen a destino es válido
                            movimientos.emplace_back(origen, destino); // Añade el movimiento al vector de movimientos válidos
                        }
                    }
                }
                tablero.setMovInicial(); // Resetea la matriz de movimientos posibles
            }
        }
    }
    return movimientos; // Retorna el vector de movimientos válidos
}

// Método para seleccionar el mejor movimiento (en este caso, de manera aleatoria)
std::pair<Casilla, Casilla> AI::seleccionarMejorMovimiento(const std::vector<std::pair<Casilla, Casilla>>& movimientos) {
    int index = std::rand() % movimientos.size(); // Selecciona un índice aleatorio en el vector de movimientos
    return movimientos[index]; // Retorna el movimiento en el índice seleccionado
}
