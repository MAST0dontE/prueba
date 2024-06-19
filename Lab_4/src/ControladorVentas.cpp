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

        set<ProductoEnPromocion*> prod = (*it)->getProductos();
         if(!prod.empty()){
            ProductoEnPromocion* producto = (*prod.begin()); 
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
     if (it != this->productos.end()) {
        Producto* producto = it->second;

        if (cant > 0 && cant <= producto->getStock()) {
            float precio = producto->getPrecio();
            this->datosCompra.push_back(DTProductoCompra(codigo, precio, cant));
            this->montoTotalCompra += precio * cant;
        } else {
            cout << "Cantidad inválida. Debe ser mayor a 0 y no exceder el stock disponible." << endl;
        } 
    } else {
        cout << "Producto no encontrado con el código proporcionado: " << codigo << endl;
    } 
}

DTInfoCompra ControladorVentas::mostrarDetallesCompra(){
    // Implementación
    return DTInfoCompra(DTFecha(1,1,1), 0);
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
};

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
    Promocion* promo = new Promocion(this->nombrePromo, this->descripcionPromo, this->fechaVencimientoPromo);
    set<ProductoEnPromocion*>::iterator it;
    for(it = this->productosPromo.begin(); it!= this->productosPromo.end(); ++it){
        promo->agregarProductoPromocion((*it));
    }
    this->setPromocion(promo);
    this->productosPromo.clear();
    cout<<"La Promocion se ha ingresado correctamente: "<<endl;
}

void ControladorVentas::agregarProducto(int codigo, int cantMinima){

    // DTInfoProducto:: DTInfoProducto(codigo,"nombre", 0, int cantStock, string descripcion,  ECategoria categoria, string vendedor);
    // datosProductosPromo.insert(make_pair(codigo, this->datosProducto));


}

static void imprimirPromoVenderdor(string nickname, Promocion* promocion) {
    cout << "Promocion: " << promocion->getNombre() << "\n" << endl;
    cout << "Descripcion: " << promocion->getDescripcion() << "\n" << endl;
    cout << "Productos en Promocion:\n" << endl;
    for (auto productos = promocion->getProductos().begin(); productos != promocion->getProductos().end(); ++productos) {
            ProductoEnPromocion* productoActual = *productos;
            cout << "  Producto: " << productoActual->getProducto()->getCodigo() << "\n" << endl;
            cout << "  Descuento: " << productoActual->getDescuento() << "%\n" << endl;
            cout << "  Cantidad Minima: " << productoActual->getCantMinima() << "\n" << endl;
    }
}


void ControladorVentas::infoVendedor(string nickname){
	Vendedor* vendedorInfo = vendedores.find(nickname)->second;
	cout << "Nickname: " << vendedorInfo->getNickname() << "\n" << endl;
	cout << "Fecha de nacimiento: " << vendedorInfo->getFecha() << "\n" << endl;
	cout << "Productos disponibles:" << "\n" << endl;
	for (auto productoSet = vendedorInfo->obtenerProductos().begin(); productoSet != vendedorInfo->obtenerProductos().end(); ++productoSet)
	{
		DTInfoProducto productoActual = *productoSet;
		cout << productoActual.getDTInfoProducto() << "\n" << endl;
	}
	cout << "Promociones vigentes:" << "\n" << endl;
	for (auto enPromo = promociones.begin() ; enPromo != promociones.end() ; ++enPromo)
	{
        Promocion* promoActual = *enPromo;
        set<ProductoEnPromocion*> setProd = promoActual->getProductos();
        auto productoVend = setProd.begin();
        ProductoEnPromocion* ayuda = *productoVend;
        if (ayuda->getProducto()->getNombreVendedor() == nickname) {
            imprimirPromoVenderdor(nickname, promoActual);
        }
	}
}
