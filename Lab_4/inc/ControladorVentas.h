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
    public:
        set<string> altaPromocion(string nickname, string descripcion, DTFecha fechaCreacion);
        void agregarProducto(int codigo, int cantMinima, float descuento);
        bool ingresarPromocion();
        set<string> listarNicknamesClientes() ;
        set<DTIdProducto> seleccionarCliente(string nickname);
        set<DTIdProducto> seleccionarVendedor(string nickname);
        DTInfoCompra mostrarDetallesCompra();
        void registrarCompra();
        bool ingresarPromocion();
};

#endif // CONTROLADORVENTAS_H
