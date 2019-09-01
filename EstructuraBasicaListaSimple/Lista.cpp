#include "stdafx.h"
#include "Lista.h"

Lista::Lista()
{
}

Lista::~Lista()
{
}

void Lista::SetCabeza(Nodo *_cabeza) {
	this->cabeza = _cabeza;
}
Nodo *Lista::GetCabeza() {
	return this->cabeza;
}

void Lista::VaciarLista() {
	Nodo *Aux = this->GetCabeza();
	while (Aux != NULL) {
		this->SetCabeza(this->GetCabeza()->GetSiguiente());
		Aux->SetSiguiente(NULL);
		delete(Aux);
		Aux = this->GetCabeza();
	}
}

void Lista::DesplegarLista() {
	Nodo *Aux = this->GetCabeza();
	if (Aux == NULL) {
		cout << "La lista esta vacia." << endl;
	}
	else {
		while (Aux != NULL) {
			cout << Aux->GetPersona()->GetCedula() << " - " << Aux->GetPersona()->GetNombre() << " - " << Aux->GetPersona()->GetEdad() << endl;
			Aux = Aux->GetSiguiente();
		}
	}
	system("pause");
}

Nodo *Lista::GetMenor(Nodo *Menor, Nodo *Ultimo) {
	if (Menor == NULL) {
		Menor = this->GetCabeza();
		Nodo *Aux = this->GetCabeza();
		while (Aux != NULL) {
			if (Aux->GetPersona()->GetCedula() < Menor->GetPersona()->GetCedula()) {
				Menor = Aux;
			}
			Aux = Aux->GetSiguiente();
		}
	}
	else {
		Nodo *Aux = this->GetCabeza();
		while (Aux != NULL) {
			if (Aux->GetPersona()->GetCedula() > Menor->GetPersona()->GetCedula()) {
				Menor = Aux;
				break;
			}
			Aux = Aux->GetSiguiente();
		}
		while (Aux != NULL) {
			if ((Aux->GetPersona()->GetCedula() < Menor->GetPersona()->GetCedula()) && (Aux->GetPersona()->GetCedula() > Ultimo->GetPersona()->GetCedula())) {
				Menor = Aux;
			}
			Aux = Aux->GetSiguiente();
		}
	}
	return Menor;
}

void Lista::DesplegarRepetido(Nodo *Menor) {
	Nodo *Aux = this->GetCabeza();
	while (Aux != NULL) {
		if (Aux->GetPersona()->GetCedula() == Menor->GetPersona()->GetCedula()) {
			cout << Aux->GetPersona()->GetCedula() << " - " << Aux->GetPersona()->GetNombre() << endl;
		}
		Aux = Aux->GetSiguiente();
	}
}

void Lista::DesplegarAscendente() {
	if (this->GetCabeza() != NULL) {
		Nodo *Menor = this->GetMenor(NULL, NULL);
		this->DesplegarRepetido(Menor);                                                                                
		Nodo *Ultimo = Menor;
		while (Menor != NULL) {
			Menor = this->GetMenor(Menor, Ultimo);
			if (Ultimo->GetPersona()->GetCedula() == Menor->GetPersona()->GetCedula()) {
				Menor = NULL;
			}
			else {
				this->DesplegarRepetido(Menor);
				Ultimo = Menor;
			}
		}
		system("pause");
	}
}

void Lista::InsertarFinal(int _cedula, char *_nombre, int _edad) {
	Nodo *Temp = new Nodo(new Persona(_cedula, _nombre, _edad));
	if (this->GetCabeza() == NULL) {
		this->SetCabeza(Temp);
	}
	else {
		Nodo *Aux = this->GetCabeza();
		while (Aux->GetSiguiente() != NULL) {
			Aux = Aux->GetSiguiente();
		}
		Aux->SetSiguiente(Temp);
	}
}

// Proyecto

void Lista::InsertarUltimo(Nodo *nodo) {
	if (this->GetCabeza() == NULL) {
		this->SetCabeza(nodo);
	}
	else {
		Nodo *Aux = this->GetCabeza();
		while (Aux->GetSiguiente() != NULL) {
			Aux = Aux->GetSiguiente();
		}
		Aux->SetSiguiente(nodo);
	}
}

