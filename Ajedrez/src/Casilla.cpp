#include "Casilla.h"
#include <cmath>


Casilla::Casilla(int x, int y)
{
	f = x;
	c = y;
}

Casilla::Casilla(const Casilla& cas)
{
	f = cas.f;
	c = cas.c;
}

Casilla::~Casilla()
{
}

bool Casilla::operator==(const Casilla& other) const
{
	return f == other.f && c == other.c;
}

Casilla Casilla::operator-(const Casilla& v) const
{
	return { f - v.f, c - v.c };
}

Casilla Casilla::operator+(const Casilla& v) const
{
	return { f + v.f, c + v.c };
}

double Casilla::operator*(const Casilla& v) const
{
	return f * v.f + c * v.c;
}

Casilla Casilla::operator*(double num) const
{
	return { static_cast<int>(f * num), static_cast<int>(c * num) };
}

Casilla Casilla::operator/(double num) const
{
	return { static_cast<int>(f / num), static_cast<int>(c / num) };

}

double Casilla::modulo() const
{
	 return std::sqrt(f * f + c * c); 
}

double Casilla::argumento() const
{
	return atan2(static_cast<double>(f), static_cast<double>(c));
}

