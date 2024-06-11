#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <iostream>
#include <string>
#include <set>
#include "DTIdProducto.h"

using namespace std;
class DTNotificacion{
public:
    string nicknameVendedor, nombrePromo;
    set<DTIdProducto> productos;
    DTNotificacion(string nicknameVendedor, string nombrePromo, set<DTIdProducto> productos);
};

#endif // DTNOTIFICACION_H
