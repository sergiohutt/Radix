#include "stdafx.h"
#include "Persona.h"


Persona::Persona()
{
}


Persona::~Persona()
{
}

Persona::Persona(int _cedula, char *_nombre, int _edad) {
	this->SetCedula(_cedula);
	this->SetNombre(_nombre);
	this->SetEdad(_edad);
}

void Persona::SetCedula(int _cedula) {
	this->cedula = _cedula;
}

int Persona::GetCedula() {
	return this->cedula;
}

void Persona::SetNombre(char *_nombre) {
	strcpy_s(this->nombre, _nombre);
}
char *Persona::GetNombre() {
	return this->nombre;
}

void Persona::SetEdad(int _edad) {
	this->edad = _edad;
}

int Persona::GetEdad() {
	return this->edad;
}