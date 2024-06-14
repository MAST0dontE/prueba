#ifndef DTINFOPROMOCION_H
#define DTINFOPROMOCION_H

#include <string>
#include <vector>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"

using namespace std;

class DTInfoPromocion{
    public:
        string nombre;
        string descripcion;
        DTFecha fechaDeVencimiento;
        string infoVendedor;
        vector<ProductoEnPromocion*> productos;

        DTInfoPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento,string infoVendedor, vector<ProductoEnPromocion*> productos);
        string toString();

};

#endif // DTINFOPROMOCION_H