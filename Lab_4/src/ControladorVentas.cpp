#include "ControladorVentas.h"
#include "../inc/Producto.h"
#include "ECategoria.h"

ControladorVentas * ControladorVentas::ControladorVentasInst = NULL;

ControladorVentas::ControladorVentas(){
    //Constructor
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

void ControladorVentas::setCompra(Compra *compra)
{
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
/* 
Version para imprimir en el main
    set<string> res;
    for (const auto& pair : this->clientes) {
        res.insert(pair.first);
    }
    return res; */
 
 // Version para imprimir directo en la funcion
    for (const auto& pair : this->clientes) {
        cout<< pair.first + "\n" << endl;
    }
}

void ControladorVentas::seleccionarCliente(string nickname){
    map<int, Producto*>::iterator it;
    this->nicknameClienteRealizarCompra = nickname;

       for (it = productos.begin(); it != productos.end(); ++it) {
        Producto* producto = it->second; 
        DTInfoProducto dtip(it->first, producto->getNombre(), producto->getPrecio(), producto->getStock(), producto->getDescripcion(), producto->getCategoria(), producto->getNombreVendedor());

       cout << dtip.getDTInfoProducto() << "\n" << endl;
    }  
}

void ControladorVentas::agregarProductoCompra(int codigo, int cant){
    auto it = this->productos.find(codigo);
    auto codigoProducto = this->datosProductoCompra.find(codigo);
    auto codigoProductoPromo = this->productosEnPromo.find(codigo);

    if (it != this->productos.end()) {
        if(codigoProducto == this->datosProductoCompra.end() || codigoProductoPromo == this->productosEnPromo.end()){
             Producto* producto = it->second;

            if (cant > 0 && cant <= producto->getStock()) {

                if(producto->getEnPromocion()){
                    auto it2 = this->promociones.begin();
                    while((*it2)->getProductos().find(codigo) == (*it2)->getProductos().end()){
                        it2++;
                    }
                    ProductoEnPromocion* p = (*it2)->getProductos()[codigo];
                     if(p->getCantMinima() <= cant){
                        this->productosEnPromo[codigo] = cant;
                     }else{
                        float precio = producto->getPrecio();
                        this->montoTotalCompra += precio * cant;     
                        this->datosProductoCompra.emplace(codigo, DTProductoCompra(codigo, precio, cant));
                     }

                } /* else {
                    float precio = producto->getPrecio();
                    this->montoTotalCompra += precio * cant;     
                    this->datosProductoCompra.emplace(codigo, DTProductoCompra(codigo, precio, cant));
                } */
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

void ControladorVentas::procesarProductosEnPromo(){
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
        if (promo != nullptr) {
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
            
            if (todosProductosEnPromo){
                // Aplica la promoción
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

void ControladorVentas::registrarCompra()
{
    // Implementación
}

void ControladorVentas::liberarMemoriaRealizarCompra()
{
}

//el Sistema le asigna un código único al producto y lo da de alta en el sistema.
void ControladorVentas::cargarNuevoProducto(string nicknameVendedor, int codigo, string  nombreProd,float  precio , int stock , string  descripcion,
    ECategoria  categoria, bool enPromocion){
/*     int codigo = 15 * stock * stock*(stock%5) + static_cast<int>(precio * precio) % 3 + 27; //asigno código
    Producto *P=new Producto(codigo, stock, precio, nombreProd, descripcion, nicknameVendedor,categoria, false); //instancio producto
    productos.insert(P);//inserto en set el producto P
    Vendedor *V=vendedores[nicknameVendedor]; //busco al vendedor que pone en venta el prod
    V->agregarProducto(P); //lo vinculo */

    //int codigo = 15 * stock * stock * (stock % 5) + static_cast<int>(precio * precio) % 3 + 27;
    Producto *P = new Producto(codigo, stock, precio, nombreProd, descripcion, nicknameVendedor, categoria, enPromocion);
    productos[codigo] = P;
    Vendedor *V = vendedores[nicknameVendedor];
    V->agregarProducto(P);
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
    map<int, DTInfoProducto> productos;
    int contadorProds = 0;
    Vendedor* vendedor = this->vendedores[this->nicknameVendedorPromo];
    for(it = this->productosPromo.begin(); it!= this->productosPromo.end(); ++it){
        promo->agregarProductoPromocion((*it));
        Producto* prod = (*it)->getProducto();
        productos.emplace(contadorProds, prod->getInfoProducto());
        contadorProds++;
    }
        //(*it)->setPromocion(promo);
    vendedor->notificar(DTNotificacion(this->nicknameVendedorPromo,this->nombrePromo, productos));
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
        Compra* compraActual = *compraIt; 
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
    for (auto  compraIt = compras.begin(); compraIt != compras.end(); ++compraIt)
    {
        Compra* compraActual = *compraIt; 
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

void ControladorVentas::agregarProducto(int codigo, int cantMinima){

    // DTInfoProducto:: DTInfoProducto(codigo,"nombre", 0, int cantStock, string descripcion,  ECategoria categoria, string vendedor);
    // datosProductosPromo.insert(make_pair(codigo, this->datosProducto));


}

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
    for (auto productoSet = vendedorInfo->obtenerProductos().begin(); productoSet != vendedorInfo->obtenerProductos().end(); ++productoSet) {
        DTInfoProducto productoActual = *productoSet;
        cout << productoActual.getDTInfoProducto() << endl;
    }
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
