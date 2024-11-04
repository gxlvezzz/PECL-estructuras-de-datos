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
    if (cabeza == nullptr) {
        cout << "No hay procesos en la lista." << endl;
        return;
    }

    cout << left << setw(10) << "PID" 
              << setw(15) << "Usuario" 
              << setw(15) << "Tipo" 
              << setw(15) << "Estado" 
              << setw(10) << "Prioridad" 
              << endl;

    cout << string(65, '-') << endl;

    pnodoLista actual = cabeza;
    while (actual != nullptr) {
         Proceso& proceso = actual->valor; // Acceder al proceso del nodo
        if (!proceso.esTiempoReal()) { // Solo muestra si es un proceso normal
            cout << left << setw(10) << proceso.getPID()
                      << setw(15) << proceso.getUsuario()
                      << setw(15) << "Normal"
                      << setw(15) << (proceso.estaEnEjecucion() ? "En Ejecución" : "Parado")
                      << setw(10) << proceso.getPrioridad()
                      << endl;
        }
        actual = actual->siguiente;
    }
}

// Método para mostrar los procesos de tiempo real en formato tabla
void Lista::muestraProcesosTiempoReal()  {
    if (cabeza == nullptr) {
        cout << "No hay procesos en la lista de tiempo real." << endl;
        return;
    }

    cout << left << setw(10) << "PID" 
              << setw(15) << "Usuario" 
              << setw(15) << "Tipo" 
              << setw(15) << "Estado" 
              << setw(10) << "Prioridad" 
              << endl;

    cout << string(65, '-') << endl;

    pnodoLista actual = cabeza;
    while (actual != nullptr) {
         Proceso& proceso = actual->valor; // Acceder al proceso del nodo
        if (proceso.esTiempoReal()) { // Solo muestra si es tiempo real
            cout << left << setw(10) << proceso.getPID()
                      << setw(15) << proceso.getUsuario()
                      << setw(15) << "Tiempo Real"
                      << setw(15) << (proceso.estaEnEjecucion() ? "En Ejecución" : "Parado")
                      << setw(10) << proceso.getPrioridad()
                      << endl;
        }
        actual = actual->siguiente;
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
