#pragma once
#include "Ajedrez.h"

//desde archivo Mundo, implementamos una sensilla m��quina de estado 

class Mundo
{
private:
	Ajedrez ajedrez;
	//estados de la m��quina
	enum Estados { INICIO, JUEGO_BABY, JUEGO_GARDNER, FIN, PAUSA };
	Estados estado;


public:
	Mundo();
	~Mundo();

	void dibuja(); //pantalla
	void tecla(unsigned char key);

	//metodos logicos
	void pulsar_raton(int button, int state, int x, int y);

};