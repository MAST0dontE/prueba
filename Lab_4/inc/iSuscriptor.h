#ifndef ISUSCRIPTOR_H
#define ISUSCRIPTOR_H

#include <set>
#include "DTNotificacion.h"

class iSuscriptor{
    public:
    
        virtual void agregarSuscripcion() = 0 ;
        virtual void notificar(DTNotificacion notificacion) = 0;
        virtual void eliminarSuscripcion() = 0;
        virtual string getNicknameSuscriptor() = 0;
};

#endif // ISUSCRIPTOR_H
