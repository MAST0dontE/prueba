#include "ProductoEnPromocion.h"

ProductoEnPromocion::ProductoEnPromocion(int codigo, int stock, float precio, string nombre, string descripcion, ECategoria categoria, float descuento, int cantMinima)
    : Producto(codigo, stock, precio, nombre, descripcion, categoria), descuento(descuento), cantMinima(cantMinima) {}
