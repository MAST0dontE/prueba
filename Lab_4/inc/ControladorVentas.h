#ifndef CONTROLADORVENTAS_H
#define CONTROLADORVENTAS_H

#include "iControladorVentas.h"
#include <string>
#include <set>
#include "Cliente.h"
#include "Vendedor.h"
#include "Promocion.h"
#include "Compra.h"
#include "Producto.h"
#include "DTFecha.h"
#include "DTInfoCompra.h"
using namespace std;

class ControladorVentas : public iControladorVentas{
    private:
        set<Producto*> productos;
        
    public:
        set<string> altaPromocion(string nickname, string descripcion, DTFecha fechaCreacion);
        void agregarProducto(int codigo, int cantMinima, float descuento);
        set<string> listarNicknamesClientes() ;
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
        //nuevos cambios
        set<DTInfoProducto> listarProductos();

};

#endif // CONTROLADORVENTAS_H
