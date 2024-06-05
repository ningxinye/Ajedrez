
#include "Mundo.h"
#include"ETSIDI.h"
#include "freeglut.h"
#include <math.h>
#include <string>



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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("D:/download/trabajo_inf_2024/FINAL/Ajedrez/bin/inicio.png").id); 
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
	else if (estado == JUEGO_BABY) {
		ajedrez.dibuja();

		// Mostrar el temporizador
		int tiempoRestante = obtenerTiempoRestante();
		glDisable(GL_LIGHTING);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy(std::to_string(tiempoRestante).c_str(), 6, 5); // Ajustar la posición según sea necesario
		glEnable(GL_LIGHTING);

		if (tiempoRestante <= 0) {
			estado = TIEMPO_LIM;
		}
	
	}

	else if (estado == JUEGO_GARDNER) {
		ajedrez.dibuja();

		// Mostrar el temporizador
		int tiempoRestante = obtenerTiempoRestante();
		glDisable(GL_LIGHTING);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy(std::to_string(tiempoRestante).c_str(), 6, 5); // Ajustar la posición según sea necesario
		glEnable(GL_LIGHTING);

		if (tiempoRestante <= 0) {
			estado = TIEMPO_LIM;
		}

	}

	else if (estado == JUGADOR_VS_AI) {

		ajedrez.dibuja();

		int tiempoRestante = obtenerTiempoRestante();
		glDisable(GL_LIGHTING);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy(std::to_string(tiempoRestante).c_str(), 6, 5);
		glEnable(GL_LIGHTING);

		if (tiempoRestante <= 0) {
			estado = TIEMPO_LIM;
		}

	}
	else if (estado == TIEMPO_LIM) {
		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
		// Código para el estado FIN
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy("Tiempo agotado", -3, 5); // Ajustar la posición según sea necesario

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
			ajedrez.inicializa(true, false);
			iniciarContador(60); // Establecer el temporizador a 60 segundos
			estado = JUEGO_BABY;
		}
		else if (key == 'G' || key == 'g') {
			ajedrez.inicializa(false, false);
			iniciarContador(60); // Establecer el temporizador a 60 segundos
			estado = JUEGO_GARDNER;
		}
		else if (key == 'a' || key == 'A') {
			ajedrez.inicializa(true, true); // Jugador vs AI
			iniciarContador(60);
			estado = JUGADOR_VS_AI;
		}
		else if (key == 'S' || key == 's')
			exit(0);
		break;
	case JUEGO_BABY:
		//Agregamos la lógica clave para manejar el estado del tablero de ajedrez
		break;
	case JUEGO_GARDNER:
		//Agregar lógica de claves para manejar otro estado del tablero de ajedrez
		break;
	case FIN:
		//Agregamos la lógica clave para manejar el estado final del juego
		break;
	case PAUSA:
		if ((estado == JUEGO_BABY || estado == JUEGO_GARDNER || estado == JUGADOR_VS_AI) && (key == 'p' || key == 'P')) {
			estado = PAUSA;
		}
		// Agrega logica de clave de procesamiento cuando el juego esta en pausa
		break;
	default:
		break;

	}
}

void Mundo::JUEGA(int button, int state, int x, int y)
{
	if (estado == JUEGO_BABY || estado == JUEGO_GARDNER || estado == JUGADOR_VS_AI) {
		ajedrez.JUEGO(button, state, x, y);

	}
}

void Mundo::iniciarContador(int segundos)
{
	countdownTime = segundos;
	startTime = time(0);
}

int Mundo::obtenerTiempoRestante()
{
	time_t now = time(0);
	int elapsed = static_cast<int>(difftime(now, startTime));
	return countdownTime - elapsed;
}






