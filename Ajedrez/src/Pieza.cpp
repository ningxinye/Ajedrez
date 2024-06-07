
#include "Pieza.h"
#include <iostream>
#include <filesystem>

Pieza::Pieza()
{
    movida = 0;
}

Pieza::~Pieza()
{
}

//pintando cada pieza
void Pieza::dibuja(int AUX, int auxmov)
{
    //std::cout << "Dibujando pieza: Tipo " << tipo << ", Color " << color << " en la casilla (" << casilla.f << ", " << casilla.c << ")\n";

    // Habilitar el uso de texturas
    glEnable(GL_TEXTURE_2D);

    // Seleccionar la textura adecuada seg¨²n el tipo y color de la pieza
    const char* rutaImagen = nullptr;

    if ( tipo == No_pieza ||color == Sin_color) {
        // Si el color es Sin_color, no hay pieza que dibujar
         //rutaImagen = "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/vacio.png";
        rutaImagen = "imagenes/vacio.png";
    }
    else {
        switch (tipo)
    {
        case Peon:
            //rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/peon_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/peon_blanco.png";
            rutaImagen = (color == Negra) ? "imagenes/peon_negro.png" : "imagenes/peon_blanco.png";
            break;
        case Caballo:
            //rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/caballo_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/caballo_blanco.png";
            rutaImagen = (color == Negra) ? "imagenes/caballo_negro.png" : "imagenes/caballo_blanco.png";
            break;
        case Alfil:
            //rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/alfil_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/alfil_blanco.png";
            rutaImagen = (color == Negra) ? "imagenes/alfil_negro.png" : "imagenes/alfil_blanco.png";
            break;
        case Torre:
            //rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/torre_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/torre_blanco.png";
            rutaImagen = (color == Negra) ? "imagenes/torre_negro.png" : "imagenes/torre_blanco.png";
            break;
        case Rey:
            //rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/rey_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/rey_blanco.png";
            rutaImagen = (color == Negra) ? "imagenes/rey_negro.png" : "imagenes/rey_blanco.png";
            break;
        case Reina:
            //rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/reina_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/reina_blanco.png";
            rutaImagen = (color == Negra) ? "imagenes/reina_negro.png" : "imagenes/reina_blanco.png";
            break;
        default:
            // Caso por defecto, para manejar otros tipos de piezas inesperados
            return;
        }
    }

    glDisable(GL_LIGHTING);
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
    /**/

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
  

}

Pieza::Pieza(const Pieza& p)
{
    //parametro constante
    tipo = p.tipo;
    color = p.color;
    casilla = p.casilla;
    fila = p.fila;
    col = p.col;
    //movida = p.movida;

}
