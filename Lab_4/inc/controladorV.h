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
using namespace std;

class ControladorVentas : public iControladorVentas{
    public:
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setPromocion(Promocion *promocion);
        void setCompra(Compra *compra);
        void setProducto(Producto *producto);

        set<string> altaPromocion(string, string, DTFecha);

        set<DTIdProducto> seleccionarVendedor(string);

        void agregarProducto(int, float);
        bool ingresarPromocion();

        set<string> listarNicknamesClientes();
        set<DTIdProducto> seleccionarCliente(string);

        void mostrarDetallesCompra(DTInfoCompra);
        void registrarCompra();
        bool ingresarPromocion();
};

#endif // CONTROLADORVENTAS_H
