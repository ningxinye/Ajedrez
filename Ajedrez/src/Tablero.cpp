#include "Tablero.h"
#include <iostream>
#include <string>

Tablero::Tablero() {

    casillas.resize(n, std::vector<Pieza*>(n, nullptr));
    //Matriz de posibles movimientos
    mov = new int* [n];
    for (int i = 0; i < n; i++) {
        mov[i] = new int[n];
    }

    // Inicializar el tablero con piezas en las posiciones iniciales
   // casillas.resize(5, std::vector<Pieza*>(5, nullptr)); // Tablero de 5*5
    posicionInicial(); // Asegúrate de que las piezas están configuradas desde el inicio
}

Tablero::~Tablero()
{
    // Libera la memoria de la pieza de ajedrez en el tablero.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            delete casillas[i][j];  // Eliminar pieza individualmente
        }
    }

    //Matriz de posibles movimientos
    for (int i = 0; i < n; i++) {
        delete[] mov[i];  //eliminacion
    }
    delete[] mov;
}

void Tablero::dibuja() {

    std::cout << "Dibujando tablero.\n";
    int aux = 0;
    // Dibujar tablero y piezas juntos
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Dibujar tablero  
            aux++;
            if(mov[i][j] == 1){
                glColor3ub(34, 177, 76);
            }
            else if ((i + j) % 2 == 0) {
                glDisable(GL_LIGHTING);
                glColor3ub(45, 87, 44); // verde oscuro
            }

            else {
                glColor3ub(189, 236, 182); // verde claro
            }
            aux++;   
            casillas[i][j]->dibuja(aux, mov[i][j]);//Llama al dibuja de pieza
        }

        glBegin(GL_POLYGON);
        // Usando las coordenadas correctas, dibuja las celdas del tablero de ajedrez a un tamaño de 1x1
        glVertex3f(-0.5, -0.5, -0.5f);
        glVertex3f(-0.5, 5.5, -0.5f);
        glVertex3f(5.5, 5.5, -0.5f);
        glVertex3f(5.5, -0.5, -0.5f);
        glEnd();

        glEnable(GL_LIGHTING);
    }

}

void Tablero::posicionInicial()//Posicion iniciales de las piezas en el tablero
{

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

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
            //Asignación de casilla
            casillas[i][j]->setCasilla(i, j);
        }
    }

}

int Tablero::getColor(Casilla& cas)
{
    if (cas.f < 0 || cas.f >= 5 || cas.c < 0 || cas.c >= 5) {
        return Sin_color; // Asegurar los límites
    }
    if (casillas[cas.f][cas.c] == nullptr) {
        return Sin_color;
    }
    int color = casillas[cas.f][cas.c]->getColor();
    return color;
}

int Tablero::validarEnroque(Casilla& origen, Casilla& destino)
{
    return 0;
}

bool Tablero::validarMovimiento(const Casilla& origen, const Casilla& destino)
{
    //Comprobación de enroque si procede
     //cod

     // Validación de movimiento basada en las reglas de la pieza
    if (casillas[origen.f][origen.c]->getColor() == casillas[destino.f][destino.c]->getColor() && casillas[destino.f][destino.c]->getTipo() != No_pieza) {
        // Si el color de destino es igual que el de origen y hay una pieza en destino, invalida el movimiento
        return false;
    }
    else {
        bool resultado = false;  // Variable para almacenar el resultado del movimiento
        switch (casillas[origen.f][origen.c]->getTipo()) { // Comprobación del movimiento en función de la pieza de origen y destino
        case Peon:
            // Crea una copia temporal del tablero para evaluar los movimientos sin alterar el tablero original
            Pieza* tempCasillas[5][5];
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    tempCasillas[i][j] = casillas[i][j];
                }
            }
            if (((casillas[origen.f][origen.c]->getColor() == Blanca) && (casillas[destino.f][destino.c]->getColor() == Negra)) ||
                ((casillas[origen.f][origen.c]->getColor() == Negra) && (casillas[destino.f][destino.c]->getColor() == Blanca))) {
                // Si hay una pieza de color opuesto en el destino, se verifica si el peón puede comer
                std::cout << "Llamando a puedeMoverse con origen: (" << origen.f << ", " << origen.c << ") Y destino: (" << destino.f << ", " << destino.c << ")\n";
                     resultado = Peon::puedecomer(origen, destino, tempCasillas);
                     std::cout << "Result of puedeMoverse: " << resultado << std::endl;
           
            }
            else {
                // Se verifica si el peón puede moverse a una casilla vacía
                resultado = Peon::puedeMoverse(origen, destino, tempCasillas);
            }
            break;
        case Torre:
            // Implementar lógica de movimiento de la torre
            break;
        case Caballo:
            // Implementar lógica de movimiento del caballo
            break;
        case Alfil:
            // Implementar lógica de movimiento del alfil
            break;
        case Reina:
            // Implementar lógica de movimiento de la reina
            break;
        case Rey:
            // Implementar lógica de movimiento del rey
            break;
        default:
            resultado = false;  // Si no se reconoce el tipo de pieza, el movimiento es inválido
            break;
        }
        return resultado;  // Devuelve el resultado de la validación del movimiento
    }
}

void Tablero::actualizarMovimiento(Casilla& origen, Casilla& destino)
{
    //Hay dos posibilidades: movimiento a casilla vacía o comer pieza
    //borra la casilla de origen (No_pieza y Sin_color)
    // y sobreescribe los datos en la de destino
   //Indica que la pieza se ha movido

    std::cout << "Moviendo pieza desde (" << origen.f << ", " << origen.c << ")" << " a (" << destino.f << ", " << destino.c << ")\n";
    //mover pieza
    casillas[destino.f][destino.c]->setTipo(casillas[origen.f][origen.c]->getTipo());
    casillas[destino.f][destino.c]->setColor(casillas[origen.f][origen.c]->getColor());

    casillas[destino.f][destino.c]->setMovida(true);

    //limpiar origen
    casillas[origen.f][origen.c]->setColor(Sin_color);
    casillas[origen.f][origen.c]->setTipo(No_pieza);
    std::cout << "Pieza movida y actualizada. Tipo en destino: " << casillas[destino.f][destino.c]->getTipo() << "\n";
}

int Tablero::PosiblesMovimientos(Casilla& origen)
{
    //Recorre el tablero y asigna valor 1 a la casilla de destino si la pieza se puede mover ahí
//Matriz de ayuda al movimiento
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (validarMovimiento(origen, casillas[i][j]->getCasilla())) {  mov[i][j] = 1;  }
        }
    }
    return 0;
}

void Tablero::setMovInicial()
{
    //Reseta la matriz de ayuda al movimiento a 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) { mov[i][j] = 0; }
    }
}

void Tablero::resaltarMovimientosLegales(const Casilla& origen)
{
    limpiarDestacados();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Casilla destino(i, j);
            if (validarMovimiento(origen, destino)) {
                mov[i][j] = 1;  // Utilice una matriz auxiliar para marcar la posición a la que puede moverse
            }
        }
    }
}

void Tablero::limpiarDestacados()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mov[i][j] = 0;  // Restablecer matriz auxiliar
        }
    }
}
