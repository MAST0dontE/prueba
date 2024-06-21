#include "Vendedor.h"


Vendedor::Vendedor(string nickname,string contrasenia, DTFecha fechaDeNacimiento, string codigoRUT) \
    : Usuario(nickname,contrasenia, fechaDeNacimiento), codigoRUT(codigoRUT) {}

string Vendedor::getCodigoRUT(){
    return this->codigoRUT;
}

void Vendedor::agregarProducto(Producto *producto){
    this->productosVendedor.insert(producto);
}

void Vendedor::setearProductosVendedor(set<Producto*> productos){
    this->productosVendedor = productos;
    
}

string Vendedor::toString()
{
    return "Nombre del vendedor: " + this->nickname + "\n";
}

vector<DTInfoProducto> Vendedor::obtenerProductos() const{
    vector<DTInfoProducto> detallesProductos;
    for (set<Producto*>::iterator it = productosVendedor.begin(); it != productosVendedor.end(); ++it){
        Producto *producto = *it;
        int codigo = producto->getCodigo();    
        string nombre = producto->getNombre(); 
        float precio = producto->getPrecio();
        int cantStock = producto->getStock();
        string descripcion = producto->getDescripcion();
        ECategoria categoria = producto->getCategoria();
        string vendedor = producto->getNombreVendedor();
        DTInfoProducto detalle(codigo, nombre, precio, cantStock, descripcion, categoria, vendedor);
        detallesProductos.push_back(detalle);
    }
    return detallesProductos;
}
set<Producto*> Vendedor::getProductos() {
    return productosVendedor;
}

vector<Comentario> Vendedor::listarComentarios(string)
{
    return vector<Comentario>();
}

void Vendedor::listarProductosVendedor(){
    set<Producto*> productos = this->getProductos();
    if(productos.empty()){
        cout<<"Este vendedor aun no posee productos asociados."<<endl;
        }
        else{
            cout<< "Se muestran los productos asociados al vendedor " << this->getNickname() <<":"<< endl;
            for (auto it = productos.begin(); it != productos.end(); ++it) {
                DTInfoProducto DTproductoPrueba = (*it)->getInfoProducto();
                string resultado = DTproductoPrueba.toString();
                cout << resultado << "\n"<< endl;
            }
        } 
}

void Vendedor::agregarComentario(Comentario *comentario){
    comentariosUsuario[comentario->getId()] = comentario;
}

map<int, Comentario *> Vendedor::getComentarios()
{
    return comentariosUsuario;
}

void Vendedor::agregarSuscriptor(iSuscriptor* suscriptor){
    this->suscriptores[suscriptor->getNicknameSuscriptor()] = suscriptor;
}

void Vendedor::removerSuscriptor(iSuscriptor* suscriptor){
    //string aBorrar = suscriptor->getNickname();
    this->suscriptores.erase(suscriptor->getNicknameSuscriptor());
}

bool Vendedor::estaSuscripto(string nickname){
    map<string, iSuscriptor*>::iterator it;
    bool result = false;
    for(it=suscriptores.begin();it!=suscriptores.end();++it){
        if (it->first == nickname){
            result=true;
        }
    }
    return result;
}
set<string> Vendedor::listarProductoPendientes(string nickname){
    set<string> listarProductoPendientes;
    return listarProductoPendientes;
}

void Vendedor::notificar(DTNotificacion notificacion){
    map<string, iSuscriptor*>::iterator it;
    for(it=this->suscriptores.begin();it!=this->suscriptores.end();++it){
        (*it).second->notificar(notificacion);
    }
}

void Vendedor::eliminarComentario(int id){
    comentariosUsuario.erase(id);
}
