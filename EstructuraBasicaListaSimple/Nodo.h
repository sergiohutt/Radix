#pragma once
#include "Persona.h"
class Nodo
{
private:
	Persona *persona;
	Nodo *siguiente;

public:
	Nodo();
	~Nodo();

	Nodo(Persona *);

	void SetPersona(Persona *);
	Persona *GetPersona();

	void SetSiguiente(Nodo *);
	Nodo *GetSiguiente();
};

