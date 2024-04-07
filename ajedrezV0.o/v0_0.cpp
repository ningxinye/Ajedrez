#include <iostream>
#include <vector>

// Definición de clases
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
    bool estaOcupadaPorColor(int fila, int col, Piza::Color color) const {
        if (casillas[fila][col] != nullptr) {e
            return casillas[fila][col]->getColor() == color;
        }
        return false;
    }

private:
    std::vector<std::vector<Pieza*>> casillas; // Representación del tablero
};

class Juego {
public:
    Juego() : tablero() {}

    // Método principal para iniciar y ejecutar el juego
    void jugar() {
        // Implementación del ciclo de juego (turnos de jugadores, verificación de estado del juego, etc.)
    }

private:
    Tablero tablero;
};

int main() {
    Juego juego;
    juego.jugar();

    return 0;
}

