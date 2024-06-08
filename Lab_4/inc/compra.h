#ifndef COMPRA_H
#define COMPRA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"
#include "CompraPorProducto.h"
using namespace std;

class Compra{
    private:
        DTFecha fechaDeCompra;
        float montoTotal;
        set<ProductoEnPromocion> productosEnPromo;
        set<CompraPorProducto> productos;

    public:
        //Compra(DTFecha fechaDeCompra, float montoTotal);
        void addProducto(ProductoEnPromocion producto);
};

#endif // COMPRA_H
