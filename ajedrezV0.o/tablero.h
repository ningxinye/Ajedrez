#pragma once
#include "pieza.h"
#include <vector>


class Tablero {
public:
    Tablero() {
        // Inicializar el tablero con piezas en las posiciones iniciales
        casillas.resize(5, std::vector<Pieza*>(5, nullptr)); // Tablero de 8x8
        // Aqu� debes inicializar las casillas con las piezas en su posici�n inicial
    }

    // M�todos para mostrar el tablero, realizar movimientos, etc.
    void mostrar() const {
        // Implementaci�n para mostrar el tablero en la consola
    }

    Pieza* obtenerPiezaEnPosicion(int fila, int col) const {
        return casillas[fila][col];
    }

    // M�todo para comprobar si una casilla est� ocupada por una pieza
    bool estaOcupada(int fila, int col) const {
        return casillas[fila][col] != nullptr;
    }

    // M�todo para comprobar si una casilla est� ocupada por una pieza de un color espec�fico
    bool estaOcupadaPorColor(int fila, int col, Pieza::Color color) const {
        if (casillas[fila][col] != nullptr) {
            return casillas[fila][col]->getColor() == color;
        }
        return false;
    }

private:
    std::vector<std::vector<Pieza*>> casillas; // Representaci�n del tablero
};