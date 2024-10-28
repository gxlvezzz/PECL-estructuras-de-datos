#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
using namespace std;

class NodoCola{
public:
	NodoCola(Proceso v, NodoCola* sig = NULL);
	~NodoCola();
	
private: 
	Proceso valor;
	NodoCola* siguiente;
	friend class Cola;
};

typedef NodoCola* pnodoCola;
#endif