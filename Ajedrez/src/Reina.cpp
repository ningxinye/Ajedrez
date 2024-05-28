#include "Reina.h"
#include <iostream>
#include <cmath>

bool Reina::esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
    std::cout << "Comprobando movimiento de la reina: desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";

    int diferenciaDeFilas = destino.f - origen.f;
    int diferenciaDeColumnas = destino.c - origen.c;

    // Verificar si el movimiento es en línea recta o diagonal
    if (abs(diferenciaDeFilas) != abs(diferenciaDeColumnas) &&
        diferenciaDeFilas != 0 &&
        diferenciaDeColumnas != 0) {
        return false;
    }

    int stepFila = (diferenciaDeFilas != 0) ? (diferenciaDeFilas / abs(diferenciaDeFilas)) : 0;
    int stepColumna = (diferenciaDeColumnas != 0) ? (diferenciaDeColumnas / abs(diferenciaDeColumnas)) : 0;

    // Verificar si hay piezas en el camino
    int f = origen.f + stepFila;
    int c = origen.c + stepColumna;
    while (f != destino.f || c != destino.c) {
        if (casillas[f][c]->getTipo() != No_pieza) {
            std::cout << "Hay una pieza en el camino en (" << f << ", " << c << ")\n";
            return false;
        }
        f += stepFila;
        c += stepColumna;
    }

    // Verificar el destino
    if (casillas[destino.f][destino.c]->getTipo() == No_pieza ||
        casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
        return true;
    }

    return false;
}