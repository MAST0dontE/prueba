#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include "iControladorUsuarios.h"
#include <string>
#include <vector>
#include <set>
#include "Cliente.h"
#include "Vendedor.h"
#include "Comentario.h"
using namespace std;

class ControladorUsuarios : public iControladorUsuarios{
    public:
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setComentario(Comentario *comentario);

        bool altaCliente(string, string, DTFecha, DTDireccion, string, bool);
        bool altaVendedor(string, string, DTFecha, string);

        set<string> listaDeUsuarios();
        Usuario *seleccionarUsuario(string);

        void setDTComentario(DTComentario *comentario);
        void eliminarComentario(DTComentario *comentario);

        set<DTNotificacion> consultarNotificaciones();
        void eliminarSuscripciones(string);
};

#endif // CONTROLADORUSUARIOS_H
