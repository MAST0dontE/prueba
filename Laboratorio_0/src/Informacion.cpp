#include "../inc/Informacion.h"

/* Informacion::Informacion(int id, const DTFecha& fecha){
	this->Identificador = id;
	this->Fecha = DTFecha(fecha.dia, fecha.mes, fecha.anio);
} */
Informacion::Informacion(int id, const DTFecha &fecha) : Fecha(fecha.dia, fecha.mes, fecha.anio)
{
	this->Identificador = id;
}

bool operator<(const Informacion &info) const{
	return Identificador < info.Identificador;
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

void Informacion::guardadoPor(Estudiante est *)
{
	InformacionGuardadaPor.push_back(est);
}

void Informacion::eliminarLinkEstudiante(int ci){
	for (auto it = InformacionGuardada.begin(); it != InformacionGuardada.end(); it++){
		if ((*it)->getCi() == ci){
			InformacionGuardada.erase(it);
			break;
		}
	}
}
