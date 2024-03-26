#include "../inc/Estudiante.h"

Estudiante::Estudiante(string nombre, int ci, string email){
	this->ci = ci;
	this->nombre = nombre;
	this->email = email;
}

string Estudiante::getNombre(){
	return this->nombre;
}

void Estudiante::setNombre(string nombre){
	this->nombre = nombre;
}

int Estudiante::getCi(){
	return this->ci;
}

void Estudiante::setCi(int ci){
	this->ci = ci;
}

string Estudiante::getEmail(){
	return this->email;
}

void Estudiante::setEmail(string email){
	this->email = email;
}

string Estudiante::toString(){
	return "Nombre: " + nombre + ", CI: " + to_string(ci) + ", Email: " + email;
}

string Estudiante::listarInfo(DTFecha& Desde, Informacion* Estudiante.Guardado);{
	//DesdeFecha
int i=0;
	if (DesdeFecha(Informacion[i].getFecha,Desde))>1
	{
		return Informacion[i].toString()
		i=i+1;
	}
}



Informacion** Estudiante::Guardado(Informacion *info1, Informacion *info2, Informacion *info3);{
	Arr[0]=info1;
	Arr[1]=info2;
	Arr[2]=info3;
return Arr;
}
