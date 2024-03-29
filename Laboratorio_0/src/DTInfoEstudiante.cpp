#include "../inc/DTInfoEstudiante.h"

DTInfoEstudiante::DTInfoEstudiante(int ci, int identificadorInfo, string NombreEst)
{
	this->ci = ci;
	this->identificadorInfo = identificadorInfo;
	this->NombreEst = NombreEst;

	DTInfoEstudiante(int ci, int identificadorInfo, string NombreEst)
		: ci(ci), identificadorInfo(identificadorInfo), NombreEst(NombreEst) {}

	friend ostream &operator<<(ostream &os, const DTInfoEstudiante &estudiante)
	{
		os << estudiante.ci << ", " << estudiante.identificadorInfo << ", " << estudiante.NombreEst;
		return os;
	}
};