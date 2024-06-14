#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"
#include <vector>
using namespace std;

class Promocion{
    private:
        string nombre;
        string descripcion;
        DTFecha fechaDeVencimiento;
        vector<ProductoEnPromocion*> productos;

    public:
        Promocion(string nombre, string descripcion, DTFecha fechaDeVencimiento);
        void agregarProductoPromocion(ProductoEnPromocion* producto);
        string getNombre();
        string getDescripcion();
        DTFecha getFechaDeVencimiento();
        vector<ProductoEnPromocion*> getProductos();
};

#endif // PROMOCION_H
