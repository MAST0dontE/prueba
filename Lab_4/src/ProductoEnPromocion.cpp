#include "ProductoEnPromocion.h"

ProductoEnPromocion::ProductoEnPromocion(Producto* producto ,float descuento, int cantMinima)
    : ptrProducto(producto), descuento(descuento), cantMinima(cantMinima) {}

float ProductoEnPromocion::getDescuento(){
    return this->descuento;
}

int ProductoEnPromocion::getCantMinima(){
    return this->cantMinima;
}

Producto* ProductoEnPromocion::getProducto()
{
    return this->ptrProducto;
}
