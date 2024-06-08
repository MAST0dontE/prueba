#include "Producto.h"

Producto::Producto(int codigo, int stock, float precio, string nombre, string descripcion, Ecategoria categoria)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria) {}

DTIdProducto Producto::getDatosProducto()
{
    // Implementación
    return DTIdProducto();
}

DTProductoCompra Producto::getDatosCompra()
{
    // Implementación
    return DTProductoCompra();
}

void Producto::agregarProducto(int stock, int cantidad)
{
    // Implementación
}

DTInfoProducto Producto::getInfoProducto()
{
    // Implementación
    return DTInfoProducto();
}
