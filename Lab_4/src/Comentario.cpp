#include "Comentario.h"

Comentario::Comentario(int id, string comentario, DTFecha fechaDeComentario) \
            : comentario(comentario), fechaDeComentario(fechaDeComentario) {}
            
int Comentario::getId() const{
    return id;
}
            
string Comentario::getTexto() const{
    return comentario;
}

DTFecha Comentario::getFecha() const{
    return fechaDeComentario;
}
