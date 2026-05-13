#pragma once
#include <iostream>
#include <string>
#include "persona.h"

class Alumno :
    public Persona
{
public:
    int matricula;

    bool matriculaPar();
};

