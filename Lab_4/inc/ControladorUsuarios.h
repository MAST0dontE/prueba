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
using namespace std;

class ControladorUsuarios : public iControladorUsuarios{
    private:

    static ControladorUsuarios * controladorUsuariosInst;
    ControladorUsuarios();

    // Colecciones:
    map<string, Usuario *> usuarios;
    map<string, Cliente*> clientes;
    map<string, Vendedor*> vendedores;

    // Datos que guarda este controlador:
    int codigoSeleccionado = 0;
    bool respuestaSeleccionada; //deberia inicializarlo con algun valor? como es un triste char no supe hacerlo xd perdon p1 j3j3
    int idSeleccionado;
    int creadorIdComentario;
    string usuarioSeleccionado;
    string vendedorProductoSeleccionado;
    string nombreNuevoSuscriptor;
    public:
        static ControladorUsuarios* getControladorUsuarios();
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setComentario(Comentario *comentario);
        bool altaCliente(string nickname, string contrasenia, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad);
        bool altaVendedor(string nickname, string contrasenia, DTFecha fechaNacimiento, string codigoRUT);
        set<string> listaDeUsuarios();
        set<string> listaDeVendedores();
        set<DTcomentario> listarComentarios(string nickname);
        void seleccionarComentario(DTcomentario *comentario) ;
        void consultarNotificaciones(string nickname); 
        void eliminarSuscripciones(string nickname);
        void seleccionarUsuario_(string nickname);
        Usuario *seleccionarUsuario(string nickname);
        void listarProductos();
        void listarComentarios(int codigo);
        void seleccionarProducto(int codigo, string nickname);
        void tipoComentario();
        void deseaRespuestas();
        void seleccionarComentario(int id);
        void nuevoComentario(string comentario, DTFecha fechaDeComentario);
        void nuevaRespuesta(string comentario, DTFecha fechaDeComentario);
        void listarComentariosUsuario(string nickname);
        void setDTComentario(DTcomentario *comentario);
        void eliminarComentarioRecursivo(Comentario *comentario);
        void listaDeUsuarios_();
        void infoCliente(string nickname);
        void imprimirListaDeVendedores();
        void imprimirSuscripcionesDisponiblesPara(string nickname);
        void suscribirmeA(string nickname);
        bool existenUsuariosRegistrados();
        // void nuevaSuscripcion(string nickname);
};


#endif // CONTROLADORUSUARIOS_H
