#ifndef FACTORIA_H
#define FACTORIA_H

#include "ControladorUsuarios.h"
#include "ControladorVentas.h"

class Factoria{
    public:
        ControladorUsuarios *getControladorUsuarios();
        ControladorVentas *getControladorVentas();
};

#endif // FACTORIA_H
