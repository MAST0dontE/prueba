#include "DTInfoProducto.h"

DTInfoProducto::DTInfoProducto(int codigo, string nombre, float precio, int cantStock, string descripcion,  ECategoria categoria, string vendedor): codigo(codigo), nombre(nombre), precio(precio), cantStock(cantStock), descripcion(descripcion), categoria(categoria), vendedor(vendedor)
{}


string DTInfoProducto::toString(){
    return "Codigo: " + to_string(this->codigo) + " \nNombre: " + this->nombre;
}
;

string DTInfoProducto::imprimirInfoRestante(){
    return "Precio: " + to_string(this->precio)+ "\nCantidad en stock: " + to_string(this->cantStock) +
    "\nDescripcion: " + this->descripcion + "\nCategoria: " + this->nombreCategoria[static_cast<int>(this->categoria)] + "\nVendedor: " + this->vendedor;
}