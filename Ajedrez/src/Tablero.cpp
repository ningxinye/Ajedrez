
#include "Tablero.h"
#include "Peon.h"

#include <iostream>
#include <string>



Tablero::Tablero():tabla(nullptr)
{
    // Inicializar el tablero con piezas en las posiciones iniciales
    casillas.resize(5, std::vector<Pieza*>(5, nullptr)); // Tablero de 5*5
 
     // Inicializar tabla
    tabla = new Pieza * [n];
    for (int i = 0; i < n; ++i) {
        tabla[i] = new Pieza[n];
    }

   // Aquí debes inicializar las casillas con las piezas en su posición inicial

}

Tablero::~Tablero()
{
    // Libera la memoria de la pieza de ajedrez en el tablero.
    if (tabla != nullptr) {
        for (int i = 0; i < n; ++i) {
            delete[] tabla[i];
        }
        delete[] tabla;
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
        casillas[2][i] = new Pieza(Tipo::No_pieza, Color:: Sin_color, 2, i);
    }
}

bool Tablero::estaDentroDelTablero(const Casilla& casilla) const
{
    // Verifica si la casilla está dentro de los límites del tablero
    return casilla.f >= 0 && casilla.f < 5 && casilla.c >= 0 && casilla.c < 5;
}

bool Tablero::puedeMoverse(Pieza* pieza, const Casilla& origen, const Casilla& destino)
{
    // Lógica para verificar si una pieza puede moverse desde origen a destino
        // Esto puede incluir verificar las reglas de movimiento de la pieza específica
        // Aquí puede implementar la lógica de movimiento específica de cada tipo de pieza
    if (pieza->getTipo() == Tipo::Peon) {
        // Si la pieza es un peón, realiza la conversión de tipo
        Peon* peon = dynamic_cast<Peon*>(pieza);
        if (peon && peon->Mov(origen, destino, casillas)) {
            return true;
        }
    }
    // Agregue lógica para otros tipos de piezas aquí
    return false;  // Por defecto, retorna falso si el movimiento no es válido
}

bool Tablero::moverPieza(Pieza* pieza, const Casilla& origen, const Casilla& destino)
{
    // Verifica si la posición de destino es válida y si el movimiento cumple con las reglas del juego
    // Por ejemplo, puedes verificar si la posición de destino está dentro de los límites del tablero
    // Comprueba si se puede mover a la posición de destino
    if (estaDentroDelTablero(destino) && puedeMoverse(pieza, origen, destino)) {
        // Mueve la pieza
        casillas[destino.f][destino.c] = pieza;
        casillas[origen.f][origen.c] = nullptr; // Limpia la posición de origen
        pieza->setCasilla(destino.f, destino.c);
        return true;  // Movimiento exitoso
    }
    return false;  // Movimiento fallido
}




