#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <fstream> // Para manejar archivos
#include <sstream> //Para manipular flujos de cadenas de texto 
#include <filesystem>  // Para manejar directorios y archivos

#include "../inc/ControladorUsuarios.h"
#include "../inc/ControladorVentas.h"
#include "../inc/Producto.h"
#include "../inc/Vendedor.h"
#include "../inc/ProductoEnPromocion.h"
#include "../inc/DTInfoPromocion.h"
#include "../inc/Fabrica.h"

#include <stdlib.h>

using namespace std;
namespace fs = std::filesystem;

// Estructura para almacenar los datos de cada fila del CSV
struct CasoPrueba {
    int id;
    std::string nombre;
    int edad;
};

// Función para leer un archivo CSV y almacenar los datos en un vector de estructuras CasoPrueba
std::vector<CasoPrueba> leerCSV(const std::string& nombreArchivo) {
    std::vector<CasoPrueba> casos;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return casos;
    }

    // Leer la primera línea (encabezados) y descartarla
    std::getline(archivo, linea);

    // Leer el archivo línea por línea
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string dato;
        CasoPrueba caso;

        // Leer y asignar los datos de cada columna a la estructura CasoPrueba
        std::getline(ss, dato, ',');
        caso.id = std::stoi(dato);
        std::getline(ss, caso.nombre, ',');
        std::getline(ss, dato, ',');
        caso.edad = std::stoi(dato);

        // Agregar el caso leído al vector de casos
        casos.push_back(caso);
    }

    archivo.close();
    return casos;
}

vector<string> listarArchivosCSV(const string& carpeta) {
    vector<string> archivosCSV;

    for (const auto& entry : fs::directory_iterator(carpeta)) {
        if (entry.path().extension() == ".csv") {
            archivosCSV.push_back(entry.path().string());
        }
    }

    return archivosCSV;
}


bool esBisiesto(int anio){
    bool aux;
    aux = (anio%4==0 && (!anio%100==0 || anio%400));
   return aux;
}

int diasMes(int mes, int anio){
    int cantDias;
    switch (mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        cantDias = 31;
        break;
        case 4: case 6: case 9: case 11:
        cantDias = 30;
        break;
        case 2:
            if (esBisiesto(anio))
                cantDias = 29;
             else 
                cantDias = 28;
        break;
        default: printf("Numero de mes invalido."); 
    }
    return cantDias;
}

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


//Vendedor* vendedor1 = new Vendedor("pepito", "contraV1", DTFecha(1,1,1), "123456789");    
//Vendedor* vendedor2 = new Vendedor("tiranosaurioRex", "contraV2", DTFecha(1,1,1), "987654321");
//Vendedor* vendedor3 = new Vendedor("solitarioGamer", "contraV3", DTFecha(1,1,1), "32134834");

//Cliente* cliente1 = new Cliente("un cliente1", "contraC1", DTFecha(1,1,1), DTDireccion("calle1", 123) ,"ciudad1");
//Cliente* cliente2 = new Cliente("un cliente2", "contraC2", DTFecha(1,1,1),DTDireccion("calle1", 123), "ciudad2");
//Cliente* cliente3 = new Cliente("un cliente3", "contraC3", DTFecha(1,1,1),DTDireccion("calle1", 123), "ciudad3");
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
controladorUsuarios->consultarNotificaciones("Donatelo");

cout << "````````````````````````````````````````````````````" << endl;
cout << "     ** CASO DE USO: Suscribirse FIN **" << endl;

// ** CASO DE USO: Suscribirse FIN ** //

//**FUNCIONES PARA FECHA**//



//----------------------**PRUEBA DE MENU INTERACTIVO**----------------------//

cout <<"               	-----    	¡Bienvenido a Mercado Finger!   	-----"<<endl;
cout <<" "<<endl;
cout <<"Antes de comenzar, por favor indique la fecha actual:"<<endl;
int anio=0;
int mes =0;
int dia=0;
cout <<"Ingrese el anio"<<endl;
cin>>anio;
cout <<"Ingrese el mes"<<endl;
cin>>mes;
while(mes>12 || mes<1){
	cout<<"Ingrese un mes valido:"<<endl;
	cin>>mes;
}
cout <<"Ingrese el dia"<<endl;
cin>>dia;
int cantDiasMes = diasMes(mes, anio);
while(dia>cantDiasMes || dia<1){
	cout<<"Ingrese un dia valido:"<<endl;
	cin>>dia;
}

cout <<"¿En que lo podemos asistir?"<<endl;
cout <<"Digite 1 para Alta de usuario."<<endl;
cout <<"Digite 2 para Listado de usuarios."<<endl;
cout <<"Digite 3 para Alta de producto."<<endl;
cout <<"Digite 4 para Consultar producto."<<endl;
cout <<"Digite 5 para Crear promocion."<<endl;
cout <<"Digite 6 para Consultar promocion."<<endl;
cout <<"Digite 7 para Realizar compra."<<endl;
cout <<"Digite 8 para Dejar comentario."<<endl;
cout <<"Digite 9 para Eliminar comentario."<<endl;
cout <<"Digite 10 para Enviar producto."<<endl;
cout <<"Digite 11 para Expediente de usuario."<<endl;
cout <<"Digite 12 para Suscribirse a notificaciones."<<endl;
cout <<"Digite 13 para Consultar notificaciones"<<endl;
cout <<"Digite 14 para Eliminar suscripciones."<<endl;
cout <<"Digite 15 para los casos de prueba "<<endl;


