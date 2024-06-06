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
	static const int n = 5;
	std::vector<std::vector<Pieza*>> casillas; // Representaci¨®n del tablero
   // Pieza** PIE; //PIE es una matriz de piezas
	int** mov; //matriz auxiliar para implementar la ayuda al movimiento
	//bool necesitoRedibujo[5][5];

public:
	Tablero();
	~Tablero();

	//grafico
	void dibuja();
	void colocarPiezasIniciales(int fila, Color color, std::vector<Tipo> piezas);
	//void dibujarPiezas();

	void posicionarPeones(int fila, Color color);

	void vaciarFila(int fila);

	//logico
	void posicionInicial(bool est);
	int getColor(Casilla& cas); // Obtener el color de la pieza de ajedrez en una posicion determinada.
    bool validarMovimiento(const Casilla& origen, const Casilla& destino);
	void actualizarMovimiento(Casilla& origen, Casilla& destino);
	int PosiblesMovimientos(Casilla& origen);
	void setMovInicial();
	void resaltarMovimientosLegales(const Casilla& origen);
	void limpiarDestacados();

};