#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "DTFecha.h"
#include "DTcomentario.h"
using namespace std;

class Comentario{
    private:
        int id;
        string comentario;
        DTFecha fechaDeComentario;

    public:
        Comentario(int id, string comentario, DTFecha fechaDeComentario);
        int getId() const;
        string getTexto() const;
        DTFecha getFecha() const;
};

#endif // COMENTARIO_H
