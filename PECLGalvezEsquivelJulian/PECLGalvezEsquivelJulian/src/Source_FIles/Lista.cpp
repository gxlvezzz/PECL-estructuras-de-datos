#include "src/Header_Files/Lista.hpp"
#include "src/Header_Files/Proceso.hpp"
#include "src/Header_Files/NodoLista.hpp"
#include "src/Header_Files/Pila.hpp"
#include <iostream>
using namespace std;

// Constructor
Lista::Lista() {
    longitud=0;
	ultimo=NULL;
}

	
	
/*

// Método para mostrar los procesos normales en formato tabla
void Lista::muestraProcesos()  {
   if(longitud==0){
		cout << "Esta cola se encuentra vacia." << endl;
	}else{
		cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    cout << "---------------------------------------------------" << endl; // Línea de separación
    pnodoLista aux = ultimo;
    while(aux){
        aux->valor.mostrarEnTabla();
        aux = aux->siguiente;
    }
    cout << endl;
    }

    
}


void Lista::ordenarListaPorPrioridad() {
    if (longitud < 2) return; // 

    for (pnodoLista i = ultimo; i != NULL; i = i->siguiente) {
        for (pnodoLista j = i->siguiente; j != NULL; j = j->siguiente) {
            if (i->valor.getPrioridad() > j->valor.getPrioridad()) {
                // Intercambiar los valores de los nodos si la prioridad de i es mayor que la de j
                Proceso temp = i->valor;
                i->valor = j->valor;
                j->valor = temp;
            }
        }
    }
}

Proceso Lista::obtenerMenorPrioridad() {
    ordenarListaPorPrioridad();
	if (longitud < 1) {
        Proceso p;
        p.setVacio(1);  
        return p;
    }
    return ultimo->valor;
}

Proceso Lista::obtenerMayorPrioridad() {
	ordenarListaPorPrioridad();
    if (longitud < 1) {
        Proceso p;
        p.setVacio(1);  
    }
    pnodoLista nodo = ultimo;
    while (nodo->siguiente != NULL) {
        nodo = nodo->siguiente;
    }
    return nodo->valor;
}

void Lista::buscarProcesosUsuario(string user){
    if(longitud < 1){
        return;
	}
    pnodoLista aux = ultimo;
    while(aux != NULL){
        if(aux->valor.getUsuario() == user){
            aux->valor.mostrarEnTabla();
			 aux = aux->siguiente;
        
	 }else{ 
		 aux = aux->siguiente;
    }
	}
}

Proceso* Lista::buscarProcesosPID(int pid, bool imprimir) {
    if (longitud < 1) {
        return nullptr;
    }
    pnodoLista aux = ultimo;
    while (aux != NULL) {
        if (aux->valor.getPID() == pid) {
            if (imprimir) {
                aux->valor.mostrarEnTabla();  
            }
            return &(aux->valor);  
        }
        aux = aux->siguiente;
    }
    return nullptr; 
}


void Lista::enlistar(Proceso v){
	pnodoLista nuevo;
    nuevo = new NodoLista(v,siguiente,anterior);
	nuevo->valor.setEstado(true);
    ultimo = nuevo;
    longitud++;	
}

Proceso Lista::extraer(int pid){
    if (!ultimo) return Proceso();

    pnodoLista nodo = ultimo;
    pnodoLista anterior = nullptr;

    while (nodo->valor.getPID() != pid) {
        anterior = nodo;
        nodo = nodo->siguiente;
    }
    if (!nodo) return Proceso();
	Proceso procesoEliminado = nodo->valor;
    if (nodo == ultimo) {
        ultimo = nodo->siguiente;
    } else {

        anterior->siguiente = nodo->siguiente;
    }

    delete nodo;
    longitud--;
	return procesoEliminado;
}





int Lista::getLongitud(){
    return this->longitud;
}

*/

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

