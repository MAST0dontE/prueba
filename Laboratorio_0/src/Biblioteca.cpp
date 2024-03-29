#include "../inc/Biblioteca.h"

Biblioteca :: Biblioteca(){
    std::set<Informacion*> infos;
    this->InformacionesGuardadas = infos;
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
        this->informacionesGuardadas.erase(it);
    }
}

set<DTInfoEstudiante> Biblioteca ::buscarTermino(Biblioteca biblio, string clave){
    set<DTInfoEstudiante> result = set<DTInfoEstudiante>;
    auto it=this->infos.find(clave);
    if(it != this->infos.end()){
        for(const Estudiante est* : biblio->infos.guardadoPor()){
        DTInfoEstudiante estu = DTInfoEstudiante::DTInfoEstudiante(est->getCedula(), est->getNombre(), infoString->getIdentificador());
        result.insert(estu);
        }
    }
    return result;
}

Biblioteca :: ~Biblioteca(){

}
