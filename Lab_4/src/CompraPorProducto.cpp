#include "CompraPorProducto.h"

CompraPorProducto::CompraPorProducto(std::string nombre, std::string descripcion, DTFecha fechaDeTransaccion, float montoTotal)
    : nombre(nombre), descripcion(descripcion), fechaDeTransaccion(fechaDeTransaccion), montoTotal(montoTotal) {}
