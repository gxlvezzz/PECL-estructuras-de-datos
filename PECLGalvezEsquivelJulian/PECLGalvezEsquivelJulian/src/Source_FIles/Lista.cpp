#include "src/Header_Files/Lista.hpp"
#include "src/Header_Files/Proceso.hpp"
#include <iostream>
using namespace std;

// Constructor
Lista::Lista() {
    longitud=0;
	ultimo=NULL;
}


// Método para mostrar los procesos normales en formato tabla
void Lista::muestraProcesosNormal()  {
   if (longitud < 1) {
        cout << "No hay procesos en la lista normal." << endl;
        return;
    }

    cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    cout << "---------------------------------------------------" << endl; // Línea de separación

    pnodoLista actual = primero;
    while (actual != nullptr) {
        Proceso& proceso = actual->valor; // Acceder al proceso del nodo

        // Construir la línea de salida sin usar setw
        string tipo = proceso.esTiempoReal() ? "Tiempo Real" : "Normal";
        string estado = proceso.estaEnEjecucion() ? "En Ejecución" : "Parado";

        cout << proceso.getPID() << "\t" 
             << proceso.getUsuario() << "\t" 
             << tipo << "\t" 
             << estado << "\t" 
             << proceso.getPrioridad() << endl;

        actual = actual->siguiente; // Mover al siguiente nodo
    }
}

// Método para mostrar los procesos de tiempo real en formato tabla
void Lista::muestraProcesosTiempoReal()  {
    if (longitud < 1) {
        cout << "No hay procesos en la lista de tiempo real." << endl;
        return;
    }

    cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    cout << "---------------------------------------------------" << endl; // Línea de separación

    pnodoLista actual = primero;
    while (actual != nullptr) {
        Proceso& proceso = actual->valor; // Acceder al proceso del nodo

        // Verificar si el proceso es de tipo tiempo real
        if (proceso.esTiempoReal()) {
            // Construir la línea de salida sin usar setw
            string tipo = "Tiempo Real";
            string estado = proceso.estaEnEjecucion() ? "En Ejecución" : "Parado";

            cout << proceso.getPID() << "\t" 
                 << proceso.getUsuario() << "\t" 
                 << tipo << "\t" 
                 << estado << "\t" 
                 << proceso.getPrioridad() << endl;
        }

        actual = actual->siguiente; // Mover al siguiente nodo
    }
}

Proceso Lista::menorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = primero;
    pnodoLista maximo = primero;
    
    while(aux->siguiente != NULL){
        if(aux->siguiente->valor.getPrioridad() > maximo->valor.getPrioridad())
            maximo = aux->siguiente;
        aux = aux->siguiente;
    }
    return maximo->valor;
}

Proceso Lista::mayorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = primero;
    pnodoLista minimo = primero;
    
    while(aux->siguiente != NULL){
        if(aux->siguiente->valor.getPrioridad() < minimo->valor.getPrioridad())
            minimo = aux->siguiente;
        aux = aux->siguiente;
    }
    return minimo->valor;
}

void Lista::buscarProcesosUsuario(string user){
    if(longitud < 1)
        return;
    pnodoLista aux = primero;
    while(aux != NULL){
        if(aux->valor.getUsuario() == user){
            aux->valor.mostrar();
        }
        aux = aux->siguiente;
    }
}

void Lista::enlistar(Proceso v){
	pnodoLista nuevo;
    nuevo = new NodoLista(v,ultimo);
    ultimo = nuevo;
    longitud++;	
}

void Lista::extraer(){
    pnodoLista nodo;
    if(!ultimo)
        return;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    longitud--;
    delete nodo;
}

void Lista::buscarYEliminarProceso(int pid) {
    if (longitud < 1) return Proceso(-1);  // Proceso con PID -1 indica que no se encontró

    pnodoLista actual = primero;
    pnodoLista anterior = nullptr;

    while (actual != nullptr) {
        if (actual->valor.getPID() == pid) {
            // Proceso encontrado; eliminarlo de la lista
            Proceso proceso = actual->valor;
            if (anterior == nullptr) {
                primero = actual->siguiente;  // Eliminar el primer nodo
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            longitud--;

            return proceso;
        }
        anterior = actual;
        actual = actual->siguiente;
    }

    return Proceso(-1);  // Proceso no encontrado
}

void Lista::buscarProcesoPorPID(int pid) {
    pnodoLista actual = primero;

    while (actual != nullptr) {
        if (actual->valor.getPID() == pid) {
            return &(actual->valor); // Retorna un puntero al proceso
        }
        actual = actual->siguiente;
    }
    
    return nullptr; // No se encontró el proceso
}

int Lista::getLongitud(){
    return this->longitud;
}



// Destructor
Lista::~Lista() {
    pnodoLista aux;
		while(ultimo){
			aux = ultimo;
			ultimo = ultimo->siguiente;
			delete aux;
    }
	longitud=0;
}
