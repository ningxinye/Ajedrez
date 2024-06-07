
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

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/ETSIDI.png").id);
    glDisable(GL_LIGHTING);

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 1);    glVertex3f(-14.5f, -3.5f, 0.0f); //esquina inferior izquierda
    glTexCoord2d(1, 1);    glVertex3f(14.5f, -3.5f, 0.0f);
    glTexCoord2d(1, 0);    glVertex3f(14.5f, 18.5f, 0.0f);
    glTexCoord2d(0, 0);    glVertex3f(-14.5f, 18.5f, 0.0f); //esquina superior izquierda
    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Ajedrez::inicializa(bool est, bool vsAI)
{
    this->vsAI = vsAI; // Establecer el modo de juego_ai simple
    tablero.posicionInicial(est);
    tablero.setMovInicial();
    turno = Blanca; // Asegurar que el turno inicial sea de las blancas
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
    if (state != GLUT_DOWN) return 0; // Solo manejar eventos cuando se presiona el boton

    cout << "Evento del raton recibido - Boton: " << button << ", Estado: " << state << ", x: " << x << ", y: " << y << endl;
    auto getCasilla = [](int x, int y) -> Casilla {
        Casilla casilla;
        casilla.c = static_cast<int>((x - 226) / 70);
        casilla.f = 4 - static_cast<int>((y - 126) / 70);
        return casilla;
        };

    if (origen.f == INVALID_POS && origen.c == INVALID_POS) {
        origen = getCasilla(x, y);
        cout << "Origen seleccionado - f: " << origen.f << ", c: " << origen.c << endl;

        if (!verificarturno(tablero.getColor(origen))) {
            origen.f = origen.c = INVALID_POS;
            cout << "Origen no valido debido a turno o casilla vacia" << endl;
            return 0;
        }

        tablero.PosiblesMovimientos(origen);
        tablero.resaltarMovimientosLegales(origen);
    }
    else if (origen.f != INVALID_POS && origen.c != INVALID_POS && destino.f == INVALID_POS && destino.c == INVALID_POS) {
        destino = getCasilla(x, y);
        cout << "Destino seleccionado - f: " << destino.f << ", c: " << destino.c << endl;

        if (destino == origen) {
            origen.f = origen.c = destino.f = destino.c = INVALID_POS;
            tablero.limpiarDestacados();
            tablero.setMovInicial();
            cout << "El origen y el destino son los mismos. Reiniciando." << endl;
            return 0;
        }
        else if (!tablero.validarMovimiento(origen, destino)) {
            destino.f = destino.c = INVALID_POS;
            cout << "Movimiento no valido. Restablecer destino." << endl;
            return 0;
        }
        else {
            tablero.actualizarMovimiento(origen, destino);
            turno = (turno == Blanca) ? Negra : Blanca; // Cambiar el turno
            origen.f = origen.c = destino.f = destino.c = INVALID_POS;
            tablero.limpiarDestacados();
            tablero.setMovInicial();

            // Si es el turno de la IA, hacer el movimiento de la IA
            if (vsAI && turno == Negra) {
                jugarAI();
                turno = Blanca; // Cambiar el turno de vuelta a las blancas despues de que la IA haga su movimiento
            }
        }
    }

    return 0;
}

void Ajedrez::setTurno(int v)
{
    turno = v;
}

void Ajedrez::jugarAI()
{
    ai.realizarMovimiento(tablero, Negra);

}

int Ajedrez::jaque()
{
    return tablero.jaque(turno);
}

Tablero& Ajedrez::obtenerTablero()
{
    return tablero;
}
