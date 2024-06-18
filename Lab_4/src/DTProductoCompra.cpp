#include "DTProductoCompra.h"

DTProductoCompra::DTProductoCompra(int codigo, float precio, int cant): codigo(codigo), precio(precio), cant(cant){}

string DTProductoCompra::toString(){
    return "Codigo: " + to_string(this->codigo) + " \nPrecio: " + to_string(this->precio) + " \nCantidad: " + to_string(this->cant);
}
