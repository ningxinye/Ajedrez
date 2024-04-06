#include "Mundo.h"
#include"ETSIDI.h"
#include "freeglut.h"
#include <math.h>

Mundo::Mundo()
{
	estado = INICIO;
}

Mundo::~Mundo()
{
}



void Mundo::dibuja()
{
	gluLookAt(0, 7.5, 30,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f,0,5.0f);	
		glVertex3f(5.0f,0,-5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}



void Mundo::tecla(unsigned char key)
{

}
