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

		/*
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Mini juegos de ajedrez", -5, 12);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA Q PARA EMPEZAR AJEDREZ BABY ", -7, 9);
		ETSIDI::printxy("PULSE LA TECLA W PARA EMPEZAR AJEDREZ GARDNER ", -7, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("Orden de los Peones Algor¨ªtmicos", 3, 1);
		*/

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("C:/Users/User/Documents/GitHub/Ajedrez/Ajedrez/bin/inicio.png").id);  //C:/Users/User/Documents/GitHub/Ajedrez/Ajedrez/bin/inicio.png
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-14.5f, -3.5f, 0.0f); //esquina inferior izquierda
		glTexCoord2d(1, 1);    glVertex3f(14.5f, -3.5f, 0.0f);
		glTexCoord2d(1, 0);    glVertex3f(14.5f, 18.5f, 0.0f);
		glTexCoord2d(0, 0);    glVertex3f(-14.5f, 18.5f, 0.0f); //esquina superior izquierda
		glEnd();

		/*glTexCoord2d(0, 1); glVertex3f(-28.0f, -20.0f, 0.0f);
		glTexCoord2d(1, 1); glVertex3f(28.0f, -20.0f, 0.0f);
		glTexCoord2d(1, 0); glVertex3f(28.0f, 20.0f, 0.0f);
		glTexCoord2d(0, 0); glVertex3f(-28.0f, 20.0f, 0.0f);*/

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else if (estado == JUEGO_BABY || estado == JUEGO_GARDNER) {

		ajedrez.dibuja();
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
		if (key == 'B' || key == 'b') {
			ajedrez.inicializa(true);
			estado = JUEGO_BABY;
		}
		else if (key == 'G' || key == 'g') {
			ajedrez.inicializa(false);
			estado = JUEGO_GARDNER;
		}
		else if (key == 'S' || key == 's')
			exit(0);
		break;
	case JUEGO_BABY:
		//Agregamos la logica clave para manejar el estado del tablero de ajedrez
		break;
	case JUEGO_GARDNER:
		//Agregar logica de claves para manejar otro estado del tablero de ajedrez
		break;
	case FIN:
		
		//Agregamos la logica clave para manejar el estado final del juego
		break;
	case PAUSA:
		if (estado == JUEGO_BABY || estado == JUEGO_GARDNER && (key == 'p' || key == 'P')) {
			estado = PAUSA;
		}
		// Agrega logica de clave de procesamiento cuando el juego esta en pausa
		break;
	default:
		break;

	}
}

//navegacion por raton
void Mundo::JUEGA(int button, int state, int x, int y)
{
	if (estado == JUEGO_BABY || estado == JUEGO_GARDNER) {
		ajedrez.JUEGO(button, state, x, y);
	}
}




