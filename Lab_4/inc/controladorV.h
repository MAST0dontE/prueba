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
        set<string> altaPromocion(string, string, DTfecha);
        set<DTidProducto> seleccionarVendedor(string);
        void agregarProducto(int, int, float);
        bool ingresarPromocion();
        set<string> listarNicknamesClientes() ;
        set<DTidProducto> seleccionarCliente(string);
        DTinfoCompra mostrarDetallesCompra();
        void registrarCompra();
        bool ingresarPromocion();
};

#endif // CONTROLADORVENTAS_H
