#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <map>
#include "DTFecha.h"
#include "DTcomentario.h"
using namespace std;

class Producto;
class Comentario{
    private:
        int id;
        string comentario;
        DTFecha fechaDeComentario;
        map<int, Comentario*> respuestas;
        Producto* producto;

    public:
        Comentario(int id, string comentario, DTFecha fechaDeComentario);
        ~Comentario();
        int getId() const;
        string getTexto() const;
        DTFecha getFecha() const;
        Producto* getProducto() const;
        void agregarRespuesta (Comentario* comentario);
        void eliminarRespuesta(int id);
        map<int, Comentario*>& getRespuestas();
};

#endif // COMENTARIO_H
