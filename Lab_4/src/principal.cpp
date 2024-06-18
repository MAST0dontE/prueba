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

/*ControladorUsuarios ControladorUsuariosTrucho;
bool a=ControladorUsuariosTrucho.altaVendedor("un vendedor1", "contra",DTFecha(1,1,1), "123");
bool b=ControladorUsuariosTrucho.altaVendedor("un vendedor2", "contra",DTFecha(1,1,1), "123");
bool c=ControladorUsuariosTrucho.altaVendedor("un vendedor3", "contra",DTFecha(1,1,1), "123");
ControladorUsuariosTrucho.listaDeUsuarios_();*/

controladorVentas.setCliente(cliente1);
controladorVentas.setCliente(cliente2);
controladorVentas.setCliente(cliente3);

controladorVentas.setVendedor(vendedor1);
controladorVentas.setVendedor(vendedor2);
controladorVentas.setVendedor(vendedor3); 

// ** CASO DE USO: Consultar Producto INICIO ** //
cout<< "** CASO DE USO: Consultar Producto INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

Producto* productoPrueba1 = new Producto(1, 1, 1, "productoDePrueba1" , "este es el producto de prueba 1", "pepito", ECategoria::otros, false);
Producto* productoPrueba2 = new Producto(2, 2, 2, "productoDePrueba2" , "este es el producto de prueba 2", "papito", ECategoria::ropa, false);
Producto* productoPrueba3 = new Producto(3, 3, 3, "productoDePrueba3" , "este es el producto de prueba 3", "putito", ECategoria::electrodomesticos, false);


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

cout<< "** CASO DE USO: Consultar Producto FIN **"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Consultar Producto FIN ** //

// ** CASO DE USO: Consultar Promocion INICIO ** //
cout<< "** CASO DE USO: Consultar Promocion INICIO ** **"<< endl;
cout<< "-----------------------------------------------------"<< endl;


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


controladorVentas.listarPromociones();

controladorVentas.consultarPromocion("promocionDePrueba1");
controladorVentas.consultarPromocion("promocionDePrueba3");

cout<< "** CASO DE USO: Consultar Promocion FIN ** **"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Consultar Promocion FIN ** //

// ** CASO DE USO: Realizar compra INICIO ** //
cout<< "** CASO DE USO: Realizar compra INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

cout<< "\nClientes: \n" << endl;
controladorVentas.listarNicknamesClientes();


cout<< "** CASO DE USO: Realizar compra FIN**"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Realizar compra FIN ** //


// ** CASO DE USO: Alta Producto INICIO ** //
cout<< "** CASO DE USO: Alta Producto INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

controladorVentas.cargarNuevoProducto("pepito","productoPepito1", 1, 1, "el producto de pepito uno",ECategoria::otros, false);
controladorVentas.cargarNuevoProducto("pepito","productoPepito2", 2, 2, "el producto de pepito dos",ECategoria::ropa, false);
controladorVentas.cargarNuevoProducto("pepito","productoPepito2", 3, 3, "el producto de pepito tres",ECategoria::electrodomesticos, false);

cout<< "** CASO DE USO: Alta Producto FIN**"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Alta Producto FIN ** //


// ** CASO DE USO: Crear Promocion INICIO ** //
cout<< "** CASO DE USO: Crear Promocion INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

controladorVentas.altaPromocion("promocionZZZ", "sdfhjahsdga", DTFecha(1,2,3));
controladorVentas.seleccionarVendedor("pepito");

cout<< "** CASO DE USO: Crear Promocion FIN**"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Crear Promocion FIN ** //

// ** CASO DE USO: Dejar Comentario INICIO ** //

cout << "     ** CASO DE USO: Dejar Comentario INICIO **" << endl;
cout << "````````````````````````````````````````````````````" << endl;



cout << "````````````````````````````````````````````````````" << endl;
cout << "     ** CASO DE USO: Dejar Comentario FIN **" << endl;

// ** CASO DE USO: Dejar Comentario FIN ** //

//----------------------**PRUEBA DE MENU INTERACTIVO**----------------------//
ControladorUsuarios ControladorUsuariosTrucho;
cout <<"                ---     ¡Bienvenido a Mercado Finger!     ---"<<endl
    <<" "<<endl
    <<"¿En que lo podemos asistir?"<< endl 
    <<"Recuerde usar el comando /help para ver el resto de comandos disponibles" <<endl
    <<"y el comando /exit para salir."<<endl; 

