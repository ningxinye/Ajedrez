#include "Ajedrez.h"

using namespace std;

void Ajedrez::dibuja()
{
	gluLookAt(4, 4, 12,  // posicion del ojo
		4, 4, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
	tablero.dibuja();
	tablero.posicionInicial();

}

void Ajedrez::inicializa()
{
}