#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Observer.h"
#include "DTDireccion.h"
using namespace std;

class Cliente : public Usuario, public Observer{
    private:
        DTDireccion direccion;
        string ciudadResidencia;
        set<DTNotificacion> notificaciones;

    public:
        // GETTERS
        DTDireccion getDireccion();
        string getCiudadResidencia();
        
        Cliente(string contrasenia, string nickname, DTFecha fecha, DTDireccion direccion, string ciudadResidencia);
        void agregarSuscripcion() override;
        void eliminarSuscripcion() override;
        void notificar(DTNotificacion notificacion) override;
        bool esVendedor() const override{
            return false;
        }
        set<DTNotificacion> getNotificaciones();
        void borrarNotificaciones();
};

#endif // CLIENTE_H
