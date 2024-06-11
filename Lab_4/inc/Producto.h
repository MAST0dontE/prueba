#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include "DTIdProducto.h"
#include "DTInfoProducto.h"
#include "ECategoria.h"
#include "DTProductoCompra.h"
using namespace std;

class Producto{ 
    private:
        int codigo;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        Ecategoria categoria;

    public:
        Producto(int codigo, int stock, float precio, string nombre, string descripcion, Ecategoria categoria);
        DTProductoCompra getDatosProducto();
        DTInfoCompra getDatosCompra();
        void agregarProducto(int stock, int cantidad);
        DTIdProducto getInfoProducto();
};

#endif // PRODUCTO_H
