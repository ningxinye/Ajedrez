#pragma once
#include "freeglut.h"

class Casilla
{
public:
	int f; //fila (1,...,5)
	int c; //columna (a,..,e )

	//constructor
	Casilla(int x = -1, int y = -1);

	friend class Pieza;
	friend class Tablero;
	friend class Ajedrez;
};
