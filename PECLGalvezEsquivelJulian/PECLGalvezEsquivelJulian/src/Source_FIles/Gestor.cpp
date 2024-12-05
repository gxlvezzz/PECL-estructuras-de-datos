#include <src/Header_Files/Gestor.hpp>
#include <iostream>
#include <src/Header_Files/Proceso.hpp>
#include <src/Header_Files/Lista.hpp>
#include <src/Header_Files/Pila.hpp>
#include <src/Header_Files/Arbol.hpp>

using namespace std;

	Pila pila;
	Pila pilaNormal;
	Pila pilaTiempoReal;
	Proceso proceso;
	Cola cola;
	Cola colaGPU0;
	Cola colaGPU1;
	Cola colaGPU2;
	Cola colaGPU3;
	Lista listaNormal;
	Lista listaTiempoReal;
	Lista lista;
	Arbol arbol;
	int indiceNormal = 0;
	int indiceTiempoReal = 0;
	Proceso procesoAuxiliar;

	
	
	

	
void Gestor::genera12Procesos() {
    // Generar datos estáticos
    Proceso procesoAuxiliar;
    procesoAuxiliar.generarPID();
	
    // Iterar para generar procesos
    for (int i = 0; i < 12; i++) {
        Proceso proceso; // Crear un nuevo proceso
        proceso.setPID(Proceso::cadenaPID[i]); // Asignar un PID único
		
        // Insertar proceso en la pila
        pila.insertar(proceso);
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

void Gestor::encolarProcesos() {
	int indiceNormal = 0;
	int indiceTiempoReal = 0;
	Proceso procesoAuxiliar;
	procesoAuxiliar.generarPrioridadNormal();
	procesoAuxiliar.generarPrioridadTiempoReal();
	
    while (pila.getLongitud() != 0) {
        // Obtener el proceso de la pila
        proceso = pila.cima();
        // Verificar el tipo del proceso
        if (proceso.getTipo() == false) { // Proceso normal
			proceso.setPrioridad(Proceso::cadenaPrioridadNormal[indiceNormal]);
			indiceNormal++;
            // Insertar en la cola GPU correspondiente con menor longitud
            if (colaGPU0.getLongitud() <= colaGPU1.getLongitud()) {
                colaGPU0.insertar(proceso);
            } else {
                colaGPU1.insertar(proceso);
            }
        } else { // Proceso tiempo real
			proceso.setPrioridad(Proceso::cadenaPrioridadTiempoReal[indiceTiempoReal]);
			indiceTiempoReal++;
            // Insertar en la cola GPU correspondiente con menor longitud
            if (colaGPU2.getLongitud() <= colaGPU3.getLongitud()) {
                colaGPU2.insertar(proceso);
            } else {
                colaGPU3.insertar(proceso);
            }
        }
        // Insertar en la cola principal
        cola.insertar(proceso);
        // Extraer el proceso de la pila
        pila.extraer();
    }
    // Ordenar las colas después de insertar todos los procesos
    colaGPU0.ordenarPorPrioridad();
    colaGPU1.ordenarPorPrioridad();
    colaGPU2.ordenarPorPrioridad();
    colaGPU3.ordenarPorPrioridad();
    cola.ordenarPorPrioridad();
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
int Gestor::ProcesosEnArbol() {
    return arbol.contarNodos();
}
void Gestor::crearYdibujarABB() {

    // Inserta los procesos de la pila en el árbol
    while (pila.getLongitud() != 0) {
        // Obtener el proceso de la pila
        Proceso proceso = pila.cima();
		
		if (proceso.getTipo() == false) { // Proceso normal
			proceso.setPrioridad(Proceso::cadenaPrioridadNormal[indiceNormal]);
			indiceNormal++;
		} else { // Proceso tiempo real
			proceso.setPrioridad(Proceso::cadenaPrioridadTiempoReal[indiceTiempoReal]);
			indiceTiempoReal++;
		}
        
        // Insertar en el árbol usando la prioridad del proceso como valor entero
        arbol.insertar(proceso.getPrioridad()); // Cambia esto a getPID() si lo prefieres
        
        // Extraer el proceso de la pila después de insertarlo en el árbol
        pila.extraer();
    }

    // Dibujar el árbol después de la inserción
    arbol.dibujar();
}

void Gestor::mostrarProcesosEnArbol() {
    arbol.mostrarProcesosEnInorden();
}


Gestor::Gestor(){
		
}

Gestor::~Gestor(){
	
}