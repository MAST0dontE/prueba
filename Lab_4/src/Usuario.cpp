#include "Usuario.h"

Usuario::Usuario(string contrasenia, string nickname, DTFecha fechaDeNacimiento)
    : contrasenia(contrasenia), nickname(nickname), fechaDeNacimiento(fechaDeNacimiento) {}

Usuario::~Usuario() {}
