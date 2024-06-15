#include "Vendedor.h"


Vendedor::Vendedor(string contrasenia, string nickname, DTFecha fechaDeNacimiento, string codigoRUT) \
    : Usuario(contrasenia, nickname, fechaDeNacimiento), codigoRUT(codigoRUT) {}

string Vendedor::getCodigoRUT(){
    return this->codigoRUT;
}


void Vendedor::notificar()
{
    // Implementación
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

vector<Comentario> Vendedor::listarComentarios(string)
{
    return vector<Comentario>();
}