void Lista::InsertarInicio(Nodo *Aux) {
	Aux->SetSiguiente(GetCabeza());
	SetCabeza(Aux);
}

int Lista::Size() {
	int contador = 0;
	Nodo *Aux = GetCabeza();
	while (Aux != NULL){
		contador++;
		Aux = Aux->GetSiguiente();
	}
	return contador;
}

bool Lista::EstaVacia() {
	return this->GetCabeza() == NULL;
}

bool Lista::ListaOrdenadaAscendente() {
	bool bandera = true;
	if (GetCabeza() != NULL) {
		Nodo *Aux = this->GetCabeza();
		while (Aux->GetSiguiente() != NULL)
		{
			//char *nombre = Aux->GetPersona()->GetNombre();
			//char *nombre2 = Aux->GetSiguiente()->GetPersona()->GetNombre();
			//char comp[30];
			//char comp2[30];
			//strcpy_s(comp, nombre);
			//strcpy_s(comp2, nombre2);
			if (/*(strcmp(comp, comp2) <0) && */(Aux->GetPersona()->GetCedula() > Aux->GetSiguiente()->GetPersona()->GetCedula())) {
				bandera = false;
				return bandera;
			}
			Aux = Aux->GetSiguiente();
		}
	}
	return bandera;
}

Nodo *Lista::DesligarCabeza(Nodo *Aux) {
	SetCabeza(Aux->GetSiguiente());
	Aux->SetSiguiente(NULL);
	return Aux;
}

Nodo *Lista::DirAnterior(Nodo *_posicion) {
	if (GetCabeza() == NULL) {
		return NULL;
	}
	else {
		Nodo *Aux = GetCabeza();
		while (Aux->GetSiguiente() != NULL) {
			if (Aux->GetSiguiente()->GetPersona()->GetCedula() == _posicion->GetPersona()->GetCedula()) {
				return Aux;
			}
			else {
				Aux = Aux->GetSiguiente();
			}
		}
		return NULL;
	}
}

Nodo *Lista::DesligarNodo(Nodo *Aux) {
	if (EstaVacia()) {
		return false;
	}
	else if (GetCabeza()->GetPersona()->GetCedula() == Aux->GetPersona()->GetCedula()) {
		Nodo *Aux2 = GetCabeza();
		SetCabeza(Aux2->GetSiguiente());
		Aux2->SetSiguiente(NULL);
		return Aux2;
	}
	else {
		Nodo *anterior = DirAnterior(Aux);
		if (anterior == NULL) {
			return false;
		}
		else {
			Nodo *Aux3 = anterior->GetSiguiente();
			anterior->SetSiguiente(Aux3->GetSiguiente());
			Aux3->SetSiguiente(NULL);
			return Aux3;
		}
	}
}

Nodo *Lista::DirNodo(Nodo *Aux) {
	if (GetCabeza() == NULL) {
		return NULL;
	}
	else {
		Nodo *Aux2 = GetCabeza();
		while (Aux2 != NULL) {
			if (Aux2->GetPersona()->GetCedula() == Aux->GetPersona()->GetCedula()) {
				return Aux2;
			}
			else {
				Aux2 = Aux2->GetSiguiente();
			}
		}
		return NULL;
	}
}

int Lista::DirPosicion(Nodo *Aux) {
	Nodo *Aux2 = GetCabeza();
	int cont = 0;
	for (int i = Aux2->GetPersona()->GetCedula(); i=Aux->GetPersona()->GetCedula(); Aux2 = Aux2->GetSiguiente()) {
		cont++;
	}
	return cont;
}

bool Lista::InsertarDespuesDe(Nodo *Aux, int id) {
	if (GetCabeza() == NULL) {
		return false;
	}
	else {
		Nodo *Aux2 = DirNodo(Aux);
		if (Aux2 == NULL) {
			return false;
		}
		else {
			Aux->SetSiguiente(Aux2->GetSiguiente());
			Aux2->SetSiguiente(Aux);
			return true;
		}
	}
}

