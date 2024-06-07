#include "Factoria.h"

ControladorUsuarios *Factoria::getControladorUsuarios()
{
    return new ControladorUsuarios();
}

ControladorVentas *Factoria::getControladorVentas()
{
    return new ControladorVentas();
}
