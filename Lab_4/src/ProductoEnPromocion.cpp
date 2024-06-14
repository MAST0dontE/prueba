#include "ProductoEnPromocion.h"

ProductoEnPromocion::ProductoEnPromocion(int codigo, int stock, float precio, string nombre, string descripcion,string vendedor, ECategoria categoria, float descuento, int cantMinima)
    : Producto(codigo, stock, precio, nombre, descripcion, vendedor, categoria), descuento(descuento), cantMinima(cantMinima) {}
