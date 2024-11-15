#include <src/Header_Files/Gestor.hpp>
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
#include <src/Header_Files/Lista.hpp>
#include <src/Header_Files/Pila.hpp>

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
	Lista lista;
	
	

	
void Gestor::genera12Procesos() {
	    // Generar los valores para cadenaPID
    Proceso procesoAuxiliar;  // Crear una instancia de Proceso para llamar a generarPID
    procesoAuxiliar.generarPID();
	
    for (int i = 0; i < 12; i++) {
		proceso=Proceso();
        proceso.setPID(Proceso::cadenaPID[i]);  // Asignar un PID único del arreglo mezclado
        pila.insertar(proceso);   // Insertar el nuevo proceso en la pila
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
		colaGPU0.ordenarPorPrioridad();
	}else if(colaGPU1.getLongitud() < colaGPU0.getLongitud()){
		colaGPU1.encolar(proceso);
		colaGPU1.ordenarPorPrioridad();	
		}else{
		colaGPU0.encolar(proceso);
		colaGPU0.ordenarPorPrioridad();}
	
	}else{
		
		if(colaGPU2.getLongitud() < colaGPU3.getLongitud()){
		colaGPU2.encolar(proceso);
		colaGPU2.ordenarPorPrioridad();
	}else if(colaGPU3.getLongitud() < colaGPU2.getLongitud()){
		colaGPU3.encolar(proceso);
		colaGPU3.ordenarPorPrioridad();
		}else{
		colaGPU2.encolar(proceso);
		colaGPU2.ordenarPorPrioridad();
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
/*
void Gestor::muestraProcesosNormal() {
    listaNormal.muestraProcesos(); // Llama directamente a la función de Lista
}

void Gestor::muestraProcesosTiempoReal() {
    listaTiempoReal.muestraProcesos(); // Llama directamente a la función de Lista
}
	
void Gestor::buscarProcesos() {
	
    listaNormal.obtenerMayorPrioridad();
    listaTiempoReal.obtenerMenorPrioridad();


    Proceso procesoMenorNormal = listaNormal.obtenerMenorPrioridad();


    cout << "\tNormal menor prioridad -> \t\t";
    string estadoMenorNormal = procesoMenorNormal.getEstado() ? "ejecucion" : "parado";
    string tipoMenorNormal = procesoMenorNormal.getTipo() ? "tiempo real" : "normal";
    cout << "El proceso cuyo PID es " << procesoMenorNormal.getPID()
         << " es de tipo " << tipoMenorNormal
         << ", su estado es " << estadoMenorNormal
         << " y su prioridad es: " << procesoMenorNormal.getPrioridad() << endl;

    Proceso procesoMayorTiempoReal = listaTiempoReal.obtenerMayorPrioridad();

    cout << "\tTiempo real mayor prioridad -> \t\t";
    string estadoMayorTiempoReal = procesoMayorTiempoReal.getEstado() ? "ejecucion" : "parado";
    string tipoMayorTiempoReal = procesoMayorTiempoReal.getTipo() ? "tiempo real" : "normal";
    cout << "El proceso cuyo PID es " << procesoMayorTiempoReal.getPID()
         << " es de tipo " << tipoMayorTiempoReal
         << ", su estado es " << estadoMayorTiempoReal
         << " y su prioridad es: " << procesoMayorTiempoReal.getPrioridad() << endl;
}


void Gestor::buscarProcesoPorNombreUsuario(){
    string o;
    cout << "\tIntroduce un nombre de usuario: ";
    cin >> o;
    cout << "PID\tUsuario\t\tTipo\t\tEstado\t\tPrioridad" << endl;
	
    lista.buscarProcesosUsuario(o);
	
}
void Gestor::eliminarProcesoPorPID() {
	cout << "\tIntroduce un PID: ";
	int pid;
    cin >> pid;
	cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    cout << "---------------------------------------------------" << endl;
	lista.buscarProcesosPID(pid,true);
	if(proceso.getPrioridad()==true){
	listaTiempoReal.extraer(pid);	
	}else{
	listaNormal.extraer(pid);
	}
	Proceso procesoeliminado = lista.extraer(pid);
	pila.insertar(procesoeliminado);
	procesoeliminado.mostrarEnTabla();
	procesoeliminado.mostrar(true);
	
}

void Gestor::cambiarPrioridadProcesoPorPID() {
    cout << "\tIntroduce un PID: ";
    int pid;
    cin >> pid;

    Proceso* procesoEncontrado = lista.buscarProcesosPID(pid, false); 
    if (procesoEncontrado == nullptr) {  
        cout << "No se encontró el proceso con el PID especificado." << endl;
        return;
    }

    cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    procesoEncontrado->mostrarEnTabla();

    bool esTiempoReal = procesoEncontrado->getTipo();

    if (esTiempoReal) {
        listaTiempoReal.extraer(pid);
    } else {
        listaNormal.extraer(pid);
    }

    cout << "\tIntroduce una nueva prioridad: ";
    int nuevaPrioridad;
    cin >> nuevaPrioridad;

    procesoEncontrado->setPrioridad(nuevaPrioridad);

    if (esTiempoReal) {
        listaTiempoReal.enlistar(*procesoEncontrado);  
    } else {
        listaNormal.enlistar(*procesoEncontrado);  
    }
	
	cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    procesoEncontrado->mostrarEnTabla();
}


void Gestor::reiniciar() {
        
        pila.~Pila();
        colaGPU0.~Cola();
		colaGPU1.~Cola();
		colaGPU2.~Cola();
		colaGPU3.~Cola();		
        listaNormal.~Lista();
        listaTiempoReal.~Lista();

        cout << "El programa ha sido reiniciado al estado inicial." << endl;
    }
	
void Gestor::enlistarProcesos(){
	while (cola.getLongitud()!=0){
	proceso = cola.cima();
	lista.enlistar(proceso);
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

*/
Gestor::Gestor(){
		
}

Gestor::~Gestor(){
	
}