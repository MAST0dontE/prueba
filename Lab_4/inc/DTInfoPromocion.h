#ifndef DTINFOPROMOCION_H
#define DTINFOPROMOCION_H

#include <string>
#include <set>
#include  "DTInfoProducto.h"

using namespace std;

class DTInfoPromocion{
    public:
        string infoVendedor;
        set<DTInfoProducto> productos;
        DTInfoPromocion(string infoVendedor, set<DTInfoProducto> productos);
};

#endif // DTINFOPROMOCION_H