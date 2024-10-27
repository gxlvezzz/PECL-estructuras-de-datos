#include <src/Header_Files/Gestor.hpp>
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
using namespace std;

	Pila pila;
	Proceso proceso;

void Gestor::genera12Procesos(){
	if(pila.getLongitud()<48){
	for (int i=0; i<12; i++){
	proceso.crearProceso();
	pila.insertar(proceso);
		}		
	}else{
		return;
	}
}

int Gestor::ProcesosEnPila(){
	int procesos_en_pila = pila.getLongitud();
	return procesos_en_pila;
}
Gestor::Gestor(){
		
}

Gestor::~Gestor(){
	
}