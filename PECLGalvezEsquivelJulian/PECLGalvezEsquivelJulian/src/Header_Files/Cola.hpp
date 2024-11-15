#ifndef COLA_HPP
#define COLA_HPP

#include <iostream>
#include <src/Header_Files/NodoCola.hpp>
#include <src/Header_Files/Proceso.hpp>
using namespace std;

class Cola{
public:
	Cola();
	~Cola();
	void insertar(Proceso v);
	int getLongitud();
	void mostrar();
	void vaciar();
	Proceso eliminar();
	Proceso verPrimero();
	void ordenarPorPrioridad();
	
private: 
	
	int longitud;
	pnodoCola primero, ultimo;

	
	
	
};
typedef NodoCola* pnodoCola;
#endif