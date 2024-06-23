#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip> // Para setw
#include <limits>  // Para numeric_limits
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
/* namespace fs = std::filesystem;

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
} */


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

void mostrarBienvenida() {
    cout << "\033[2J\033[1;1H"; // Secuencia de escape ANSI para limpiar la pantalla
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║           ¡Bienvenido a Mercado Finger!            ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n\n";
}


void mostrarMenu() {
    cout << "╔════════════════════════════════════════╗\n";
    cout << "║           Menú Principal               ║\n";
    cout << "╠════════════════════════════════════════╣\n";
	cout << "║  0. ❌ Salir                           ║\n";
	cout << "║  1. 📁 Alta de usuario                 ║\n";
    cout << "║  2. 📋 Listado de usuarios             ║\n";
    cout << "║  3. 📁 Alta de producto                ║\n";
    cout << "║  4. 🔍 Consultar producto              ║\n";
    cout << "║  5. 🎁 Crear promoción                 ║\n";
    cout << "║  6. 🔍 Consultar promoción             ║\n";
    cout << "║  7. 🛒 Realizar compra                 ║\n";
    cout << "║  8. 💬 Dejar comentario                ║\n";
    cout << "║  9. 🗑️ Eliminar comentario             ║\n";
    cout << "║ 10. 📦 Enviar producto                 ║\n";
    cout << "║ 11. 🗃️ Expediente de usuario           ║\n";
    cout << "║ 12. 🔔 Suscribirse a notificaciones    ║\n";
    cout << "║ 13. 🔍 Consultar notificaciones        ║\n";
    cout << "║ 14. 🗑️ Eliminar suscripciones          ║\n";
    cout << "║ 15. 🧪 Casos de prueba                 ║\n";
    cout << "╚════════════════════════════════════════╝\n";
}

void pedirFechaActual(int& anio, int& mes, int& dia) {
    cout << "Antes de comenzar, por favor indique la fecha actual:\n";
    cout << "Ingrese el año: ";
    cin >> anio;

    cout << "Ingrese el mes: ";
    cin >> mes;
    while (mes > 12 || mes < 1) {
        cout << "Ingrese un mes válido: ";
        cin >> mes;
    }

    int cantDiasMes = 31; // Valor por defecto para establecer un límite inicial seguro
    switch (mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            cantDiasMes = 30;
            break;
        case 2:
            if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
                cantDiasMes = 29;
            } else {
                cantDiasMes = 28;
            }
            break;
        default:
            cantDiasMes = 31;
            break;
    }

    cout << "Ingrese el día: ";
    cin >> dia;
    while (dia > cantDiasMes || dia < 1) {
        cout << "Ingrese un día válido: ";
        cin >> dia;
    }

}

void esperarTecla() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar cualquier entrada previa
    cin.get(); // Espera a que el usuario presione Enter
}

