#ifndef DTINFOPRODUCTO_H
#define DTINFOPRODUCTO_H

#include <string>
#include "ECategoria.h"

using namespace std;

class DTInfoProducto{
    public:
        int codigo;
        string nombre;
        float precio;
        int cantStock;
        string descripcion;
        ECategoria categoria;
        string vendedor;
        // friend ostream& operator << (std::ostream& os,DTInfoProducto& producto);   
        string toString();     
        DTInfoProducto(int codigo, string nombre, float precio, int cantStock, string descripcion,  ECategoria categoria, string vendedor);

};

#endif // DTINFOPRODUCTO_H 