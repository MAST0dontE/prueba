#ifndef PRODUCTOENPROMOCION_H
#define PRODUCTOENPROMOCION_H

#include "Producto.h"
using namespace std;

class ProductoEnPromocion : public Producto{
    private:
        Producto *producto;
        float descuento;
        int cantMinima;

    public:
        ProductoEnPromocion(Producto *producto, float descuento, int cantMinima);
        float getDescuento();
        int getCantMinima();
};

#endif // PRODUCTOENPROMOCION_H
