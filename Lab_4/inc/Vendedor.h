#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"
#include "Producto.h"
#include "DTFecha.h"
#include <string>
using namespace std;
class Vendedor : public Usuario{
    private:
        string codigoRUT;
        set<Producto*> productosVendedor;
    public:
        //GETTERS
        string getCodigoRUT();
        Vendedor(string contrasenia, string nickname, DTFecha fecha, string codigoRUT);
        void notificar();
        void agregarProducto(Producto* producto);
        void setearProductosVendedor(set<Producto*>);
        string toString();
        bool esVendedor() const override{return true; }
        vector<DTInfoProducto> obtenerProductos()const;
        vector<Comentario> listarComentarios(string) override;
        set<Producto*> getProductos();
        void agregarComentario(Comentario*);
        map<int, Comentario*> getComentarios();
};

#endif // VENDEDOR_H
