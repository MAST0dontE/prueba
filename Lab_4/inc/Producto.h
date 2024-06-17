#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>
#include "DTInfoProducto.h"
#include "DTInfoProducto.h"
#include "ECategoria.h"
#include "DTProductoCompra.h"
#include "DTInfoCompra.h"
#include "Comentario.h"

using namespace std;

class Producto{ 
    private:
        int codigo;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        string vendedor;
        ECategoria categoria;
        map<int, Comentario*> comentarios;

    public:
        Producto(int codigo, int stock, float precio, string nombre, string descripcion, string vendedor, ECategoria categoria);
        DTProductoCompra getDatosProducto();
        DTInfoCompra getDatosCompra();
        void agregarProducto(int stock, int cantidad);
        DTInfoProducto getInfoProducto();
        //getters y setters:
        int getCodigo();
        int getStock();
        float getPrecio();
        string getNombre();
        string getDescripcion();
        ECategoria getCategoria();
        string getNombreVendedor();
        map<int, Comentario*> getComentarios();
        void agregarComentario(Comentario* comentario);
};

#endif // PRODUCTO_H
