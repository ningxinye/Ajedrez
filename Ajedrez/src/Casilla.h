#pragma once
#include "freeglut.h"
#include "ostream"
#include <math.h>

class Casilla
{
public:
	int f; // fila
	int c; // columna

	Casilla(int x = -1, int y = -1);  // declarar constructor
	Casilla(const Casilla& cas);
	~Casilla();	//DESTRUCTOR

	//Sobrecarga de operadores
	bool operator==(const Casilla& other) const;// La sobrecarga del operador de comparaci¨®n tambi¨¦n solo declara
	Casilla operator-(const Casilla& v) const; // resta de vectores
	Casilla operator+(const Casilla& v) const; // suma de vectores
	double operator*(const Casilla& v) const; // producto escalar
	Casilla operator*(double num) const; // producto por un escalar
	Casilla operator/(double num) const; // divisi¨®n por un escalar

	
	//Operaciones vectoriales // argumento y modulo
	double modulo() const;// modulo del vector
	double argumento() const; // argumento del vector


	


	friend class Pieza;
	friend class Tablero;
	friend class Ajedrez;
};
