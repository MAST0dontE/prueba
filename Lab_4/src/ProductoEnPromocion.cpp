#include "ProductoEnPromocion.h"

ProductoEnPromocion::ProductoEnPromocion(Producto *producto ,float descuento, int cantMinima)
    : Producto(*producto), descuento(descuento), cantMinima(cantMinima) {}

float ProductoEnPromocion::getDescuento(){
    return this->descuento;
}

int ProductoEnPromocion::getCantMinima(){
    return this->cantMinima;
}
