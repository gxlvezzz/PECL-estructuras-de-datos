#include <src/Header_Files/Gestor.hpp>
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
#include <src/Header_Files/Lista.hpp>
#include <src/Header_Files/Pila.hpp>
#include <src/Header_Files/Arbol.hpp>

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
    Proceso procesoAuxiliar;  
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
	Proceso procesoAuxiliar;
	procesoAuxiliar.generarPrioridadNormal();
	procesoAuxiliar.generarPrioridadTiempoReal();
	int prioridadNormal=0;
	int prioridadTiempoReal=0;
	int indice = 0;

	while (pila.getLongitud()!=0){
	proceso = pila.cima();

	if(proceso.getTipo()==false){
		indice = Proceso::cadenaPrioridadNormal[prioridadNormal];
		proceso.setPrioridad(indice);
		prioridadNormal++;
		if(colaGPU0.getLongitud() <= colaGPU1.getLongitud()){
		colaGPU0.insertar(proceso);
		colaGPU0.ordenarPorPrioridad();
	}else if(colaGPU1.getLongitud() < colaGPU0.getLongitud()){
		colaGPU1.insertar(proceso);
		colaGPU1.ordenarPorPrioridad();	
		}
	
	}else{
		indice = Proceso::cadenaPrioridadTiempoReal[prioridadTiempoReal];
		proceso.setPrioridad(indice);
		prioridadTiempoReal++;
		if(colaGPU2.getLongitud() <= colaGPU3.getLongitud()){
		colaGPU2.insertar(proceso);
		colaGPU2.ordenarPorPrioridad();
	}else if(colaGPU3.getLongitud() < colaGPU2.getLongitud()){
		colaGPU3.insertar(proceso);
		colaGPU3.ordenarPorPrioridad();
		}}
	cola.insertar(proceso);
	cola.ordenarPorPrioridad();	
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
    listaNormal.muestraProcesos(); // Llama directamente a la función de Lista
}

void Gestor::muestraProcesosTiempoReal() {
    listaTiempoReal.muestraProcesos(); // Llama directamente a la función de Lista
}
	
void Gestor::buscarProcesos() {
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
    cout << "-----------------------------------------------------------------" << endl;
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
	procesoeliminado.mostrar(true);
	
}

void Gestor::cambiarPrioridadProcesoPorPID() {
    cout << "\tIntroduce un PID: ";
    int pid;
    cin >> pid;

    // Buscar el proceso en la lista principal
    Proceso* procesoEncontrado = lista.buscarProcesosPID(pid, false);
    if (procesoEncontrado == nullptr) {
        cout << "No se encontró el proceso con el PID especificado." << endl;
        return;
    }

    // Mostrar la información actual del proceso
    cout << "PID\tUsuario\t\tTipo\t\tEstado\t\tPrioridad" << endl;
    procesoEncontrado->mostrarEnTabla();

    // Solicitar nueva prioridad
    cout << "\tIntroduce una nueva prioridad: ";
    int nuevaPrioridad;
    cin >> nuevaPrioridad;

    // Determinar el tipo de proceso (Normal o Tiempo Real)
    bool esTiempoReal = procesoEncontrado->getTipo();

    // Eliminar el proceso de las listas específicas
    if (esTiempoReal) {
        listaTiempoReal.extraer(pid);
    } else {
        listaNormal.extraer(pid);
    }
    // Eliminar el proceso de la lista general
    lista.extraer(pid);

    // Actualizar la prioridad del proceso
    procesoEncontrado->setPrioridad(nuevaPrioridad);

    // Insertar nuevamente el proceso en las listas correspondientes
    if (esTiempoReal) {
        listaTiempoReal.insertarOrdenado(*procesoEncontrado);
    } else {
        listaNormal.insertarOrdenado(*procesoEncontrado);
    }
    lista.insertarOrdenado(*procesoEncontrado);

    // Mostrar información actualizada
    cout << "PID\tUsuario\t\tTipo\t\tEstado\t\tPrioridad (Actualizada)" << endl;
    procesoEncontrado->mostrarEnTabla();
}

void Gestor::mostrarProcesosNormalesPrioridadMayor() {
	 listaNormal.ordenarListaProcesosPrioridadMayor();
}

void Gestor::mostrarProcesosTiempoRealPrioridadMayor() {
     listaTiempoReal.ordenarListaProcesosPrioridadMayor();
    
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
	
void Gestor::enlistarProcesos() {
    while (colaGPU2.getLongitud() > 0 || colaGPU3.getLongitud() > 0) {
        if (colaGPU2.getLongitud() > 0 && 
            (colaGPU3.getLongitud() == 0 || colaGPU2.verPrimero().getPrioridad() <= colaGPU3.verPrimero().getPrioridad())) {
            // Extraer el proceso con menor prioridad de GPU2
            Proceso procesoGPU2 = colaGPU2.verPrimero();
            colaGPU2.eliminar();
            lista.enlistar(procesoGPU2);
            listaTiempoReal.enlistar(procesoGPU2);
        } else if (colaGPU3.getLongitud() > 0) {
            // Extraer el proceso con menor prioridad de GPU3
            Proceso procesoGPU3 = colaGPU3.verPrimero();
            colaGPU3.eliminar();
            lista.enlistar(procesoGPU3);
            listaTiempoReal.enlistar(procesoGPU3);
        }
    }
	
	 while (colaGPU0.getLongitud() > 0 || colaGPU1.getLongitud() > 0) {
        if (colaGPU0.getLongitud() > 0 && 
            (colaGPU1.getLongitud() == 0 || colaGPU0.verPrimero().getPrioridad() <= colaGPU1.verPrimero().getPrioridad())) {
            // Extraer el proceso con menor prioridad de GPU0
            Proceso procesoGPU0 = colaGPU0.verPrimero();
            colaGPU0.eliminar();
            lista.enlistar(procesoGPU0);
            listaNormal.enlistar(procesoGPU0);
        } else if (colaGPU1.getLongitud() > 0) {
            // Extraer el proceso con menor prioridad de GPU1
            Proceso procesoGPU1 = colaGPU1.verPrimero();
            colaGPU1.eliminar();
            lista.enlistar(procesoGPU1);
            listaNormal.enlistar(procesoGPU1);
        }
    }
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