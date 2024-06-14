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
Producto productoPrueba = Producto(1, 1, 1, "productoDePrueba" , "este es el producto de prueba", "pepito", ropa);
DTInfoProducto DTproductoPrueba = productoPrueba.getInfoProducto();
string resultado = DTproductoPrueba.toString();
cout << resultado << endl;
    return 0;
}