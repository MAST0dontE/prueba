#include "Cliente.h"


Cliente::Cliente(string contrasenia, string nickname, DTFecha fechaDeNacimiento, DTDireccion direccion, string ciudadResidencia)
    : Usuario(nickname,contrasenia, fechaDeNacimiento), direccion(direccion), ciudadResidencia(ciudadResidencia) {}

DTDireccion Cliente::getDireccion()
{
    return this->direccion;
}

string Cliente::getCiudadResidencia()
{
    return this->ciudadResidencia;
}

const set<Compra *> &Cliente::getComprasRealizadas() const
{
    return this->comprasRealizadas;
}

void Cliente::agregarSuscripcion(){

}

void Cliente::notificar(DTNotificacion notificacion)
{
    // Implementación
}

set<DTNotificacion> Cliente::getNotificaciones()
{
    // Implementación
    return set<DTNotificacion>();
}

void Cliente::borrarNotificaciones()
{
notificaciones.clear();
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
    int idComentario = comentario->getId();
    comentariosUsuario[idComentario] = comentario;
}