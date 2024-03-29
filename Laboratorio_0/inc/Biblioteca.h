#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <set>
#include "Informacion.h"
using namespace std;

class Biblioteca{
    private:
    set<Informacion*> InformacionesGuardadas;
    
    public: 
    Biblioteca();
    set<Informacion*> getInformacionesGuardadas();
    void insertarInformacion();
    void eliminarInformacion();
    set<DTInfoEstudiante> buscarTermino(Biblioteca Biblioteca);
    ~Biblioteca();
}
#endif
