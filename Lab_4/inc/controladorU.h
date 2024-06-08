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
    bool altaCliente(string, string, DTfecha, DTdireccion, string);
    bool altaVendedor(string, string, DTfecha, string);
    set<string> listaDeUsuarios();
    set<DTcomentario> seleccionarUsuario(string);
    void seleccionarComentario(DTcomentario) ;
    void eliminarComentario(DTcomentario);
    set<string> suscribirseA(string);
    set<DTnotificacion> consultarNotificaciones(string) ;
    set<string> eliminarSuscripciones(string);
};

#endif // CONTROLADORUSUARIOS_H
