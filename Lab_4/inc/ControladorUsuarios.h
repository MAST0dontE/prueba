#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include "iControladorUsuarios.h"
#include <string>
#include <vector>
#include <set>
#include "Cliente.h"
#include "DTFecha.h"
#include "Vendedor.h"
#include "DTcomentario.h"
#include "DTNotificacion.h"
#include "DTDireccion.h"
#include "Comentario.h"
using namespace std;

class ControladorUsuarios : public iControladorUsuarios{
private:
vector<Usuario*> Usuarios;
public:
    //porque notificaciones es un bool? no se
    void setCliente(Cliente *cliente);
    void setVendedor(Vendedor *vendedor);
    void setComentario(Comentario *comentario);
    bool altaCliente(string username, string password, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad);
    bool altaVendedor(string username, string password, DTFecha fechaNacimiento, string codigoRUT);
    set<string> listaDeUsuarios();
    set<DTcomentario> listarComentarios(string nickname);
    void seleccionarComentario(DTcomentario *comentario) ;
    void eliminarComentario(DTcomentario *comentario);
    set<string> suscribirseA(string nickname);
    set<DTNotificacion> consultarNotificaciones(string username); ;
    void eliminarSuscripciones(string username);
   // Usuario *seleccionarUsuario(string username);
   void setDTComentario(DTcomentario *comentario);
   //void listaDeUsuarios();
};


#endif // CONTROLADORUSUARIOS_H
