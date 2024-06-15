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

/*Usuario *ControladorUsuarios::seleccionarVendedor(string username){
	map<string, Usuario *>::iterator it = usuarios.find(username);
	if (it != usuarios.end()){
		Usuario *usuario = it->second;
		if (usuario->esVendedor()) {
			Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);
				vector<DTInfoProducto> productos = vendedor->obtenerProductos();
				cout << "Productos del vendedor " << username << ":\n";
				for (vector<DTInfoProducto>::iterator prodIt = productos.begin(); prodIt != productos.end(); ++prodIt)
				{
					cout << prodIt->toString() << "\n";
				}
				return usuario;
		}
		else{
			cout << "El usuario " << username << " es un cliente.\n";
		}
	}
	else{
		cout << "Usuario " << username << " no encontrado.\n";
	}
	return nullptr;
}*/

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

/*set<DTComentario> ControladorUsuarios::seleccionarProducto(string nickname, int codigo)
{
	set<DTComentario> comentarios;
	map<string, Usuario*>::iterator it = usuarios.find(nickname);

	if (it != usuarios.end()){
		Vendedor *vendedor = dynamic_cast<Vendedor*>(it->second);{
			vector<Producto> productos = vendedor->getProductos();
			for (vector<Producto>::iterator prodIt = productos.begin(); prodIt != productos.end(); ++prodIt){
				if (prodIt->getCodigo() == codigo){
					vector<Comentario> comentariosProducto = prodIt->getComentarios();
					for (vector<Comentario>::iterator comIt = comentariosProducto.begin(); comIt != comentariosProducto.end(); ++comIt)
					{
						DTComentario dtComentario(comIt->getTexto(), comIt->getFecha());
						comentarios.insert(dtComentario);
					}
					return comentarios;
				}
			}
		}
	}

	cout << "Codigo o vendedor incorrectos.\n";
	return comentarios;
}*/

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