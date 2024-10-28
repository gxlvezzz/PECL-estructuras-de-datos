#include <src/Header_Files/Gestor.hpp>
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
using namespace std;

	Pila pila;
	Proceso proceso;
	Cola cola;
	Cola colaGPU0;
	Cola colaGPU1;
	Cola colaGPU2;
	Cola colaGPU3;

	
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
	return pila.getLongitud();
}

void Gestor::muestraProcesos(){
	pila.mostrar();
	
	
}
void Gestor::borraProcesosPila(){
	pila.~Pila();
}

void Gestor::encolarProcesos(){
	while (pila.getLongitud()!=0){
	proceso = pila.cima();
	if(proceso.getTipo()==false){
		
		if(colaGPU0.getLongitud() < colaGPU1.getLongitud()){
		colaGPU0.encolar(proceso);
	}else if(colaGPU1.getLongitud() < colaGPU0.getLongitud()){
		colaGPU1.encolar(proceso);	
		}else{
		colaGPU0.encolar(proceso);		}
	
	}else{
		
		if(colaGPU2.getLongitud() < colaGPU2.getLongitud()){
		colaGPU2.encolar(proceso);
	}else if(colaGPU3.getLongitud() < colaGPU2.getLongitud()){
		colaGPU3.encolar(proceso);	
		}else{
		colaGPU2.encolar(proceso);
	}}
	cola.encolar(proceso);
	pila.extraer();
	}
}
	//if(colaGPU0.getLongitud() < colaGPU1.getLongitud()){
	//	cola.encolarProcesoNormal(colaGPU0);
	//}else if(colaGPU1.getLongitud() < colaGPU0.getLongitud()){
	//	cola.encolarProcesoNormal(colaGPU1);
	//}else{
	//	cola.encolarProcesoNormal(colaGPU0);
		
	


int Gestor::ProcesosEnGPU0(){
	return colaGPU0.getLongitud();
}

int Gestor::ProcesosEnGPU1(){
	return colaGPU1.getLongitud();
}

int Gestor::ProcesosEnGPU2(){
	return colaGPU2.getLongitud();
}

int Gestor::ProcesosEnGPU3(){
	return colaGPU3.getLongitud();
}

void Gestor::muestraProcesosGPUs0y1(){
	//cola.mostrarGPU0y1();
}
Gestor::Gestor(){
		
}

Gestor::~Gestor(){
	
}