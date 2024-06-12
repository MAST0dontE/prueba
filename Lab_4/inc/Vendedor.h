#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"
#include "DTNotificacion.h"
#include "DTInfoProducto.h"
#include "DTFecha.h"
#include <string>
#include <set>
using namespace std;
class Vendedor : public Usuario{
    private:
        string codigoRUT;
        set<DTNotificacion> notificaciones;
        set<DTInfoProducto> productosVendedor;
    public:
        //GETTERS
        string getCodigoRUT();
        Vendedor(string contraseña, string nickname, DTFecha fecha, string codigoRUT);
        void notificar();
        void setearProductosVendedor(set<DTInfoProducto>);
};

#endif // VENDEDOR_H
