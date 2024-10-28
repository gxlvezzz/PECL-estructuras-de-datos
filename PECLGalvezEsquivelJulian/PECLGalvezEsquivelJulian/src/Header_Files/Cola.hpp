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
	void encolarGPU1();
	void encolarGPU2();
	void encolarGPU3();
	void encolarProcesoNormal(Cola& c);
	int getLongitud();
	
private: 
	
	int longitud;
	pnodoCola ultimo;

	
	
	
};
typedef NodoCola* pnodoCola;
#endif