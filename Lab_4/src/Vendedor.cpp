#include "Vendedor.h"

Vendedor::Vendedor(std::string contrasenia, std::string nickname, DTFecha fechaDeNacimiento, std::string codigoRUT)
    : Usuario(contrasenia, nickname, fechaDeNacimiento), codigoRUT(codigoRUT) {}

void Vendedor::notificar()
{
    // Implementación
}

void Vendedor::setearProductosVendedor(std::set<DTIdProducto> productos)
{
    // Implementación
}
