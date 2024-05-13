
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

Casilla Ajedrez::getCasilla(int x, int y) //Devuelve la casilla en función de las coordenadas x,y del ratón
{
	Casilla casilla; 
	casilla.c=  floor((x - 226) / 70); //Obtenido experimentalmente para el tama?o de ventana del juego
	casilla.f = 4 - floor((y - 126) / 70);
	return casilla;
}

int Ajedrez::JUEGO(int button, int state, int x, int y)
{
	// 日志：鼠标事件接收
	std::cout << "Evento del RATON recibido - Botón: " << button << ", ESTADO: " << state << ", x: " << x << ", y: " << y << std::endl;
	if (origen.f == HOME && origen.c == HOME) { //Si no hay origen seleccionado, se slecciona uno

		origen = getCasilla(x, y);
		std::cout << "Origen seleccionado - f: " << origen.f << ", c: " << origen.c << std::endl; // 日志：选定起始位置
		if (!verificarturno(tablero.getColor(origen))) { //Si no es el turno o se pulsa una casilla vacía se borra el origen

			origen.f = origen.c = HOME;
			std::cout << "Origen no válido debido a turno o casilla vacía" << std::endl; // 日志：无效起始位置
			return 0;
		}
		tablero.PosiblesMovimientos(origen); //Muestra los posibles movimiento de la pieza seleccionada
		tablero.resaltarMovimientosLegales(origen);
	}
	else if (origen.f != HOME && origen.c != HOME && destino.f == HOME && destino.c == HOME) {	//Si ya está guarado el origen
		//slecciona el destino
		destino = getCasilla(x, y);
		std::cout << "Destino seleccionado - f: " << destino.f << ", c: " << destino.c << std::endl; // 日志：选定目标位置


		if (destino == origen) { //Si el origen es igual al destino, se borra el origen y el destino

			origen.f = origen.c = destino.f = destino.c = HOME;
			tablero.limpiarDestacados();
			tablero.setMovInicial(); //Borra la matriz de ayuda el movimeinto
			std::cout << "El origen y el destino son los mismos. Reiniciando." << std::endl; // 日志：起始和目标位置相同
			return 0;

		}
		else if (!tablero.validarMovimiento(origen, destino)) {//Si el movimiento no es válido borra el destino

			destino.f = destino.c = HOME;
			std::cout << "Movimiento no válido. Restablecer destino." << std::endl; // 日志：无效移动
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

