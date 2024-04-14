
#include "Pieza.h"

Pieza::Pieza()
{
}

Pieza::~Pieza()
{
}

//pintando cada pieza
void Pieza::dibuja()
{
    glDisable(GL_LIGHTING);
    // Habilitar el uso de texturas
    glEnable(GL_TEXTURE_2D);



    // Seleccionar la textura adecuada seg¨²n el tipo y color de la pieza
    const char* rutaImagen = nullptr;
    switch (tipo)
    {
    case No_pieza:
        // No hay pieza, no se dibuja nada
        return;
    case Peon:
        rutaImagen = (color == Negra) ? "bin/imagenes/peon_negro.png" : "bin/imagenes/peon_blanco.png";
        break;
    case Caballo:
        rutaImagen = (color == Negra) ? "bin/imagenes/caballo_negro.png" : "imagenes/caballo_blanco.png";
        break;
    case Alfil:
        rutaImagen = (color == Negra) ? "imagenes/alfil_negro.png" : "imagenes/alfil_blanco.png";
        break;
    case Torre:
        rutaImagen = (color == Negra) ? "imagenes/torre_negro.png" : "imagenes/torre_blanco.png";
        break;
    case Rey:
        rutaImagen = (color == Negra) ? "imagenes/rey_negro.png" : "imagenes/rey_blanco.png";
        break;
    case Reina:
        rutaImagen = (color == Negra) ? "imagenes/reina_negro.png" : "imagenes/reina_blanco.png";
        break;

    }

    // Seleccionar la textura seg¨²n la ruta de la imagen
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(rutaImagen).id);

    // Especificar coordenadas de textura y v¨¦rtices para la pieza
    glBegin(GL_POLYGON);
    // Esquina superior izquierda
    glTexCoord2d(0, 0);
    glVertex3f(static_cast<GLfloat>(casilla.c + 1), static_cast<GLfloat>(casilla.f + 1), 0.0f);
    // Esquina superior derecha
    glTexCoord2d(1, 0);
    glVertex3f(static_cast<GLfloat>(casilla.c), static_cast<GLfloat>(casilla.f + 1), 0.0f);
    // Esquina inferior derecha
    glTexCoord2d(1, 1);
    glVertex3f(static_cast<GLfloat>(casilla.c), static_cast<GLfloat>(casilla.f), 0.0f);
    // Esquina inferior izquierda
    glTexCoord2d(0, 1);
    glVertex3f(static_cast<GLfloat>(casilla.c + 1), static_cast<GLfloat>(casilla.f), 0.0f);
    glEnd(); 
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
 

}

Pieza::Pieza(const Pieza& p)
{
    //par¨¢metro constante
    tipo = p.tipo;
    color = p.color;
    casilla = p.casilla;
    fila = p.fila;
    col = p.col;

}
