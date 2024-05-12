#pragma once
#include "Tablero.h"
#include "freeglut.h"
#define HOME -10 //Valor arbitrario de inicio de las casillas de origen y destino

//para gestionar el juego, por lo tanto, hace falta organizar dos cosas:
//gr芍fico del juego y l車gico del juego

class Ajedrez
{
private:
	Tablero tablero;
	int turno = Blanca;// gestion de turno con valor inicial 0
	//HOME:Estado no inicializado,Esto es particularmente 迆til cuando se manejan interacciones del usuario (como clics del mouse en un tablero de ajedrez),
	//  ya que puede verificar f芍cilmente si Casilla todav赤a est芍 en este estado de inicializaci車n y, por lo tanto, si el usuario ha seleccionado una posici車n inicial o de destino v芍lida.
	Casilla origen{ HOME, HOME };  //Casilla de origen para la implementaci車n del movimeinto por rat車n
	Casilla destino{ HOME, HOME };  //Casilla de destsino para la implementaci車n del movimiento por rat車n

public:
	Ajedrez();
	//gr芍fica
	void dibuja();
	void inicializa();
	//l車gico
	bool verificarturno(int color);
	Casilla getCasilla(int x, int y);//Casilla en la que se pincha, aqui pongo la relacion entre la ventana fisica con la casilla logica
	int JUEGO(int button, int state, int x, int y);	//Coordina los diferentes m谷todos de tablero para gestionar una jugada
	void setTurno(int v);
	int getTurno(){ return turno; }

};
