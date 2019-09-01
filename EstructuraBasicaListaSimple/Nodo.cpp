#include "stdafx.h"
#include "Nodo.h"


Nodo::Nodo()
{
}


Nodo::~Nodo()
{
}

Nodo::Nodo(Persona *_persona) {
	this->SetPersona(_persona);
}

void Nodo::SetPersona(Persona *_persona) {
	this->persona = _persona;
}
Persona *Nodo::GetPersona() {
	return this->persona;
}

void Nodo::SetSiguiente(Nodo *_siguiente) {
	this->siguiente = _siguiente;
}
Nodo *Nodo::GetSiguiente() {
	return this->siguiente;
}