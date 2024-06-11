#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>
#include "Cliente.h"
#include "DTNotificacion.h"

class Observer{
    public:
        virtual void agregarSuscripcion();
        virtual void notificar(DTNotificacion notificacion);
        virtual void eliminarSuscripcion();
};
//frgttkhrej
#endif // OBSERVER_H
