#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Comentario.h"
using namespace std;
class Usuario {
    protected:
        string contraseña;
        string nickname;
        DTFecha fecha;

    public:
        Usuario(string contraseña, string nickname, DTFecha fecha);
        virtual ~Usuario();

        virtual vector<Comentario> listarComentarios(string) = 0;
};

#endif // USUARIO_H
