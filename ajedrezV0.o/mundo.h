#pragma once
using byte = unsigned char;

class Mundo
{
	double xojo, yojo, zojo;

public:
	void inicializa();
	void dibuja();
	void mueve();
	void tecla(byte);
};