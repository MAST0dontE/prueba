#include "DTInfoPromocion.h"

DTInfoPromocion::DTInfoPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, string infoVendedor, set<ProductoEnPromocion*> productos) : nombre(nombre), descripcion(descripcion), fechaDeVencimiento(fechaDeVencimiento) ,infoVendedor(infoVendedor), productos(productos)
{}

string DTInfoPromocion::toString()
{
    return "Info Vendedor: " + this->infoVendedor + "\nProductos: " + to_string(this->productos.size()) + "\n";
}
