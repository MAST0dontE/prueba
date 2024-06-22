#include "ControladorUsuarios.h"

ControladorUsuarios* ControladorUsuarios::controladorUsuariosInst = nullptr;

ControladorUsuarios::ControladorUsuarios(){
	//constructor
}

ControladorUsuarios* ControladorUsuarios::getControladorUsuarios(){
	if (!controladorUsuariosInst){
		controladorUsuariosInst = new ControladorUsuarios();
	}
	return controladorUsuariosInst;
}

void ControladorUsuarios::setCliente(Cliente *cliente){
	this->clientes[cliente->getNickname()] = cliente;
	this->usuarios[cliente->getNickname()] = cliente;
}

void ControladorUsuarios::setVendedor(Vendedor *vendedor){
	this->vendedores[vendedor->getNickname()] = vendedor;
	this->usuarios[vendedor->getNickname()] = vendedor;
}

	bool ControladorUsuarios::altaCliente(string nickname, string contrasenia, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad)
	{
		if (clientes.find(nickname) != clientes.end() || vendedores.find(nickname) != vendedores.end())
		{
			return false;
		}
		Cliente *nuevoCliente = new Cliente(nickname, contrasenia, fechaNacimiento, direccion, ciudad);
		this->setCliente(nuevoCliente);
		ControladorVentas *controladorVentas = ControladorVentas::getControladorVentas();
		controladorVentas->setCliente(nuevoCliente);
		return true;
}

bool ControladorUsuarios::existeNickname(string nickname){
	if (vendedores.find(nickname) != vendedores.end() || clientes.find(nickname) != clientes.end()) {
        return true;
    }
	else return false;
}

