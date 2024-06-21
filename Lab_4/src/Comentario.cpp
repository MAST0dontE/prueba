#include "Comentario.h"

Comentario::Comentario(int id, string comentario, DTFecha fechaDeComentario) \
            : id(id), comentario(comentario), fechaDeComentario(fechaDeComentario) {}

Comentario::~Comentario(){
    for (map<int, Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it){
        delete it->second;
    }
    respuestas.clear();
}

int Comentario::getId() const{
    return id;
}
            
string Comentario::getTexto() const{
    return comentario;
}

DTFecha Comentario::getFecha() const{
    return fechaDeComentario;
}

Producto *Comentario::getProducto() const{
    return producto;
}

void Comentario::agregarRespuesta(Comentario* comentario){
    respuestas[comentario->getId()] = comentario;
}

map<int, Comentario*>& Comentario::getRespuestas(){
    return respuestas;
}

void Comentario::eliminarRespuesta(int id){
    respuestas.erase(id);
}