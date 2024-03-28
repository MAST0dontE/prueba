#include "../inc/PaginaWeb.h"
#include "../inc/DTFecha.h"

PaginaWeb::PaginaWeb(int Identificador,const DTFecha& Fecha, string Titulo, string Link, string Text): Informacion(Identificador, Fecha){
    this->Titulo = Titulo;
    this->Link = Link;
    this->Text = Text;
}

string PaginaWeb::toString(){
    return "PaginaWeb: " + to_string(getIdentificador()) +", "+ getFecha().toString() +", "+ this->Titulo +", "+ this->Link +", "+ this->Text +".";
    
}

string PaginaWeb::getTitulo(){
    return this->Titulo;
}

string PaginaWeb::getLink(){
    return this->Link;
}

string PaginaWeb::getText(){
    return this->Text;
}

PaginaWeb :: ~PaginaWeb(){

}