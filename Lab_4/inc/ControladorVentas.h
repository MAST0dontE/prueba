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
        set<Producto*> productos;
        set<Promocion*> promociones;
        map<string, Cliente*> clientes;
        map<string, Vendedor*> vendedores;
        set<Compra*> compras;
        
    public:
        set<string> altaPromocion(string nickname, string descripcion, DTFecha fechaCreacion);
        void agregarProducto(int codigo, int cantMinima, float descuento);
        set<string> listarNicknamesClientes();
        set<DTInfoProducto> seleccionarCliente(string nickname);
        set<DTInfoProducto> seleccionarVendedor(string nickname);
        DTInfoCompra mostrarDetallesCompra();
        void registrarCompra();
        bool ingresarPromocion();
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setPromocion(Promocion *promocion);
        void setCompra(Compra *compra);
        void setProducto(Producto *producto);
        set<Producto*> getProductos();
        //nuevos cambios
        void listarProductos();
        void consultarProducto(int codigo, string nombre);
        vector<DTInfoPromocion> listarPromociones();
        void consultarPromocion(string nombre);
        void cargarNuevoProducto(string nicknameVendedor,string  nombreProd,float  precio , int stock , string  descripcion, ECategoria  categoria);
       
};

#endif // CONTROLADORVENTAS_H
