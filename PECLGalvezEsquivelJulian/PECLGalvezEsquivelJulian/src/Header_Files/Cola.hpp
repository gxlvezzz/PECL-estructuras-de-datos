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
	void encolar(Proceso v);
	void encolarProcesoNormal(Cola& c);
	int getLongitud();
	void mostrar();
	
private: 
	
	int longitud;
	pnodoCola ultimo;

	
	
	
};
typedef NodoCola* pnodoCola;
#endif