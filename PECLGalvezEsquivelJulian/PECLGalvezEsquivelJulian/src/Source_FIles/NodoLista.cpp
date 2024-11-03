#include "src/Header_Files/NodoLista.hpp"
#include <iostream>
#include <iomanip>

using namespace std;


NodoLista::NodoLista(Proceso v, NodoLista* sig)
{
    valor = v;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
}
//NodoLista.cpp
