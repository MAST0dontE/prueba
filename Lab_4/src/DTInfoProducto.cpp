#include "DTInfoProducto.h"

<<<<<<< HEAD
DTInfoProducto::DTInfoProducto(int codigo, string nombre, float precio, int cantStock, string descripcion,  ECategoria categoria, string vendedor): codigo(codigo), nombre(nombre), precio(precio), cantStock(cantStock), descripcion(descripcion), categoria(categoria), vendedor(vendedor)
{}
=======
DTInfoProducto::DTInfoProducto(int codigo, string nombre, float precio, int cantStock, string descripcion,  ECategoria categoria, string vendedor){};

/*ostream& operator <<(std::ostream& os, const DTInfoProducto& producto){
        os << producto.nombre ;
        //<< "Codigo: " << obj.codigo <<"Precio: " << obj.precio <<"Cantidad en stock: " << obj.cantStock << "Descripcion: " << obj.descripcion <<"Categoria: " << obj.categoria <<"Vendido por: " << obj.vendedor ;
        return os;
    }
*/

string DTInfoProducto::toString(){
    return "Codigo: " + to_string(this->codigo) + " \nNombre: " + this->nombre;
}
;
>>>>>>> 162d507 (DTInfoProducto(male sal))
