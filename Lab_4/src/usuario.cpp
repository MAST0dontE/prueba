#include "Usuario.h"

Usuario::Usuario(std::string contrasenia, std::string nickname, DTFecha fechaDeNacimiento)
    : contrasenia(contrasenia), nickname(nickname), fechaDeNacimiento(fechaDeNacimiento) {}

Usuario::~Usuario() {}
