#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include "iControladorUsuarios.h"
#include <string>
#include <vector>
#include <set>
#include <map>
#include "Cliente.h"
#include "DTFecha.h"
#include "Vendedor.h"
#include "Usuario.h"
#include "Cliente.h"
#include "DTcomentario.h"
#include "DTNotificacion.h"
#include "ControladorVentas.h"
#include "DTDireccion.h"
#include "Comentario.h"
#include "DTInfoProducto.h"
using namespace std;

class ControladorUsuarios : public iControladorUsuarios{
    private:
    int codigoSeleccionado = 0;
    bool respuestaSeleccionada; //deberia inicializarlo con algun valor? como es un triste char no supe hacerlo xd perdon p1 j3j3
    int idSeleccionado;
    int creadorIdComentario;
    string vendedorSeleccionado;
    map<string, Usuario*> usuarios;
    //map<string, Usuario*>::iterator it0;
    map<string, Cliente*> clientes;
    map<string, Cliente*>::iterator it1;
    map<string, Vendedor*> vendedores;
    map<string, Vendedor*>::iterator it2;
    //vector<Usuario*> Usuarios;
    //vector<Vendedor*> Vendedores;
    //vector<Cliente*> Clientes;
    
    public:
        //porque notificaciones es un bool? no se
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setComentario(Comentario *comentario);
        bool altaCliente(string username, string password, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad);
        bool altaVendedor(string username, string password, DTFecha fechaNacimiento, string codigoRUT);
        set<string> listaDeVendedores();
        set<DTcomentario> listarComentarios(string nickname);
        void seleccionarComentario(DTcomentario *comentario) ;
        void eliminarComentario(DTcomentario *comentario);
        set<string> suscribirseA(string nickname);
        set<DTNotificacion> consultarNotificaciones(string username); 
        void eliminarSuscripciones(string username);
        void seleccionarVendedor(string username);
        Usuario *seleccionarUsuario(string username);
        void listarProductosVendedor();
        void listarComentarios(int codigo);
        void seleccionarProducto(int codigo);
        void tipoComentario();
        void deseaRespuestas();
        void seleccionarComentario(int id);
        void nuevoComentario(string comentario, DTFecha fechaDeComentario);
        // void setDTComentario(DTcomentario *comentario);
        void listaDeUsuarios_();
        void infoCliente(string nickname);
        void infoVendedor(string nickname);
        // void nuevaSuscripcion(string nickname);
};


#endif // CONTROLADORUSUARIOS_H
