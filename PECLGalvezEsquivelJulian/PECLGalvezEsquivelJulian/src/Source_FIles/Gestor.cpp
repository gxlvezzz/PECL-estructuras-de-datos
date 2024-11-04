#include <src/Header_Files/Gestor.hpp>
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
#include <src/Header_Files/Lista.hpp>

using namespace std;

	Pila pila;
	Proceso proceso;
	Cola cola;
	Cola colaGPU0;
	Cola colaGPU1;
	Cola colaGPU2;
	Cola colaGPU3;
	Lista listaNormal;
	Lista listaTiempoReal;
	
void Gestor::genera12Procesos(){
	if(pila.getLongitud()<48){
	for (int i=0; i<12; i++){
	proceso.crearProceso();
	pila.insertar(proceso);
		}		
	}else{
		cout << "La pila esta llena." << endl;
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
		
		if(colaGPU2.getLongitud() < colaGPU3.getLongitud()){
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
	cout << "GPU0: " << endl;
	colaGPU0.mostrar();
	cout << "GPU1: " << endl;
	colaGPU1.mostrar();
}

void Gestor::muestraProcesosGPUs2y3(){
	cout << "GPU2: " << endl;
	colaGPU2.mostrar();
	cout << "GPU3: " << endl;
	colaGPU3.mostrar();
}

void Gestor::borraProcesosColas(){
	colaGPU0.~Cola();
	colaGPU1.~Cola();
	colaGPU2.~Cola();
	colaGPU3.~Cola();
}

void Gestor::muestraProcesosNormal() {
    listaNormal.muestraProcesoEnTabla(); // Llama directamente a la función de Lista
}

void Gestor::muestraProcesosTiempoReal() {
    listaTiempoReal.muestraProcesoEnTabla(); // Llama directamente a la función de Lista
}
	
void Gestor::buscarProcesos(){
    cout << "\tNormal menor prioridad -> \t\t";
    Proceso proceso = listaNormal.menorPrioridad();
    
    string estado = "parado";
    if(proceso.getEstado())
        estado = "ejecucion";
        
    string tipo = "normal";
    if(proceso.getTipo())
        tipo = "tiempo real";
    
    cout << "\tEl proceso cuyo PID es "<< proceso.getPID() << " es de tipo " << tipo
    << ", su estado es " << estado << " y su prioridad es: " << proceso.getPrioridad() << endl;
    
    cout << "\tTiempo real mayor prioridad -> \t\t";
    proceso = listaTiempoReal.mayorPrioridad();
    
    estado = "parado";
    if(proceso.getEstado())
        estado = "ejecucion";
        
    tipo = "normal";
    if(proceso.getTipo())
        tipo = "tiempo real";
    
    cout << "\tEl proceso cuyo PID es "<< proceso.getPID() << " es de tipo " << tipo
    << ", su estado es " << estado << " y su prioridad es: " << proceso.getPrioridad() << endl;
 
}

void Gestor::buscarProcesoPorNombreUsuario(){
    string o;
    cout << "\tIntroduce un nombre de usuario: ";
    cin >> o;
    cout << "\tPID\tUsuario\tTipo\tEstado\t\tPrioridad" << endl;
    listaNormal.buscarProcesosUsuario(o);
    listaTiempoReal.buscarProcesosUsuario(o);
}

void Gestor::reiniciar() {
        // Vaciamos las estructuras de datos
        pila.~Pila();
        colaGPU0.~Cola();
		colaGPU1.~Cola();
		colaGPU2.~Cola();
		colaGPU3.~Cola();
		
        listaNormal.vaciar();
        listaTiempoReal.vaciar();

        // Opcional: Reiniciar contadores o variables adicionales

        cout << "El programa ha sido reiniciado al estado inicial." << endl;
    }
	
void Gestor::enlistarProcesos(){
	while (cola.getLongitud()!=0){
	proceso = cola.cima();
	if(proceso.getTipo()==false){
		
		listaNormal.enlistar(proceso);		
	
	}else{
		
		listaTiempoReal.enlistar(proceso);
	}
	cola.extraer();
	}
	colaGPU0.~Cola();
	colaGPU1.~Cola();
	colaGPU2.~Cola();
	colaGPU3.~Cola();
}
	
int Gestor::ProcesosEnListaNormal(){
	return listaNormal.getLongitud();
}

int Gestor::ProcesosEnListaTiempoReal(){
	return listaTiempoReal.getLongitud();
}


Gestor::Gestor(){
		
}

Gestor::~Gestor(){
	
}