#include "Compra.h"
Compra::Compra(DTFecha fechaDeCompra, float montoTotal, set<ProductoEnPromocion *> productosEnPromo, set<CompraPorProducto *> productos, string cliente) : fechaDeCompra(fechaDeCompra), montoTotal(montoTotal), productosEnPromo(productosEnPromo), productos(productos), cliente(cliente)
{
}
/*DTFecha Compra::getFechaDeCompra() const {
    return this->fechaDeCompra;
}*/

/*float Compra::getMontoTotal() const {
    return this->montoTotal;
}*/

string Compra::getFechaDeCompra() 
{
     return this->fechaDeCompra.toString();
}

float Compra::getMontoTotal()
{
    return this->montoTotal;
}

const std::set<CompraPorProducto *> &Compra::getProductos() const
{
    return this->productos;
}

string Compra::getCliente()
{
    return this->cliente;
}

void Compra::addProducto(ProductoEnPromocion producto)
{
    // Implementación
}
