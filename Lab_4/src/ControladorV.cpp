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

std::set<std::string> ControladorVentas::altaPromocion(std::string nombre, std::string descripcion, DTFecha fechaVencimiento)
{
    // Implementación
    return std::set<std::string>();
}

std::set<DTIdProducto> ControladorVentas::seleccionarVendedor(std::string codigoRUT)
{
    // Implementación
    return std::set<DTIdProducto>();
}

void ControladorVentas::agregarProducto(int codigo, float precio)
{
    // Implementación
}

bool ControladorVentas::ingresarPromocion()
{
    // Implementación
    return true;
}

std::set<std::string> ControladorVentas::listarNicknamesClientes()
{
    // Implementación
    return std::set<std::string>();
}

std::set<DTIdProducto> ControladorVentas::seleccionarCliente(std::string nickname)
{
    // Implementación
    return std::set<DTIdProducto>();
}

void ControladorVentas::mostrarDetallesCompra(DTInfoCompra infoCompra)
{
    // Implementación
}

void ControladorVentas::registrarCompra()
{
    // Implementación
}

bool ControladorVentas::ingresarPromocion()
{
    // Implementación
    return true;
}
