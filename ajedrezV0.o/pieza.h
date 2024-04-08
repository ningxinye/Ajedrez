#pragma once

class Pieza {
public:
    enum class Tipo { Peon, Caballo, Alfil, Torre, Rey, Reina };
    enum class Color { Blanca, Negra };

    //Constructor
    Pieza(Tipo tipo, Color color, int fila, int col) : tipo(tipo), color(color), fila(fila), col(col) {}

    // Métodos para obtener información sobre la pieza
    Tipo getTipo() const { return tipo; }
    Color getColor() const { return color; }
    int getFila() const { return fila; }
    int getCol() const { return col; }

    // Métodos para mover la pieza y otras operaciones relacionadas
    void mover(int nuevafila, int nuevacol) {
        // Implementación del movimiento de la pieza
    }

private:
    Tipo tipo;
    Color color;
    int fila;
    int col;
};