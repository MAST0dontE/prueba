#ifndef PRODUCTOENPROMOCION_H
#define PRODUCTOENPROMOCION_H

#include "Producto.h"
using namespace std;

class ProductoEnPromocion{
    private:
        Producto ptrProducto;
        float descuento;
        int cantMinima;

    public:
        ProductoEnPromocion(Producto* producto, float descuento, int cantMinima);
        float getDescuento();
        int getCantMinima();
        Producto getProducto();
};

#endif // PRODUCTOENPROMOCION_H
