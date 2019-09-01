// EstructuraBasicaListaSimple.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lista.h"

int main()
{
	Lista *lista = new Lista();
	lista->InsertarFinal(1, "Andre", 30);
	lista->InsertarFinal(1, "Raul", 28);
	lista->InsertarFinal(2, "Danny", 21);
	lista->InsertarFinal(2, "Raul", 19);
	lista->InsertarFinal(2, "Andre", 28);
	lista->InsertarFinal(5, "Danny", 21);
	lista->InsertarFinal(5, "Daniela", 18);
	//lista->InsertarFinal(4, "Sergio", 31);
	//lista->InsertarFinal(5, "Raul", 19);
	//lista->InsertarFinal(1, "Andre", 30);
	//lista->InsertarFinal(2, "Danny", 21);
	//lista->InsertarFinal(1, "Andre", 30);
	//lista->InsertarFinal(3, "Daniela", 18);
	//lista->InsertarFinal(4, "Sergio", 31);
	//lista->InsertarFinal(4, "Sergio", 31);
	//lista->InsertarFinal(5, "Raul", 19);
	//lista->InsertarFinal(1, "Andre", 30);
	//lista->InsertarFinal(2, "Danny", 21);
	//lista->InsertarFinal(3, "Daniela", 18);
	lista->DesplegarLista();
	lista->RadixSortGeneral();
	lista->DesplegarLista();

    return 0;
}