bool ControladorUsuarios::altaVendedor(string nickname, string contrasenia, DTFecha fechaNacimiento, string codigoRUT)
{
	if (vendedores.find(nickname) != vendedores.end() || clientes.find(nickname) != clientes.end()) {
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

void ControladorUsuarios::imprimirListaDeUsuarios(){
	cout<<"Se listan los nicknames de todos los usuarios registrados en el sistema:"<<endl;
	map<string, Usuario*>::iterator it;
    for(it=usuarios.begin(); it != usuarios.end(); ++it){
        Usuario* usuario = it->second;
		if (usuario->esVendedor()){
			Vendedor* vendedor = dynamic_cast<Vendedor*>(usuario);
			cout << vendedor->getNickname() << endl;
		}
		else{
			Cliente* cliente = dynamic_cast<Cliente*>(usuario);
			cout << cliente->getNickname() << endl;
		}
    }
}

void ControladorUsuarios::imprimirListaDeVendedores(){
	cout<<"Se listan los nicknames de todos los vendedores registrados en el sistema:"<<endl;
	map<string, Vendedor*>::iterator it;
    for(it=vendedores.begin(); it != vendedores.end(); ++it){
        Vendedor* vendedor = it->second;
        cout<< vendedor->getNickname() << endl;
    }
}

void ControladorUsuarios::imprimirListaDeClientes(){
	cout<<"Se listan los nicknames de todos los clientes registrados en el sistema:"<<endl;
	map<string, Cliente*>::iterator it;
    for(it=clientes.begin(); it != clientes.end(); ++it){
        Cliente* cliente = it->second;
        cout<< cliente->getNickname() << endl;
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
	this->usuarioSeleccionado = nickname;
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
	this->codigoSeleccionado = codigo;
	this->vendedorProductoSeleccionado = nickname;
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
	map<string, Usuario*>::iterator itU = usuarios.find(usuarioSeleccionado);
	if (itU == usuarios.end()){
		cout << "Usuario no seleccionado o no encontrado.\n";
		return;
	}
	else{
		map<string, Usuario *>::iterator it = usuarios.find(vendedorProductoSeleccionado);
		if (it == usuarios.end()){
			cout << "Vendedor no seleccionado o no encontrado.\n";
			return;
		}
		Vendedor *vendedor = dynamic_cast<Vendedor *>(it->second);
		if (!vendedor){
			cout << "Vendedor no encontrado o no es un vendedor válido.\n";
			return;
		}
		set<Producto *> productosVendedor = vendedor->getProductos();
		Producto *productoSeleccionado = nullptr;
		for (set<Producto *>::iterator prodIt = productosVendedor.begin(); prodIt != productosVendedor.end(); ++prodIt){
			if ((*prodIt)->getCodigo() == codigoSeleccionado){
				productoSeleccionado = *prodIt;
				break;
			}
		}
		if (!productoSeleccionado){
			cout << "Producto no encontrado.\n";
			return;
		}
		int idComentario = creadorIdComentario++;
		Comentario *nuevoComentario = new Comentario(idComentario, comentario, fechaDeComentario);
		nuevoComentario->setAutor(usuarioSeleccionado);
		nuevoComentario->setProducto(productoSeleccionado);
		nuevoComentario->setComentarioPadre(nuevoComentario);
		productoSeleccionado->agregarComentario(nuevoComentario);
		Usuario *usuarioActual = itU->second;
		if (usuarioActual->esVendedor()){
			Vendedor *vendedorActual = dynamic_cast<Vendedor *>(itU->second);
			vendedorActual->agregarComentario(nuevoComentario);
		}
		else{
			Cliente *clienteActual = dynamic_cast<Cliente *>(itU->second);
			clienteActual->agregarComentario(nuevoComentario);
		}
	}
}

void ControladorUsuarios::nuevaRespuesta(string comentario, DTFecha fechaDeComentario){
	 map<string, Usuario*>::iterator it = usuarios.find(comentador);
    if (it == usuarios.end()) {
        cout << "Usuario comentador no encontrado.\n";
        return;
    }
	map<string, Usuario *>::iterator itU = usuarios.find(usuarioSeleccionado);
	if (itU == usuarios.end()){
		cout << "Usuario no seleccionado o no encontrado.\n";
		return;
	}
    Usuario* comentadorActual = it->second;
    map<int, Comentario*> comentarios;
    if (comentadorActual->esVendedor()) {
        Vendedor* comentadorVendedor = dynamic_cast<Vendedor*>(comentadorActual);
        comentarios = comentadorVendedor->getComentarios();
    } 
	else{
        Cliente* comentadorCliente = dynamic_cast<Cliente*>(comentadorActual);
        comentarios = comentadorCliente->getComentarios();
    }
    Comentario* comentarioR = nullptr;
    map<int, Comentario*>::iterator comIt = comentarios.find(idSeleccionado);
    if (comIt != comentarios.end()) {
        comentarioR = comIt->second;
    }
	else{
        cout << "Comentario con ID " << idSeleccionado << " no encontrado.\n";
        return;
    }
	int idComentario = creadorIdComentario++;
	Comentario* nuevoComentario = new Comentario(idComentario, comentario, fechaDeComentario);
	Comentario* comentarioPadre = comentarioR->getComentarioPadre();
	nuevoComentario->setComentarioPadre(comentarioPadre);
	nuevoComentario->setAutor(usuarioSeleccionado);
	map<int, Comentario*> respuestasPadre = comentarioPadre->getRespuestas();
    Comentario* comentarioParaResponder = nullptr;
    map<int, Comentario*>::iterator comIt2 = respuestasPadre.find(idSeleccionado);
    if (comIt2 != respuestasPadre.end()) {
        comentarioParaResponder = comIt2->second;
	}
	if (comentarioParaResponder) {
        comentarioParaResponder->agregarRespuesta(nuevoComentario);
    } else {
        cout << "Comentario con ID " << idSeleccionado << " no encontrado.\n";
        delete nuevoComentario;
	}
	Usuario *usuarioActual = itU->second;
	if (usuarioActual->esVendedor()){
	Vendedor *vendedorActual = dynamic_cast<Vendedor*>(itU->second);
	vendedorActual->agregarComentario(nuevoComentario);
	}
	else{
		Cliente* clienteActual = dynamic_cast<Cliente*>(itU->second);
		clienteActual->agregarComentario(nuevoComentario);
	}
}




void ControladorUsuarios::listarComentarios(int codigo) {
    map<string, Vendedor*>::iterator it = vendedores.find(vendedorProductoSeleccionado);
    if (it != vendedores.end()) {
        Vendedor* vendedor = it->second;
        if (vendedor) {
            set<Producto*> productosVendedor = vendedor->getProductos();
            for (set<Producto*>::iterator prodIt = productosVendedor.begin(); prodIt != productosVendedor.end(); ++prodIt) {
				if (prodIt != productosVendedor.end()){
					if ((*prodIt)->getCodigo() == codigo){
						map<int, Comentario *> comentarios = (*prodIt)->getComentarios();
						for (map<int, Comentario *>::iterator comIt = comentarios.begin(); comIt != comentarios.end(); ++comIt){
							Comentario *comentario = comIt->second;
							cout << "ID: " << comentario->getId() << ", Texto: " << comentario->getTexto()
								 << ", Fecha: " << comentario->getFecha().toString() << ", Autor: " << comentario->getAutor() << "\n";
						}
					}
				}
				else {
					cout << "Prodcuto no encontrado.\n" ;
				}
            }
		}
	}
	else{
		cout << "Vendedor no seleccionado o no encontrado.\n";
	}
}

void ControladorUsuarios::seleccionarComentario(int id, string nickname)
{
	this->idSeleccionado = id;
	this->comentador = nickname;
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

void ControladorUsuarios::eliminarComentarioRecursivo(Comentario* comentario) {
    map<int, Comentario*>& respuestas = comentario->getRespuestas();
    for (map<int, Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it) {
        eliminarComentarioRecursivo(it->second);
    }
    for (map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it) {
        Usuario* usuarioActual = it->second;
        if (!usuarioActual->esVendedor()) {
            Cliente* cliente = dynamic_cast<Cliente*>(usuarioActual);
            if (cliente) {
                cliente->eliminarComentario(comentario->getId());
            }
        } else {
            Vendedor* vendedor = dynamic_cast<Vendedor*>(usuarioActual);
            if (vendedor) {
                vendedor->eliminarComentario(comentario->getId());
            }
        }
    }
    Comentario* comentarioPadre = comentario->getComentarioPadre();
    if (comentarioPadre) {
        comentarioPadre->getRespuestas().erase(comentario->getId());
    } else {
        Producto* producto = comentario->getProducto();
        if (producto) {
            producto->eliminarComentario(comentario->getId());
        }
    }
    delete comentario;
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


void ControladorUsuarios::consultarNotificaciones(string nickname){
	Cliente *cliente = clientes[nickname];
	map<int, DTNotificacion> notificaciones = cliente->getNotificaciones();
	map<int, DTNotificacion>::iterator it;
	if(notificaciones.empty()){
		cout<<"El usuario "<<nickname<<" no tiene nuevas notificaciones"<<endl;
	}
	else{
	for(it=notificaciones.begin();it!=notificaciones.end();++it){
		cout<<"aaaaa"<<endl;
		cout<<it->second.getNicknameVendedor()<<it->second.getNombrePromo()<<it->second.getDTInfoProducto()<<endl;
	}
	cliente->borrarNotificaciones();
	}
}

void ControladorUsuarios::eliminarSuscripciones(string nicknameCliente){
	Vendedor* vendedor = this->vendedores[nicknameCliente];
	vendedor->removerSuscriptor(this->clientes[nicknameCliente]);
	
}

void ControladorUsuarios::listarSuscripciones(string nickname){
	map<string, Vendedor*>::iterator it;
	this->nombreNuevoSuscriptor = nickname;
	cout<<"Las suscripciones disponibles para "<< nickname <<" son:"<<endl;
	for (it= vendedores.begin(); it!=vendedores.end(); ++it){
		bool suscripto = it->second->estaSuscripto(nickname);
		if(suscripto){
			cout<<it->first<<endl;
		}
	}
}

void ControladorUsuarios::listaDeUsuarios_(){
	map<string, Cliente*>::iterator it1;
	map<string, Vendedor*>::iterator it2;
	if(clientes.empty() && vendedores.empty()){
		cout<<"En este momento no existe ningun usario registrado en el sistema."<<endl;
	} else{
		cout<<"A continuacion se listan los usuarios registrados actualmente en el sistema:"<<endl;
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
		CompraPorProducto* productoActuallIterador = compraPorProductoit->second;
		compraPorProductoAString(productoActuallIterador);
    }	
}


void ControladorUsuarios::infoCliente(string nickname) {
	
	Cliente* clienteInfo = clientes.find(nickname)->second;
	if (clienteInfo->getNickname() == nickname) {		
		cout << "Nickname: " << clienteInfo->getNickname() << endl;
		cout << "Fecha de nacimiento: " << clienteInfo->getFecha() << "\n" << endl;
		if (clienteInfo->getComprasRealizadas().empty()){
			cout <<"El cliente no ha realizado compras." << "\n" << endl;
		}
		else{
			cout << "Compras realizadas: " << endl;
			for (auto it = clienteInfo->getComprasRealizadas().begin(); it != clienteInfo->getComprasRealizadas().end(); ++it) {
			Compra* compraActualIt = it->second;
			compraAString(compraActualIt);
			cout << "Monto total: " << compraActualIt->getMontoTotal() << "\n" << endl;
			cout << "Fecha: " << compraActualIt->getFechaDeCompra() << "\n" << endl;}
					
		}
	}
	else {
		cout << "\n" << "No existe un cliente con el usuario proporcionado." << "\n" << endl;
	}
 }


void ControladorUsuarios::imprimirSuscripcionesDisponiblesPara(string nickname){
	map<string, Vendedor*>::iterator it;
	this->nombreNuevoSuscriptor = nickname;
	cout<<"Las suscripciones disponibles para "<< nickname <<" son:"<<endl;
	for (it= vendedores.begin(); it!=vendedores.end(); ++it){
		bool suscripto = it->second->estaSuscripto(nickname);
		if(!suscripto){
			cout<<it->first<<endl;
		}
	}
}

void ControladorUsuarios::suscribirmeA(string nickname){
	Vendedor* vendedor = this->vendedores[nickname];
	bool estaSuscripto = vendedor->estaSuscripto(this->nombreNuevoSuscriptor);
	if(!estaSuscripto){
		vendedor->agregarSuscriptor(this->clientes[this->nombreNuevoSuscriptor]);
		cout<<this->nombreNuevoSuscriptor<<" se ha suscrito a "<<nickname<<endl;
	}
	else {
		cout<<this->nombreNuevoSuscriptor<< "ya se encuentra suscrito a" << nickname<<endl;
		cout<<"INGRESE UNA SUSCRIPCION VALIDA:"<<endl;
	}
}

bool ControladorUsuarios::existenUsuariosRegistrados()
{
    if (clientes.empty()&&vendedores.empty())
	{
		return false;
	}
	else {
		return true;
	}
	
}
