#include "../inc/Informacion.h"

/* Informacion::Informacion(int id, const DTFecha& fecha){
	this->Identificador = id;
	this->Fecha = DTFecha(fecha.dia, fecha.mes, fecha.anio);
} */
Informacion::Informacion(int id, const DTFecha &fecha) : Fecha(fecha.dia, fecha.mes, fecha.anio){
	this->Identificador = id;
}

 bool Informacion::operator<(const Informacion& info) const {
	return Identificador < info.Identificador;
 }

int Informacion::getIdentificador(){
	return this->Identificador;
}

DTFecha Informacion::getFecha(){
	return this->Fecha;
}

Informacion :: ~Informacion(){
}

void Informacion::guardadoPor(Estudiante est*){
	InformacionGuardadaPor.push_back(est);
} 

vector<Estudiante*> Informacion::getInformacionGuardadaPor(){
	return InformacionGuardadaPor;
}

void Informacion::eliminarLinkEstudiante(int ci){
	for (auto it = InformacionGuardadaPor.begin(); it != InformacionGuardadaPor.end(); it++){
		if ((*it)->getCi() == ci){
			InformacionGuardadaPor.erase(it);
			break;
		}
	}
}
