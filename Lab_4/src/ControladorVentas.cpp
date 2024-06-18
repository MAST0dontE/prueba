#include "ControladorVentas.h"
#include "../inc/Producto.h"
#include "ECategoria.h"

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

void ControladorVentas::consultarProducto(int codigo, string nombre){
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
        DTInfoProducto DTproductoPrueba = producto->getInfoProducto();
        string resultado = DTproductoPrueba.imprimirInfoRestante();
        cout << "Producto consultado: " << nombre << "\n" << endl;
        cout << resultado << "\n" << endl;
        encontrado = true;
    }
    
    if (!encontrado) {
        cout << "No existe ningun producto registrado con el codigo consultado: " << codigo << " \n" << endl;
    }
}


vector<DTInfoPromocion> ControladorVentas::listarPromociones(){
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

void ControladorVentas::consultarPromocion(string nombre){
    vector<DTInfoPromocion> prom = this->listarPromociones();
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



void ControladorVentas::agregarProducto(int codigo,int cantMinima, float descuento){

    // Implementación
}

bool ControladorVentas::ingresarPromocion()
{
    // Implementación
    return true;
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
void ControladorVentas::cargarNuevoProducto(string nicknameVendedor,string  nombreProd,float  precio , int stock , string  descripcion, ECategoria  categoria, bool enPromocion){
/*     int codigo = 15 * stock * stock*(stock%5) + static_cast<int>(precio * precio) % 3 + 27; //asigno código
    Producto *P=new Producto(codigo, stock, precio, nombreProd, descripcion, nicknameVendedor,categoria, false); //instancio producto
    productos.insert(P);//inserto en set el producto P
    Vendedor *V=vendedores[nicknameVendedor]; //busco al vendedor que pone en venta el prod
    V->agregarProducto(P); //lo vinculo */

    int codigo = 15 * stock * stock * (stock % 5) + static_cast<int>(precio * precio) % 3 + 27;
    Producto *P = new Producto(codigo, stock, precio, nombreProd, descripcion, nicknameVendedor, categoria, enPromocion);
    productos[codigo] = P;
    Vendedor *V = vendedores[nicknameVendedor];
    V->agregarProducto(P);
}

void ControladorVentas::altaPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento){
    this->nombrePromo = nombre;
    this->descripcionPromo = descripcion;
    this->fechaVencimientoPromo = fechaDeVencimiento;
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

