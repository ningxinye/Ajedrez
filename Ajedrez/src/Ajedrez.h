#pragma once
#include "Tablero.h"
#include "freeglut.h"
#define HOME -10 //Valor arbitrario de inicio de las casillas de origen y destino

//para gestionar el juego, por lo tanto, hace falta organizar dos cosas:
//gr��fico del juego y l��gico del juego

class Ajedrez
{
private:
	Tablero tablero;
	int turno = Blanca;// gestion de turno con valor inicial 0
	//HOME:Estado no inicializado,Esto es particularmente ��til cuando se manejan interacciones del usuario (como clics del mouse en un tablero de ajedrez),
	//  ya que puede verificar f��cilmente si Casilla todav��a est�� en este estado de inicializaci��n y, por lo tanto, si el usuario ha seleccionado una posici��n inicial o de destino v��lida.
	Casilla origen{ HOME, HOME };  //Casilla de origen para la implementaci��n del movimeinto por rat��n
	Casilla destino{ HOME, HOME };  //Casilla de destsino para la implementaci��n del movimiento por rat��n

public:
	Ajedrez();
	//gr��fica
	void dibuja();
	void inicializa();
	//l��gico
	bool verificarturno(int color);
	Casilla getCasilla(int x, int y);//Casilla en la que se pincha, aqui pongo la relacion entre la ventana fisica con la casilla logica
	int JUEGO(int button, int state, int x, int y);	//Coordina los diferentes m��todos de tablero para gestionar una jugada
	void setTurno(int v);
	int getTurno(){ return turno; }

};
