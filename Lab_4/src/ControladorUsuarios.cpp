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

void ControladorUsuarios::seleccionarVendedor(string username){
	string vendedorSeleccionado = username;
}

void ControladorUsuarios::listarProductosVendedor(){
	map<string, Usuario *>::iterator it = usuarios.find(vendedorSeleccionado);
	if (it != usuarios.end())
	{
		Usuario *usuario = it->second;
		if (usuario->esVendedor()){
			Vendedor *vendedor = dynamic_cast<Vendedor *>(usuario);
			vector<DTInfoProducto> productos = vendedor->obtenerProductos();
			cout << "Productos del vendedor " << vendedorSeleccionado << ":\n";
			for (vector<DTInfoProducto>::iterator prodIt = productos.begin(); prodIt != productos.end(); ++prodIt){
				cout << prodIt->toString() << "\n";
			}
		}
		else{
			cout << "El usuario " << vendedorSeleccionado << " es un cliente.\n";
		}
	}
	else{
		cout << "Usuario " << vendedorSeleccionado << " no encontrado.\n";
	}
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

void ControladorUsuarios::listarComentarios(int codigo) {
    set<DTcomentario> comentarios;
    map<string, Usuario*>::iterator it = usuarios.find(vendedorSeleccionado);
    if (it != usuarios.end()) {
        Vendedor* vendedor = dynamic_cast<Vendedor*>(it->second);
        if (vendedor) {
            set<Producto*> productosVendedor = vendedor->getProductos();
            for (set<Producto*>::iterator prodIt = productosVendedor.begin(); prodIt != productosVendedor.end(); ++prodIt) {
				if (prodIt != productosVendedor.end()){
					if ((*prodIt)->getCodigo() == codigo){
						map<int, Comentario *> comentarios = (*prodIt)->getComentarios();
						for (map<int, Comentario *>::iterator comIt = comentarios.begin(); comIt != comentarios.end(); ++comIt)
						{
							Comentario *comentario = comIt->second;
							cout << "ID: " << comentario->getId() << ", Texto: " << comentario->getTexto()
								 << ", Fecha: " << comentario->getFecha().toString() << "\n";
						}
					}
				else {
					cout << "Prodcuto no encontrado.\n" ;
				}
				}
            }
        }
    } else {
        cout << "Vendedor no seleccionado o no encontrado.\n";
    }
}

void ControladorUsuarios::seleccionarComentario(int id)
{
	int idSeleccionado = id;
}

void ControladorUsuarios::deseaRespuestas(){
	cout << "¿Desea desplegar respuestas a un comentario? (Y/N): ";
	char respuesta;
	cin >> respuesta;
	if (respuesta == 'Y' || respuesta == 'y'){
		cout << "Ingrese ID de comentario a desplegar: ";
		int comentario;
		cin >> comentario;
		idSeleccionado = comentario;
	}
}

void ControladorUsuarios::seleccionarProducto(int codigo){
	int codigoSeleccionado = codigo;
}

void ControladorUsuarios::tipoComentario(){
	cout << "¿Desea realizar un comentario nuevo? (Y/N): ";
	char respuesta;
	cin >> respuesta;
	if (respuesta == 'Y' || respuesta == 'y'){
		respuestaSeleccionada = true;
	}
	else if (respuesta == 'N' || respuesta == 'n'){
		respuestaSeleccionada = false;
	}
	else{
		cout << "Respuesta no válida." << endl;
	}
}


void ControladorUsuarios::nuevoComentario(string comentario, DTFecha fechaDeComentario){
	map<string, Usuario *>::iterator it = usuarios.find(vendedorSeleccionado);
    if (it == usuarios.end()) {
        cout << "Vendedor no seleccionado o no encontrado.\n";
        return;
    }
    Vendedor* vendedor = dynamic_cast<Vendedor*>(it->second);
    if (!vendedor) {
        cout << "Vendedor no encontrado o no es un vendedor válido.\n";
        return;
    }
    set<Producto*> productosVendedor = vendedor->getProductos();
    Producto* productoSeleccionado = nullptr;
    for (set<Producto*>::iterator prodIt = productosVendedor.begin(); prodIt != productosVendedor.end(); ++prodIt) {
        if ((*prodIt)->getCodigo() == codigoSeleccionado) {
            productoSeleccionado = *prodIt;
            break;
        }
    }
    if (!productoSeleccionado) {
        cout << "Producto no encontrado.\n";
        return;
    }
	int idComentario = creadorIdComentario++;
	Comentario* nuevoComentario = new Comentario(idComentario, comentario, fechaDeComentario);
    if (respuestaSeleccionada == true) {
        productoSeleccionado->agregarComentario(nuevoComentario);
    }  else if (respuestaSeleccionada == false) {
        map<int, Comentario*> comentariosProducto = productoSeleccionado->getComentarios();
        Comentario* comentarioParaResponder = nullptr;
        map<int, Comentario*>::iterator comIt = comentariosProducto.find(idSeleccionado);
        if (comIt != comentariosProducto.end()) {
            comentarioParaResponder = comIt->second;
        }
        if (comentarioParaResponder) {
            comentarioParaResponder->agregarRespuesta(nuevoComentario);
        } else {
            cout << "Comentario con ID " << idSeleccionado << " no encontrado.\n";
            delete nuevoComentario;
		}
    } else {
        cout << "Opción de respuesta no válida.\n";
        delete nuevoComentario; 
    }
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
		printf("aaaaaaaaaaaaaaaaaaa\n");
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