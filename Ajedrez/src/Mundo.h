#pragma once
#include"Ajedrez.h"

//desde archivo mundo, implementamos una sensilla m¨¢quina de estado 

class Mundo
{
private:
	Ajedrez ajedrez;
	enum Estados{INICIO, JUEGO, FIN, PAUSA};
	Estados estado;


public: 
	Mundo();
	~Mundo();

	void tecla(unsigned char key);
	void dibuja();
	

};
