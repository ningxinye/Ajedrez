
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



int Ajedrez::JUEGO(int button, int state, int x, int y) {
    // Log: Recepci車n de evento de rat車n
    std::cout << "Evento del rat車n recibido - Bot車n: " << button << ", Estado: " << state << ", x: " << x << ", y: " << y << std::endl;

    // Funci車n interna para obtener la casilla en funci車n de las coordenadas del rat車n
    auto getCasilla = [](int x, int y) -> Casilla {
        Casilla casilla;
        casilla.c = static_cast<int>((x - 226) / 70); // Obtenido experimentalmente para el tama?o de ventana del juego
        casilla.f = 4 - static_cast<int>((y - 126) / 70);
        return casilla;
        };

    if (origen.f == INVALID_POS && origen.c == INVALID_POS) { // Si no hay origen seleccionado, se selecciona uno
        origen = getCasilla(x, y);
        std::cout << "Origen seleccionado - f: " << origen.f << ", c: " << origen.c << std::endl; // Log: selecci車n de origen

        if (!verificarturno(tablero.getColor(origen))) { // Si no es el turno o se pulsa una casilla vac赤a se borra el origen
            origen.f = origen.c = INVALID_POS;
            std::cout << "Origen no v芍lido debido a turno o casilla vac赤a" << std::endl; // Log: origen no v芍lido
            return 0;
        }

        tablero.PosiblesMovimientos(origen); // Muestra los posibles movimientos de la pieza seleccionada
        tablero.resaltarMovimientosLegales(origen);
    }
    else if (origen.f != INVALID_POS && origen.c != INVALID_POS && destino.f == INVALID_POS && destino.c == INVALID_POS) { // Si ya est芍 guardado el origen
        destino = getCasilla(x, y); // Se selecciona el destino
        std::cout << "Destino seleccionado - f: " << destino.f << ", c: " << destino.c << std::endl; // Log: selecci車n de destino

        if (destino == origen) { // Si el origen es igual al destino, se borra el origen y el destino
            origen.f = origen.c = destino.f = destino.c = INVALID_POS;
            tablero.limpiarDestacados();
            tablero.setMovInicial(); // Borra la matriz de ayuda al movimiento
            std::cout << "El origen y el destino son los mismos. Reiniciando." << std::endl; // Log: origen y destino son iguales
            return 0;
        }
        else if (!tablero.validarMovimiento(origen, destino)) { // Si el movimiento no es v芍lido borra el destino
            destino.f = destino.c = INVALID_POS;
            std::cout << "Movimiento no v芍lido. Restablecer destino." << std::endl; // Log: movimiento no v芍lido
            return 0;
        }
        else if (tablero.validarEnroque(origen, destino) && tablero.validarMovimiento(origen, destino)) { // Si se dan condiciones de enroque y no hay piezas en medio
            turno++; // Se completa el movimiento y se aumenta el turno
            origen.f = origen.c = destino.f = destino.c = INVALID_POS; // Se borran origen y destino
            tablero.limpiarDestacados();
            tablero.setMovInicial();
            return 0;
        }
        else { // Se valida el movimiento y no es enroque
            tablero.actualizarMovimiento(origen, destino); // Actualiza la matriz del tablero
            turno++; // Aumenta el turno
            origen.f = origen.c = destino.f = destino.c = INVALID_POS; // Resetea las casillas de origen y destino
            tablero.limpiarDestacados();
            tablero.setMovInicial(); // Resetea la matriz de ayuda al movimiento
        }
    }

    if (turno > 9) {
        turno = 0;
    }
    return 0;
}

void Ajedrez::setTurno(int v)
{
	turno = v;
}

