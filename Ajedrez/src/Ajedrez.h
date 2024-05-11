#pragma once
#include "Tablero.h"
#include "freeglut.h"
//para gestionar el juego, por lo tanto, hace falta organizar dos cosas:
//gr��fico del juego y l��gico del juego
class Ajedrez
{
private:
	Tablero tablero;
	Color turno;
	bool piezaSeleccionada; // Seguimiento de si una pieza ha sido seleccionada
	Casilla origen;         // Almacenar la posici��n inicial
	Casilla destino;        // destino de almacenamiento

public:
	Ajedrez();

	//gr��fica
	void dibuja();
	void inicializa();

	//l��gico
	Color getTurno()const;
	// Devuelve una referencia constante al tablero
	const Tablero& getTablero() const;
	// Devuelve una referencia no constante al tablero
	Tablero& getTablero();
	// Declaraci��n de la nueva funci��n para interaccion entre el raton y jueg0
	void jugada(int col, int fila);

};
