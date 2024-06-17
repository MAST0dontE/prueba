#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <set>
#include "DTNotificacion.h"
#include "Comentario.h"
using namespace std;
class Usuario {
    protected:
        string contrasenia;
        string nickname;
        DTFecha fechaDeNacimiento;
        set<Comentario *> comentariosUsuario;
        set<DTNotificacion> notificaciones;

    public:
        Usuario(string contrasenia, string nickname, DTFecha fechaDeNacimiento);
        virtual ~Usuario();
        string getNickname();
        string getFecha();
        virtual bool esVendedor() const = 0;
        virtual vector<Comentario> listarComentarios(string) = 0;
        //virtual string tostring() = 0;
};

#endif // USUARIO_H
