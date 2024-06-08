#ifndef FABRICA_H
#define FABRICA_H

#include "ControladorUsuarios.h"
#include "ControladorVentas.h"

class Fabrica{
    public:
        ControladorUsuarios *getControladorUsuarios();
        ControladorVentas *getControladorVentas();
};

#endif // FABRICA_H
