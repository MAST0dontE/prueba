#include <iostream>
#include <vector>
#include <string>
#include "../inc/ControladorUsuarios.h"
#include "../inc/ControladorVentas.h"
#include "../inc/Producto.h"
#include "../inc/Vendedor.h"
#include "../inc/ProductoEnPromocion.h"
#include "../inc/DTInfoPromocion.h"
#include "../inc/Fabrica.h"

#include <stdlib.h>
int main() {

// ** FABRICA CREACION Y GET iCONTROLADORES** //
/*
Fabrica * factoria;
factoria = Fabrica::getFabrica();
factoria->getiControladorUsuarios();
factoria->getiControladorVentas();
// ----------------------------------------------- //
*/

ControladorUsuarios* controladorUsuarios = ControladorUsuarios::getControladorUsuarios();
ControladorVentas* controladorVentas = ControladorVentas::getControladorVentas();

ControladorUsuarios* controladorUsuarios2 = ControladorUsuarios::getControladorUsuarios();
ControladorVentas* controladorVentas2 = ControladorVentas::getControladorVentas();

if(controladorUsuarios==controladorUsuarios2){
    cout<<"Controlador Ususarios ES SINGLETON"<<endl;
}

if(controladorVentas==controladorVentas2){
    cout<<"Controlador Ventas ES SINGLETON"<<endl;
}


Vendedor* vendedor1 = new Vendedor("pepito", "contraV1", DTFecha(1,1,1), "123456789");    
Vendedor* vendedor2 = new Vendedor("tiranosaurioRex", "contraV2", DTFecha(1,1,1), "987654321");
Vendedor* vendedor3 = new Vendedor("solitarioGamer", "contraV3", DTFecha(1,1,1), "32134834");

Cliente* cliente1 = new Cliente("un cliente1", "contraC1", DTFecha(1,1,1), DTDireccion("calle1", 123) ,"ciudad1");
Cliente* cliente2 = new Cliente("un cliente2", "contraC2", DTFecha(1,1,1),DTDireccion("calle1", 123), "ciudad2");
Cliente* cliente3 = new Cliente("un cliente3", "contraC3", DTFecha(1,1,1),DTDireccion("calle1", 123), "ciudad3");
/*
ControladorUsuarios ControladorUsuariosTrucho;
bool a=controladorUsuarios->altaVendedor("un vendedor1", "contra",DTFecha(1,1,1), "123");
bool b=controladorUsuarios->altaVendedor("un vendedor2", "contra",DTFecha(1,1,1), "123");
bool c=controladorUsuarios->altaVendedor("un vendedor3", "contra",DTFecha(1,1,1), "123");
controladorUsuarios->listaDeUsuarios_();
*/
controladorUsuarios->altaVendedor("pepito", "contraV1", DTFecha(1,1,1), "123456789");
controladorUsuarios->altaVendedor("tiranosaurioRex", "contraV2", DTFecha(1,1,1), "987654321");
controladorUsuarios->altaVendedor("solitarioGamer", "contraV3", DTFecha(1,1,1), "32134834");
controladorUsuarios->altaVendedor("DaVinci","zzz123", DTFecha(15,4,1452),"45666544");

controladorUsuarios->altaCliente("Donatelo", "contraC1", DTFecha(1,1,1),DTDireccion("calle1", 123), "ciudad1");
controladorUsuarios->altaCliente("Leonardo", "contraC2", DTFecha(2,2,2),DTDireccion("calle2", 321), "ciudad2");
controladorUsuarios->altaCliente("Raphael", "contraC3", DTFecha(3,3,3),DTDireccion("calle3", 132), "ciudad3");


// ** CASO DE USO: Consultar Producto INICIO ** //
cout<< "** CASO DE USO: Consultar Producto INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

Producto* productoPrueba1 = new Producto(1, 1, 1, "productoDePrueba1" , "este es el producto de prueba 1", "pepito", ECategoria::otros, false);
Producto* productoPrueba2 = new Producto(2, 2, 2, "productoDePrueba2" , "este es el producto de prueba 2", "tiranosaurioRex", ECategoria::ropa, false);
Producto* productoPrueba3 = new Producto(3, 3, 3, "productoDePrueba3" , "este es el producto de prueba 3", "solitarioGamer", ECategoria::electrodomesticos, false);

controladorVentas->setProducto(productoPrueba1);
controladorVentas->setProducto(productoPrueba2);
controladorVentas->setProducto(productoPrueba3);

controladorVentas->listarProductos();
controladorVentas->consultarProducto(2);
controladorVentas->consultarProducto(4);

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

controladorVentas->setPromocion(promocionPrueba1);
controladorVentas->setPromocion(promocionPrueba2);

promocionPrueba1->agregarProductoPromocion(productoEnPromocion1);
promocionPrueba1->agregarProductoPromocion(productoEnPromocion2);
promocionPrueba2->agregarProductoPromocion(productoEnPromocion3);


controladorVentas->listarPromociones();

controladorVentas->consultarPromocion("promocionDePrueba1");
controladorVentas->consultarPromocion("promocionDePrueba3");

cout<< "** CASO DE USO: Consultar Promocion FIN ** **"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Consultar Promocion FIN ** //

// ** CASO DE USO: Realizar compra INICIO ** //
cout<< "** CASO DE USO: Realizar compra INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

cout<< "\nClientes: \n" << endl;
controladorVentas->listarNicknamesClientes();

cout << "\nListado de productos: \n" << endl;
controladorVentas->seleccionarCliente("un cliente1");


cout<< "** CASO DE USO: Realizar compra FIN**"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Realizar compra FIN ** //


// ** CASO DE USO: Alta Producto INICIO ** //
cout<< "** CASO DE USO: Alta Producto INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

controladorVentas->cargarNuevoProducto("pepito",11, "productoPepito1", 1, 1, "el producto de pepito uno",ECategoria::otros, false);
controladorVentas->cargarNuevoProducto("pepito",12, "productoPepito2", 2, 2, "el producto de pepito dos",ECategoria::ropa, false);
controladorVentas->cargarNuevoProducto("pepito",13, "productoPepito2", 3, 3, "el producto de pepito tres",ECategoria::electrodomesticos, false);

controladorVentas->cargarNuevoProducto("tiranosaurioRex",321, "productoTiranosaurio1", 1, 1, "el producto de Tiranosaurio uno",ECategoria::otros, false);
controladorVentas->cargarNuevoProducto("tiranosaurioRex",322, "productoTiranosaurio2", 2, 2, "el producto de Tiranosaurio dos",ECategoria::ropa, false);

cout<< "** CASO DE USO: Alta Producto FIN**"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Alta Producto FIN ** //


// ** CASO DE USO: Crear Promocion INICIO ** //
cout<< "** CASO DE USO: Crear Promocion INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

controladorVentas->altaPromocion("promocionZZZ", "sdfhjahsdga", DTFecha(1,2,3), 0.5);
controladorVentas->seleccionarVendedor("pepito");
controladorVentas->agregarProductoPromo(11,21);
controladorVentas->agregarProductoPromo(12,22);
controladorVentas->ingresarPromocion();
controladorVentas->consultarPromocion("promocionZZZ");

controladorVentas->altaPromocion("promocionVACIA", "sdfhjahsdgaaaaazzz", DTFecha(1,2,3), 0.25);
controladorVentas->seleccionarVendedor("solitarioGamer");
controladorVentas->agregarProductoPromo(13,2);
controladorVentas->ingresarPromocion();
controladorVentas->consultarPromocion("promocionVACIA");
/*
controladorVentas->altaPromocion("promocionTIRA", "kkkkkkkkkkkk", DTFecha(1,2,3), 0.5);
controladorVentas->seleccionarVendedor("tiranosaurioRex");
controladorVentas->agregarProductoPromo(321,3);
controladorVentas->ingresarPromocion();
controladorVentas->listarPromociones();
*/
cout<< "** CASO DE USO: Crear Promocion FIN**"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Crear Promocion FIN ** //

// ** CASO DE USO: Dejar Comentario INICIO ** //

cout << "     ** CASO DE USO: Dejar Comentario INICIO **" << endl;
cout << "````````````````````````````````````````````````````" << endl;



cout << "````````````````````````````````````````````````````" << endl;
cout << "     ** CASO DE USO: Dejar Comentario FIN **" << endl;

// ** CASO DE USO: Dejar Comentario FIN ** //

// ** CASO DE USO: Suscribirse INICIO ** //

cout << "     ** CASO DE USO: Suscribirse INICIO **" << endl;
cout << "````````````````````````````````````````````````````" << endl;


//controladorUsuarios->imprimirListaDeVendedores();
controladorUsuarios->imprimirSuscripcionesDisponiblesPara("Donatelo");
controladorUsuarios->suscribirmeA("tiranosaurioRex");
controladorUsuarios->imprimirSuscripcionesDisponiblesPara("Donatelo");
controladorUsuarios->suscribirmeA("tiranosaurioRex");
controladorVentas->altaPromocion("promocionTIRA", "kkkkkkkkkkkk", DTFecha(1,2,3), 0.5);
controladorVentas->seleccionarVendedor("tiranosaurioRex");
controladorVentas->agregarProductoPromo(321,3);
controladorVentas->ingresarPromocion();

controladorUsuarios->consultarNotificaciones("Donatelo");

cout << "````````````````````````````````````````````````````" << endl;
cout << "     ** CASO DE USO: Suscribirse FIN **" << endl;

// ** CASO DE USO: Suscribirse FIN ** //


//----------------------**PRUEBA DE MENU INTERACTIVO**----------------------//

cout <<"               	-----    	¡Bienvenido a Mercado Finger!   	-----"<<endl;
cout <<" "<<endl;
cout <<"¿En que lo podemos asistir?"<<endl;
cout <<"Escriba 1 para consultar Producto"<<endl;
cout <<"Escriba 2 para dar Alta usuario"<<endl;
cout <<"Escriba 3 para Listado de usuarios"<<endl;
cout <<"Escriba 4 para Alta producto"<<endl;
cout <<"Escriba 5 para Consulta notificaciones"<<endl;
cout <<"Escriba 6 para Dejar comentario"<<endl; 
cout <<"Escriba 7 para Enviar producto"<<endl; 
cout <<"Escriba 8 para RealizarCompra"<<endl; 
cout <<"Escriba 9 para ConsultarPromocion"<<endl;
cout <<"Escriba 10 para ver expediente de usuario"<<endl; 
cout <<"Escriba 0 para salir"<<endl;



int entradaConsola;
cin>>entradaConsola;
while (entradaConsola != 0){
	switch (entradaConsola){
    	case 1:{
        	controladorVentas->listarProductos();
        	cout << "Desea consultar algun producto en especifico? Y/N ?" <<endl;
        	char respuesta1;
        	cin>> respuesta1;
        	if (respuesta1 == 'Y' || respuesta1 == 'y' ){
            	cout << "Indique el codigo del producto que desea consultar:" <<endl;
            	int codigo;
            	cin>> codigo;
            	controladorVentas->consultarProducto(codigo);
        	}
            break;
            }
        	
    	case 2:{
            
        	string NombreUsuario;
        	cout << "Indique Nombre del Usuario nuevo"<<endl;
        	getline(cin,NombreUsuario);
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	string contra;
        	cout << "Indique contra del Usuario nuevo"<<endl;
        	getline(cin,contra);
        	int ano;
        	cout << "Indique año de nacimiento"<<endl;
        	cin>>ano;
        	int mes;
        	cout << "Indique mes de nacimiento"<<endl;
        	cin>>mes;
        	int dia;
        	cout << "Indique dia de nacimiento"<<endl;
        	cin>>dia;
        	cout <<"¿Desea crear una instancia de cliente o de un vendedor master?" <<endl;
        	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	char c;
        	while (cin.get(c) && c != '\n');

        	string respuesta2;
        	getline(cin,respuesta2);
        	if (respuesta2 == "Cliente" || respuesta2 == "cliente" ){
            	cout << "Indique ciudad del cliente"<<endl;
            	string ciudad;
            	getline(cin,ciudad);
            	bool a=controladorUsuarios->altaCliente(NombreUsuario, contra,DTFecha(dia,mes,ano),DTDireccion("calle1", 123), ciudad);
            	if (a) {cout <<"Su cliente fue creado"<<endl;}
        	} else if(respuesta2 == "Vendedor" || respuesta2 == "vendedor" ){
            	string codigoRut;
            	cout << "Indique codigo Rut del vendedor"<<endl;
            	getline(cin,codigoRut);
            	if (controladorUsuarios->altaVendedor(NombreUsuario,contra, DTFecha(dia,mes,ano), codigoRut)){cout <<"Su vendedor fue creado"<<endl;}
        	} else {
            	break;}
        	break;
        	}
    	case 3:{
        	controladorUsuarios->listaDeUsuarios_();
            break;
    	}
    	case 4:{
        	cout <<"elija el nombre de un vendedor de los siguientes"<<endl;
        	controladorUsuarios->listaDeVendedores();
        	string NombreVendedor;
        	getline(cin,NombreVendedor);
        	string NombreProducto;
        	cout<<"Indique el nombre del producto"<<endl;
        	getline(cin,NombreProducto);
            int codigo;
        	cout<<"Indique el codigo del producto"<<endl;
        	cin>>codigo;
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
       	    controladorVentas->cargarNuevoProducto(NombreVendedor,codigo,NombreProducto, precio ,stock ,Descripcion, categoriaEnum, false);
            break;
    	}   
    	case 5:{/*
        	cout<<"Indique el nombre del cliente"<<endl;
        	string NombreCliente;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	getline(cin,NombreCliente);
        	set<DTNotificacion> Notificaciones=controladorUsuarios->consultarNotificaciones(NombreCliente);
        	string SuperMegaStringFaseDios;
            if(SuperMegaStringFaseDios.empty()){cout<<"No hay notificaciones"<<endl;}else{
                for (auto notif:Notificaciones){
            	SuperMegaStringFaseDios += notif.getnicknameVendedor() + "\n";
            	SuperMegaStringFaseDios += notif.getnombrePromo() + "\n";
            	SuperMegaStringFaseDios += notif.getDTInfoProducto() + "\n";
        	}
        	cout <<SuperMegaStringFaseDios<<endl;
            
            }*/
            break;
    	}
    	case 6:{/*
        	controladorUsuarios->listaDeUsuarios();
        	string NombreUsuario;
        	cout << "Indique Nombre del Usuario que desea agregar un comentario"<<endl;
        	getline(cin,NombreUsuario);
        	controladorUsuarios->seleccionarUsuario_(NombreUsuario);
        	controladorVentas->listarProductos();
        	int CodigoProducto;
        	cout<<"Escriba el codigo del producto al que desea ingresar un comentario"<<endl;
        	cin >> CodigoProducto;
        	string NombreVendedor;
        	cout<<"Escriba el nombre del vendedor del producto"<<endl;
        	getline(cin,NombreVendedor);
        	controladorUsuarios->seleccionarProducto(CodigoProducto, NombreVendedor);
        	string respuesta;
        	cout<<"¿Desea dejar un comentario nuevo o responder uno ya existente?"<<endl;
        	getline(cin,respuesta);
        	if(respuesta == "Dejar un comentario"){
            	string comentario;
            	cout<<"Escriba el comentario"<<endl;
            	getline(cin,comentario);
            	controladorUsuarios->nuevoComentario(comentario, DTFecha(1,1,1) );
            	cout<<"el comentario fue agregado"<<endl;
        	}else if (respuesta == "Responder uno ya existente"){
            	controladorUsuarios->listarComentarios(CodigoProducto);
            	int id;
            	cout << "Escriba el id del comentario al que desea responder" <<endl;
            	cin >> id;
            	controladorUsuarios->seleccionarComentario(id);
            	string comentario;
            	cout << "Escriba el comentario" << endl;
            	getline(cin, comentario);
            	controladorUsuarios->nuevaRespuesta(comentario, DTFecha(1,1,1));
            	cout << "el comentario fue agregado" << endl;
        	}*/
            break;
    	}
    	case 7:{
        	/*set<string> ListaVend=controladorUsuarios->listaDeVendedores();
        	set<string>::iterator it;
        	for (it=ListaVend.begin(); it !=ListaVend.end(); it++){
            	cout<<*it<<endl;
        	}
        	string NombreVendedor;
        	cout << "Indique Nombre del vendedor"<<endl;
        	getline(cin,NombreVendedor);
            //auto vendedor = controladorUsuarios->seleccionarUsuario(NombreVendedor);
            //set<string> productosPendientes= vendedor->listarProductoPendientes(NombreVendedor);
            */
		    cout << "Vendedores disponibles:" << endl;
		   	controladorVentas->listarNicknamesVendedor();
			cout <<"Indique el nickname de vendedor:" << endl;
			string nickname;
			cin >> nickname;
			if (controladorVentas->listarProductosPendientes(nickname) == 1)
			{
				cout <<"Indique el codigo del producto deseado:" << endl;
				int producto;
				cin>>producto;
				if (controladorVentas->getProductos().find(producto)->first == producto)
				{
					Producto* ptrProducto = controladorVentas->getProductos().find(producto)->second;
					if (controladorVentas->listarComprasAEnviar(ptrProducto) == 1)
					{
						cout << "Seleccione la compra a enviar:" << endl;
						int idCompra;
						string nickVendedor;
						cin >> idCompra >> nickVendedor;

						controladorVentas->compraEnviada(idCompra, producto, nickname);
						cout << "La compra ha sido modificada correctamente" << endl;
					}
					else {
						cout << "No hay compras pendientes o la opción es inválida." << endl;
					}
				}
				else  {
					cout << "\n" << "Opción inválida." << "\n" << endl;
				}
			}
			else if (controladorVentas->getVendedores().find(nickname)->first == nickname)
			{
				cout << "\n" <<"No existen compras pendientes de envio del vendedor seleccionado." << "\n" << endl;				
			} else {
				cout << "\n" <<"Opción inválida." << "\n" << endl;
			}
			break;
    	}
    	case 8:{
			cout << "Clientes disponibles: " << endl;
        	controladorVentas->listarNicknamesClientes();
        	cout << "Indique el nickname del cliente: "<<endl;
        	string nicknameCliente;
			cin.ignore();
        	getline(cin,nicknameCliente);
        	controladorVentas->seleccionarCliente(nicknameCliente);

        	string respuesta3 = "Y";
        	while (respuesta3 != "N" || respuesta3 != "n"){
            	cout << "Desea agregar un producto a la compra? Y/N"<<endl;
				//cin >> respuesta3;
            	getline(cin,respuesta3);
				//cin.ignore();

            	if (respuesta3 == "Y" || respuesta3 == "y"){
                	cout << "Indique el codigo y cantidad del producto a agregar en la compra" <<endl;
                	int codigo;
                	cin>>codigo;
                	int cantidad;
                	cin>>cantidad;
                	controladorVentas->agregarProductoCompra(codigo, cantidad);
               	 
            	} else if (respuesta3 == "N" || respuesta3 == "n"){
                	break;
            	} else {
                	cout << "Opción no válida." <<endl;
            	}
        	}
        	controladorVentas->mostrarDetallesCompra();

        	cout << "Desea confirmar la compra? Y/N" <<endl;
        	string respuesta4;
        	getline(cin,respuesta4);

        	if (respuesta4 == "Y" || respuesta4 == "y"){
            	controladorVentas->registrarCompra();
            	cout << "Compra realizada con éxito." <<endl;
        	} else if (respuesta4 == "N" || respuesta4 == "n"){
            	cout << "Compra cancelada." <<endl;
        	} else {
            	cout << "Opción no válida." <<endl;
        	}

			controladorVentas->liberarMemoriaRealizarCompra();
            break;
    	}
    	case 9:{
        	controladorVentas->listarPromociones();
        	cout << "Desea consultar alguna promocion en especifico? Y/N ?" <<endl;
        	char respuesta5;
        	cin>> respuesta5;
        	if (respuesta5 == 'Y' || respuesta5 == 'y' ){
            	cout << "Indique el nombre de la promocion que desea consultar:" <<endl;
            	string nombrePromocion;
            	cin>> nombrePromocion;
            	controladorVentas->consultarPromocion(nombrePromocion);
        	}
            break;
    	}
		case 10:{
			cout <<"Usuarios registrados:" << endl;
		   	controladorUsuarios->listaDeUsuarios_();
		   	cout <<"¿Cual clase de usuario desea ver?" << endl;
		   	cout <<"1 - Cliente" << endl;
		   	cout <<"2 - Vendedor" << endl;
		   	int clase;
			cin>>clase;
			cout << "Indique el nickname del usuario:" << endl;
			string nickname;
			cin>>nickname;
			if (controladorUsuarios->existenUsuariosRegistrados()) {
				switch (clase)
				{
				case 1:
					controladorUsuarios->infoCliente(nickname);
					break;
				case 2:
					controladorVentas->infoVendedor(nickname);
					break;				
				default:
					cout << "Su entrada no es válida. Por favor seleccione 1 o 2." << endl;
					break;
				}
			}
			else {
				cout << "No existen usuarios registrados. No es posible ver expedientes." << endl;
			}
            break;
		}
    	default:
        	cout <<"Opción no válida." <<endl;
        	break;
	}
    cout<<"¿Desea realizar otra operación?"<<endl;
    cout <<"Escriba 1 para consultar Producto"<<endl;
    cout <<"Escriba 2 para dar Alta usuario"<<endl;
    cout <<"Escriba 3 para Listado de usuarios"<<endl;
    cout <<"Escriba 4 para Alta producto"<<endl;
    cout <<"Escriba 5 para Consulta notificaciones"<<endl;
    cout<<"Escriba 6 para Dejar comentario"<<endl; 
    cout <<"Escriba 7 para Enviar producto"<<endl; 
    cout <<"Escriba 8 para RealizarCompra"<<endl; 
    cout <<"Escriba 9 para ConsultarPromocion"<<endl; 
	cout <<"Escriba 10 para ver expediente de usuario"<<endl;
    cout <<"Escriba 0 para salir"<<endl;
    cin>>entradaConsola;
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