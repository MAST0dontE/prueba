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

class ControladorVentas : public iControladorVentas{
    public:
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        void setPromocion(Promocion *promocion);
        void setCompra(Compra *compra);
        void setProducto(Producto *producto);

        std::set<std::string> altaPromocion(std::string, std::string, DTFecha);

        std::set<DTIdProducto> seleccionarVendedor(std::string);

        void agregarProducto(int, float);
        bool ingresarPromocion();

        std::set<std::string> listarNicknamesClientes();
        std::set<DTIdProducto> seleccionarCliente(std::string);

        void mostrarDetallesCompra(DTInfoCompra);
        void registrarCompra();
        bool ingresarPromocion();
};

#endif // CONTROLADORVENTAS_H
