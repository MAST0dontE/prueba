#include "Producto.h"

Producto::Producto(int codigo, int stock, float precio, string nombre, string descripcion, Ecategoria categoria)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria) {}

DTProductoCompra Producto::getDatosProducto()
{
    // Implementación
    return DTIdProducto();
}

DTInfoCompra Producto::getDatosCompra()
{
    // Implementación
    return DTProductoCompra();
}

void Producto::agregarProducto(int stock, int cantidad)
{
    // Implementación
}

DTIdProducto Producto::getInfoProducto()
{
    // Implementación
    return DTInfoProducto();
}
