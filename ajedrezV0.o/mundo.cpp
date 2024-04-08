#include "mundo.h"
#include "freeglut.h"
#include <cmath>

void Mundo::inicializa() {

	xojo = 20;
	yojo = 20;
	zojo = 20;
}

void Mundo::dibuja() {
	gluLookAt(xojo, yojo, zojo,// posicion del ojo
		0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

}

void Mundo::mueve()
{

	auto d = sqrt(xojo * xojo + zojo * zojo);
	auto theta = atan2(zojo, xojo);
	theta += 0.1;

	xojo = d * cos(theta);
	zojo = d * sin(theta);
}

void Mundo::tecla(byte key)
{
	
}