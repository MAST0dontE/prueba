#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"
#include <string>
#include <set>

class Vendedor : public Usuario{
    private:
        std::string codigoRUT;
        std::set<DTNotificacion> notificaciones;

    public:
        Vendedor(std::string contrasenia, std::string nickname, DTFecha fechaDeNacimiento, std::string codigoRUT);

        void notificar();
        void setearProductosVendedor(std::set<DTIdProducto>);
};

#endif // VENDEDOR_H
