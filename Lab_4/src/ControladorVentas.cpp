#include "ControladorVentas.h"
#include "../inc/Producto.h"
#include "ECategoria.h"

ControladorVentas * ControladorVentas::ControladorVentasInst = NULL;

ControladorVentas::ControladorVentas(){
    //Constructor
}

void ControladorVentas::setFechaActual(DTFecha fechaSistema){
    this->fechaActual = fechaSistema;
}

ControladorVentas * ControladorVentas::getControladorVentas(){
	if (!ControladorVentasInst){
		ControladorVentasInst = new ControladorVentas();
	}
	return ControladorVentasInst;
}

void ControladorVentas::setCliente(Cliente *cliente)
{
    this->clientes[cliente->getNickname()] = cliente;
}

void ControladorVentas::setVendedor(Vendedor *vendedor){
    this->vendedores[vendedor->getNickname()] = vendedor;
}

void ControladorVentas::setPromocion(Promocion *promocion){
    this->promociones.insert(promocion);
}

void ControladorVentas::setCompra(Compra *compra){
    this->compras[compra->getId()] = compra;
    // Implementación
}

void ControladorVentas::setFechaPromo(DTFecha fechaPromocion){
    this->fechaVencimientoPromo = fechaPromocion;
}

map<int, Producto*> ControladorVentas::getProductos(){
    return this->productos;
}

map<string, Vendedor*> ControladorVentas::getVendedores()
{
    return this->vendedores;
}

map<string, Cliente *> ControladorVentas::getClientes()
{
    return this->clientes;
}

void ControladorVentas::setProducto(Producto *producto){
    this->productos[producto->getCodigo()] = producto;
}

void ControladorVentas::listarProductos(){

/* set<Producto*> productos = this->getProductos();
    cout<< "Se muestran los productos: \n" << endl;
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        DTInfoProducto DTproductoPrueba = (*it)->getInfoProducto();
        string resultado = DTproductoPrueba.toString();
        cout << resultado << "\n"<< endl;
} 
 */
    map<int, Producto*> productos = this->getProductos();
        cout<< "Se muestran los productos: \n" << endl;
        for (auto it = productos.begin(); it != productos.end(); ++it) {
            Producto* producto = it->second;
            DTInfoProducto DTproductoPrueba = producto->getInfoProducto();
            string resultado = DTproductoPrueba.toString();
            cout << resultado << "\n"<< endl;
    } 
}

void ControladorVentas::consultarProducto(int codigo){
/*     set<Producto*> productos = this->getProductos();
    bool encontrado = false;
        for (auto it = productos.begin(); it != productos.end(); ++it) {
            if ((*it)->getCodigo() == codigo){
                DTInfoProducto DTproductoPrueba = (*it)->getInfoProducto();
                string resultado = DTproductoPrueba.imprimirInfoRestante();
                cout<< "Producto consultado: " << nombre <<"\n" << endl;
                cout << resultado << "\n"<< endl;
                encontrado = true;
            }
        
        }
    if(!encontrado){
        cout << "No existe ningun producto registrado con el codigo consultado: " << codigo << " \n "<< endl;
    } */

    map<int, Producto*> productos = this->getProductos();
    bool encontrado = false;
    auto it = productos.find(codigo);
    
    if (it != productos.end()) {
        Producto* producto = it->second;
        string nombreProd = it->second->getNombre();
        DTInfoProducto DTproductoPrueba = producto->getInfoProducto();
        string resultado = DTproductoPrueba.imprimirInfoRestante();
        cout << "Producto consultado: " << nombreProd << "\n" << endl;
        cout << resultado << "\n" << endl;
        encontrado = true;
    }
    
    if (!encontrado) {
        cout << "No existe ningun producto registrado con el codigo consultado: " << codigo << " \n" << endl;
    }
}


vector<DTInfoPromocion> ControladorVentas::crearSetDTInfoPromocion(){
    set<Promocion*>::iterator it;
    vector<DTInfoPromocion> res;

    for(it=promociones.begin(); it != promociones.end(); ++it){
        Promocion* promocion = *it;

        map<int,ProductoEnPromocion*> prod = (*it)->getProductos();
         if(!prod.empty()){
            ProductoEnPromocion* producto = (*prod.begin()).second; //Obtengo el primer producto de la promocion (porque todos los productos de la promocion son del mismo vendedor
            Producto* prod = producto->getProducto();
            string nombreVendedor = prod->getNombreVendedor();

            auto vendedorIt = vendedores.find(nombreVendedor);
            if(vendedorIt != vendedores.end()){
                string vendedorInfo = vendedorIt->second->toString();
                DTInfoPromocion dtip(promocion->getNombre(), promocion->getDescripcion(), promocion->getFechaDeVencimiento(), vendedorInfo, promocion->getProductos());
                res.push_back(dtip);
            }
         }
    }
    return res;
}

