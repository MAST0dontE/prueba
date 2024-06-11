#ifndef COMPRAPORPRODUCTO_H
#define COMPRAPORPRODUCTO_H

#include <string>
#include "EEnvio.h"
using namespace std;
class CompraPorProducto{
    private:
        int cantidadSolicitada;
        EEnvio estadoDEEnvio;

    public:
    CompraPorProducto(int cantidadSolicitada, EEnvio estadoDEEnvio);
    EEnvio getestadoDEEnvio();
    void setestadoDEEnvio(EEnvio estadoDEEnvio);
};

#endif // COMPRAPORPRODUCTO_H
