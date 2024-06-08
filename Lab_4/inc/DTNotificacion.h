#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <iostream>
#include <string>
#include <set>
#include "DTidProducto.h"

using namespace std;
class DTNotificacion{
public:
    string nicknameVendedor, nombrePromo;
    set<DTidProducto> productos;
    DTNotificacion(string nicknameVendedor, string nombrePromo, set<DTidProducto> productos);
};

#endif // DTNOTIFICACION_H
