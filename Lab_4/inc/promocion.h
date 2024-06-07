#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"

class Promocion
{
private:
    std::string nombre;
    std::string descripcion;
    DTFecha fechaDeVencimiento;
    std::set<ProductoEnPromocion> productos;

public:
    Promocion(std::string nombre, std::string descripcion, DTFecha fechaDeVencimiento);
    void agregarProductoPromocion(ProductoEnPromocion producto);
};

#endif // PROMOCION_H
