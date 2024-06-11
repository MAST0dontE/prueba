#ifndef COMPRAPORPRODUCTO_H
#define COMPRAPORPRODUCTO_H

#include <string>
#include "EEnvio.h"
#include "EEnvio.h"
using namespace std;
class CompraPorProducto{
    private:
        int cantidadSolicitada;
        EEnvio estadoDeEnvio;

    public:
    CompraPorProducto(int cantidadSolicitada, EEnvio estadoDeEnvio);
    EEnvio getestadoDeEnvio();
    void setestadoDeEnvio(EEnvio estadoDeEnvio);
};

#endif // COMPRAPORPRODUCTO_H
