#include <src/Header_Files/NodoLista.hpp>
#include <src/Header_Files/Proceso.hpp>

NodoLista::NodoLista(Proceso* p, NodoLista* ant, NodoLista* sig)
{
	this->valor = p;
	this->anterior = ant;
	this->siguiente = sig;
}

NodoLista::~NodoLista()
{
	if (valor != nullptr){
			delete valor; //Eliminamos el proceso del programa.
			valor = nullptr; //Evitamos que se quede un puntero colgante.
	}
}
