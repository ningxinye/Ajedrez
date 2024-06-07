#pragma once
#include "Ajedrez.h"
#include <ctime>

//desde archivo Mundo, implementamos una sensilla m��quina de estado 
class Mundo
{
private:
	Ajedrez ajedrez;
	//estados de la m��quina
	enum Estados { INICIO, SELECCIONAR, JUEGO_BABY, JUEGO_GARDNER, JUGADOR_VS_AI, JAQUEBLANCO, JAQUENEGRO, FIN, PAUSA, TIEMPO_LIM };
	Estados estado;
	Estados estadoanterior;

	bool jaqueBlanco = false;			//Auxiliares para las transiciones entre estados
	bool jaqueNegro = false;
	// Variables para el temporizador
	time_t startTime;
	int countdownTime; // En segundos

public:
	Mundo();
	~Mundo();

	std::string nueva_musica;
	std::string musica_actual;

	void dibuja();
	void tecla(unsigned char key);
	
	void musica();
	void JUEGA(int button, int state, int x, int y); //jugar con raton
	void jaque();
	void iniciarContador(int segundos); // Inicializar el temporizador
	int obtenerTiempoRestante(); // Obtener el tiempo restante

};