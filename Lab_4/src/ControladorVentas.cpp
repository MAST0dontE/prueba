#include "ControladorVentas.h"
#include "../inc/Producto.h"

void ControladorVentas::setCliente(Cliente *cliente)
{
    // Implementación
}

void ControladorVentas::setVendedor(Vendedor *vendedor)
{
    // Implementación
}

void ControladorVentas::setPromocion(Promocion *promocion){
    this->promociones.insert(promocion);
}

void ControladorVentas::setCompra(Compra *compra)
{
    // Implementación
}


set<Producto*> ControladorVentas::getProductos(){
    return this->productos;
};

void ControladorVentas::setProducto(Producto *producto)
{
    /*set<Producto*> productos = this->getProductos();
    productos.insert(producto); */
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

void ControladorVentas::listarPromociones(){
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
    
/*     for (auto it = this->promociones.begin(); it != this->promociones.end(); ++it) {
     vector<ProductoEnPromocion*> productos = (*it)->getProductos();
     cout << "Promocion: " << (*it)->getNombre() << endl;
    auto prodIt = productos.front();

    string nombreV = (*prodIt)->getNombreVendedor();
    cout << "Nombre vendedor: " << nombreV << endl;
    string vendedorInfo = vendedores[nombreV]->toString();

    DTInfoPromocion dtip((*it)->getNombre(), (*it)->getDescripcion(), (*it)->getFechaDeVencimiento(), vendedorInfo, (*it)->getProductos());

    cout<< dtip.toString() << endl;

    }
 */


}

void ControladorVentas::consultarPromocion(string nombre){

/*     vector<DTInfoPromocion> prom = this->listarPromociones();
     vector<DTInfoPromocion>::iterator it = find_if(prom.begin(), prom.end(),
                                         [&nombre](const DTInfoPromocion& dtip) {
        return dtip.nombre == nombre;

                           });
  
    if (it != prom.end()) {
        return *it;
    } else {
        throw runtime_error("Promoción no encontrada");
    }  */

}

set<string> ControladorVentas::altaPromocion(string nombre, string descripcion, DTFecha fechaVencimiento)
{
    // Implementación
    return set<string>();
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

set<string> ControladorVentas::listarNicknamesClientes()
{
    // Implementación
    return set<string>();
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
