#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include "iControladorUsuarios.h"
#include <string>
#include <vector>
#include <set>
#include "Cliente.h"
#include "Vendedor.h"
#include "Comentario.h"

class ControladorUsuarios : public iControladorUsuarios{
    public:
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setComentario(Comentario *comentario);

        bool altaCliente(std::string, std::string, DTFecha, DTDireccion, std::string, bool);
        bool altaVendedor(std::string, std::string, DTFecha, std::string);

        std::set<std::string> listaDeUsuarios();
        Usuario *seleccionarUsuario(std::string);

        void setDTComentario(DTComentario *comentario);
        void eliminarComentario(DTComentario *comentario);

        std::set<DTNotificacion> consultarNotificaciones();
        void eliminarSuscripciones(std::string);
};

#endif // CONTROLADORUSUARIOS_H
