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

	//jaque y sus funciones auxiliares

	//Busca la posición del rey en el tablero según su color.
	Casilla encontrarRey(Color color);
	//Verifica si el rey de un color específico está en jaque.
	bool estaEnJaque(Color color);
	// Verifica si el rey puede escapar del jaque moviéndose a una posición segura, capturando la pieza enemiga o bloqueando el ataque.
	bool puedeEscaparDeJaque(Color color);
	//Verifica si una posición específica está bajo amenaza de piezas enemigas.
	bool estaAmenazado(const Casilla& pos, Color colorEnemigo);
	//Determina si el rey está en jaque o jaque mate y retorna un valor basado en el estado actual del juego.
	int jaque(int turn);

	bool reyExiste(Color color);

};