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

// Método para mostrar los procesos de tiempo real en formato tabla


 Proceso Lista::menorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p ;
    }
    pnodoLista aux = ultimo;
    
    while(aux != NULL){
        if(aux->valor.getPID() > aux->siguiente->valor.getPID()){
            ultimo = aux->siguiente;
			aux->siguiente;
		}
	}
 
}

   Proceso Lista::mayorPrioridad(){
    if(longitud < 1){
        Proceso p;
        p.setVacio(1);
        return p;
    }
    pnodoLista aux = ultimo;
    
    while(aux != NULL){
        if(aux->valor.getPID() < aux->siguiente->valor.getPID()){
            ultimo = aux->siguiente;
            aux->siguiente;
		}
	}
	

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

void Lista::buscarProcesosPID(int pid, bool b){
    if(longitud < 1){
        return;
	}
    pnodoLista aux = ultimo;
    while(aux != NULL){
        if(aux->valor.getPID() == pid){
            aux->valor.mostrarEnTabla();
			 
        if (b){
			cout<<"\n"<< endl;
			aux->valor.mostrar(true);
			aux = aux->siguiente;
		}
	 }else{ 
		 aux = aux->siguiente;
    }
	}
}

void Lista::enlistar(Proceso v){
	pnodoLista nuevo;
    nuevo = new NodoLista(v,ultimo);
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


/*void Lista::buscarYEliminarProceso(int pid) {
    if (longitud < 1) {
        cout << "La lista está vacía." << endl;
        return ;
    }
    pnodoLista nodo;
	nodo = ultimo;
    if(!ultimo)
        return;
	while (nodo->valor.getPID() != pid){
		ultimo = nodo->siguiente;
		if (nodo->valor.getPID() == pid) {
			
			nodo->valor.mostrar(true);
	}
	
}
}
*/



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
