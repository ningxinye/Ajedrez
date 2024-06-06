#include "Rey.h"
#include <iostream>
#include <cmath>

bool Rey::esMovimientoValido(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5])
{
    std::cout << "Comprobando movimiento de la reina: desde (" << origen.f << ", " << origen.c << ") hasta (" << destino.f << ", " << destino.c << ")\n";

    int diferenciaDeFilas = destino.f - origen.f;
    int diferenciaDeColumnas = destino.c - origen.c;
    int Fila, Columna;

    if (casillas[origen.f][origen.c]->getColor() == Blanca) {
        std::cout << "Intento de movimiento de una pieza blanca.\n";

        // Comprabación
        if (diferenciaDeFilas != 0 && diferenciaDeColumnas != 0 && abs(diferenciaDeFilas) != abs(diferenciaDeColumnas)) {
            std::cout << "Movimiento no es ni en líneal ni diagonal\n";
            return false;
        }

        if (diferenciaDeFilas != 0) {
            Fila = diferenciaDeFilas / abs(diferenciaDeFilas);
        }
        else {
            Fila = 0;
        }


        if (diferenciaDeColumnas != 0) {
            Columna = diferenciaDeColumnas / abs(diferenciaDeColumnas);
        }
        else {
            Columna = 0;
        }



        int f = origen.f + Fila;
        int c = origen.c + Columna;
        while (f != destino.f || c != destino.c) {
            if (casillas[f][c]->getTipo() != No_pieza) {
                std::cout << "Hay una pieza en el camino en (" << f << ", " << c << ")\n";
                return false;
            }
            f += Fila;
            c += Columna;
        }


        if (casillas[destino.f][destino.c]->getTipo() == No_pieza || casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
            return true;
        }
    }
    else if (casillas[origen.f][origen.c]->getColor() == Negra) {
        std::cout << "Intento de movimiento de una pieza negra.\n";

        // Comprabación
        if (diferenciaDeFilas != 0 && diferenciaDeColumnas != 0 && abs(diferenciaDeFilas) != abs(diferenciaDeColumnas)) {
            std::cout << "Movimiento no es ni en líneal ni diagonal\n";
            return false;
        }

        if (diferenciaDeFilas != 0) {
            Fila = diferenciaDeFilas / abs(diferenciaDeFilas);
        }
        else {
            Fila = 0;
        }


        if (diferenciaDeColumnas != 0) {
            Columna = diferenciaDeColumnas / abs(diferenciaDeColumnas);
        }
        else {
            Columna = 0;
        }



        int f = origen.f + Fila;
        int c = origen.c + Columna;
        while (f != destino.f || c != destino.c) {
            if (casillas[f][c]->getTipo() != No_pieza) {
                std::cout << "Hay una pieza en el camino en (" << f << ", " << c << ")\n";
                return false;
            }
            f += Fila;
            c += Columna;
        }


        if (casillas[destino.f][destino.c]->getTipo() == No_pieza || casillas[destino.f][destino.c]->getColor() != casillas[origen.f][origen.c]->getColor()) {
            return true;
        }
    }

    return false;




    return false;
}