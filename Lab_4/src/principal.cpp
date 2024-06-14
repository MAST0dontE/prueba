#include <iostream>
#include <vector>
#include <string>
#include "../inc/ControladorUsuarios.h"
#include "../inc/ControladorVentas.h"
#include "../inc/Producto.h"
#include "../inc/ProductoEnPromocion.h"

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
controladorVentas.consultarProducto(4,"productoDePrueba2");


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
ProductoEnPromocion productoEnPromocion1(productoPrueba1, 0.5, 2);
ProductoEnPromocion productoEnPromocion2(productoPrueba2, 0.5, 2);
ProductoEnPromocion productoEnPromocion3(productoPrueba3, 0.5, 2);

  

Promocion* promocionPrueba1 = new Promocion("promocionDePrueba1", "esta es la promocion de prueba 1", DTFecha(1,1,2021));
Promocion* promocionPrueba2 = new Promocion("promocionDePrueba2", "esta es la promocion de prueba 2", DTFecha(2,2,2022));

controladorVentas.setPromocion(promocionPrueba1);
controladorVentas.setPromocion(promocionPrueba2);

/* promocionPrueba1->agregarProductoPromocion(ProductoEnPromocion(productoEnPromocion1));
promocionPrueba1->agregarProductoPromocion(ProductoEnPromocion(productoEnPromocion2));
promocionPrueba2->agregarProductoPromocion(ProductoEnPromocion(productoEnPromocion3));
 */

controladorVentas.listarPromociones();

  
delete promocionPrueba1;
delete promocionPrueba2;

    return 0;
}