int main() {

// ** FABRICA CREACION Y GET iCONTROLADORES** //
cout<<"SE CREA LA FABRICA"<<endl;
Fabrica * factoria;
factoria = factoria->getFabrica();
Fabrica * factoriaFake;
factoriaFake = factoriaFake->getFabrica();

if(factoria==factoriaFake){
	cout<<"LA FABRICA ES SINGLETON"<<endl;
}
else cout<<"ANDA COMO EL ORTOOOOOOOOOOO"<<endl;

// ----------------------------------------------- //



iControladorUsuarios* controladorUsuarios = factoria->getControladorUsuarios();
iControladorVentas* controladorVentas = factoria->getControladorVentas();

iControladorUsuarios* controladorUsuarios2 = factoria->getControladorUsuarios();
iControladorVentas* controladorVentas2 = factoria->getControladorVentas();

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

controladorVentas->cargarNuevoProducto("tiranosaurioRex",321, "productoTiranosaurio1", 1, 100, "el producto de Tiranosaurio uno",ECategoria::otros, false);
controladorVentas->cargarNuevoProducto("tiranosaurioRex",322, "productoTiranosaurio2", 2, 200, "el producto de Tiranosaurio dos",ECategoria::ropa, false);
controladorVentas->cargarNuevoProducto("tiranosaurioRex",323, "productoTiranosaurio2", 3, 300, "el producto de Tiranosaurio dos",ECategoria::ropa, false);


cout<< "** CASO DE USO: Alta Producto FIN**"<< endl;
cout<< "-----------------------------------------------------"<< endl;
// ** CASO DE USO: Alta Producto FIN ** //


// ** CASO DE USO: Crear Promocion INICIO ** //
cout<< "** CASO DE USO: Crear Promocion INICIO **"<< endl;
cout<< "-----------------------------------------------------"<< endl;

controladorVentas->altaPromocion("promocionZZZ", "sdfhjahsdga", DTFecha(1,2,3), 50);
controladorVentas->seleccionarVendedor("pepito");
controladorVentas->agregarProductoPromo(11,21);
controladorVentas->agregarProductoPromo(12,22);
controladorVentas->ingresarPromocion();
controladorVentas->consultarPromocion("promocionZZZ");

controladorVentas->altaPromocion("promocionVACIA", "sdfhjahsdgaaaaazzz", DTFecha(1,2,3), 25);
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
/*
US1 ana23 V 2,4,8,9
US2 carlos78 V 1,3,6,10,11
US3 diegom V 5,7,12,14
US4 juan87
US5 laura
US6 maria01 V
US7 natalia
US8 pablo10
US9 roberto
US10 sofia25 V 13,15
*/
// ** CASO DE USO: Dejar Comentario INICIO ** //

cout << "     ** CASO DE USO: Dejar Comentario INICIO **" << endl;
cout << "````````````````````````````````````````````````````" << endl;
//CM5
controladorUsuarios->seleccionarUsuario_("natalia");
controladorUsuarios->seleccionarProducto(1, "carlos78");
controladorUsuarios->nuevoComentario("¿Como es el ajuste? ¿Es ajustada o holgada?", DTFecha(02,06,2024));
//CM6
controladorUsuarios->seleccionarUsuario_("laura");
controladorUsuarios->seleccionarProducto(2, "ana23");
controladorUsuarios->nuevoComentario("¿Como es el ajuste? ¿Es ajustada o holgada?", DTFecha(02,06,2024));
//CM7
controladorUsuarios->seleccionarUsuario_("ana23");
controladorUsuarios->seleccionarProducto(2, "ana23");
controladorUsuarios->seleccionarComentario(5, "laura");
controladorUsuarios->nuevaRespuesta("El televisor LED tiene una resolucion de 4K UHD.", DTFecha(02, 06, 2024));
//CM8
controladorUsuarios->seleccionarUsuario_("pablo10");
controladorUsuarios->seleccionarProducto(2, "ana23");
controladorUsuarios->nuevoComentario("¿Tiene soporte para HDR10?", DTFecha(03, 06, 2024));
//CM9
controladorUsuarios->seleccionarUsuario_("ana23");
controladorUsuarios->seleccionarProducto(2, "ana23");
controladorUsuarios->seleccionarComentario(7, "laura");
controladorUsuarios->nuevaRespuesta("Si, soporta HDR10.", DTFecha(03, 06, 2024));
//CM10
controladorUsuarios->seleccionarUsuario_("natalia");
controladorUsuarios->seleccionarProducto(3, "carlos78");
controladorUsuarios->nuevoComentario("¿La chaqueta de cuero es resistente al agua?", DTFecha(03, 06, 2024));
//CM11
controladorUsuarios->seleccionarUsuario_("carlos78");
controladorUsuarios->seleccionarProducto(3, "carlos78");
controladorUsuarios->seleccionarComentario(9, "natalia");
controladorUsuarios->nuevaRespuesta("No, la chaqueta de cuero no es resistente al agua", DTFecha(03, 06, 2024));
//CM12
controladorUsuarios->seleccionarUsuario_("laura");
controladorUsuarios->seleccionarProducto(3, "carlos78");
controladorUsuarios->seleccionarComentario(9, "natalia");
controladorUsuarios->nuevaRespuesta("¿Viene en otros colores?", DTFecha(04, 06, 2024));
//CM13
controladorUsuarios->seleccionarUsuario_("carlos78");
controladorUsuarios->seleccionarProducto(3, "carlos78");
controladorUsuarios->seleccionarComentario(11, "laura");
controladorUsuarios->nuevaRespuesta("Si, tambien esta disponible en marron.", DTFecha(04, 06, 2024));
//CM14
controladorUsuarios->seleccionarUsuario_("roberto");
controladorUsuarios->seleccionarProducto(3, "carlos78");
controladorUsuarios->seleccionarComentario(9, "natalia");
controladorUsuarios->nuevaRespuesta("¿Es adecuada para climas frios?", DTFecha(04, 06, 2024));
//CM15
controladorUsuarios->seleccionarUsuario_("pablo10");
controladorUsuarios->seleccionarProducto(4, "ana23");
controladorUsuarios->nuevoComentario("¿El microondas digital tiene funcion de descongelacion rapida?", DTFecha(04, 06, 2024));
//CM16 ==== ACA ====
controladorUsuarios->seleccionarUsuario_("ana23");
controladorUsuarios->seleccionarProducto(4, "ana23");
controladorUsuarios->seleccionarComentario(9, "natalia");
controladorUsuarios->nuevaRespuesta("Si, el microondas digital incluye una funcion de descongelacion rapida.", DTFecha(04, 06, 2024));
//CM17
controladorUsuarios->seleccionarUsuario_("natalia");
controladorUsuarios->seleccionarProducto(4, "ana23");
controladorUsuarios->seleccionarComentario(14, "roberto");
controladorUsuarios->nuevaRespuesta("¿Cuantos niveles de potencia tiene? ", DTFecha(05, 06, 2024));
//CM18
controladorUsuarios->seleccionarUsuario_("ana23");
controladorUsuarios->seleccionarProducto(4, "ana23");
controladorUsuarios->seleccionarComentario(16, "natalia");
controladorUsuarios->nuevaRespuesta("Tiene 10 niveles de potencia.", DTFecha(05, 06, 2024));
//CM19
controladorUsuarios->seleccionarUsuario_("roberto");
controladorUsuarios->seleccionarProducto(4, "ana23");
controladorUsuarios->seleccionarComentario(14, "roberto");
controladorUsuarios->nuevaRespuesta("¿Es facil de limpiar? ", DTFecha(05, 06, 2024));
//CM20
controladorUsuarios->seleccionarUsuario_("roberto");
controladorUsuarios->seleccionarProducto(5, "diegom");
controladorUsuarios->nuevoComentario("¿La luz LED se puede controlar con una aplicacion movil?", DTFecha(05, 06, 2024));

cout<< "````````````````````````````````````````````````````" << endl;
cout << "     ** CASO DE USO: Dejar Comentario FIN **" << endl;



cout << "     ** CASO DE USO: Eliminar Comentario INICIO **" << endl;
cout << "````````````````````````````````````````````````````" << endl;


cout << "````````````````````````````````````````````````````" << endl;
cout << "     ** CASO DE USO: Eliminar Comentario FIN **" << endl;

// ** CASO DE USO: Dejar Comentario FIN ** //

// ** CASO DE USO: Suscribirse INICIO ** //

cout << "     ** CASO DE USO: Suscribirse INICIO **" << endl;
cout << "````````````````````````````````````````````````````" << endl;


//controladorUsuarios->imprimirListaDeVendedores();
controladorUsuarios->imprimirSuscripcionesDisponiblesPara("Donatelo");
controladorUsuarios->suscribirmeA("tiranosaurioRex");
controladorUsuarios->imprimirSuscripcionesDisponiblesPara("Donatelo");
controladorUsuarios->suscribirmeA("tiranosaurioRex");
controladorVentas->altaPromocion("promocionTIRA", "kkkkkkkkkkkk", DTFecha(25,6,2024), 50);
controladorVentas->seleccionarVendedor("tiranosaurioRex");
controladorVentas->agregarProductoPromo(321,1);
controladorVentas->agregarProductoPromo(322,1);
controladorVentas->agregarProductoPromo(323,1);
controladorVentas->ingresarPromocion();

controladorUsuarios->consultarNotificaciones("Donatelo");
controladorUsuarios->consultarNotificaciones("Donatelo");

cout << "````````````````````````````````````````````````````" << endl;
cout << "     ** CASO DE USO: Suscribirse FIN **" << endl;



//---------------------Casos de prueba tarea 4---------------------//
	//Datos básicos de usuarios:
controladorUsuarios->altaVendedor("ana23", "qwer1234", DTFecha(15,5,1988), "212345678001");
controladorUsuarios->altaVendedor("carlos78", "asdfghj", DTFecha(18,6,1986), "356789012345");
controladorUsuarios->altaVendedor("diegom", "zxcvbn", DTFecha(28,7,1993), "190123456789");
controladorUsuarios->altaVendedor("maria01", "5tgb6yhn", DTFecha(25,3,1985), "321098765432");
controladorUsuarios->altaVendedor("sofia25", "1234asdf", DTFecha(7,12,1983), "445678901234");
controladorUsuarios->altaCliente("juan87", "1qaz2wsx", DTFecha(20,10,1992),DTDireccion("Av. 18 de Julio", 456), "Melo");
controladorUsuarios->altaCliente("laura", "3edc4rfv", DTFecha(22,9,1979),DTDireccion("Rondeau", 1617), "Montevideo");
controladorUsuarios->altaCliente("natalia", "poiuyt", DTFecha(14,4,1982),DTDireccion("Paysandú", 2021), "Salto");
controladorUsuarios->altaCliente("pablo10", "lkjhgv", DTFecha(30,8,1990),DTDireccion("Av. Rivera ", 1819), "Mercedes");
controladorUsuarios->altaCliente("roberto", "mnbvcx", DTFecha(12,11,1995),DTDireccion("Av. Brasil", 1011), "Montevideo");
	//Datos de prodcutos:

controladorVentas->cargarNuevoProducto("carlos78", 1, "Camiseta Azul", 1400, 50, "Camiseta de poliéster, color azul", ropa, false);
controladorVentas->cargarNuevoProducto("ana23", 2, "Televisor LED", 40500, 30, "Televisor LED 55 pulgadas", electrodomesticos, false);
controladorVentas->cargarNuevoProducto("carlos78", 3, "Chaqueta de Cuero", 699.99, 20, "Chaqueta de cuero, color negro", ropa, false);
controladorVentas->cargarNuevoProducto("ana23", 4, "Microondas Digital", 1199.99, 15, "Microondas digital, 30L", electrodomesticos, false);
controladorVentas->cargarNuevoProducto("diegom", 5, "Luz LED", 599.99, 40, "Luz Bluetooth LED", otros, false);
controladorVentas->cargarNuevoProducto("carlos78", 6, "Pantalones Vaqueros", 60, 25, "Pantalones vaqueros, talla 32", ropa, false);
controladorVentas->cargarNuevoProducto("diegom", 7, "Auriculares Bluetooth", 199.99, 35, "Auriculares bluetooth para celular", otros, false);
controladorVentas->cargarNuevoProducto("ana23", 8, "Refrigerador", 15499, 10, "Refrigerador de doble puerta", electrodomesticos, false);
controladorVentas->cargarNuevoProducto("ana23", 9, "Cafetera", 23000, 50, "Cafetera de goteo programable", electrodomesticos, false);
controladorVentas->cargarNuevoProducto("carlos78", 10, "Zapatillas Deportivas", 5500, 20, "Zapatillas para correr, talla 42", ropa, false);
controladorVentas->cargarNuevoProducto("carlos78", 11, "Mochila", 9000, 30, "Mochila de viaje, 40L", otros, false);
controladorVentas->cargarNuevoProducto("diegom", 12, "Plancha de Ropa", 2534, 25, "Plancha a vapor, 1500W", electrodomesticos, false);
controladorVentas->cargarNuevoProducto("sofia25", 13, "Gorra", 200, 50, "Gorra para deportes, color rojo", ropa, false);
controladorVentas->cargarNuevoProducto("diegom", 14, "Tablet", 15000, 15, "Tablet Android de 10 pulgadas", electrodomesticos, false);
controladorVentas->cargarNuevoProducto("sofia25", 15, "Reloj de Pared", 150.50, 20, "Reloj de pared vintage", otros, false);

	//Datos de promociones:


controladorVentas->altaPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", DTFecha(25, 10, 2024), 30);
controladorVentas->seleccionarVendedor("ana23");
controladorVentas->agregarProductoPromo(2, 1);
controladorVentas->ingresarPromocion();

//controladorVentas->altaPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", DTFecha(25, 10, 2024), 30);
controladorVentas->altaPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", DTFecha(26, 10, 2024), 20);
controladorVentas->seleccionarVendedor("carlos78");
controladorVentas->agregarProductoPromo(6, 3);
controladorVentas->agregarProductoPromo(3, 2);
controladorVentas->ingresarPromocion();

controladorVentas->altaPromocion("Domotica", "Para modernizar tu casa", DTFecha(26, 10, 2024), 10);
controladorVentas->seleccionarVendedor("diegom");
controladorVentas->agregarProductoPromo(5, 2);
controladorVentas->ingresarPromocion();

controladorVentas->altaPromocion("Liquidacion", "Hasta agotar stock", DTFecha(26, 3, 2024), 10);
controladorVentas->seleccionarVendedor("diegom");
controladorVentas->agregarProductoPromo(14, 1);
controladorVentas->ingresarPromocion();


//----------------------**MENU INTERACTIVO**----------------------//

int anio = 0;
int mes = 0;
int dia = 0;

mostrarBienvenida();
pedirFechaActual(anio, mes, dia);

    // Creación de la fecha actual
cout << "\nFecha actual establecida: " << setw(2) << setfill('0') << dia << "/" 
     << setw(2) << setfill('0') << mes << "/" << anio << endl;

  controladorVentas->setFechaActual(DTFecha(dia,mes,anio));
    // Aquí podrías continuar con la lógica de tu programa

esperarTecla(); // Espera a que el usuario presione Enter
    
int opcion;

do {
    mostrarMenu();
    cout << "Ingrese la opción deseada: ";
    cin >> opcion;
    switch (opcion) {
        case 1:{
			string nombreUsuario;
			cout << "Indique Nombre del Usuario nuevo"<<endl;
			cin>>nombreUsuario;
			while(controladorUsuarios->existeNickname(nombreUsuario)){
				cout<<"El nickname ya se encuentra registrado, por favor ingrese otro."<<endl;
				cin>>nombreUsuario;
				cout << "Ha seleccionado Alta de usuario.\n";
			}
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
				bool a=controladorUsuarios->altaCliente(nombreUsuario, contra, DTFecha(dia,mes,ano),DTDireccion(calle, numPuerta), ciudad);
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
					if (controladorUsuarios->altaVendedor(nombreUsuario,contra, DTFecha(dia,mes,ano), codigoRut)){
						cout <<"Su vendedor fue creado"<<endl;}
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
        	cout <<"Elija el nombre de un vendedor para asignarle el producto: "<<endl;

        	controladorUsuarios->listaDeVendedores();
        	string nombreVendedor;
        	cin>>nombreVendedor;
        	string nombreProducto;
        	cout<<"Indique el nombre del producto"<<endl;
        	cin>>nombreProducto;
            int codigo;
        	cout<<"Indique el codigo del producto"<<endl;
        	cin>>codigo;
			while(controladorVentas->existeCodigo(codigo)){
				cout<<"El codigo ingresado ya le corresponde a otro producto, por favor ingrese uno distinto: "<<endl;
				cin>>codigo;
			}
			cout<<"Indique el precio del producto"<<endl;
        	float precio;
        	cin>>precio;
			cout<<"Indique la cantidad en stock del producto"<<endl;
        	int stock;
        	cin>>stock;
			cin.ignore();
        	string descripcion;
        	cout<<"Indique la descripcion del producto"<<endl;
        	getline(cin,descripcion);
        	cout<<"Indique a cual categoria pertenece su producto: 1-ropa, 2-electrodomesticos, 3-otros"<<endl;   
        	int categoria;
        	cin>>categoria;
			while(categoria<1 || categoria > 3){
				cout<<"Categoria invalida, ingrese una de las indicadas: "<<endl;
				cin>>categoria;
			}
        	ECategoria categoriaEnum = static_cast<ECategoria>(categoria-1); 	 
       	    controladorVentas->cargarNuevoProducto(nombreVendedor,codigo,nombreProducto, precio ,stock ,descripcion, categoriaEnum, false);
            break;
    	}
		case 4:{
			controladorVentas->listarProductos();
			cout << "Desea consultar algun producto en especifico? Y/N ?" << endl;
			char respuesta1;
			cin >> respuesta1;
			if (respuesta1 == 'Y' || respuesta1 == 'y'){
				cout << "Indique el codigo del producto que desea consultar:" << endl;
				int codigo;
				cin >> codigo;
				controladorVentas->consultarProducto(codigo);
			}
			break;
		}
		case 5:{
			cout << "Ingrese el nombre de la promocion" << endl;
			cin.ignore();
			string nombrePromo;
			getline(cin, nombrePromo);
			cout << "Ingrese la descripcion de la promocion" << endl;
			string descPromo;
			getline(cin, descPromo);
			cout << "A continuacion ingrese la fecha de vencimiento de su promo:" << endl;
			int anioProm = 0;
			int mesProm = 0;
			int diaProm = 0;
			cout << "Ingrese el anio" << endl;
			cin >> anioProm;
			while (anioProm < anio){
				cout << "Ingrese un anio valido:" << endl;
				cin >> anioProm;
			}
			if(anioProm==anio){ //si el anio es igual, pido mes >=
				cout<<"Ingrese el mes"<<endl;
				cin>>mesProm;
				while(mesProm>12 || mesProm<1||mesProm<mes){
					cout<<"Ingrese un mes valido:"<<endl;
					cin>>mesProm;
				}
			}else{//si el anio ya es mas grande me sirve cualquier mes
				cout<<"Ingrese el mes"<<endl;
				cin>>mesProm;
				while(mesProm>12 || mesProm<1){
					cout<<"Ingrese un mes valido:"<<endl;
					cin>>mesProm;
				}
			}
			if(anioProm==anio && mesProm==mes){//si el anio y el mes sin iguales, pido dia >=
				cout <<"Ingrese el dia"<<endl;
				cin>>diaProm;
				int cantDiasMesProm = diasMes(mesProm, anioProm);
				while(diaProm>cantDiasMesProm || diaProm<1||diaProm<dia){
					cout<<"Ingrese un dia valido:"<<endl;
					cin>>diaProm;
				}	
			}else{//el anio o el mes ya es mas grande, me sirve cualquier dia
				cout <<"Ingrese el dia"<<endl;
				cin>>diaProm;
				int cantDiasMesProm = diasMes(mesProm, anioProm);
				while(diaProm>cantDiasMesProm || diaProm<1){
					cout<<"Ingrese un dia valido:"<<endl;
					cin>>diaProm;
				}	
			}
			cout << "Ingrese el descuento de la promocion: " << endl;
			float descuento;
			cin >> descuento;
			while (descuento < 0){
				cout << "Ingrese un descuento valido:" << endl;
				cin >> descuento;
			}
			controladorVentas->altaPromocion(nombrePromo, descPromo, DTFecha(diaProm, mesProm, anioProm), descuento);
			string nombreVendedor;
			cin >> nombreVendedor;
			while (!(controladorUsuarios->existeNickname(nombreVendedor) && controladorUsuarios->esVendedor(nombreVendedor))){
				cout << "Ingrese un vendedor valido: " << endl;
			}
			while (!controladorVentas->vendedorTieneProductos(nombreVendedor)){
				cout << "En este momento " << nombreVendedor << " no posee ningun producto asociado, vuelva a intentar con otro:" << endl;
				cin >> nombreVendedor;
			}
			controladorVentas->seleccionarVendedor(nombreVendedor);
			while (!controladorVentas->alMenosUnProductoPromo()){
				cout << "Ingrese el codigo del producto que desea agregar:" << endl;
				int codigoProd;
				cin >> codigoProd;
				cout << "Ingrese la cantidad minima del producto seleccionado:" << endl;
				int cantProd;
				cin >> cantProd;
				controladorVentas->agregarProductoPromo(codigoProd, cantProd);
			}
			cout << "Desea agregar otro producto a la promocion? Y/N" << endl;
			char masProds;
			cin >> masProds;
			if (masProds == 'Y' || masProds == 'y'){
				while (masProds == 'Y' || masProds == 'y')
				{
					cout << "Ingrese el codigo del producto que desea agregar:" << endl;
					int codigoProd;
					cin >> codigoProd;
					cout << "Ingrese la cantidad minima del producto seleccionado:" << endl;
					int cantProd;
					cin >> cantProd;
					controladorVentas->agregarProductoPromo(codigoProd, cantProd);
					cout << "Desea agregar otro producto a la promocion? Y/N" << endl;
					cin >> masProds;
				}
			}
			controladorVentas->ingresarPromocion();
			break;
		}
		case 6:{
			controladorVentas->listarPromociones();
			cout << "Desea consultar alguna promocion en especifico? Y/N ?" << endl;
			char respuesta5;
			cin >> respuesta5;
			if (respuesta5 == 'Y' || respuesta5 == 'y'){
				cout << "Indique el nombre de la promocion que desea consultar:" << endl;
				string nombrePromocion;
				cin >> nombrePromocion;
				controladorVentas->consultarPromocion(nombrePromocion);
			}
			break;
		}
		/* case 6
		controladorVentas->listarPromociones();
		cout << "Desea consultar alguna promocion en especifico? Y/N ?" <<endl;
		char respuesta5;
		cin>> respuesta5;
		if (respuesta5 == 'Y' || respuesta5 == 'y' ){
			cout << "Indique el nombre de la promocion que desea consultar:" <<endl;
			string nombrePromocion;
			cin>> nombrePromocion;
			controladorVentas->consultarPromocion(nombrePromocion);
		}*/
		case 7:{
			cout << "Clientes: " << endl;
        	controladorVentas->listarNicknamesClientes();
        	cout << "Indique el nickname del cliente: "<<endl;
        	string nicknameCliente;
			cin.ignore();
        	getline(cin,nicknameCliente);
			while(!controladorVentas->seleccionarCliente(nicknameCliente)){
				cout << "Nickname inválido. Intente nuevamente ingresando un nickname valido" << endl;
				getline(cin,nicknameCliente);
			}
        	string respuesta3 = "Y";
			bool flag = false;
        	while (respuesta3 != "N" && respuesta3 != "n"){
            	cout << "Desea agregar un producto a la compra? Y/N"<<endl;
            	getline(cin,respuesta3);
            	if (respuesta3 == "Y" || respuesta3 == "y"){
					flag = true;
                	cout << "Indique el codigo y cantidad del producto a agregar en la compra" <<endl;
                	int codigo;
                	cin>>codigo;
                	int cantidad;
                	cin>>cantidad;
                	controladorVentas->agregarProductoCompra(codigo, cantidad);
					cin.ignore();
            	} else if (respuesta3 == "N" || respuesta3 == "n"){
                	break;
            	} else {
                	cout << "Opción no válida." <<endl;
            	}
        	}
			if (flag){
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
			}
			controladorVentas->liberarMemoriaRealizarCompra();
            break;
    	}
		case 8: {
			controladorUsuarios->imprimirListaDeUsuarios();
			string NombreUsuario;
			cout << "Indique Nombre del Usuario que desea agregar un comentario: ";
			cin >> NombreUsuario;
			controladorUsuarios->seleccionarUsuario_(NombreUsuario);
			controladorUsuarios->listarProductos();
			int CodigoProducto;
			cout << "Escriba el código del producto al que desea ingresar un comentario: ";
			cin >> CodigoProducto;
			cin.ignore();
			string NombreVendedor;
			cout << "Escriba el nombre del vendedor que publico el producto: ";
			cin >> NombreVendedor;
			controladorUsuarios->seleccionarProducto(CodigoProducto, NombreVendedor);
			cin.ignore(); // Ignorar el carácter de nueva línea residual
			string respuesta;
			cout << "¿Desea dejar un comentario nuevo (C) o responder uno ya existente (R)? ";
			do{
				getline(cin, respuesta);
				if (respuesta == "c" || respuesta == "C")
				{
					string comentario;
					cout << "Escriba el comentario: ";
					getline(cin, comentario);
					controladorUsuarios->nuevoComentario(comentario, DTFecha(dia, mes, anio));
					cout << "El comentario fue agregado" << endl;
				}
				else if (respuesta == "r" || respuesta == "R")
				{
					controladorUsuarios->listarComentarios(CodigoProducto);
					int id;
					cout << "Escriba el ID del comentario al que desea responder: ";
					cin >> id;
					string comentador;
					cout << "Escriba el nombre del autor del comentario al que desea responder: ";
					cin >> comentador;
					controladorUsuarios->seleccionarComentario(id, comentador);
					cin.ignore(); // Ignorar el carácter de nueva línea residual
					string comentario;
					cout << "Escriba el comentario: ";
					getline(cin, comentario);
					controladorUsuarios->nuevaRespuesta(comentario, DTFecha(1, 1, 1));
					cout << "El comentario fue agregado" << endl;
				}
				else{
					cout << "Opcion invalida. \n";
				}
			} while (respuesta != "C" || respuesta != "c" || respuesta != "R" || respuesta != "r");
			break;
		}
		case 9:{
			controladorUsuarios->imprimirListaDeUsuarios();
			string NombreUsuario;
			cout << "Indique Nombre del Usuario al que desea eliminar un comentario: ";
			cin >> NombreUsuario;
			controladorUsuarios->seleccionarUsuario_(NombreUsuario);
			controladorUsuarios->listarComentariosUsuario(NombreUsuario);
			int IdComentario;
			cout << "Indique ID del comentario que desea eliminar: ";
			cin >> IdComentario;
			string NombreAutor;
			cout << "Indique nombre del autor del comentario que desea eliminar: ";
			cin >> NombreAutor;
			Comentario *comentarioAEliminar = controladorUsuarios->buscarComentario(IdComentario, NombreAutor);
			controladorUsuarios->eliminarComentarioRecursivo(comentarioAEliminar);
			break;
    	}
		case 10:{
		    cout << "Vendedores disponibles:" << endl;
		   	controladorVentas->listarNicknamesVendedor();
			cout <<"Indique el nickname de vendedor:" << endl;
			string nickname;
			cin >> nickname;
			if (controladorVentas->listarProductosPendientes(nickname) == 1){
				cout <<"Indique el codigo del producto deseado:" << endl;
				int producto;
				cin>>producto;
				if (controladorVentas->getProductos().find(producto)->first == producto)
				{
					Producto* ptrProducto = controladorVentas->getProductos().find(producto)->second;
					if (controladorVentas->listarComprasAEnviar(ptrProducto) == 1)
					{
						cout << "Seleccione el numero de compra a enviar:" << endl;
						int idCompra;
						cin >> idCompra;

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
		case 11:{
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
		case 12:{
			cout << "Usted ha seleccionado suscribirse a notificaciones:"<<endl;
			cout <<"Desea ver un listado con los posibles suscriptores? Y/N"<<endl;
			char resp;
			cin>>resp;
			if (resp == 'Y' || resp == 'y'){
				controladorUsuarios->imprimirListaDeClientes();
			}
			cout<<"Indique el nombre del nuevo suscriptor"<<endl;
			string suscriptorNuevo;
			cin>>suscriptorNuevo;
			controladorUsuarios->imprimirSuscripcionesDisponiblesPara(suscriptorNuevo);
			cout<<"Desea registrar una nueva suscripcion entre las disponibles? Y/N"<<endl;
			char resp2;
			cin>>resp2;
			while(resp2!='n'&& resp2!='N'){
			cout<<"Indique a quien desea suscribirse para empezar a recibir sus notificaciones: "<<endl;
			string creadorDeContenido;
			cin>>creadorDeContenido;
			controladorUsuarios->suscribirmeA(creadorDeContenido);
			cout<<"Desea ingresar otra suscripcion? Y/N"<<endl;
			cin>>resp2;
			}
			break;
		}
		case 13:{
			cout<<"Indique el nombre del cliente"<<endl;
        	string NombreCliente;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	cin>>NombreCliente;
			cout<<NombreCliente<<endl;
        	controladorUsuarios->consultarNotificaciones(NombreCliente);
            break;
    	}
		case 14:{
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
				if (respuesta6 == "N" || respuesta6 == "n") {
					break;
				} 
			} while (respuesta6 == "Y" || respuesta6 == "y");
			break;
		} 
		/*case 15: {
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
		} */
    	/*default:
        	cout <<"Opción no válida." <<endl;
        	break;
	}*/
		case 0:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opción inválida. Por favor, ingrese una opción válida.\n";
			break;
        }
	} while (opcion != 0);
    /*cout<<"¿Desea realizar otra operación?"<<endl;
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
};*/




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