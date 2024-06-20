#include "CompraPorProducto.h"

CompraPorProducto::CompraPorProducto(int cantidadSolicitada, EEnvio estadoDeEnvio)
{
}

EEnvio CompraPorProducto::getestadoDeEnvio()
{
    //return EEnvio();
    return EEnvio();
}

int CompraPorProducto::getCantidadSolicitada() {
    return this->cantidadSolicitada;
}


int CompraPorProducto::getCodigoProducto() {
    return this->ptrProducto->getCodigo();
}

string CompraPorProducto::getVendedor()
{
    return this->ptrProducto->getNombreVendedor();
}

void CompraPorProducto::setestadoDeEnvio(EEnvio estadoDeEnvio)
{
}
