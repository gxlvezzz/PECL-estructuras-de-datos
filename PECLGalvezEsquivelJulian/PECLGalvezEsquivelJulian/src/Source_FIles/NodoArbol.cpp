#include <src/Header_Files/NodoArbol.hpp>
#include <src/Header_Files/Proceso.hpp>

NodoArbol::NodoArbol(Proceso dato)
{
    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}