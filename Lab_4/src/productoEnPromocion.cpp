#include "ProductoEnPromocion.h"

ProductoEnPromocion::ProductoEnPromocion(int codigo, int stock, float precio, std::string nombre, std::string descripcion, CCategoria categoria, float descuento, int cantMinima)
    : Producto(codigo, stock, precio, nombre, descripcion, categoria), descuento(descuento), cantMinima(cantMinima) {}
