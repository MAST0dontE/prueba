#ifndef PRODUCTOENPROMOCION_H
#define PRODUCTOENPROMOCION_H

#include "Producto.h"
using namespace std;

class ProductoEnPromocion : public Producto{
    private:
        float descuento;
        int cantMinima;

    public:
        ProductoEnPromocion(int codigo, int stock, float precio, string nombre, string descripcion,string vendedor, ECategoria categoria, float descuento, int cantMinima);
       // float getDescuento();
       // int getCantMinima();
};

#endif // PRODUCTOENPROMOCION_H
