#ifndef DTINFOPRODUCTO_H
#define DTINFOPRODUCTO_H

#include <string>
#include "ECategoria.h"

using namespace std;

class DTInfoProducto{
    public:
        string vendedor;
        int cantStock;
        string descripcion;
        float precio;
        ECategoria categoria;

        DTInfoProducto(int codigo, string nombre, string vendedor, int cantStock, string descripcion, float precio, ECategoria categoria);

};

#endif // DTINFOPRODUCTO_H