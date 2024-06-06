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
    posicionInicial(false); // Asegúrate de que las piezas están configuradas desde el inicio
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

    //  std::cout << "Dibujando tablero.\n";
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
           
            // Dibujar la pieza si existe
            if (casillas[i][j] != nullptr) {
                casillas[i][j]->dibuja(aux, mov[i][j]);
            }
            //casillas[i][j]->dibuja(aux, mov[i][j]); //Llama al dibuja de pieza
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

void Tablero::colocarPiezasIniciales(int fila, Color color, std::vector<Tipo> piezas) {
    for (int j = 0; j < 5; j++) {
        casillas[fila][j] = new Pieza(piezas[j], color, fila, j);
    }
}

void Tablero::posicionarPeones(int fila, Color color) {
    for (int j = 0; j < 5; j++) {
        casillas[fila][j] = new Pieza(Tipo::Peon, color, fila, j);
    }
}

void Tablero::vaciarFila(int fila) {
    for (int j = 0; j < 5; j++) {
        casillas[fila][j] = new Pieza(Tipo::No_pieza, Color::Sin_color, fila, j);
    }
}

void Tablero::posicionInicial(bool est) 
{
    // Configuración de las piezas
    std::vector<Tipo> piezasBlancas = { Tipo::Torre, Tipo::Caballo, Tipo::Alfil, Tipo::Reina, Tipo::Rey };
    std::vector<Tipo> piezasNegrasBABY = { Tipo::Rey, Tipo::Reina, Tipo::Alfil, Tipo::Caballo, Tipo::Torre };
    std::vector<Tipo> piezasNegrasGARDNER = { Tipo::Torre, Tipo::Caballo, Tipo::Alfil, Tipo::Reina, Tipo::Rey };

    // Colocar piezas blancas
    colocarPiezasIniciales(0, Color::Blanca, piezasBlancas);
    posicionarPeones(1, Color::Blanca);

    // Vaciar la fila central
    vaciarFila(2);

    // Colocar peones negros
    posicionarPeones(3, Color::Negra);

    // Colocar piezas negras según el tipo de ajedrez
    if (est) { // Configuración BABY
        colocarPiezasIniciales(4, Color::Negra, piezasNegrasBABY);
    }
    else { // Configuración GARDNER
        colocarPiezasIniciales(4, Color::Negra, piezasNegrasGARDNER);
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


bool Tablero::validarMovimiento(const Casilla& origen, const Casilla& destino)
{
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
            resultado = Peon::esMovimientoValido(origen, destino, tempCasillas);
            break;
              case Torre:
          // Implementar lógica de movimiento de la torre
         
          for (int i = 0; i < 5; ++i) {
              for (int j = 0; j < 5; ++j) {
                  tempCasillas[i][j] = casillas[i][j];
              }
          }
          resultado = Torre::esMovimientoValido(origen, destino, tempCasillas);        
          break;
      case Caballo:
          // Implementar lógica de movimiento del caballo
          break;
      case Alfil:
          // Implementar lógica de movimiento del alfil
          for (int i = 0; i < 5; ++i) {
              for (int j = 0; j < 5; ++j) {
                  tempCasillas[i][j] = casillas[i][j];
              }
          }
          resultado = alfil::SePuedeMover(origen, destino, tempCasillas);
          break;
      case Reina:
          // Implementar lógica de movimiento de la reina

          for (int i = 0; i < 5; ++i) {
              for (int j = 0; j < 5; ++j) {
                  tempCasillas[i][j] = casillas[i][j];
              }
          }
          resultado = Reina::esMovimientoValido(origen, destino, tempCasillas);
          break;
      case Rey:
          // Implementar lógica de movimiento del rey
          for (int i = 0; i < 5; ++i) {
              for (int j = 0; j < 5; ++j) {
                  tempCasillas[i][j] = casillas[i][j];
              }
          }
          //resultado = Rey::esMovimientoValido(origen, destino, tempCasillas);
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

    //RENOVAR LA POSICION DE LAS PIEZAS
    //casillas[destino.f][destino.c]->setMovida(true);
    casillas[destino.f][destino.c]->setCasilla(destino.f, destino.c);

    //limpiar origen
    casillas[origen.f][origen.c]->setColor(Sin_color);
    casillas[origen.f][origen.c]->setTipo(No_pieza);
    casillas[origen.f][origen.c]->setCasilla(origen.f, origen.c);

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

/*void Tablero::muevePieza(int x1, int y1, int x2, int y2)
{
    //logica del mov de las piezas
    casillas[x2][y2] = casillas[x1][y1];
    casillas[x1][y1] = nullptr;

    //marcar las piezas que necesita redibujar
    necesitoRedibujo[x1][y1] = true;
    necesitoRedibujo[x2][y2] = true;
}*/
