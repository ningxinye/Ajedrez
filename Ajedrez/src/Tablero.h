<<<<<<< Updated upstream:Ajedrez/Tablero.h
#pragma once

#pragma once
#include <iostream>
#include"Pieza.h"
#include "freeglut.h"

//esta clase funciona como una matriz auxiliar de piezas
//para implementar la ayuada al movimiento
class Tablero
{
private:
	const int n = 5;
	std::vector<std::vector<Pieza*>> casillas; // Representaci¨®n del tablero
	Pieza** tabla; //Tablero es una matriz de piezas

public:
	Tablero();
	~Tablero();

	// M¨¦todos para mostrar el tablero, realizar movimientos, etc.
	void mostrar() const {
		// Implementaci¨®n para mostrar el tablero en la consola
	}

	Pieza* obtenerPiezaEnPosicion(int fila, int col) const {
		return casillas[fila][col];
	}

	// M¨¦todo para comprobar si una casilla est¨¢ ocupada por una pieza
	bool estaOcupada(int fila, int col) const {
		return casillas[fila][col] != nullptr;
	}

	// M¨¦todo para comprobar si una casilla est¨¢ ocupada por una pieza de un color espec¨ªfico
	bool estaOcupadaPorColor(int fila, int col, Pieza color) const {
		if (casillas[fila][col] != nullptr) {

			return casillas[fila][col]->getColor();
		}
		return false;
	}

	//gr¨¢fico
	void dibuja();
	void dibujarPiezas();

	//logico
	void posicionInicial();
=======
#pragma once

#pragma once
#include <iostream>
#include"Pieza.h"
#include "freeglut.h"

//esta clase funciona como una matriz auxiliar de piezas
//para implementar la ayuada al movimiento
class Tablero
{
private:
	const int n = 5;
	std::vector<std::vector<Pieza*>> casillas; // Representaci¨®n del tablero

public:
	Tablero();
	~Tablero();

	// M¨¦todos para mostrar el tablero, realizar movimientos, etc.
	void mostrar() const {
		// Implementaci¨®n para mostrar el tablero en la consola
	}

	Pieza* obtenerPiezaEnPosicion(int fila, int col) const {
		return casillas[fila][col];
	}

	// M¨¦todo para comprobar si una casilla est¨¢ ocupada por una pieza
	bool estaOcupada(int fila, int col) const {
		return casillas[fila][col] != nullptr;
	}

	// M¨¦todo para comprobar si una casilla est¨¢ ocupada por una pieza de un color espec¨ªfico
	bool estaOcupadaPorColor(int fila, int col, Pieza color) const {
		if (casillas[fila][col] != nullptr) {

			return casillas[fila][col]->getColor();
		}
		return false;
	}

	//gr¨¢fico
	void dibuja();
	void posicionInicial();



	//logico
>>>>>>> Stashed changes:Ajedrez/src/Tablero.h
};