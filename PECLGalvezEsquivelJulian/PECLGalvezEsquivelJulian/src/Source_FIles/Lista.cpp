#include "src/Header_Files/Lista.hpp"
#include "src/Header_Files/Proceso.hpp"
#include "src/Header_Files/NodoLista.hpp"
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
    if(longitud < 1)
        return;
    pnodoLista aux = ultimo;
    while(aux != NULL){
        if(aux->valor.getUsuario() == user){
            aux->valor.mostrarEnTabla();
			 aux = aux->siguiente;
        
	 }else{ aux = aux->siguiente;
    }
	}
}

void Lista::buscarProcesosPID(int pid){
    if(longitud < 1)
        return;
    pnodoLista aux = ultimo;
    while(aux != NULL){
        if(aux->valor.getPID() == pid){
            aux->valor.mostrar(true);
			return;
        }
        aux->siguiente;
    }
}

void Lista::enlistar(Proceso v){
	pnodoLista nuevo;
    nuevo = new NodoLista(v,ultimo);
	nuevo->valor.setEstado(true);
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
void Lista::buscarProcesoPID(int pid) {
	if (longitud < 1) {
        cout << "La lista está vacía." << endl;
        return;
    }
	
   pnodoLista nodo;
   nodo = ultimo;
    if(!ultimo){
	return;}
	while (nodo->valor.getPID() != pid){
		ultimo = nodo->siguiente;
		if (nodo->valor.getPID() == pid) {
			cout << "PID\tUsuario\tTipo\t\tEstado\t\tPrioridad" << endl;
    cout << "---------------------------------------------------" << endl; // Línea de separación


        cout << nodo->valor.getPID() << "\t" 
             << nodo->valor.getUsuario() << "\t" 
             << nodo->valor.getTipo() << "\t" 
             << nodo->valor.getEstado() << "\t" 
             << nodo->valor.getPrioridad() << endl;

    }
			nodo->valor.mostrar(true);
	    
	}
	
}
    
   // return nullptr; // No se encontró el proceso


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
