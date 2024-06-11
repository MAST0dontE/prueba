#include "Cliente.h"

Cliente::Cliente(string contrasenia, string nickname, DTFecha fechaDeNacimiento, DTDireccion direccion, string ciudadResidencia)
    : Usuario(contrasenia, nickname, fechaDeNacimiento), direccion(direccion), ciudadResidencia(ciudadResidencia) {}

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
    // Implementación
}

void Cliente::eliminarSuscripcion()
{
    // Implementación
}
