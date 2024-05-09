#pragma once
#include "Tablero.h"
#include "freeglut.h"
//para gestionar el juego, por lo tanto, hace falta organizar dos cosas:
//gr¨¢fico del juego y l¨®gico del juego
class Ajedrez
{
private:
	Tablero tablero;
	Color turno;


public:


	//gr¨¢fica
	void dibuja();
	void inicializa();

	//l¨®gico
	Color getTurno()const;


	// Devuelve una referencia constante al tablero
	const Tablero& getTablero() const {
		return tablero;
	}

};
