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
void Lista::muestraProcesos()  {
   if (longitud < 1) {
        cout << "No hay procesos en la lista normal." << endl;
        return;
    }

    cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    cout << "---------------------------------------------------" << endl; // Línea de separación

   
    while (ultimo != nullptr) {
        Proceso& proceso = ultimo->valor; // Acceder al proceso del nodo

        cout << proceso.getPID() << "\t" 
             << proceso.getUsuario() << "\t" 
             << proceso.getTipo() << "\t" 
             << proceso.getEstado() << "\t" 
             << proceso.getPrioridad() << endl;

        ultimo = ultimo->siguiente; // Mover al siguiente nodo
    }
}

// Método para mostrar los procesos de tiempo real en formato tabla


 void Lista::menorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = ultimo;
    pnodoLista maximo = ultimo;
    
    while(aux->siguiente != NULL){
        if(aux->siguiente->valor.getPrioridad() > maximo->valor.getPrioridad())
            maximo = aux->siguiente;
        aux = aux->siguiente;
    }
    return maximo->valor;
}

   void Lista::mayorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = ultimo;
    pnodoLista minimo = ultimo;
    
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
    pnodoLista aux = ultimo;
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

    pnodoLista nodo;
    if(!ultimo)
        return;
    nodo = ultimo;
	while (PID != pid){
		ultimo = nodo->siguiente;
		if (PID == pid) 
			longitud--;
			delete nodo;
	}
	
}


void Lista::buscarProcesoPorPID(int pid) {
   pnodoLista nodo;
    if(!ultimo){
	return;}
    nodo = ultimo;
	while (PID != pid){
		ultimo = nodo->siguiente;
		if (PID == pid) {
			proceso.mostrar();
	    }
	
	}
	
}
    
   // return nullptr; // No se encontró el proceso
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
	