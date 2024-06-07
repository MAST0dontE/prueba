#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>
#include "Cliente.h"
#include "DTNotificacion.h"

class Observer
{
public:
    virtual void agregarSuscripcion(Cliente *cliente) = 0;
    virtual void notificar(DTNotificacion notificacion) = 0;
    virtual void eliminarSuscripcion(Cliente *cliente) = 0;
};

#endif // OBSERVER_H
