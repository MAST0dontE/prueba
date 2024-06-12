#include "DTInfoPromocion.h"

DTInfoPromocion::DTInfoPromocion(string infoVendedor, set<ProductoEnPromocion*> productos) : infoVendedor(infoVendedor), productos(productos)
{}

string DTInfoPromocion::toString()
{
    return "Info Vendedor: " + this->infoVendedor + "\nProductos: " + to_string(this->productos.size()) + "\n";
}