void Lista::RadixSort() {
	if (this->GetCabeza() != NULL) {
		int x = 1;
		int y = 1;
		int z = 0;
		int numero = 0;
		Lista *lista0 = new Lista();
		Lista *lista1 = new Lista();
		Lista *lista2 = new Lista();
		Lista *lista3 = new Lista();
		Lista *lista4 = new Lista();
		Lista *lista5 = new Lista();
		Lista *lista6 = new Lista();
		Lista *lista7 = new Lista();
		Lista *lista8 = new Lista();
		Lista *lista9 = new Lista();
		while (!ListaOrdenadaAscendente()) {
			Nodo *Aux = this->GetCabeza();
			x = x * 10;
			z = 0;
			while (Aux != NULL) {
				numero = Aux->GetPersona()->GetCedula();
				z = (numero % x) / y;
				this->DesligarCabeza(Aux);
				switch (z) {
				case 0:
					lista0->InsertarUltimo(Aux);
					break;
				case 1:
					lista1->InsertarUltimo(Aux);
					break;
				case 2:
					lista2->InsertarUltimo(Aux);
					break;
				case 3:
					lista3->InsertarUltimo(Aux);
					break;
				case 4:
					lista4->InsertarUltimo(Aux);
					break;
				case 5:
					lista5->InsertarUltimo(Aux);
					break;
				case 6:
					lista6->InsertarUltimo(Aux);
					break;
				case 7:
					lista7->InsertarUltimo(Aux);
					break;
				case 8:
					lista8->InsertarUltimo(Aux);
					break;
				case 9:
					lista9->InsertarUltimo(Aux);
					break;
				}
				Aux = this->GetCabeza();
			}
			while (lista0->GetCabeza() != NULL) {
				Aux = lista0->GetCabeza();
				lista0->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista1->GetCabeza() != NULL) {
				Aux = lista1->GetCabeza();
				lista1->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista2->GetCabeza() != NULL) {
				Aux = lista2->GetCabeza();
				lista2->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista3->GetCabeza() != NULL) {
				Aux = lista3->GetCabeza();
				lista3->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista4->GetCabeza() != NULL) {
				Aux = lista4->GetCabeza();
				lista4->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista5->GetCabeza() != NULL) {
				Aux = lista5->GetCabeza();
				lista5->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista6->GetCabeza() != NULL) {
				Aux = lista6->GetCabeza();
				lista6->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista7->GetCabeza() != NULL) {
				Aux = lista7->GetCabeza();
				lista7->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista8->GetCabeza() != NULL) {
				Aux = lista8->GetCabeza();
				lista8->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista9->GetCabeza() != NULL) {
				Aux = lista9->GetCabeza();
				lista9->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			y = y * 10;
		}
	}
}

// Prueba

void Lista::RadixSort2() {
	if (this->GetCabeza() != NULL) {
		int x = 1;
		int y = 1;
		int z = 0;
		int numero = 0;
		Lista *lista0 = new Lista();
		Lista *lista1 = new Lista();
		Lista *lista2 = new Lista();
		Lista *lista3 = new Lista();
		Lista *lista4 = new Lista();
		Lista *lista5 = new Lista();
		Lista *lista6 = new Lista();
		Lista *lista7 = new Lista();
		Lista *lista8 = new Lista();
		Lista *lista9 = new Lista();
		while (!ListaOrdenadaAscendente()) {
			Nodo *Aux = this->GetCabeza();
			x = x * 10;
			z = 0;
			while (Aux->GetSiguiente() != NULL) {
				if (Aux->GetPersona()->GetCedula() == Aux->GetSiguiente()->GetPersona()->GetCedula()) {
					numero = Aux->GetPersona()->GetEdad();
					z = (numero % x) / y;
					this->DesligarCabeza(Aux);
					switch (z) {
					case 0:
						lista0->InsertarUltimo(Aux);
						break;
					case 1:
						lista1->InsertarUltimo(Aux);
						break;
					case 2:
						lista2->InsertarUltimo(Aux);
						break;
					case 3:
						lista3->InsertarUltimo(Aux);
						break;
					case 4:
						lista4->InsertarUltimo(Aux);
						break;
					case 5:
						lista5->InsertarUltimo(Aux);
						break;
					case 6:
						lista6->InsertarUltimo(Aux);
						break;
					case 7:
						lista7->InsertarUltimo(Aux);
						break;
					case 8:
						lista8->InsertarUltimo(Aux);
						break;
					case 9:
						lista9->InsertarUltimo(Aux);
						break;
					}
				}
				numero = Aux->GetPersona()->GetCedula();
				z = (numero % x) / y;
				this->DesligarCabeza(Aux);
				switch (z) {
				case 0:
					lista0->InsertarUltimo(Aux);
					break;
				case 1:
					lista1->InsertarUltimo(Aux);
					break;
				case 2:
					lista2->InsertarUltimo(Aux);
					break;
				case 3:
					lista3->InsertarUltimo(Aux);
					break;
				case 4:
					lista4->InsertarUltimo(Aux);
					break;
				case 5:
					lista5->InsertarUltimo(Aux);
					break;
				case 6:
					lista6->InsertarUltimo(Aux);
					break;
				case 7:
					lista7->InsertarUltimo(Aux);
					break;
				case 8:
					lista8->InsertarUltimo(Aux);
					break;
				case 9:
					lista9->InsertarUltimo(Aux);
					break;
				}
				Aux = this->GetCabeza();
			} 
			while (lista0->GetCabeza() != NULL) {
				Aux = lista0->GetCabeza();
				lista0->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista1->GetCabeza() != NULL) {
				Aux = lista1->GetCabeza();
				lista1->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista2->GetCabeza() != NULL) {
				Aux = lista2->GetCabeza();
				lista2->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista3->GetCabeza() != NULL) {
				Aux = lista3->GetCabeza();
				lista3->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista4->GetCabeza() != NULL) {
				Aux = lista4->GetCabeza();
				lista4->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista5->GetCabeza() != NULL) {
				Aux = lista5->GetCabeza();
				lista5->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista6->GetCabeza() != NULL) {
				Aux = lista6->GetCabeza();
				lista6->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista7->GetCabeza() != NULL) {
				Aux = lista7->GetCabeza();
				lista7->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista8->GetCabeza() != NULL) {
				Aux = lista8->GetCabeza();
				lista8->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista9->GetCabeza() != NULL) {
				Aux = lista9->GetCabeza();
				lista9->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			y = y * 10;
		}
	}
}

//Prueba 2

bool Lista::ListaOrdenadaAscendenteCedula() {
	bool bandera = true;
	if (GetCabeza() != NULL) {
		Nodo *Aux = this->GetCabeza();
		while (Aux->GetSiguiente() != NULL)
		{
			//char *nombre = Aux->GetPersona()->GetNombre();
			//char *nombre2 = Aux->GetSiguiente()->GetPersona()->GetNombre();
			//char comp[30];
			//char comp2[30];
			//strcpy_s(comp, nombre);
			//strcpy_s(comp2, nombre2);
			if (/*(strcmp(comp, comp2) <0) && */(Aux->GetPersona()->GetCedula() > Aux->GetSiguiente()->GetPersona()->GetCedula())) {
				bandera = false;
				return bandera;
			}
			Aux = Aux->GetSiguiente();
		}
	}
	return bandera;
}

void Lista::RadixSortCedula() {
	if (this->GetCabeza() != NULL) {
		int x = 1;
		int y = 1;
		int z = 0;
		int numero = 0;
		Lista *lista0 = new Lista();
		Lista *lista1 = new Lista();
		Lista *lista2 = new Lista();
		Lista *lista3 = new Lista();
		Lista *lista4 = new Lista();
		Lista *lista5 = new Lista();
		Lista *lista6 = new Lista();
		Lista *lista7 = new Lista();
		Lista *lista8 = new Lista();
		Lista *lista9 = new Lista();
		while (!ListaOrdenadaAscendenteCedula()) {
			Nodo *Aux = this->GetCabeza();
			x = x * 10;
			z = 0;
			while (Aux != NULL) {
				numero = Aux->GetPersona()->GetCedula();
				z = (numero % x) / y;
				this->DesligarCabeza(Aux);
				switch (z) {
				case 0:
					lista0->InsertarUltimo(Aux);
					break;
				case 1:
					lista1->InsertarUltimo(Aux);
					break;
				case 2:
					lista2->InsertarUltimo(Aux);
					break;
				case 3:
					lista3->InsertarUltimo(Aux);
					break;
				case 4:
					lista4->InsertarUltimo(Aux);
					break;
				case 5:
					lista5->InsertarUltimo(Aux);
					break;
				case 6:
					lista6->InsertarUltimo(Aux);
					break;
				case 7:
					lista7->InsertarUltimo(Aux);
					break;
				case 8:
					lista8->InsertarUltimo(Aux);
					break;
				case 9:
					lista9->InsertarUltimo(Aux);
					break;
				}
				Aux = this->GetCabeza();
			}
			while (lista0->GetCabeza() != NULL) {
				Aux = lista0->GetCabeza();
				lista0->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista1->GetCabeza() != NULL) {
				Aux = lista1->GetCabeza();
				lista1->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista2->GetCabeza() != NULL) {
				Aux = lista2->GetCabeza();
				lista2->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista3->GetCabeza() != NULL) {
				Aux = lista3->GetCabeza();
				lista3->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista4->GetCabeza() != NULL) {
				Aux = lista4->GetCabeza();
				lista4->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista5->GetCabeza() != NULL) {
				Aux = lista5->GetCabeza();
				lista5->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista6->GetCabeza() != NULL) {
				Aux = lista6->GetCabeza();
				lista6->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista7->GetCabeza() != NULL) {
				Aux = lista7->GetCabeza();
				lista7->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista8->GetCabeza() != NULL) {
				Aux = lista8->GetCabeza();
				lista8->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista9->GetCabeza() != NULL) {
				Aux = lista9->GetCabeza();
				lista9->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			y = y * 10;
		}
	}
}

bool Lista::ListaOrdenadaAscendenteEdad() {
	bool bandera = true;
	if (GetCabeza() != NULL) {
		Nodo *Aux = this->GetCabeza();
		while (Aux->GetSiguiente() != NULL)
		{
			//char *nombre = Aux->GetPersona()->GetNombre();
			//char *nombre2 = Aux->GetSiguiente()->GetPersona()->GetNombre();
			//char comp[30];
			//char comp2[30];
			//strcpy_s(comp, nombre);
			//strcpy_s(comp2, nombre2);
			if (/*(strcmp(comp, comp2) <0) && */(Aux->GetPersona()->GetEdad() > Aux->GetSiguiente()->GetPersona()->GetEdad())) {
				bandera = false;
				return bandera;
			}
			Aux = Aux->GetSiguiente();
		}
	}
	return bandera;
}

void Lista::RadixSortEdad() {
	if (this->GetCabeza() != NULL) {
		int x = 1;
		int y = 1;
		int z = 0;
		int numero = 0;
		Lista *lista0 = new Lista();
		Lista *lista1 = new Lista();
		Lista *lista2 = new Lista();
		Lista *lista3 = new Lista();
		Lista *lista4 = new Lista();
		Lista *lista5 = new Lista();
		Lista *lista6 = new Lista();
		Lista *lista7 = new Lista();
		Lista *lista8 = new Lista();
		Lista *lista9 = new Lista();
		while (!ListaOrdenadaAscendenteEdad()) {
			Nodo *Aux = this->GetCabeza();
			x = x * 10;
			z = 0;
			while (Aux != NULL) {
				numero = Aux->GetPersona()->GetEdad();
				z = (numero % x) / y;
				this->DesligarCabeza(Aux);
				switch (z) {
				case 0:
					lista0->InsertarUltimo(Aux);
					break;
				case 1:
					lista1->InsertarUltimo(Aux);
					break;
				case 2:
					lista2->InsertarUltimo(Aux);
					break;
				case 3:
					lista3->InsertarUltimo(Aux);
					break;
				case 4:
					lista4->InsertarUltimo(Aux);
					break;
				case 5:
					lista5->InsertarUltimo(Aux);
					break;
				case 6:
					lista6->InsertarUltimo(Aux);
					break;
				case 7:
					lista7->InsertarUltimo(Aux);
					break;
				case 8:
					lista8->InsertarUltimo(Aux);
					break;
				case 9:
					lista9->InsertarUltimo(Aux);
					break;
				}
				Aux = this->GetCabeza();
			}
			while (lista0->GetCabeza() != NULL) {
				Aux = lista0->GetCabeza();
				lista0->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista1->GetCabeza() != NULL) {
				Aux = lista1->GetCabeza();
				lista1->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista2->GetCabeza() != NULL) {
				Aux = lista2->GetCabeza();
				lista2->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista3->GetCabeza() != NULL) {
				Aux = lista3->GetCabeza();
				lista3->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista4->GetCabeza() != NULL) {
				Aux = lista4->GetCabeza();
				lista4->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista5->GetCabeza() != NULL) {
				Aux = lista5->GetCabeza();
				lista5->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista6->GetCabeza() != NULL) {
				Aux = lista6->GetCabeza();
				lista6->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista7->GetCabeza() != NULL) {
				Aux = lista7->GetCabeza();
				lista7->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista8->GetCabeza() != NULL) {
				Aux = lista8->GetCabeza();
				lista8->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			while (lista9->GetCabeza() != NULL) {
				Aux = lista9->GetCabeza();
				lista9->DesligarCabeza(Aux);
				this->InsertarUltimo(Aux);
			}
			y = y * 10;
		}
	}
}

void Lista::RadixSortGeneral() {
	int x = 1;
	int y = 1;
	int z = 0;
	int numero = 0;
	Lista *lista0 = new Lista();
	Lista *lista1 = new Lista();
	Lista *lista2 = new Lista();
	Lista *lista3 = new Lista();
	Lista *lista4 = new Lista();
	Lista *lista5 = new Lista();
	Lista *lista6 = new Lista();
	Lista *lista7 = new Lista();
	Lista *lista8 = new Lista();
	Lista *lista9 = new Lista();
	RadixSortCedula();
	Nodo *Aux = this->GetCabeza();
	while (Aux != NULL && Aux->GetSiguiente() != NULL) {
		Nodo *Aux2 = Aux;
		while (Aux2->GetSiguiente() != NULL) {
			if (Aux->GetPersona()->GetCedula() == Aux2->GetSiguiente()->GetPersona()->GetCedula()) {
				Nodo *Aux3 = this->GetCabeza();
				x = x * 10;
				z = 0;
				while (Aux3 != NULL) {
					numero = Aux3->GetPersona()->GetEdad();
					z = (numero % x) / y;
					Nodo *Aux4 = DirAnterior(Aux3);
					this->DesligarNodo(Aux3);
					switch (z) {
					case 0:
						lista0->InsertarUltimo(Aux3);
						break;
					case 1:
						lista1->InsertarUltimo(Aux3);
						break;
					case 2:
						lista2->InsertarUltimo(Aux3);
						break;
					case 3:
						lista3->InsertarUltimo(Aux3);
						break;
					case 4:
						lista4->InsertarUltimo(Aux3);
						break;
					case 5:
						lista5->InsertarUltimo(Aux3);
						break;
					case 6:
						lista6->InsertarUltimo(Aux3);
						break;
					case 7:
						lista7->InsertarUltimo(Aux3);
						break;
					case 8:
						lista8->InsertarUltimo(Aux3);
						break;
					case 9:
						lista9->InsertarUltimo(Aux3);
						break;
					}
					Aux3 = this->GetCabeza();
				}
				while (lista0->GetCabeza() != NULL) {
					Aux3 = lista0->GetCabeza();
					lista0->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista1->GetCabeza() != NULL) {
					Aux3 = lista1->GetCabeza();
					lista1->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista2->GetCabeza() != NULL) {
					Aux3 = lista2->GetCabeza();
					lista2->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista3->GetCabeza() != NULL) {
					Aux3 = lista3->GetCabeza();
					lista3->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista4->GetCabeza() != NULL) {
					Aux3 = lista4->GetCabeza();
					lista4->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista5->GetCabeza() != NULL) {
					Aux = lista5->GetCabeza();
					lista5->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista6->GetCabeza() != NULL) {
					Aux3 = lista6->GetCabeza();
					lista6->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista7->GetCabeza() != NULL) {
					Aux3 = lista7->GetCabeza();
					lista7->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista8->GetCabeza() != NULL) {
					Aux3 = lista7->GetCabeza();
					lista7->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				while (lista9->GetCabeza() != NULL) {
					Aux3 = lista9->GetCabeza();
					lista9->DesligarCabeza(Aux3);
					this->InsertarDespuesDe(Aux3, Aux4->GetPersona()->GetCedula());
				}
				y = y * 10;
			}
			else {
				Aux2 = Aux2->GetSiguiente();
			}
		}
		Aux = Aux->GetSiguiente();
	}
}