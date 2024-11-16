#include <src/Header_Files/Cola.hpp>
#include <iostream>

using namespace std;



Cola::Cola(){
	longitud=0;
	primero = NULL;
	ultimo=NULL;
}

	
void Cola::insertar(Proceso v){
	pnodoCola nuevo;
    nuevo = new NodoCola(v);
    if (ultimo)
		ultimo->siguiente =nuevo;
	ultimo = nuevo;

	if (!primero)
		primero=nuevo;
    longitud++;	
}

void Cola::ordenarPorPrioridad() {
    if (longitud < 2) return;  // No hay necesidad de ordenar si la cola tiene menos de 2 elementos

    bool huboIntercambio;

    // Implementación del algoritmo de burbuja
    do {
        huboIntercambio = false;
        pnodoCola actual = primero;

        while (actual != NULL && actual->siguiente != NULL) {
            if (actual->valor.getPrioridad() > actual->siguiente->valor.getPrioridad()) {
                // Intercambiar los valores de los nodos si la prioridad de "actual" es mayor que la de "siguiente"
                Proceso temp = actual->valor;
                actual->valor = actual->siguiente->valor;
                actual->siguiente->valor = temp;

                huboIntercambio = true;  // Indicar que hubo al menos un intercambio en este ciclo
            }
            actual = actual->siguiente;  // Avanzar al siguiente nodo
        }
    } while (huboIntercambio);  // Repetir hasta que no haya intercambios
}



int Cola::getLongitud(){
    return this->longitud;
}

void Cola::mostrar(){
	pnodoCola aux = primero;
	while(aux){
		aux->valor.mostrar(true);
		aux= aux->siguiente;
	}
	cout << endl;
}


Proceso Cola::eliminar(){
	pnodoCola nodo;
    Proceso v;
	nodo = primero;
	if(!nodo){
		return Proceso();
	}
		primero = nodo -> siguiente;
		v = nodo -> valor;
		delete nodo;
		if(!primero){
			ultimo = NULL;
		}
		longitud--;
		return v;
	
}
Proceso Cola::verPrimero(){
	return primero->valor;
}


Cola:: ~Cola(){
	while(primero)
		eliminar();
}


	



