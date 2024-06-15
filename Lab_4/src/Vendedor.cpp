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

vector<DTInfoProducto> Vendedor::obtenerProductos()
{
}

vector<Comentario> Vendedor::listarComentarios(string)
{
    return vector<Comentario>();
}
