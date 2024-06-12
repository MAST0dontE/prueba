#include "Vendedor.h"


Vendedor::Vendedor(string contrasenia, string nickname, DTFecha fechaDeNacimiento, string codigoRUT)
    : Usuario(contrasenia, nickname, fechaDeNacimiento), codigoRUT(codigoRUT) {}

string Vendedor::getCodigoRUT(){
    return this->codigoRUT;
}


void Vendedor::notificar()
{
    // Implementación
}


void Vendedor::setearProductosVendedor(set<DTInfoProducto> productos)
{
    // Implementación
}

string Vendedor::toString()
{
    return "Vendedor: " + this->nickname + " - " + this->codigoRUT;
}