//mapeo de comandos para el switch
map<string, int> comandos;
comandos["/consultarProducto"] = 1; //futuramente caso de uso numero 4 //
comandos["/Alta usuario"] = 2;
comandos["/Listado de usuarios"] = 3;
comandos["/Alta producto"] = 4;
comandos["/Consulta notificaciones"] = 5;
comandos["/Dejar comentario"] = 6; //Ver con Santi
comandos["/Enviar producto"] = 7; //Falta terminar Enviar Producto
comandos["/RealizarCompra"] = 8;

// cargar comandos casos de uso//
cout << "Comandos para los casos de uso xd " <<endl;
string entradaConsola;
getline(cin, entradaConsola);
while (entradaConsola != "/exit"){
    getline(cin, entradaConsola);
    if(comandos.find(entradaConsola)!= comandos.end()){
    int valorEntrada = comandos[entradaConsola];
    switch (valorEntrada){
        case 1:{
            controladorVentas.listarProductos();
            cout << "Desea consultar algun producto en especifico? Y/N ?" <<endl;
            char respuesta1;
            cin>> respuesta1;
            if (respuesta1 == 'Y' || respuesta1 == 'y' ){
                cout << "Indique el codigo del producto que desea consultar:" <<endl;
                int codigo;
                cin>> codigo;
                controladorVentas.consultarProducto(codigo,"productoDePrueba2");
            }}
            break;
        case 2:{
            string NombreUsuario;
            cout << "Indique Nombre del Usuario nuevo"<<endl;
            getline(cin,NombreUsuario);
            string contra;
            cout << "Indique contra del Usuario nuevo"<<endl;
            getline(cin,contra);
            int ano;
            cout << "Indique anio de insercion al ambito satanico del cliente"<<endl;
            cin>>ano;
            int mes;
            cout << "Indique mes de insercion al ambito satanico del cliente"<<endl;
            cin>>mes;
            int dia;
            cout << "Indique dia de insercion al ambito satanico del cliente"<<endl;
            cin>>dia;
            cout <<"¿Desea crear una instancia de cliente o de un vendedor master?" <<endl;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string respuesta2;
            getline(cin,respuesta2);
            if (respuesta2 == "Cliente" || respuesta2 == "cliente" ){
                cout << "Indique ciudad del cliente"<<endl;
                string ciudad;
                getline(cin,ciudad);
                bool a=ControladorUsuariosTrucho.altaCliente(NombreUsuario, contra,DTFecha(dia,mes,ano),DTDireccion("calle1", 123), ciudad);
                if (a) {cout <<"Su cliente fue creado"<<endl;}
            } else if(respuesta2 == "Vendedor" || respuesta2 == "vendedor" ){
                string codigoRut;
                cout << "Indique codigo Rut del vendedor"<<endl;
                getline(cin,codigoRut);
                if (ControladorUsuariosTrucho.altaVendedor(NombreUsuario,contra, DTFecha(dia,mes,ano), codigoRut)){cout <<"Su vendedor fue creado y es un hijo de remil puta"<<endl;}
            } else { 
                break;}
            break;
            }
        case 3:{
            ControladorUsuariosTrucho.listaDeUsuarios_();
        }
        case 4:{
            cout <<"elija el nombre de un vendedor de los siguientes"<<endl;
            ControladorUsuariosTrucho.listaDeVendedores();
            string NombreVendedor;
            getline(cin,NombreVendedor);
            string NombreProducto;
            cout<<"Indique el nombre del producto"<<endl;
            getline(cin,NombreProducto);
            float precio; 
            cin>>precio;
            int stock;
            cin>>stock;
            string Descripcion;
            cout<<"Indique la descripcion del producto"<<endl;
            getline(cin,Descripcion); 
            cout<<"indique a cual categoria pertenece su producto: 1-ropa, 2-electrodomesticos, 3-otros"<<endl;   
            int categoria;
            cin>>categoria;  
            ECategoria categoriaEnum = static_cast<ECategoria>(categoria);      
            controladorVentas.cargarNuevoProducto(NombreVendedor,NombreProducto, precio ,stock ,Descripcion, categoriaEnum, false);
        }
        case 5:{
            cout<<"Indique el nombre del cliente"<<endl;
            string NombreCliente;
            getline(cin,NombreCliente);
            set<DTNotificacion> Notificaciones=ControladorUsuariosTrucho.consultarNotificaciones(NombreCliente);
            string SuperMegaStringFaseDios;
            for (auto notif:Notificaciones){
                SuperMegaStringFaseDios += notif.getnicknameVendedor() + "\n";
                SuperMegaStringFaseDios += notif.getnombrePromo() + "\n";
                SuperMegaStringFaseDios += notif.getDTInfoProducto() + "\n";
            }
            cout <<SuperMegaStringFaseDios<<endl;
        }
        case 6:{
            ControladorUsuariosTrucho.listaDeUsuarios();
            string NombreUsuario;
            cout << "Indique Nombre del Usuario que desea agregar un comentario"<<endl;
            getline(cin,NombreUsuario);
            ControladorUsuariosTrucho.seleccionarUsuario_(NombreUsuario);
            controladorVentas.listarProductos();
            int CodigoProducto;
            cout<<"Escriba el codigo del producto al que desea ingresar un comentario"<<endl;
            cin >> CodigoProducto;
            string NombreVendedor;
            cout<<"Escriba el nombre del vendedor del producto"<<endl;
            getline(cin,NombreVendedor);
            ControladorUsuariosTrucho.seleccionarProducto(CodigoProducto, NombreVendedor);
            string respuesta;
            cout<<"¿Desea dejar un comentario nuevo o responder uno ya existente?"<<endl;
            getline(cin,respuesta);
            if(respuesta == "Dejar un comentario"){
                string comentario;
                cout<<"Escriba el comentario"<<endl;
                getline(cin,comentario);
                ControladorUsuariosTrucho.nuevoComentario(comentario, DTFecha(1,1,1) );
                cout<<"el comentario fue agregado"<<endl;
            }else if (respuesta == "Responder uno ya existente"){
                ControladorUsuariosTrucho.listarComentarios(CodigoProducto);
                int id;
                cout << "Escriba el id del comentario al que desea responder" <<endl;
                cin >> id;
                ControladorUsuariosTrucho.seleccionarComentario(id);
                string comentario;
                cout << "Escriba el comentario" << endl;
                getline(cin, comentario);
                ControladorUsuariosTrucho.nuevaRespuesta(comentario, DTFecha(1,1,1));
                cout << "el comentario fue agregado" << endl;
            }
        }
        case 7:{
            set<string> ListaVend=ControladorUsuariosTrucho.listaDeVendedores();
            set<string>::iterator it;
            for (it=ListaVend.begin(); it !=ListaVend.end(); it++){
                cout<<*it<<endl;
            }
            string NombreVendedor;
            cout << "Indique Nombre del vendedor"<<endl;
            getline(cin,NombreVendedor);
        }
        case 8:{
            controladorVentas.listarNicknamesClientes();
            cout << "Indique el nickname del cliente: "<<endl;
            string nicknameCliente;
            getline(cin,nicknameCliente);
            controladorVentas.seleccionarCliente(nicknameCliente);

            string respuesta3 = "Y";
            while (respuesta3 != "N" || respuesta3 != "n"){
                cout << "Desea agregar un producto a la compra? Y/N"<<endl;
                getline(cin,respuesta3);

                if (respuesta3 == "Y" || respuesta3 == "y"){
                    cout << "Indique el codigo y cantidad del producto a agregar en la compra" <<endl;
                    int codigo;
                    cin>>codigo;
                    int cantidad;
                    cin>>cantidad;
                    controladorVentas.agregarProductoCompra(codigo, cantidad);
                    
                } else if (respuesta3 == "N" || respuesta3 == "n"){
                    break;
                } else {
                    cout << "Opción no válida." <<endl;
                }
            }
            DTInfoCompra dtic = controladorVentas.mostrarDetallesCompra();
           // cout << "Detalles de la compra: \n" << dtic.toString() << endl;

            cout << "Desea confirmar la compra? Y/N" <<endl;
            string respuesta4;
            getline(cin,respuesta4);

            if (respuesta4 == "Y" || respuesta4 == "y"){
                controladorVentas.registrarCompra();
                cout << "Compra realizada con éxito." <<endl;
            } else if (respuesta4 == "N" || respuesta4 == "n"){
                cout << "Compra cancelada." <<endl;
            } else {
                cout << "Opción no válida." <<endl;
            }

        }
        default:
            cout <<"Opción no válida." <<endl;
            break;
    }
    }
    
};



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