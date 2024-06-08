#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Comentario.h"
using namespace std;
class Usuario {
    protected:
        string contrasenia;
        string nickname;
        DTFecha fechaDeNacimiento;

    public:
        Usuario(string contrasenia, string nickname, DTFecha fechaDeNacimiento);
        virtual ~Usuario();

        virtual vector<Comentario> listarComentarios(string) = 0;
};

#endif // USUARIO_H
