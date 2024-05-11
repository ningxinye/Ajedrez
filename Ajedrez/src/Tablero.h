#pragma once
#include <iostream>
#include <vector>
#include"Pieza.h"
#include "freeglut.h"

//esta clase funciona como una matriz auxiliar de piezas
//para implementar la ayuada al movimiento
class Tablero
{
private:
	const int n = 5;
	std::vector<std::vector<Pieza*>> casillas; // Representaci¨®n del tablero
//	Pieza** tabla; //Tablero es una matriz de piezas

public:
	Tablero();
	~Tablero();

	//gr¨¢fico
	void dibuja();
	//void dibujarPiezas();

	//logico
	void posicionInicial();
	Pieza* obtenerPiezaEnPosicion(int fila, int col) const;
	bool validarMovimiento(Casilla origen, Casilla destino);
	bool moverPieza(Pieza* pieza, const Casilla& origen, const Casilla& destino);
	// Verifica si una casilla est¨¢ dentro del tablero
	bool estaDentroDelTablero(const Casilla& casilla) const;
	// Verifica si una pieza puede moverse desde la casilla de origen a la de destino
	bool puedeMoverse(Pieza* pieza, const Casilla& origen, const Casilla& destino);
	Color getColor(Casilla cas); // Obtener el color de la pieza de ajedrez en una posici¨®n determinada.
	void mostrarPosiblesMovimientos(Casilla cas);
	void resetearAyudaMovimiento();


	/*
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

	// M¨¦todos para mostrar el tablero, realizar movimientos, etc.
	void mostrar() const {
		// Implementaci¨®n para mostrar el tablero en la consola
	}
	*/
};