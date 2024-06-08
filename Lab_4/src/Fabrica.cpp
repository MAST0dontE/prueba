#include "Fabrica.h"

ControladorUsuarios *Fabrica::getControladorUsuarios()
{
    return new ControladorUsuarios();
}

ControladorVentas *Fabrica::getControladorVentas()
{
    return new ControladorVentas();
}
