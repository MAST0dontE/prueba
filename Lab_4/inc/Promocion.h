#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"
#include <set>
using namespace std;

class Promocion{
    private:
        string nombre;
        string descripcion;
        DTFecha fechaDeVencimiento;
        set<ProductoEnPromocion> productos;

    public:
        Promocion(string nombre, string descripcion, DTFecha fechaDeVencimiento);
        void agregarProductoPromocion(ProductoEnPromocion producto);
};

#endif // PROMOCION_H