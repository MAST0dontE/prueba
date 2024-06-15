#ifndef DTINFOPROMOCION_H
#define DTINFOPROMOCION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"

using namespace std;

class DTInfoPromocion{
    public:
        string nombre;
        string descripcion;
        DTFecha fechaDeVencimiento;
        string infoVendedor;
        set<ProductoEnPromocion*> productos;

        DTInfoPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento,string infoVendedor, set<ProductoEnPromocion*> productos);
        string toString();

};

#endif // DTINFOPROMOCION_H