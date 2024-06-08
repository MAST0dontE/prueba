#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <string>
#include "DTFecha.h"
using namespace std;

class DTcomentario{
    public:
        string comentario;
        DTFecha fecha;
        DTcomentario(string comentario, DTFecha fecha);

};

#endif // DTCOMENTARIO_H