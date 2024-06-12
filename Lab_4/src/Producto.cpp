#include "Producto.h"

Producto::Producto(int codigo, int stock, float precio, string nombre, string descripcion, ECategoria categoria)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria) {}

DTProductoCompra Producto::getDatosProducto()
{
    // Implementación
    return DTProductoCompra(0, 0.0, 0);
}

DTInfoCompra Producto::getDatosCompra()
{
    // Implementación
    return DTInfoCompra(DTFecha(1,1,1), 0);
}

void Producto::agregarProducto(int stock, int cantidad)
{
    // Implementación
}
   
DTInfoProducto Producto::getInfoProducto()
{
    // Implementación
    return DTInfoProducto(0, " ", " ", 0, " ", 0.0, otros);
}

int Producto::getCodigo()
{
    return 0;
}

int Producto::getStock()
{
    return 0;
}

float Producto::getPrecio()
{
    return 0.0f;
}

string Producto::getNombre()
{
    return string();
}

string Producto::getDescripcion()
{
    return string();
}

ECategoria Producto::getCategoria()
{
    return ECategoria();
}
