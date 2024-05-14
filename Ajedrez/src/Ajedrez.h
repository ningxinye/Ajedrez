#pragma once
#include "Tablero.h"
#include "freeglut.h"
#define INVALID_POS -10 //Valor arbitrario de inicio de las casillas de origen y destino

//para gestionar el juego, por lo tanto, hace falta organizar dos cosas:
//gr��fico del juego y l��gico del juego

class Ajedrez
{
private:
	Tablero tablero;
	int turno = Blanca;// gestion de turno con valor inicial 0
	//INVALID_POS:Estado no inicializado,Esto es particularmente ��til cuando se manejan interacciones del usuario (como clics del mouse en un tablero de ajedrez),
	//  ya que puede verificar f��cilmente si Casilla todav��a est�� en este estado de inicializaci��n y, por lo tanto, si el usuario ha seleccionado una posici��n inicial o de destino v��lida.
	Casilla origen{ INVALID_POS, INVALID_POS };  //Casilla de origen para la implementaci��n del movimeinto por rat��n
	Casilla destino{ INVALID_POS, INVALID_POS };  //Casilla de destsino para la implementaci��n del movimiento por rat��n

public:
	Ajedrez();
	//gr��fica
	void dibuja();
	void inicializa();
	//l��gico
	bool verificarturno(int color);
	int JUEGO(int button, int state, int x, int y);	//Coordina los diferentes m��todos de tablero para gestionar una jugada
	void setTurno(int v);
	int getTurno(){ return turno; }

};