void ControladorVentas::listarPromociones(){
    vector<DTInfoPromocion> listadoPromociones = this->crearSetDTInfoPromocion();
    cout<< "Promociones: \n" << endl;   

for (auto it = listadoPromociones.begin(); it != listadoPromociones.end(); ++it) {
    DTInfoPromocion dtip = *it;
    cout << dtip.toStringSimple() + "------------------------------\n" << endl;   
} 

}

void ControladorVentas::consultarPromocion(string nombre){
    vector<DTInfoPromocion> prom = this->crearSetDTInfoPromocion();
    vector<DTInfoPromocion>::iterator it = find_if(prom.begin(), prom.end(),
                                        [&nombre](const DTInfoPromocion& dtip) {
        return dtip.nombre == nombre;

        });
    if (it != prom.end()) {
       cout << it->toString() + "\n"<< endl;
    } else {
       cout<< "Promoción no encontrada"<< endl;
    }
 
}

void ControladorVentas::listarNicknamesClientes(){
 // Version para imprimir directo en la funcion
    for (const auto& pair : this->clientes) {
        cout<< pair.first + "\n" << endl;
    }
}

bool ControladorVentas::seleccionarCliente(string nickname){
    map<int, Producto*>::iterator it;
    auto cliente = this->clientes.find(nickname);
    bool encontrado = false;

    if(cliente != this->clientes.end()){
        encontrado = true;
        cout << "Cliente seleccionado: " << nickname << endl;
        this->nicknameClienteRealizarCompra = nickname;
        cout << "\nListado de productos: \n" << endl;
        for (it = productos.begin(); it != productos.end(); ++it) {
            Producto* producto = it->second; 
            DTInfoProducto dtip(it->first, producto->getNombre(), producto->getPrecio(), producto->getStock(), producto->getDescripcion(), producto->getCategoria(), producto->getNombreVendedor());

            cout << dtip.getDTInfoProducto() << "\n" << endl;
        }  
    } else {
        cout << "Cliente no encontrado con el nickname proporcionado: " << nickname << endl;

    }
    return encontrado;
}

void ControladorVentas::agregarProductoCompra(int codigo, int cant){
    auto it = this->productos.find(codigo);
    auto codigoProducto = this->datosProductoCompra.find(codigo);
  //  auto codigoProductoPromo = this->productosEnPromo.find(codigo);

    if (it != this->productos.end()) {
        if(codigoProducto == this->datosProductoCompra.end()){
             Producto* producto = it->second;
            if (cant > 0 && cant <= producto->getStock()){
                if(producto->getEnPromocion()){
                    auto it2 = this->promociones.begin();
                    while((*it2)->getProductos().find(codigo) == (*it2)->getProductos().end()){
                        it2++;
                    }
                    ProductoEnPromocion* p = (*it2)->getProductos()[codigo];
                     if(p->getCantMinima() <= cant){
                        this->productosEnPromo[codigo] = cant;
                     }
                } 
               float precio = producto->getPrecio();
               this->montoTotalCompra += precio * cant;     
               this->datosProductoCompra.emplace(codigo, DTProductoCompra(codigo, precio, cant));
            
            } else {
            cout << "Cantidad inválida. Debe ser mayor a 0 y no exceder el stock disponible." << endl;
            } 
        }else {
            cout << "El producto con el código " << codigo << " ya se encuentra agregado en la compra." << endl;
        }
    } else {
        cout << "Producto no encontrado con el código proporcionado: " << codigo << endl;
    } 
}

int ControladorVentas::compararFechasPromociones(DTFecha fecha1){
    int res = 0;
    if ((fecha1.anio != this->fechaActual.anio) || (fecha1.mes != this->fechaActual.mes) || (fecha1.dia != this->fechaActual.dia)) {
        if ((fecha1.anio < this->fechaActual.anio) || ((fecha1.anio == this->fechaActual.anio) && (fecha1.mes < this->fechaActual.mes)) ||
            ((fecha1.anio == this->fechaActual.anio) && (fecha1.mes == this->fechaActual.mes) && (fecha1.dia < this->fechaActual.dia))) {
            res = -1;
        } else {
            res = 1;
        }
    }
    return res;
}    

