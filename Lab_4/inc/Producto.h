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
        ECategoria categoria;

    public:
        Producto(int codigo, int stock, float precio, string nombre, string descripcion, ECategoria categoria);
        DTIdProductoCompra getDatosProducto();
       // DTidProductoCompra getDatosCompra();
        void agregarProducto(int stock, int cantidad);
        DTidProducto getInfoProducto();
};

#endif // PRODUCTO_H
