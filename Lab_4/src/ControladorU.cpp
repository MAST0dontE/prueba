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

bool ControladorUsuarios::altaCliente(string username, string password, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad, bool notificaciones)
{
	// Implementación
	return true;
}

bool ControladorUsuarios::altaVendedor(string username, string password, DTFecha fechaNacimiento, string codigoRUT)
{
	// Implementación
	return true;
}

set<string> ControladorUsuarios::listaDeUsuarios()
{
	// Implementación
	return set<string>();
}

Usuario *ControladorUsuarios::seleccionarUsuario(string username)
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

set<DTNotificacion> ControladorUsuarios::consultarNotificaciones()
{
	// Implementación
	return set<DTNotificacion>();
}

void ControladorUsuarios::eliminarSuscripciones(string username)
{
	// Implementación
}
