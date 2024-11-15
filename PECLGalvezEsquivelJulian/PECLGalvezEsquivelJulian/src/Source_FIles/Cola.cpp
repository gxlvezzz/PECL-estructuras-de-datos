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
    if (longitud < 2) return; // No hay necesidad de ordenar si la cola tiene menos de 2 elementos

    for (pnodoCola i = ultimo; i != NULL; i = i->siguiente) {
        for (pnodoCola j = i->siguiente; j != NULL; j = j->siguiente) {
            if (i->valor.getPrioridad() > j->valor.getPrioridad()) {
                // Intercambiar los valores de los nodos si la prioridad de i es mayor que la de j
                Proceso temp = i->valor;
                i->valor = j->valor;
                j->valor = temp;
            }
        }
    }
}

/*void Cola::encolarProcesoNormal(Cola& c){
    pnodoCola aux = ultimo;
    while(aux){
        if(!aux->valor.getTipo()){
			c.encolar(aux->valor);			
		}		
        aux = aux->siguiente;
    }
    cout << endl;
}*/

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
	if(!nodo)
		return Proceso();
		primero = nodo -> siguiente;
		v = nodo -> valor;
		delete nodo;
		if(!primero)
			ultimo = NULL;
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


	



