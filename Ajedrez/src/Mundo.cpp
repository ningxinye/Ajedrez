#include "Mundo.h"
#include"ETSIDI.h"
#include "freeglut.h"
#include <math.h>
#include <string>



Mundo::Mundo()
{
	estado = INICIO;
	musica();
}

Mundo::~Mundo()
{
}


void Mundo::dibuja()
{
	musica();

	if (estado == INICIO) { //dibuja la pantalla del menu del inicio

		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  


		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/inicio.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-14.5f, -3.5f, 0.0f); //esquina inferior izquierda
		glTexCoord2d(1, 1);    glVertex3f(14.5f, -3.5f, 0.0f);
		glTexCoord2d(1, 0);    glVertex3f(14.5f, 18.5f, 0.0f);
		glTexCoord2d(0, 0);    glVertex3f(-14.5f, 18.5f, 0.0f); //esquina superior izquierda
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	else if (estado == SELECCIONAR)
	{
		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/seleccionar.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-14.5f, -3.5f, 0.0f); //esquina inferior izquierda
		glTexCoord2d(1, 1);    glVertex3f(14.5f, -3.5f, 0.0f);
		glTexCoord2d(1, 0);    glVertex3f(14.5f, 18.5f, 0.0f);
		glTexCoord2d(0, 0);    glVertex3f(-14.5f, 18.5f, 0.0f); //esquina superior izquierda
		glEnd();

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
		ETSIDI::printxy("(P) pausa", 6, 6);
		glEnable(GL_LIGHTING);

		if (tiempoRestante <= 0) {
			estado = TIEMPO_LIM;
		}

		if (!ajedrez.obtenerTablero().reyExiste(Blanca) || !ajedrez.obtenerTablero().reyExiste(Negra)) {
			estado = FIN;

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
		ETSIDI::printxy("(P) pausa", 6, 6);
		glEnable(GL_LIGHTING);

		if (tiempoRestante <= 0) {
			estado = TIEMPO_LIM;
		}
		if (!ajedrez.obtenerTablero().reyExiste(Blanca) || !ajedrez.obtenerTablero().reyExiste(Negra)) {
			estado = FIN;
		}

	}
	else if (estado == JUGADOR_VS_AI) {

		ajedrez.dibuja();

		int tiempoRestante = obtenerTiempoRestante();
		glDisable(GL_LIGHTING);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy(std::to_string(tiempoRestante).c_str(), 6, 5);
		ETSIDI::printxy("(P) pausa", 6, 6);
		glEnable(GL_LIGHTING);

		if (tiempoRestante <= 0) {
			estado = TIEMPO_LIM;
		}
		if (!ajedrez.obtenerTablero().reyExiste(Blanca) || !ajedrez.obtenerTablero().reyExiste(Negra)) {
			estado = FIN;

		}
	}
	else if (estado == JAQUEBLANCO) {
		ajedrez.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy("Jaque al Blanco", -3, 5); // Ajustar la posición según sea necesario
	}
	else if (estado == JAQUENEGRO) {
		ajedrez.dibuja();
		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy("Jaque al Negro", -3, 5); // Ajustar la posición según sea necesario
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
		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		ETSIDI::setTextColor(1, 0, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 24);
		ETSIDI::printxy("Fin del juego", -3, 5); // Ajustar la posición según sea necesario
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -12, 4);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -12,3);

	}

	else if (estado == PAUSA) {

		gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pausa.png").id);
		glDisable(GL_LIGHTING);

		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1);    glVertex3f(-14.5f, -3.5f, 0.0f); //esquina inferior izquierda
		glTexCoord2d(1, 1);    glVertex3f(14.5f, -3.5f, 0.0f);
		glTexCoord2d(1, 0);    glVertex3f(14.5f, 18.5f, 0.0f);
		glTexCoord2d(0, 0);    glVertex3f(-14.5f, 18.5f, 0.0f); //esquina superior izquierda
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);


	}
}

//navegacion por teclado para avanzar el juego
void Mundo::tecla(unsigned char key) {
	static bool ia = false;

	switch (estado) {
	case INICIO:
		if (key == '1' || key == '2') {
			ia = (key == '1');
			ETSIDI::play("musica/seleccionar.wav");
			estado = SELECCIONAR;
		}
		else if (key == 'S' || key == 's') {
			exit(0);
		}
		break;
	case SELECCIONAR:
		if (key == 'B' || key == 'b' || key == 'G' || key == 'g') {
			ETSIDI::play("musica/seleccionar.wav");
			bool isBaby = (key == 'B' || key == 'b');
			ajedrez.inicializa(isBaby, ia);
			iniciarContador(60); // Establecer el temporizador a 60 segundos
			estado = ia ? JUGADOR_VS_AI : (isBaby ? JUEGO_BABY : JUEGO_GARDNER);
		}
		break;
	case JUEGO_BABY:
	case JUEGO_GARDNER:
	case JUGADOR_VS_AI:
		if (key == 'p' || key == 'P') {
			estado = PAUSA;
		}
		break;
	case PAUSA:
		if (key == 'v' || key == 'V') {
			estado = ia ? JUGADOR_VS_AI : (estado == JUEGO_BABY ? JUEGO_BABY : JUEGO_GARDNER);
		}
		else if (key == 's' || key == 'S') {
			exit(0);
		}
		break;
	case FIN:
		if (key == 'c' || key == 'C') {
			estado = INICIO;
		}
		else if (key == 's' || key == 'S') {
			exit(0);
		}
		break;
	default:
		break;
	}
}



void Mundo::musica() {


	if (estado == INICIO) {
		nueva_musica = "musica/chill.mp3";
	}
	else if (estado == JUEGO_BABY || estado == JUEGO_GARDNER || estado == JUGADOR_VS_AI) {
		nueva_musica = "musica/juego.mp3";
	}
	else if (estado == PAUSA) {
		nueva_musica = "musica/pausa.mp3";
	}

	// Solo cambiar la música si es diferente a la actual
	if (nueva_musica != musica_actual) {
		ETSIDI::stopMusica(); // Detener la música actual antes de cambiar
		ETSIDI::playMusica(nueva_musica.c_str(), true);
		musica_actual = nueva_musica; // Actualizar el estado actual de la música
	}
}

void Mundo::JUEGA(int button, int state, int x, int y)
{
	if (estado == JUEGO_BABY || estado == JUEGO_GARDNER || estado == JUGADOR_VS_AI || estado == JAQUEBLANCO || estado == JAQUENEGRO) {
		ajedrez.JUEGO(button, state, x, y);
	}
	jaque();
}

void Mundo::jaque()
{
	if (estado == JUEGO_BABY || estado == JUEGO_GARDNER || estado == JUGADOR_VS_AI || estado == JAQUEBLANCO || estado == JAQUENEGRO) {
		int resultadoJaque = ajedrez.jaque();
		if (resultadoJaque == 1) {
			estadoanterior = estado;
			estado = JAQUEBLANCO;
			jaqueBlanco = true;
		}
		else if (resultadoJaque == 2) {
			  estadoanterior = estado; 
			estado = JAQUENEGRO;
			jaqueNegro = true;
		}
		else if (resultadoJaque == 3 || resultadoJaque == 4) {
			estado = FIN;
		}
		else if (estado == JAQUEBLANCO || estado == JAQUENEGRO) {
			if (ajedrez.jaque() == 0) {
				jaqueNegro = false;
				jaqueBlanco = false;
				estado = estadoanterior;
			}
			else if (ajedrez.jaque() == 3 || ajedrez.jaque() == 4) { estado = FIN; }
		}
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





