
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
		ETSIDI::printxy("Mini juego de ajedrez", -5, 12);
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
