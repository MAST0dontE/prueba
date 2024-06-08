#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "DTIdProducto.h"
#include "DTInfoProducto.h"
#include "DTProductoCompra.h"
using namespace std;

class Producto{
    private:
        int codigo;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        CCategoria categoria;

    public:
        Producto(int codigo, int stock, float precio, string nombre, string descripcion, CCategoria categoria);
        DTIdProducto getDatosProducto();
        DTProductoCompra getDatosCompra();
        void agregarProducto(int stock, int cantidad);
        DTInfoProducto getInfoProducto();
};

#endif // PRODUCTO_H
