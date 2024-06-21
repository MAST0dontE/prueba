#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include "DTNotificacion.h"
#include "Comentario.h"
using namespace std;
class Usuario {
    protected:
        string nickname;
        string contrasenia;
        DTFecha fechaDeNacimiento;
        map<int, Comentario*> comentariosUsuario;
        set<DTNotificacion> notificaciones;

    public:
        Usuario(string nickname, string contrasenia, DTFecha fechaDeNacimiento);
        virtual ~Usuario();
        string getNickname();
        string getFecha();
        virtual bool esVendedor() const = 0;
        virtual vector<Comentario> listarComentarios(string) = 0;
        //virtual string tostring() = 0;
};

#endif // USUARIO_H
