#include "Casilla.h"

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
