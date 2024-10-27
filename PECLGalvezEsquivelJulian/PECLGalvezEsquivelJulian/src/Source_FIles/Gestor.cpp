#include <src/Header_Files/Gestor.hpp>
#include <iostream>
#include "src/Source_Files/Proceso.cpp"
using namespace std;

	Pila pila;
	Proceso proceso;

void Gestor::genera12Procesos(){
	for (int i=0; i<12; i++){
	proceso.crearProceso();
	pila.insertar(proceso);
	}	
}

int Gestor::ProcesosEnPila(){
	int procesos_en_pila = pila.getLongitud();
	return procesos_en_pila;
}