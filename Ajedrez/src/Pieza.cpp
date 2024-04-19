
#include "Pieza.h"
#include <iostream>
#include <filesystem>

Pieza::Pieza()
{
}

Pieza::~Pieza()
{
}

//pintando cada pieza
void Pieza::dibuja()
{

    // Habilitar el uso de texturas
    glEnable(GL_TEXTURE_2D);



    // Seleccionar la textura adecuada seg迆n el tipo y color de la pieza
    const char* rutaImagen = nullptr;

    if (color == Sin_color || tipo == No_pieza) {
        // Si el color es Sin_color, no hay pieza que dibujar
        return;
    }

    switch (tipo)
    {
    case Peon:
        rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/peon_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/peon_blanco.png";
        break;
    case Caballo:
        rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/caballo_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/caballo_blanco.png";
        break;
    case Alfil:
        rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/alfil_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/alfil_blanco.png";
        break;
    case Torre:
        rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/torre_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/torre_blanco.png";
        break;
    case Rey:
        rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/rey_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/rey_blanco.png";
        break;
    case Reina:
        rutaImagen = (color == Negra) ? "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/reina_negro.png" : "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/reina_blanco.png";
        break;
    default:
        // Caso por defecto, para manejar otros tipos de piezas inesperados
        return;
    }

    glDisable(GL_LIGHTING);
    // Seleccionar la textura seg迆n la ruta de la imagen

    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(rutaImagen).id);

    
    // Especificar coordenadas de textura y v谷rtices para la pieza
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
  

    /*

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

    // Ruta de sprite de todas las piezas
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << "Current working directory: " << currentPath << std::endl;
    const char* rutaImagen = "D:/download/trabajo_inf_2024/NUEVA CARPETA/Ajedrez/Ajedrez/Ajedrez/bin/todas_las_piezas_sprite.png";  // Cambia a la ruta de tu imagen de sprite
    std::cout << "Image path: " << rutaImagen << std::endl;

    // Carga la textura
    ETSIDI::GLTexture textura = ETSIDI::getTexture(rutaImagen);

    // Verifica si la textura fue cargada correctamente
    if (textura.id == 0) {
        std::cerr << "Error: No se pudo cargar la textura de " << rutaImagen << std::endl;
        return;
    }

    // Vincula la textura utilizando el ID de la textura
    glBindTexture(GL_TEXTURE_2D, textura.id);

    // Determina las coordenadas de textura seg迆n el tipo y color de la pieza
    const GLfloat texWidth = 1.0f / 6.0f; // Ancho de cada pieza en el sprite es 1/6
    const GLfloat texHeight = 1.0f / 2.0f; // Altura de cada pieza en el sprite es 1/2

    // Coordenadas de textura para la pieza
    GLfloat texX = 0.0f;
    GLfloat texY = (color == Negra) ? 0.0f : 0.5f; // Color negro en la primera fila, blanco en la segunda

    switch (tipo) {
    case Torre:
        texX = 0.0f; // La torre est芍 en la primera posici車n
        break;
    case Alfil:
        texX = texWidth; // El alfil est芍 en la segunda posici車n
        break;
    case Rey:
        texX = 2 * texWidth; // El rey est芍 en la tercera posici車n
        break;
    case Reina:
        texX = 3 * texWidth; // La reina est芍 en la cuarta posici車n
        break;
    case Caballo:
        texX = 4 * texWidth; // El caballo est芍 en la quinta posici車n
        break;
    case Peon:
        texX = 5 * texWidth; // El pe車n est芍 en la sexta posici車n
        break;
    case No_pieza:
        // Si no hay pieza, no se dibuja nada
        return;
    }

    // Dibuja la pieza con las coordenadas de textura calculadas
    glBegin(GL_POLYGON);
    glTexCoord2f(texX, texY + texHeight);
    glVertex3f(static_cast<GLfloat>(casilla.c + 1), static_cast<GLfloat>(casilla.f + 1), 0.0f); // Esquina superior izquierda
    glTexCoord2f(texX + texWidth, texY + texHeight);
    glVertex3f(static_cast<GLfloat>(casilla.c), static_cast<GLfloat>(casilla.f + 1), 0.0f); // Esquina superior derecha
    glTexCoord2f(texX + texWidth, texY);
    glVertex3f(static_cast<GLfloat>(casilla.c), static_cast<GLfloat>(casilla.f), 0.0f); // Esquina inferior derecha
    glTexCoord2f(texX, texY);
    glVertex3f(static_cast<GLfloat>(casilla.c + 1), static_cast<GLfloat>(casilla.f), 0.0f); // Esquina inferior izquierda
    glEnd();

    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);*/

}

Pieza::Pieza(const Pieza& p)
{
    //par芍metro constante
    tipo = p.tipo;
    color = p.color;
    casilla = p.casilla;
    fila = p.fila;
    col = p.col;

}
