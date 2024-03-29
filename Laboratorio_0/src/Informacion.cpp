#include "../inc/Informacion.h"

/* Informacion::Informacion(int id, const DTFecha& fecha){
	this->Identificador = id;
	this->Fecha = DTFecha(fecha.dia, fecha.mes, fecha.anio);
} */
Informacion::Informacion(int id, const DTFecha &fecha) : Fecha(fecha.dia, fecha.mes, fecha.anio)
{
	this->Identificador = id;
}

int Informacion::getIdentificador()
{
	return this->Identificador;
}

DTFecha Informacion::getFecha()
{
	return this->Fecha;
}

Informacion ::~Informacion()
{
}
/* void Informacion::guardadoPor(Estudiante* est){
	InformacionGuardadaPor.push_back(info);
} */