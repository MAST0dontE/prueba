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
	ControladorVentas controladorVentas;
	controladorVentas.setCliente(nuevoCliente);
    return true; 
}


bool ControladorUsuarios::altaVendedor(string username, string password, DTFecha fechaNacimiento, string codigoRUT)
{
	if (vendedores.find(username) != vendedores.end()) {
        return false;
    }
    Vendedor* nuevoVendedor = new Vendedor(password, username, fechaNacimiento, codigoRUT);
    setVendedor(nuevoVendedor);
	ControladorVentas controladorVentas;
	controladorVentas.setVendedor(nuevoVendedor);
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
    } /*else if (respuestaSeleccionada == false) {
        // Buscar el comentario con el ID seleccionado para responder
        map<int, Comentario*>  = productoSeleccionado->getComentarios();
        Comentario* comentarioParaResponder = nullptr;
        for (map<int, Comentario*>::iterator comIt = comentariosProducto.begin(); comIt != comentariosProducto.end(); ++comIt) {
            if ((*comIt)->getId() == idSeleccionado) {
                comentarioParaResponder = *comIt;
                break;
            }
        }
        if (comentarioParaResponder) {
            // Agregar la respuesta al comentario encontrado
            comentarioParaResponder->agregarRespuesta(nuevoComentario);
        } else {
            cout << "Comentario con ID " << idSeleccionado << " no encontrado.\n";
            delete nuevoComentario; // Limpiar el comentario creado si no se usó
        }
    }*/
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

//Imprime el producto y la cantidad de una instancia CompraPorProducto
static void compraPorProductoAString(CompraPorProducto* compraPorProducto) {
	cout << "Producto: " << compraPorProducto->getCodigoProducto() << "\n" << endl;
	cout << "Cantidad: " << compraPorProducto->getCantidadSolicitada() << "\n" << endl; 
	cout << "Vendedor: " << compraPorProducto->getVendedor() << "\n" << endl;
}

//Imprime cada producto y cantidad solicitada en una compra
static void compraAString(Compra* compra) {
	for (auto compraPorProductoit= compra->getProductos().begin(); compraPorProductoit != compra->getProductos().end(); ++compraPorProductoit) {
		CompraPorProducto* productoActuallIterador = *compraPorProductoit;
		compraPorProductoAString(productoActuallIterador);
    }	
}


void ControladorUsuarios::infoCliente(string nickname) {
	
	Cliente* clienteInfo = clientes.find(nickname)->second;
	cout << "Nickname: " << clienteInfo->getNickname() << "\n" << endl;
	cout << "Fecha de nacimiento: " << clienteInfo->getFecha() << "\n" << endl;
	cout << "Compras realizadas:" << "\n" << endl;
	for (auto it = clienteInfo->getComprasRealizadas().begin(); it != clienteInfo->getComprasRealizadas().end(); ++it) {
	Compra* compraActualIt = *it;
    compraAString(compraActualIt);
	cout << "Monto total: " << compraActualIt->getMontoTotal() << "\n" << endl;
	cout << "Fecha: " << compraActualIt->getFechaDeCompra() << "\n" << endl;
        		
	}
}

void ControladorUsuarios::infoVendedor(string nickname) {

}
