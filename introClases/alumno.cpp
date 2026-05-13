#include "alumno.h"
#include "persona.h"

bool Alumno::matriculaPar() {
	if (matricula % 2 == 0) return true;
	else return false;
}
