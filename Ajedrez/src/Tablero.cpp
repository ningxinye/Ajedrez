
#include "Tablero.h"
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

   // Aqu¨ª debes inicializar las casillas con las piezas en su posici¨®n inicial

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

void Tablero::dibuja()
{
    //dibujar piezas
    dibujarPiezas();
    posicionInicial();

    //dibujar tablero
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0) {
                glDisable(GL_LIGHTING);
                glColor3ub(45, 87, 44); //verde oscuro 
                glBegin(GL_POLYGON);
                glVertex3f(static_cast<GLfloat>(i + 1.5), static_cast<GLfloat>(j + 1.5), 0);
                glVertex3f(static_cast<GLfloat>(i + 1.5), static_cast<GLfloat>(j + 2.5), 0);
                glVertex3f(static_cast<GLfloat>(i + 2.5), static_cast<GLfloat>(j + 2.5), 0);
                glVertex3f(static_cast<GLfloat>(i + 2.5), static_cast<GLfloat>(j + 1.5), 0);
                glEnd();
            }
            else {
                glColor3ub(189, 236, 182); //verde claro
                glBegin(GL_POLYGON);
                glVertex3f(static_cast<GLfloat>(i + 1.5), static_cast<GLfloat>(j + 1.5), 0);
                glVertex3f(static_cast<GLfloat>(i + 1.5), static_cast<GLfloat>(j + 2.5), 0);
                glVertex3f(static_cast<GLfloat>(i + 2.5), static_cast<GLfloat>(j + 2.5), 0);
                glVertex3f(static_cast<GLfloat>(i + 2.5), static_cast<GLfloat>(j + 1.5), 0);
                glEnd();
            }

            glEnable(GL_LIGHTING);
        }
    }
  
  
}

void Tablero::dibujarPiezas()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (casillas[i][j] != nullptr) {
                casillas[i][j]->dibuja(); // Llame a la funci¨®n de dibujo de la pieza de ajedrez.
            }
        }
    }
}



void Tablero::posicionInicial()//Posicion iniciales de las piezas en el tablero
{
    // Piezas negras
    casillas[0][0] = new Pieza(Tipo::Torre, Color::Negra, 0, 0);
    casillas[0][1] = new Pieza(Tipo::Caballo, Color::Negra, 0, 1);
    casillas[0][2] = new Pieza(Tipo::Alfil, Color::Negra, 0, 2);
    casillas[0][3] = new Pieza(Tipo::Rey, Color::Negra, 0, 3);
    casillas[0][4] = new Pieza(Tipo::Reina, Color::Negra, 0, 4);
    for (int i = 0; i < 5; ++i) {
        casillas[1][i] = new Pieza(Tipo::Peon, Color::Negra, 1, i);
    }

    // Piezas blancas
    casillas[3][0] = new Pieza(Tipo::Rey, Color::Blanca, 3, 0);
    casillas[3][1] = new Pieza(Tipo::Reina, Color::Blanca, 3, 1);
    casillas[3][2] = new Pieza(Tipo::Alfil, Color::Blanca, 3, 2);
    casillas[3][3] = new Pieza(Tipo::Caballo, Color::Blanca, 3, 3);
    casillas[3][4] = new Pieza(Tipo::Torre, Color::Blanca, 3, 4);
    for (int i = 0; i < 5; ++i) {
        casillas[4][i] = new Pieza(Tipo::Peon, Color::Blanca, 4, i);
    }
     
}
