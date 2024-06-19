#include "ControladorUsuarios.h"

ControladorUsuarios * ControladorUsuarios::controladorUsuariosInst = nullptr;

ControladorUsuarios::ControladorUsuarios(){
	//constructor
}

ControladorUsuarios * ControladorUsuarios::getControladorUsuarios(){
	if (!controladorUsuariosInst){
		controladorUsuariosInst = new ControladorUsuarios();
	}
	return controladorUsuariosInst;
}

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


bool ControladorUsuarios::altaCliente(string nickname, string contrasenia, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad)
{
    if (clientes.find(nickname) != clientes.end()) {
        return false;
    }
    Cliente* nuevoCliente = new Cliente(nickname, contrasenia, fechaNacimiento, direccion, ciudad);
    this->setCliente(nuevoCliente);
	ControladorVentas* controladorVentas = ControladorVentas::getControladorVentas();
	controladorVentas->setCliente(nuevoCliente);
    return true; 
}


bool ControladorUsuarios::altaVendedor(string nickname, string contrasenia, DTFecha fechaNacimiento, string codigoRUT)
{
	if (vendedores.find(nickname) != vendedores.end()) {
        return false;
    }
    Vendedor* nuevoVendedor = new Vendedor(nickname, contrasenia, fechaNacimiento, codigoRUT);
    setVendedor(nuevoVendedor);
	ControladorVentas* controladorVentas = ControladorVentas::getControladorVentas();	
	controladorVentas->setVendedor(nuevoVendedor);
    return true; 
}

set<string> ControladorUsuarios::listaDeVendedores()
{
	set<string> listaVendedores;
	for (map<string, Vendedor*>::iterator it = vendedores.begin(); it != vendedores.end(); ++it)
	{
		listaVendedores.insert(it->first);
	}
	return listaVendedores;
}

void ControladorUsuarios::imprimirListaDeVendedores(){
	cout<<"Se listan los nicknames de todos los vendedores registrados en el sistema:"<<endl;
	map<string, Vendedor*>::iterator it;
    for(it=vendedores.begin(); it != vendedores.end(); ++it){
        Vendedor* vendedor = it->second;
        cout<< vendedor->getNickname() << endl;
    }
}



set<string> ControladorUsuarios::listaDeUsuarios() {
	set<string> listaUsuarios;
	for (map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
		listaUsuarios.insert(it->first);
	}
	return listaUsuarios;
}

void ControladorUsuarios::seleccionarUsuario_(string nickname){
	string usuarioSeleccionado = nickname;
}

void ControladorUsuarios::listarProductos(){
	for (map<string, Vendedor*>::iterator it = vendedores.begin(); it != vendedores.end(); ++it){
		if (it != vendedores.end()){
			Vendedor *vendedor = it->second;
			vector<DTInfoProducto> productos = vendedor->obtenerProductos();
			cout << "Productos del vendedor " << it->first << ":\n";
			for (vector<DTInfoProducto>::iterator prodIt = productos.begin(); prodIt != productos.end(); ++prodIt){
				cout << prodIt->toString() << "\n";
			}
		}
	}
}

void ControladorUsuarios::seleccionarProducto(int codigo, string nickname){
	int codigoSeleccionado = codigo;
	string vendedorProductoSeleccionado = nickname;
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
		void tipoComentario();
	}
}

void ControladorUsuarios::nuevoComentario(string comentario, DTFecha fechaDeComentario){
	map<string, Usuario*>::iterator it = usuarios.find(vendedorProductoSeleccionado);
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
    productoSeleccionado->agregarComentario(nuevoComentario);
	map<string, Usuario *>::iterator itU = usuarios.find(usuarioSeleccionado);
	if (itU != usuarios.end()){
		Usuario *usuarioActual = itU->second;
		if (usuarioActual->esVendedor()){
		Vendedor *vendedorActual = dynamic_cast<Vendedor*>(itU->second);
		vendedorActual->agregarComentario(nuevoComentario);
		}
		else {
			Cliente *clienteActual = dynamic_cast<Cliente*>(itU->second);
			clienteActual->agregarComentario(nuevoComentario);
		}
	}
}

