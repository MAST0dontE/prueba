#include "Producto.h"

Producto::Producto(int codigo, int stock, float precio, string nombre, string descripcion, ECategoria categoria)
    : codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), categoria(categoria) {}

int getCodigo(){
    return this.codigo;
};

int getStock(){
    return this.codigo;
};

float getPrecio(){
    return this.precio;
};

string getNombre(){
    return this.nombre;
};

string getDescripcion(){
    return this.descripcion;
};

ECategoria getCategoria(){
    return this.categoria;
};

string getNombreVendedor(){
    return this.vendedor->getNombre();
};

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
    DTInfoProducto result;
    result.cantStock = this->getStock();
    result.descripcion = this->getDescripcion();
    result.precio = this->getPrecio();
    result.categoria = this->getCategoria();
    DTInfoProducto::DTInfoProducto(this->getCodigo(), this->getNombre(), this->getPrecio(), this->getStock(), this->getDescripcion(),  this->getCategoria,this->getVendedor()){


    return DTInfoProducto(0, " ", " ", 0, " ", 0.0, otros);
}

int Producto::getCodigo()
{
    return 0;
}

int Producto::getStock()
{
    return 0;
}

float Producto::getPrecio()
{
    return 0.0f;
}

string Producto::getNombre()
{
    return string();
}

string Producto::getDescripcion()
{
    return string();
}

ECategoria Producto::getCategoria()
{
    return ECategoria();
}
