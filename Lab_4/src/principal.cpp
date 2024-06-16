#include <iostream>
#include <vector>
#include <string>
#include "../inc/ControladorUsuarios.h"
#include "../inc/ControladorVentas.h"
#include "../inc/Producto.h"
#include "../inc/Vendedor.h"
#include "../inc/ProductoEnPromocion.h"
#include "../inc/DTInfoPromocion.h"

#include <stdlib.h>
int main() {

ControladorVentas controladorVentas;
Vendedor* vendedor1 = new Vendedor("y si me mato en lo del pelado", "pepito", DTFecha(1,1,1), "123456789");    
Vendedor* vendedor2 = new Vendedor("y si me mato en lo del pelado2", "papito", DTFecha(1,1,1), "987654321");
Vendedor* vendedor3 = new Vendedor("y si me mato en lo del pelado3", "putito", DTFecha(1,1,1), "32134834");

Cliente* cliente1 = new Cliente("un cliente1", "contra", DTFecha(1,1,1), DTDireccion("calle1", 123) ,"ciudad1");
Cliente* cliente2 = new Cliente("un cliente2", "contra", DTFecha(1,1,1),DTDireccion("calle1", 123), "ciudad2");
Cliente* cliente3 = new Cliente("un cliente3", "contra", DTFecha(1,1,1),DTDireccion("calle1", 123), "ciudad3");

ControladorUsuarios ControladorUsuariosTrucho;
bool a=ControladorUsuariosTrucho.altaVendedor("un vendedor1", "contra",DTFecha(1,1,1), "123");
bool b=ControladorUsuariosTrucho.altaVendedor("un vendedor2", "contra",DTFecha(1,1,1), "123");
bool c=ControladorUsuariosTrucho.altaVendedor("un vendedor3", "contra",DTFecha(1,1,1), "123");
ControladorUsuariosTrucho.listaDeUsuarios_();

controladorVentas.setCliente(cliente1);
controladorVentas.setCliente(cliente2);
controladorVentas.setCliente(cliente3);

controladorVentas.setVendedor(vendedor1);
controladorVentas.setVendedor(vendedor2);
controladorVentas.setVendedor(vendedor3); 

// ** CASO DE USO: Consultar Producto INICIO ** //

Producto* productoPrueba1 = new Producto(1, 1, 1, "productoDePrueba1" , "este es el producto de prueba 1", "pepito", ECategoria::otros);
Producto* productoPrueba2 = new Producto(2, 2, 2, "productoDePrueba2" , "este es el producto de prueba 2", "papito", ECategoria::ropa);
Producto* productoPrueba3 = new Producto(3, 3, 3, "productoDePrueba3" , "este es el producto de prueba 3", "putito", ECategoria::electrodomesticos);


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

ProductoEnPromocion* productoEnPromocion1 = new ProductoEnPromocion(productoPrueba1, 0.5, 2);
ProductoEnPromocion* productoEnPromocion2 = new ProductoEnPromocion(productoPrueba2, 0.3, 4);
ProductoEnPromocion* productoEnPromocion3 = new ProductoEnPromocion(productoPrueba3, 0.1, 3);

  

Promocion* promocionPrueba1 = new Promocion("promocionDePrueba1", "esta es la promocion de prueba 1", DTFecha(1,1,2021));
Promocion* promocionPrueba2 = new Promocion("promocionDePrueba2", "esta es la promocion de prueba 2", DTFecha(2,2,2022));

controladorVentas.setPromocion(promocionPrueba1);
controladorVentas.setPromocion(promocionPrueba2);

promocionPrueba1->agregarProductoPromocion(productoEnPromocion1);
promocionPrueba1->agregarProductoPromocion(productoEnPromocion2);
promocionPrueba2->agregarProductoPromocion(productoEnPromocion3);


vector<DTInfoPromocion> listadoPromociones = controladorVentas.listarPromociones();
cout<< "Promociones: \n" << endl;   

for (auto it = listadoPromociones.begin(); it != listadoPromociones.end(); ++it) {
    DTInfoPromocion dtip = *it;
    cout << dtip.toStringSimple() + "------------------------------\n" << endl;   
} 


controladorVentas.consultarPromocion("promocionDePrueba1");
controladorVentas.consultarPromocion("promocionDePrueba3");

// ** CASO DE USO: Consultar Promocion FIN ** //

// ** CASO DE USO: Realizar compra INICIO ** //
set<string> listaNicknames = controladorVentas.listarNicknamesClientes();

cout<< "\nClientes: \n" << endl;
for (auto it = listaNicknames.begin(); it != listaNicknames.end(); ++it) {
    cout << *it << "\n" << endl;
}

// ** SE LIBERA LA MEMORIA ** //
delete productoEnPromocion1;  
delete productoEnPromocion2;
delete productoEnPromocion3;
delete promocionPrueba1;
delete promocionPrueba2;
delete productoPrueba1;
delete productoPrueba2;
delete productoPrueba3;

    return 0;
}