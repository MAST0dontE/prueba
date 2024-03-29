#include <iostream>
#include <stdlib.h>
#include "../inc/Informacion.h"
#include "../inc/Libro.h"
#include "../inc/DTFecha.h"
#include "../inc/chatGPT.h"
#include "../inc/PaginaWeb.h"
#include "../inc/Estudiante.h"
#include <set>

int main()
{
	// Parte A

	DTFecha fecha1(7, 3, 2024);
	DTFecha fecha2(5, 3, 2024);

	PaginaWeb Informacion1(1, fecha1, "Programación 4 Guía Semana 1 (4/3)", "https://eva.fing.edu.uy/pluginfile.php/468051/mod_resource/content/4/Guia01_P42024_IntroCBasicos.pdf", "El objetivo de esta semana es contextualizar el paradigma de Orientación a Objetos (OO) en el marco de la Ingeniería de Software, así como comenzar a ver sus conceptos básicos y cómo éstos se implementan en C++.");
	PaginaWeb Informacion2(2, fecha2, "Programación orientada a objetos", "https://eva.fing.edu.uy/pluginfile.php/468051/mod_resource/content/4/Guia01_P42024_IntroCBasicos.pdf", "La programación orientada a objetos (POO, en español) es un paradigma de programación que parte del concepto de \"objetos\" como base, los cuales contienen información en forma de campos (a veces también referidos como atributos o propiedades) y código en forma de métodos. Algunas características clave de la programación orientada a objetos son herencia, cohesión, abstracción, polimorfismo, acoplamiento y encapsulamiento.");

	// Fin de parte A

	// Parte B

	DTFecha fecha3(8, 3, 2024);
	DTFecha fecha4(5, 3, 2024);

	chatGPT Informacion3(3, fecha3, "¿Qué es el polimorfismo en orientación a objetos?", "El polimorfismo en programación orientada a objetos se refiere a la capacidad de un objeto de tomar múltiples formas. Puede ser estático, resuelto en tiempo de compilación, basado en la herencia, o dinámico, resuelto en tiempo de ejecución, asociado a interfaces o métodos abstractos. En esencia, permite que objetos de diferentes clases respondan a la misma interfaz de manera coherente, facilitando la flexibilidad y extensibilidad del código.");
	chatGPT Informacion4(4, fecha4, "¿Qué es el acoplamiento en orientación a objetos?", "El acoplamiento en programación orientada a objetos se refiere al grado de dependencia entre las clases o módulos de un sistema. Un bajo acoplamiento es deseable, ya que implica que las clases son independientes entre sí, lo que facilita la modificación, mantenimiento y reutilización del código. Por otro lado, un alto acoplamiento indica una fuerte interdependencia entre las clases, lo que puede hacer que el sistema sea más difícil de entender, modificar y mantener.");

	// Fin parte B

	// Parte C

	set<string> autores = {"Craig Larman"};
	DTFecha fecha5(15, 3, 2024);
	Libro Informacion5(5, fecha5, "Applying UML and Patterns: An Introduction to Object-Oriented Analysis and Design and Iterative Development", autores, "Applying UML and Patterns is the world´s #1 business and college introduction to “thinking in objects”―and using that insight in real-world objectoriented analysis and design. Building on two widely acclaimed previous editions, Craig Larman has updated this book to fully reflect the new UML 2 standard, to help you master the art of object design, and to promote high-impact, iterative, and skillful agile modeling practices.");

	// Fin parte C

	// Parte D

	cout << Informacion1.toString() + "\n"
		 << endl;
	cout << Informacion2.toString() + "\n"
		 << endl;
	cout << Informacion3.toString() + "\n"
		 << endl;
	cout << Informacion4.toString() + "\n"
		 << endl;
	cout << Informacion5.toString() + "\n"
		 << endl;

	// Fin parte D

	// Parte E

	Estudiante estudiante1("Alex García", 52365899, "ag5678@gmail.com");
	Estudiante estudiante2("Betina Gonzalez", 49891239, "beg999@gmail.com");

	// Fin de Parte E

	// Parte F
	estudiante1.guardarInformacion(&Informacion1);
	estudiante1.guardarInformacion(&Informacion2);
	estudiante1.guardarInformacion(&Informacion3);

	estudiante2.guardarInformacion(&Informacion3);
	estudiante2.guardarInformacion(&Informacion4);
	estudiante2.guardarInformacion(&Informacion5);

	estudiante1.eliminarLinkInformacion(Informacion1.getIdentificador());
	/* 	estudiante1.eliminarLinkInformacion(Informacion2.getIdentificador());
		estudiante1.eliminarLinkInformacion(Informacion3.getIdentificador());
	 */
	// Fin Parte F
	// Test commit Cyn
	// Parte G
	set<string> infoStrings = estudiante1.listarInfo(fecha3);
	for (const string &info : infoStrings)
	{
		cout << info << endl;
	}

	set<string> infoStrings2 = estudiante2.listarInfo(fecha3);
	for (const string &info : infoStrings)
	{
		cout << info << endl;
	}
<<<<<<< HEAD
	== == == =
				 estudiante1.eliminarLinkInformacion(Informacion1.getIdentificador());
	estudiante1.eliminarLinkInformacion(Informacion2.getIdentificador());
	estudiante1.eliminarLinkInformacion(Informacion3.getIdentificador());

	/* DTInfoEstudiante Estudiante1(52365899, 1 , 2 , 3 , "Alex García");
	Informacion *Registro1 = Guardado(Informacion1, Informacion2, Informacion3);

	DTInfoEstudiante Estudiante2(49891239 , 3 , 4 , 5 ,"Betina Gonzalez");
	Informacion *Registro2 = Guardado(Informacion3, Informacion4, Informacion5);
	 */
	// Fin Parte F

	// Parte G
>>>>>>> 49a2215941b0df75a83c89feeff9784d6d66c9eb

	// Fin Parte G

	// Parte H

	set<DTInfoEstudiante> public buscarPolimorfismo(const set<Informacion> &informacionSet)
	{
		set<DTInfoEstudiante> result = new set<DTInfoEstudiante>();
		// Recorremos cada objeto Informacion en el conjunto
		for (const Informacion &info : informacionSet)
		{
			string infoString = info.toString();
			// Verificamos si la información contiene el término "polimorfismo"
			if (infoString.find("polimorfismo" != string::npos))
			{
				// Recorremos los estudiantes relacionados con este objeto Informacion (relacionados mediante guardadorPor)
				for (const Estudiante *est : info.guardadoPor())
				{
					// Creamos una instancia de DTInfoEstudiante y la agregamos al conjunto
					DTInfoEstudiante DTInfoEstudiante(est.getCedula(), est.getNombre(), infoString.getIdentificador());
					result.insert(dtInfoEstudiante);
				}
			}
		}
		return result;
	}
	// OBS: se necesitaría un getEstudiantes
	return 0;
}
