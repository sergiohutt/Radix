#pragma once
class Persona
{
private:
	int cedula;
	char nombre[20];
	int edad;
public:
	Persona();
	~Persona();

	Persona(int, char *, int);

	void SetCedula(int);
	int GetCedula();

	void SetNombre(char *);
	char *GetNombre();

	void SetEdad(int);
	int GetEdad();
};

