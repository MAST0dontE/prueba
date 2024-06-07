#include "Transaccion.h"

Transaccion::Transaccion(std::string nombre, std::string descripcion, DTFecha fechaDeTransaccion, float montoTotal)
    : nombre(nombre), descripcion(descripcion), fechaDeTransaccion(fechaDeTransaccion), montoTotal(montoTotal) {}
