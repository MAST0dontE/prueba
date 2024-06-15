#include "ControladorUsuarios.h"

void ControladorUsuarios::setCliente(Cliente *cliente)
{
	this->clientes[cliente->getNickname()] = cliente;
}

void ControladorUsuarios::setVendedor(Vendedor *vendedor)
{
	this->vendedores[vendedor->getNickname()] = vendedor;
}

void ControladorUsuarios::setComentario(Comentario *comentario)
{
	// Implementación
}

bool ControladorUsuarios::altaCliente(string username, string password, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad)
{
    if (clientes.find(username) != clientes.end()) {
        return false;
    }
    Cliente* nuevoCliente = new Cliente(password, username, fechaNacimiento, direccion, ciudad);
    setCliente(nuevoCliente);
    return true; 
}


bool ControladorUsuarios::altaVendedor(string username, string password, DTFecha fechaNacimiento, string codigoRUT)
{
	if (vendedores.find(username) != vendedores.end()) {
        return false;
    }
    Vendedor* nuevoVendedor = new Vendedor(password, username, fechaNacimiento, codigoRUT);
    setVendedor(nuevoVendedor);
    return true; 
}

set<string> ControladorUsuarios::listaDeVendedores() {
	set<string> listaVendedores;
	for (map<string, Vendedor*>::iterator it = vendedores.begin(); it != vendedores.end(); ++it) {
		listaVendedores.insert(it->first);
	}
	return listaVendedores;
}

Usuario *ControladorUsuarios::seleccionarUsuario(string username){
    if (clientes.find(username) != clientes.end()) {
        return clientes.find(username)->second;
    }
    if (vendedores.find(username) != vendedores.end()) {
        return vendedores.find(username)->second;
    }
	//en caso de que no exista
    return nullptr;  
}



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
	for (it1= clientes.begin(); it1!=clientes.end(); ++it1){
		printf( "(%s)\n", it1->first.c_str() );
		printf( "(%s)\n", it1->second->getFecha().c_str() );
		printf( "(%s)\n", it1->second->getCiudadResidencia().c_str() );
	}
		for (it2= vendedores.begin(); it2!=vendedores.end(); ++it2){
		printf( "(%s)\n", it2->first.c_str() );
		printf( "(%s)\n", it2->second->getFecha().c_str() );
		printf( "(%s)\n", it2->second->getCodigoRUT().c_str() );
	}
	/*for (vector<Vendedor*>::iterator it = Vendedores.begin(); it != Vendedores.end(); ++it) {
		printf( "(%s)\n", (*it)->getNickname().c_str() );
		printf( "(%s)\n", (*it)->getFecha().c_str() );
		printf( "(%s)\n", (*it)->getCodigoRUT().c_str() );
	}
	for (vector<Cliente*>::iterator it = Clientes.begin(); it != Clientes.end(); ++it) {
		printf( "(%s)\n", (*it)->getNickname().c_str() );
		printf( "(%s)\n", (*it)->getFecha().c_str() );
		printf( "(%s)\n", (*it)->getCiudadResidencia().c_str() );
	}	*/
}