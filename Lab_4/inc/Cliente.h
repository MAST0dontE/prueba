#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "iSuscriptor.h"
#include "DTDireccion.h"
#include "Compra.h"
using namespace std;

class Cliente : public Usuario, public iSuscriptor{
    private:
        DTDireccion direccion;
        string ciudadResidencia;
        map<int, Compra*> comprasRealizadas;
        //set<DTNotificacion> notificaciones;

    public:
        // GETTERS
        DTDireccion getDireccion();
        string getCiudadResidencia();
        const map<int, Compra*>& getComprasRealizadas() const;
        Cliente(string contrasenia, string nickname, DTFecha fecha, DTDireccion direccion, string ciudadResidencia);
        void agregarSuscripcion() override ;
        void eliminarSuscripcion() override ;
        void notificar(DTNotificacion notificacion) override ;
        string getNicknameSuscriptor() override ;
        bool esVendedor() const override{return false;} 
        //set<DTNotificacion> getNotificaciones();
        void borrarNotificaciones();
        vector<Comentario> listarComentarios(string) override;
        void agregarComentario (Comentario*);
        map<int, Comentario *> getComentarios();
};

#endif // CLIENTE_H
