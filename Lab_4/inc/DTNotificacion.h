#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <iostream>
#include <string>
#include <set>
#include "DTInfoProducto.h"

using namespace std;
class DTNotificacion{
public:
    string nicknameVendedor, nombrePromo;
    set<DTInfoProducto> productos;
    DTNotificacion(string nicknameVendedor, string nombrePromo, set<DTInfoProducto> productos);
    string getNicknameVendedor();
    string getNombrePromo();
    string getDTInfoProducto();
};

#endif // DTNOTIFICACION_H
