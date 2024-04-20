
#include "Ajedrez.h"

using namespace std;

void Ajedrez::dibuja()
{
	gluLookAt(2.5, 2.5, 12,  // posicion del ojo
		2.5, 2.5, 0.0,    // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
	
	tablero.dibuja();


}

void Ajedrez::inicializa()
{
	tablero.posicionInicial();
	//soy irene

}