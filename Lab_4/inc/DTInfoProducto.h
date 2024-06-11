#ifndef DTINFOPRODUCTO_H
#define DTINFOPRODUCTO_H

#include <string>
#include "Ecategoria.h"

using namespace std;

class DTInfoProducto{
    public:
        string vendedor;
        int cantStock;
        string descripcion;
        float precio;
        Ecategoria categoria;

        DTInfoProducto(int codigo, string nombre, string vendedor, int cantStock, string descripcion, float precio, Ecategoria categoria);

};

#endif // DTINFOPRODUCTO_H