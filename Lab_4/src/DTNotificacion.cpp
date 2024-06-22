#include "../inc/DTNotificacion.h"

DTNotificacion::DTNotificacion(string nicknameVendedor, string nombrePromo, map<int, DTInfoProducto> productos): nicknameVendedor(nicknameVendedor), nombrePromo(nombrePromo)
{
};
string DTNotificacion:: getNicknameVendedor(){
    return nicknameVendedor;
}
string DTNotificacion:: getNombrePromo(){
    return nombrePromo;
}
/*string DTNotificacion:: getDTInfoProductoNotificacion(){
    string MegaSuperInfoProducto;
    for(auto producto:productos){
        MegaSuperInfoProducto +=producto.second.getDTInfoProducto() + "\n";
    }
    return MegaSuperInfoProducto ;
}*/