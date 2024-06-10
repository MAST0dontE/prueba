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

bool ControladorUsuarios::altaCliente(string username, string password, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad)
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

/* Usuario *ControladorUsuarios::seleccionarUsuario(string username)
{
	// Implementación
	return nullptr;
}
 */
void ControladorUsuarios::seleccionarComentario(DTcomentario *comentario)
{
}

void ControladorUsuarios::setDTComentario(DTcomentario *comentario)
{
	// Implementación
}

void ControladorUsuarios::eliminarComentario(DTcomentario *comentario)
{
	// Implementación
}

set<string> ControladorUsuarios::suscribirseA(string)
{
    return set<string>();
}

set<DTNotificacion> ControladorUsuarios::consultarNotificaciones(string username)
{
	// Implementación
	return set<DTNotificacion>();
}

void ControladorUsuarios::eliminarSuscripciones(string username)
{
	// Implementación
}
