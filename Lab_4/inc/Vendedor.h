#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "Usuario.h"
#include "Producto.h"
#include "DTFecha.h"
#include "iSuscriptor.h"
#include <string>
using namespace std;
class Vendedor : public Usuario{
    private:
        string codigoRUT;
        set<Producto*> productosVendedor;
        map<string, iSuscriptor*> suscriptores;
        
    public:
        //GETTERS
        string getCodigoRUT();
        Vendedor(string nickname, string contrasenia, DTFecha fecha, string codigoRUT);
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
        void listarProductosVendedor();
        void agregarSuscriptor(iSuscriptor* suscriptor);
        void removerSuscriptor(iSuscriptor* suscriptor);
        bool estaSuscripto(string nickname);
};

#endif // VENDEDOR_H
