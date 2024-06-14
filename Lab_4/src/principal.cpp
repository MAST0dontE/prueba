#include <iostream>
#include <vector>
#include <string>
#include "../inc/ControladorUsuarios.h"
#include "../inc/ControladorVentas.h"
#include "../inc/Producto.h"

#include "../inc/DTInfoPromocion.h"

#include <stdlib.h>
int main() {


// ** CASO DE USO: Consultar Producto INICIO ** //

Producto* productoPrueba1 = new Producto(1, 1, 1, "productoDePrueba1" , "este es el producto de prueba 1", "pepito", ECategoria::otros);
Producto* productoPrueba2 = new Producto(2, 2, 2, "productoDePrueba2" , "este es el producto de prueba 2", "papito", ECategoria::ropa);
Producto* productoPrueba3 = new Producto(3, 3, 3, "productoDePrueba3" , "este es el producto de prueba 3", "putito", ECategoria::electrodomesticos);

ControladorVentas controladorVentas;
controladorVentas.setProducto(productoPrueba1);
controladorVentas.setProducto(productoPrueba2);
controladorVentas.setProducto(productoPrueba3);

controladorVentas.listarProductos();
controladorVentas.consultarProducto(2,"productoDePrueba2");


/*
DTInfoProducto DTproductoPrueba = productoPrueba.getInfoProducto();
string resultado = DTproductoPrueba.toString();
cout<< "Se muestran los productos: \n" << endl;
cout << resultado << "\n"<< endl;
string resultado2 = DTproductoPrueba.imprimirInfoRestante();
cout<< "Se elige el producto de prueba: \n" << endl;
cout << resultado2 <<"\n" <<endl;
*/

// ** CASO DE USO: Consultar Producto FIN ** //


    return 0;
}