void ControladorVentas::procesarProductosEnPromo()
{
    while (!this->productosEnPromo.empty()) {
        auto it = this->productosEnPromo.begin();
        int codigoProducto = it->first;
        int cantidad = it->second;
        //this->productosEnPromo.erase(it);

        Promocion* promo = nullptr;

        // encontrar la promoción que contiene el producto
        for (auto it1 = this->promociones.begin(); it1 != this->promociones.end(); ++it1) {
            if ((*it1)->getProductos().find(codigoProducto) != (*it1)->getProductos().end()) {
                promo = *it1;
                break;
            }
        }
        if (promo != nullptr && (compararFechasPromociones(promo->getFechaDeVencimiento()) == -1|| compararFechasPromociones(promo->getFechaDeVencimiento()) == 0)){
            map<int, ProductoEnPromocion*> productosEnPromo = promo->getProductos();
            bool todosProductosEnPromo = true;
            map<int, DTProductoCompra> productosCompra;

            for (const auto& par : productosEnPromo) {
                int codigoProdPromo = par.first;
                ProductoEnPromocion* prodEnPromo = par.second;

                auto itProdEnPromo = this->productosEnPromo.find(codigoProdPromo);

                if (itProdEnPromo != this->productosEnPromo.end()) {
                    // Producto está en productosEnPromo y cumple con la cantidad mínima
                    int cantidadSolicitada = itProdEnPromo->second;
                    if (cantidadSolicitada >= prodEnPromo->getCantMinima()) {
                        float precioConDescuento = prodEnPromo->getProducto()->getPrecio() * (1 - prodEnPromo->getDescuento() / 100.0);
                        productosCompra.emplace(codigoProdPromo, DTProductoCompra(codigoProdPromo, precioConDescuento, cantidadSolicitada));
                       // productosCompra[codigoProdPromo] = DTProductoCompra(codigoProdPromo, precioConDescuento, cantidadSolicitada);
                        this->productosEnPromo.erase(itProdEnPromo);
                    }else {
                        todosProductosEnPromo = false;
                        break;
                    } 
                } else {
                    todosProductosEnPromo = false;
                    break;
                }
            }
            
            if (todosProductosEnPromo){// Aplica la promocion 
                for (const auto& par : productosCompra) {
                    auto it = this->productos.find(par.first);
                    Producto* producto = it->second;
                    float precioOriginal = producto->getPrecio();

                    //resto el precio que habia sumado previamente y sumo el precio con descuento al monto total
                    this->montoTotalCompra -= precioOriginal * par.second.cant; 
                    this->montoTotalCompra += par.second.precio * par.second.cant; 
                    //Borro el producto que agregue si descuento en agregarProductoCompra y pongo el nuevo con descuento
                    this->datosProductoCompra.erase(par.first);
                    this->datosProductoCompra.emplace(par.first, par.second);
                }
            }

        }
    }
}

void ControladorVentas::mostrarDetallesCompra(){
    this->procesarProductosEnPromo();
    cout << "Detalles de la compra: " << endl;

    for (const auto& par : this->datosProductoCompra) {
        DTProductoCompra producto = par.second;
        cout << producto.toString() << endl;
    }
    cout << "Monto total de la compra: " << this->montoTotalCompra << endl;
    
} 
/*Chequea que la compra no sea vacía.
Registra la compra en el sistema si el parámetro es verdadero, lo que significa que:
1. Crea una instancia de Compra y le asocia la fecha actual al atributo fechaDeCompra y a montoTotal el monto guardado calculado en mostrarDetallesCompra().
2.Crea tantas instancias de tipo CompraPorProducto como la cantidad de productos que se hayan guardado anteriormente, le asocia la cantidad a cantidadSolicitada e inicializa el estadoDeEnvío en pendiente.

PostCondiciones:
1. Debe quedar creada una nueva instancia de Compra en el sistema.
2. Debe quedar liberada la memoria auxiliar utilizada para guardar previamente:
- codigo y cantidad guardados por agregarProducto
- nickname guardado por seleccionarCliente
-monto calculado por mostrarDetallesCompra
3. Deben quedar creados los links entre Compra y el Cliente.
4. Deben quedar creados los links entre Compra y Producto.

 */

void ControladorVentas::registrarCompra(){
    map<int, CompraPorProducto*> productosCompra;

    for(const auto& par : this->datosProductoCompra){
        Producto* producto = this->productos[par.first];
        producto->setStock(producto->getStock() - par.second.cant);
        
        CompraPorProducto* compraPorProducto = new CompraPorProducto(producto, par.second.cant, EEnvio::pendiente);
        productosCompra[par.first] = compraPorProducto;
    }
    this->idCompra++;
    Compra* compra = new Compra(this->idCompra, this->fechaActual, this->montoTotalCompra, productosCompra, this->nicknameClienteRealizarCompra);
    
    Cliente* cliente = this->clientes[this->nicknameClienteRealizarCompra];
    cliente->agregarCompra(compra);
    this->compras[this->idCompra] = compra;
}

