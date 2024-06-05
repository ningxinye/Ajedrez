#pragma once
#include "Ajedrez.h"
#include <ctime>

//desde archivo Mundo, implementamos una sensilla m¨¢quina de estado 
class Mundo
{
private:
	Ajedrez ajedrez;
	//estados de la m¨¢quina
	enum Estados { INICIO, JUEGO_BABY, JUEGO_GARDNER, JUGADOR_VS_AI, FIN, PAUSA, TIEMPO_LIM};
	Estados estado;


	// Variables para el temporizador
	time_t startTime;
	int countdownTime; // En segundos

public:
	Mundo();
	~Mundo();

	void dibuja(); //pantalla
	void tecla(unsigned char key);
	//MOMENTOS QUE PUEDEN JUGAR CON EL RATON
	void JUEGA(int button, int state, int x, int y);

	void iniciarContador(int segundos); // Inicializar el temporizador
	int obtenerTiempoRestante(); // Obtener el tiempo restante

};