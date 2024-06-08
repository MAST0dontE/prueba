#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>
using namespace std;
class Transaccion{
    private:
        string nombre;
        string descripcion;
        DTFecha fechaDeTransaccion;
        float montoTotal;

    public:
        Transaccion(string nombre, string descripcion, DTFecha fechaDeTransaccion, float montoTotal);
};

#endif // TRANSACCION_H
