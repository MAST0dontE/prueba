#include "Compra.h"
Compra::Compra(DTFecha fechaDeCompra, float montoTotal, map<int, CompraPorProducto *> productos, string cliente) : fechaDeCompra(fechaDeCompra), montoTotal(montoTotal), productos(productos), cliente(cliente)
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

const map<int, CompraPorProducto*> &Compra::getProductos() const
{
    return this->productos;
}

/*const <CompraPorProducto *> &Compra::getProductos() const
{
    return this->productos;
}*/

string Compra::getCliente()
{
    return this->cliente;
}

int Compra::getId()
{
    return this->id;
}



void Compra::addProducto(ProductoEnPromocion producto)
{
    // Implementación
}
