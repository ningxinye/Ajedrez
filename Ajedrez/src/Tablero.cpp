
#include "Tablero.h"
#include "Peon.h"
#include <iostream>
#include <string>




Tablero::Tablero() {

    // Inicializar el tablero con piezas en las posiciones iniciales
    casillas.resize(5, std::vector<Pieza*>(5, nullptr)); // Tablero de 5*5
    posicionInicial(); // Asegúrate de que las piezas están configuradas desde el inicio
}

Tablero::~Tablero()
{
    // Libera la memoria de la pieza de ajedrez en el tablero.
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) 
        {
            delete casillas[i][j]; // Eliminar pieza individualmente
        }
    }
}

void Tablero::dibuja() {

    // Dibujar tablero y piezas juntos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Dibujar tablero
            if ((i + j) % 2 == 0) {
                glDisable(GL_LIGHTING);
                glColor3ub(45, 87, 44); // verde oscuro
            }
            else {
                glColor3ub(189, 236, 182); // verde claro
            }

            glBegin(GL_POLYGON);
            // Usando las coordenadas correctas, dibuja las celdas del tablero de ajedrez a un tamaño de 1x1
            glVertex3f(-0.5, -0.5, -0.5f);
            glVertex3f(-0.5, 5.5, -0.5f);
            glVertex3f(5.5, 5.5, -0.5f);
            glVertex3f(5.5, -0.5, -0.5f);
            glEnd();

            glEnable(GL_LIGHTING);

            // Dibujar las piezas
            if (casillas[i][j] != nullptr) {
                // Antes de dibujar la pieza de ajedrez, asegúrate de establecer las coordenadas de la pieza de ajedrez
                casillas[i][j]->setCasilla(i, j);
                casillas[i][j]->dibuja();// Dibuja la pieza de ajedrez usando las coordenadas de la celda actual



            }
        }
    }
}

/*void Tablero::dibujarPiezas()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (casillas[i][j] != nullptr) {
                casillas[i][j]->dibuja(); // Llame a la función de dibujo de la pieza de ajedrez.
            }
        }
    }
}
*/

void Tablero::posicionInicial()//Posicion iniciales de las piezas en el tablero
{
    // Piezas Blanca
    casillas[0][0] = new Pieza(Tipo::Torre, Color::Blanca, 0, 0);
    casillas[0][1] = new Pieza(Tipo::Caballo, Color::Blanca, 0, 1);
    casillas[0][2] = new Pieza(Tipo::Alfil, Color::Blanca, 0, 2);
    casillas[0][3] = new Pieza(Tipo::Reina, Color::Blanca, 0, 3);
    casillas[0][4] = new Pieza(Tipo::Rey, Color::Blanca, 0, 4);
    for (int i = 0; i < 5; ++i) {
        casillas[1][i] = new Pieza(Tipo::Peon, Color::Blanca, 1, i);
    }

    // Piezas Negra
    casillas[4][0] = new Pieza(Tipo::Rey, Color::Negra, 4, 0);
    casillas[4][1] = new Pieza(Tipo::Reina, Color::Negra, 4, 1);
    casillas[4][2] = new Pieza(Tipo::Alfil, Color::Negra, 4, 2);
    casillas[4][3] = new Pieza(Tipo::Caballo, Color::Negra, 4, 3);
    casillas[4][4] = new Pieza(Tipo::Torre, Color::Negra, 4, 4);
    for (int i = 0; i < 5; ++i) {
        casillas[3][i] = new Pieza(Tipo::Peon, Color::Negra, 3, i);
    }
    // Vacios
    for (int i = 0; i < 5; ++i) {
        casillas[2][i] = new Pieza(Tipo::No_pieza, Color::Sin_color, 2, i);
    }
}


Color Tablero::getColor(Casilla cas)
{
    if (cas.f < 0 || cas.f >= 5 || cas.c < 0 || cas.c >= 5) return Sin_color; // Asegurar los límites
    if (casillas[cas.f][cas.c] == nullptr) return Sin_color;
    return casillas[cas.f][cas.c]->getColor();
}

void Tablero::mostrarPosiblesMovimientos(Casilla cas)
{

}

void Tablero::resetearAyudaMovimiento()
{
    // Resetea o limpia los posibles movimientos mostrados anteriormente
}

bool Tablero::validarMovimiento(Casilla origen, Casilla destino)
{
    // Validación de movimiento basada en las reglas de la pieza
    if (!estaDentroDelTablero(origen) || !estaDentroDelTablero(destino)) return false;
    Pieza* pieza = casillas[origen.f][origen.c];

    // Convertir casillas a tipo Pieza*[][5]
    Pieza* tablero[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tablero[i][j] = casillas[i][j];
        }
    }

    return pieza && pieza->puedeMoverse(origen, destino, tablero);
}


Pieza* Tablero::obtenerPiezaEnPosicion(int fila, int col) const
{
    return casillas[fila][col];
}

bool Tablero::estaDentroDelTablero(const Casilla& casilla) const
{
    // Verifica si la casilla está dentro de los límites del tablero
    return casilla.f >= 0 && casilla.f < 5 && casilla.c >= 0 && casilla.c < 5;
}



bool Tablero::puedeMoverse(Pieza* pieza, const Casilla& origen, const Casilla& destino)
{
    if (!estaDentroDelTablero(destino)) 
        return false;

    /**/
    // Convertir casillas a tipo Pieza*[][5]
    Pieza* tablero[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tablero[i][j] = casillas[i][j];
        }
    }

    // Llama al método puedeMoverse de la pieza
    return pieza->puedeMoverse(origen, destino, tablero);

    
}

bool Tablero::moverPieza(Pieza* pieza, const Casilla& origen, const Casilla& destino)
{
    // Verifica si la posición de destino está dentro de los límites del tablero
    if (!estaDentroDelTablero(destino)) {
        std::cout << "Movimiento fuera del tablero." << std::endl;
        return false;
    }

    // Verifica si el movimiento es válido
    if (!puedeMoverse(pieza, origen, destino)) {
        std::cout << "Movimiento no permitido por las reglas de la pieza." << std::endl;
        return false;
    }

    // Realiza el movimiento
    casillas[destino.f][destino.c] = pieza;
    casillas[origen.f][origen.c] = nullptr;
    pieza->setCasilla(destino.f, destino.c);

    // Configurar `movida` a `true`，porque la pieza se movió
    pieza->setMovida(true);

    return true;
}




