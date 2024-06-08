#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "DTFecha.h"
using namespace std;

class Comentario{
    private:
        string comentario;
        DTFecha fechaDeComentario;

    public:
        Comentario(string comentario, DTFecha fechaDeComentario);
};

#endif // COMENTARIO_H
