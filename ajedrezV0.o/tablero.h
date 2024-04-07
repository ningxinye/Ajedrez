#pragma once
#include "pieza.h"
#include <vector>


class Tablero {
public:
    Tablero() {
        // Inicializar el tablero con piezas en las posiciones iniciales
        casillas.resize(5, std::vector<Pieza*>(5, nullptr)); // Tablero de 8x8
        // Aquí debes inicializar las casillas con las piezas en su posición inicial
    }

    // Métodos para mostrar el tablero, realizar movimientos, etc.
    void mostrar() const {
        // Implementación para mostrar el tablero en la consola
    }

    Pieza* obtenerPiezaEnPosicion(int fila, int col) const {
        return casillas[fila][col];
    }

    // Método para comprobar si una casilla está ocupada por una pieza
    bool estaOcupada(int fila, int col) const {
        return casillas[fila][col] != nullptr;
    }

    // Método para comprobar si una casilla está ocupada por una pieza de un color específico
    bool estaOcupadaPorColor(int fila, int col, Pieza::Color color) const {
        if (casillas[fila][col] != nullptr) {
            return casillas[fila][col]->getColor() == color;
        }
        return false;
    }

private:
    std::vector<std::vector<Pieza*>> casillas; // Representación del tablero
};