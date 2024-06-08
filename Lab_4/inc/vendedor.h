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
        Vendedor(string contraseña, string nickname, DTFecha fecha, string codigoRUT);

        void notificar();
        set<DTIdProducto> setearProductosVendedor();
};

#endif // VENDEDOR_H
