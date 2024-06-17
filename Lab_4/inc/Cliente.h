#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "Observer.h"
#include "DTDireccion.h"
#include "Compra.h"
using namespace std;

class Cliente : public Usuario, public Observer{
    private:
        DTDireccion direccion;
        string ciudadResidencia;
        set<DTNotificacion> notificaciones;
        set<Compra*> comprasRealizadas;

    public:
        // GETTERS
        DTDireccion getDireccion();
        string getCiudadResidencia();
        const set<Compra*>& getComprasRealizadas() const;

        
        Cliente(string contrasenia, string username, DTFecha fecha, DTDireccion direccion, string ciudadResidencia);
        void agregarSuscripcion() override;
        void eliminarSuscripcion() override;
        void notificar(DTNotificacion notificacion) override;
        bool esVendedor() const override{
            return false;
        } 
        set<DTNotificacion> getNotificaciones();
        void borrarNotificaciones();
        vector<Comentario> listarComentarios(string) override;
};

#endif // CLIENTE_H
