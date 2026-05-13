#include <iostream>
#include "persona.h"
#include "alumno.h"

int main() {
	Alumno miAlumno;

	miAlumno.edad_ = 18;
	miAlumno.nombre_ = { "Paco" };
	miAlumno.matricula = 57122;

	if (miAlumno.adulto()) std::cout << "El alumno es mayor de edad" << std::endl;
	if (miAlumno.matriculaPar()) std::cout << "Su matricula es par";

	return 0;



}