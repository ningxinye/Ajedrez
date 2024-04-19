
#pragma once

#include <iostream>
#include <vector>
#include"ETSIDI.h"
#include "Casilla.h"
#include"freeglut.h"

enum  Tipo { No_pieza, Peon, Caballo, Alfil, Torre, Rey, Reina };
enum  Color { Sin_color, Blanca, Negra };

class Pieza
{

public:
    Pieza();
    ~Pieza();

    //grafico
    void dibuja();


    //Constructor
   Pieza(Tipo tipo, Color color, int fila, int col):tipo(tipo), color(color), casilla(fila, col), fila(fila), col(col)
    {
    }
    Pieza(const Pieza& p);

    // Métodos para obtener información sobre la pieza
    Tipo getTipo() const { return tipo; }
    Color getColor() const { return color; }
    Casilla getCasilla() { return casilla; }
    int getFila() const { return fila; }
    int getCol() const { return col; }


    // Métodos para mover la pieza y otras operaciones relacionadas
    void mover(int nuevafila, int nuevacol) {
        // Implementación del movimiento de la pieza
    }


    void setTipo(Tipo tipo) { tipo = tipo; }
    void setColor(Color color) { color = color; }
    void setCasilla(int x, int y) { casilla.f = x; casilla.c = y; }
    int setFila(int fila) { fila = fila; }
    int setCol(int col) { col = col; }

private:
    Tipo tipo;
    Color color;
    Casilla casilla;
    int fila=0;//fila (1,2...5)
    int col=0;//columna (a,b,c..e)

};


