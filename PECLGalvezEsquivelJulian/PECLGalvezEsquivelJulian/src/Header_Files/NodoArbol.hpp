#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
class NodoArbol
{
public:
    NodoArbol(Proceso dato);
    ~NodoArbol();

private:
    Proceso dato; // Aquí se almacenan enteros pero en vuestra práctica se deben almacenar pacientes
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
