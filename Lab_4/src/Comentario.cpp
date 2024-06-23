#include "Comentario.h"

Comentario::Comentario(int id, string comentario, DTFecha fechaDeComentario) \
            : id(id), comentario(comentario), fechaDeComentario(fechaDeComentario) {}

Comentario::~Comentario(){
    for (map<int, Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it){
        delete it->second;
    }
    respuestas.clear();
}

int Comentario::getId() const{
    return id;
}
            
string Comentario::getTexto() const{
    return comentario;
}

string Comentario::getAutor() const{
    return autor;
}

DTFecha Comentario::getFecha() const{
    return fechaDeComentario;
}

Producto* Comentario::getProducto() const{
    return producto;
}

void Comentario::setProducto(Producto* producto){
    this->producto = producto;
}

void Comentario::setAutor(string nickname){
    this->autor = nickname;
}

Comentario* Comentario::getComentarioPadre() const{
    return comentarioPadre;
}

int Comentario::getIdComentarioPadre(){
    return comentarioPadre->getId();
}

void Comentario::setComentarioPadre(Comentario* comentarioPadre) {
    this->comentarioPadre = comentarioPadre;
}
void Comentario::agregarRespuesta(Comentario* comentario){
    respuestas[comentario->getId()] = comentario;
}

map<int, Comentario*>& Comentario::getRespuestas(){
    return respuestas;
}

/* vector<Comentario> Comentario::cargarComentariosDesdeCSV(const string &nombreArchivo){
        std::vector<Comentario> comentarios;
    std::ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
        return comentarios;
    }

    std::string linea;
    std::getline(archivo, linea); // Leer la primera línea que contiene los encabezados

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string ref, refUsuario, refProducto, fecha, texto, refRespuestaA;

        std::getline(ss, ref, ';');
        std::getline(ss, refUsuario, ';');
        std::getline(ss, refProducto, ';');
        std::getline(ss, fecha, ';');
        std::getline(ss, texto, ';');
        std::getline(ss, refRespuestaA, ';');

        // Crear el objeto Comentario
        int id = std::stoi(ref.substr(2)); // Obtener el ID del comentario eliminando el prefijo "CM"
        DTFecha fechaComentario; // Debes implementar la clase DTFecha según tus necesidades
        Comentario comentario(id, texto, fechaComentario);

        // Añadir el comentario a la lista
        comentarios.push_back(comentario);
    }

    archivo.close();
    return comentarios;
    
} */

void Comentario::eliminarRespuesta(int id){
    respuestas.erase(id);
}