int entradaConsola;
cin>>entradaConsola;
while (entradaConsola != 0){
	switch (entradaConsola){
    	case 1:{
        	string NombreUsuario;
        	cout << "Indique Nombre del Usuario nuevo"<<endl;
        	cin>>NombreUsuario;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	string contra;
        	cout << "Indique contraseña del Usuario nuevo"<<endl;
        	cin>>contra;
        	int ano;
        	cout << "Indique año de nacimiento"<<endl;
        	cin>>ano;
        	int mes;
        	cout << "Indique mes de nacimiento"<<endl;
        	cin>>mes;
        	int dia;
        	cout << "Indique dia de nacimiento"<<endl;
        	cin>>dia;
        	cout <<"¿Desea registrar un vendedor o un cliente?" <<endl;
        	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	char c;
        	while (cin.get(c) && c != '\n');

        	string respuesta2;
        	getline(cin,respuesta2);
        	if (respuesta2 == "Cliente" || respuesta2 == "cliente" ){
            	cout << "Indique ciudad del cliente:"<<endl;
            	string ciudad;
            	getline(cin,ciudad);
				cout << "A continuación indique su dirección:"<<endl;
				cout << "Indique calle:"<<endl;
				string calle;
				getline(cin, calle);
				cout << "Indique número de puerta:"<<endl;
				int numPuerta;
				cin>>numPuerta;
            	bool a=controladorUsuarios->altaCliente(NombreUsuario, contra, DTFecha(dia,mes,ano),DTDireccion(calle, numPuerta), ciudad);
            	if (a) {
					cout <<"Su cliente fue creado"<<endl;
					break;
					}
				else {
					cout <<"No fue posible crear el cliente."<<endl;

				}
        	} else if(respuesta2 == "Vendedor" || respuesta2 == "vendedor" ){
            	string codigoRut;
            	cout << "Indique codigo Rut del vendedor"<<endl;
            	getline(cin,codigoRut);
            	if (controladorUsuarios->altaVendedor(NombreUsuario,contra, DTFecha(dia,mes,ano), codigoRut)){cout <<"Su vendedor fue creado"<<endl;}
        	} else {
            	break;
				}
        	break;
        	}
    	case 2:{
        	controladorUsuarios->listaDeUsuarios_();
            break;
    	}
    	case 3:{
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
		case 4:{
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
			cout << "Clientes: " << endl;
        	controladorVentas->listarNicknamesClientes();
        	cout << "Indique el nickname del cliente: "<<endl;
        	string nicknameCliente;
			cin.ignore();
        	getline(cin,nicknameCliente);
			cout << "\nListado de productos: \n" << endl;
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
		case 11:{
			cout << "Indique su nickname: "<<endl;
			string nicknameCliente;
			getline (cin, nicknameCliente);
			cout << "Suscripciones de " << nicknameCliente << ":" << endl;
			controladorUsuarios->listarSuscripciones(nicknameCliente);
			string respuesta6 = "Y";
			do {
				cout << "Indique el nickname del vendedor al que desea eliminar la suscripción: " << endl;
				string nicknameVendedor;
				getline(cin, nicknameVendedor);
				controladorUsuarios->eliminarSuscripciones(nicknameVendedor);
				
				cout << "Desea eliminar otra suscripción? Y/N" << endl;
				getline(cin, respuesta6);
/* 				if (respuesta6 == "N" || respuesta6 == "n") {
					break;
				} */
			} while (respuesta6 == "Y" || respuesta6 == "y");

		}
		case 15: {
			string carpeta = "data"; // Carpeta donde están los CSV
			vector<string> archivosCSV = listarArchivosCSV(carpeta);

			if (archivosCSV.empty()) {
       			std::cerr << "No se encontraron archivos CSV en la carpeta especificada." << std::endl;
       			return 1;
			
    		}
			cout << "Archivos CSV disponibles:" << endl;
   			for (size_t i = 0; i < archivosCSV.size(); ++i) {
      	  		cout << i + 1 << ". " << archivosCSV[i] << endl;
    		}
			std::cout << "Seleccione el número del archivo CSV que desea procesar: ";
   			size_t seleccion;
    		std::cin >> seleccion;

   	 	if (seleccion < 1 || seleccion > archivosCSV.size()) {
        	std::cerr << "Selección inválida." << std::endl;
        	return 1;
    	}

    	std::vector<CasoPrueba> casos = leerCSV(archivosCSV[seleccion - 1]);

    	// Imprimir los datos leídos
    	for (const auto& caso : casos) {
        	std::cout << "ID: " << caso.id << ", Nombre: " << caso.nombre << ", Edad: " << caso.edad << std::endl;
    	}


		}
    	default:
        	cout <<"Opción no válida." <<endl;
        	break;
	}
    cout<<"¿Desea realizar otra operación?"<<endl;
	cout <<"¿En que lo podemos asistir?"<<endl;
	cout <<"Digite 1 para Alta de usuario."<<endl;
	cout <<"Digite 2 para Listado de usuarios."<<endl;
	cout <<"Digite 3 para Alta de producto."<<endl;
	cout <<"Digite 4 para Consultar producto."<<endl;
	cout <<"Digite 5 para Crear promocion."<<endl;
	cout <<"Digite 6 para Consultar promocion."<<endl;
	cout <<"Digite 7 para Realizar compra."<<endl;
	cout <<"Digite 8 para Dejar comentario."<<endl;
	cout <<"Digite 9 para Eliminar comentario."<<endl;
	cout <<"Digite 10 para Enviar producto."<<endl;
	cout <<"Digite 11 para Expediente de usuario."<<endl;
	cout <<"Digite 12 para Suscribirse a notificaciones."<<endl;
	cout <<"Digite 13 para Consultar notificaciones"<<endl;
	cout <<"Digite 14 para Eliminar suscripciones."<<endl;
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