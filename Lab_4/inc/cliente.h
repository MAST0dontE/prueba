#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Observer.h"
using namespace std;

class Cliente : public Usuario, public Observer{
    private:
        DTDireccion direccion;
        string ciudadResidencia;
        set<DTNotificacion> notificaciones;

    public:
        Cliente(string contrasenia, string nickname, DTFecha fechaDeNacimiento, DTDireccion direccion, std::string ciudadResidencia);

        void notificar(DTNotificacion notificacion);
        set<DTNotificacion> getNotificaciones();
        void borrarNotificaciones();
};

#endif // CLIENTE_H
