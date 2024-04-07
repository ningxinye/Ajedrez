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
	if (estado==INICIO) {

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
		ETSIDI::printxy("Orden de los Peones Algor¨ªtmicos", 3, 1);


 }
	else if (estado == JUEGO_BABY) {


	}

	else if (estado == JUEGO_GARDNER) {

	}
	else if (estado == FIN) {

	}

	else if (estado == PAUSA) {

	}
}



void Mundo::tecla(unsigned char key)
{

}
