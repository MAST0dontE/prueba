#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "DTInfoProducto.h"
#include "DTInfoProducto.h"
#include "ECategoria.h"
#include "DTProductoCompra.h"
#include "DTInfoCompra.h"

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
        DTProductoCompra getDatosProducto();
        DTInfoCompra getDatosCompra();
        void agregarProducto(int stock, int cantidad);
        DTInfoProducto getInfoProducto();
};

#endif // PRODUCTO_H
