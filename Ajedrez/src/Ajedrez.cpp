
#include "Ajedrez.h"

using namespace std;


Ajedrez::Ajedrez()
{
}

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
	tablero.setMovInicial();
	
}

bool Ajedrez::verificarturno(int color)
{
	std::cout << "Verificando turno. Turno actual: " << turno << ", Color de pieza: " << color << std::endl;
	if ((turno % 2 == 0 && color != Negra) || (turno % 2 == 1 && color != Blanca)) {
		std::cout << "Volverse incorrecto o color de la pieza incorrecta." << std::endl;
		return false;
	}
	return true;
}

Casilla Ajedrez::getCasilla(int x, int y) //Devuelve la casilla en funci��n de las coordenadas x,y del rat��n
{
	Casilla casilla; 
	casilla.c=  floor((x - 226) / 70); //Obtenido experimentalmente para el tama?o de ventana del juego
	casilla.f = 4 - floor((y - 126) / 70);
	return casilla;
}

int Ajedrez::JUEGO(int button, int state, int x, int y)
{
	// ��־������¼�����
	std::cout << "Evento del RATON recibido - Bot��n: " << button << ", ESTADO: " << state << ", x: " << x << ", y: " << y << std::endl;
	if (origen.f == HOME && origen.c == HOME) { //Si no hay origen seleccionado, se slecciona uno

		origen = getCasilla(x, y);
		std::cout << "Origen seleccionado - f: " << origen.f << ", c: " << origen.c << std::endl; // ��־��ѡ����ʼλ��
		if (!verificarturno(tablero.getColor(origen))) { //Si no es el turno o se pulsa una casilla vac��a se borra el origen

			origen.f = origen.c = HOME;
			std::cout << "Origen no v��lido debido a turno o casilla vac��a" << std::endl; // ��־����Ч��ʼλ��
			return 0;
		}
		tablero.PosiblesMovimientos(origen); //Muestra los posibles movimiento de la pieza seleccionada
		tablero.resaltarMovimientosLegales(origen);
	}
	else if (origen.f != HOME && origen.c != HOME && destino.f == HOME && destino.c == HOME) {	//Si ya est�� guarado el origen
		//slecciona el destino
		destino = getCasilla(x, y);
		std::cout << "Destino seleccionado - f: " << destino.f << ", c: " << destino.c << std::endl; // ��־��ѡ��Ŀ��λ��


		if (destino == origen) { //Si el origen es igual al destino, se borra el origen y el destino

			origen.f = origen.c = destino.f = destino.c = HOME;
			tablero.limpiarDestacados();
			tablero.setMovInicial(); //Borra la matriz de ayuda el movimeinto
			std::cout << "El origen y el destino son los mismos. Reiniciando." << std::endl; // ��־����ʼ��Ŀ��λ����ͬ
			return 0;

		}
		else if (!tablero.validarMovimiento(origen, destino)) {//Si el movimiento no es v��lido borra el destino

			destino.f = destino.c = HOME;
			std::cout << "Movimiento no v��lido. Restablecer destino." << std::endl; // ��־����Ч�ƶ�
			return 0;

		}

		else if ((tablero.validarEnroque(origen, destino) != 0) && tablero.validarMovimiento(origen, destino)) {		//Si se dan condiciones de enroque y no hay piezas en medio 

			turno++; //Se completa el movimiento y se aumenta el turno
			origen.f = origen.c = destino.f = destino.c = HOME; //Se borran origen y destino
			tablero.limpiarDestacados();
			tablero.setMovInicial();
	
			return 0;

		}
		else { //Se valida el movimiento y no es enroque

			tablero.actualizarMovimiento(origen, destino);						//Atualiza la matriz del tablero
			turno++;												//Aumenta el turno
			origen.f = origen.c = destino.f = destino.c = HOME;		//Resetea las casillas de origen y destino
			tablero.limpiarDestacados();
			tablero.setMovInicial();									//Resetea la matriz de ayuda al movimiento

			}

		}
	
	if (turno > 9) 
	{
		turno = 0;
	}
	return 0;
}

void Ajedrez::setTurno(int v)
{
	turno = v;
}

