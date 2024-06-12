#ifndef DTINFOPROMOCION_H
#define DTINFOPROMOCION_H

#include <string>
#include <set>
#include "ProductoEnPromocion.h"

using namespace std;

class DTInfoPromocion{
    public:
        string infoVendedor;
        set<ProductoEnPromocion*> productos;

        DTInfoPromocion(string infoVendedor, set<ProductoEnPromocion*> productos);
        string toString();

};

#endif // DTINFOPROMOCION_H