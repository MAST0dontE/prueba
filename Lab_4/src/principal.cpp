#include <iostream>
#include <vector>
#include <string>
#include "../inc/ControladorUsuarios.h"
#include "../inc/ControladorVentas.h"
#include "../inc/Producto.h"

#include "../inc/DTInfoPromocion.h"

#include <stdlib.h>
int main() {
//DTInfoProducto Prueba
Producto productoPrueba = Producto(1, 1, 1, "productoDePrueba" , "este es el producto de prueba", "pepito", ECategoria::otros);
DTInfoProducto DTproductoPrueba = productoPrueba.getInfoProducto();
string resultado = DTproductoPrueba.toString();
cout<< "Se muestran los productos: \n" << endl;
cout << resultado << "\n"<< endl;
string resultado2 = DTproductoPrueba.imprimirInfoRestante();
cout<< "Se elige el producto de prueba: \n" << endl;
cout << resultado2 <<"\n" <<endl;



    return 0;
}