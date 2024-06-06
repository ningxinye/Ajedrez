#pragma once
#include <iostream>
#include <vector>
#include"ETSIDI.h"
#include "Casilla.h"
#include"Peon.h"
#include"Torre.h"
#include"Reina.h"
//#include"Rey.h"
#include"freeglut.h"

enum  Tipo { No_pieza, Peon, Caballo, Alfil, Torre, Rey, Reina };
enum  Color { Sin_color, Blanca, Negra };

class Pieza
{

public:
    Pieza();
    ~Pieza();

    //grafico
    void dibuja(int AUX, int auxmov);

    //Constructor
   Pieza(Tipo tipo, Color color, int fila, int col):tipo(tipo), color(color), casilla(fila, col), fila(fila), col(col)
    {
    }
    Pieza(const Pieza& p);

    // Metodos para obtener informacion sobre la pieza
    Tipo getTipo() const { return tipo; }
    Color getColor() const { return color; }
    Casilla getCasilla() { return casilla; }
    bool getMovida() const { return movida; }
    int getFila() const { return fila; }
    int getCol() const { return col; }

    // con el valor de movida: logica de mov de las piezas, verificaciones.....
    void setTipo(Tipo nuevoTipo) { tipo = nuevoTipo; }
    void setColor(Color nuevoColor) { color = nuevoColor; }
    void setCasilla(int f, int c) { casilla.f = f; casilla.c = c; }
    void setMovida(bool a) { movida = a; }
    int setFila(int nuevaFila) { fila = nuevaFila; }
    int setCol(int nuevaCol) { col = nuevaCol; }

     // Define el metodo virtual puedeMoverse
    virtual bool puedeMoverse(const Casilla& origen, const Casilla& destino, Pieza* casillas[5][5]) {
        // De forma predeterminada, retorna false (los subtipos deben anular este m¨¦todo)
        return false;
    }

private:
    Tipo tipo;
    Color color;
    Casilla casilla;
    int fila=0;//fila (1,2...5)
    int col=0;//columna (a,b,c..e)
    bool movida;//indica si la pieza se ha movido durante la partida o no

};


