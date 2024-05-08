#pragma once
#include "freeglut.h"
#include "ostream"
#include <math.h>

class Casilla
{
public:
	int f; //fila (1,...,5)
	int c; //columna (a,..,e )

	//constructor
	Casilla(int x = -1, int y = -1);
	//DESTRUCTOR
	Casilla(const Casilla& cas);
	~Casilla();

	// argumento y modulo
	inline double modulo() const { return std::sqrt(f * f + c * c); } // modulo del vector
	inline double argumento() const { return std::atan2(f, c); } // argumento del vector

	inline Casilla unitario() const {
		double mod = modulo();
		if (mod > 0.00001) {
			//  static_cast<int>() 
			return { static_cast<int>(f / mod), static_cast<int>(c / mod) };
		}
		return { f, c };
	} //devuelve un vector unitario

	// Sobrecarga de operadores
	inline Casilla operator-(const Casilla& v) const {
		return { f - v.f, c - v.c };
	} // resta de vectores

	inline Casilla operator+(const Casilla& v) const {
		return { f + v.f, c + v.c };
	} // suma de vectores

	inline double operator*(const Casilla& v) const {
		return (f * v.f + c * v.c);
	} // producto escalar

	inline Casilla operator*(double num) const {
		
		return { static_cast<int>(f * num), static_cast<int>(c * num) };
	} // producto por un escalar

	inline Casilla operator/(double num) const {
		
		return { static_cast<int>(f / num), static_cast<int>(c / num) };
	} // divisi¨®n por un escalar


	friend class Pieza;
	friend class Tablero;
	friend class Ajedrez;
};
