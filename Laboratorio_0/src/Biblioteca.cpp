#include "../inc/Biblioteca.h"

Biblioteca :: Biblioteca(){
   // set<Informacion*> infos;
    //this->InformacionesGuardadas = infos;
}

set<Informacion*> getInformacionesGuardadas(){
    return this->InformacionesGuardadas;
}


void Biblioteca :: insertarInformacion(Informacion &Informacion){
    this->InformacionesGuardadas.insert(Informacion);
}

void Biblioteca :: eliminarInformacion(int id){
    auto it = this->informacionesGuardadas.find(id);
    if (it != this->informacionesGuardadas.end()) {
        for(auto it2 = it.getGuardadoPor.begin(); it2 != it.getGuardadoPor.end(); it2++){
		    it.eliminarLinkEstudiante(it2.getCi());
			it2.eliminarLinkInformacion(id);
		}
        this->informacionesGuardadas.erase(it);
    }
}

set<DTInfoEstudiante> Biblioteca ::buscarTermino(string clave){
    set<DTInfoEstudiante> result = set<DTInfoEstudiante>;
    auto it=this->infos.find(clave);
    if(it != this->infos.end()){
        for(const Estudiante est* : this->infos.guardadoPor()){
        DTInfoEstudiante estu = DTInfoEstudiante::DTInfoEstudiante(est->getCedula(), est->getNombre(), infoString->getIdentificador());
        result.insert(estu);
        }
    }
    return result;
}

Biblioteca :: ~Biblioteca(){

}
