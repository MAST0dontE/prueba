#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "DTFecha.h"

class Comentario{
    private:
        std::string comentario;
        DTFecha fechaDeComentario;

    public:
        Comentario(std::string comentario, DTFecha fechaDeComentario);
};

#endif // COMENTARIO_H
