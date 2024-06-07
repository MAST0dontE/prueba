#ifndef COMPRA_H
#define COMPRA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"

class Compra
{
private:
    DTFecha fechaDeCompra;
    float montoTotal;
    std::set<ProductoEnPromocion> productos;

public:
    Compra(DTFecha fechaDeCompra, float montoTotal);
    void addProducto(ProductoEnPromocion producto);
};

#endif // COMPRA_H
