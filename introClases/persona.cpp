#include "persona.h"

bool Persona::adulto() { 
	if (edad_ > 17) return true;
	else return false;
}
