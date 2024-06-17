#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <map>
#include "DTFecha.h"
#include "DTcomentario.h"
using namespace std;

class Comentario{
    private:
        int id;
        string comentario;
        DTFecha fechaDeComentario;
        map<int, Comentario*> respuestas;

        public : Comentario(int id, string comentario, DTFecha fechaDeComentario);
        ~Comentario();
        int getId() const;
        string getTexto() const;
        DTFecha getFecha() const;
        void agregarRespuesta (Comentario* comentario);
};

#endif // COMENTARIO_H
