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

set<Producto*> ControladorVentas::getProductos(){
    return this->productos;
};

void ControladorVentas::setProducto(Producto *producto)
{
    this->productos.insert(producto);
}

void ControladorVentas::listarProductos(){

    set<Producto*> productos = this->getProductos();
        cout<< "Se muestran los productos: \n" << endl;
        for (auto it = productos.begin(); it != productos.end(); ++it) {
            DTInfoProducto DTproductoPrueba = (*it)->getInfoProducto();
            string resultado = DTproductoPrueba.toString();
            cout << resultado << "\n"<< endl;
    }; 
}

void ControladorVentas::consultarProducto(int codigo, string nombre){
    set<Producto*> productos = this->getProductos();
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
    }
};

vector<DTInfoPromocion> ControladorVentas::listarPromociones(){
    set<Promocion*>::iterator it;
    vector<DTInfoPromocion> res;

    for(it=promociones.begin(); it != promociones.end(); ++it){
        set<ProductoEnPromocion*> prod = (*it)->getProductos();
         if(!prod.empty()){
            ProductoEnPromocion* producto = (*prod.begin()); 
            string vendedorInfo = vendedores[(*producto).getProducto().getNombreVendedor()]->toString();
            DTInfoPromocion dtip((*it)->getNombre(), (*it)->getDescripcion(), (*it)->getFechaDeVencimiento(), vendedorInfo, (*it)->getProductos());
            
            res.push_back(dtip); 
         }
    }
    return res;
/*     set<Promocion*>::iterator it;
    vector<DTInfoPromocion> res;
    

    for(it=promociones.begin(); it != promociones.end(); ++it){
        set<ProductoEnPromocion*> prod = (*it)->getProductos();

        if(!prod.empty()){
            set<ProductoEnPromocion*>::iterator iter = prod.begin();
            string nombreV = (*iter)->getNombreVendedor();
            string vendedorInfo = vendedores[nombreV]->toString();

            DTInfoPromocion dtip((*it)->getNombre(), (*it)->getDescripcion(), (*it)->getFechaDeVencimiento(), vendedorInfo, (*it)->getProductos());
            res.push_back(dtip);
        }
    }
    return res; 
 */


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

set<DTInfoProducto> ControladorVentas::seleccionarVendedor(string nickname)
{
    // Implementación
    return set<DTInfoProducto>();
}

void ControladorVentas::agregarProducto(int codigo,int cantMinima, float descuento)
{
    // Implementación
}

bool ControladorVentas::ingresarPromocion()
{
    // Implementación
    return true;
}

set<string> ControladorVentas::listarNicknamesClientes(){
    set<string> res;
    for (const auto& pair : this->clientes) {
        res.insert(pair.first);
    }
    return res;
}

set<DTInfoProducto> ControladorVentas::seleccionarCliente(string nickname)
{
    // Implementación
    return set<DTInfoProducto>();
}

DTInfoCompra ControladorVentas::mostrarDetallesCompra()
{
    // Implementación
    return DTInfoCompra(DTFecha(1,1,1), 0);
}

void ControladorVentas::registrarCompra()
{
    // Implementación
}

//el Sistema le asigna un código único al producto y lo da de alta en el sistema.
void ControladorVentas::cargarNuevoProducto(string nicknameVendedor,string  nombreProd,float  precio , int stock , string  descripcion, ECategoria  categoria){
    int codigo = 15 * stock * stock*(stock%5) + static_cast<int>(precio * precio) % 3 + 27; //asigno código
    Producto *P=new Producto(codigo, stock, precio, nombreProd, descripcion, nicknameVendedor,categoria); //instancio producto
    productos.insert(P);//inserto en set el producto P
    Vendedor *V=vendedores[nicknameVendedor]; //busco al vendedor que pone en venta el prod
    V->agregarProducto(P); //lo vinculo
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
