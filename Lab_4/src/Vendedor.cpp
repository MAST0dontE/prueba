#include "Vendedor.h"

Vendedor::Vendedor(string contrasenia, string nickname, DTFecha fechaDeNacimiento, string codigoRUT)
    : Usuario(contrasenia, nickname, fechaDeNacimiento), codigoRUT(codigoRUT) {}

//getters
string getCodigoRUT(){
    // Implementación
};


void Vendedor::notificar()
{
    // Implementación
}


void Vendedor::setearProductosVendedor(set<DTInfoProducto> productos)
{
    // Implementación
}
