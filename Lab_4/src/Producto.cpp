#include "Producto.h"

Producto::Producto(int codigo, int stock, float precio, string nombre, string descripcion, string vendedor, ECategoria categoria, bool enPromocion): 
codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), vendedor(vendedor), categoria(categoria), enPromocion(enPromocion) {}





DTProductoCompra Producto::getDatosProducto()
{
    // Implementación
    return DTProductoCompra(0, 0.0, 0);
}

DTInfoCompra Producto::getDatosCompra()
{
    // Implementación
    return DTInfoCompra(DTFecha(1,1,1), 0);
}

void Producto::agregarProducto(int stock, int cantidad)
{
    // Implementación
}
   
DTInfoProducto Producto::getInfoProducto(){
    // Implementación
   /*  DTInfoProducto result;
    result.cantStock = this->getStock();
    result.descripcion = this->getDescripcion();
    result.precio = this->getPrecio();
    result.categoria = this->getCategoria();
    DTInfoProducto::DTInfoProducto(this->getCodigo(), this->getNombre(), this->getPrecio(), this->getStock(), this->getDescripcion(),  this->getCategoria,this->getVendedor())

 */
    return DTInfoProducto(this->getCodigo(), this->getNombre(), this->getPrecio(), this->getStock(), this->getDescripcion(),  this->getCategoria(),this->getNombreVendedor());
     
}

int Producto::getCodigo()
{
    return this->codigo;
}

int Producto::getStock()
{
    return this->stock;
}

float Producto::getPrecio()
{
    return this->precio;
}

string Producto::getNombre()
{
    return this->nombre;
}

string Producto::getDescripcion()
{
    return this->descripcion;
}

ECategoria Producto::getCategoria()
{
    return this->categoria;
}

string Producto::getNombreVendedor()
{
    return this->vendedor;
}

map<int, Comentario*> Producto::getComentarios(){
    return comentarios;
}

bool Producto::getEnPromocion()
{
    return this->enPromocion;
}

void Producto::agregarComentario(Comentario* comentario){
   comentarios[comentario->getId()] = comentario;
}

void Producto::setStock(int stock){
    this->stock = stock;
}

void Producto::eliminarComentario(int id){
    comentarios.erase(id);
}