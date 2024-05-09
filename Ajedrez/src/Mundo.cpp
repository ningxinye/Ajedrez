
#include "Mundo.h"
#include"ETSIDI.h"
#include "freeglut.h"
#include <math.h>

Mundo::Mundo()
{
	estado = INICIO;
}

Mundo::~Mundo()
{
}



void Mundo::dibuja()
{
	if (estado == INICIO) { //dibuja la pantalla del menu del inicio

		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Mini juegos de ajedrez", -5, 12);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA Q PARA EMPEZAR AJEDREZ BABY ", -7, 9);
		ETSIDI::printxy("PULSE LA TECLA W PARA EMPEZAR AJEDREZ GARDNER ", -7, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("Orden de los Peones Algor赤tmicos", 3, 1);


	}
	else if (estado == JUEGO_BABY) {

		ajedrez.dibuja();
		

	
	
	}

	else if (estado == JUEGO_GARDNER) {

	}
	else if (estado == FIN) {

	}

	else if (estado == PAUSA) {

	}
}


//navegacion por teclado para avanzar el juego
void Mundo::tecla(unsigned char key){

	switch (estado) {
	case INICIO:
		ajedrez.inicializa();
		if (key == 'Q') {
			estado = JUEGO_BABY;
		}
		break;
	case JUEGO_BABY:
		//Agregamos la l車gica clave para manejar el estado del tablero de ajedrez
		break;
	case JUEGO_GARDNER:
		//Agregar l車gica de claves para manejar otro estado del tablero de ajedrez
		break;
	case FIN:
		//Agregamos la l車gica clave para manejar el estado final del juego
		break;
	case PAUSA:
		// Agrega l車gica de clave de procesamiento cuando el juego est芍 en pausa
		break;
	default:
		break;

	}
}

void Mundo::pulsar_raton(int button, int state, int x, int y)
{
	// Verifica si estamos en el estado de juego JUEGO_BABY
	if (estado == JUEGO_BABY) {
		// Verifica si se ha presionado el bot車n izquierdo del rat車n
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			// Convertir las coordenadas de la ventana a coordenadas del tablero de ajedrez
			// Calcula la columna y fila del tablero seg迆n las coordenadas de la ventana
			int col = static_cast<int>((x - 125) / 110.4);
			int fila = static_cast<int>((y - 25) / 110.4);

			// Asegurarse de que las coordenadas est芍n dentro de los l赤mites del tablero
			if (fila >= 0 && fila < 5 && col >= 0 && col < 5) {
				// Si no se ha seleccionado una pieza, intenta seleccionarla
				if (!piezaSeleccionada) {
					// Obtener la pieza en la posici車n seleccionada
					Pieza* pieza = ajedrez.getTablero().obtenerPiezaEnPosicion(fila, col);

					// Si la posici車n contiene una pieza del color del turno, la seleccionamos
					if (pieza != nullptr && pieza->getColor() == ajedrez.getTurno()) {
						origen = Casilla(fila, col);  // Guarda la posici車n de origen
						piezaSeleccionada = true;    // Marca que la pieza est芍 seleccionada
					}
				}
				else {
					// Si ya se ha seleccionado una pieza, intenta moverla a la posici車n actual
					destino = Casilla(fila, col);  // Guarda la posici車n de destino

					// Obtener la pieza en la posici車n de origen
					Pieza* pieza = ajedrez.getTablero().obtenerPiezaEnPosicion(origen.f, origen.c);

					// Intenta mover la pieza del origen al destino
					if (pieza != nullptr && ajedrez.getTablero().moverPieza(pieza, origen, destino)) {
						// Movimiento exitoso, actualiza la selecci車n de la pieza
						piezaSeleccionada = false;
						glutPostRedisplay();  // Actualiza la pantalla
					}
				}
			}
		}
	}
}

