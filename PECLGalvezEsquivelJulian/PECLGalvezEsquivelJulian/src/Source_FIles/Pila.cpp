#include "src/Header_Files/Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}

bool Pila::buscarPID(int pid){
    if(longitud < 1){
        return false;
	}
    pnodoPila aux = ultimo;
    while(aux != NULL){
        if(aux->valor.getPID() == pid){
           return true; 
    }
	aux = aux->siguiente;
	}
	return false;
}

bool Pila::buscarPrioridad(int prioridad){
    if(longitud < 1){
        return false;
	}
    pnodoPila aux = ultimo;
    while(aux != NULL){
        if(aux->valor.getPrioridad() == prioridad){
           return true; 
    }
	aux = aux->siguiente;
	}
	return false;
}

void Pila::insertar(Proceso v){
    pnodoPila nuevo;
    nuevo = new NodoPila(v,ultimo);
    ultimo = nuevo;
    longitud++;
	nuevo->valor.setEstado(false);
}


void Pila::extraer(){
    pnodoPila nodo;
    if(!ultimo)
        return;
    nodo = ultimo;
    ultimo = nodo->siguiente;
    longitud--;
    delete nodo;
}

Proceso Pila::cima(){
    if(!ultimo){
        Proceso pro;
        pro.setVacio(true);
        return ultimo->valor;
    }
    return ultimo->valor;
}

void Pila::mostrar(){
	if(longitud==0){
		cout << "La pila se encuentra vacia." << endl;
	}else{
    pnodoPila aux = ultimo;
    while(aux){
        aux->valor.mostrar(false);
        aux = aux->siguiente;
    }
    cout << endl;
}}


int Pila::getLongitud(){
    return this->longitud;
}



Pila::~Pila()
{
    pnodoPila aux;
    while(ultimo){
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
		longitud=0;
    }
}



//Pila.cpp