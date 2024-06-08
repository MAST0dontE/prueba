#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"
#include <string>
#include <set>
using namespace std;
class Vendedor : public Usuario{
    private:
        string codigoRUT;
        set<DTNotificacion> notificaciones;

    public:
        Vendedor(string contrasenia, string nickname, DTFecha fechaDeNacimiento, string codigoRUT);

        void notificar();
        void setearProductosVendedor(set<DTIdProducto>);
};

#endif // VENDEDOR_H
