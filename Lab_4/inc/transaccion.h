#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion
{
private:
    std::string nombre;
    std::string descripcion;
    DTFecha fechaDeTransaccion;
    float montoTotal;

public:
    Transaccion(std::string nombre, std::string descripcion, DTFecha fechaDeTransaccion, float montoTotal);
};

#endif // TRANSACCION_H