void ControladorVentas::liberarMemoriaRealizarCompra(){
    this->datosProductoCompra.clear();
    this->productosEnPromo.clear();
    this->montoTotalCompra = 0;
    this->nicknameClienteRealizarCompra = "";
}


//el Sistema le asigna un código único al producto y lo da de alta en el sistema.
void ControladorVentas::cargarNuevoProducto(string nicknameVendedor, int codigo, string  nombreProd,float  precio , int stock , string  descripcion,
    ECategoria  categoria, bool enPromocion){

    if(this->productos.find(codigo)==this->productos.end()){
        Producto *P = new Producto(codigo, stock, precio, nombreProd, descripcion, nicknameVendedor, categoria, enPromocion);
        productos[codigo] = P;
        Vendedor *V = vendedores[nicknameVendedor];
        V->agregarProducto(P);
        cout<<"El producto "<<nombreProd<<" fue cargado correctamente para el vendedor "<<nicknameVendedor<<"."<<endl;
    }
    else{
        cout<<"El codigo '"<<codigo <<"' ya esta asociado a otro producto. Vuelva a intentarlo con informacion valida."<<endl;
    }
}

void ControladorVentas::altaPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, float descuentoPromo){
    this->nombrePromo = nombre;
    this->descripcionPromo = descripcion;
    this->fechaVencimientoPromo = fechaDeVencimiento;
    this->descuentoPromo = descuentoPromo;
    map<string, Vendedor*>::iterator it;
    cout << "Seleccione un vendedor: " << endl;
    for(it=vendedores.begin(); it != vendedores.end(); ++it){
        Vendedor* vendedor = it->second;
        cout<< vendedor->getNickname() << endl;
    }
}

bool ControladorVentas::vendedorTieneProductos(string nickname){
    Vendedor* vendedor = this->vendedores[nickname];
    return (vendedor->tieneProductos());
}

void ControladorVentas::seleccionarVendedor(string nickname){
    this->nicknameVendedorPromo = nickname;
    Vendedor* vendedor = this->vendedores[nickname];
    vendedor->listarProductosVendedor();
}

void ControladorVentas::agregarProductoPromo(int codigo, int cantMinima){
    Producto* producto = this->productos[codigo];
    if(producto!=NULL && !producto->getEnPromocion() && producto->getNombreVendedor()==this->nicknameVendedorPromo){
        ProductoEnPromocion* produPromo = new ProductoEnPromocion(producto, this->descuentoPromo, cantMinima);
        this->productosPromo.insert(produPromo);
        producto->ahoraEstaEnPromo();
        cout<< "El producto es valido y se agregara correctamente a la promo: "<<endl;
    }
    else cout<< "El producto NO es valido para agregarse correctamente a la promo: "<<endl;
}


void ControladorVentas::ingresarPromocion(){
    if(this->productosPromo.empty()){
        cout<<"No es posible resgistrar una promocion vacia, por favor agregue al menos un producto valido."<<endl;
    }
    else{
    Promocion* promo = new Promocion(this->nombrePromo, this->descripcionPromo, this->fechaVencimientoPromo);
    set<ProductoEnPromocion*>::iterator it;
    map<int, DTInfoProducto> productosPromoDT;
    //int contadorProds = 0;
    Vendedor* vendedor = this->vendedores[this->nicknameVendedorPromo];
    for(it = this->productosPromo.begin(); it!= this->productosPromo.end(); ++it){
        promo->agregarProductoPromocion((*it));
        Producto* prod = (*it)->getProducto();
        DTInfoProducto dtProd = prod->getInfoProducto();
        productosPromoDT.emplace(prod->getCodigo(), dtProd);
        //contadorProds++;
    }
        //(*it)->setPromocion(promo);
    vendedor->notificar(DTNotificacion(this->nicknameVendedorPromo,this->nombrePromo, productosPromoDT));
    this->setPromocion(promo);
    this->productosPromo.clear();
    cout<<"La Promocion se ha ingresado correctamente: "<<endl;
    //Se crea la notificacion asociada a esta promo:
    //this->vendedores[this->nicknameVendedorPromo]->notificar(DTNotificacion(this->nicknameVendedorPromo,this->nombrePromo, productos));
    }
}

