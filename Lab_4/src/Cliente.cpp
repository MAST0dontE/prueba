#include "Cliente.h"


Cliente::Cliente(string nickname, string contrasenia, DTFecha fechaDeNacimiento, DTDireccion direccion, string ciudadResidencia)
    : Usuario(nickname,contrasenia, fechaDeNacimiento), direccion(direccion), ciudadResidencia(ciudadResidencia) {}

DTDireccion Cliente::getDireccion()
{
    return this->direccion;
}

string Cliente::getCiudadResidencia()
{
    return this->ciudadResidencia;
}

const map<int, Compra*> &Cliente::getComprasRealizadas() const
{
    return this->comprasRealizadas;
}

void Cliente::agregarSuscripcion(){
    //Implementacion
}

void Cliente::notificar(DTNotificacion notificacion){
    int key = this->contadorNotificaciones;
    this->notificaciones.emplace(key,notificacion);
    this->contadorNotificaciones++;
}


map<int, DTNotificacion> Cliente::getNotificaciones(){
    return this->notificaciones;
}

void Cliente::borrarNotificaciones(){
    notificaciones.clear();
    this->contadorNotificaciones = 0;
}

vector<Comentario> Cliente::listarComentarios(string)
{
    return vector<Comentario>();
}

void Cliente::eliminarSuscripcion()
{
    // Implementación
}

void Cliente::agregarComentario(Comentario *comentario)
{
    comentariosUsuario[comentario->getId()] = comentario;
}

map<int, Comentario*> Cliente::getComentarios(){
    return comentariosUsuario;
}

void Cliente::agregarCompra(Compra *compra){
    comprasRealizadas[compra->getId()] = compra;
}

string Cliente::getNicknameSuscriptor(){
    return this->getNickname();
}