#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo *cabeza;

	void SetCabeza(Nodo *);
	Nodo *GetCabeza();

	Nodo *GetMenor(Nodo *, Nodo *);
	void DesplegarRepetido(Nodo *);

public:
	Lista();
	~Lista();
	
	void VaciarLista();
	void InsertarFinal(int, char*, int);

	void DesplegarLista();
	void DesplegarAscendente();

	// Proyecto

	void InsertarUltimo(Nodo *);
	void InsertarInicio(Nodo *Aux);
	int Size();
	bool EstaVacia();
	bool ListaOrdenadaAscendente();
	Nodo *DesligarCabeza(Nodo *);
	Nodo *DirAnterior(Nodo *);
	Nodo *DesligarNodo(Nodo *);
	int DirPosicion(Nodo *);
	Nodo *DirNodo(Nodo *);
	bool InsertarDespuesDe(Nodo *, int);
	void RadixSort();
	
	//Prueba
	
	void RadixSort2();

	//Prueba 2

	bool ListaOrdenadaAscendenteCedula();
	void RadixSortCedula();
	bool ListaOrdenadaAscendenteEdad();
	void RadixSortEdad();
	void RadixSortGeneral();
};