void ControladorUsuarios::nuevaRespuesta(string comentario, DTFecha fechaDeComentario){
	map<string, Usuario*>::iterator it = usuarios.find(vendedorProductoSeleccionado);
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
	map<string, Usuario *>::iterator itU = usuarios.find(usuarioSeleccionado);
	if (itU != usuarios.end()){
		Usuario *usuarioActual = itU->second;
		if (usuarioActual->esVendedor()){
		Vendedor *vendedorActual = dynamic_cast<Vendedor*>(itU->second);
		vendedorActual->agregarComentario(nuevoComentario);
		}
		else {
			Cliente *clienteActual = dynamic_cast<Cliente*>(itU->second);
			clienteActual->agregarComentario(nuevoComentario);
		}
	}
}



void ControladorUsuarios::listarComentarios(int codigo) {
    map<string, Usuario*>::iterator it = usuarios.find(vendedorProductoSeleccionado);
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

void ControladorUsuarios::listarComentariosUsuario(string nickname)
{
	map<string, Usuario*>::iterator it = usuarios.find(vendedorProductoSeleccionado);
	if (it != usuarios.end())
	{
		Vendedor *vendedor = dynamic_cast<Vendedor*>(it->second);
		if (vendedor){
			map<int, Comentario *> comentarios = vendedor->getComentarios();
			for (map<int, Comentario *>::iterator comIt = comentarios.begin(); comIt != comentarios.end(); ++comIt){
				Comentario *comentario = comIt->second;
				cout << "ID: " << comentario->getId() << ", Texto: " << comentario->getTexto() \
					 << ", Fecha: " << comentario->getFecha().toString() << "\n";
			}
		}
		else if (!vendedor){
			Cliente *cliente = dynamic_cast<Cliente*>(it->second);
			if (cliente){
				map<int, Comentario *> comentarios = cliente->getComentarios();
				for (map<int, Comentario *>::iterator comIt = comentarios.begin(); comIt != comentarios.end(); ++comIt){
					Comentario *comentario = comIt->second;
					cout << "ID: " << comentario->getId() << ", Texto: " << comentario->getTexto() \
						 << ", Fecha: " << comentario->getFecha().toString() << "\n";
				}
			}
		}
	}
}

void ControladorUsuarios::eliminarComentario(int id)
{
	// Implementación
}

Usuario *ControladorUsuarios::seleccionarUsuario(string nickname)
{
	if (clientes.find(nickname) != clientes.end())
	{
		return clientes.find(nickname)->second;
	}
	if (vendedores.find(nickname) != vendedores.end())
	{
		return vendedores.find(nickname)->second;
	}
	// en caso de que no exista
	return nullptr;
}

/*void ControladorUsuarios::setDTComentario(DTcomentario *comentario)
{
	// Implementación
}*/


set<string> ControladorUsuarios::suscribirseA(string)
{
    return set<string>();
}

set<DTNotificacion> ControladorUsuarios::consultarNotificaciones(string nickname)
{
	// Implementación
	return set<DTNotificacion>();
}

void ControladorUsuarios::eliminarSuscripciones(string nickname)
{
	// Implementación
}
void ControladorUsuarios::listaDeUsuarios_(){
	map<string, Cliente*>::iterator it1;
	map<string, Vendedor*>::iterator it2;
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



void ControladorUsuarios::imprimirSuscripcionesDisponibles(string nickname){
	map<string, Vendedor*>::iterator it;
	for (it= vendedores.begin(); it!=vendedores.end(); ++it){
		bool suscripto = it->second->estaSuscripto(nickname);
		if(!suscripto){
			cout<<it->first<<endl;
			cout<<"aaaaaa"<<endl;
		}
	}
}