#include "../inc/Biblioteca.h"

Biblioteca :: Biblioteca(){
   set<Informacion*> infos;
    this->InformacionesGuardadas = infos;
}

set<Informacion*> Biblioteca :: getInformacionesGuardadas(){
    return this->InformacionesGuardadas;
}


void Biblioteca :: insertarInformacion(Informacion* Informacion){
    this->InformacionesGuardadas.insert(Informacion);
}

void Biblioteca :: eliminarInformacion(int id){
    for(auto it = InformacionesGuardadas.begin(); it != InformacionesGuardadas.end(); it++){
		if((*it)->getIdentificador() == id){
			InformacionesGuardadas.erase(it);
			break;
		}

}

set<DTInfoEstudiante> Biblioteca ::buscarTermino(string clave){
    set<DTInfoEstudiante> result = set<DTInfoEstudiante>;
    auto it=this->infos.find(clave);
    if(it != this->infos.end()){
        for(const Estudiante est* : this->infos.getInformacionGuardadaPor()){
        DTInfoEstudiante estu = DTInfoEstudiante::DTInfoEstudiante(est->getCedula(), est->getNombre(), infoString->getIdentificador());
        result.insert(estu);
        }
    }
    return result;
}

Biblioteca :: ~Biblioteca(){

}
