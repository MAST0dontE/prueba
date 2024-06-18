#include "DTInfoPromocion.h"

DTInfoPromocion::DTInfoPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, string infoVendedor, set<ProductoEnPromocion*> productos) : nombre(nombre), descripcion(descripcion), fechaDeVencimiento(fechaDeVencimiento) ,infoVendedor(infoVendedor), productos(productos)
{}


string DTInfoPromocion::toString(){
 /*    set<ProductoEnPromocion*>::iterator it;
    string prodString = "";
    for (it = productos.begin(); it != productos.end(); it++){
        prodString += (*it)->getProducto().getNombre() + "\nDescripcion: " +(*it)->getProducto().getDescripcion() + "\nPrecio Original: " + to_string((*it)->getProducto().getPrecio()) + "\nCantidad minima: " + to_string((*it)->getCantMinima()) + "\nDescuento: "+ to_string((*it)->getDescuento()) + "\n\n";
        
    }
    return "\nProductos de la promocion "+ this->nombre + ":\n" + prodString  + "Informacion del vendedor\n" + this->infoVendedor;
 */
    set<ProductoEnPromocion*>::iterator it;
    string prodString = "";
    for (it = productos.begin(); it != productos.end(); ++it) {
        Producto* prod = (*it)->getProducto();
        prodString += "Nombre: " + prod->getNombre() + "\n";
        prodString += "Descripcion: " + prod->getDescripcion() + "\n";
        prodString += "Precio Original: " + to_string(prod->getPrecio()) + "\n";
        prodString += "Cantidad Minima: " + to_string((*it)->getCantMinima()) + "\n";
        prodString += "Descuento: " + to_string((*it)->getDescuento()) + "\n\n";
    }
    return "\nProductos de la promocion " + this->nombre + ":\n" + prodString + "Informacion del vendedor\n" + this->infoVendedor;
}

string DTInfoPromocion::toStringSimple(){
/*     set<ProductoEnPromocion*>::iterator it;
    string prodString = "";
    for (it = productos.begin(); it != productos.end(); it++){
        prodString += (*it)->getProducto().getNombre() + "\n";
        
    }
    return "Nombre de la promocion: " + this->nombre + "\nDescripcion: " + this->descripcion +"\nProductos en la promocion: "+ prodString  + "\nFecha de vencimiento: " + this->fechaDeVencimiento.toString() + "\n";
 */
  set<ProductoEnPromocion*>::const_iterator it;
    string prodString = "";
    for (it = productos.begin(); it != productos.end(); ++it) {
        Producto* prod = (*it)->getProducto();
        prodString += prod->getNombre() + "\n";
    }
    return "Nombre de la promocion: " + this->nombre + 
           "\nDescripcion: " + this->descripcion + 
           "\nProductos en la promocion: " + prodString + 
           "\nFecha de vencimiento: " + this->fechaDeVencimiento.toString() + "\n";

}
