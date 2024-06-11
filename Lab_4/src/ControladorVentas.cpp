#include "ControladorVentas.h"

void ControladorVentas::setCliente(Cliente *cliente)
{
    // Implementación
}

void ControladorVentas::setVendedor(Vendedor *vendedor)
{
    // Implementación
}

void ControladorVentas::setPromocion(Promocion *promocion)
{
    // Implementación
}

void ControladorVentas::setCompra(Compra *compra)
{
    // Implementación
}

void ControladorVentas::setProducto(Producto *producto)
{
    // Implementación
}

set<DTInfoProducto> ControladorVentas::listarProductos()
{
    return set<DTInfoProducto>();
}

set<string> ControladorVentas::altaPromocion(string nombre, string descripcion, DTFecha fechaVencimiento)
{
    // Implementación
    return set<string>();
}

set<DTInfoProducto> ControladorVentas::seleccionarVendedor(string nickname)
{
    // Implementación
    return set<DTInfoProducto>();
}

void ControladorVentas::agregarProducto(int codigo,int cantMinima, float descuento)
{
    // Implementación
}

bool ControladorVentas::ingresarPromocion()
{
    // Implementación
    return true;
}

set<string> ControladorVentas::listarNicknamesClientes()
{
    // Implementación
    return set<string>();
}

set<DTInfoProducto> ControladorVentas::seleccionarCliente(string nickname)
{
    // Implementación
    return set<DTInfoProducto>();
}

DTInfoCompra ControladorVentas::mostrarDetallesCompra()
{
    // Implementación
    return DTInfoCompra(DTFecha(1,1,1), 0);
}

void ControladorVentas::registrarCompra()
{
    // Implementación
}
