#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"
#include "DTNotificacion.h"
#include "Producto.h"
#include "DTFecha.h"
#include <string>
#include <set>
using namespace std;
class Vendedor : public Usuario{
    private:
        string codigoRUT;
        set<DTNotificacion> notificaciones;
        set<Producto*> productosVendedor;
    public:
        //GETTERS
        string getCodigoRUT();
        Vendedor(string contrasenia, string nickname, DTFecha fecha, string codigoRUT);
        void notificar();
        void agregarProducto(Producto* producto);
        void setearProductosVendedor(set<Producto*>);
        string toString();
        bool esVendedor() const override{
            return true; 
        }
        //vector<DTInfoProducto> obtenerProductos();
        vector<Comentario> listarComentarios(string) override;
};

#endif // VENDEDOR_H
