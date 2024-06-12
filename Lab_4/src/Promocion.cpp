#include "Promocion.h"

Promocion::Promocion(string nombre, string descripcion, DTFecha fechaDeVencimiento)
    : nombre(nombre), descripcion(descripcion), fechaDeVencimiento(fechaDeVencimiento) {}

void Promocion::agregarProductoPromocion(ProductoEnPromocion producto)
{
    // Implementación
}

set<ProductoEnPromocion> Promocion::getProductos()
{
    return set<ProductoEnPromocion>();
}
