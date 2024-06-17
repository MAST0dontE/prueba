#include "../inc/DTNotificacion.h"

DTNotificacion::DTNotificacion(string nicknameVendedor, string nombrePromo, set<DTInfoProducto> productos): nicknameVendedor(nicknameVendedor), nombrePromo(nombrePromo)
{
};
string DTNotificacion:: getnicknameVendedor(){
    return nicknameVendedor;
}
string DTNotificacion:: getnombrePromo(){
    return nombrePromo;
}
string DTNotificacion:: getDTInfoProducto(){
return "aaaa";
}