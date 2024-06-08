#include "Cliente.h"

Cliente::Cliente(std::string contrasenia, std::string nickname, DTFecha fechaDeNacimiento, DTDireccion direccion, std::string ciudadResidencia)
    : Usuario(contrasenia, nickname, fechaDeNacimiento), direccion(direccion), ciudadResidencia(ciudadResidencia) {}

void Cliente::notificar(DTNotificacion notificacion)
{
    // Implementación
}

std::set<DTNotificacion> Cliente::getNotificaciones()
{
    // Implementación
    return std::set<DTNotificacion>();
}

void Cliente::borrarNotificaciones()
{
    // Implementación
}
