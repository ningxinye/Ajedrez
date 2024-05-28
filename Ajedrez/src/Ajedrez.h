#pragma once
#include "Tablero.h"
#include "freeglut.h"
#define INVALID_POS -10 //Valor arbitrario de inicio de las casillas de origen y destino

//para gestionar el juego, por lo tanto, hace falta organizar dos cosas:
//grafico del juego y l¨®gico del juego

class Ajedrez
{
private:
	Tablero tablero;
	int turno = Blanca;// gestion de turno con valor inicial 0
	//INVALID_POS:Estado no inicializado,Esto es particularmente util cuando se manejan interacciones del usuario (como clics del mouse en un tablero de ajedrez),
	//  ya que puede verificar facilmente si Casilla todavia esta en este estado de inicializacion y, por lo tanto, si el usuario ha seleccionado una posici¨®n inicial o de destino v¨¢lida.
	Casilla origen{ INVALID_POS, INVALID_POS };  //Casilla de origen para la implementacion del movimeinto por raton
	Casilla destino{ INVALID_POS, INVALID_POS };  //Casilla de destsino para la implementacion del movimiento por raton

public:
	Ajedrez();
	//grafica
	void dibuja();
	void inicializa(bool est);
	//logica
	bool verificarturno(int color);
	int JUEGO(int button, int state, int x, int y);	//Coordina los diferentes metodos de tablero para gestionar una jugada
	void setTurno(int v);
	int getTurno(){ return turno; }

};
