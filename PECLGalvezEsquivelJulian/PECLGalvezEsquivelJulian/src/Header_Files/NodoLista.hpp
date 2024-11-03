#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
using namespace std;

class NodoLista{
public:
	NodoLista(Proceso v, NodoLista* sig = NULL);
	~NodoLista();
	
private: 
	Proceso valor;
	NodoLista* siguiente;
	friend class Lista;
};

typedef NodoLista* pnodoLista;
#endif