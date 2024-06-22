#ifndef CONTROLADORVENTAS_H
#define CONTROLADORVENTAS_H

#include "iControladorVentas.h"
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include "Cliente.h"
#include "Vendedor.h"
#include "Promocion.h"
#include "Compra.h"
#include "DTInfoPromocion.h"
#include "DTProductoCompra.h"
#include "ECategoria.h"
#include "Producto.h"
#include "DTFecha.h"
#include "DTInfoCompra.h"
using namespace std;

class ControladorVentas : public iControladorVentas{
    private:
        static ControladorVentas * ControladorVentasInst;
        ControladorVentas();

        int idCompra = 0;
        DTFecha fechaActual = DTFecha(0,0,0);
        //Colecciones:
        map<int ,Producto*> productos;
        set<Promocion*> promociones;
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
        set<Compra*> compras;

        //Datos que guarda este controlador para los casos de uso relacionados a promocion:
        string nombrePromo;
        string descripcionPromo;
        DTFecha fechaVencimientoPromo = DTFecha(0,0,0);
        string nicknameVendedorPromo;
        float descuentoPromo;
        set<ProductoEnPromocion*> productosPromo;
    
        //Datos que guarda este controlador para los casos de uso relacionados a compra:
        string nicknameClienteRealizarCompra;
        map<int, DTProductoCompra> datosProductoCompra;
        map<int, int> productosEnPromo;
        float montoTotalCompra;
        
    public:
        static ControladorVentas * getControladorVentas();
        void agregarProducto(int codigo, int cantMinima, float descuento);
        void listarNicknamesClientes();
        bool seleccionarCliente(string nickname);
        void mostrarDetallesCompra();
        void registrarCompra();
        //setters y getters INICIO
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setPromocion(Promocion *promocion);
        void setCompra(Compra *compra);
        void setProducto(Producto *producto);
        map<int, Producto*> getProductos();
        map<string, Vendedor*> getVendedores();
        map<string, Cliente*> getClientes();
        void setFechaPromo(DTFecha fechaPromocion);
        void setFechaActual(DTFecha fechaSistema);
        //setters y getters FIN
        void listarProductos();
        void consultarProducto(int codigo);
        vector<DTInfoPromocion> crearSetDTInfoPromocion();
        void listarPromociones();

        void consultarPromocion(string nombre);
        void cargarNuevoProducto(string nicknameVendedor,int codigo, string  nombreProd,float  precio , int stock , string  descripcion, ECategoria  categoria, bool enPromocion);
        void altaPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, float descuentoPromo);
        void seleccionarVendedor(string nickname);
        void agregarProducto(int codigo, int cantMinima);
        void infoVendedor(string nickname);
        void listarNicknamesVendedor();
        void agregarProductoCompra(int codigo, int cantMinima);
        void agregarProductoPromo(int codigo, int cantMinima);
        void liberarMemoriaRealizarCompra();
        void ingresarPromocion();
        void notificar(DTNotificacion);
        int listarProductosPendientes(string nickname); //devuelve 1 si existian productos pendientes
        int listarComprasAEnviar(Producto* producto); //devuelve 1 si existen compras pendientes de envio con ese producto
        void compraEnviada(int idCompra, int idProducto, string nickname);
        void procesarProductosEnPromo();
};

#endif // CONTROLADORVENTAS_H
