#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "Comentario.h"

class Usuario {
    protected:
        std::string contrasenia;
        std::string nickname;
        DTFecha fechaDeNacimiento;

    public:
        Usuario(std::string contrasenia, std::string nickname, DTFecha fechaDeNacimiento);
        virtual ~Usuario();

        virtual std::vector<Comentario> listarComentarios(std::string) = 0;
};

#endif // USUARIO_H
