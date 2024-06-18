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
#include "ECategoria.h"
#include "Producto.h"
#include "DTFecha.h"
#include "DTInfoCompra.h"
using namespace std;

class ControladorVentas : public iControladorVentas{
    private:
        map<int ,Producto*> productos; //cambiar a map
        set<Promocion*> promociones;
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
        map<string, Vendedor*>::iterator it;
        set<Compra*> compras;
        //atributos para los datos de promocion
        string nombrePromo;
        string descripcionPromo;
        DTFecha fechaVencimientoPromo = DTFecha(0,0,0);
        string nicknameVendedorPromo;
        
        map<int, DTInfoProducto> datosProductosPromo;
        
        //atributos para los datos de compra
        string nicknameClienteRealizarCompra;
        vector<DTProductoCompra> datosCompra;
        float montoTotalCompra;
        
    public:
        void agregarProducto(int codigo, int cantMinima, float descuento);
        void listarNicknamesClientes();
        void seleccionarCliente(string nickname);
        DTInfoCompra mostrarDetallesCompra();
        void registrarCompra();
        bool ingresarPromocion();
        //setters y getters INICIO
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setPromocion(Promocion *promocion);
        void setCompra(Compra *compra);
        void setProducto(Producto *producto);
        map<int, Producto*> getProductos();
        void setFechaPromo(DTFecha fechaPromocion);
        //setters y getters FIN
        void listarProductos();
        void consultarProducto(int codigo, string nombre);
        vector<DTInfoPromocion> crearSetDTInfoPromocion();
        void listarPromociones();

        void consultarPromocion(string nombre);
        void cargarNuevoProducto(string nicknameVendedor,string  nombreProd,float  precio , int stock , string  descripcion, ECategoria  categoria, bool enPromocion);
        void altaPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento);
        void seleccionarVendedor(string nickname);
        void agregarProductoCompra(int codigo, int cantMinima);

        void liberarMemoriaRealizarCompra();
};

#endif // CONTROLADORVENTAS_H
