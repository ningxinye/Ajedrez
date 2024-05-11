
#include "Ajedrez.h"

using namespace std;


Ajedrez::Ajedrez() : turno(Color::Blanca), piezaSeleccionada(false), origen(-1, -1), destino(-1, -1) {}

void Ajedrez::dibuja()
{
	gluLookAt(2.5, 2.5, 12,  // posicion del ojo
		2.5, 2.5, 0.0,    // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
	
	tablero.dibuja();


}

void Ajedrez::inicializa()
{
	tablero.posicionInicial();
    turno = Color::Blanca;
    piezaSeleccionada = false;

}
Color Ajedrez::getTurno() const
{
    return turno;
}

const Tablero& Ajedrez::getTablero() const
{
    return tablero;
}

Tablero& Ajedrez::getTablero()
{
    return tablero;
}

void Ajedrez::jugada(int col, int fila)
{
    //Casilla destino = { fila, col };

    if (!piezaSeleccionada) {

        Casilla nuevaOrigen(col, fila);

        if (tablero.obtenerPiezaEnPosicion(origen.f, origen.c) && tablero.getColor(origen) == turno) {
            // Si la pieza seleccionada pertenece al jugador en la ronda actual
            origen = nuevaOrigen;
            piezaSeleccionada = true;
            tablero.mostrarPosiblesMovimientos(origen); // Mostrar posibles movimientos, si se implementan
        }

        else {
            // Si no hay ninguna pieza de ajedrez en la posici車n seleccionada o no es la pieza de ajedrez del jugador actual
            origen = Casilla(-1, -1); // restablecer origen
            piezaSeleccionada = false;
        }
    }
    else {
        // Si una pieza ya ha sido seleccionada, maneja la selecci車n de la posici車n de destino.
        Casilla nuevoDestino(col, fila);
        if (nuevoDestino == origen) {
            // Si la posici車n de destino es la misma que el origen, anule la selecci車n
            origen = Casilla(-1, -1);
            piezaSeleccionada = false;
           // tablero.resetearAyudaMovimiento(); // Mostrar posibles movimientos
        }
        else if (tablero.validarMovimiento(origen, destino)) {
            // Comprueba si es un movimiento v芍lido.
            Pieza* pieza = tablero.obtenerPiezaEnPosicion(origen.f, origen.c);
            if (pieza) {
                tablero.moverPieza(pieza, origen, nuevoDestino);
                turno = (turno == Color::Blanca) ? Color::Negra : Color::Blanca;// Cambiar de ronda
                origen = Casilla(-1, -1);
                destino = Casilla(-1, -1);
                piezaSeleccionada = false;
              //  tablero.resetearAyudaMovimiento(); //Posibles movimientos para restablecer la pantalla
            }
        }
      
    }
}