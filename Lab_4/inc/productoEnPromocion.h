#ifndef PRODUCTOENPROMOCION_H
#define PRODUCTOENPROMOCION_H

#include "Producto.h"

class ProductoEnPromocion : public Producto
{
private:
    float descuento;
    int cantMinima;

public:
    ProductoEnPromocion(int codigo, int stock, float precio, std::string nombre, std::string descripcion, CCategoria categoria, float descuento, int cantMinima);
};

#endif // PRODUCTOENPROMOCION_H
