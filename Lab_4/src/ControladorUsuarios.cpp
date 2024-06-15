#include "ControladorUsuarios.h"

void ControladorUsuarios::setCliente(Cliente *cliente)
{
	// Implementación
}

void ControladorUsuarios::setVendedor(Vendedor *vendedor)
{
	// Implementación
}

void ControladorUsuarios::setComentario(Comentario *comentario)
{
	// Implementación
}

bool ControladorUsuarios::altaCliente(string username, string password, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad)
{
	// Implementación
	return true;
}

bool ControladorUsuarios::altaVendedor(string username, string password, DTFecha fechaNacimiento, string codigoRUT)
{
	// Implementación
	return true;
}

set<string> ControladorUsuarios::listaDeUsuarios() {
	set<string> listaUsuarios;
	for (vector<Usuario*>::iterator it = Usuarios.begin(); it != Usuarios.end(); ++it) {
		listaUsuarios.insert((*it)->getNickname());
	}
	return listaUsuarios;
}

/*Usuario *ControladorUsuarios::seleccionarUsuario(string username){
	for (vector<Usuario*>::iterator it = Usuarios.begin(); it != Usuarios.end(); ++it){
		if ((*it)->getNickname() == username){
			Usuario *usuario = *it;
			if (usuario->esVendedor()){
				Vendedor *vendedor = dynamic_cast<Vendedor*>(usuario);
				vector<DTInfoProducto> productos = vendedor->listarProductos();
				cout << "Productos del vendedor " << username << ":\n";
				for (vector<DTinfoProducto>::iterator prodIt = productos.begin(); prodIt != productos.end(); ++prodIt){
					cout << prodIt->toString() << "\n";
				}
			}
			else{
				cout << "El usuario " << username << " es un cliente.\n";
			}
			return usuario;
		}
	}
	cout << "Usuario " << username << " no encontrado.\n";
	return nullptr;
}
*/

void ControladorUsuarios::seleccionarComentario(DTcomentario *comentario)
{
}

/*void ControladorUsuarios::setDTComentario(DTcomentario *comentario)
{
	// Implementación
}*/

void ControladorUsuarios::eliminarComentario(DTcomentario *comentario)
{
	// Implementación
}

set<string> ControladorUsuarios::suscribirseA(string)
{
    return set<string>();
}

set<DTNotificacion> ControladorUsuarios::consultarNotificaciones(string username)
{
	// Implementación
	return set<DTNotificacion>();
}

void ControladorUsuarios::eliminarSuscripciones(string username)
{
	// Implementación
}
void ControladorUsuarios::listaDeUsuarios_(){
	for (vector<Vendedor*>::iterator it = Vendedores.begin(); it != Vendedores.end(); ++it) {
		printf( "(%s)\n", (*it)->getNickname().c_str() );
		printf( "(%s)\n", (*it)->getFecha().c_str() );
		printf( "(%s)\n", (*it)->getCodigoRUT().c_str() );
	}
	for (vector<Cliente*>::iterator it = Clientes.begin(); it != Clientes.end(); ++it) {
		printf( "(%s)\n", (*it)->getNickname().c_str() );
		printf( "(%s)\n", (*it)->getFecha().c_str() );
		printf( "(%s)\n", (*it)->getCiudadResidencia().c_str() );
	}	
}