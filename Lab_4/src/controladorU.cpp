#include "ControladorUsuarios.h"

void ControladorUsuarios::setCliente(Cliente *cliente)
{
	// Implementación
}

void ControladorUsuarios::setVendedor(Vendedor *vendedor)
{
	// Implementación
}

void ControladorUsuarios::setComentario(Comentario *comentario)
{
	// Implementación
}

bool ControladorUsuarios::altaCliente(std::string username, std::string password, DTFecha fechaNacimiento, DTDireccion direccion, std::string ciudad, bool notificaciones)
{
	// Implementación
	return true;
}

bool ControladorUsuarios::altaVendedor(std::string username, std::string password, DTFecha fechaNacimiento, std::string codigoRUT)
{
	// Implementación
	return true;
}

std::set<std::string> ControladorUsuarios::listaDeUsuarios()
{
	// Implementación
	return std::set<std::string>();
}

Usuario *ControladorUsuarios::seleccionarUsuario(std::string username)
{
	// Implementación
	return nullptr;
}

void ControladorUsuarios::setDTComentario(DTComentario *comentario)
{
	// Implementación
}

void ControladorUsuarios::eliminarComentario(DTComentario *comentario)
{
	// Implementación
}

std::set<DTNotificacion> ControladorUsuarios::consultarNotificaciones()
{
	// Implementación
	return std::set<DTNotificacion>();
}

void ControladorUsuarios::eliminarSuscripciones(std::string username)
{
	// Implementación
}
