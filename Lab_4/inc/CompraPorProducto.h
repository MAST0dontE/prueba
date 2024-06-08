#ifndef COMPRAPORPRODUCTO_H
#define COMPRAPORPRODUCTO_H

#include <string>
#include "Eenvio.h"
using namespace std;
class CompraPorProducto{
    private:
        int cantidadSolicitada;
        Eenvio estadoDeEnvio;

    public:
    CompraPorProducto(int cantidadSolicitada, Eenvio estadoDeEnvio);
    Eenvio getestadoDeEnvio();
    void setestadoDeEnvio(Eenvio estadoDeEnvio);
};

#endif // COMPRAPORPRODUCTO_H