int ControladorVentas::listarProductosPendientes(string nickname){
    int existenProductosPendientes = 0;
    for (auto  compraIt = compras.begin(); compraIt != compras.end(); ++compraIt)
    {
        Compra* compraActual = compraIt->second; 
        for (auto compraPorProducto = compraActual->getProductos().begin() ; compraPorProducto != compraActual->getProductos().end(); ++compraPorProducto)
        {
          CompraPorProducto* productoActual = compraPorProducto->second;
          if ((productoActual->getVendedor() == nickname) && (productoActual->getestadoDeEnvio() == EEnvio::pendiente))
          {
            cout << "Producto pendiente de envio: " << productoActual->getCodigoProducto() << endl;
            existenProductosPendientes = 1;
          }
        }
    }
    return existenProductosPendientes;
}

int ControladorVentas::listarComprasAEnviar(Producto *producto){
    int existenComprasAEnviar = 0;
    cout << "Compras pendientes a enviar:" << endl;
    for (auto  compraIt = compras.begin(); compraIt != compras.end(); ++compraIt){
        Compra* compraActual = compraIt->second; 
        for (auto compraPorProducto = compraActual->getProductos().begin() ; compraPorProducto != compraActual->getProductos().end(); ++compraPorProducto)
        {
            CompraPorProducto* productoActual = compraPorProducto->second;
          if ((productoActual->getCodigoProducto() == producto->getCodigo()) && (productoActual->getestadoDeEnvio() == EEnvio::pendiente))
          {
            existenComprasAEnviar = 1;
            cout << "COMPRA: " << compraActual->getId() << endl;
            cout << "  Cliente: " << compraActual->getCliente() << endl;
            cout << "  Fecha de realización: " << compraActual->getFechaDeCompra() << endl;
          }
        }
    }
    return existenComprasAEnviar;
}

void ControladorVentas::compraEnviada(int idCompra, int idProducto, string nickname) {
    Cliente* cliente = clientes.find(nickname)->second;
    Compra* compra = cliente->getComprasRealizadas().find(idCompra)->second;
    CompraPorProducto* productoEnviado = compra->getProductos().find(idProducto)->second;
    productoEnviado->setestadoDeEnvio(EEnvio::enviado);
}

//void ControladorVentas::agregarProducto(int codigo, int cantMinima){

    // DTInfoProducto:: DTInfoProducto(codigo,"nombre", 0, int cantStock, string descripcion,  ECategoria categoria, string vendedor);
    // datosProductosPromo.insert(make_pair(codigo, this->datosProducto));


//}

static void imprimirPromoVendedor(string nickname, Promocion* promocion) {
    cout << "Promocion: " << promocion->getNombre() << endl;
    cout << "Descripcion: " << promocion->getDescripcion() << "\n" << endl;
    cout << "Productos en Promocion: " << endl;
    for (auto productos = promocion->getProductos().begin(); productos != promocion->getProductos().end(); ++productos) {
        ProductoEnPromocion* productoActual = productos->second;
        cout << "-> Producto: " << productoActual->getProducto()->getCodigo() << endl;
        cout << "    Descuento: " << productoActual->getDescuento() << endl;
        cout << "    Cantidad Minima: " << productoActual->getCantMinima() << endl;
    }
}


void ControladorVentas::infoVendedor(string nickname){
    Vendedor* vendedorInfo = vendedores.find(nickname)->second;
    cout << "Nickname: " << vendedorInfo->getNickname() << endl;
    cout << "Fecha de nacimiento: " << vendedorInfo->getFecha() << "\n" << endl;
    cout << "Productos disponibles:" << endl;
    cout << "ESTOY ENTRANDOOOOOO" << endl;
    vendedorInfo->listarProductosVendedor();
    cout << "Promociones vigentes:" << endl;
    for (auto enPromo = promociones.begin(); enPromo != promociones.end(); ++enPromo) {
        Promocion* promoActual = *enPromo;
        map<int, ProductoEnPromocion*> mapProd = promoActual->getProductos();
        auto productoVend = mapProd.begin();
        ProductoEnPromocion* ayuda = productoVend->second;
        if (ayuda->getProducto()->getNombreVendedor() == nickname) {
            imprimirPromoVendedor(nickname, promoActual);
        }
    }
}

void ControladorVentas::listarNicknamesVendedor()
{
    for (const auto& pair : this->vendedores) {
        cout<< pair.first + "\n" << endl;
    }
}

bool ControladorVentas::existeCodigo(int codigo){
	if (productos.find(codigo) != productos.end()) {
        return true;
    }
	else return false;
}

bool ControladorVentas::alMenosUnProductoPromo(){
    return !(this->productosPromo.empty());
}