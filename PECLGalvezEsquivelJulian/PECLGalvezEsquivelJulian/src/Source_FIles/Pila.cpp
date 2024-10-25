#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}

void Pila::insertar(Proceso v){
    pnodoPila nuevo;
    nuevo = new NodoPila(v,ultimo);
    ultimo = nuevo;
    longitud++;
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
    pnodoPila aux = ultimo;
    cout << "\tEl contenido de la pila es: \n";
    while(aux){
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
    cout << endl;
}

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
    }
}
Pila.cpp