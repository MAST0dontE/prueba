#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Observer.h"

class Cliente : public Usuario, public Observer{
    private:
        DTDireccion direccion;
        std::string ciudadResidencia;
        std::set<DTNotificacion> notificaciones;

    public:
        Cliente(std::string contrasenia, std::string nickname, DTFecha fechaDeNacimiento, DTDireccion direccion, std::string ciudadResidencia);

        void notificar(DTNotificacion notificacion);
        std::set<DTNotificacion> getNotificaciones();
        void borrarNotificaciones();
};

#endif // CLIENTE_H
