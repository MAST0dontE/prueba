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

Usuario *ControladorUsuarios::seleccionarVendedor(string username){
	map<string,Usuario*>::iterator it = usuarios.find(username);
	if (it != usuarios.end()){
		Usuario *usuario = it->second;
		if (usuario->esVendedor()) {
			string vendedorSeleccionado = username;
			Vendedor *vendedor = dynamic_cast<Vendedor*>(usuario);
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

/*set<DTcomentario> ControladorUsuarios::seleccionarProducto( int codigo){
	set<DTcomentario> comentarios;
	map<string,Usuario*>::iterator it = usuarios.find(vendedorSeleccionado);
	if (it != usuarios.end()){
		Vendedor *vendedor = dynamic_cast<Vendedor*>(it->second);
		if (vendedor){
			set<Producto*> productosVendedor = vendedor->getProductos();
			for (set<Producto*>::iterator prodIt = productosVendedor.begin(); prodIt != productosVendedor.end(); ++prodIt){
				if ((*prodIt)->getCodigo() == codigo){
					vector<Comentario*> comentariosProducto = (*prodIt)->getComentarios();
					for (vector<Comentario*>::iterator comIt = comentariosProducto.begin(); comIt != comentariosProducto.end(); ++comIt){
						Comentario* comentario = *comIt;
						DTcomentario dtComentario(comentario->getId(), comentario->getTexto(), comentario->getFecha());
						comentarios.insert(dtComentario);
					}
					cout << "Comentarios del producto con código " << codigo << ":\n";
					for (set<DTcomentario>::iterator comIt = comentarios.begin(); comIt != comentarios.end(); ++comIt){
						cout << comIt->toString() << "\n";
					}
					return comentarios;
				}
			}
			cout << "Producto no encontrado.\n";
		}
	}
	else{
		cout << "Vendedor no seleccionado o no encontrado.\n";
	}
	return comentarios;
}*/

void ControladorUsuarios::seleccionarProducto(int codigo){
	codigoSeleccionado = codigo;
}

	void ControladorUsuarios::seleccionarComentario(DTcomentario * comentario)
	{
	}

	/*void ControladorUsuarios::setDTComentario(DTcomentario *comentario)
	{
		// Implementación
	}*/

	void ControladorUsuarios::eliminarComentario(DTcomentario * comentario)
	{
		// Implementación
	}

	set<string> ControladorUsuarios::suscribirseA(string)
	{
		return set<string>();
	}

set<DTNotificacion> ControladorUsuarios::consultarNotificaciones(string username)
{
	Cliente *C=clientes[username];
	set<DTNotificacion> Notificaciones_=C->getNotificaciones();
	C->borrarNotificaciones();
	return Notificaciones_;
}

void ControladorUsuarios::eliminarSuscripciones(string username)
{
	// Implementación
}



/*El caso de uso comienza cuando se desea consultar la información de todos
los usuarios del sistema. Para esto, el Sistema lista los nicknames
(pseudónimos) de todos los usuarios junto a la fecha de nacimiento. En caso
de que el usuario sea un cliente, adicionalmente se muestra su dirección y
ciudad de residencia, mientras que, si se trata de un vendedor, se muestra
su código RUT*/
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

/*static string compraPorProductoAString(CompraPorProducto* compraPorProducto) {

}*/

/*static string compraAString(Compra* compra) {
	for (auto itSet= productos.begin(); itSet != productos.end(); ++itSet) {
        compraPorProductoAString
    }
    std::cout << std::endl;
	
}*/

/*string ControladorUsuarios::infoCliente(string nickname) {
	if (!esVendedor())
		Cliente clienteInfo = clientes.find(nickname);
		cout << "Nickname: " << getNickname(clienteInfo);
		cout << "Fecha de nacimiento: " << getFecha(clienteInfo);
		for ( i = 0; i < count; i++)
		{
			
		}
		
	}
}*/